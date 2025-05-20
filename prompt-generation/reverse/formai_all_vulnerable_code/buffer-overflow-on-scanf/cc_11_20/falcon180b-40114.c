//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SONGS 100
#define MAX_TITLE_LEN 100
#define MAX_ARTIST_LEN 100
#define MAX_ALBUM_LEN 100
#define MAX_GENRE_LEN 100

typedef struct {
    char title[MAX_TITLE_LEN];
    char artist[MAX_ARTIST_LEN];
    char album[MAX_ALBUM_LEN];
    char genre[MAX_GENRE_LEN];
    int length;
    int rating;
} song;

int main() {
    song library[MAX_SONGS];
    int num_songs = 0;
    char choice;

    printf("Welcome to the Music Library Management System!\n");
    printf("Please choose an option:\n");
    printf("1. Add song\n");
    printf("2. Display library\n");
    printf("3. Search for song\n");
    printf("4. Exit\n");

    while (1) {
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                if (num_songs >= MAX_SONGS) {
                    printf("Library is full. Please delete a song before adding a new one.\n");
                } else {
                    printf("Enter song title: ");
                    scanf("%s", library[num_songs].title);
                    printf("Enter artist: ");
                    scanf("%s", library[num_songs].artist);
                    printf("Enter album: ");
                    scanf("%s", library[num_songs].album);
                    printf("Enter genre: ");
                    scanf("%s", library[num_songs].genre);
                    printf("Enter song length in seconds: ");
                    scanf("%d", &library[num_songs].length);
                    printf("Enter song rating (1-5): ");
                    scanf("%d", &library[num_songs].rating);
                    num_songs++;
                }
                break;
            case '2':
                if (num_songs == 0) {
                    printf("Library is empty.\n");
                } else {
                    printf("Song Title\tArtist\tAlbum\tGenre\tLength\tRating\n");
                    for (int i = 0; i < num_songs; i++) {
                        printf("%s\t%s\t%s\t%s\t%d\t%d\n", library[i].title, library[i].artist, library[i].album, library[i].genre, library[i].length, library[i].rating);
                    }
                }
                break;
            case '3':
                if (num_songs == 0) {
                    printf("Library is empty.\n");
                } else {
                    printf("Enter search query: ");
                    char query[MAX_TITLE_LEN];
                    scanf("%s", query);
                    for (int i = 0; i < num_songs; i++) {
                        if (strstr(library[i].title, query) || strstr(library[i].artist, query) || strstr(library[i].album, query) || strstr(library[i].genre, query)) {
                            printf("%s\t%s\t%s\t%s\t%d\t%d\n", library[i].title, library[i].artist, library[i].album, library[i].genre, library[i].length, library[i].rating);
                        }
                    }
                }
                break;
            case '4':
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}