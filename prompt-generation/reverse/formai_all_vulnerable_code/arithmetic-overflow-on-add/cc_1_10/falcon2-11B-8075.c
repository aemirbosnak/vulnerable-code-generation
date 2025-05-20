//Falcon2-11B DATASET v1.0 Category: Music Library Management System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* title;
    int length;
} Song;

typedef struct {
    Song* songs;
    int capacity;
    int size;
} MusicLibrary;

void addSongToLibrary(MusicLibrary* lib, const char* title, int length) {
    if (lib->size == lib->capacity) {
        lib->capacity *= 2;
        lib->songs = realloc(lib->songs, lib->capacity * sizeof(Song));
    }

    Song newSong;
    newSong.title = malloc(strlen(title) + 1);
    strcpy(newSong.title, title);
    newSong.length = length;

    lib->songs[lib->size].title = newSong.title;
    lib->songs[lib->size].length = newSong.length;

    lib->size++;
}

void deleteSongFromLibrary(MusicLibrary* lib, int index) {
    for (int i = index; i < lib->size - 1; i++) {
        lib->songs[i] = lib->songs[i + 1];
    }
    lib->size--;
}

void searchSongInLibrary(MusicLibrary* lib, const char* title) {
    for (int i = 0; i < lib->size; i++) {
        if (strcmp(lib->songs[i].title, title) == 0) {
            printf("Song found: %s\n", lib->songs[i].title);
        }
    }
}

void displayMostPopularSongs(MusicLibrary* lib) {
    int totalLength = 0;
    int mostPopularSongIndex = 0;
    for (int i = 0; i < lib->size; i++) {
        totalLength += lib->songs[i].length;
        if (totalLength < lib->songs[mostPopularSongIndex].length) {
            mostPopularSongIndex = i;
        }
    }

    printf("Most popular song: %s\n", lib->songs[mostPopularSongIndex].title);
}

int main() {
    MusicLibrary lib;
    lib.capacity = 10;
    lib.size = 0;

    addSongToLibrary(&lib, "Song 1", 4);
    addSongToLibrary(&lib, "Song 2", 3);
    addSongToLibrary(&lib, "Song 3", 5);
    addSongToLibrary(&lib, "Song 4", 2);
    addSongToLibrary(&lib, "Song 5", 7);

    searchSongInLibrary(&lib, "Song 1");
    searchSongInLibrary(&lib, "Song 2");
    searchSongInLibrary(&lib, "Song 3");
    searchSongInLibrary(&lib, "Song 4");
    searchSongInLibrary(&lib, "Song 5");

    displayMostPopularSongs(&lib);

    deleteSongFromLibrary(&lib, 0);
    deleteSongFromLibrary(&lib, 2);

    searchSongInLibrary(&lib, "Song 1");
    searchSongInLibrary(&lib, "Song 2");
    searchSongInLibrary(&lib, "Song 3");
    searchSongInLibrary(&lib, "Song 4");
    searchSongInLibrary(&lib, "Song 5");

    displayMostPopularSongs(&lib);

    return 0;
}