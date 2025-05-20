//FormAI DATASET v1.0 Category: Mailing list manager ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contact {
    char* name;
    char* email;
    struct Contact* next;
} Contact;

void add_contact(Contact** head, char* name, char* email) {
    Contact* new_contact = (Contact*) malloc(sizeof(Contact));
    new_contact->name = (char*) malloc(strlen(name) + 1);
    new_contact->email = (char*) malloc(strlen(email) + 1);
    strcpy(new_contact->name, name);
    strcpy(new_contact->email, email);
    new_contact->next = *head;
    *head = new_contact;
}

void print_contacts(Contact* head) {
    if (head == NULL) {
        printf("No contacts found.\n");
        return;
    }
    printf("Contact List:\n");
    printf("--------------------------------\n");
    Contact* current = head;
    while (current != NULL) {
        printf("Name: %s\n", current->name);
        printf("Email: %s\n", current->email);
        printf("--------------------------------\n");
        current = current->next;
    }
}

Contact* search_contact(Contact* head, char* name) {
    Contact* current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void delete_contact(Contact** head, char* name) {
    Contact* current = *head;
    if (current != NULL && strcmp(current->name, name) == 0) {
        *head = current->next;
        free(current);
        printf("Contact deleted.\n");
        return;
    }
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            Contact* temp = current;
            current = current->next;
            free(temp);
            printf("Contact deleted.\n");
            return;
        }
        current = current->next;
    }
    printf("Contact not found.\n");
}

int main() {
    Contact* head = NULL;
    int choice;
    char name[50];
    char email[50];
    do {
        printf("\n");
        printf("1. Add contact\n");
        printf("2. Print contacts\n");
        printf("3. Search contact\n");
        printf("4. Delete contact\n");
        printf("5. Quit\n");
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                add_contact(&head, name, email);
                printf("Contact added.\n");
                break;
            case 2:
                print_contacts(head);
                break;
            case 3:
                printf("Enter name: ");
                scanf("%s", name);
                if (search_contact(head, name) == NULL) {
                    printf("Contact not found.\n");
                } else {
                    printf("Contact found.\n");
                }
                break;
            case 4:
                printf("Enter name: ");
                scanf("%s", name);
                delete_contact(&head, name);
                break;
            case 5:
                printf("Quitting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);
    return 0;
}