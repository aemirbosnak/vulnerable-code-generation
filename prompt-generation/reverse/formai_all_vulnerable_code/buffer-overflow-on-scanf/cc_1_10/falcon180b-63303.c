//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100
#define MAX_LIST_SIZE 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} contact;

typedef struct {
    contact *contacts;
    int size;
} mailing_list;

void initialize_list(mailing_list *list) {
    list->contacts = NULL;
    list->size = 0;
}

void add_contact(mailing_list *list, contact *contact) {
    if (list->size >= MAX_LIST_SIZE) {
        printf("Error: List is full.\n");
        return;
    }
    list->contacts = realloc(list->contacts, sizeof(contact) * (list->size + 1));
    memcpy(list->contacts + list->size, contact, sizeof(contact));
    list->size++;
}

void print_list(mailing_list *list) {
    printf("Name\tEmail\n");
    for (int i = 0; i < list->size; i++) {
        printf("%s\t%s\n", list->contacts[i].name, list->contacts[i].email);
    }
}

int main() {
    mailing_list list;
    initialize_list(&list);

    char input[100];
    while (1) {
        printf("Enter command (add, print, quit): ");
        scanf("%s", input);
        if (strcmp(input, "add") == 0) {
            contact contact;
            printf("Enter name: ");
            scanf("%s", contact.name);
            printf("Enter email: ");
            scanf("%s", contact.email);
            add_contact(&list, &contact);
        } else if (strcmp(input, "print") == 0) {
            print_list(&list);
        } else if (strcmp(input, "quit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}