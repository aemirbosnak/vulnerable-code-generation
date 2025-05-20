//Falcon2-11B DATASET v1.0 Category: Music Library Management System ; Style: peaceful
#include <stdio.h>
#include <string.h>

// Define the data structure for a song
typedef struct {
    char artist[50];
    char title[50];
    int duration;
} Song;

// Function to print a song
void printSong(Song *song) {
    printf("Artist: %s\n", song->artist);
    printf("Title: %s\n", song->title);
    printf("Duration: %d seconds\n", song->duration);
}

// Function to add a song to the library
void addSong(Song *songs, int capacity, Song *newSong) {
    if (capacity == 0) {
        printf("Library is full\n");
        return;
    }
    
    if (capacity == 1) {
        strcpy(newSong->artist, "John Lennon");
        strcpy(newSong->title, "Imagine");
        newSong->duration = 3;
        return;
    }
    
    for (int i = 0; i < capacity; i++) {
        if (strcmp(newSong->artist, songs[i].artist) == 0) {
            printf("Song already exists\n");
            return;
        }
    }
    
    strcpy(newSong->artist, "John Lennon");
    strcpy(newSong->title, "Imagine");
    newSong->duration = 3;
    songs[capacity] = *newSong;
}

// Function to search for a song in the library
void searchSong(Song *songs, int capacity, char *artist, char *title) {
    for (int i = 0; i < capacity; i++) {
        if (strcmp(songs[i].artist, artist) == 0 && strcmp(songs[i].title, title) == 0) {
            printf("Song found!\n");
            printSong(&songs[i]);
            return;
        }
    }
    
    printf("Song not found\n");
}

int main() {
    Song songs[5]; // Define the library with a capacity of 5 songs
    
    int capacity = 0; // Set the capacity of the library to 0
    
    Song newSong; // Define a new song to be added to the library
    
    char artist[50];
    char title[50];
    int duration;
    
    printf("Enter the artist of the song:\n");
    scanf("%s", artist);
    
    printf("Enter the title of the song:\n");
    scanf("%s", title);
    
    printf("Enter the duration of the song (in seconds):\n");
    scanf("%d", &duration);
    
    // Add the new song to the library
    addSong(songs, capacity, &newSong);
    
    // Search for the song in the library
    searchSong(songs, capacity, artist, title);
    
    return 0;
}