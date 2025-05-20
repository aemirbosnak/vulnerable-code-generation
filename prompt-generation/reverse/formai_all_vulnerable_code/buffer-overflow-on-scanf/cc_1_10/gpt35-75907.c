//FormAI DATASET v1.0 Category: Music Library Management System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for a song
struct song {
    char title[100];
    char artist[100];
    char album[100];
    int year;
};

// Define the library as an array of songs
struct song library[100];
int libraryCount = 0;

// Function to add a song to the library
void addSong(char title[100], char artist[100], char album[100], int year) {
    if (libraryCount >= 100) {
        printf("Library is full. Cannot add song.\n");
        return;
    }

    struct song newSong;
    strcpy(newSong.title, title);
    strcpy(newSong.artist, artist);
    strcpy(newSong.album, album);
    newSong.year = year;

    library[libraryCount] = newSong;
    libraryCount++;

    printf("Song \"%s\" added to library.\n", title);
}

// Function to remove a song from the library
void removeSong(char title[100]) {
    int i;
    for (i = 0; i < libraryCount; i++) {
        if (strcmp(library[i].title, title) == 0) {
            // Shift all elements to the left
            for (int j = i; j < libraryCount - 1; j++) {
                library[j] = library[j + 1];
            }

            libraryCount--;
            printf("Song \"%s\" removed from library.\n", title);
            return;
        }
    }

    printf("Song \"%s\" not found in library.\n", title);
}

// Function to search for songs by title
void searchByTitle(char title[100]) {
    printf("Results for \"%s\":\n\n", title);

    int i;
    for (i = 0; i < libraryCount; i++) {
        if (strstr(library[i].title, title) != NULL) {
            printf("Title: %s\n", library[i].title);
            printf("Artist: %s\n", library[i].artist);
            printf("Album: %s\n", library[i].album);
            printf("Year: %d\n\n", library[i].year);
        }
    }
}

// Main function
int main() {
    int choice = 0;

    while (choice != 4) {
        printf("\nMusic Library Management System\n");
        printf("1. Add Song\n");
        printf("2. Remove Song\n");
        printf("3. Search by Title\n");
        printf("4. Exit\n");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        // Flush stdin after scanf to prevent buffer overflow
        while ((getchar()) != '\n');

        switch (choice) {
            case 1: {
                char title[100], artist[100], album[100];
                int year;

                printf("\nEnter Song Title: ");
                fgets(title, 100, stdin);

                printf("\nEnter Artist Name: ");
                fgets(artist, 100, stdin);

                printf("\nEnter Album Name: ");
                fgets(album, 100, stdin);

                printf("\nEnter Year: ");
                scanf("%d", &year);

                addSong(title, artist, album, year);
                break;
            }

            case 2: {
                char title[100];

                printf("\nEnter Song Title: ");
                fgets(title, 100, stdin);

                removeSong(title);
                break;
            }

            case 3: {
                char title[100];

                printf("\nEnter Search Query: ");
                fgets(title, 100, stdin);

                searchByTitle(title);
                break;
            }

            case 4:
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    printf("\nExiting...\n");
    return 0;
}