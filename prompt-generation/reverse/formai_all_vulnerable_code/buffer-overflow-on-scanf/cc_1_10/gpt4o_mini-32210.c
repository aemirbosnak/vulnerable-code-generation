//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 50

typedef struct {
    char website[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} Entry;

void printMenu() {
    printf("\nPassword Management System\n");
    printf("1. Add a new entry\n");
    printf("2. View all entries\n");
    printf("3. Search for an entry\n");
    printf("4. Delete an entry\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

void addEntry(Entry entries[], int *count) {
    if (*count >= MAX_ENTRIES) {
        printf("Limit reached! Cannot add more entries.\n");
        return;
    }

    Entry newEntry;
    printf("Enter website: ");
    scanf("%s", newEntry.website);
    printf("Enter username: ");
    scanf("%s", newEntry.username);
    printf("Enter password: ");
    scanf("%s", newEntry.password);

    entries[*count] = newEntry;
    (*count)++;
    printf("Entry added successfully.\n");
}

void viewEntries(Entry entries[], int count) {
    if (count == 0) {
        printf("No entries to display.\n");
        return;
    }

    printf("\nStored Passwords:\n");
    for (int i = 0; i < count; i++) {
        printf("Website: %s, Username: %s, Password: %s\n", entries[i].website, entries[i].username, entries[i].password);
    }
}

void searchEntry(Entry entries[], int count) {
    char website[MAX_LENGTH];
    printf("Enter website to search: ");
    scanf("%s", website);

    for (int i = 0; i < count; i++) {
        if (strcasecmp(entries[i].website, website) == 0) {
            printf("Website: %s, Username: %s, Password: %s\n", entries[i].website, entries[i].username, entries[i].password);
            return;
        }
    }
    printf("Entry not found.\n");
}

void deleteEntry(Entry entries[], int *count) {
    char website[MAX_LENGTH];
    printf("Enter website to delete: ");
    scanf("%s", website);
    
    for (int i = 0; i < *count; i++) {
        if (strcasecmp(entries[i].website, website) == 0) {
            // Shift remaining entries
            for (int j = i; j < *count - 1; j++) {
                entries[j] = entries[j + 1];
            }
            (*count)--;
            printf("Entry deleted successfully.\n");
            return;
        }
    }
    printf("Entry not found.\n");
}

int main() {
    Entry entries[MAX_ENTRIES];
    int count = 0;
    int choice;

    while (1) {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry(entries, &count);
                break;
            case 2:
                viewEntries(entries, count);
                break;
            case 3:
                searchEntry(entries, count);
                break;
            case 4:
                deleteEntry(entries, &count);
                break;
            case 5:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}