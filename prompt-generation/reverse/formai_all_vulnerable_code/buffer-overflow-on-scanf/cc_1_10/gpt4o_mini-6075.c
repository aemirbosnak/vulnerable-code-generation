//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for contact information
typedef struct {
    char name[50];
    char phone[15];
    char email[50];
    char address[100];
} Contact;

// Function Prototypes
void addContact(Contact **contacts, int *count);
void viewContacts(Contact *contacts, int count);
void searchContact(Contact *contacts, int count);
void deleteContact(Contact **contacts, int *count);
void updateContact(Contact *contacts, int count);
void cleanupContacts(Contact *contacts, int count);

int main() {
    Contact *contacts = NULL;
    int count = 0;
    int choice;

    printf("Welcome to the Futuristic Phone Book\n");
    printf("=====================================\n");

    while (1) {
        printf("\nSelect an action:\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Update Contact\n");
        printf("5. Delete Contact\n");
        printf("6. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline from input buffer

        switch (choice) {
            case 1:
                addContact(&contacts, &count);
                break;
            case 2:
                viewContacts(contacts, count);
                break;
            case 3:
                searchContact(contacts, count);
                break;
            case 4:
                updateContact(contacts, count);
                break;
            case 5:
                deleteContact(&contacts, &count);
                break;
            case 6:
                cleanupContacts(contacts, count);
                printf("Exiting the Futuristic Phone Book. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
    return 0;
}

void addContact(Contact **contacts, int *count) {
    (*count)++;
    *contacts = realloc(*contacts, (*count) * sizeof(Contact));
    if (*contacts == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    printf("Enter Name: ");
    fgets((*contacts)[*count - 1].name, 50, stdin);
    strtok((*contacts)[*count - 1].name, "\n"); // Remove newline

    printf("Enter Phone: ");
    fgets((*contacts)[*count - 1].phone, 15, stdin);
    strtok((*contacts)[*count - 1].phone, "\n");

    printf("Enter Email: ");
    fgets((*contacts)[*count - 1].email, 50, stdin);
    strtok((*contacts)[*count - 1].email, "\n");

    printf("Enter Address: ");
    fgets((*contacts)[*count - 1].address, 100, stdin);
    strtok((*contacts)[*count - 1].address, "\n");

    printf("Contact added successfully!\n");
}

void viewContacts(Contact *contacts, int count) {
    if (count == 0) {
        printf("No contacts to display.\n");
        return;
    }

    printf("\nContacts List:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. Name: %s, Phone: %s, Email: %s, Address: %s\n",
               i + 1, contacts[i].name, contacts[i].phone,
               contacts[i].email, contacts[i].address);
    }
}

void searchContact(Contact *contacts, int count) {
    char searchName[50];
    printf("Enter the name to search: ");
    fgets(searchName, 50, stdin);
    strtok(searchName, "\n");

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcasecmp(contacts[i].name, searchName) == 0) {
            printf("Found Contact: Name: %s, Phone: %s, Email: %s, Address: %s\n",
                   contacts[i].name, contacts[i].phone,
                   contacts[i].email, contacts[i].address);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found!\n");
    }
}

void deleteContact(Contact **contacts, int *count) {
    if (*count == 0) {
        printf("No contacts to delete.\n");
        return;
    }

    int deleteIndex;
    viewContacts(*contacts, *count);
    printf("Select the contact number to delete: ");
    scanf("%d", &deleteIndex);
    getchar(); // Clear newline

    if (deleteIndex < 1 || deleteIndex > *count) {
        printf("Invalid contact number.\n");
        return;
    }

    for (int i = deleteIndex - 1; i < *count - 1; i++) {
        (*contacts)[i] = (*contacts)[i + 1];
    }

    (*count)--;
    *contacts = realloc(*contacts, (*count) * sizeof(Contact));
    printf("Contact deleted successfully!\n");
}

void updateContact(Contact *contacts, int count) {
    if (count == 0) {
        printf("No contacts to update.\n");
        return;
    }

    int updateIndex;
    viewContacts(contacts, count);
    printf("Select the contact number to update: ");
    scanf("%d", &updateIndex);
    getchar(); // Clear newline

    if (updateIndex < 1 || updateIndex > count) {
        printf("Invalid contact number.\n");
        return;
    }

    printf("Updating Contact: %s\n", contacts[updateIndex - 1].name);
    printf("Enter new Name: ");
    fgets(contacts[updateIndex - 1].name, 50, stdin);
    strtok(contacts[updateIndex - 1].name, "\n");

    printf("Enter new Phone: ");
    fgets(contacts[updateIndex - 1].phone, 15, stdin);
    strtok(contacts[updateIndex - 1].phone, "\n");

    printf("Enter new Email: ");
    fgets(contacts[updateIndex - 1].email, 50, stdin);
    strtok(contacts[updateIndex - 1].email, "\n");

    printf("Enter new Address: ");
    fgets(contacts[updateIndex - 1].address, 100, stdin);
    strtok(contacts[updateIndex - 1].address, "\n");

    printf("Contact updated successfully!\n");
}

void cleanupContacts(Contact *contacts, int count) {
    free(contacts);
}