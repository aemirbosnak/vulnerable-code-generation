//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define MAX_NAME 50
#define MAX_ARTIST 50
#define MAX_ALBUM 100
#define MAX_GENRE 50

typedef struct {
    char name[MAX_NAME];
    char artist[MAX_ARTIST];
    char album[MAX_ALBUM];
    char genre[MAX_GENRE];
    int duration;
} Song;

void addSong(Song* songs, int numSongs) {
    if (numSongs == MAX_SONGS) {
        printf("Library is full. Cannot add more songs.\n");
        return;
    }

    printf("Enter song name: ");
    scanf("%s", songs[numSongs].name);

    printf("Enter artist name: ");
    scanf("%s", songs[numSongs].artist);

    printf("Enter album name: ");
    scanf("%s", songs[numSongs].album);

    printf("Enter genre: ");
    scanf("%s", songs[numSongs].genre);

    printf("Enter song duration in seconds: ");
    scanf("%d", &songs[numSongs].duration);

    numSongs++;
}

void displaySongs(Song* songs, int numSongs) {
    printf("\nSongs in the library:\n");
    for (int i = 0; i < numSongs; i++) {
        printf("%d. %s - %s\n", i+1, songs[i].artist, songs[i].name);
    }
}

void searchSong(Song* songs, int numSongs, char* query) {
    int matches = 0;

    for (int i = 0; i < numSongs; i++) {
        if (strstr(songs[i].name, query) || strstr(songs[i].artist, query) || strstr(songs[i].album, query) || strstr(songs[i].genre, query)) {
            printf("%s\n", songs[i].name);
            matches++;
        }
    }

    if (matches == 0) {
        printf("No matches found.\n");
    }
}

int main() {
    Song songs[MAX_SONGS];
    int numSongs = 0;

    addSong(songs, numSongs);
    addSong(songs, numSongs);
    addSong(songs, numSongs);

    displaySongs(songs, numSongs);

    char query[MAX_NAME];
    printf("\nEnter a search query: ");
    scanf("%s", query);

    searchSong(songs, numSongs, query);

    return 0;
}