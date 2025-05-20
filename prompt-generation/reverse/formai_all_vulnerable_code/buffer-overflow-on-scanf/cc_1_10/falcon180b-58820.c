//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define MAX_TITLE_LEN 80
#define MAX_ARTIST_LEN 80
#define MAX_ALBUM_LEN 100
#define MAX_GENRE_LEN 50

typedef struct {
    char title[MAX_TITLE_LEN];
    char artist[MAX_ARTIST_LEN];
    char album[MAX_ALBUM_LEN];
    char genre[MAX_GENRE_LEN];
    int duration;
    int year;
} Song;

void print_song(Song *song) {
    printf("Title: %s\n", song->title);
    printf("Artist: %s\n", song->artist);
    printf("Album: %s\n", song->album);
    printf("Genre: %s\n", song->genre);
    printf("Duration: %d seconds\n", song->duration);
    printf("Year: %d\n\n", song->year);
}

int compare_songs(const void *a, const void *b) {
    Song *song1 = (Song *)a;
    Song *song2 = (Song *)b;

    if (song1->year == song2->year) {
        return strcmp(song1->title, song2->title);
    } else {
        return song1->year - song2->year;
    }
}

int main() {
    Song library[MAX_SONGS];
    int num_songs = 0;

    printf("Welcome to the Post-Apocalyptic Music Library Management System!\n");

    while (num_songs < MAX_SONGS) {
        printf("Enter song information:\n");
        printf("Title: ");
        scanf("%s", library[num_songs].title);
        printf("Artist: ");
        scanf("%s", library[num_songs].artist);
        printf("Album: ");
        scanf("%s", library[num_songs].album);
        printf("Genre: ");
        scanf("%s", library[num_songs].genre);
        printf("Duration (in seconds): ");
        scanf("%d", &library[num_songs].duration);
        printf("Year: ");
        scanf("%d", &library[num_songs].year);

        num_songs++;
    }

    qsort(library, num_songs, sizeof(Song), compare_songs);

    printf("Songs sorted by year:\n");
    for (int i = 0; i < num_songs; i++) {
        print_song(&library[i]);
    }

    return 0;
}