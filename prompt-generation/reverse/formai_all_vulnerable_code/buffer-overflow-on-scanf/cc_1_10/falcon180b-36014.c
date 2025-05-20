//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 100
#define MAX_NUMBER_LEN 20
#define MAX_ENTRIES 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
} Entry;

Entry phonebook[MAX_ENTRIES];
int numEntries = 0;

void addEntry() {
    if (numEntries >= MAX_ENTRIES) {
        printf("Phone book is full. Cannot add more entries.\n");
        return;
    }
    
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
    
    printf("Enter name (up to %d characters): ", MAX_NAME_LEN - 1);
    scanf("%s", name);
    
    printf("Enter phone number (up to %d characters): ", MAX_NUMBER_LEN - 1);
    scanf("%s", number);
    
    strcpy(phonebook[numEntries].name, name);
    strcpy(phonebook[numEntries].number, number);
    
    numEntries++;
    printf("Entry added successfully.\n");
}

void searchEntry() {
    char searchName[MAX_NAME_LEN];
    
    printf("Enter name to search: ");
    scanf("%s", searchName);
    
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(phonebook[i].name, searchName) == 0) {
            printf("Name: %s\n", phonebook[i].name);
            printf("Phone number: %s\n", phonebook[i].number);
            return;
        }
    }
    
    printf("Entry not found.\n");
}

void deleteEntry() {
    char searchName[MAX_NAME_LEN];
    
    printf("Enter name to delete: ");
    scanf("%s", searchName);
    
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(phonebook[i].name, searchName) == 0) {
            memset(phonebook[i].name, 0, sizeof(phonebook[i].name));
            memset(phonebook[i].number, 0, sizeof(phonebook[i].number));
            numEntries--;
            printf("Entry deleted successfully.\n");
            return;
        }
    }
    
    printf("Entry not found.\n");
}

void printAllEntries() {
    if (numEntries == 0) {
        printf("Phone book is empty.\n");
        return;
    }
    
    for (int i = 0; i < numEntries; i++) {
        printf("Name: %s\n", phonebook[i].name);
        printf("Phone number: %s\n", phonebook[i].number);
        printf("\n");
    }
}

int main() {
    int choice;
    
    do {
        printf("1. Add entry\n");
        printf("2. Search entry\n");
        printf("3. Delete entry\n");
        printf("4. Print all entries\n");
        printf("5. Exit\n");
        
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
                printAllEntries();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 5);
    
    return 0;
}