//Code Llama-13B DATASET v1.0 Category: Music Library Management System ; Style: lively
// Music Library Management System Example Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
#include <time.h>

// Structures
typedef struct {
    char name[50];
    char artist[50];
    char album[50];
    int year;
    double price;
} Song;

typedef struct {
    Song *songs;
    int num_songs;
    int capacity;
} Library;

// Function Declarations
void init_library(Library *lib);
void add_song(Library *lib, const char *name, const char *artist, const char *album, int year, double price);
void remove_song(Library *lib, int index);
void print_library(Library *lib);
void sort_library(Library *lib);

// Main Function
int main() {
    Library lib;
    init_library(&lib);

    // Add some songs to the library
    add_song(&lib, "Song 1", "Artist 1", "Album 1", 2020, 10.99);
    add_song(&lib, "Song 2", "Artist 2", "Album 2", 2021, 11.99);
    add_song(&lib, "Song 3", "Artist 3", "Album 3", 2022, 12.99);

    // Remove a song from the library
    remove_song(&lib, 0);

    // Print the library
    print_library(&lib);

    // Sort the library by artist
    sort_library(&lib);

    // Print the library again
    print_library(&lib);

    return 0;
}

// Function Definitions
void init_library(Library *lib) {
    lib->num_songs = 0;
    lib->capacity = 100;
    lib->songs = (Song *) malloc(lib->capacity * sizeof(Song));
}

void add_song(Library *lib, const char *name, const char *artist, const char *album, int year, double price) {
    if (lib->num_songs == lib->capacity) {
        lib->capacity *= 2;
        lib->songs = (Song *) realloc(lib->songs, lib->capacity * sizeof(Song));
    }

    Song *song = &lib->songs[lib->num_songs];
    strcpy(song->name, name);
    strcpy(song->artist, artist);
    strcpy(song->album, album);
    song->year = year;
    song->price = price;

    lib->num_songs++;
}

void remove_song(Library *lib, int index) {
    if (index < 0 || index >= lib->num_songs) {
        return;
    }

    for (int i = index; i < lib->num_songs - 1; i++) {
        lib->songs[i] = lib->songs[i + 1];
    }

    lib->num_songs--;
}

void print_library(Library *lib) {
    for (int i = 0; i < lib->num_songs; i++) {
        printf("%d. %s by %s on %s (%d) - $%.2f\n", i + 1, lib->songs[i].name, lib->songs[i].artist, lib->songs[i].album, lib->songs[i].year, lib->songs[i].price);
    }
}

void sort_library(Library *lib) {
    int i, j;
    Song temp;
    for (i = 0; i < lib->num_songs - 1; i++) {
        for (j = i + 1; j < lib->num_songs; j++) {
            if (strcmp(lib->songs[i].artist, lib->songs[j].artist) > 0) {
                temp = lib->songs[i];
                lib->songs[i] = lib->songs[j];
                lib->songs[j] = temp;
            }
        }
    }
}