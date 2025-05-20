//Code Llama-13B DATASET v1.0 Category: Music Library Management System ; Style: rigorous
/*
 * C Music Library Management System Example Program
 *
 * This program demonstrates a basic music library management system using C.
 * It allows users to add, remove, and search for songs in a library.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define MAX_NAME_LEN 256
#define MAX_ALBUM_LEN 128

// Define a structure to represent a song
typedef struct {
    char name[MAX_NAME_LEN];
    char album[MAX_ALBUM_LEN];
    int year;
} Song;

// Define an array to store songs
Song songs[MAX_SONGS];

// Define a function to add a song to the library
void add_song(Song song) {
    // Check if the library is full
    if (sizeof(songs) == MAX_SONGS) {
        printf("Library is full, cannot add more songs\n");
        return;
    }

    // Add the song to the library
    songs[sizeof(songs) - 1] = song;
}

// Define a function to remove a song from the library
void remove_song(char *name) {
    // Check if the song exists in the library
    for (int i = 0; i < sizeof(songs); i++) {
        if (strcmp(songs[i].name, name) == 0) {
            // Remove the song from the library
            for (int j = i; j < sizeof(songs) - 1; j++) {
                songs[j] = songs[j + 1];
            }
            return;
        }
    }

    // If the song is not found, print an error message
    printf("Song not found in the library\n");
}

// Define a function to search for a song in the library
void search_song(char *name) {
    // Check if the song exists in the library
    for (int i = 0; i < sizeof(songs); i++) {
        if (strcmp(songs[i].name, name) == 0) {
            // Print the song information
            printf("Name: %s\nAlbum: %s\nYear: %d\n", songs[i].name, songs[i].album, songs[i].year);
            return;
        }
    }

    // If the song is not found, print an error message
    printf("Song not found in the library\n");
}

// Define a function to print all songs in the library
void print_songs() {
    // Check if the library is empty
    if (sizeof(songs) == 0) {
        printf("Library is empty\n");
        return;
    }

    // Print all songs in the library
    for (int i = 0; i < sizeof(songs); i++) {
        printf("Name: %s\nAlbum: %s\nYear: %d\n", songs[i].name, songs[i].album, songs[i].year);
    }
}

int main() {
    // Initialize the library
    int library_size = 0;

    // Add some songs to the library
    Song song1 = {"Song1", "Album1", 2022};
    Song song2 = {"Song2", "Album2", 2023};
    Song song3 = {"Song3", "Album3", 2024};
    add_song(song1);
    add_song(song2);
    add_song(song3);

    // Search for a song in the library
    search_song("Song2");

    // Remove a song from the library
    remove_song("Song1");

    // Print all songs in the library
    print_songs();

    return 0;
}