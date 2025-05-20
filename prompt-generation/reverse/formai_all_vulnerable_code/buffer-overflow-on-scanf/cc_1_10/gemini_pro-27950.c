//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct contact {
    char *name;
    char *phone_number;
    struct contact *next;
} contact_t;

// Function to create a new contact
contact_t *create_contact(char *name, char *phone_number) {
    contact_t *new_contact = (contact_t *)malloc(sizeof(contact_t));
    new_contact->name = (char *)malloc(strlen(name) + 1);
    strcpy(new_contact->name, name);
    new_contact->phone_number = (char *)malloc(strlen(phone_number) + 1);
    strcpy(new_contact->phone_number, phone_number);
    new_contact->next = NULL;
    return new_contact;
}

// Function to add a contact to the phone book
void add_contact(contact_t **head, char *name, char *phone_number) {
    contact_t *new_contact = create_contact(name, phone_number);
    if (*head == NULL) {
        *head = new_contact;
    } else {
        contact_t *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_contact;
    }
}

// Function to search for a contact in the phone book
contact_t *search_contact(contact_t *head, char *name) {
    contact_t *current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to delete a contact from the phone book
void delete_contact(contact_t **head, char *name) {
    contact_t *current = *head;
    contact_t *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                *head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current->name);
            free(current->phone_number);
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

// Function to print the phone book
void print_phone_book(contact_t *head) {
    contact_t *current = head;
    while (current != NULL) {
        printf("%s: %s\n", current->name, current->phone_number);
        current = current->next;
    }
}

// Function to get a valid name from the user
char *get_name() {
    char *name = (char *)malloc(100);
    printf("Enter name: ");
    scanf(" %[^\n]s", name);
    return name;
}

// Function to get a valid phone number from the user
char *get_phone_number() {
    char *phone_number = (char *)malloc(100);
    printf("Enter phone number: ");
    scanf(" %[^\n]s", phone_number);
    return phone_number;
}

// Function to get a valid option from the user
int get_option() {
    int option;
    printf("\nChoose an option:\n");
    printf("1. Add contact\n");
    printf("2. Search contact\n");
    printf("3. Delete contact\n");
    printf("4. Print phone book\n");
    printf("5. Quit\n");
    printf("Enter option: ");
    scanf("%d", &option);
    return option;
}

// Main function
int main() {
    contact_t *head = NULL;

    while (true) {
        int option = get_option();

        switch (option) {
            case 1: {
                char *name = get_name();
                char *phone_number = get_phone_number();
                add_contact(&head, name, phone_number);
                printf("Contact added successfully!\n");
                break;
            }
            case 2: {
                char *name = get_name();
                contact_t *contact = search_contact(head, name);
                if (contact != NULL) {
                    printf("Contact found:\n");
                    printf("Name: %s\n", contact->name);
                    printf("Phone number: %s\n", contact->phone_number);
                } else {
                    printf("Contact not found!\n");
                }
                break;
            }
            case 3: {
                char *name = get_name();
                delete_contact(&head, name);
                printf("Contact deleted successfully!\n");
                break;
            }
            case 4: {
                print_phone_book(head);
                break;
            }
            case 5: {
                printf("Quitting...\n");
                return 0;
            }
            default: {
                printf("Invalid option!\n");
            }
        }
    }

    return 0;
}