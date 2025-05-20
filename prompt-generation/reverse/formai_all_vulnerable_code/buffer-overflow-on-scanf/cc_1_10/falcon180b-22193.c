//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of songs and albums
#define MAX_SONGS 1000
#define MAX_ALBUMS 100

typedef struct {
    char title[50];
    char artist[50];
    char genre[20];
    int year;
    char album[50];
} Song;

typedef struct {
    char name[50];
    int num_songs;
    Song songs[MAX_SONGS];
} Album;

int main() {
    int num_albums = 0;
    Album albums[MAX_ALBUMS];

    // Add albums
    char choice;
    do {
        printf("Enter 1 to add an album, 0 to exit: ");
        scanf("%c", &choice);

        if (choice == '1') {
            printf("Enter album name: ");
            scanf("%s", albums[num_albums].name);
            num_albums++;

            if (num_albums == MAX_ALBUMS) {
                printf("Maximum number of albums reached!\n");
            }
        }
    } while (choice == '1' && num_albums < MAX_ALBUMS);

    // Add songs to albums
    int album_index, song_index;
    do {
        printf("Enter album index: ");
        scanf("%d", &album_index);

        if (album_index >= 0 && album_index < num_albums) {
            printf("Enter song title: ");
            scanf("%s", albums[album_index].songs[song_index].title);
            printf("Enter artist name: ");
            scanf("%s", albums[album_index].songs[song_index].artist);
            printf("Enter genre: ");
            scanf("%s", albums[album_index].songs[song_index].genre);
            printf("Enter year: ");
            scanf("%d", &albums[album_index].songs[song_index].year);

            song_index++;

            if (song_index == MAX_SONGS) {
                printf("Maximum number of songs reached for album %s!\n", albums[album_index].name);
            }
        }
    } while (album_index >= 0 && album_index < num_albums);

    return 0;
}