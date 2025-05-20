//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define MAX_SONG_NAME_LENGTH 50
#define MAX_ARTIST_NAME_LENGTH 50

typedef struct {
    char songName[MAX_SONG_NAME_LENGTH];
    char artistName[MAX_ARTIST_NAME_LENGTH];
    int year;
    int duration;
} Song;

void addSong(Song* songs, int numSongs) {
    printf("Enter song name: ");
    scanf("%s", songs[numSongs].songName);
    printf("Enter artist name: ");
    scanf("%s", songs[numSongs].artistName);
    printf("Enter year: ");
    scanf("%d", &songs[numSongs].year);
    printf("Enter duration in seconds: ");
    scanf("%d", &songs[numSongs].duration);
    numSongs++;
}

void displaySongs(Song* songs, int numSongs) {
    printf("\nSong Library:\n");
    printf("---------------------\n");
    for (int i = 0; i < numSongs; i++) {
        printf("%d. %s - %s (%d)\n", i+1, songs[i].songName, songs[i].artistName, songs[i].year);
        printf("Duration: %d seconds\n", songs[i].duration);
        printf("---------------------\n");
    }
}

int main() {
    Song songs[MAX_SONGS];
    int numSongs = 0;

    printf("Welcome to the Happy Song Library Management System!\n");
    printf("Let's start adding some songs to your library.\n");

    while (numSongs < MAX_SONGS) {
        addSong(songs, numSongs);
        printf("\nDo you want to add another song? (y/n): ");
        char choice;
        scanf("%c", &choice);
        if (choice == 'n' || choice == 'N') {
            break;
        }
    }

    printf("\nYour song library contains %d songs.\n", numSongs);
    displaySongs(songs, numSongs);

    return 0;
}