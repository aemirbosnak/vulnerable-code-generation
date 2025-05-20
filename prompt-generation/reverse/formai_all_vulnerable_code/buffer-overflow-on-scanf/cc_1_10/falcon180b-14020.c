//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

// Define the database structure
typedef struct {
    char name[50];
    int age;
    char address[100];
} Entry;

// Function to add an entry to the database
void addEntry(Entry entries[], int *numEntries) {
    printf("Enter name: ");
    scanf("%s", entries[*numEntries].name);

    printf("Enter age: ");
    scanf("%d", &entries[*numEntries].age);

    printf("Enter address: ");
    scanf("%s", entries[*numEntries].address);

    (*numEntries)++;
}

// Function to display all entries in the database
void displayEntries(Entry entries[], int numEntries) {
    printf("\nDatabase:\n");
    for (int i = 0; i < numEntries; i++) {
        printf("Name: %s\nAge: %d\nAddress: %s\n", entries[i].name, entries[i].age, entries[i].address);
    }
}

// Function to search for an entry in the database by name
int searchEntry(Entry entries[], int numEntries, char *name) {
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    Entry entries[MAX_ENTRIES];
    int numEntries = 0;

    printf("Happy Database!\n");

    // Add some entries
    addEntry(entries, &numEntries);
    addEntry(entries, &numEntries);
    addEntry(entries, &numEntries);

    // Display all entries
    displayEntries(entries, numEntries);

    // Search for an entry
    char searchName[50];
    printf("Enter name to search: ");
    scanf("%s", searchName);

    int index = searchEntry(entries, numEntries, searchName);
    if (index!= -1) {
        printf("Found entry for %s:\n", searchName);
        displayEntries(entries, 1);
    } else {
        printf("Entry not found.\n");
    }

    return 0;
}