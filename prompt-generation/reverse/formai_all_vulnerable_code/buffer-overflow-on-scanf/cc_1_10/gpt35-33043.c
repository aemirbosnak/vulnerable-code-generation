//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum size for music library
#define MAX_SIZE 100

// Struct to hold music information
typedef struct song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
} Song;

// Function to print menu options
void printMenu() {
    printf("\n\n*** MUSIC LIBRARY MANAGEMENT SYSTEM ***\n");
    printf("\n1. VIEW LIBRARY\n");
    printf("2. ADD SONG\n");
    printf("3. REMOVE SONG\n");
    printf("4. EDIT SONG\n");
    printf("5. SEARCH SONG\n");
    printf("0. EXIT\n");
}

// Function to clear input buffer
void clearBuffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

// Function to add a new song to the library
void addSong(Song library[], int* numSongs) {
    // Check if music library is full
    if (*numSongs == MAX_SIZE) {
        printf("Error: music library is full.\n");
        return;
    }

    // Prompt user for song details
    printf("\nEnter song title:\n");
    fgets(library[*numSongs].title, 50, stdin);
    library[*numSongs].title[strcspn(library[*numSongs].title, "\n")] = 0;

    printf("Enter artist name:\n");
    fgets(library[*numSongs].artist, 50, stdin);
    library[*numSongs].artist[strcspn(library[*numSongs].artist, "\n")] = 0;

    printf("Enter album name:\n");
    fgets(library[*numSongs].album, 50, stdin);
    library[*numSongs].album[strcspn(library[*numSongs].album, "\n")] = 0;

    printf("Enter year of release:\n");
    scanf("%d", &library[*numSongs].year);

    // Increment number of songs in library
    (*numSongs)++;
}

// Function to remove a song from the library
void removeSong(Song library[], int* numSongs) {
    char title[50];
    int songIndex = -1;

    // Prompt user for song title to remove
    printf("\nEnter title of song to remove:\n");
    fgets(title, 50, stdin);
    title[strcspn(title, "\n")] = 0;

    // Search for song in library
    for (int i = 0; i < *numSongs; i++) {
        if (strcmp(library[i].title, title) == 0) {
            songIndex = i;
            break;
        }
    }

    // If song is found, remove it from library
    if (songIndex != -1) {
        for (int i = songIndex; i < *numSongs - 1; i++) {
            library[i] = library[i + 1];
        }
        (*numSongs)--;
        printf("Song successfully removed from library.\n");
    } else {
        printf("Error: song not found in library.\n");
    }
}

// Function to edit a song in the library
void editSong(Song library[], int numSongs) {
    char title[50];
    int songIndex = -1;

    // Prompt user for song title to edit
    printf("\nEnter title of song to edit:\n");
    fgets(title, 50, stdin);
    title[strcspn(title, "\n")] = 0;

    // Search for song in library
    for (int i = 0; i < numSongs; i++) {
        if (strcmp(library[i].title, title) == 0) {
            songIndex = i;
            break;
        }
    }

    // If song is found, prompt user for new song details and update it in the library
    if (songIndex != -1) {
        printf("\nEnter new song title (press ENTER to keep current value):\n");
        char newTitle[50];
        fgets(newTitle, 50, stdin);
        newTitle[strcspn(newTitle, "\n")] = 0;
        if (strcmp(newTitle, "") != 0) {
            strcpy(library[songIndex].title, newTitle);
        }

        printf("Enter new artist name (press ENTER to keep current value):\n");
        char newArtist[50];
        fgets(newArtist, 50, stdin);
        newArtist[strcspn(newArtist, "\n")] = 0;
        if (strcmp(newArtist, "") != 0) {
            strcpy(library[songIndex].artist, newArtist);
        }

        printf("Enter new album name (press ENTER to keep current value):\n");
        char newAlbum[50];
        fgets(newAlbum, 50, stdin);
        newAlbum[strcspn(newAlbum, "\n")] = 0;
        if (strcmp(newAlbum, "") != 0) {
            strcpy(library[songIndex].album, newAlbum);
        }

        printf("Enter new year of release (press ENTER to keep current value):\n");
        char newYearStr[50];
        fgets(newYearStr, 50, stdin);
        newYearStr[strcspn(newYearStr, "\n")] = 0;
        if (strcmp(newYearStr, "") != 0) {
            int newYear = atoi(newYearStr);
            library[songIndex].year = newYear;
        }

        printf("Song successfully edited.\n");
    } else {
        printf("Error: song not found in library.\n");
    }
}

// Function to search for a song(s) in the library and display the result(s)
void searchSong(Song library[], int numSongs) {
    char query[50];
    int numResults = 0;

    // Prompt user for search query
    printf("\nEnter search query:\n");
    fgets(query, 50, stdin);
    query[strcspn(query, "\n")] = 0;

    // Search for matches in library
    printf("Search results:\n");
    for (int i = 0; i < numSongs; i++) {
        if (strstr(library[i].title, query) || strstr(library[i].artist, query) || strstr(library[i].album, query)) {
            printf("%d. %s - %s [%s] (%d)\n", i + 1, library[i].title, library[i].artist, library[i].album, library[i].year);
            numResults++;
        }
    }

    if (numResults == 0) {
        printf("No results found.\n");
    }
}

// Main function
int main() {
    // Declare music library and number of songs in it
    Song library[MAX_SIZE];
    int numSongs = 0;

    // Variable to hold user's menu choice
    int choice;

    // Loop until user chooses to exit program
    do {
        // Print menu and prompt user for choice
        printMenu();
        printf("\n\nEnter your choice:\n");
        scanf("%d", &choice);
        clearBuffer();

        // Execute choice
        switch (choice) {
            case 0: // Exit program
                printf("Goodbye!\n");
                break;

            case 1: // View library
                if (numSongs == 0) {
                    printf("\nNo songs in music library.\n");
                } else {
                    printf("\n\n*** MUSIC LIBRARY ***\n");
                    for (int i = 0; i < numSongs; i++) {
                        printf("%d. %s - %s [%s] (%d)\n", i + 1, library[i].title, library[i].artist, library[i].album, library[i].year);
                    }
                }
                break;

            case 2: // Add song
                addSong(library, &numSongs);
                printf("Song successfully added to library.\n");
                break;

            case 3: // Remove song
                removeSong(library, &numSongs);
                break;

            case 4: // Edit song
                editSong(library, numSongs);
                break;

            case 5: // Search song
                searchSong(library, numSongs);
                break;

            default: // Invalid choice
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}