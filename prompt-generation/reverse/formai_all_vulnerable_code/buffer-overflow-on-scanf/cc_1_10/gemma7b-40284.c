//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store music library information
struct MusicLibrary {
    char title[50];
    char artist[50];
    char genre[50];
    int year;
    struct MusicLibrary* next;
};

// Function to insert a music record into the library
void insertMusicRecord(struct MusicLibrary** head) {
    // Allocate memory for a new record
    struct MusicLibrary* newRecord = (struct MusicLibrary*)malloc(sizeof(struct MusicLibrary));

    // Get the record information from the user
    printf("Enter the title: ");
    scanf("%s", newRecord->title);

    printf("Enter the artist: ");
    scanf("%s", newRecord->artist);

    printf("Enter the genre: ");
    scanf("%s", newRecord->genre);

    printf("Enter the year: ");
    scanf("%d", &newRecord->year);

    // Insert the new record into the library
    if (*head == NULL) {
        *head = newRecord;
    } else {
        (*head)->next = newRecord;
    }

    // Print a confirmation message
    printf("Record inserted successfully!\n");
}

// Function to search the music library
void searchMusicLibrary(struct MusicLibrary* head) {
    // Get the search term from the user
    char searchTerm[50];
    printf("Enter the search term: ");
    scanf("%s", searchTerm);

    // Search the library for the record
    struct MusicLibrary* currentRecord = head;
    while (currentRecord) {
        // Check if the record title matches the search term
        if (strcmp(currentRecord->title, searchTerm) == 0) {
            // Print the record information
            printf("Title: %s\n", currentRecord->title);
            printf("Artist: %s\n", currentRecord->artist);
            printf("Genre: %s\n", currentRecord->genre);
            printf("Year: %d\n", currentRecord->year);
            printf("\n");
        }
        currentRecord = currentRecord->next;
    }

    // Print a message if no records are found
    if (currentRecord == NULL) {
        printf("No records found.\n");
    }
}

// Main function
int main() {
    // Create a music library
    struct MusicLibrary* head = NULL;

    // Insert some music records
    insertMusicRecord(&head);
    insertMusicRecord(&head);
    insertMusicRecord(&head);

    // Search the music library
    searchMusicLibrary(head);

    return 0;
}