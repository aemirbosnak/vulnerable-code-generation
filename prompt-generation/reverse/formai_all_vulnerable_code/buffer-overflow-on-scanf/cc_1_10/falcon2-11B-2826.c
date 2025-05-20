//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CONTACTS 10
#define MAX_NAME 50
#define MAX_PHONE 15

// Function to add a new contact to the phone book
void add_contact(char **contacts, int *max_contacts) {
    char name[MAX_NAME + 1];
    char phone[MAX_PHONE + 1];
    int i, j;
    char *new_contact = malloc(sizeof(char) * (MAX_NAME + 1));

    // Get the new contact details
    printf("Enter the name: ");
    scanf("%s", name);

    printf("Enter the phone number: ");
    scanf("%s", phone);

    // Check if the phone number is valid
    if (strlen(phone)!= 10) {
        printf("Invalid phone number. Must be 10 digits.\n");
        return;
    }

    // Check if the phone number is already in the phone book
    for (i = 0; i < *max_contacts; i++) {
        for (j = 0; j < strlen(phone); j++) {
            if (contacts[i][j] == phone[j]) {
                printf("Phone number already exists in the phone book.\n");
                return;
            }
        }
    }

    // Add the new contact to the phone book
    for (i = 0; i < *max_contacts; i++) {
        if (strcmp(contacts[i], new_contact) == 0) {
            break;
        }
    }
    if (i == *max_contacts) {
        // Phone book is full, cannot add new contact
        printf("Phone book is full, cannot add new contact.\n");
        return;
    }

    strcpy(contacts[i], new_contact);
    *max_contacts++;

    printf("Contact added successfully.\n");
}

// Function to search for a contact in the phone book
void search_contact(char **contacts, int max_contacts) {
    char name[MAX_NAME + 1];
    int i;

    printf("Enter the name to search for: ");
    scanf("%s", name);

    // Search for the contact
    for (i = 0; i < max_contacts; i++) {
        if (strcmp(contacts[i], name) == 0) {
            printf("Contact found.\n");
            printf("Name: %s\n", contacts[i]);
            printf("Phone number: %s\n", &contacts[i][strlen(name)]);
            break;
        }
    }

    if (i == max_contacts) {
        printf("Contact not found.\n");
    }
}

// Function to delete a contact from the phone book
void delete_contact(char **contacts, int max_contacts) {
    char name[MAX_NAME + 1];
    int i, j;

    printf("Enter the name to delete: ");
    scanf("%s", name);

    // Search for the contact
    for (i = 0; i < max_contacts; i++) {
        if (strcmp(contacts[i], name) == 0) {
            // Delete the contact
            for (j = i; j < max_contacts - 1; j++) {
                strcpy(contacts[j], contacts[j + 1]);
            }

            // Decrement the max_contacts
            max_contacts--;
            break;
        }
    }

    if (i == max_contacts) {
        printf("Contact not found.\n");
    }
}

int main() {
    char *contacts[MAX_CONTACTS];
    int max_contacts = 0;

    while (1) {
        printf("1. Add a new contact\n2. Search for a contact\n3. Delete a contact\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact(contacts, &max_contacts);
                break;
            case 2:
                search_contact(contacts, max_contacts);
                break;
            case 3:
                delete_contact(contacts, max_contacts);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}