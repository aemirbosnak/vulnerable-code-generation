//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000 // Maximum number of entries in the phone book

// Structure to store each entry in the phone book
typedef struct {
    char name[50]; // Name of the person
    char phone[20]; // Phone number of the person
} Entry;

// Function to compare two entries based on their names
int compareEntries(const void* a, const void* b) {
    Entry* entryA = (Entry*) a;
    Entry* entryB = (Entry*) b;
    return strcmp(entryA->name, entryB->name);
}

// Function to print the contents of the phone book
void printPhoneBook(Entry* phoneBook, int numEntries) {
    printf("Phone Book:\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%s - %s\n", phoneBook[i].name, phoneBook[i].phone);
    }
}

// Function to search for an entry in the phone book
int searchPhoneBook(Entry* phoneBook, int numEntries, char* name) {
    Entry key = {.name = name };
    Entry* result = bsearch(&key, phoneBook, numEntries, sizeof(Entry), compareEntries);
    if (result == NULL) {
        printf("Entry not found.\n");
        return -1;
    } else {
        printf("Found entry: %s - %s\n", result->name, result->phone);
        return 0;
    }
}

// Function to add an entry to the phone book
void addEntry(Entry* phoneBook, int* numEntries) {
    Entry newEntry;
    printf("Enter name: ");
    scanf("%s", newEntry.name);
    printf("Enter phone number: ");
    scanf("%s", newEntry.phone);
    if (*numEntries == MAX_ENTRIES) {
        printf("Phone book is full.\n");
        return;
    }
    (*numEntries)++;
    phoneBook[*numEntries - 1] = newEntry;
    qsort(phoneBook, *numEntries, sizeof(Entry), compareEntries);
}

// Function to delete an entry from the phone book
void deleteEntry(Entry* phoneBook, int* numEntries) {
    printf("Enter name to delete: ");
    char name[50];
    scanf("%s", name);
    int index = searchPhoneBook(phoneBook, *numEntries, name);
    if (index == -1) {
        printf("Entry not found.\n");
        return;
    }
    memmove(&phoneBook[index], &phoneBook[index + 1], (*numEntries - index - 1) * sizeof(Entry));
    (*numEntries)--;
}

// Main function
int main() {
    Entry phoneBook[MAX_ENTRIES];
    int numEntries = 0;

    // Initialize the phone book with some entries
    phoneBook[numEntries++] = (Entry) {.name = "John",.phone = "555-1234" };
    phoneBook[numEntries++] = (Entry) {.name = "Jane",.phone = "555-5678" };

    // Add an entry
    addEntry(phoneBook, &numEntries);

    // Print the phone book
    printPhoneBook(phoneBook, numEntries);

    // Search for an entry
    char name[50];
    printf("Enter name to search: ");
    scanf("%s", name);
    int result = searchPhoneBook(phoneBook, numEntries, name);

    // Delete an entry
    if (result == 0) {
        deleteEntry(phoneBook, &numEntries);
        printPhoneBook(phoneBook, numEntries);
    }

    return 0;
}