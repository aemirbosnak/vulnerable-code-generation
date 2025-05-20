//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define MAX_NAME_LEN 50
#define MAX_ARTIST_LEN 50
#define MAX_ALBUM_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char artist[MAX_ARTIST_LEN];
    char album[MAX_ALBUM_LEN];
} Song;

Song songs[MAX_SONGS];
int numSongs = 0;

void addSong() {
    if (numSongs >= MAX_SONGS) {
        printf("Error: Cannot add more songs. Maximum limit reached.\n");
        return;
    }

    printf("Enter song name: ");
    scanf("%s", songs[numSongs].name);

    printf("Enter artist name: ");
    scanf("%s", songs[numSongs].artist);

    printf("Enter album name: ");
    scanf("%s", songs[numSongs].album);

    numSongs++;
    printf("Song added successfully.\n");
}

void searchSong() {
    char searchName[MAX_NAME_LEN];

    printf("Enter song name to search: ");
    scanf("%s", searchName);

    int found = 0;
    for (int i = 0; i < numSongs; i++) {
        if (strcmp(songs[i].name, searchName) == 0) {
            printf("Song found!\n");
            printf("Name: %s\n", songs[i].name);
            printf("Artist: %s\n", songs[i].artist);
            printf("Album: %s\n", songs[i].album);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Song not found.\n");
    }
}

int main() {
    int choice;

    do {
        printf("\nMusic Library Management System\n");
        printf("1. Add song\n");
        printf("2. Search song\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addSong();
            break;
        case 2:
            searchSong();
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 3);

    return 0;
}