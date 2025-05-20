//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    int phone;
} Entry;

void addEntry(Entry entries[], int numEntries) {
    printf("Enter name: ");
    scanf("%s", entries[numEntries].name);
    printf("Enter address: ");
    scanf("%s", entries[numEntries].address);
    printf("Enter phone number: ");
    scanf("%d", &entries[numEntries].phone);
}

void displayEntry(Entry entry) {
    printf("Name: %s\n", entry.name);
    printf("Address: %s\n", entry.address);
    printf("Phone: %d\n\n", entry.phone);
}

void searchEntry(Entry entries[], int numEntries, char searchName[]) {
    int i;
    for(i=0; i<numEntries; i++) {
        if(strcmp(entries[i].name, searchName) == 0) {
            displayEntry(entries[i]);
            return;
        }
    }
    printf("Entry not found.\n");
}

int main() {
    Entry entries[MAX_ENTRIES];
    int numEntries = 0;

    printf("Welcome to the Phonebook Database!\n\n");
    while(numEntries < MAX_ENTRIES) {
        printf("1. Add an entry\n2. Search for an entry\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addEntry(entries, numEntries);
                numEntries++;
                break;
            case 2:
                printf("Enter name to search for: ");
                char searchName[MAX_NAME_LENGTH];
                scanf("%s", searchName);
                searchEntry(entries, numEntries, searchName);
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}