//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SONGS 1000

// Data Structure to store a Song
struct Song {
    char title[100];
    char artist[50];
    char album[50];
    int year;
};

// Initialize the Music Library with empty entries
struct Song library[MAX_SONGS];
int num_songs = 0;

// Function to Add a Song to the Library
void addSong() {
    if(num_songs == MAX_SONGS) {
        printf("The Music Library is full. Cannot add more songs.\n");
        return;
    }
    struct Song song;
    printf("Enter the Song Title: ");
    scanf("%s", song.title);
    printf("Enter the Artist Name: ");
    scanf("%s", song.artist);
    printf("Enter the Album Name: ");
    scanf("%s", song.album);
    printf("Enter the Year of Release: ");
    scanf("%d", &song.year);
    library[num_songs++] = song;
    printf("Song added successfully to the Music Library.\n");
}

// Function to Search for a Song in the Library
void searchSong() {
    char title[100];
    printf("Enter the Song Title: ");
    scanf("%s", title);
    for(int i = 0; i < num_songs; i++) {
        if(strcmp(title, library[i].title) == 0) {
            printf("Song found in the Music Library.\n");
            printf("Title: %s\n", library[i].title);
            printf("Artist: %s\n", library[i].artist);
            printf("Album: %s\n", library[i].album);
            printf("Year: %d\n", library[i].year);
            return;
        }
    }
    printf("Song not found in the Music Library.\n");
}

// Function to Display all the Songs in the Library
void displaySongs() {
    if(num_songs == 0) {
        printf("The Music Library is empty. Cannot display songs.\n");
        return;
    }
    printf("List of Songs in the Music Library:\n");
    for(int i = 0; i < num_songs; i++) {
        printf("Title: %s, Artist: %s, Album: %s, Year: %d\n",
            library[i].title, library[i].artist, library[i].album, library[i].year);
    }
}

int main() {
    printf("Welcome to the Music Library Management System in C.\n");
    printf("I am Sherlock, your personal assistant.\n");
    while(1) {
        printf("What would you like to do?\n");
        printf("1. Add a Song to the Library\n");
        printf("2. Search for a Song in the Library\n");
        printf("3. Display all the Songs in the Library\n");
        printf("4. Exit the System\n");
        int choice;
        printf("Please Enter your Choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: addSong(); break;
            case 2: searchSong(); break;
            case 3: displaySongs(); break;
            case 4: printf("Thank you for using the Music Library Management System. Goodbye!\n"); exit(0);
            default: printf("Invalid Choice. Please try again.\n");
        }
    }
    return 0;
}