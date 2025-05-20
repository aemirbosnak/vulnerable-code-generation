//FormAI DATASET v1.0 Category: Music Library Management System ; Style: irregular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the structure for storing the song information
struct Song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
};

// Define the function for adding a new song to the library
void addSong(struct Song *songs, int *count) {
    printf("Enter the title of the song: ");
    scanf("%s", songs[*count].title);
    printf("Enter the artist of the song: ");
    scanf("%s", songs[*count].artist);
    printf("Enter the album of the song: ");
    scanf("%s", songs[*count].album);
    printf("Enter the year the song was released: ");
    scanf("%d", &songs[*count].year);
    (*count)++;
}

// Define the function for displaying the songs in the library
void displaySongs(struct Song *songs, int count) {
    printf("Song Library\n");
    for (int i = 0; i < count; i++) {
        printf("\nSong %d:\n", i+1);
        printf("Title: %s\n", songs[i].title);
        printf("Artist: %s\n", songs[i].artist);
        printf("Album: %s\n", songs[i].album);
        printf("Year: %d\n", songs[i].year);
    }
}

// Define the function for searching the library for a specific song
void searchSong(struct Song *songs, int count) {
    char title[50];
    printf("Enter the title of the song to search: ");
    scanf("%s", title);
    for (int i = 0; i < count; i++) {
        if (strcmp(songs[i].title, title) == 0) {
            printf("\nSong %d:\n", i+1);
            printf("Title: %s\n", songs[i].title);
            printf("Artist: %s\n", songs[i].artist);
            printf("Album: %s\n", songs[i].album);
            printf("Year: %d\n", songs[i].year);
            return;
        }
    }
    printf("The song %s was not found in the library.\n", title);
}

// Define the main function to run the program
int main() {
    // Declare the variables
    struct Song songs[100];
    int count = 0;
    char choice;

    // Loop through the menu until the user chooses to exit
    do {
        printf("\nMenu:\n");
        printf("1. Add a song to the library\n");
        printf("2. Display all songs in the library\n");
        printf("3. Search for a song in the library\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        // Switch case to handle the user's choice
        switch (choice) {
            case '1':
                addSong(songs, &count);
                break;
            case '2':
                displaySongs(songs, count);
                break;
            case '3':
                searchSong(songs, count);
                break;
            case '4':
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != '4');

    return 0;
}