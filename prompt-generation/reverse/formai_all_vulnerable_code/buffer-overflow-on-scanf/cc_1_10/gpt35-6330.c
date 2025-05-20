//FormAI DATASET v1.0 Category: Music Library Management System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 50

struct Song {
    char title[100];
    char album[100];
    char artist[100];
    int year;
};

struct Song library[MAX_SONGS];
int numOfSongs = 0;

void addSong() {
    struct Song newSong;
    printf("Enter song title: ");
    fgets(newSong.title, 100, stdin);
    printf("Enter album name: ");
    fgets(newSong.album, 100, stdin);
    printf("Enter artist name: ");
    fgets(newSong.artist, 100, stdin);
    printf("Enter year of release: ");
    scanf("%d", &newSong.year);
    getchar();
    library[numOfSongs] = newSong;
    numOfSongs++;
    printf("\nSong added successfully!\n\n");
}

void printSongs() {
    printf("*************************************\n");
    printf("          C Music Library\n");
    printf("*************************************\n");

    if (numOfSongs == 0) {
        printf("\nThe library is empty.\n\n");
        return;
    }

    printf("Number of songs in the library: %d\n\n", numOfSongs);

    printf("%-30s %-30s %-30s %-10s\n", "Title", "Album", "Artist", "Year");
    printf("--------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < numOfSongs; i++) {
        printf("%-30s %-30s %-30s %-10d\n", library[i].title, library[i].album, library[i].artist, library[i].year);
    }
    printf("--------------------------------------------------------------------------------------------------------\n\n");
}

void deleteSong() {
    int songIndex;
    printf("Enter index of the song you want to delete: ");
    scanf("%d", &songIndex);
    getchar();

    if (songIndex < 1 || songIndex > numOfSongs) {
        printf("\nInvalid index. Please enter a valid index.\n\n");
        return;
    }

    for (int i = songIndex-1; i < numOfSongs-1; i++) {
        library[i] = library[i+1];
    }
    numOfSongs--;
    printf("\nSong deleted successfully!\n\n");
}

void searchSong() {
    char searchTitle[100];
    int found = 0;
    printf("Enter song title to search: ");
    fgets(searchTitle, 100, stdin);

    for (int i = 0; i < numOfSongs; i++) {
        if (strcmp(searchTitle, library[i].title) == 0) {
            found = 1;
            printf("\nSong found at index %d:\n\n", i+1);
            printf("Title: %sAlbum: %sArtist: %sYear: %d\n\n", library[i].title, library[i].album, library[i].artist, library[i].year);
            break;
        }
    }

    if (!found) {
        printf("\nSong not found.\n\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("*************************************\n");
        printf("          C Music Library\n");
        printf("*************************************\n");
        printf("1. Add Song\n");
        printf("2. Print Songs\n");
        printf("3. Delete Song\n");
        printf("4. Search Song\n");
        printf("5. Exit\n\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);
        getchar();

        switch(choice) {
            case 1:
                addSong();
                break;
            case 2:
                printSongs();
                break;
            case 3:
                deleteSong();
                break;
            case 4:
                searchSong();
                break;
            case 5:
                printf("\nGoodbye!\n\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please enter a valid choice.\n\n");
                break;
        }
    }
    return 0;
}