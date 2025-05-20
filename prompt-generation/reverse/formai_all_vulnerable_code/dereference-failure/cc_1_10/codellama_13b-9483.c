//Code Llama-13B DATASET v1.0 Category: Music Library Management System ; Style: light-weight
/*
 * C Music Library Management System Example Program
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the song structure
struct song {
    char *title;
    char *artist;
    char *genre;
    int length;
};

// Function to print a song
void print_song(struct song *song) {
    printf("Title: %s\n", song->title);
    printf("Artist: %s\n", song->artist);
    printf("Genre: %s\n", song->genre);
    printf("Length: %d\n", song->length);
}

// Function to add a song to the library
void add_song(struct song *song, char *title, char *artist, char *genre, int length) {
    song->title = title;
    song->artist = artist;
    song->genre = genre;
    song->length = length;
}

// Function to remove a song from the library
void remove_song(struct song *song) {
    free(song->title);
    free(song->artist);
    free(song->genre);
    free(song);
}

// Function to search for a song in the library
struct song *search_song(struct song *songs, int num_songs, char *title) {
    for (int i = 0; i < num_songs; i++) {
        if (strcmp(songs[i].title, title) == 0) {
            return &songs[i];
        }
    }
    return NULL;
}

int main() {
    // Create a library of songs
    struct song songs[100];
    int num_songs = 0;

    // Add some songs to the library
    add_song(&songs[num_songs++], "Song 1", "Artist 1", "Genre 1", 100);
    add_song(&songs[num_songs++], "Song 2", "Artist 2", "Genre 2", 200);
    add_song(&songs[num_songs++], "Song 3", "Artist 3", "Genre 3", 300);

    // Print all songs in the library
    for (int i = 0; i < num_songs; i++) {
        print_song(&songs[i]);
    }

    // Search for a song in the library
    struct song *found = search_song(songs, num_songs, "Song 1");
    if (found != NULL) {
        printf("Found song: %s\n", found->title);
    } else {
        printf("Song not found\n");
    }

    // Remove a song from the library
    remove_song(&songs[0]);

    // Print all songs in the library again
    for (int i = 0; i < num_songs; i++) {
        print_song(&songs[i]);
    }

    return 0;
}