//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for music library item
typedef struct {
    char title[100];
    char artist[100];
    int year;
    char genre[50];
} MusicItem;

// Define structure for music library
typedef struct {
    int size;
    int capacity;
    MusicItem *items;
} MusicLibrary;

// Function to initialize music library
void initMusicLibrary(MusicLibrary *library) {
    library->size = 0;
    library->capacity = 10;
    library->items = (MusicItem *)malloc(library->capacity * sizeof(MusicItem));
}

// Function to add music item to library
void addMusicItem(MusicLibrary *library, MusicItem item) {
    if (library->size == library->capacity) {
        library->capacity += 10;
        library->items = (MusicItem *)realloc(library->items, library->capacity * sizeof(MusicItem));
    }
    strcpy(library->items[library->size].title, item.title);
    strcpy(library->items[library->size].artist, item.artist);
    library->items[library->size].year = item.year;
    strcpy(library->items[library->size].genre, item.genre);
    library->size++;
}

// Function to display music library
void displayMusicLibrary(MusicLibrary library) {
    printf("Music Library:\n");
    printf("--------------------\n");
    for (int i = 0; i < library.size; i++) {
        printf("%s - %s (%d) - %s\n", library.items[i].title, library.items[i].artist, library.items[i].year, library.items[i].genre);
    }
}

// Function to search music library by artist
void searchByArtist(MusicLibrary library, char *artist) {
    printf("Search Results:\n");
    printf("--------------------\n");
    for (int i = 0; i < library.size; i++) {
        if (strcmp(library.items[i].artist, artist) == 0) {
            printf("%s - %s (%d) - %s\n", library.items[i].title, library.items[i].artist, library.items[i].year, library.items[i].genre);
        }
    }
}

// Function to search music library by genre
void searchByGenre(MusicLibrary library, char *genre) {
    printf("Search Results:\n");
    printf("--------------------\n");
    for (int i = 0; i < library.size; i++) {
        if (strcmp(library.items[i].genre, genre) == 0) {
            printf("%s - %s (%d) - %s\n", library.items[i].title, library.items[i].artist, library.items[i].year, library.items[i].genre);
        }
    }
}

int main() {
    MusicLibrary library;
    initMusicLibrary(&library);

    MusicItem item1 = {"Bohemian Rhapsody", "Queen", 1975, "Rock"};
    MusicItem item2 = {"Stairway to Heaven", "Led Zeppelin", 1971, "Rock"};
    MusicItem item3 = {"Thriller", "Michael Jackson", 1982, "Pop"};

    addMusicItem(&library, item1);
    addMusicItem(&library, item2);
    addMusicItem(&library, item3);

    displayMusicLibrary(library);

    searchByArtist(library, "Queen");
    searchByGenre(library, "Rock");

    return 0;
}