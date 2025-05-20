//Code Llama-13B DATASET v1.0 Category: Phone Book ; Style: inquisitive
// A unique C Phone Book example program in a inquisitive style
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store phone book entries
typedef struct {
    char name[20];
    char phone[10];
} PhoneBookEntry;

// Function to add a phone book entry
void addEntry(PhoneBookEntry* phoneBook, int size) {
    // Prompt user for entry
    printf("Enter name: ");
    scanf("%s", phoneBook[size].name);
    printf("Enter phone number: ");
    scanf("%s", phoneBook[size].phone);
}

// Function to search for a phone book entry
void searchEntry(PhoneBookEntry* phoneBook, int size) {
    // Prompt user for search query
    printf("Enter name to search: ");
    char searchQuery[20];
    scanf("%s", searchQuery);

    // Search for entry
    for (int i = 0; i < size; i++) {
        if (strcmp(phoneBook[i].name, searchQuery) == 0) {
            printf("Found entry: %s - %s\n", phoneBook[i].name, phoneBook[i].phone);
            return;
        }
    }

    // If no entry found, print error message
    printf("Entry not found\n");
}

// Function to display all phone book entries
void displayEntries(PhoneBookEntry* phoneBook, int size) {
    for (int i = 0; i < size; i++) {
        printf("%s - %s\n", phoneBook[i].name, phoneBook[i].phone);
    }
}

int main() {
    // Initialize phone book
    PhoneBookEntry phoneBook[100];
    int size = 0;

    // Add some entries to the phone book
    addEntry(phoneBook, size++);
    addEntry(phoneBook, size++);
    addEntry(phoneBook, size++);

    // Search for an entry
    searchEntry(phoneBook, size);

    // Display all entries
    displayEntries(phoneBook, size);

    return 0;
}