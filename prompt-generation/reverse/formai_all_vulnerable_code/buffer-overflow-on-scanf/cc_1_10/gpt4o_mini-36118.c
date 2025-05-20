//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256

typedef struct {
    char website[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} Entry;

Entry passwordManager[MAX_ENTRIES];
int entryCount = 0;

// Function prototypes
void addEntry();
void viewEntries();
void deleteEntry();
void clearInputBuffer();

int main() {
    int choice;

    do {
        printf("\n====================\n");
        printf(" Password Manager\n");
        printf("====================\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Delete Entry\n");
        printf("4. Exit\n");
        printf("====================\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch(choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                deleteEntry();
                break;
            case 4:
                printf("Exiting! Your secrets are safe! 🌟\n");
                break;
            default:
                printf("Invalid choice, try again! 🚫\n");
                break;
        }
    } while(choice != 4);

    return 0;
}

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Oops! Can't add more entries. Maximum reached! ⚠️\n");
        return;
    }

    Entry newEntry;
    printf("Enter website: ");
    fgets(newEntry.website, MAX_LENGTH, stdin);
    newEntry.website[strcspn(newEntry.website, "\n")] = 0; // Remove newline

    printf("Enter username: ");
    fgets(newEntry.username, MAX_LENGTH, stdin);
    newEntry.username[strcspn(newEntry.username, "\n")] = 0; // Remove newline

    printf("Enter password: ");
    fgets(newEntry.password, MAX_LENGTH, stdin);
    newEntry.password[strcspn(newEntry.password, "\n")] = 0; // Remove newline

    passwordManager[entryCount++] = newEntry;
    printf("Entry added successfully! 🎉\n");
}

void viewEntries() {
    if (entryCount == 0) {
        printf("No entries found. Feel free to add some! ✨\n");
        return;
    }

    printf("\n=== Your Password Entries ===\n");
    for(int i = 0; i < entryCount; i++) {
        printf("Entry %d:\n", i + 1);
        printf("Website: %s\n", passwordManager[i].website);
        printf("Username: %s\n", passwordManager[i].username);
        // Security first! We won't display the full password.
        printf("Password: ********\n");
        printf("============================\n");
    }
}

void deleteEntry() {
    if (entryCount == 0) {
        printf("No entries to delete! 🥺\n");
        return;
    }

    int entryNumber;
    printf("Enter the entry number to delete (1-%d): ", entryCount);
    scanf("%d", &entryNumber);
    clearInputBuffer();

    if (entryNumber < 1 || entryNumber > entryCount) {
        printf("Invalid entry number! 🚫\n");
        return;
    }

    for (int i = entryNumber - 1; i < entryCount - 1; i++) {
        passwordManager[i] = passwordManager[i + 1];
    }
    entryCount--;
    printf("Entry deleted successfully! 🗑️\n");
}

void clearInputBuffer() {
    while (getchar() != '\n');
}