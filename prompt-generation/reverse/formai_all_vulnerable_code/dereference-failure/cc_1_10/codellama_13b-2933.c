//Code Llama-13B DATASET v1.0 Category: Music Library Management System ; Style: high level of detail
/// main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold information about a song
typedef struct {
    char title[50];
    char artist[50];
    char album[50];
    int duration;
} Song;

// Structure to hold information about a music library
typedef struct {
    int num_songs;
    Song* songs;
} MusicLibrary;

// Function to create a new music library
MusicLibrary* create_music_library() {
    MusicLibrary* library = malloc(sizeof(MusicLibrary));
    library->num_songs = 0;
    library->songs = NULL;
    return library;
}

// Function to add a song to a music library
void add_song_to_library(MusicLibrary* library, Song* song) {
    library->num_songs++;
    library->songs = realloc(library->songs, library->num_songs * sizeof(Song));
    library->songs[library->num_songs - 1] = *song;
}

// Function to remove a song from a music library
void remove_song_from_library(MusicLibrary* library, int index) {
    for (int i = index; i < library->num_songs - 1; i++) {
        library->songs[i] = library->songs[i + 1];
    }
    library->num_songs--;
    library->songs = realloc(library->songs, library->num_songs * sizeof(Song));
}

// Function to find a song in a music library
int find_song_in_library(MusicLibrary* library, char* title, char* artist) {
    for (int i = 0; i < library->num_songs; i++) {
        if (strcmp(library->songs[i].title, title) == 0 && strcmp(library->songs[i].artist, artist) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to print a music library
void print_music_library(MusicLibrary* library) {
    for (int i = 0; i < library->num_songs; i++) {
        printf("%d. %s - %s\n", i + 1, library->songs[i].title, library->songs[i].artist);
    }
}

int main() {
    MusicLibrary* library = create_music_library();
    Song song1 = {"Song 1", "Artist 1", "Album 1", 300};
    Song song2 = {"Song 2", "Artist 2", "Album 2", 300};
    Song song3 = {"Song 3", "Artist 3", "Album 3", 300};
    add_song_to_library(library, &song1);
    add_song_to_library(library, &song2);
    add_song_to_library(library, &song3);
    print_music_library(library);
    remove_song_from_library(library, 1);
    print_music_library(library);
    int index = find_song_in_library(library, "Song 1", "Artist 1");
    if (index != -1) {
        printf("Found song %s - %s at index %d\n", library->songs[index].title, library->songs[index].artist, index);
    } else {
        printf("Song not found\n");
    }
    return 0;
}