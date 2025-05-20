//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_EMAIL_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} contact;

contact* create_contact(char* name, char* email) {
    contact* new_contact = (contact*) malloc(sizeof(contact));
    strcpy(new_contact->name, name);
    strcpy(new_contact->email, email);
    return new_contact;
}

void print_contact(contact* c) {
    printf("Name: %s\nEmail: %s\n", c->name, c->email);
}

int compare_contacts(contact* a, contact* b) {
    return strcmp(a->name, b->name);
}

void sort_contacts(contact** contacts, int count) {
    qsort(contacts, count, sizeof(contact*), compare_contacts);
}

int main() {
    FILE* input_file = fopen("contacts.txt", "r");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    contact* contacts = NULL;
    int count = 0;

    while (fscanf(input_file, "%s %s", contacts[count].name, contacts[count].email)!= EOF) {
        count++;
        contacts = realloc(contacts, sizeof(contact) * count);
    }

    fclose(input_file);

    sort_contacts(contacts, count);

    for (int i = 0; i < count; i++) {
        print_contact(&contacts[i]);
    }

    free(contacts);

    return 0;
}