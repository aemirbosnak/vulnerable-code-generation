//FormAI DATASET v1.0 Category: Music Library Management System ; Style: standalone
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100 // Maximum length of song title and artist name

// Struct to store details of each song
struct Song {
    char title[MAX_LENGTH];
    char artist[MAX_LENGTH];
    int year;
};

// Function to add a new song to the library
void add_song(struct Song library[], int* num_songs) {
    struct Song new_song;
    printf("Enter the song title: ");
    fgets(new_song.title, MAX_LENGTH, stdin);
    new_song.title[strcspn(new_song.title, "\n")] = '\0'; // Remove trailing newline character
    printf("Enter the artist name: ");
    fgets(new_song.artist, MAX_LENGTH, stdin);
    new_song.artist[strcspn(new_song.artist, "\n")] = '\0'; // Remove trailing newline character
    printf("Enter the release year: ");
    scanf("%d", &new_song.year);
    getchar(); // Remove trailing newline character from input buffer
    
    library[*num_songs] = new_song;
    (*num_songs)++;
    printf("Song added to the library!\n");
}

// Function to search for a song in the library by title
void search_song(struct Song library[], int num_songs) {
    char search_title[MAX_LENGTH];
    printf("Enter the title of the song to search for: ");
    fgets(search_title, MAX_LENGTH, stdin);
    search_title[strcspn(search_title, "\n")] = '\0'; // Remove trailing newline character
    
    int found = 0;
    for (int i = 0; i < num_songs; i++) {
        if (strcmp(library[i].title, search_title) == 0) {
            printf("Song found in the library!\nTitle: %s\nArtist: %s\nYear: %d\n", library[i].title, library[i].artist, library[i].year);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Song not found in the library.\n");
    }
}

int main() {
    struct Song library[MAX_LENGTH];
    int num_songs = 0;
    printf("Welcome to the C Music Library Management System!\n");
    while (1) {
        printf("\nWhat would you like to do?\n1. Add a new song to the library\n2. Search for a song in the library\n3. Exit the program\n");
        int choice;
        scanf("%d", &choice);
        getchar(); // Remove trailing newline character from input buffer
        switch (choice) {
            case 1:
                add_song(library, &num_songs);
                break;
            case 2:
                search_song(library, num_songs);
                break;
            case 3:
                printf("Thank you for using the C Music Library Management System!\n");
                return 0;
            default:
                printf("Invalid input. Please enter a valid choice.\n");
        }
    }
}