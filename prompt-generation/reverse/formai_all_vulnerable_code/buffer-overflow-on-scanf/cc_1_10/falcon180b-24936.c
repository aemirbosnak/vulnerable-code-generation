//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100

typedef struct {
    char title[80];
    char artist[80];
    char album[80];
    int length;
    char genre[20];
    char filepath[100];
} Song;

void addSong(Song songs[], int numSongs) {
    printf("Enter song title: ");
    scanf("%s", songs[numSongs].title);
    printf("Enter song artist: ");
    scanf("%s", songs[numSongs].artist);
    printf("Enter song album: ");
    scanf("%s", songs[numSongs].album);
    printf("Enter song length (in seconds): ");
    scanf("%d", &songs[numSongs].length);
    printf("Enter song genre: ");
    scanf("%s", songs[numSongs].genre);
    printf("Enter song file path: ");
    scanf("%s", songs[numSongs].filepath);
    numSongs++;
}

void displaySong(Song song) {
    printf("Title: %s\n", song.title);
    printf("Artist: %s\n", song.artist);
    printf("Album: %s\n", song.album);
    printf("Length: %d seconds\n", song.length);
    printf("Genre: %s\n", song.genre);
    printf("File path: %s\n", song.filepath);
}

void playSong(Song song) {
    printf("Playing %s by %s from album %s...\n", song.title, song.artist, song.album);
    printf("Length: %d seconds\n", song.length);
    printf("Genre: %s\n", song.genre);
    printf("File path: %s\n", song.filepath);
}

int main() {
    Song songs[MAX_SONGS];
    int numSongs = 0;

    while (numSongs < MAX_SONGS) {
        printf("Do you want to add a song? (y/n): ");
        char choice;
        scanf("%c", &choice);

        if (choice == 'y' || choice == 'Y') {
            addSong(songs, numSongs);
        } else {
            printf("Exiting...\n");
            break;
        }
    }

    printf("Your music library contains %d songs:\n", numSongs);

    for (int i = 0; i < numSongs; i++) {
        displaySong(songs[i]);
    }

    printf("Which song do you want to play? (Enter song number): ");
    int songNum;
    scanf("%d", &songNum);

    playSong(songs[songNum - 1]);

    return 0;
}