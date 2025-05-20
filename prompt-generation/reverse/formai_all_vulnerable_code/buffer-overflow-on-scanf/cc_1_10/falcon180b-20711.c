//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100

typedef struct {
    char title[50];
    char artist[50];
    int duration;
    char genre[20];
} Song;

Song songs[MAX_SONGS];
int numSongs = 0;

void addSong() {
    if (numSongs == MAX_SONGS) {
        printf("Library is full!\n");
        return;
    }

    printf("Enter song title: ");
    scanf("%s", songs[numSongs].title);

    printf("Enter artist name: ");
    scanf("%s", songs[numSongs].artist);

    printf("Enter song duration in seconds: ");
    scanf("%d", &songs[numSongs].duration);

    printf("Enter song genre: ");
    scanf("%s", songs[numSongs].genre);

    numSongs++;
}

void displaySongs() {
    printf("\nSong Library:\n");

    for (int i = 0; i < numSongs; i++) {
        printf("%d. %s - %s (%d seconds) - %s\n", i+1, songs[i].title, songs[i].artist, songs[i].duration, songs[i].genre);
    }
}

void searchSongByTitle() {
    char searchTitle[50];

    printf("\nEnter song title to search: ");
    scanf("%s", searchTitle);

    int found = 0;

    for (int i = 0; i < numSongs; i++) {
        if (strcmp(songs[i].title, searchTitle) == 0) {
            printf("\nSong found:\n");
            printf("%s - %s (%d seconds) - %s\n", songs[i].title, songs[i].artist, songs[i].duration, songs[i].genre);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Song not found.\n");
    }
}

int main() {
    printf("Welcome to the Music Library Management System!\n");

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Add song\n");
        printf("2. Display songs\n");
        printf("3. Search song by title\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addSong();
                break;
            case 2:
                displaySongs();
                break;
            case 3:
                searchSongByTitle();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}