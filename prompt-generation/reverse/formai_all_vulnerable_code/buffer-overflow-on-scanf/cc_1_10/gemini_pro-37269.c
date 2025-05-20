//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 20
#define MAX_CONTACTS 100

typedef struct Contact {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;

Contact contacts[MAX_CONTACTS];
int num_contacts = 0;

// Function to add a new contact to the phone book
void add_contact() {
    if (num_contacts >= MAX_CONTACTS) {
        printf("Phone book is full!\n");
        return;
    }

    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter phone number: ");
    scanf("%s", phone);

    strcpy(contacts[num_contacts].name, name);
    strcpy(contacts[num_contacts].phone, phone);

    num_contacts++;
}

// Function to search for a contact in the phone book
void search_contact() {
    char name[MAX_NAME_LENGTH];

    printf("Enter name to search for: ");
    scanf("%s", name);

    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Name: %s\n", contacts[i].name);
            printf("Phone number: %s\n", contacts[i].phone);
            return;
        }
    }

    printf("Contact not found!\n");
}

// Function to delete a contact from the phone book
void delete_contact() {
    char name[MAX_NAME_LENGTH];

    printf("Enter name to delete: ");
    scanf("%s", name);

    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            for (int j = i + 1; j < num_contacts; j++) {
                contacts[j - 1] = contacts[j];
            }
            num_contacts--;
            printf("Contact deleted!\n");
            return;
        }
    }

    printf("Contact not found!\n");
}

// Function to print all contacts in the phone book
void print_contacts() {
    for (int i = 0; i < num_contacts; i++) {
        printf("Name: %s\n", contacts[i].name);
        printf("Phone number: %s\n", contacts[i].phone);
        printf("\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nCyberpunk Phone Book\n");
        printf("1. Add contact\n");
        printf("2. Search contact\n");
        printf("3. Delete contact\n");
        printf("4. Print all contacts\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                search_contact();
                break;
            case 3:
                delete_contact();
                break;
            case 4:
                print_contacts();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}