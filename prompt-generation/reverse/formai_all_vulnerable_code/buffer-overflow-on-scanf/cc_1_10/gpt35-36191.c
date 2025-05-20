//FormAI DATASET v1.0 Category: Phone Book ; Style: minimalist
#include<stdio.h>
#include<string.h>

#define MAX_CONTACTS 100

//Structure to hold contact information
struct Contact {
    char name[50];
    char phone[15];
};

//Function to display the phonebook
void displayPhonebook(struct Contact phonebook[], int numContacts) {
    printf("-----PHONEBOOK-----\n");
    for (int i = 0; i < numContacts; i++) {
        printf("%d. %s - %s\n", i+1, phonebook[i].name, phonebook[i].phone);
    }
    printf("-------------------\n");
}

//Function to add a contact to the phonebook
void addContact(struct Contact phonebook[], int *numContacts) {
    if (*numContacts >= MAX_CONTACTS) {
        printf("Phonebook is full! Cannot add more contacts.\n");
        return;
    }
    printf("Enter name: ");
    scanf("%s", phonebook[*numContacts].name);
    printf("Enter phone number: ");
    scanf("%s", phonebook[*numContacts].phone);
    printf("Contact added successfully.\n");
    (*numContacts)++;
}

int main() {
    struct Contact phonebook[MAX_CONTACTS];
    int numContacts = 0;
    char choice;
    while (1) {
        printf("MENU:\n");
        printf("1. Display Phonebook\n");
        printf("2. Add Contact\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        switch (choice) {
            case '1':
                displayPhonebook(phonebook, numContacts);
                break;
            case '2':
                addContact(phonebook, &numContacts);
                break;
            case '3':
                printf("Exiting program...");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}