//FormAI DATASET v1.0 Category: Phone Book ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 30
#define MAX_NUMBER_LENGTH 15
#define MAX_ENTRIES 100

typedef struct PhoneBookEntry {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} PhoneBookEntry;

int numEntries = 0; // number of entries currently in phone book
PhoneBookEntry phoneBook[MAX_ENTRIES]; // array to store phone book entries

/**
 * Display the entire phone book.
 */
void displayPhoneBook() {
    printf("Phone Book:\n");
    printf("--------------------------\n");
    for (int i = 0; i < numEntries; i++) {
        PhoneBookEntry entry = phoneBook[i];
        printf("%s: %s\n", entry.name, entry.number);
    }
}

/**
 * Find a phone book entry by name.
 * @param name The name to search for.
 * @return The index of the entry, or -1 if not found.
 */
int findEntryByName(char *name) {
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

/**
 * Add a new phone book entry.
 * @param name The name of the entry.
 * @param number The phone number of the entry.
 */
void addEntry(char *name, char *number) {
    if (numEntries == MAX_ENTRIES) {
        printf("Error: phone book is full!\n");
        return;
    }

    if (findEntryByName(name) != -1) {
        printf("Error: entry already exists for %s\n", name);
        return;
    }

    PhoneBookEntry entry;
    strncpy(entry.name, name, MAX_NAME_LENGTH);
    entry.name[MAX_NAME_LENGTH - 1] = '\0'; // ensure null-terminated string

    strncpy(entry.number, number, MAX_NUMBER_LENGTH);
    entry.number[MAX_NUMBER_LENGTH - 1] = '\0'; // ensure null-terminated string

    phoneBook[numEntries++] = entry;
    printf("Added entry for %s\n", name);
}

/**
 * Remove an existing phone book entry by name.
 * @param name The name of the entry to remove.
 */
void removeEntry(char *name) {
    int index = findEntryByName(name);
    if (index == -1) {
        printf("Error: entry for %s not found\n", name);
        return;
    }

    // Shift entries after the removed entry back by one
    for (int i = index; i < numEntries - 1; i++) {
        phoneBook[i] = phoneBook[i + 1];
    }

    numEntries--;
    printf("Removed entry for %s\n", name);
}

int main() {
    char choice;
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];

    printf("C Phone Book Example\n");

    while (1) {
        printf("\nMenu\n");
        printf("--------------------------\n");
        printf("1. Display phone book\n");
        printf("2. Add entry\n");
        printf("3. Remove entry\n");
        printf("4. Quit\n");
        printf("Enter choice (1-4): ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                displayPhoneBook();
                break;
            case '2':
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone number: ");
                scanf("%s", number);
                addEntry(name, number);
                break;
            case '3':
                printf("Enter name: ");
                scanf("%s", name);
                removeEntry(name);
                break;
            case '4':
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}