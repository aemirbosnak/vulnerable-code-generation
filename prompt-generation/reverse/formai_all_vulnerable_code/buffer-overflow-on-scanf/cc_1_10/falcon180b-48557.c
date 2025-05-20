//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100

typedef struct {
    char title[50];
    char artist[50];
    char album[50];
    int duration;
    char genre[20];
} Song;

Song songs[MAX_SONGS];
int numSongs;

void addSong() {
    if (numSongs >= MAX_SONGS) {
        printf("Library is full.\n");
        return;
    }

    printf("Enter song title: ");
    scanf("%s", songs[numSongs].title);

    printf("Enter artist name: ");
    scanf("%s", songs[numSongs].artist);

    printf("Enter album name: ");
    scanf("%s", songs[numSongs].album);

    printf("Enter song duration (in seconds): ");
    scanf("%d", &songs[numSongs].duration);

    printf("Enter song genre: ");
    scanf("%s", songs[numSongs].genre);

    numSongs++;
    printf("Song added successfully.\n");
}

void displaySongs() {
    int i;
    printf("Song Library:\n");
    for (i = 0; i < numSongs; i++) {
        printf("%d. %s - %s (%s)\n", i + 1, songs[i].title, songs[i].artist, songs[i].album);
    }
}

void searchSong() {
    char searchTitle[50];
    int i;

    printf("Enter song title to search: ");
    scanf("%s", searchTitle);

    for (i = 0; i < numSongs; i++) {
        if (strcmp(searchTitle, songs[i].title) == 0) {
            printf("Song found:\n");
            printf("%s - %s (%s)\n", songs[i].title, songs[i].artist, songs[i].album);
            return;
        }
    }

    printf("Song not found.\n");
}

int main() {
    int choice;

    do {
        printf("Music Library Management System\n");
        printf("1. Add song\n");
        printf("2. Display songs\n");
        printf("3. Search song\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addSong();
                break;
            case 2:
                displaySongs();
                break;
            case 3:
                searchSong();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}