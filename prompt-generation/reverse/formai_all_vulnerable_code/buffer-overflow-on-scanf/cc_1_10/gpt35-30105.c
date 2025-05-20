//FormAI DATASET v1.0 Category: Music Library Management System ; Style: multiplayer
#include <stdio.h>
#include <string.h>

// Structure for a song
typedef struct {
    char title[50];
    char artist[50];
    int year;
} Song;

// Variables
Song musicLibrary[50];
int count = 0;

// Function to add a song to the music library
void addSong() {
    if (count < 50) {
        printf("Enter the song title: ");
        scanf("%s", musicLibrary[count].title);
        printf("Enter the artist name: ");
        scanf("%s", musicLibrary[count].artist);
        printf("Enter the year of release: ");
        scanf("%d", &musicLibrary[count].year);
        count++;
        printf("Song added successfully!\n");
    } else {
        printf("Music library is full!\n");
    }
}

// Function to display the music library
void displayLibrary() {
    printf("Title\tArtist\tYear\n");
    printf("------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%s\t%d\n", musicLibrary[i].title, musicLibrary[i].artist, musicLibrary[i].year);
    }
}

// Main function
int main() {
    int choice;
    while (1) {
        // Single player menu
        printf("\n\n----- Music Library Management System -----\n");
        printf("1. Add a song\n");
        printf("2. Display music library\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addSong();
                break;
            case 2:
                displayLibrary();
                break;
            case 3:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}