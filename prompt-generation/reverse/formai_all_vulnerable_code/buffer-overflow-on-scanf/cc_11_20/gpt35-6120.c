//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ARTIST_NAME_LEN 50
#define MAX_SONG_TITLE_LEN 50
#define MAX_NUM_SONGS 100

typedef struct {
    char artist[MAX_ARTIST_NAME_LEN];
    char title[MAX_SONG_TITLE_LEN];
    int year;
} song;

int main() {
    int num_songs = 0;
    song song_list[MAX_NUM_SONGS];
    bool running = true;

    while (running) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a song\n");
        printf("2. Print all songs by an artist\n");
        printf("3. Print all songs from a certain year\n");
        printf("4. Quit\n");
        printf("Enter a choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_songs == MAX_NUM_SONGS) {
                    printf("Sorry, the library is full!\n");
                } else {
                    song new_song;
                    printf("Enter the artist name: ");
                    scanf("%s", new_song.artist);
                    printf("Enter the song title: ");
                    scanf("%s", new_song.title);
                    printf("Enter the release year: ");
                    scanf("%d", &new_song.year);
                    song_list[num_songs++] = new_song;
                    printf("Song added!\n");
                }
                break;
            case 2:
                printf("Enter the artist name: ");
                char artist_name[MAX_ARTIST_NAME_LEN];
                scanf("%s", artist_name);
                printf("Songs by %s:\n", artist_name);
                for (int i = 0; i < num_songs; i++) {
                    if (strcmp(song_list[i].artist, artist_name) == 0) {
                        printf("[%d] %s - %s (%d)\n", i+1, song_list[i].artist, song_list[i].title, song_list[i].year);
                    }
                }
                break;
            case 3:
                printf("Enter the release year: ");
                int year;
                scanf("%d", &year);
                printf("Songs released in %d:\n", year);
                for (int i = 0; i < num_songs; i++) {
                    if (song_list[i].year == year) {
                        printf("[%d] %s - %s (%d)\n", i+1, song_list[i].artist, song_list[i].title, song_list[i].year);
                    }
                }
                break;
            case 4:
                printf("Goodbye!\n");
                running = false;
                break;
            default:
                printf("Invalid option!\n");
        }
    }

    return 0;
}