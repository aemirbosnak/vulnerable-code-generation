//FormAI DATASET v1.0 Category: Phone Book ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_PHONE_LEN 15
#define MAX_ENTRIES 100

// Define a struct for a phone book entry
typedef struct {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
} PhoneBookEntry;

// Declare necessary functions
void addEntry(PhoneBookEntry entries[], int *numEntries);
int findEntryIndex(PhoneBookEntry entries[], int numEntries, char *name);
void deleteEntry(PhoneBookEntry entries[], int *numEntries);
void searchEntries(PhoneBookEntry entries[], int numEntries, char *name);

int main() {
    PhoneBookEntry phoneBook[MAX_ENTRIES];
    int numEntries = 0;
    char choice = ' ';

    printf("Welcome to the Brave C Phone Book\n");

    // Loop until the user chooses to exit
    while (choice != 'E') {
        printf("\nPlease select an option:\n");
        printf("A: Add an entry\n");
        printf("D: Delete an entry\n");
        printf("S: Search for an entry\n");
        printf("E: Exit the program\n");

        // Read in the user's choice
        scanf(" %c", &choice);
        switch (choice) {
            case 'A':
                addEntry(phoneBook, &numEntries);
                break;
            case 'D':
                deleteEntry(phoneBook, &numEntries);
                break;
            case 'S':
                printf("Enter a name to search for: ");
                char searchName[MAX_NAME_LEN];
                scanf(" %[^\n]", searchName);
                searchEntries(phoneBook, numEntries, searchName);
                break;
            case 'E':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
                break;
        }
    }

    return 0;
}

// Function to add a new entry to the phone book
void addEntry(PhoneBookEntry entries[], int *numEntries) {
    // Make sure we have room for another entry
    if (*numEntries == MAX_ENTRIES) {
        printf("The phone book is full!\n");
        return;
    }

    printf("Enter a name: ");
    char newName[MAX_NAME_LEN];
    scanf(" %[^\n]", newName);

    printf("Enter a phone number: ");
    char newPhone[MAX_PHONE_LEN];
    scanf(" %[^\n]", newPhone);

    // Check if the entry already exists in the phone book
    if (findEntryIndex(entries, *numEntries, newName) != -1) {
        printf("This name is already in the phone book.\n");
        return;
    }

    // Add the new entry to the phone book
    strcpy(entries[*numEntries].name, newName);
    strcpy(entries[*numEntries].phone, newPhone);
    (*numEntries)++;
    printf("New entry added to the phone book.\n");
}

// Function to find the index of a phone book entry given a name
int findEntryIndex(PhoneBookEntry entries[], int numEntries, char *name) {
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            return i;
        }
    }
    return -1;  // Entry not found
}

// Function to delete a phone book entry
void deleteEntry(PhoneBookEntry entries[], int *numEntries) {
    printf("Enter a name to delete: ");
    char deleteName[MAX_NAME_LEN];
    scanf(" %[^\n]", deleteName);

    int deleteIndex = findEntryIndex(entries, *numEntries, deleteName);
    if (deleteIndex == -1) {
        printf("Entry not found.\n");
        return;
    }

    // Shift all entries after the deleted one down by one
    for (int i = deleteIndex; i < (*numEntries)-1; i++) {
        strcpy(entries[i].name, entries[i+1].name);
        strcpy(entries[i].phone, entries[i+1].phone);
    }
    (*numEntries)--;
    printf("Entry deleted from the phone book.\n");
}

// Function to search for a phone book entry given a name
void searchEntries(PhoneBookEntry entries[], int numEntries, char *name) {
    int searchIndex = findEntryIndex(entries, numEntries, name);
    if (searchIndex == -1) {
        printf("Entry not found.\n");
        return;
    }

    printf("Name: %s\n", entries[searchIndex].name);
    printf("Phone: %s\n", entries[searchIndex].phone);
}