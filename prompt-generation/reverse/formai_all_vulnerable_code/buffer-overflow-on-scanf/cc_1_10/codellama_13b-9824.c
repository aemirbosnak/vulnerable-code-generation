//Code Llama-13B DATASET v1.0 Category: Phone Book ; Style: energetic
// A unique C Phone Book example program in an energetic style
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to represent a phone book entry
typedef struct {
    char name[20];
    char phone[15];
} Entry;

// Function to add a new entry to the phone book
void addEntry(Entry *phoneBook, int *numEntries) {
    printf("Enter name: ");
    scanf("%s", phoneBook[*numEntries].name);
    printf("Enter phone number: ");
    scanf("%s", phoneBook[*numEntries].phone);
    (*numEntries)++;
}

// Function to search for an entry in the phone book
void searchEntry(Entry *phoneBook, int numEntries) {
    char name[20];
    int found = 0;
    printf("Enter name to search for: ");
    scanf("%s", name);
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            printf("Found! Phone number: %s\n", phoneBook[i].phone);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Not found.\n");
    }
}

// Main function
int main() {
    // Initialize phone book array
    Entry phoneBook[100];
    int numEntries = 0;

    // Add entries to phone book
    printf("Adding entries to phone book...\n");
    addEntry(phoneBook, &numEntries);
    addEntry(phoneBook, &numEntries);
    addEntry(phoneBook, &numEntries);
    addEntry(phoneBook, &numEntries);
    addEntry(phoneBook, &numEntries);
    addEntry(phoneBook, &numEntries);
    addEntry(phoneBook, &numEntries);
    addEntry(phoneBook, &numEntries);
    addEntry(phoneBook, &numEntries);
    addEntry(phoneBook, &numEntries);
    printf("Phone book is now full.\n");

    // Search for an entry in the phone book
    printf("Searching for an entry...\n");
    searchEntry(phoneBook, numEntries);

    return 0;
}