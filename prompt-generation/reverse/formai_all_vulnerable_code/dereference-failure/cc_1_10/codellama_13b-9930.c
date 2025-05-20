//Code Llama-13B DATASET v1.0 Category: Music Library Management System ; Style: complex
// Music Library Management System
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define data structures
typedef struct {
    char title[50];
    char artist[50];
    char genre[50];
    int year;
} Song;

typedef struct {
    Song *songs;
    int num_songs;
} Library;

// Function to add a song to the library
void add_song(Library *library, Song song) {
    library->songs = realloc(library->songs, (library->num_songs + 1) * sizeof(Song));
    library->songs[library->num_songs] = song;
    library->num_songs++;
}

// Function to remove a song from the library
void remove_song(Library *library, int index) {
    if (index < 0 || index >= library->num_songs) {
        printf("Invalid index\n");
        return;
    }
    for (int i = index; i < library->num_songs - 1; i++) {
        library->songs[i] = library->songs[i + 1];
    }
    library->num_songs--;
    library->songs = realloc(library->songs, library->num_songs * sizeof(Song));
}

// Function to search for a song in the library
Song *search_song(Library *library, char *title) {
    for (int i = 0; i < library->num_songs; i++) {
        if (strcmp(library->songs[i].title, title) == 0) {
            return &library->songs[i];
        }
    }
    return NULL;
}

// Function to sort the songs in the library
void sort_songs(Library *library) {
    int i, j;
    Song temp;
    for (i = 0; i < library->num_songs - 1; i++) {
        for (j = i + 1; j < library->num_songs; j++) {
            if (strcmp(library->songs[i].title, library->songs[j].title) > 0) {
                temp = library->songs[i];
                library->songs[i] = library->songs[j];
                library->songs[j] = temp;
            }
        }
    }
}

// Function to print the songs in the library
void print_songs(Library *library) {
    for (int i = 0; i < library->num_songs; i++) {
        printf("%s - %s (%s, %d)\n", library->songs[i].title, library->songs[i].artist, library->songs[i].genre, library->songs[i].year);
    }
}

// Main function
int main() {
    Library library;
    library.num_songs = 0;
    library.songs = NULL;

    // Add some songs to the library
    add_song(&library, (Song){"Song 1", "Artist 1", "Genre 1", 2000});
    add_song(&library, (Song){"Song 2", "Artist 2", "Genre 2", 2001});
    add_song(&library, (Song){"Song 3", "Artist 3", "Genre 3", 2002});
    add_song(&library, (Song){"Song 4", "Artist 4", "Genre 4", 2003});
    add_song(&library, (Song){"Song 5", "Artist 5", "Genre 5", 2004});

    // Remove a song from the library
    remove_song(&library, 2);

    // Search for a song in the library
    Song *song = search_song(&library, "Song 3");
    if (song != NULL) {
        printf("Found song: %s - %s (%s, %d)\n", song->title, song->artist, song->genre, song->year);
    } else {
        printf("Song not found\n");
    }

    // Sort the songs in the library
    sort_songs(&library);

    // Print the songs in the library
    print_songs(&library);

    return 0;
}