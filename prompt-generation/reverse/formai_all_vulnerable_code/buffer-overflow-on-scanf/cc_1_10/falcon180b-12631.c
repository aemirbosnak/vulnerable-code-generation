//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    char artist[MAX_NAME_LEN];
    int duration;
} Song;

Song library[MAX_SONGS];
int numSongs;

void addSong() {
    printf("Enter song name: ");
    scanf("%s", library[numSongs].name);
    printf("Enter artist name: ");
    scanf("%s", library[numSongs].artist);
    printf("Enter song duration (in seconds): ");
    scanf("%d", &library[numSongs].duration);
    numSongs++;
}

void viewSongs() {
    printf("Song Library\n");
    printf("--------------------\n");
    for (int i = 0; i < numSongs; i++) {
        printf("%d. %s - %s (%d seconds)\n", i+1, library[i].name, library[i].artist, library[i].duration);
    }
}

void searchSong() {
    printf("Enter song name to search: ");
    char searchName[MAX_NAME_LEN];
    scanf("%s", searchName);
    int found = 0;
    for (int i = 0; i < numSongs; i++) {
        if (strcmp(library[i].name, searchName) == 0) {
            printf("Song found: %s - %s (%d seconds)\n", library[i].name, library[i].artist, library[i].duration);
            found = 1;
        }
    }
    if (!found) {
        printf("Song not found.\n");
    }
}

int main() {
    printf("Welcome to the Music Library Management System\n");
    printf("What would you like to do?\n");
    printf("1. Add song\n");
    printf("2. View songs\n");
    printf("3. Search song\n");
    printf("4. Exit\n");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            addSong();
            break;
        case 2:
            viewSongs();
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
    return 0;
}