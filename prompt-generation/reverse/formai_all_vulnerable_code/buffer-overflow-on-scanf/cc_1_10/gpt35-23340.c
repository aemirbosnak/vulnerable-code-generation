//FormAI DATASET v1.0 Category: Phone Book ; Style: satisfied
#include <stdio.h>
#include <string.h>

// Structure for each phone book entry
struct PhoneBookEntry {
    char name[50];
    char number[20];
};

void addEntry(struct PhoneBookEntry *phonebook, int *numEntries);
void searchEntry(struct PhoneBookEntry *phonebook, int numEntries);
void deleteEntry(struct PhoneBookEntry *phonebook, int *numEntries);

int main() {
    struct PhoneBookEntry phonebook[100]; // Limit 100 entries
    int numEntries = 0;
    int menuOption;

    // Loop until user exits
    while (1) {
        printf("=== Phone Book ===\n");
        printf("1. Add Entry\n");
        printf("2. Search Entry\n");
        printf("3. Delete Entry\n");
        printf("4. Quit\n");

        printf("Enter menu option: ");
        scanf("%d", &menuOption);

        if (menuOption == 1) {
            addEntry(phonebook, &numEntries);
        } else if (menuOption == 2) {
            searchEntry(phonebook, numEntries);
        } else if (menuOption == 3) {
            deleteEntry(phonebook, &numEntries);
        } else if (menuOption == 4) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid menu option. Try again.\n");
        }
    }

    return 0;
}

// Function to add a new entry to the phone book
void addEntry(struct PhoneBookEntry *phonebook, int *numEntries) {
    if (*numEntries >= 100) {
        printf("Phone book is full. Cannot add entry.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", phonebook[*numEntries].name);
    printf("Enter phone number: ");
    scanf("%s", phonebook[*numEntries].number);
    (*numEntries)++;

    printf("Entry added successfully!\n");
}

// Function to search for an entry in the phone book
void searchEntry(struct PhoneBookEntry *phonebook, int numEntries) {
    char searchName[50];
    printf("Enter name to search: ");
    scanf("%s", searchName);

    int found = 0;
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(searchName, phonebook[i].name) == 0) {
            printf("Entry found:\n");
            printf("Name: %s\n", phonebook[i].name);
            printf("Phone Number: %s\n", phonebook[i].number);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Entry not found.\n");
    }
}

// Function to delete an entry from the phone book
void deleteEntry(struct PhoneBookEntry *phonebook, int *numEntries) {
    char searchName[50];
    printf("Enter name to delete: ");
    scanf("%s", searchName);

    int foundIndex = -1;
    for (int i = 0; i < *numEntries; i++) {
        if (strcmp(searchName, phonebook[i].name) == 0) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        printf("Entry not found.\n");
        return;
    }

    for (int i = foundIndex; i < *numEntries-1; i++) {
        strcpy(phonebook[i].name, phonebook[i+1].name);
        strcpy(phonebook[i].number, phonebook[i+1].number);
    }
    (*numEntries)--;
    printf("Entry deleted successfully!\n");
}