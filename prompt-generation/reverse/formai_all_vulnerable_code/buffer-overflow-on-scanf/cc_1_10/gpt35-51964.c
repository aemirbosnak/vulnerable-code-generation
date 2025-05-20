//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARTIST_NAME 100
#define MAX_SONG_NAME 100
#define MAX_SONG_DURATION 10

struct song {
    char artist[MAX_ARTIST_NAME];
    char title[MAX_SONG_NAME];
    char duration[MAX_SONG_DURATION];
};

int main() {
    struct song library[100];
    int num_songs = 0;
    int choice;

    printf("Welcome to the Music Library Management System!\n\n");

    do {
        printf("1. Add a song to the library\n");
        printf("2. Print all songs in the library\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1: // Add a song
                printf("Enter the artist name: ");
                scanf("%s", library[num_songs].artist);
                printf("Enter the song title: ");
                scanf("%s", library[num_songs].title);
                printf("Enter the song duration (mm:ss format): ");
                scanf("%s", library[num_songs].duration);
                printf("\nSong added to the library!\n\n");
                num_songs++;
                break;
            case 2: // Print all songs
                printf("Music Library:\n");
                for (int i = 0; i < num_songs; i++) {
                    printf("%d. %s - %s (%s)\n", i+1, library[i].artist, library[i].title, library[i].duration);
                }
                printf("\n");
                break;
            case 3: // Quit
                printf("Goodbye!\n");
                break;
            default: // Invalid input
                printf("Invalid choice. Please try again.\n\n");
                break;
        }
    } while (choice != 3);

    return 0;
}