//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_SIZE 100

typedef struct {
    char name[MAX_ENTRY_SIZE];
    int age;
    char address[MAX_ENTRY_SIZE];
} Entry;

void addEntry(Entry *entries, int numEntries) {
    printf("Enter name: ");
    scanf("%s", entries[numEntries].name);
    printf("Enter age: ");
    scanf("%d", &entries[numEntries].age);
    printf("Enter address: ");
    scanf("%s", entries[numEntries].address);
    numEntries++;
}

void displayEntry(Entry entry) {
    printf("Name: %s\n", entry.name);
    printf("Age: %d\n", entry.age);
    printf("Address: %s\n", entry.address);
}

void deleteEntry(Entry *entries, int numEntries) {
    printf("Enter name to delete: ");
    scanf("%s", entries[numEntries-1].name);
    numEntries--;
}

void searchEntry(Entry *entries, int numEntries) {
    printf("Enter name to search: ");
    char name[MAX_ENTRY_SIZE];
    scanf("%s", name);
    for(int i = 0; i < numEntries; i++) {
        if(strcmp(entries[i].name, name) == 0) {
            displayEntry(entries[i]);
        }
    }
}

int main() {
    Entry entries[MAX_ENTRIES];
    int numEntries = 0;

    while(numEntries < MAX_ENTRIES) {
        int choice;
        printf("1. Add entry\n2. Display entry\n3. Delete entry\n4. Search entry\n5. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addEntry(entries, numEntries);
                break;
            case 2:
                printf("Displaying all entries:\n");
                for(int i = 0; i < numEntries; i++) {
                    displayEntry(entries[i]);
                }
                break;
            case 3:
                deleteEntry(entries, numEntries);
                break;
            case 4:
                searchEntry(entries, numEntries);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}