//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

// Define the Music Library Management System structure
typedef struct MusicLibrary {
    char title[50];
    char artist[50];
    char genre[50];
    int year;
    struct MusicLibrary* next;
} MusicLibrary;

// Function to insert a new music entry into the library
void insertMusic(MusicLibrary* head) {
    // Allocate memory for the new music entry
    MusicLibrary* newMusic = (MusicLibrary*)malloc(sizeof(MusicLibrary));

    // Get the music entry details from the user
    printf("Enter the title: ");
    scanf("%s", newMusic->title);

    printf("Enter the artist: ");
    scanf("%s", newMusic->artist);

    printf("Enter the genre: ");
    scanf("%s", newMusic->genre);

    printf("Enter the year: ");
    scanf("%d", &newMusic->year);

    // Link the new music entry to the head of the library
    newMusic->next = head;
    head = newMusic;
}

// Function to search for music in the library
MusicLibrary* searchMusic(MusicLibrary* head, char* title) {
    // Iterate over the library to find the music entry
    MusicLibrary* currentMusic = head;
    while (currentMusic) {
        if (strcmp(currentMusic->title, title) == 0) {
            return currentMusic;
        }
        currentMusic = currentMusic->next;
    }

    // Return NULL if the music entry is not found
    return NULL;
}

// Function to update the music entry
void updateMusic(MusicLibrary* musicEntry) {
    // Get the music entry details from the user
    printf("Enter the new title: ");
    scanf("%s", musicEntry->title);

    printf("Enter the new artist: ");
    scanf("%s", musicEntry->artist);

    printf("Enter the new genre: ");
    scanf("%s", musicEntry->genre);

    printf("Enter the new year: ");
    scanf("%d", &musicEntry->year);
}

// Function to delete the music entry
void deleteMusic(MusicLibrary* head, MusicLibrary* musicEntry) {
    // If the music entry is the first entry in the library, delete the first entry
    if (musicEntry == head) {
        head = musicEntry->next;
    } else {
        MusicLibrary* previousMusic = musicEntry;
        MusicLibrary* currentMusic = head;
        while (currentMusic) {
            if (currentMusic->next == musicEntry) {
                previousMusic->next = musicEntry->next;
            }
            previousMusic = currentMusic;
            currentMusic = currentMusic->next;
        }
    }

    // Free the memory of the music entry
    free(musicEntry);
}

int main() {
    // Create the head of the music library
    MusicLibrary* head = NULL;

    // Insert some music entries into the library
    insertMusic(head);
    insertMusic(head);
    insertMusic(head);

    // Search for music in the library
    MusicLibrary* musicEntry = searchMusic(head, "The Dark Side of the Moon");

    // Update the music entry
    updateMusic(musicEntry);

    // Delete the music entry
    deleteMusic(head, musicEntry);

    return 0;
}