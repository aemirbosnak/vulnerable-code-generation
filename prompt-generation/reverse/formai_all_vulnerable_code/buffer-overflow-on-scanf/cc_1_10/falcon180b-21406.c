//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define MAX_NAME_LENGTH 50
#define MAX_ARTIST_LENGTH 50
#define MAX_ALBUM_LENGTH 50
#define MAX_GENRE_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    char album[MAX_ALBUM_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    int length;
    int rating;
} Song;

int main() {
    Song library[MAX_SONGS];
    int numSongs = 0;

    while (numSongs < MAX_SONGS) {
        printf("Enter song name: ");
        scanf("%s", library[numSongs].name);

        printf("Enter artist name: ");
        scanf("%s", library[numSongs].artist);

        printf("Enter album name: ");
        scanf("%s", library[numSongs].album);

        printf("Enter genre: ");
        scanf("%s", library[numSongs].genre);

        printf("Enter song length in seconds: ");
        scanf("%d", &library[numSongs].length);

        printf("Enter song rating (1-5): ");
        scanf("%d", &library[numSongs].rating);

        numSongs++;
    }

    printf("Songs in library:\n");
    for (int i = 0; i < numSongs; i++) {
        printf("%s by %s (%s) - %d seconds, rating: %d\n", library[i].name, library[i].artist, library[i].album, library[i].length, library[i].rating);
    }

    return 0;
}