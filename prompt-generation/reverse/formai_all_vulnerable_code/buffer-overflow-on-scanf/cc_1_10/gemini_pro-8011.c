//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ENTRIES 100

typedef struct {
    char name[50];
    char number[20];
} PhoneEntry;

PhoneEntry phonebook[MAX_ENTRIES];
int numEntries = 0;

void addEntry() {
    if (numEntries == MAX_ENTRIES) {
        printf("Phonebook is full!\n");
        return;
    }
    printf("Enter name: ");
    scanf(" %[^\n]", phonebook[numEntries].name);
    printf("Enter number: ");
    scanf(" %[^\n]", phonebook[numEntries].number);
    numEntries++;
}

void searchEntry() {
    char name[50];
    printf("Enter name to search: ");
    scanf(" %[^\n]", name);
    int found = 0;
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Found: %s (%s)\n", phonebook[i].name, phonebook[i].number);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Entry not found!\n");
    }
}

void deleteEntry() {
    char name[50];
    printf("Enter name to delete: ");
    scanf(" %[^\n]", name);
    int found = 0;
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            for (int j = i; j < numEntries - 1; j++) {
                phonebook[j] = phonebook[j + 1];
            }
            numEntries--;
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Entry not found!\n");
    }
}

void listEntries() {
    if (numEntries == 0) {
        printf("Phonebook is empty!\n");
        return;
    }
    printf("Phonebook:\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%s (%s)\n", phonebook[i].name, phonebook[i].number);
    }
}

int main() {
    int choice;
    do {
        printf("1. Add Entry\n2. Search Entry\n3. Delete Entry\n4. List Entries\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                searchEntry();
                break;
            case 3:
                deleteEntry();
                break;
            case 4:
                listEntries();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);
    return 0;
}