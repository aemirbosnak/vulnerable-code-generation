//FormAI DATASET v1.0 Category: Music Library Management System ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure to represent a song
struct Song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
};

// Function to read a song from the console
void readSong(struct Song *song) {
    printf("\nEnter details of the song:\n\n");
    printf("Title: ");
    fgets(song->title, 50, stdin);
    printf("Artist: ");
    fgets(song->artist, 50, stdin);
    printf("Album: ");
    fgets(song->album, 50, stdin);
    printf("Year: ");
    scanf("%d", &song->year);
}

// Function to print a song to the console
void printSong(struct Song *song) {
    printf("Title: %s", song->title);
    printf("Artist: %s", song->artist);
    printf("Album: %s", song->album);
    printf("Year: %d\n\n", song->year);
}

// Function to add a song to the library
void addSong(struct Song *library, int *numSongs) {
    readSong(&library[*numSongs]);
    (*numSongs)++;
}

// Function to search the library for songs based on title
void searchByTitle(struct Song *library, int numSongs) {
    char title[50];
    printf("\nEnter title to search for: ");
    fgets(title, 50, stdin);
    for(int i=0; i<numSongs; i++) {
        if(strstr(library[i].title, title)) {
            printSong(&library[i]);
        }
    }
}

// Function to search the library for songs based on artist
void searchByArtist(struct Song *library, int numSongs) {
    char artist[50];
    printf("\nEnter artist to search for: ");
    fgets(artist, 50, stdin);
    for(int i=0; i<numSongs; i++) {
        if(strstr(library[i].artist, artist)) {
            printSong(&library[i]);
        }
    }
}

// Function to search the library for songs based on album
void searchByAlbum(struct Song *library, int numSongs) {
    char album[50];
    printf("\nEnter album to search for: ");
    fgets(album, 50, stdin);
    for(int i=0; i<numSongs; i++) {
        if(strstr(library[i].album, album)) {
            printSong(&library[i]);
        }
    }
}

int main() {
    struct Song library[100];
    int numSongs = 0;
    int choice;
    do {
        // Display menu
        printf("Music Library Management System\n\n");
        printf("1. Add Song\n");
        printf("2. Search by Title\n");
        printf("3. Search by Artist\n");
        printf("4. Search by Album\n");
        printf("5. Exit\n\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // Eat the newline character after the user enters their choice
        switch(choice) {
            case 1: addSong(library, &numSongs); break;
            case 2: searchByTitle(library, numSongs); break;
            case 3: searchByArtist(library, numSongs); break;
            case 4: searchByAlbum(library, numSongs); break;
            case 5: printf("Goodbye!"); break;
            default: printf("Invalid choice!");
        }
    } while(choice != 5);
    return 0;
}