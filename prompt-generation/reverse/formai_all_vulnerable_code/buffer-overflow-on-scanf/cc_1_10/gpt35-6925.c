//FormAI DATASET v1.0 Category: Phone Book ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contact {
    char name[50];
    char phone_number[20];
    char email[50];
    struct contact *next;
} Contact;

Contact *head = NULL;

void add_contact() {
    Contact *new_contact = malloc(sizeof(Contact));
    printf("Enter name:\n");
    scanf("%s", new_contact->name);
    printf("Enter phone number:\n");
    scanf("%s", new_contact->phone_number);
    printf("Enter email:\n");
    scanf("%s", new_contact->email);
    new_contact->next = head;
    head = new_contact;
    printf("Contact added successfully.\n");
}

void search_contact() {
    char name[50];
    printf("Enter name to search:\n");
    scanf("%s", name);
    Contact *current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("Name: %s\n", current->name);
            printf("Phone number: %s\n", current->phone_number);
            printf("Email: %s\n", current->email);
            return;
        }
        current = current->next;
    }
    printf("No contact found.\n");
}

void display_contacts() {
    if (head == NULL) {
        printf("Phone book is empty.\n");
        return;
    }
    Contact *current = head;
    printf("\n");
    while (current != NULL) {
        printf("Name: %s\n", current->name);
        printf("Phone number: %s\n", current->phone_number);
        printf("Email: %s\n", current->email);
        printf("------------------\n");
        current = current->next;
    }
}

void delete_contact() {
    if (head == NULL) {
        printf("Phone book is empty.\n");
        return;
    }
    char name[50];
    printf("Enter name to delete:\n");
    scanf("%s", name);
    if (strcmp(head->name, name) == 0) {
        Contact *temp = head;
        head = head->next;
        free(temp);
        printf("%s has been deleted from the phone book.\n", name);
        return;
    }
    Contact *current = head;
    while (current->next != NULL) {
        if (strcmp(current->next->name, name) == 0) {
            Contact *temp = current->next;
            current->next = current->next->next;
            free(temp);
            printf("%s has been deleted from the phone book.\n", name);
            return;
        }
        current = current->next;
    }
    printf("%s was not found in the phone book.\n", name);
}

void menu() {
    printf("\nWelcome to the Cyberpunk Phone Book\n");
    printf("1. Add a contact\n");
    printf("2. Search for a contact\n");
    printf("3. Display all contacts\n");
    printf("4. Delete a contact\n");
    printf("5. Exit\n");
}

int main() {
    int choice = 0;
    while (choice != 5) {
        menu();
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                search_contact();
                break;
            case 3:
                display_contacts();
                break;
            case 4:
                delete_contact();
                break;
            case 5:
                printf("Exiting Cyberpunk Phone Book.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}