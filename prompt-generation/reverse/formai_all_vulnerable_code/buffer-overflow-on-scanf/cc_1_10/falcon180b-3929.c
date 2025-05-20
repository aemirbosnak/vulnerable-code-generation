//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100

typedef struct {
    char title[80];
    char artist[80];
    char album[80];
    int duration;
} Song;

void addSong(Song* library, int numSongs) {
    char title[80];
    char artist[80];
    char album[80];
    int duration;

    printf("Enter song title: ");
    scanf("%s", title);
    printf("Enter artist name: ");
    scanf("%s", artist);
    printf("Enter album name: ");
    scanf("%s", album);
    printf("Enter song duration (in seconds): ");
    scanf("%d", &duration);

    int i;
    for (i = 0; i < numSongs; i++) {
        if (strcmp(library[i].title, title) == 0) {
            printf("Song with this title already exists.\n");
            return;
        }
    }

    strcpy(library[numSongs].title, title);
    strcpy(library[numSongs].artist, artist);
    strcpy(library[numSongs].album, album);
    library[numSongs].duration = duration;

    printf("Song added successfully.\n");
}

void displaySongs(Song* library, int numSongs) {
    printf("\nSong Library:\n");
    printf("--------------------\n");
    printf("Title\tArtist\tAlbum\tDuration\n");

    int i;
    for (i = 0; i < numSongs; i++) {
        printf("%s\t%s\t%s\t%d seconds\n", library[i].title, library[i].artist, library[i].album, library[i].duration);
    }
}

void searchSong(Song* library, int numSongs, char* keyword) {
    int i;

    for (i = 0; i < numSongs; i++) {
        if (strcmp(library[i].title, keyword) == 0 || strcmp(library[i].artist, keyword) == 0 || strcmp(library[i].album, keyword) == 0) {
            printf("\nSong found:\n");
            printf("Title: %s\n", library[i].title);
            printf("Artist: %s\n", library[i].artist);
            printf("Album: %s\n", library[i].album);
            printf("Duration: %d seconds\n", library[i].duration);
        }
    }
}

int main() {
    Song library[MAX_SONGS];
    int numSongs = 0;

    while (1) {
        printf("\n1. Add song\n2. Display songs\n3. Search song\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (numSongs >= MAX_SONGS) {
                printf("Song library is full.\n");
            } else {
                addSong(library, numSongs);
                numSongs++;
            }
            break;

        case 2:
            if (numSongs == 0) {
                printf("Song library is empty.\n");
            } else {
                displaySongs(library, numSongs);
            }
            break;

        case 3:
            printf("Enter keyword: ");
            char keyword[80];
            scanf("%s", keyword);
            searchSong(library, numSongs, keyword);
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}