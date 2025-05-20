//FormAI DATASET v1.0 Category: Phone Book ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 20
#define MAX_ENTRIES 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} PhoneBookEntry;

int numEntries = 0;
PhoneBookEntry entries[MAX_ENTRIES];

void addEntry(char *name, char *phone) {
    if (numEntries == MAX_ENTRIES) {
        printf("Phone book is full, cannot add any more entries.\n");
        return;
    }
    PhoneBookEntry newEntry;
    strcpy(newEntry.name, name);
    strcpy(newEntry.phone, phone);
    entries[numEntries] = newEntry;
    numEntries++;
}

void removeEntry(char *name) {
    int i;
    for (i = 0; i < numEntries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            int j;
            for (j = i; j < numEntries - 1; j++) {
                entries[j] = entries[j + 1];
            }
            numEntries--;
            printf("Entry removed successfully.\n");
            return;
        }
    }
    printf("Entry not found, cannot remove.\n");
}

void searchByName(char *name) {
    int i;
    for (i = 0; i < numEntries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Name: %s, Phone: %s\n", entries[i].name, entries[i].phone);
            return;
        }
    }
    printf("Entry not found.\n");
}

void searchByPhone(char *phone) {
    int i;
    for (i = 0; i < numEntries; i++) {
        if (strcmp(entries[i].phone, phone) == 0) {
            printf("Name: %s, Phone: %s\n", entries[i].name, entries[i].phone);
            return;
        }
    }
    printf("Entry not found.\n");
}

void printAllEntries() {
    int i;
    for (i = 0; i < numEntries; i++) {
        printf("Name: %s, Phone: %s\n", entries[i].name, entries[i].phone);
    }
}

int main() {
    char choice;
    while (1) {
        printf("Phone book application\n");
        printf("Enter your choice:\n");
        printf("a - Add entry\n");
        printf("r - Remove entry\n");
        printf("s - Search by name\n");
        printf("t - Search by phone\n");
        printf("p - Print all entries\n");
        printf("q - Quit\n");
        scanf(" %c", &choice);
        switch (choice) {
            case 'a': {
                char name[MAX_NAME_LENGTH];
                char phone[MAX_PHONE_LENGTH];
                printf("Enter name:\n");
                scanf(" %[^\n]", name);
                printf("Enter phone number:\n");
                scanf(" %[^\n]", phone);
                addEntry(name, phone);
                break;
            }
            case 'r': {
                char name[MAX_NAME_LENGTH];
                printf("Enter name to remove:\n");
                scanf(" %[^\n]", name);
                removeEntry(name);
                break;
            }
            case 's': {
                char name[MAX_NAME_LENGTH];
                printf("Enter name to search:\n");
                scanf(" %[^\n]", name);
                searchByName(name);
                break;
            }
            case 't': {
                char phone[MAX_PHONE_LENGTH];
                printf("Enter phone number to search:\n");
                scanf(" %[^\n]", phone);
                searchByPhone(phone);
                break;
            }
            case 'p': {
                printAllEntries();
                break;
            }
            case 'q': {
                printf("Quitting application.\n");
                exit(0);
            }
            default: {
                printf("Invalid choice, try again.\n");
            }
        }
    }
    return 0;
}