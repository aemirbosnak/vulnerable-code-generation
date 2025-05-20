//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Donald Knuth
#include <stdio.h>

#define MAX_ENTRIES 100 // maximum number of entries that can be added
#define MAX_NAME_LEN 50 // maximum length of name for an entry

struct Entry {
    char name[MAX_NAME_LEN];
    int amount;
};

// function to add new entry
void addEntry(struct Entry* entries, int* numEntries) {
    if (*numEntries >= MAX_ENTRIES) {
        printf("Cannot add more entries. Maximum limit reached.\n");
        return;
    }

    struct Entry newEntry;

    printf("Enter the name for the new entry: ");
    scanf("%s", &newEntry.name);

    printf("Enter the amount for the new entry: ");
    scanf("%d", &newEntry.amount);

    entries[*numEntries] = newEntry;
    (*numEntries)++;
}

// function to display all entries
void displayEntries(struct Entry* entries, int numEntries) {
    if (numEntries == 0) {
        printf("No entries found.\n");
        return;
    }

    printf("Name\tAmount\n");
    printf("-------------------------\n");

    for (int i = 0; i < numEntries; i++) {
        printf("%s\t%d\n", entries[i].name, entries[i].amount);
    }
}

// function to display total expense
void displayTotal(struct Entry* entries, int numEntries) {
    int total = 0;

    for (int i = 0; i < numEntries; i++) {
        total += entries[i].amount;
    }

    printf("Total expense: %d\n", total);
}

// main function
int main() {
    int choice;
    struct Entry entries[MAX_ENTRIES];
    int numEntries = 0;

    do {
        printf("1. Add new entry\n");
        printf("2. Display all entries\n");
        printf("3. Display total expense\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addEntry(entries, &numEntries);
            break;

        case 2:
            displayEntries(entries, numEntries);
            break;

        case 3:
            displayTotal(entries, numEntries);
            break;

        case 4:
            printf("Exiting program\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    } while (choice != 4);

    return 0;
}