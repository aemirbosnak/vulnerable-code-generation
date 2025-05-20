//FormAI DATASET v1.0 Category: Music Library Management System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100    // Maximum size of music library

// Structure to store a single song's information
typedef struct song {
    char title[30];
    char artist[30];
    char album[30];
    int year;
    int rating;
} Song;

// Declare an array of songs to represent the music library
Song library[MAX_SIZE];

// Declare a variable to keep track of the number of songs in the library
int num_songs = 0;

// Function to add a new song to the library
void add_song() {
    Song new_song;
    printf("Enter the details of the new song:\n");
    printf("Title: ");
    scanf("%s", new_song.title);
    printf("Artist: ");
    scanf("%s", new_song.artist);
    printf("Album: ");
    scanf("%s", new_song.album);
    printf("Year: ");
    scanf("%d", &new_song.year);
    printf("Rating (out of 10): ");
    scanf("%d", &new_song.rating);
    library[num_songs++] = new_song;
}

// Function to display all the songs in the library
void display_songs() {
    printf("Title\t\tArtist\t\tAlbum\t\tYear\tRating\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < num_songs; i++) {
        printf("%s\t%s\t\t%s\t\t%d\t%d\n", library[i].title, library[i].artist, library[i].album, library[i].year, library[i].rating);
    }
}

// Function to search for a song by title
void search_song() {
    char title[30];
    printf("Enter the title of the song you want to search for: ");
    scanf("%s", title);
    for (int i = 0; i < num_songs; i++) {
        if (strcmp(library[i].title, title) == 0) {
            printf("%s\t%s\t\t%s\t\t%d\t%d\n", library[i].title, library[i].artist, library[i].album, library[i].year, library[i].rating);
            return;
        }
    }
    printf("Song not found.\n");
}

// Function to delete a song from the library by title
void delete_song() {
    char title[30];
    printf("Enter the title of the song you want to delete: ");
    scanf("%s", title);
    for (int i = 0; i < num_songs; i++) {
        if (strcmp(library[i].title, title) == 0) {
            num_songs--;
            for (int j = i; j < num_songs; j++) {
                library[j] = library[j+1];
            }
            printf("Song successfully deleted.\n");
            return;
        }
    }
    printf("Song not found.\n");
}

// Main function to display the menu and handle user input
int main() {
    int choice;
    do {
        printf("\n");
        printf("Music Library Management System\n");
        printf("------------------------------------\n");
        printf("1. Add a new song\n");
        printf("2. Display all the songs\n");
        printf("3. Search for a song by title\n");
        printf("4. Delete a song by title\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: add_song(); break;
            case 2: display_songs(); break;
            case 3: search_song(); break;
            case 4: delete_song(); break;
            case 5: printf("Exiting...\n"); exit(0);
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (1);
    return 0;
}