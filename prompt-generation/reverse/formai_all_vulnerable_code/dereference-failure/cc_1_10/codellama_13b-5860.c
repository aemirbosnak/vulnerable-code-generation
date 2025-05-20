//Code Llama-13B DATASET v1.0 Category: Phone Book ; Style: realistic
// C Phone Book Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store phone book entry
typedef struct {
    char name[50];
    char phone[15];
} Entry;

// Function to add a new entry to the phone book
void addEntry(Entry *phoneBook, int *size, int *capacity) {
    if (*size == *capacity) {
        *capacity *= 2;
        phoneBook = realloc(phoneBook, *capacity * sizeof(Entry));
    }
    printf("Enter name: ");
    fgets(phoneBook[*size].name, 50, stdin);
    printf("Enter phone number: ");
    fgets(phoneBook[*size].phone, 15, stdin);
    *size += 1;
}

// Function to search for an entry in the phone book
int searchEntry(Entry *phoneBook, int size, char *name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to display all entries in the phone book
void displayAllEntries(Entry *phoneBook, int size) {
    for (int i = 0; i < size; i++) {
        printf("%s: %s\n", phoneBook[i].name, phoneBook[i].phone);
    }
}

// Function to display a specific entry in the phone book
void displayEntry(Entry *phoneBook, int size, char *name) {
    int index = searchEntry(phoneBook, size, name);
    if (index != -1) {
        printf("%s: %s\n", phoneBook[index].name, phoneBook[index].phone);
    } else {
        printf("Entry not found.\n");
    }
}

int main() {
    // Create a new phone book with capacity of 10
    Entry *phoneBook = malloc(10 * sizeof(Entry));
    int size = 0;
    int capacity = 10;

    // Add some entries to the phone book
    addEntry(phoneBook, &size, &capacity);
    addEntry(phoneBook, &size, &capacity);
    addEntry(phoneBook, &size, &capacity);

    // Search for an entry in the phone book
    char name[50];
    printf("Enter name to search: ");
    fgets(name, 50, stdin);
    int index = searchEntry(phoneBook, size, name);
    if (index != -1) {
        printf("Found entry at index %d.\n", index);
    } else {
        printf("Entry not found.\n");
    }

    // Display all entries in the phone book
    displayAllEntries(phoneBook, size);

    // Display a specific entry in the phone book
    printf("Enter name to display: ");
    fgets(name, 50, stdin);
    displayEntry(phoneBook, size, name);

    // Free memory allocated for the phone book
    free(phoneBook);

    return 0;
}