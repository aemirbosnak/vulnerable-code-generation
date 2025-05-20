//FormAI DATASET v1.0 Category: Music Library Management System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 1000
#define MAX_LENGTH 100
#define MAX_ARTIST 100
#define MAX_GENRE 50

typedef struct song {
    char title[MAX_LENGTH];
    char artist[MAX_ARTIST];
    char genre[MAX_GENRE];
    int length; // in seconds
} Song;

Song library[MAX_SONGS];

int num_songs = 0;

void add_song() {
    Song new_song;
    
    printf("Enter the title of the song: ");
    fgets(new_song.title, MAX_LENGTH, stdin);
    new_song.title[strcspn(new_song.title, "\n")] = '\0'; // remove newline character
    
    printf("Enter the name of the artist: ");
    fgets(new_song.artist, MAX_ARTIST, stdin);
    new_song.artist[strcspn(new_song.artist, "\n")] = '\0';
    
    printf("Enter the genre of the song: ");
    fgets(new_song.genre, MAX_GENRE, stdin);
    new_song.genre[strcspn(new_song.genre, "\n")] = '\0';
    
    printf("Enter the length of the song (in seconds): ");
    scanf("%d", &new_song.length);
    getchar(); // remove newline character from buffer
    
    library[num_songs++] = new_song;
    
    printf("Song added successfully.\n");
}

void search_song() {
    char title[MAX_LENGTH];
    int found = 0;
    
    printf("Enter the title of the song you want to search: ");
    fgets(title, MAX_LENGTH, stdin);
    title[strcspn(title, "\n")] = '\0';
    
    for (int i = 0; i < num_songs; i++) {
        if (strcmp(library[i].title, title) == 0) {
            printf("Title: %s\n", library[i].title);
            printf("Artist: %s\n", library[i].artist);
            printf("Genre: %s\n", library[i].genre);
            printf("Length: %d seconds\n", library[i].length);
            found = 1;
        }
    }
    
    if (!found) {
        printf("Song not found.\n");
    }
}

void display_library() {
    if (num_songs == 0) {
        printf("No songs in the library.\n");
    }
    else {
        printf("Title\t\t\tArtist\t\t\tGenre\t\t\tLength (in seconds)\n");
        printf("------------------------------------------------------------------\n");
        for (int i = 0; i < num_songs; i++) {
            printf("%-30s\t%-30s\t%-20s\t%d\n", library[i].title, library[i].artist, library[i].genre, library[i].length);
        }
    }
}

int main() {
    int choice = -1;
    
    while (choice != 4) {
        printf("Welcome to C Music Library Management System!\n");
        printf("1. Add a song to the library.\n");
        printf("2. Search for a song in the library.\n");
        printf("3. Display the entire library.\n");
        printf("4. Exit the program.\n");
        printf("Please enter your choice (1-4): ");
        scanf("%d", &choice);
        getchar(); // remove newline character from buffer
        
        switch (choice) {
            case 1:
                add_song();
                break;
            case 2:
                search_song();
                break;
            case 3:
                display_library();
                break;
            case 4:
                printf("Exiting the program. Thank you for using C Music Library Management System!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}