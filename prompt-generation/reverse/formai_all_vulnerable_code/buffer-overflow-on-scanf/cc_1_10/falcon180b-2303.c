//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 1000
#define MAX_SONG_NAME_LENGTH 100

typedef struct {
    char name[MAX_SONG_NAME_LENGTH];
    int duration;
    int genre;
} Song;

Song library[MAX_SONGS];
int numSongs = 0;

void addSong() {
    if (numSongs == MAX_SONGS) {
        printf("Library is full.\n");
        return;
    }

    char name[MAX_SONG_NAME_LENGTH];
    printf("Enter song name: ");
    scanf("%s", name);

    int duration;
    printf("Enter song duration (in seconds): ");
    scanf("%d", &duration);

    int genre;
    printf("Enter song genre (1 for pop, 2 for rock, 3 for classical): ");
    scanf("%d", &genre);

    strcpy(library[numSongs].name, name);
    library[numSongs].duration = duration;
    library[numSongs].genre = genre;

    numSongs++;
    printf("Song added to library.\n");
}

void displaySongs() {
    printf("Library contents:\n");
    for (int i = 0; i < numSongs; i++) {
        printf("%d. %s (%d seconds, %d genre)\n", i+1, library[i].name, library[i].duration, library[i].genre);
    }
}

void searchSongs() {
    char query[MAX_SONG_NAME_LENGTH];
    printf("Enter search query: ");
    scanf("%s", query);

    int results = 0;
    for (int i = 0; i < numSongs; i++) {
        if (strstr(library[i].name, query)) {
            printf("%d. %s (%d seconds, %d genre)\n", i+1, library[i].name, library[i].duration, library[i].genre);
            results++;
        }
    }

    if (results == 0) {
        printf("No results found.\n");
    }
}

int main() {
    int choice;

    do {
        printf("Music Library Management System\n");
        printf("1. Add song\n");
        printf("2. Display songs\n");
        printf("3. Search songs\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addSong();
                break;
            case 2:
                displaySongs();
                break;
            case 3:
                searchSongs();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice!= 4);

    return 0;
}