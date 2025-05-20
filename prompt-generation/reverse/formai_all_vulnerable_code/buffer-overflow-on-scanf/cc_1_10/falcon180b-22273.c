//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLES 100
#define MAX_ARTISTS 100
#define MAX_ALBUMS 100
#define MAX_GENRES 100

typedef struct {
    char title[MAX_TITLES];
    char artist[MAX_ARTISTS];
    char album[MAX_ALBUMS];
    char genre[MAX_GENRES];
} Song;

int main() {
    Song library[MAX_TITLES];
    int numSongs = 0;

    // Initialize library with default values
    strcpy(library[numSongs].title, "Unknown");
    strcpy(library[numSongs].artist, "Unknown");
    strcpy(library[numSongs].album, "Unknown");
    strcpy(library[numSongs].genre, "Unknown");

    numSongs++;

    // Add a song to the library
    Song newSong;
    printf("Enter song title: ");
    scanf("%s", newSong.title);
    printf("Enter song artist: ");
    scanf("%s", newSong.artist);
    printf("Enter song album: ");
    scanf("%s", newSong.album);
    printf("Enter song genre: ");
    scanf("%s", newSong.genre);

    library[numSongs] = newSong;
    numSongs++;

    // Print the library
    printf("\nLibrary:\n");
    for (int i = 0; i < numSongs; i++) {
        printf("%s - %s (%s) [%s]\n", library[i].title, library[i].artist, library[i].album, library[i].genre);
    }

    return 0;
}