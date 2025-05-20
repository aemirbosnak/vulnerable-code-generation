//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define MAX_NAME_LEN 50
#define MAX_ARTIST_LEN 50
#define MAX_ALBUM_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char artist[MAX_ARTIST_LEN];
    char album[MAX_ALBUM_LEN];
    int duration;
} Song;

void readSongs(Song songs[]) {
    FILE *fp = fopen("songs.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open songs file.\n");
        exit(1);
    }
    int count = 0;
    while (fscanf(fp, "%s %s %s %d", songs[count].name, songs[count].artist, songs[count].album, &songs[count].duration)!= EOF) {
        count++;
    }
    fclose(fp);
}

void printSongs(Song songs[]) {
    printf("Name\tArtist\tAlbum\tDuration\n");
    for (int i = 0; i < MAX_SONGS; i++) {
        if (songs[i].name[0]!= '\0') {
            printf("%s\t%s\t%s\t%d\n", songs[i].name, songs[i].artist, songs[i].album, songs[i].duration);
        }
    }
}

void searchSongs(Song songs[], char *query) {
    printf("Search results:\n");
    for (int i = 0; i < MAX_SONGS; i++) {
        if (strstr(songs[i].name, query)!= NULL || strstr(songs[i].artist, query)!= NULL || strstr(songs[i].album, query)!= NULL) {
            printf("%s\t%s\t%s\t%d\n", songs[i].name, songs[i].artist, songs[i].album, songs[i].duration);
        }
    }
}

int main() {
    Song songs[MAX_SONGS];
    readSongs(songs);
    printSongs(songs);
    char query[MAX_NAME_LEN];
    printf("Enter a search query: ");
    scanf("%s", query);
    searchSongs(songs, query);
    return 0;
}