//FormAI DATASET v1.0 Category: Music Library Management System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Song {
    int id;
    char title[50];
    char artist[50];
    char album[50];
    int year;
    int duration; //seconds
    int plays;
} Song;

Song songs[100];
int numOfSongs = 0;

void addSong() {
    if (numOfSongs >= 100) {
        printf("Error: Music library is full.\n");
        return;
    }

    Song newSong;

    printf("Enter song title: ");
    fgets(newSong.title, 50, stdin);

    printf("Enter artist name: ");
    fgets(newSong.artist, 50, stdin);

    printf("Enter album name: ");
    fgets(newSong.album, 50, stdin);

    printf("Enter release year: ");
    scanf("%d", &newSong.year);

    printf("Enter song duration (seconds): ");
    scanf("%d", &newSong.duration);

    newSong.id = numOfSongs;
    newSong.plays = 0;

    songs[numOfSongs] = newSong;
    numOfSongs++;

    printf("Song added successfully!\n");
}

void showLibrary() {
    printf("=== MUSIC LIBRARY ===\n");

    for (int i = 0; i < numOfSongs; i++) {
        printf("ID: %d\n", songs[i].id);
        printf("Title: %s", songs[i].title);
        printf("Artist: %s", songs[i].artist);
        printf("Album: %s", songs[i].album);
        printf("Year: %d\n", songs[i].year);
        printf("Duration: %d seconds\n", songs[i].duration);
        printf("Plays: %d\n\n", songs[i].plays);
    }
}

void playSong(int id) {
    if (id < 0 || id >= numOfSongs) {
        printf("Error: Invalid song ID.\n");
        return;
    }

    printf("Now playing: %s by %s\n", songs[id].title, songs[id].artist);
    songs[id].plays++;
}

int main() {
    int choice;

    printf("Welcome to C Music Library Management System!\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add new song\n");
        printf("2. Show music library\n");
        printf("3. Play a song\n");
        printf("4. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addSong();
                break;

            case 2:
                showLibrary();
                break;

            case 3:
                printf("Enter song ID to play: ");
                scanf("%d", &choice);
                playSong(choice);
                break;

            case 4:
                printf("Thanks for using C Music Library Management System!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}