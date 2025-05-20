//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define TITLE_LENGTH 50
#define ARTIST_LENGTH 50
#define ALBUM_LENGTH 50

typedef struct {
    char title[TITLE_LENGTH];
    char artist[ARTIST_LENGTH];
    char album[ALBUM_LENGTH];
    int year;
} Song;

Song musicLibrary[MAX_SONGS];
int songCount = 0;

void displayMenu() {
    printf("\n--- Music Library Management System ---\n");
    printf("1. Add Song\n");
    printf("2. View Songs\n");
    printf("3. Delete Song\n");
    printf("4. Exit\n");
    printf("Select an option: ");
}

void addSong() {
    if (songCount >= MAX_SONGS) {
        printf("Music library is full!\n");
        return;
    }
    Song newSong;
    printf("Enter Song Title: ");
    scanf(" %[^\n]%*c", newSong.title);
    printf("Enter Artist Name: ");
    scanf(" %[^\n]%*c", newSong.artist);
    printf("Enter Album Name: ");
    scanf(" %[^\n]%*c", newSong.album);
    printf("Enter Release Year: ");
    scanf("%d", &newSong.year);
    
    musicLibrary[songCount++] = newSong;
    printf("Song added successfully!\n");
}

void viewSongs() {
    if (songCount == 0) {
        printf("No songs in the library!\n");
        return;
    }
    printf("\n--- Music Library ---\n");
    for (int i = 0; i < songCount; i++) {
        printf("Song %d:\n", i + 1);
        printf(" Title: %s\n", musicLibrary[i].title);
        printf(" Artist: %s\n", musicLibrary[i].artist);
        printf(" Album: %s\n", musicLibrary[i].album);
        printf(" Year: %d\n\n", musicLibrary[i].year);
    }
}

void deleteSong() {
    if (songCount == 0) {
        printf("No songs to delete!\n");
        return;
    }
    int index;
    printf("Enter the number of the song to delete (1 - %d): ", songCount);
    scanf("%d", &index);
    
    if (index < 1 || index > songCount) {
        printf("Invalid song number!\n");
        return;
    }
    
    for (int i = index - 1; i < songCount - 1; i++) {
        musicLibrary[i] = musicLibrary[i + 1];
    }
    songCount--;
    printf("Song deleted successfully!\n");
}

int main() {
    int option;

    while (1) {
        displayMenu();
        scanf("%d", &option);
        switch (option) {
            case 1: 
                addSong(); 
                break;
            case 2: 
                viewSongs(); 
                break;
            case 3: 
                deleteSong(); 
                break;
            case 4: 
                printf("Exiting the program.\n");
                exit(0);
            default: 
                printf("Invalid option, please try again!\n");
        }
    }
    return 0;
}