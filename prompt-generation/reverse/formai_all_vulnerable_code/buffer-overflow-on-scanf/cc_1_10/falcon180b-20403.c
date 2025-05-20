//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the structure for a phone book entry
typedef struct {
    char name[50];
    char phone[15];
} Entry;

// Function prototypes
void addEntry(Entry entries[], int *size);
void searchEntry(Entry entries[], int size, char *name);
void printEntries(Entry entries[], int size);

int main() {
    Entry entries[100];
    int size = 0;

    // Initialize the phone book
    addEntry(entries, &size);

    // Print the phone book
    printEntries(entries, size);

    // Search for an entry
    char name[50];
    printf("Enter a name to search for: ");
    scanf("%s", name);
    searchEntry(entries, size, name);

    return 0;
}

// Add a new entry to the phone book
void addEntry(Entry entries[], int *size) {
    printf("Enter a name: ");
    scanf("%s", entries[*size].name);

    printf("Enter a phone number: ");
    scanf("%s", entries[*size].phone);

    (*size)++;
}

// Search for an entry in the phone book
void searchEntry(Entry entries[], int size, char *name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Found entry:\n");
            printf("Name: %s\n", entries[i].name);
            printf("Phone: %s\n", entries[i].phone);
        }
    }
}

// Print all entries in the phone book
void printEntries(Entry entries[], int size) {
    if (size == 0) {
        printf("Phone book is empty.\n");
        return;
    }

    printf("Phone book:\n");
    for (int i = 0; i < size; i++) {
        printf("Name: %s\n", entries[i].name);
        printf("Phone: %s\n", entries[i].phone);
        printf("\n");
    }
}