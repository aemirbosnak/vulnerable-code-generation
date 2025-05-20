//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Ada Lovelace
/* C Music Library Management System */
/* Designed by Ada Lovelace */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 1000
#define MAX_TITLE 50
#define MAX_ARTIST 50
#define MAX_ALBUM 50
#define MAX_GENRE 50

typedef struct Song {
    char title[MAX_TITLE];
    char artist[MAX_ARTIST];
    char album[MAX_ALBUM];
    char genre[MAX_GENRE];
} Song;

Song songList[MAX_SONGS];
int numSongs = 0;

/* Function to add a new song to the library */
void addSong() {
    Song newSong;
    
    printf("Enter the song title: ");
    fgets(newSong.title, MAX_TITLE, stdin);
    printf("Enter the artist: ");
    fgets(newSong.artist, MAX_ARTIST, stdin);
    printf("Enter the album: ");
    fgets(newSong.album, MAX_ALBUM, stdin);
    printf("Enter the genre: ");
    fgets(newSong.genre, MAX_GENRE, stdin);
    
    songList[numSongs] = newSong;
    numSongs++;
    printf("Song added successfully!\n");
}

/* Function to remove a song from the library */
void removeSong() {
    char title[MAX_TITLE];
    int i, index = -1;
    
    printf("Enter the title of the song to remove: ");
    fgets(title, MAX_TITLE, stdin);
    
    for (i = 0; i < numSongs; i++) {
        if (strcmp(title, songList[i].title) == 0) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("Song not found in library.\n");
    } else {
        for (i = index; i < numSongs - 1; i++) {
            songList[i] = songList[i+1];
        }
        numSongs--;
        printf("Song removed successfully!\n");
    }
}

/* Function to display all songs in the library */
void displaySongs() {
    int i;
    
    printf("Library songs:\n");
    for (i = 0; i < numSongs; i++) {
        printf("%d. %s - %s (%s, %s)\n", i+1, songList[i].title, songList[i].artist, songList[i].album, songList[i].genre);
    }
}

/* Main function */
int main() {
    int choice;
    
    while (1) {
        printf("Music Library Management System\n");
        printf("1. Add new song\n");
        printf("2. Remove song\n");
        printf("3. Display all songs\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        
        switch (choice) {
            case 1:
                addSong();
                break;
            case 2:
                removeSong();
                break;
            case 3:
                displaySongs();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    
    return 0;
}