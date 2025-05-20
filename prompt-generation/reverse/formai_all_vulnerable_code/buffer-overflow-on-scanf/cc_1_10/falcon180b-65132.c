//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define MAX_SONG_LENGTH 100

typedef struct {
    char title[MAX_SONG_LENGTH];
    char artist[MAX_SONG_LENGTH];
    char album[MAX_SONG_LENGTH];
    int length;
} Song;

void createSong(Song* song) {
    strcpy(song->title, "Unknown");
    strcpy(song->artist, "Unknown");
    strcpy(song->album, "Unknown");
    song->length = 0;
}

void addSong(Song* library, int numSongs, Song* song) {
    if (numSongs >= MAX_SONGS) {
        printf("Library is full.\n");
        return;
    }

    strcpy(library[numSongs].title, song->title);
    strcpy(library[numSongs].artist, song->artist);
    strcpy(library[numSongs].album, song->album);
    library[numSongs].length = song->length;

    numSongs++;
}

void displayLibrary(Song* library, int numSongs) {
    printf("Song Library:\n");
    for (int i = 0; i < numSongs; i++) {
        printf("%d. %s - %s (%s)\n", i+1, library[i].title, library[i].artist, library[i].album);
    }
}

void searchSong(Song* library, int numSongs, char* query) {
    int found = 0;
    for (int i = 0; i < numSongs; i++) {
        if (strstr(library[i].title, query) || strstr(library[i].artist, query) || strstr(library[i].album, query)) {
            printf("%d. %s - %s (%s)\n", i+1, library[i].title, library[i].artist, library[i].album);
            found = 1;
        }
    }

    if (!found) {
        printf("No results found.\n");
    }
}

int main() {
    Song library[MAX_SONGS];
    int numSongs = 0;

    createSong(&library[numSongs]);
    addSong(library, numSongs, &library[numSongs]);

    displayLibrary(library, numSongs);

    char query[MAX_SONG_LENGTH];
    printf("Search for a song: ");
    scanf("%s", query);
    searchSong(library, numSongs, query);

    return 0;
}