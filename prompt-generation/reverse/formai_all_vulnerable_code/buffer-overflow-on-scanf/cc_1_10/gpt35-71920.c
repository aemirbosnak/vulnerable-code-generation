//FormAI DATASET v1.0 Category: Music Library Management System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for maximum number of albums and maximum title length
#define MAX_ALBUMS 100
#define MAX_TITLE_LENGTH 50

// Define a struct to represent an album
typedef struct Album {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_TITLE_LENGTH];
    int yearReleased;
    char genre[MAX_TITLE_LENGTH];
} Album;

// Define a global array to store albums and a variable to track current number of albums
Album albums[MAX_ALBUMS];
int numAlbums = 0;

// Define function to display the main menu and return the user's choice
int displayMainMenu() {
    printf("\nMusic Library Management System");
    printf("\n1. Add a new album");
    printf("\n2. Display all albums");
    printf("\n3. Search for an album");
    printf("\n4. Quit");
    int choice;
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Define function to add a new album
void addNewAlbum() {
    printf("\nEnter the album title: ");
    scanf("%s", albums[numAlbums].title);
    printf("Enter the artist name: ");
    scanf("%s", albums[numAlbums].artist);
    printf("Enter the year released: ");
    scanf("%d", &albums[numAlbums].yearReleased);
    printf("Enter the genre: ");
    scanf("%s", albums[numAlbums].genre);
    numAlbums++;
    printf("\nAlbum added successfully!\n");
}

// Define function to display all albums
void displayAllAlbums() {
    printf("\nAll Albums (%d total):\n", numAlbums);
    printf("==================================\n");
    for (int i = 0; i < numAlbums; i++) {
        printf("Title: %s\n", albums[i].title);
        printf("Artist: %s\n", albums[i].artist);
        printf("Year Released: %d\n", albums[i].yearReleased);
        printf("Genre: %s\n", albums[i].genre);
        printf("-------------------------------\n");
    }
}

// Define function to search for an album by title
void searchForAlbum() {
    char title[MAX_TITLE_LENGTH];
    printf("\nEnter the album title to search for: ");
    scanf("%s", title);
    for (int i = 0; i < numAlbums; i++) {
        if (strcmp(title, albums[i].title) == 0) {
            printf("\nAlbum found:\n");
            printf("-------------------------------\n");
            printf("Title: %s\n", albums[i].title);
            printf("Artist: %s\n", albums[i].artist);
            printf("Year Released: %d\n", albums[i].yearReleased);
            printf("Genre: %s\n", albums[i].genre);
            printf("-------------------------------\n");
            return;
        }
    }
    printf("\nAlbum not found.\n");
}

int main() {
    int choice;
    do {
        choice = displayMainMenu();
        switch (choice) {
            case 1:
                addNewAlbum();
                break;
            case 2:
                displayAllAlbums();
                break;
            case 3:
                searchForAlbum();
                break;
            case 4:
                printf("\nThank you for using the Music Library Management System!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);
    return 0;
}