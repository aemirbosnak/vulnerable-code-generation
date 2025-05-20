//Code Llama-13B DATASET v1.0 Category: Phone Book ; Style: modular
/*
 * Phone Book Example Program
 *
 * This program uses a modular design to store and manage phone book entries.
 *
 * Author: [Your Name]
 * Date:   [Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a phone book entry
typedef struct {
    char name[50];
    char phone[20];
} PhoneBookEntry;

// Define the structure for a phone book
typedef struct {
    int size;
    PhoneBookEntry *entries;
} PhoneBook;

// Function to create a new phone book
PhoneBook *createPhoneBook() {
    PhoneBook *pb = malloc(sizeof(PhoneBook));
    pb->size = 0;
    pb->entries = NULL;
    return pb;
}

// Function to add a new entry to the phone book
void addEntry(PhoneBook *pb, char *name, char *phone) {
    // Check if the phone book is full
    if (pb->size == 50) {
        printf("Phone book is full.\n");
        return;
    }

    // Allocate memory for the new entry
    PhoneBookEntry *newEntry = malloc(sizeof(PhoneBookEntry));
    strcpy(newEntry->name, name);
    strcpy(newEntry->phone, phone);

    // Add the new entry to the end of the phone book
    pb->entries = realloc(pb->entries, (pb->size + 1) * sizeof(PhoneBookEntry));
    pb->entries[pb->size] = *newEntry;
    pb->size++;
}

// Function to remove an entry from the phone book
void removeEntry(PhoneBook *pb, char *name) {
    // Find the entry with the given name
    int index = -1;
    for (int i = 0; i < pb->size; i++) {
        if (strcmp(pb->entries[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    // If the entry is not found, return
    if (index == -1) {
        printf("Entry not found.\n");
        return;
    }

    // Remove the entry from the phone book
    pb->size--;
    for (int i = index; i < pb->size; i++) {
        pb->entries[i] = pb->entries[i + 1];
    }
}

// Function to display the contents of the phone book
void displayPhoneBook(PhoneBook *pb) {
    printf("Phone Book:\n");
    for (int i = 0; i < pb->size; i++) {
        printf("%s: %s\n", pb->entries[i].name, pb->entries[i].phone);
    }
}

// Main function
int main() {
    // Create a new phone book
    PhoneBook *pb = createPhoneBook();

    // Add some entries to the phone book
    addEntry(pb, "John", "555-1234");
    addEntry(pb, "Jane", "555-5678");
    addEntry(pb, "Bob", "555-9012");

    // Display the contents of the phone book
    displayPhoneBook(pb);

    // Remove an entry from the phone book
    removeEntry(pb, "Jane");

    // Display the contents of the phone book again
    displayPhoneBook(pb);

    // Free the memory allocated for the phone book
    free(pb);

    return 0;
}