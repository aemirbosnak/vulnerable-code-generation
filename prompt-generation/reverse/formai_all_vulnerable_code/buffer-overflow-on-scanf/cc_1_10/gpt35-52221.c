//FormAI DATASET v1.0 Category: Phone Book ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CONTACTS 100

struct Contact {
    char name[100], phone[15], email[100];
};

void addContact(struct Contact[], int*);
void searchContact(struct Contact[], int);
void displayContacts(struct Contact[], int);
void saveContacts(struct Contact[], int);

int main() {
    struct Contact contacts[MAX_CONTACTS];
    int numContacts = 0, choice;
    while (1) {
        printf("\nPhone Book Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Display All Contacts\n");
        printf("4. Save Contacts to File\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addContact(contacts, &numContacts);
                break;
            case 2:
                searchContact(contacts, numContacts);
                break;
            case 3:
                displayContacts(contacts, numContacts);
                break;
            case 4:
                saveContacts(contacts, numContacts);
                break;
            case 5:
                printf("Exiting Phone Book. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void addContact(struct Contact contacts[], int* numContacts) {
    printf("Enter contact name: ");
    scanf(" %[^\n]", contacts[*numContacts].name);
    printf("Enter contact phone number: ");
    scanf("%s", contacts[*numContacts].phone);
    printf("Enter contact email address: ");
    scanf("%s", contacts[*numContacts].email);
    (*numContacts)++;
    printf("Contact added successfully!\n");
}

void searchContact(struct Contact contacts[], int numContacts) {
    char name[100];
    printf("Enter name to search: ");
    scanf(" %[^\n]", name);
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(name, contacts[i].name) == 0) {
            printf("Contact found:\n");
            printf("Name: %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            printf("Email: %s\n", contacts[i].email);
            return;
        }
    }
    printf("Contact not found.\n");    
}

void displayContacts(struct Contact contacts[], int numContacts) {
    if (numContacts == 0) {
        printf("No contacts to display.\n");
        return;
    }
    printf("List of contacts:\n");
    for (int i = 0; i < numContacts; i++) {
        printf("%d. %s  %s  %s\n", i+1, contacts[i].name, contacts[i].phone, contacts[i].email);
    }
}

void saveContacts(struct Contact contacts[], int numContacts) {
    FILE* fp = fopen("contacts.txt", "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }
    for (int i = 0; i < numContacts; i++) {
        fprintf(fp, "%s %s %s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
    }
    fclose(fp);
    printf("Contacts saved to file.\n");
}