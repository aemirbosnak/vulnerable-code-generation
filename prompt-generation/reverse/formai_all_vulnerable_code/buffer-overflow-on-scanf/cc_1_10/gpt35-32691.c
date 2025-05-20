//FormAI DATASET v1.0 Category: Music Library Management System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 1000
#define MAX_NAME_LEN 50
#define MAX_ARTIST_LEN 50
#define MAX_ALBUM_LEN 50

typedef struct Song {
    char name[MAX_NAME_LEN];
    char artist[MAX_ARTIST_LEN];
    char album[MAX_ALBUM_LEN];
} Song;

int main() {
    // Initialize song library and counter
    Song library[MAX_SONGS];
    int num_songs = 0;

    // Print welcome message and menu options
    printf("Welcome to the Music Library Management System.\n");
    printf("Enter 1 to add a song to the library.\n");
    printf("Enter 2 to view the library.\n");
    printf("Enter 3 to exit.\n");

    // Initialize user input variable
    int choice;

    // Loop through program until user chooses to exit
    while (1) {
        // Get user choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Add a song to the library
                if (num_songs == MAX_SONGS) {
                    printf("The library is full. No more songs can be added.\n");
                } else {
                    printf("Enter the song name (max %d characters): ", MAX_NAME_LEN);
                    scanf("%s", library[num_songs].name);
                    printf("Enter the artist name (max %d characters): ", MAX_ARTIST_LEN);
                    scanf("%s", library[num_songs].artist);
                    printf("Enter the album name (max %d characters): ", MAX_ALBUM_LEN);
                    scanf("%s", library[num_songs].album);
                    num_songs++;
                    printf("Song added to the library.\n");
                }
                break;

            case 2:
                // View the entire library
                if (num_songs == 0) {
                    printf("The library is empty.\n");
                } else {
                    printf("Library contains %d songs:\n", num_songs);
                    for (int i = 0; i < num_songs; i++) {
                        printf("%d. %s - %s (%s)\n", i+1, library[i].name, library[i].artist, library[i].album);
                    }
                }
                break;

            case 3:
                // Exit the program
                printf("Thank you for using the Music Library Management System.\n");
                exit(0);

            default:
                // Invalid choice
                printf("Invalid choice. Please choose from the menu options.\n");
                break;
        }
    }

    return 0;
}