//FormAI DATASET v1.0 Category: Music Library Management System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 1000
#define MAX_TITLE_LENGTH 50
#define MAX_ARTIST_LENGTH 30
#define MAX_ALBUM_LENGTH 30
#define MAX_GENRE_LENGTH 20

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    char album[MAX_ALBUM_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    int year;
} Song;

Song library[MAX_SONGS];
int songCount = 0;

// Function to add a song to the library
void addSong() {
    Song newSong;
    printf("\nEnter the song's title: ");
    fgets(newSong.title, MAX_TITLE_LENGTH, stdin);
    printf("Enter the artist's name: ");
    fgets(newSong.artist, MAX_ARTIST_LENGTH, stdin);
    printf("Enter the album name: ");
    fgets(newSong.album, MAX_ALBUM_LENGTH, stdin);
    printf("Enter the genre: ");
    fgets(newSong.genre, MAX_GENRE_LENGTH, stdin);
    printf("Enter the year: ");
    scanf("%d", &newSong.year);

    // Add the new song to the library
    library[songCount] = newSong;
    songCount++;
    printf("\nSong added successfully!\n");
}

// Function to display all songs in the library
void displaySongs() {
    printf("\nSong Library:\n");
    for (int i = 0; i < songCount; i++) {
        printf("%d. %s by %s, from the album %s (%s), released in %d\n", 
            i + 1, library[i].title, library[i].artist, library[i].album, 
            library[i].genre, library[i].year);
    }

    if (songCount == 0) {
        printf("The library is empty!\n");
    }
}

int main() {
    int choice = 0;

    printf("Welcome to the Music Library Management System!\n");

    do {
        printf("\nAvailable Options:\n");
        printf("1. Add a song\n");
        printf("2. Display all songs\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                addSong();
                break;
            case 2:
                displaySongs();
                break;
            case 3:
                printf("\nThank you for using the Music Library Management System!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}