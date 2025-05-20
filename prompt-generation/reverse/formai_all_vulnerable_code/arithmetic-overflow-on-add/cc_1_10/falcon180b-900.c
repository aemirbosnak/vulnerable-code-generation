//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define MAX_TITLE_LENGTH 50
#define MAX_ARTIST_LENGTH 50
#define MAX_ALBUM_LENGTH 50
#define MAX_GENRE_LENGTH 20

struct Song {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    char album[MAX_ALBUM_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    int duration;
};

struct Playlist {
    char name[MAX_TITLE_LENGTH];
    int num_songs;
    struct Song songs[MAX_SONGS];
};

void add_song(struct Playlist *playlist) {
    if (playlist->num_songs >= MAX_SONGS) {
        printf("Playlist is full.\n");
        return;
    }

    printf("Enter song title: ");
    scanf("%s", playlist->songs[playlist->num_songs].title);
    printf("Enter artist name: ");
    scanf("%s", playlist->songs[playlist->num_songs].artist);
    printf("Enter album name: ");
    scanf("%s", playlist->songs[playlist->num_songs].album);
    printf("Enter genre: ");
    scanf("%s", playlist->songs[playlist->num_songs].genre);
    printf("Enter song duration (in seconds): ");
    scanf("%d", &playlist->songs[playlist->num_songs].duration);

    playlist->num_songs++;
}

void print_playlist(struct Playlist *playlist) {
    printf("Playlist:\n");
    printf("Name: %s\n", playlist->name);
    printf("Number of songs: %d\n", playlist->num_songs);

    for (int i = 0; i < playlist->num_songs; i++) {
        printf("Song %d:\n", i+1);
        printf("Title: %s\n", playlist->songs[i].title);
        printf("Artist: %s\n", playlist->songs[i].artist);
        printf("Album: %s\n", playlist->songs[i].album);
        printf("Genre: %s\n", playlist->songs[i].genre);
        printf("Duration: %d seconds\n\n", playlist->songs[i].duration);
    }
}

int main() {
    struct Playlist playlist;

    printf("Enter playlist name: ");
    scanf("%s", playlist.name);

    int choice;
    do {
        printf("\nMusic Library Management System\n");
        printf("1. Add song\n");
        printf("2. Print playlist\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_song(&playlist);
                break;
            case 2:
                print_playlist(&playlist);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}