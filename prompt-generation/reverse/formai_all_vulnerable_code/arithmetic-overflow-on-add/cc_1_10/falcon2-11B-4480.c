//Falcon2-11B DATASET v1.0 Category: Music Library Management System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

typedef struct song {
    char title[50];
    char artist[50];
    int year;
} Song;

typedef struct playlist {
    Song songs[50];
    int num_songs;
} Playlist;

void print_song(Song *song) {
    printf("%s - %s (%d)\n", song->title, song->artist, song->year);
}

void print_playlist(Playlist *playlist) {
    for (int i = 0; i < playlist->num_songs; i++) {
        printf("%s - %s (%d)\n", playlist->songs[i].title, playlist->songs[i].artist, playlist->songs[i].year);
    }
}

int main() {
    Playlist playlist;
    playlist.num_songs = 0;

    while (1) {
        printf("Menu:\n1. Add song\n2. Print playlist\n3. Quit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter song title: ");
                fgets(playlist.songs[playlist.num_songs].title, sizeof(playlist.songs[playlist.num_songs].title), stdin);
                printf("Enter song artist: ");
                fgets(playlist.songs[playlist.num_songs].artist, sizeof(playlist.songs[playlist.num_songs].artist), stdin);
                printf("Enter song year: ");
                scanf("%d", &playlist.songs[playlist.num_songs].year);
                playlist.num_songs++;
                break;
            case 2:
                print_playlist(&playlist);
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}