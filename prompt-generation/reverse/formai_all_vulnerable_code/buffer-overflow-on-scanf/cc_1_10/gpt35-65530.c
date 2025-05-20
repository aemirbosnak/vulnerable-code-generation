//FormAI DATASET v1.0 Category: Phone Book ; Style: surrealist
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONTACTS 100

typedef struct {
    char name[20];
    char number[15];
} Contact;

void addContact(Contact* contacts, int* numContacts) {
    printf("Enter Name: ");
    scanf("%s", contacts[*numContacts].name);
    printf("Enter Number: ");
    scanf("%s", contacts[*numContacts].number);
    printf("Contact Added Successfully!\n");
    (*numContacts)++;
}

void displayContacts(Contact* contacts, int numContacts) {
    printf("Contact List:\n");
    for (int i = 0; i < numContacts; i++) {
        printf("%d. %s - %s\n", i+1, contacts[i].name, contacts[i].number);
    }
    printf("\n");
}

void deleteContact(Contact* contacts, int* numContacts) {
    int index;
    printf("Enter Index of Contact to Delete: ");
    scanf("%d", &index);
    if (index < 1 || index > *numContacts) {
        printf("Invalid Index!\n");
        return;
    }
    for (int i = index-1; i < *numContacts-1; i++) {
        strcpy(contacts[i].name, contacts[i+1].name);
        strcpy(contacts[i].number, contacts[i+1].number);
    }
    (*numContacts)--;
    printf("Contact Deleted Successfully!\n");
}

void editContact(Contact* contacts, int* numContacts) {
    int index;
    printf("Enter Index of Contact to Edit: ");
    scanf("%d", &index);
    if (index < 1 || index > *numContacts) {
        printf("Invalid Index!\n");
        return;
    }
    printf("Current Name: %s\n", contacts[index-1].name);
    printf("Enter New Name (Press Enter to Skip): ");
    char newName[20];
    fgets(newName, 20, stdin);
    if (newName[0] != '\n') {
        strtok(newName, "\n");
        strcpy(contacts[index-1].name, newName);
    }
    printf("Current Number: %s\n", contacts[index-1].number);
    printf("Enter New Number (Press Enter to Skip): ");
    char newNumber[15];
    fgets(newNumber, 15, stdin);
    if (newNumber[0] != '\n') {
        strtok(newNumber, "\n");
        strcpy(contacts[index-1].number, newNumber);
    }
    printf("Contact Edited Successfully!\n");
}

void clearAllContacts(Contact* contacts, int* numContacts) {
    *numContacts = 0;
    printf("All Contacts Cleared Successfully!\n");
}

int main() {
    Contact contacts[MAX_CONTACTS];
    int numContacts = 0;
    int choice;

    srand(time(0));
    printf("Welcome to the Surrealist Phone Book!\n");
    printf("Please Choose an Option:\n");
    do {
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Delete Contact\n");
        printf("4. Edit Contact\n");
        printf("5. Clear All Contacts\n");
        printf("6. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice) {
            case 1:
                addContact(contacts, &numContacts);
                break;
            case 2:
                displayContacts(contacts, numContacts);
                break;
            case 3:
                if (numContacts > 0) {
                    deleteContact(contacts, &numContacts);
                } else {
                    printf("No Contacts in List!\n");
                }
                break;
            case 4:
                if (numContacts > 0) {
                    editContact(contacts, &numContacts);
                } else {
                    printf("No Contacts in List!\n");
                }
                break;
            case 5:
                if (numContacts > 0) {
                    clearAllContacts(contacts, &numContacts);
                } else {
                    printf("No Contacts in List!\n");
                }
                break;
            case 6:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid Choice!\n");
                break;
        }
        printf("\n");
    } while (choice != 6);

    return 0;
}