//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Entry;

Entry phoneBook[MAX_ENTRIES];
int entryCount = 0;

void addEntry();
void viewEntries();
void searchEntry();
void deleteEntry();
void displayMenu();
void clearInputBuffer();

int main() {
    int choice;

    do {
        displayMenu();
        printf("Select an option (0 to exit): ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                searchEntry();
                break;
            case 4:
                deleteEntry();
                break;
            case 0:
                printf("Exiting the phone book. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

void displayMenu() {
    printf("\n--- Phone Book Menu ---\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Search Entry\n");
    printf("4. Delete Entry\n");
    printf("0. Exit\n");
}

void addEntry() {
    if (entryCount < MAX_ENTRIES) {
        printf("Enter name: ");
        fgets(phoneBook[entryCount].name, NAME_LENGTH, stdin);
        phoneBook[entryCount].name[strcspn(phoneBook[entryCount].name, "\n")] = 0; // Remove newline

        printf("Enter phone number: ");
        fgets(phoneBook[entryCount].phone, PHONE_LENGTH, stdin);
        phoneBook[entryCount].phone[strcspn(phoneBook[entryCount].phone, "\n")] = 0; // Remove newline

        entryCount++;
        printf("Entry added successfully!\n");
    } else {
        printf("Phone book is full! Cannot add more entries.\n");
    }
}

void viewEntries() {
    if (entryCount == 0) {
        printf("No entries in the phone book.\n");
    } else {
        printf("\n---- Phone Book Entries ----\n");
        for (int i = 0; i < entryCount; i++) {
            printf("%d. Name: %s, Phone: %s\n", i + 1, phoneBook[i].name, phoneBook[i].phone);
        }
    }
}

void searchEntry() {
    char searchName[NAME_LENGTH];
    printf("Enter the name to search: ");
    fgets(searchName, NAME_LENGTH, stdin);
    searchName[strcspn(searchName, "\n")] = 0; // Remove newline

    int found = 0;
    for (int i = 0; i < entryCount; i++) {
        if (strcasecmp(phoneBook[i].name, searchName) == 0) {
            printf("Found Entry: Name: %s, Phone: %s\n", phoneBook[i].name, phoneBook[i].phone);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No entry found for the name: %s\n", searchName);
    }
}

void deleteEntry() {
    int idx;
    printf("Enter the index of the entry to delete (1-%d): ", entryCount);
    scanf("%d", &idx);
    clearInputBuffer();

    if (idx < 1 || idx > entryCount) {
        printf("Invalid index! No entry deleted.\n");
    } else {
        for (int i = idx - 1; i < entryCount - 1; i++) {
            phoneBook[i] = phoneBook[i + 1];
        }
        entryCount--;
        printf("Entry deleted successfully!\n");
    }
}

void clearInputBuffer() {
    while (getchar() != '\n') {
        // Clearing the buffer
    }
}