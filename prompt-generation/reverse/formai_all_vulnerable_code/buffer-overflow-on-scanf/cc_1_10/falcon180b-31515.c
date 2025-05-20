//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define MAX_NAME 50

typedef struct Song {
    char name[MAX_NAME];
    char artist[MAX_NAME];
    int duration;
} Song;

void addSong(Song* playlist, int n, Song newSong) {
    if (n >= 0 && n < MAX_SONGS) {
        playlist[n] = newSong;
        printf("Song added to playlist.\n");
    } else {
        printf("Invalid playlist position.\n");
    }
}

void playSong(Song* playlist, int n) {
    if (n >= 0 && n < MAX_SONGS) {
        printf("Playing %s by %s (%d seconds)\n", playlist[n].name, playlist[n].artist, playlist[n].duration);
    } else {
        printf("Invalid playlist position.\n");
    }
}

void removeSong(Song* playlist, int n) {
    if (n >= 0 && n < MAX_SONGS) {
        playlist[n] = (Song) { "", "", 0 };
        printf("Song removed from playlist.\n");
    } else {
        printf("Invalid playlist position.\n");
    }
}

void printPlaylist(Song* playlist) {
    printf("Playlist:\n");
    for (int i = 0; i < MAX_SONGS; i++) {
        if (playlist[i].name[0]!= '\0') {
            printf("  %d. %s by %s (%d seconds)\n", i + 1, playlist[i].name, playlist[i].artist, playlist[i].duration);
        }
    }
}

int main() {
    Song playlist[MAX_SONGS] = { 0 };
    int choice;

    while (1) {
        printf("Music Library Management System\n");
        printf("1. Add song\n");
        printf("2. Play song\n");
        printf("3. Remove song\n");
        printf("4. Print playlist\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                Song newSong;
                printf("Enter song name: ");
                scanf("%s", newSong.name);
                printf("Enter artist name: ");
                scanf("%s", newSong.artist);
                printf("Enter song duration (in seconds): ");
                scanf("%d", &newSong.duration);
                addSong(playlist, -1, newSong);
                break;
            }
            case 2: {
                int n;
                printf("Enter song number: ");
                scanf("%d", &n);
                playSong(playlist, n - 1);
                break;
            }
            case 3: {
                int n;
                printf("Enter song number: ");
                scanf("%d", &n);
                removeSong(playlist, n - 1);
                break;
            }
            case 4: {
                printPlaylist(playlist);
                break;
            }
            case 5: {
                exit(0);
            }
            default: {
                printf("Invalid choice.\n");
            }
        }
    }

    return 0;
}