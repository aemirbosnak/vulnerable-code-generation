//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int numEntries = 0;

void addEntry() {
    printf("Enter name (up to %d characters): ", MAX_NAME_LENGTH-1);
    scanf("%s", entries[numEntries].name);
    
    printf("Enter phone number (up to %d characters): ", MAX_NUMBER_LENGTH-1);
    scanf("%s", entries[numEntries].number);
    
    numEntries++;
}

void searchEntry() {
    char searchName[MAX_NAME_LENGTH];
    printf("Enter name to search for: ");
    scanf("%s", searchName);
    
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(entries[i].name, searchName) == 0) {
            printf("Name: %s\nPhone number: %s\n", entries[i].name, entries[i].number);
            return;
        }
    }
    
    printf("Entry not found.\n");
}

void deleteEntry() {
    printf("Enter name of entry to delete: ");
    char nameToDelete[MAX_NAME_LENGTH];
    scanf("%s", nameToDelete);
    
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(entries[i].name, nameToDelete) == 0) {
            for (int j = i; j < numEntries - 1; j++) {
                strcpy(entries[j].name, entries[j+1].name);
                strcpy(entries[j].number, entries[j+1].number);
            }
            numEntries--;
            return;
        }
    }
    
    printf("Entry not found.\n");
}

int main() {
    printf("Welcome to the phone book!\n");
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Add entry\n");
        printf("2. Search entry\n");
        printf("3. Delete entry\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        int choice;
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
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    
    return 0;
}