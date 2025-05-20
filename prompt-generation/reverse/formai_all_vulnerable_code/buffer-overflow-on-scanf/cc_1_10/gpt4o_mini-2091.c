//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold song information
typedef struct {
    char title[100];
    char artist[100];
    char genre[50];
    int year;
} Song;

// Function prototypes
void displayMenu();
void addSong(Song *library, int *count);
void displaySongs(Song *library, int count);
void searchSong(Song *library, int count);
void performAction(int choice, Song *library, int *count);

// Maximum number of songs in the library
#define MAX_SONGS 100

int main() {
    Song library[MAX_SONGS];
    int songCount = 0;
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 5) {
            printf("Exiting program. Goodbye!\n");
            break;
        }

        performAction(choice, library, &songCount);
    }

    return 0;
}

// Function to display the main menu
void displayMenu() {
    printf("\n=== Music Library Management System ===\n");
    printf("1. Add a Song\n");
    printf("2. Display All Songs\n");
    printf("3. Search for a Song\n");
    printf("4. Total Songs in Library\n");
    printf("5. Exit\n");
}

// Function to add a song to the library
void addSong(Song *library, int *count) {
    if (*count >= MAX_SONGS) {
        printf("Library is full! Cannot add more songs.\n");
        return;
    }

    printf("Enter song title: ");
    getchar(); // clear the newline character from the input buffer
    fgets(library[*count].title, sizeof(library[*count].title), stdin);
    library[*count].title[strcspn(library[*count].title, "\n")] = 0; // Remove newline

    printf("Enter artist name: ");
    fgets(library[*count].artist, sizeof(library[*count].artist), stdin);
    library[*count].artist[strcspn(library[*count].artist, "\n")] = 0; // Remove newline
    
    printf("Enter genre: ");
    fgets(library[*count].genre, sizeof(library[*count].genre), stdin);
    library[*count].genre[strcspn(library[*count].genre, "\n")] = 0; // Remove newline

    printf("Enter year of release: ");
    scanf("%d", &library[*count].year);

    (*count)++;
    printf("Song added successfully!\n");
}

// Function to display all songs in the library
void displaySongs(Song *library, int count) {
    if (count == 0) {
        printf("No songs in library.\n");
        return;
    }

    printf("\n=== Songs in Library ===\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s, Artist: %s, Genre: %s, Year: %d\n",
               library[i].title, library[i].artist, library[i].genre, library[i].year);
    }
}

// Function to search for a song by title
void searchSong(Song *library, int count) {
    char searchTerm[100];
    printf("Enter the title of the song to search: ");
    getchar(); // clear the newline character from the input buffer
    fgets(searchTerm, sizeof(searchTerm), stdin);
    searchTerm[strcspn(searchTerm, "\n")] = 0; // Remove newline

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strstr(library[i].title, searchTerm) != NULL) {
            printf("Found - Title: %s, Artist: %s, Genre: %s, Year: %d\n", 
                   library[i].title, library[i].artist, library[i].genre, library[i].year);
            found = 1;
        }
    }

    if (!found) {
        printf("No matching song found.\n");
    }
}

// Function to perform an action based on menu choice
void performAction(int choice, Song *library, int *count) {
    switch (choice) {
        case 1:
            addSong(library, count);
            break;
        case 2:
            displaySongs(library, *count);
            break;
        case 3:
            searchSong(library, *count);
            break;
        case 4:
            printf("Total songs in library: %d\n", *count);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}