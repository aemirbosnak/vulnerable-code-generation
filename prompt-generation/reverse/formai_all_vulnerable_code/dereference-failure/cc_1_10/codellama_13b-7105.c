//Code Llama-13B DATASET v1.0 Category: Music Library Management System ; Style: Donald Knuth
/*
 * music_library.c
 *
 * A unique C Music Library Management System example program in a Donald Knuth style.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures
typedef struct {
    char *title;
    char *artist;
    char *genre;
    int year;
} Song;

typedef struct {
    Song *songs;
    int num_songs;
} MusicLibrary;

// Functions
void add_song(MusicLibrary *library, Song *song) {
    library->songs = realloc(library->songs, (library->num_songs + 1) * sizeof(Song));
    library->songs[library->num_songs] = *song;
    library->num_songs++;
}

void delete_song(MusicLibrary *library, int index) {
    if (index < 0 || index >= library->num_songs) {
        return;
    }

    for (int i = index; i < library->num_songs - 1; i++) {
        library->songs[i] = library->songs[i + 1];
    }

    library->num_songs--;
    library->songs = realloc(library->songs, library->num_songs * sizeof(Song));
}

void display_song(Song *song) {
    printf("Song: %s - %s (%d)\n", song->title, song->artist, song->year);
}

int main() {
    // Initialize the music library
    MusicLibrary library = {NULL, 0};

    // Add some songs to the library
    Song song1 = {"The Sound of Silence", "Simon & Garfunkel", "Classic Rock", 1965};
    Song song2 = {"Bohemian Rhapsody", "Queen", "Classic Rock", 1975};
    Song song3 = {"Stairway to Heaven", "Led Zeppelin", "Classic Rock", 1971};

    add_song(&library, &song1);
    add_song(&library, &song2);
    add_song(&library, &song3);

    // Delete a song from the library
    delete_song(&library, 1);

    // Display the remaining songs in the library
    for (int i = 0; i < library.num_songs; i++) {
        display_song(&library.songs[i]);
    }

    // Clean up
    free(library.songs);

    return 0;
}