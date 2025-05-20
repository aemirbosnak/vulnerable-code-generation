//Code Llama-13B DATASET v1.0 Category: Music Library Management System ; Style: authentic
/*
 * C Music Library Management System
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures
typedef struct {
    char title[100];
    char artist[100];
    char genre[100];
    int year;
} Song;

typedef struct {
    char name[100];
    Song *songs;
    int num_songs;
} Artist;

// Functions
void print_song(Song *song) {
    printf("Title: %s\n", song->title);
    printf("Artist: %s\n", song->artist);
    printf("Genre: %s\n", song->genre);
    printf("Year: %d\n", song->year);
}

void print_artist(Artist *artist) {
    printf("Name: %s\n", artist->name);
    for (int i = 0; i < artist->num_songs; i++) {
        print_song(&artist->songs[i]);
    }
}

void add_song(Artist *artist, Song song) {
    artist->songs = realloc(artist->songs, (artist->num_songs + 1) * sizeof(Song));
    artist->songs[artist->num_songs] = song;
    artist->num_songs++;
}

void remove_song(Artist *artist, int index) {
    if (index < 0 || index >= artist->num_songs) {
        return;
    }

    for (int i = index; i < artist->num_songs - 1; i++) {
        artist->songs[i] = artist->songs[i + 1];
    }

    artist->num_songs--;
}

// Main function
int main() {
    // Initialize artist and songs
    Artist *artist = malloc(sizeof(Artist));
    strcpy(artist->name, "The Beatles");
    artist->num_songs = 0;
    artist->songs = NULL;

    // Add songs
    Song song1 = {"Hey Jude", "The Beatles", "Pop", 1968};
    Song song2 = {"I Want to Hold Your Hand", "The Beatles", "Pop", 1963};
    Song song3 = {"Yesterday", "The Beatles", "Pop", 1965};
    add_song(artist, song1);
    add_song(artist, song2);
    add_song(artist, song3);

    // Print artist
    print_artist(artist);

    // Remove song
    remove_song(artist, 1);

    // Print artist again
    print_artist(artist);

    // Cleanup
    free(artist);

    return 0;
}