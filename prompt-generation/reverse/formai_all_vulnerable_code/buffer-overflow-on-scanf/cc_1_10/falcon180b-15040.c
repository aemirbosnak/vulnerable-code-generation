//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SONGS 100
#define MAX_TITLE_LENGTH 100
#define MAX_ARTIST_LENGTH 50

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    int duration;
} Song;

int main() {
    Song library[MAX_SONGS];
    int numSongs = 0;
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    int duration;

    printf("Welcome to the Music Library Management System!\n");
    printf("Please enter the number of songs you want to add to the library:\n");
    scanf("%d", &numSongs);

    for (int i = 0; i < numSongs; i++) {
        printf("Please enter the title of song %d:\n", i+1);
        scanf("%s", title);
        strcpy(library[i].title, title);

        printf("Please enter the artist of song %d:\n", i+1);
        scanf("%s", artist);
        strcpy(library[i].artist, artist);

        printf("Please enter the duration of song %d in seconds:\n", i+1);
        scanf("%d", &duration);
        library[i].duration = duration;
    }

    printf("\nThe library now contains the following songs:\n");
    for (int i = 0; i < numSongs; i++) {
        printf("Song %d:\n", i+1);
        printf("Title: %s\n", library[i].title);
        printf("Artist: %s\n", library[i].artist);
        printf("Duration: %d seconds\n", library[i].duration);
    }

    return 0;
}