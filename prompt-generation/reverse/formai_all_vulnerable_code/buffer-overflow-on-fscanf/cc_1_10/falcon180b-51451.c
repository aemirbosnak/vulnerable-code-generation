//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 1000

typedef struct {
    char title[100];
    char artist[100];
    char album[100];
    int duration;
} Song;

void readSongs(Song songs[]) {
    FILE *fp;
    int i = 0;

    fp = fopen("songs.txt", "r");

    if (fp == NULL) {
        printf("Error: songs.txt not found!\n");
        exit(1);
    }

    while (fscanf(fp, "%s %s %s %d\n", songs[i].title, songs[i].artist, songs[i].album, &songs[i].duration)!= EOF) {
        i++;
    }

    fclose(fp);
}

void printSongs(Song songs[]) {
    int i;

    for (i = 0; i < MAX_SONGS; i++) {
        if (songs[i].title[0]!= '\0') {
            printf("%d. %s - %s (%d)\n", i+1, songs[i].title, songs[i].artist, songs[i].duration);
        }
    }
}

void searchSongs(Song songs[], char *query) {
    int i;

    for (i = 0; i < MAX_SONGS; i++) {
        if (songs[i].title[0]!= '\0' && strstr(songs[i].title, query)!= NULL) {
            printf("%d. %s - %s (%d)\n", i+1, songs[i].title, songs[i].artist, songs[i].duration);
        }
    }
}

int main() {
    Song songs[MAX_SONGS];

    readSongs(songs);
    printSongs(songs);

    char query[100];
    printf("Enter search query: ");
    scanf("%s", query);
    searchSongs(songs, query);

    return 0;
}