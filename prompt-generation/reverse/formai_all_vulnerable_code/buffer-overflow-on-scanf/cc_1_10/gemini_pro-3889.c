//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contact {
    char *name;
    char *number;
    struct contact *next;
} contact_t;

contact_t *head = NULL;

void add_contact(char *name, char *number) {
    contact_t *new_contact = malloc(sizeof(contact_t));
    new_contact->name = strdup(name);
    new_contact->number = strdup(number);
    new_contact->next = head;
    head = new_contact;
}

void print_contacts() {
    contact_t *current = head;
    while (current != NULL) {
        printf("%s: %s\n", current->name, current->number);
        current = current->next;
    }
}

void search_contact(char *name) {
    contact_t *current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("%s: %s\n", current->name, current->number);
            return;
        }
        current = current->next;
    }
    printf("Contact not found.\n");
}

void delete_contact(char *name) {
    contact_t *current = head;
    contact_t *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current->name);
            free(current->number);
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Contact not found.\n");
}

int main() {
    int choice;
    char name[256];
    char number[256];

    while (1) {
        printf("1. Add contact\n");
        printf("2. Print contacts\n");
        printf("3. Search contact\n");
        printf("4. Delete contact\n");
        printf("5. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter number: ");
                scanf("%s", number);
                add_contact(name, number);
                break;
            case 2:
                print_contacts();
                break;
            case 3:
                printf("Enter name: ");
                scanf("%s", name);
                search_contact(name);
                break;
            case 4:
                printf("Enter name: ");
                scanf("%s", name);
                delete_contact(name);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}