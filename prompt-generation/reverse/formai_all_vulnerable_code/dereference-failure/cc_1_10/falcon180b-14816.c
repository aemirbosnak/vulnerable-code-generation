//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    char *artist;
    char *album;
    int duration;
} Song;

Song songs[MAX_SIZE];
int numSongs = 0;

void addSong() {
    char name[50];
    char artist[50];
    char album[50];
    int duration;

    printf("Enter song name: ");
    scanf("%s", name);

    printf("Enter artist name: ");
    scanf("%s", artist);

    printf("Enter album name: ");
    scanf("%s", album);

    printf("Enter song duration in seconds: ");
    scanf("%d", &duration);

    strcpy(songs[numSongs].name, name);
    strcpy(songs[numSongs].artist, artist);
    strcpy(songs[numSongs].album, album);
    songs[numSongs].duration = duration;

    numSongs++;
}

void displaySongs() {
    int i;

    for (i = 0; i < numSongs; i++) {
        printf("%s - %s - %s - %d seconds\n", songs[i].name, songs[i].artist, songs[i].album, songs[i].duration);
    }
}

void searchSong() {
    char searchName[50];

    printf("Enter song name to search: ");
    scanf("%s", searchName);

    int i;
    for (i = 0; i < numSongs; i++) {
        if (strcmp(songs[i].name, searchName) == 0) {
            printf("%s - %s - %s - %d seconds\n", songs[i].name, songs[i].artist, songs[i].album, songs[i].duration);
        }
    }
}

int main() {
    int choice;

    do {
        printf("\n\nMusic Library Management System\n");
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
                printf("Invalid choice!\n");
        }
    } while (choice!= 4);

    return 0;
}