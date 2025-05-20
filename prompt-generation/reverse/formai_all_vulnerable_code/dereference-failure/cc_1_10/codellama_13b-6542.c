//Code Llama-13B DATASET v1.0 Category: Music Library Management System ; Style: curious
/*
* Music Library Management System
* Author: [Your Name]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the structure for a song
typedef struct {
    char* artist;
    char* title;
    int release_year;
    char* genre;
    float duration;
} Song;

// Define the structure for a music library
typedef struct {
    Song* songs;
    int num_songs;
} Library;

// Function to create a new song
Song* create_song(char* artist, char* title, int release_year, char* genre, float duration) {
    Song* song = malloc(sizeof(Song));
    song->artist = artist;
    song->title = title;
    song->release_year = release_year;
    song->genre = genre;
    song->duration = duration;
    return song;
}

// Function to add a song to a library
void add_song_to_library(Library* library, Song* song) {
    library->songs = realloc(library->songs, (library->num_songs + 1) * sizeof(Song));
    library->songs[library->num_songs] = *song;
    library->num_songs++;
}

// Function to remove a song from a library
void remove_song_from_library(Library* library, int index) {
    free(library->songs[index].artist);
    free(library->songs[index].title);
    free(library->songs[index].genre);
    for (int i = index; i < library->num_songs - 1; i++) {
        library->songs[i] = library->songs[i + 1];
    }
    library->num_songs--;
}

// Function to search for a song in a library
Song* search_song_in_library(Library* library, char* artist, char* title) {
    for (int i = 0; i < library->num_songs; i++) {
        if (strcmp(library->songs[i].artist, artist) == 0 && strcmp(library->songs[i].title, title) == 0) {
            return &library->songs[i];
        }
    }
    return NULL;
}

// Function to print the details of a song
void print_song_details(Song* song) {
    printf("Artist: %s\n", song->artist);
    printf("Title: %s\n", song->title);
    printf("Release Year: %d\n", song->release_year);
    printf("Genre: %s\n", song->genre);
    printf("Duration: %.2f\n", song->duration);
}

// Function to print the details of all songs in a library
void print_library_details(Library* library) {
    for (int i = 0; i < library->num_songs; i++) {
        printf("\nSong %d:\n", i + 1);
        print_song_details(&library->songs[i]);
    }
}

// Function to sort the songs in a library by artist
void sort_songs_by_artist(Library* library) {
    Song temp;
    for (int i = 0; i < library->num_songs - 1; i++) {
        for (int j = i + 1; j < library->num_songs; j++) {
            if (strcmp(library->songs[i].artist, library->songs[j].artist) > 0) {
                temp = library->songs[i];
                library->songs[i] = library->songs[j];
                library->songs[j] = temp;
            }
        }
    }
}

int main() {
    Library* library = malloc(sizeof(Library));
    library->num_songs = 0;
    library->songs = NULL;

    // Add some songs to the library
    add_song_to_library(library, create_song("The Beatles", "Yesterday", 1965, "Rock", 3.14));
    add_song_to_library(library, create_song("Michael Jackson", "Billie Jean", 1983, "Pop", 4.56));
    add_song_to_library(library, create_song("Queen", "Bohemian Rhapsody", 1975, "Rock", 5.99));

    // Search for a song in the library
    Song* song = search_song_in_library(library, "The Beatles", "Yesterday");
    if (song != NULL) {
        printf("Found the song!\n");
        print_song_details(song);
    } else {
        printf("Song not found.\n");
    }

    // Remove a song from the library
    remove_song_from_library(library, 0);
    printf("Song removed.\n");

    // Print the details of all songs in the library
    print_library_details(library);

    // Sort the songs by artist
    sort_songs_by_artist(library);
    printf("Songs sorted by artist.\n");

    // Print the details of all songs in the library again
    print_library_details(library);

    return 0;
}