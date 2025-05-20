//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15

// Structure to hold the Phone Book entries
typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Entry;

// Global array to hold phonebook entries
Entry phonebook[MAX_ENTRIES];
int entryCount = 0;

// Function declarations
void addEntry();
void displayEntries();
void searchEntry();
void deleteEntry();
void showMenu();

int main() {
    while (1) {
        showMenu();
        char choice;
        printf("O noble user, choose thy fate: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                addEntry();
                break;
            case '2':
                displayEntries();
                break;
            case '3':
                searchEntry();
                break;
            case '4':
                deleteEntry();
                break;
            case '5':
                printf("To sleep, perchance to dream! Exiting...\n");
                exit(0);
            default:
                printf("Alas! An unrecognized choice. Choose wisely!\n");
        }
    }
    return 0;
}

void showMenu() {
    printf("\nPhantom Phone Book - A Tale of Love and Numbers\n");
    printf("1. Add an Entry\n");
    printf("2. Display Entries\n");
    printf("3. Search for an Entry\n");
    printf("4. Delete an Entry\n");
    printf("5. Exit this realm\n");
}

void addEntry() {
    if (entryCount == MAX_ENTRIES) {
        printf("Lo! The book is full! Cannot add more entries.\n");
        return;
    }
    printf("Enter the name of the fair maiden or gallant sir: ");
    scanf(" %[^\n]%*c", phonebook[entryCount].name);
    printf("Enter their noble phone number: ");
    scanf(" %[^\n]%*c", phonebook[entryCount].phone);
    entryCount++;
    printf("A new entry hath been added to our chronicles!\n");
}

void displayEntries() {
    if (entryCount == 0) {
        printf("The book lies barren, empty as Juliet's heart without Romeo...\n");
        return;
    }
    printf("\nAll Entries in the Phone Book:\n");
    for (int i = 0; i < entryCount; i++) {
        printf("%d. %s - %s\n", i + 1, phonebook[i].name, phonebook[i].phone);
    }
}

void searchEntry() {
    printf("Enter the name to seek in this tragic tale: ");
    char searchName[NAME_LENGTH];
    scanf(" %[^\n]%*c", searchName);
    
    int found = 0;
    for (int i = 0; i < entryCount; i++) {
        if (strcasecmp(phonebook[i].name, searchName) == 0) {
            printf("Found! %s - %s\n", phonebook[i].name, phonebook[i].phone);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Alas! No entry found for the noble name: %s\n", searchName);
    }
}

void deleteEntry() {
    printf("Enter the name of the entry to be purged from existence: ");
    char deleteName[NAME_LENGTH];
    scanf(" %[^\n]%*c", deleteName);
    
    int i, found = -1;
    for (i = 0; i < entryCount; i++) {
        if (strcasecmp(phonebook[i].name, deleteName) == 0) {
            found = i;
            break;
        }
    }
    
    if (found != -1) {
        for (int j = found; j < entryCount - 1; j++) {
            phonebook[j] = phonebook[j + 1];
        }
        entryCount--;
        printf("The cruel hand of fate hath removed entry: %s\n", deleteName);
    } else {
        printf("Alas, the entry does not exist in our tragic tale.\n");
    }
}