//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 1000
#define MAX_NAME_LEN 100
#define MAX_ARTIST_LEN 100
#define MAX_ALBUM_LEN 100
#define MAX_GENRE_LEN 100
#define MAX_TRACK_LEN 100
#define MAX_YEAR_LEN 10
#define MAX_DURATION_LEN 20

typedef struct song {
    char name[MAX_NAME_LEN];
    char artist[MAX_ARTIST_LEN];
    char album[MAX_ALBUM_LEN];
    char genre[MAX_GENRE_LEN];
    char track[MAX_TRACK_LEN];
    char year[MAX_YEAR_LEN];
    char duration[MAX_DURATION_LEN];
} Song;

void addSong(Song* songs, int* numSongs) {
    printf("Enter song name: ");
    scanf("%s", songs[*numSongs].name);

    printf("Enter artist name: ");
    scanf("%s", songs[*numSongs].artist);

    printf("Enter album name: ");
    scanf("%s", songs[*numSongs].album);

    printf("Enter genre: ");
    scanf("%s", songs[*numSongs].genre);

    printf("Enter track number: ");
    scanf("%s", songs[*numSongs].track);

    printf("Enter year: ");
    scanf("%s", songs[*numSongs].year);

    printf("Enter duration (mm:ss): ");
    scanf("%s", songs[*numSongs].duration);

    (*numSongs)++;
}

void printSongs(Song* songs, int numSongs) {
    for (int i = 0; i < numSongs; i++) {
        printf("Song %d:\n", i + 1);
        printf("Name: %s\n", songs[i].name);
        printf("Artist: %s\n", songs[i].artist);
        printf("Album: %s\n", songs[i].album);
        printf("Genre: %s\n", songs[i].genre);
        printf("Track: %s\n", songs[i].track);
        printf("Year: %s\n", songs[i].year);
        printf("Duration: %s\n", songs[i].duration);
        printf("\n");
    }
}

void main() {
    Song songs[MAX_SONGS];
    int numSongs = 0;

    addSong(songs, &numSongs);
    addSong(songs, &numSongs);
    addSong(songs, &numSongs);
    addSong(songs, &numSongs);
    addSong(songs, &numSongs);

    printf("Songs:\n");
    printSongs(songs, numSongs);
}