//FormAI DATASET v1.0 Category: Phone Book ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CONTACTS 50

typedef struct {
    char name[30];
    char phone_number[15];
} Contact;

void addContact(Contact[], int);
void displayContacts(Contact[], int);
void deleteContact(Contact[], int);
void searchContacts(Contact[], int);

int main() {
    Contact phonebook[MAX_CONTACTS];
    int num_contacts = 0;
    char choice;

    printf("Oh, how I long to add a love to my phonebook\n");
    printf("Shall I add 'Y' or 'N'? ");
    scanf("\n%c", &choice);

    while (choice == 'Y' || choice == 'y') {
        addContact(phonebook, num_contacts);
        num_contacts++;
        printf("\n%s has been added to the phonebook.\n", phonebook[num_contacts - 1].name);
        printf("\nDo you want to add more contacts? Y/N ");
        scanf("\n%c", &choice);
    }

    while (1) {
        printf("\nWhat would you like to do next?\n");
        printf("1. Display all contacts.\n");
        printf("2. Delete a contact.\n");
        printf("3. Search for a contact.\n");
        printf("4. Exit from the program.\n");
        printf("Enter your choice (1-4): ");

        int option;
        scanf("%d", &option);

        switch (option) {
            case 1:
                displayContacts(phonebook, num_contacts);
                break;
            case 2:
                deleteContact(phonebook, num_contacts);
                num_contacts--;
                break;
            case 3:
                searchContacts(phonebook, num_contacts);
                break;
            case 4:
                printf("\nGoodbye, my love.\n");
                return 0;
            default:
                printf("\nInvalid option. Please try again.\n");
        }
    }
}

void addContact(Contact phonebook[], int index) {
    printf("\nEnter the name of the contact: ");
    scanf("\n%[^\n]", phonebook[index].name);

    printf("Enter the phone number of the contact: ");
    scanf("%s", phonebook[index].phone_number);
}

void displayContacts(Contact phonebook[], int num_contacts) {
    if (num_contacts == 0) {
        printf("\nThe phonebook is empty.\n");
        return;
    }

    printf("\nContacts:\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("%d. %s - %s\n", i + 1, phonebook[i].name, phonebook[i].phone_number);
    }
}

void deleteContact(Contact phonebook[], int num_contacts) {
    if (num_contacts == 0) {
        printf("\nThe phonebook is empty.\n");
        return;
    }

    char name[30];
    printf("\nEnter the name of the contact you want to delete: ");
    scanf("\n%[^\n]", name);

    int index = -1;
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        printf("\n%s has been deleted from the phonebook.\n", phonebook[index].name);

        for (int i = index; i < num_contacts - 1; i++) {
            phonebook[i] = phonebook[i + 1];
        }
    } else {
        printf("\n%s was not found in the phonebook.\n", name);
    }
}

void searchContacts(Contact phonebook[], int num_contacts) {
    if (num_contacts == 0) {
        printf("\nThe phonebook is empty.\n");
        return;
    }

    char name[30];
    printf("\nEnter the name of the contact you want to search: ");
    scanf("\n%[^\n]", name);

    int index = -1;
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        printf("\n%s - %s\n", phonebook[index].name, phonebook[index].phone_number);
    } else {
        printf("\n%s was not found in the phonebook.\n", name);
    }
}