//FormAI DATASET v1.0 Category: Mailing list manager ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50
#define MAX_CONTACTS 100

typedef struct Contact {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

typedef struct ContactList {
    Contact contacts[MAX_CONTACTS];
    int count;
} ContactList;

void print_menu() {
    printf("Menu:\n");
    printf("1. Add Contact\n");
    printf("2. Remove Contact\n");
    printf("3. Print Contacts\n");
    printf("4. Quit\n");
}

void add_contact(ContactList *list) {
    if (list->count == MAX_CONTACTS) {
        printf("Contact list is full\n");
        return;
    }

    Contact contact;
    printf("Enter name: ");
    fgets(contact.name, MAX_NAME_LENGTH, stdin);
    contact.name[strcspn(contact.name, "\n")] = 0;

    printf("Enter email: ");
    fgets(contact.email, MAX_EMAIL_LENGTH, stdin);
    contact.email[strcspn(contact.email, "\n")] = 0;

    list->contacts[list->count] = contact;
    list->count++;
}

void remove_contact(ContactList *list) {
    if (list->count == 0) {
        printf("Contact list is empty\n");
        return;
    }

    char name[MAX_NAME_LENGTH];
    printf("Enter name of contact to remove: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0;

    int found = 0;
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->contacts[i].name, name) == 0) {
            found = 1;
            for (int j = i; j < list->count - 1; j++) {
                list->contacts[j] = list->contacts[j+1];
            }
            list->count--;
            printf("%s removed from contact list\n", name);
            break;
        }
    }

    if (!found) {
        printf("%s not found in contact list\n", name);
    }
}

void print_contacts(ContactList *list) {
    printf("Contacts:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%s - %s\n", list->contacts[i].name, list->contacts[i].email);
    }
}

int main() {
    ContactList list = { .count = 0 };

    int choice;
    do {
        print_menu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                add_contact(&list);
                break;
            case 2:
                remove_contact(&list);
                break;
            case 3:
                print_contacts(&list);
                break;
            case 4:
                printf("Quitting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}