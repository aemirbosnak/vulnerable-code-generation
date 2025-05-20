//FormAI DATASET v1.0 Category: Phone Book ; Style: calm
#include <stdio.h>
#include <string.h>

#define MAX_ENTRIES 100 // Maximum number of contacts that can be stored

// Contact struct to store name and phone number
struct Contact {
    char name[50];
    char number[20];
};

// Function to add a new contact
void addContact(struct Contact phonebook[], int* numContacts){
    // Check if phonebook already full
    if (*numContacts == MAX_ENTRIES){
        printf("Phonebook is already full!\n");
        return;
    }

    // Otherwise, prompt user for name and number and add to phonebook
    char name[50], number[20];
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter number: ");
    scanf("%s", number);

    // Create new contact struct and add to phonebook
    struct Contact newContact;
    strcpy(newContact.name, name);
    strcpy(newContact.number, number);

    phonebook[*numContacts] = newContact;
    *numContacts += 1;

    printf("New contact added successfully!\n");
}

// Function to search phonebook for contacts matching a given name
void searchContacts(struct Contact phonebook[], int numContacts){
    char name[50];
    printf("Enter name to search for: ");
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < numContacts; i++){
        if (strcmp(phonebook[i].name, name) == 0){
            printf("%s: %s\n", phonebook[i].name, phonebook[i].number);
            found = 1;
        }
    }

    if (!found){
        printf("No matching contacts found!\n");
    }
}

// Function to print all contacts in phonebook
void printContacts(struct Contact phonebook[], int numContacts){
    printf("Contacts:\n");
    for (int i = 0; i < numContacts; i++){
        printf("%s: %s\n", phonebook[i].name, phonebook[i].number);
    }
}

int main(){
    struct Contact phonebook[MAX_ENTRIES];
    int numContacts = 0;

    int choice = -1;
    while (choice != 0){
        printf("\nWhat would you like to do?\n");
        printf("1. Add a new contact\n");
        printf("2. Search for a contact\n");
        printf("3. Print all contacts\n");
        printf("0. Exit\n");

        scanf("%d", &choice);

        switch (choice){
            case 1:
                addContact(phonebook, &numContacts);
                break;
            case 2:
                searchContacts(phonebook, numContacts);
                break;
            case 3:
                printContacts(phonebook, numContacts);
                break;
            case 0:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }

    return 0;
}