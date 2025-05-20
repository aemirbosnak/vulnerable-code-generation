//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100

typedef struct {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    int duration;
} Song;

Song songs[MAX_SONGS];
int numSongs = 0;

void addSong() {
    if (numSongs >= MAX_SONGS) {
        printf("Sorry, cannot add more songs.\n");
        return;
    }

    Song newSong;
    printf("Enter song title: ");
    scanf("%s", newSong.title);

    printf("Enter artist name: ");
    scanf("%s", newSong.artist);

    printf("Enter album name: ");
    scanf("%s", newSong.album);

    printf("Enter year of release: ");
    scanf("%d", &newSong.year);

    printf("Enter song duration (in seconds): ");
    scanf("%d", &newSong.duration);

    songs[numSongs++] = newSong;
    printf("Song added successfully.\n");
}

void playSong() {
    if (numSongs == 0) {
        printf("No songs in library.\n");
        return;
    }

    int choice;
    printf("Select a song to play:\n");
    for (int i = 0; i < numSongs; i++) {
        printf("%d. %s - %s (%d)\n", i+1, songs[i].artist, songs[i].title, songs[i].year);
    }

    scanf("%d", &choice);

    if (choice < 1 || choice > numSongs) {
        printf("Invalid choice.\n");
        return;
    }

    Song selectedSong = songs[choice-1];
    printf("Playing %s by %s...\n", selectedSong.title, selectedSong.artist);
}

void surrealisticMenu() {
    int choice;

    while (1) {
        printf("Surrealistic Music Library Management System\n");
        printf("1. Add a song\n");
        printf("2. Play a song\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addSong();
                break;
            case 2:
                playSong();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}

int main() {
    surrealisticMenu();
    return 0;
}