//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char title[100];
    char artist[100];
    char genre[50];
    char album[100];
    int duration;
} Song;

void addSong(Song *songs, int *numSongs) {
    printf("Enter song title: ");
    scanf("%s", songs[*numSongs].title);
    printf("Enter artist name: ");
    scanf("%s", songs[*numSongs].artist);
    printf("Enter genre: ");
    scanf("%s", songs[*numSongs].genre);
    printf("Enter album name: ");
    scanf("%s", songs[*numSongs].album);
    printf("Enter song duration in seconds: ");
    scanf("%d", &songs[*numSongs].duration);
    (*numSongs)++;
}

void printSongs(Song *songs, int numSongs) {
    printf("\nSong\tArtist\tGenre\tAlbum\tDuration\n");
    for (int i = 0; i < numSongs; i++) {
        printf("%s\t%s\t%s\t%s\t%d seconds\n", songs[i].title, songs[i].artist, songs[i].genre, songs[i].album, songs[i].duration);
    }
}

void searchSongs(Song *songs, int numSongs, char *query) {
    int count = 0;
    for (int i = 0; i < numSongs; i++) {
        if (strstr(songs[i].title, query) || strstr(songs[i].artist, query) || strstr(songs[i].genre, query) || strstr(songs[i].album, query)) {
            printf("%s\t%s\t%s\t%s\t%d seconds\n", songs[i].title, songs[i].artist, songs[i].genre, songs[i].album, songs[i].duration);
            count++;
        }
    }
    if (count == 0) {
        printf("No songs found.\n");
    }
}

int main() {
    Song songs[MAX_SIZE];
    int numSongs = 0;

    addSong(songs, &numSongs);
    addSong(songs, &numSongs);
    addSong(songs, &numSongs);

    printSongs(songs, numSongs);

    char query[100];
    printf("Enter search query: ");
    scanf("%s", query);
    searchSongs(songs, numSongs, query);

    return 0;
}