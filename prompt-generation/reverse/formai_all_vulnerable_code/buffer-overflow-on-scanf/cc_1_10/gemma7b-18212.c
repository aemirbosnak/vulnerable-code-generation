//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of entries
#define MAX_ENTRIES 10

// Define the structure of an entry
typedef struct Entry {
    char title[50];
    char content[500];
    struct Entry* next;
} Entry;

// Create a linked list of entries
Entry* head = NULL;

// Function to add an entry to the linked list
void addEntry() {
    Entry* newEntry = malloc(sizeof(Entry));

    // Get the entry title and content from the user
    printf("Enter the title of the entry: ");
    scanf("%s", newEntry->title);

    printf("Enter the content of the entry: ");
    scanf("%s", newEntry->content);

    // Add the new entry to the list
    if (head == NULL) {
        head = newEntry;
    } else {
        head->next = newEntry;
    }

    // Print a confirmation message
    printf("Entry added.\n");
}

// Function to list all entries
void listEntries() {
    Entry* currentEntry = head;

    // Iterate over the list of entries
    while (currentEntry) {
        // Print the entry title and content
        printf("Title: %s\n", currentEntry->title);
        printf("Content: %s\n", currentEntry->content);
        printf("\n");
        currentEntry = currentEntry->next;
    }
}

// Function to delete an entry
void deleteEntry() {
    Entry* currentEntry = head;
    Entry* previousEntry = NULL;

    // Get the title of the entry to be deleted
    printf("Enter the title of the entry to delete: ");
    char titleToDelete[50];
    scanf("%s", titleToDelete);

    // Iterate over the list of entries
    while (currentEntry) {
        // Compare the entry title to the title to be deleted
        if (strcmp(currentEntry->title, titleToDelete) == 0) {
            // If the entry is the first entry, update the head of the list
            if (previousEntry == NULL) {
                head = currentEntry->next;
            } else {
                previousEntry->next = currentEntry->next;
            }

            // Free the memory of the entry
            free(currentEntry);

            // Print a confirmation message
            printf("Entry deleted.\n");
            return;
        }

        previousEntry = currentEntry;
        currentEntry = currentEntry->next;
    }

    // If the entry is not found, print an error message
    printf("Error: Entry not found.\n");
}

// Main function
int main() {
    // Add an entry
    addEntry();

    // List all entries
    listEntries();

    // Delete an entry
    deleteEntry();

    // List all entries again
    listEntries();

    return 0;
}