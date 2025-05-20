//FormAI DATASET v1.0 Category: Music Library Management System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for music library entry
struct MusicEntry {
    char songName[50];
    char artist[50];
    char album[50];
    int yearReleased;
};

// Define function to display menu options
void displayMenu() {
    printf("\nMusic Library Management System\n");
    printf("1. Add new song\n");
    printf("2. View all songs\n");
    printf("3. Search for a song\n");
    printf("4. Delete a song\n");
    printf("5. Exit\n");
}

// Define function to add new music entry to library
void addSong(struct MusicEntry library[], int *numSongs) {
    printf("Enter song name: ");
    scanf("%s", library[*numSongs].songName);
    printf("Enter artist name: ");
    scanf("%s", library[*numSongs].artist);
    printf("Enter album name: ");
    scanf("%s", library[*numSongs].album);
    printf("Enter year released: ");
    scanf("%d", &library[*numSongs].yearReleased);
    (*numSongs)++;
}

// Define function to display all music entries in library
void viewLibrary(struct MusicEntry library[], int numSongs) {
    printf("\nAll songs in library:\n\n");
    for (int i = 0; i < numSongs; i++) {
        printf("%s | %s | %s | %d\n", library[i].songName, library[i].artist, library[i].album, library[i].yearReleased);
    }
}

// Define function to search for a specific song in library
void searchSong(struct MusicEntry library[], int numSongs) {
    char songName[50];
    printf("Enter song name to search for: ");
    scanf("%s", songName);
    int found = 0;
    for (int i = 0; i < numSongs; i++) {
        if (strcmp(library[i].songName, songName) == 0) {
            found = 1;
            printf("\nSong found:\n\n%s | %s | %s | %d\n", library[i].songName, library[i].artist, library[i].album, library[i].yearReleased);
        }
    }
    if (!found) {
        printf("\nSong not found.\n");
    }
}

// Define function to delete a song from library
void deleteSong(struct MusicEntry library[], int *numSongs) {
    char songName[50];
    printf("Enter song name to delete: ");
    scanf("%s", songName);
    int found = 0;
    for (int i = 0; i < *numSongs; i++) {
        if (strcmp(library[i].songName, songName) == 0) {
            found = 1;
            (*numSongs)--;
            for (int j = i; j < *numSongs; j++) {
                strcpy(library[j].songName, library[j+1].songName);
                strcpy(library[j].artist, library[j+1].artist);
                strcpy(library[j].album, library[j+1].album);
                library[j].yearReleased = library[j+1].yearReleased;
            }
            printf("\nSong deleted.\n");
            break;
        }
    }
    if (!found) {
        printf("\nSong not found.\n");
    }
}

int main() {
    struct MusicEntry library[100]; // Define array to hold up to 100 music entries
    int numSongs = 0; // Initialize number of songs in library
    int choice;
    displayMenu();
    do {
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addSong(library, &numSongs);
                break;
            case 2:
                viewLibrary(library, numSongs);
                break;
            case 3:
                searchSong(library, numSongs);
                break;
            case 4:
                deleteSong(library, &numSongs);
                break;
            case 5:
                printf("\nExiting program.\n");
                break;
            default:
                printf("\nInvalid choice.\n");
                break;
        }
    } while (choice != 5);
    return 0;
}