//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define MAX_NAME_LEN 100
#define MAX_ARTIST_LEN 100
#define MAX_ALBUM_LEN 100
#define MAX_GENRE_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    char artist[MAX_ARTIST_LEN];
    char album[MAX_ALBUM_LEN];
    char genre[MAX_GENRE_LEN];
} Song;

void print_song(Song *song) {
    printf("Name: %s\n", song->name);
    printf("Artist: %s\n", song->artist);
    printf("Album: %s\n", song->album);
    printf("Genre: %s\n", song->genre);
}

int compare_songs(Song *a, Song *b) {
    int result = strcmp(a->name, b->name);
    if (result!= 0) {
        return result;
    } else {
        result = strcmp(a->artist, b->artist);
        if (result!= 0) {
            return result;
        } else {
            return strcmp(a->album, b->album);
        }
    }
}

int main() {
    Song library[MAX_SONGS];
    int num_songs = 0;

    while (num_songs < MAX_SONGS && scanf("%s %s %s %s", library[num_songs].name, library[num_songs].artist, library[num_songs].album, library[num_songs].genre)!= EOF) {
        num_songs++;
    }

    for (int i = 0; i < num_songs; i++) {
        print_song(&library[i]);
    }

    qsort(library, num_songs, sizeof(Song), compare_songs);

    for (int i = 0; i < num_songs; i++) {
        print_song(&library[i]);
    }

    return 0;
}