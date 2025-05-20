//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: futuristic
// Holographic Music Library Management System 2050

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data types
struct MusicEntry {
    char title[50]; 
    char artist[50];
    char genre[20];
    int year;
};

// Functions
void addEntry(struct MusicEntry *library);
void searchEntry(struct MusicEntry *library);
void deleteEntry(struct MusicEntry *library);
void listEntries(struct MusicEntry *library);

// Main function
int main() {
    // Initialize the library
    struct MusicEntry library[100];
    int numEntries = 0;

    // Main menu
    int choice;
    do {
        printf("**************************************************\n");
        printf("* Welcome to the Holographic Music Library System *\n");
        printf("**************************************************\n");
        printf("1. Add a music entry\n");
        printf("2. Search for a music entry\n");
        printf("3. Delete a music entry\n");
        printf("4. List all music entries\n");
        printf("5. Exit\n");
        printf("**************************************************\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Process the user's choice
        switch (choice) {
            case 1:
                addEntry(library);
                numEntries++;
                break;
            case 2:
                searchEntry(library);
                break;
            case 3:
                deleteEntry(library);
                numEntries--;
                break;
            case 4:
                listEntries(library);
                break;
            case 5:
                printf("Thank you for using the Holographic Music Library System!\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to add a new music entry to the library
void addEntry(struct MusicEntry *library) {
    // Get the user's input
    printf("Enter the title of the song: ");
    scanf(" %[^\n]%*c", library->title); 
    printf("Enter the artist of the song: ");
    scanf(" %[^\n]%*c", library->artist);
    printf("Enter the genre of the song: ");
    scanf(" %[^\n]%*c", library->genre);
    printf("Enter the year the song was released: ");
    scanf("%d", &library->year);
}

// Function to search for a music entry in the library
void searchEntry(struct MusicEntry *library) {
    // Get the user's input
    char searchTerm[50];
    printf("Enter the search term: ");
    scanf(" %[^\n]%*c", searchTerm);

    // Search the library for the entry
    int found = 0;
    for (int i = 0; i < 100; i++) {
        if (strcmp(library[i].title, searchTerm) == 0 || strcmp(library[i].artist, searchTerm) == 0 || strcmp(library[i].genre, searchTerm) == 0) {
            // Print the entry
            printf("Title: %s\n", library[i].title);
            printf("Artist: %s\n", library[i].artist);
            printf("Genre: %s\n", library[i].genre);
            printf("Year: %d\n", library[i].year);
            found = 1;
            break;
        }
    }

    // If the entry was not found, notify the user
    if (!found) {
        printf("No entry found matching the search term.\n");
    }
}

// Function to delete a music entry from the library
void deleteEntry(struct MusicEntry *library) {
    // Get the user's input
    char searchTerm[50];
    printf("Enter the title of the song you want to delete: ");
    scanf(" %[^\n]%*c", searchTerm);

    // Search the library for the entry
    int found = 0;
    for (int i = 0; i < 100; i++) {
        if (strcmp(library[i].title, searchTerm) == 0) {
            // Delete the entry
            for (int j = i; j < 100; j++) {
                library[j] = library[j + 1];
            }
            found = 1;
            break;
        }
    }

    // If the entry was not found, notify the user
    if (!found) {
        printf("No entry found matching the search term.\n");
    }
}

// Function to list all music entries in the library
void listEntries(struct MusicEntry *library) {
    // Print the entries
    for (int i = 0; i < 100; i++) {
        if (strcmp(library[i].title, "") != 0) {
            printf("Title: %s\n", library[i].title);
            printf("Artist: %s\n", library[i].artist);
            printf("Genre: %s\n", library[i].genre);
            printf("Year: %d\n\n", library[i].year);
        }
    }
}