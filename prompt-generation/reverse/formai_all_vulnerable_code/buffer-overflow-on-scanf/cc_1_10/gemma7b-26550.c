//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of entries
#define NUM_ENTRIES 100

// Define the structure of an entry
typedef struct Entry {
    char title[50];
    char content[1000];
    int rating;
    struct Entry* next;
} Entry;

// Create a linked list of entries
Entry* head = NULL;

// Function to add an entry
void addEntry() {
    // Allocate memory for a new entry
    Entry* newEntry = (Entry*)malloc(sizeof(Entry));

    // Get the entry title and content
    printf("Enter the title of the entry:");
    scanf("%s", newEntry->title);

    printf("Enter the content of the entry:");
    scanf("%s", newEntry->content);

    // Get the entry rating
    printf("Enter the rating of the entry (1-5):");
    scanf("%d", &newEntry->rating);

    // Add the entry to the linked list
    if (head == NULL) {
        head = newEntry;
    } else {
        newEntry->next = head;
        head = newEntry;
    }
}

// Function to display all entries
void displayEntries() {
    // Traverse the linked list of entries
    Entry* currentEntry = head;
    while (currentEntry) {
        // Print the entry title, content, and rating
        printf("Title: %s\n", currentEntry->title);
        printf("Content: %s\n", currentEntry->content);
        printf("Rating: %d\n", currentEntry->rating);
        printf("\n");
        currentEntry = currentEntry->next;
    }
}

// Function to find an entry by title
Entry* findEntryByTitle(char* title) {
    // Traverse the linked list of entries
    Entry* currentEntry = head;
    while (currentEntry) {
        // Check if the entry title matches the given title
        if (strcmp(currentEntry->title, title) == 0) {
            return currentEntry;
        }
        currentEntry = currentEntry->next;
    }
    return NULL;
}

// Function to update an entry
void updateEntry(Entry* entry) {
    // Get the entry title and content
    printf("Enter the new title of the entry:");
    scanf("%s", entry->title);

    printf("Enter the new content of the entry:");
    scanf("%s", entry->content);

    // Get the entry rating
    printf("Enter the new rating of the entry (1-5):");
    scanf("%d", &entry->rating);
}

// Function to delete an entry
void deleteEntry(Entry* entry) {
    // Remove the entry from the linked list
    Entry* previousEntry = NULL;
    Entry* currentEntry = head;
    while (currentEntry) {
        if (currentEntry == entry) {
            if (previousEntry) {
                previousEntry->next = currentEntry->next;
            } else {
                head = currentEntry->next;
            }
            free(currentEntry);
            return;
        }
        previousEntry = currentEntry;
        currentEntry = currentEntry->next;
    }
    return;
}

// Main function
int main() {
    // Add some entries
    addEntry();
    addEntry();
    addEntry();

    // Display all entries
    displayEntries();

    // Find an entry by title
    Entry* entry = findEntryByTitle("Entry 2");
    if (entry) {
        // Update the entry
        updateEntry(entry);

        // Display the updated entry
        displayEntries();
    }

    // Delete an entry
    deleteEntry(entry);

    // Display the updated entries
    displayEntries();

    return 0;
}