//FormAI DATASET v1.0 Category: Phone Book ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for the phonebook entry
typedef struct PhoneBookEntry {
    char name[50];
    char phoneNumber[20];
    struct PhoneBookEntry* next;
} PhoneBookEntry;

PhoneBookEntry* createEntry(char* name, char* phoneNumber) {
    // Allocate memory for the new entry
    PhoneBookEntry* newEntry = (PhoneBookEntry*) malloc(sizeof(PhoneBookEntry));
    if (newEntry == NULL) {
        printf("Error: Out of memory");
        return NULL;
    }
    
    // Set the fields of the new entry
    strcpy(newEntry->name, name);
    strcpy(newEntry->phoneNumber, phoneNumber);
    newEntry->next = NULL;
    
    return newEntry;
}

void addEntry(PhoneBookEntry** phoneBook, char* name, char* phoneNumber) {
    // Create a new phone book entry
    PhoneBookEntry* newEntry = createEntry(name, phoneNumber);
    if (newEntry == NULL) {
        printf("Error: Failed to create new entry");
        return;
    }
    
    // Add the new entry to the beginning of the phone book
    newEntry->next = *phoneBook;
    *phoneBook = newEntry;
}

void printPhoneBook(PhoneBookEntry* phoneBook) {
    // Print the column headings
    printf("%-20s %-20s\n", "Name", "Phone Number");
    
    // Print each phone book entry
    PhoneBookEntry* currentEntry = phoneBook;
    while (currentEntry != NULL) {
        printf("%-20s %-20s\n", currentEntry->name, currentEntry->phoneNumber);
        currentEntry = currentEntry->next;
    }
}

void searchPhoneBook(PhoneBookEntry* phoneBook, char* name) {
    // Search for the entry with the specified name
    PhoneBookEntry* currentEntry = phoneBook;
    while (currentEntry != NULL) {
        if (strcmp(currentEntry->name, name) == 0) {
            printf("Phone number for %s: %s\n", name, currentEntry->phoneNumber);
            return;
        }
        currentEntry = currentEntry->next;
    }
    
    printf("Entry not found for %s\n", name);
}

int main() {
    // Create an empty phone book
    PhoneBookEntry* phoneBook = NULL;
    
    // Add some entries to the phone book
    addEntry(&phoneBook, "Alice", "555-1234");
    addEntry(&phoneBook, "Bob", "555-5678");
    addEntry(&phoneBook, "Charlie", "555-9012");
    addEntry(&phoneBook, "David", "555-3456");
    addEntry(&phoneBook, "Eve", "555-7890");
    
    // Print the phone book
    printf("Phone book:\n");
    printPhoneBook(phoneBook);
    
    // Search for a phone number
    char name[50];
    printf("\nEnter a name to search for: ");
    scanf("%s", name);
    searchPhoneBook(phoneBook, name);
    
    // Free the memory used by the phone book
    PhoneBookEntry* currentEntry = phoneBook;
    while (currentEntry != NULL) {
        PhoneBookEntry* nextEntry = currentEntry->next;
        free(currentEntry);
        currentEntry = nextEntry;
    }
    
    return 0;
}