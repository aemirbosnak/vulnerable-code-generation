//FormAI DATASET v1.0 Category: Phone Book ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for phone book entries
typedef struct PhoneBookEntry {
    char name[50];
    char number[20];
    char email[50];
} PhoneBookEntry;

// Function to add a new entry to the phone book
void addEntry(PhoneBookEntry* phonebook, int* numEntries) {
    PhoneBookEntry newEntry;
    printf("Enter name: ");
    scanf("%s", newEntry.name);
    printf("Enter phone number: ");
    scanf("%s", newEntry.number);
    printf("Enter email address: ");
    scanf("%s", newEntry.email);
    phonebook[*numEntries] = newEntry;
    (*numEntries)++;
    printf("New entry added to phone book!\n");
}

// Function to search for an entry in the phone book
void searchEntry(PhoneBookEntry* phonebook, int numEntries) {
    char searchName[50];
    printf("Enter name to search for: ");
    scanf("%s", searchName);
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(searchName, phonebook[i].name) == 0) {
            printf("Name: %s\nPhone Number: %s\nEmail: %s\n", 
                    phonebook[i].name, phonebook[i].number, phonebook[i].email);
            return;
        }
    }
    printf("Entry not found in phone book.\n");
}

// Function to print all entries in the phone book
void printPhonebook(PhoneBookEntry* phonebook, int numEntries) {
    printf("Phone Book Entries:\n");
    for (int i = 0; i < numEntries; i++) {
        printf("Name: %s\nPhone Number: %s\nEmail: %s\n\n", 
                phonebook[i].name, phonebook[i].number, phonebook[i].email);
    }
}

int main() {
    // Declare a dynamic array to hold phone book entries
    PhoneBookEntry* phonebook = malloc(10 * sizeof(PhoneBookEntry));
    int numEntries = 0;
    int choice;
    do {
        printf("1. Add new entry\n");
        printf("2. Search for entry\n");
        printf("3. Print all entries\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addEntry(phonebook, &numEntries);
                break;
            case 2:
                searchEntry(phonebook, numEntries);
                break;
            case 3:
                printPhonebook(phonebook, numEntries);
                break;
            case 4:
                printf("Exiting phone book...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    // Free the memory allocated for the phone book
    free(phonebook);
    return 0;
}