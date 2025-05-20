//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define MAX_TITLE_LENGTH 50
#define MAX_ARTIST_LENGTH 50
#define MAX_ALBUM_LENGTH 50

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    char album[MAX_ALBUM_LENGTH];
} Song;

void print_song(Song *song) {
    printf("Title: %s\n", song->title);
    printf("Artist: %s\n", song->artist);
    printf("Album: %s\n", song->album);
}

int compare_song_titles(const void *a, const void *b) {
    Song *song1 = (Song *)a;
    Song *song2 = (Song *)b;

    return strcmp(song1->title, song2->title);
}

int compare_song_artists(const void *a, const void *b) {
    Song *song1 = (Song *)a;
    Song *song2 = (Song *)b;

    return strcmp(song1->artist, song2->artist);
}

int compare_song_albums(const void *a, const void *b) {
    Song *song1 = (Song *)a;
    Song *song2 = (Song *)b;

    return strcmp(song1->album, song2->album);
}

void sort_songs(Song *songs, int num_songs, int (*compare_func)(const void *, const void *)) {
    qsort(songs, num_songs, sizeof(Song), compare_func);
}

int main() {
    Song songs[MAX_SONGS];
    int num_songs = 0;

    while(num_songs < MAX_SONGS) {
        printf("Enter song title: ");
        scanf("%s", songs[num_songs].title);

        printf("Enter song artist: ");
        scanf("%s", songs[num_songs].artist);

        printf("Enter song album: ");
        scanf("%s", songs[num_songs].album);

        num_songs++;
    }

    sort_songs(songs, num_songs, compare_song_titles);

    for(int i = 0; i < num_songs; i++) {
        print_song(&songs[i]);
    }

    sort_songs(songs, num_songs, compare_song_artists);

    for(int i = 0; i < num_songs; i++) {
        print_song(&songs[i]);
    }

    sort_songs(songs, num_songs, compare_song_albums);

    for(int i = 0; i < num_songs; i++) {
        print_song(&songs[i]);
    }

    return 0;
}