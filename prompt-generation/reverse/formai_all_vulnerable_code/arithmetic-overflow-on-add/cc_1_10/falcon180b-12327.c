//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LEN 100
#define MAX_ARTIST_LEN 100
#define MAX_ALBUM_LEN 100
#define MAX_GENRE_LEN 50
#define MAX_PLAYLIST_LEN 100

typedef struct {
    char title[MAX_TITLE_LEN];
    char artist[MAX_ARTIST_LEN];
    char album[MAX_ALBUM_LEN];
    char genre[MAX_GENRE_LEN];
} Song;

typedef struct {
    Song songs[100];
    int num_songs;
} Playlist;

void add_song(Playlist *playlist) {
    if (playlist->num_songs >= 100) {
        printf("Playlist is full!\n");
        return;
    }

    printf("Enter song title: ");
    scanf("%s", playlist->songs[playlist->num_songs].title);

    printf("Enter song artist: ");
    scanf("%s", playlist->songs[playlist->num_songs].artist);

    printf("Enter song album: ");
    scanf("%s", playlist->songs[playlist->num_songs].album);

    printf("Enter song genre: ");
    scanf("%s", playlist->songs[playlist->num_songs].genre);

    playlist->num_songs++;
}

void print_song(Song song) {
    printf("Title: %s\n", song.title);
    printf("Artist: %s\n", song.artist);
    printf("Album: %s\n", song.album);
    printf("Genre: %s\n\n", song.genre);
}

void print_playlist(Playlist playlist) {
    for (int i = 0; i < playlist.num_songs; i++) {
        print_song(playlist.songs[i]);
    }
}

int main() {
    Playlist playlist;

    int choice;
    do {
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
                print_playlist(playlist);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 3);

    return 0;
}