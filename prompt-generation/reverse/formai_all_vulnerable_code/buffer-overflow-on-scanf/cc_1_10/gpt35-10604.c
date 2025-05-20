//FormAI DATASET v1.0 Category: Phone Book ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Phone book structure
typedef struct {
    char name[50];
    char number[20];
} Contact;

// Function to add a contact
void addContact(Contact *phonebook, int *size) {
    printf("Enter name: ");
    scanf("%s", phonebook[*size].name);
    printf("Enter number: ");
    scanf("%s", phonebook[*size].number);
    (*size)++;
    printf("Contact added successfully!\n");
}

// Function to search for contacts by name
void searchContacts(Contact *phonebook, int size) {
    char searchName[50];
    printf("Enter name to search for: ");
    scanf("%s", searchName);
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(phonebook[i].name, searchName) == 0) {
            printf("Name: %s\n", phonebook[i].name);
            printf("Number: %s\n", phonebook[i].number);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

// Function to delete a contact by name
void deleteContact(Contact *phonebook, int *size) {
    char deleteName[50];
    printf("Enter name to delete: ");
    scanf("%s", deleteName);
    int found = 0;
    for (int i = 0; i < *size; i++) {
        if (strcmp(phonebook[i].name, deleteName) == 0) {
            for (int j = i; j < *size - 1; j++) {
                strcpy(phonebook[j].name, phonebook[j+1].name);
                strcpy(phonebook[j].number, phonebook[j+1].number);
            }
            (*size)--;
            found = 1;
            printf("Contact deleted successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

// Function to display all contacts
void displayContacts(Contact *phonebook, int size) {
    printf("Contacts:\n");
    for (int i = 0; i < size; i++) {
        printf("%s: %s\n", phonebook[i].name, phonebook[i].number);
    }
}

int main() {
    Contact phonebook[100];
    int size = 0;
    int choice;

    do {
        printf("Phone Book Menu:\n");
        printf("1. Add contact\n");
        printf("2. Search contacts\n");
        printf("3. Delete contact\n");
        printf("4. Display all contacts\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(phonebook, &size);
                break;
            case 2:
                searchContacts(phonebook, size);
                break;
            case 3:
                deleteContact(phonebook, &size);
                break;
            case 4:
                displayContacts(phonebook, size);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }

    } while (choice != 5);

    return 0;
}