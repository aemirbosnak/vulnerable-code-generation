//Falcon2-11B DATASET v1.0 Category: Music Library Management System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 50

typedef struct {
    char title[MAX_LEN];
    char artist[MAX_LEN];
    char genre[MAX_LEN];
    char year[4];
    char duration[10];
} Song;

void add_song(Song* songs, int size, Song new_song) {
    if (size < MAX_LEN) {
        strcpy(songs[size].title, new_song.title);
        strcpy(songs[size].artist, new_song.artist);
        strcpy(songs[size].genre, new_song.genre);
        strcpy(songs[size].year, new_song.year);
        strcpy(songs[size].duration, new_song.duration);
        size++;
    } else {
        printf("Song library is full!\n");
    }
}

void display_song(Song song) {
    printf("Title: %s\n", song.title);
    printf("Artist: %s\n", song.artist);
    printf("Genre: %s\n", song.genre);
    printf("Year: %s\n", song.year);
    printf("Duration: %s\n", song.duration);
    printf("\n");
}

int main() {
    Song songs[MAX_LEN];
    int size = 0;

    while (1) {
        printf("1. Add a song\n2. Display all songs\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter title, artist, genre, year, and duration:\n");
                char title[MAX_LEN], artist[MAX_LEN], genre[MAX_LEN], year[4], duration[10];
                scanf("%s %s %s %s %s", title, artist, genre, year, duration);
                Song new_song = {title, artist, genre, year, duration};
                add_song(songs, size, new_song);
                break;
            case 2:
                for (int i = 0; i < size; i++) {
                    display_song(songs[i]);
                }
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}