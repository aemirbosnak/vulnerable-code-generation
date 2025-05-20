//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_SONGS 1000

typedef struct {
    char title[50];
    char artist[50];
    char album[50];
    int duration;
} Song;

void add_song(Song songs[], int num_songs) {
    if (num_songs >= MAX_NUM_SONGS) {
        printf("Error: Song library is full.\n");
        return;
    }

    Song new_song;
    printf("Enter song title: ");
    scanf("%s", new_song.title);
    printf("Enter artist name: ");
    scanf("%s", new_song.artist);
    printf("Enter album name: ");
    scanf("%s", new_song.album);
    printf("Enter song duration (in seconds): ");
    scanf("%d", &new_song.duration);

    songs[num_songs] = new_song;
    num_songs++;
}

void display_songs(Song songs[], int num_songs) {
    printf("\nSongs in the library:\n");
    printf("-----------------------------------\n");

    for (int i = 0; i < num_songs; i++) {
        printf("%d. %s - %s (%s)\n", i + 1, songs[i].title, songs[i].artist, songs[i].album);
    }
}

void search_song(Song songs[], int num_songs, char search_key[]) {
    int found = 0;

    printf("\nSearch results:\n");
    printf("-----------------------------------\n");

    for (int i = 0; i < num_songs; i++) {
        if (strcmp(songs[i].title, search_key) == 0 || strcmp(songs[i].artist, search_key) == 0 || strcmp(songs[i].album, search_key) == 0) {
            printf("%d. %s - %s (%s)\n", i + 1, songs[i].title, songs[i].artist, songs[i].album);
            found = 1;
        }
    }

    if (!found) {
        printf("No songs found.\n");
    }
}

int main() {
    Song songs[MAX_NUM_SONGS];
    int num_songs = 0;

    add_song(songs, num_songs);
    add_song(songs, num_songs);
    add_song(songs, num_songs);

    display_songs(songs, num_songs);

    char search_key[50];
    printf("\nEnter search keyword: ");
    scanf("%s", search_key);

    search_song(songs, num_songs, search_key);

    return 0;
}