//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define MAX_PLAYLISTS 10

typedef struct song {
    char title[50];
    char artist[50];
    int duration;
} Song;

typedef struct playlist {
    char name[50];
    int num_songs;
    Song songs[MAX_SONGS];
} Playlist;

void add_song(Song* song) {
    int i = 0;
    while (i < MAX_SONGS && song->title[0]!= '\0') {
        strcpy(song->title, "");
        strcpy(song->artist, "");
        song->duration = 0;
        i++;
    }
}

void add_playlist(Playlist* playlist) {
    int i = 0;
    while (i < MAX_PLAYLISTS && playlist->name[0]!= '\0') {
        strcpy(playlist->name, "");
        playlist->num_songs = 0;
        i++;
    }
}

int main() {
    Song songs[MAX_SONGS];
    Playlist playlists[MAX_PLAYLISTS];
    int choice = 0;
    char input[100];

    while (choice!= 4) {
        printf("What would you like to do?\n");
        printf("1. Add a song\n");
        printf("2. Add a playlist\n");
        printf("3. View playlists\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter song title: ");
                scanf("%s", input);
                add_song(&songs[0]);
                strcpy(songs[0].title, input);
                printf("Enter artist name: ");
                scanf("%s", input);
                strcpy(songs[0].artist, input);
                printf("Enter song duration in seconds: ");
                scanf("%d", &songs[0].duration);
                break;

            case 2:
                printf("Enter playlist name: ");
                scanf("%s", input);
                add_playlist(&playlists[0]);
                strcpy(playlists[0].name, input);
                break;

            case 3:
                printf("Playlists:\n");
                for (int i = 0; i < MAX_PLAYLISTS; i++) {
                    if (playlists[i].name[0]!= '\0') {
                        printf("%s\n", playlists[i].name);
                    }
                }
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}