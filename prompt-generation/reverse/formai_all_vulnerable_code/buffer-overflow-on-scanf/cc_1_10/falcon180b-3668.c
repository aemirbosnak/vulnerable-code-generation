//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 100
#define MAX_EMAIL_LEN 100
#define MAX_SUBJECT_LEN 200
#define MAX_BODY_LEN 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} contact;

typedef struct {
    contact *list;
    int count;
} mailing_list;

void init_contact(contact *c) {
    strcpy(c->name, "");
    strcpy(c->email, "");
}

void init_mailing_list(mailing_list *m) {
    m->list = NULL;
    m->count = 0;
}

void add_contact(mailing_list *m, contact *c) {
    m->list = realloc(m->list, sizeof(contact) * (m->count + 1));
    m->list[m->count] = *c;
    m->count++;
}

void print_contact(contact *c) {
    printf("Name: %s\n", c->name);
    printf("Email: %s\n", c->email);
}

void print_mailing_list(mailing_list *m) {
    for (int i = 0; i < m->count; i++) {
        print_contact(&m->list[i]);
    }
}

int main() {
    mailing_list m;
    init_mailing_list(&m);

    char input[MAX_EMAIL_LEN];
    while (1) {
        printf("Enter email address: ");
        scanf("%s", input);

        contact c;
        init_contact(&c);

        int len = strlen(input);
        if (len < 1 || len > MAX_EMAIL_LEN) {
            printf("Invalid email address.\n");
            continue;
        }

        strcpy(c.email, input);
        int index = 0;
        while (index < len &&!isalpha(input[index])) {
            index++;
        }
        while (index < len && isalpha(input[index])) {
            c.name[index - 1] = toupper(input[index]);
            index++;
        }
        c.name[index - 1] = '\0';

        add_contact(&m, &c);
    }

    print_mailing_list(&m);

    return 0;
}