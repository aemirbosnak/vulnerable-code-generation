//FormAI DATASET v1.0 Category: Music Library Management System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SONGS 100

// Structure to hold song details
typedef struct {
    int id;
    char title[100];
    char artist[100];
    int year;
} Song;

// Array to store songs
Song songs[MAX_SONGS];
int numSongs = 0;

// Function to add a new song to the library
void addSong() {
    Song newSong;
    newSong.id = numSongs + 1;
    printf("Enter song title: ");
    scanf("%s", newSong.title);
    printf("Enter artist name: ");
    scanf("%s", newSong.artist);
    printf("Enter year of release: ");
    scanf("%d", &newSong.year);
    songs[numSongs] = newSong;
    numSongs++;
    printf("Song added successfully!\n");
}

// Function to search for a song by title
void searchSong() {
    char searchTitle[100];
    printf("Enter song title to search: ");
    scanf("%s", searchTitle);
    int found = 0;
    for(int i=0; i<numSongs; i++) {
        if(strcmp(songs[i].title, searchTitle) == 0) {
            printf("Song found! Details:\n");
            printf("ID: %d\n", songs[i].id);
            printf("Title: %s\n", songs[i].title);
            printf("Artist: %s\n", songs[i].artist);
            printf("Year of Release: %d\n", songs[i].year);
            found = 1;
        }
    }
    if(!found) {
        printf("Sorry, no song found with that title!\n");
    }
}

// Function to display all songs in the library
void displaySongs() {
    printf("All songs in the library:\n");
    for(int i=0; i<numSongs; i++) {
        printf("ID: %d\n", songs[i].id);
        printf("Title: %s\n", songs[i].title);
        printf("Artist: %s\n", songs[i].artist);
        printf("Year of Release: %d\n", songs[i].year);
    }
}

// Main function to run the program
int main() {
    int choice;
    while(1) {
        printf("C Music Library Management System\n");
        printf("1. Add a song\n");
        printf("2. Search for a song\n");
        printf("3. Display all songs\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addSong();
                break;
            case 2:
                searchSong();
                break;
            case 3:
                displaySongs();
                break;
            case 4:
                printf("Exiting program...");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}