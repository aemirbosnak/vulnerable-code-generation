//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SONGS 100
#define MAX_TITLE_LENGTH 100
#define MAX_ARTIST_LENGTH 50
#define MAX_ALBUM_LENGTH 100
#define MAX_GENRE_LENGTH 20
#define MAX_YEAR_LENGTH 4

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    char album[MAX_ALBUM_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    int year;
} Song;

void print_song(Song *song) {
    printf("Title: %s\n", song->title);
    printf("Artist: %s\n", song->artist);
    printf("Album: %s\n", song->album);
    printf("Genre: %s\n", song->genre);
    printf("Year: %d\n", song->year);
}

int compare_songs(const void *a, const void *b) {
    Song *song1 = (Song *)a;
    Song *song2 = (Song *)b;

    if (strcmp(song1->title, song2->title) < 0) {
        return -1;
    } else if (strcmp(song1->title, song2->title) > 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    Song songs[MAX_SONGS];
    int num_songs = 0;

    FILE *file = fopen("songs.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    Song temp_song;
    while (fscanf(file, "%s %s %s %s %d", temp_song.title, temp_song.artist, temp_song.album, temp_song.genre, &temp_song.year) == 5) {
        if (num_songs >= MAX_SONGS) {
            printf("Error: too many songs.\n");
            exit(1);
        }
        songs[num_songs] = temp_song;
        num_songs++;
    }

    fclose(file);

    qsort(songs, num_songs, sizeof(Song), compare_songs);

    for (int i = 0; i < num_songs; i++) {
        print_song(&songs[i]);
    }

    return 0;
}