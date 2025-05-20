//FormAI DATASET v1.0 Category: Music Library Management System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for a song entry
typedef struct song {
    char* title;
    char* artist;
    char* album;
    int year;
} Song;

// Function declarations
void add_song(Song* library[], int* num_songs);
void print_library(Song* library[], int num_songs);

int main() {
    // Initialize variables
    Song* library[100];
    int num_songs = 0;
    char input[10];
    
    // Program loop
    while(1) {
        // Prompt user for command
        printf("Enter a command (add, print, quit): ");
        scanf("%s", input);
        
        // Add command
        if(strcmp(input, "add") == 0) {
            add_song(library, &num_songs);
        }
        // Print command
        else if(strcmp(input, "print") == 0) {
            print_library(library, num_songs);
        }
        // Quit command
        else if(strcmp(input, "quit") == 0) {
            break;
        }
        // Invalid command
        else {
            printf("Invalid command\n");
        }
    }
    
    // Free memory
    for(int i = 0; i < num_songs; i++) {
        free(library[i]->title);
        free(library[i]->artist);
        free(library[i]->album);
        free(library[i]);
    }
    
    return 0;
}

// Add a new song to the library
void add_song(Song* library[], int* num_songs) {
    // Allocate memory for new song
    Song* new_song = malloc(sizeof(Song));
    new_song->title = malloc(sizeof(char) * 100);
    new_song->artist = malloc(sizeof(char) * 100);
    new_song->album = malloc(sizeof(char) * 100);
    
    // Prompt user for song information
    printf("Enter song title: ");
    scanf(" %[^\n]", new_song->title);
    printf("Enter artist name: ");
    scanf(" %[^\n]", new_song->artist);
    printf("Enter album name: ");
    scanf(" %[^\n]", new_song->album);
    printf("Enter year released: ");
    scanf("%d", &(new_song->year));
    
    // Add new song to library
    library[*num_songs] = new_song;
    (*num_songs)++;
}

// Print the entire library
void print_library(Song* library[], int num_songs) {
    printf("Library:\n");
    for(int i = 0; i < num_songs; i++) {
        printf("Song #%d: %s - %s (%s, %d)\n", i+1, library[i]->title, library[i]->artist, library[i]->album, library[i]->year);
    }
}