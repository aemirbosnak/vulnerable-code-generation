//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of albums and the maximum name length
#define MAX_ALBUMS 100
#define MAX_NAME_LENGTH 50

// Structure to represent a music album
typedef struct {
    char title[MAX_NAME_LENGTH];
    char artist[MAX_NAME_LENGTH];
    int release_year;
    char genre[MAX_NAME_LENGTH];
} Album;

// Global array to hold albums
Album albums[MAX_ALBUMS];
int album_count = 0;

// Function declarations
void addAlbum();
void viewAlbums();
void searchAlbum();
void deleteAlbum();
void displayMenu();

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAlbum();
                break;
            case 2:
                viewAlbums();
                break;
            case 3:
                searchAlbum();
                break;
            case 4:
                deleteAlbum();
                break;
            case 5:
                printf("Exiting the program. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to display the main menu
void displayMenu() {
    printf("\n=== Music Library Management System ===\n");
    printf("1. Add Album\n");
    printf("2. View Albums\n");
    printf("3. Search Album\n");
    printf("4. Delete Album\n");
    printf("5. Exit\n");
}

// Function to add a new album
void addAlbum() {
    if (album_count >= MAX_ALBUMS) {
        printf("Album library is full. Cannot add more albums.\n");
        return;
    }

    Album new_album;
    printf("Enter album title: ");
    getchar(); // Clear the newline from buffer
    fgets(new_album.title, MAX_NAME_LENGTH, stdin);
    new_album.title[strcspn(new_album.title, "\n")] = '\0'; // Remove newline

    printf("Enter artist name: ");
    fgets(new_album.artist, MAX_NAME_LENGTH, stdin);
    new_album.artist[strcspn(new_album.artist, "\n")] = '\0';

    printf("Enter release year: ");
    scanf("%d", &new_album.release_year);

    printf("Enter genre: ");
    getchar(); // Clear the newline from buffer
    fgets(new_album.genre, MAX_NAME_LENGTH, stdin);
    new_album.genre[strcspn(new_album.genre, "\n")] = '\0';

    albums[album_count] = new_album;
    album_count++;
    printf("Album added successfully!\n");
}

// Function to view all albums
void viewAlbums() {
    if (album_count == 0) {
        printf("No albums found in the library.\n");
        return;
    }

    printf("\n=== Albums in Library ===\n");
    for (int i = 0; i < album_count; i++) {
        printf("Album %d:\n", i + 1);
        printf("Title: %s\n", albums[i].title);
        printf("Artist: %s\n", albums[i].artist);
        printf("Release Year: %d\n", albums[i].release_year);
        printf("Genre: %s\n\n", albums[i].genre);
    }
}

// Function to search for an album by title
void searchAlbum() {
    char search_title[MAX_NAME_LENGTH];
    printf("Enter album title to search: ");
    getchar(); // Clear the newline from buffer
    fgets(search_title, MAX_NAME_LENGTH, stdin);
    search_title[strcspn(search_title, "\n")] = '\0';

    int found = 0;
    printf("\n=== Search Results ===\n");
    for (int i = 0; i < album_count; i++) {
        if (strcasecmp(albums[i].title, search_title) == 0) {
            printf("Album found!\n");
            printf("Title: %s\n", albums[i].title);
            printf("Artist: %s\n", albums[i].artist);
            printf("Release Year: %d\n", albums[i].release_year);
            printf("Genre: %s\n\n", albums[i].genre);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Album not found in the library.\n");
    }
}

// Function to delete an album by title
void deleteAlbum() {
    char delete_title[MAX_NAME_LENGTH];
    printf("Enter album title to delete: ");
    getchar(); // Clear the newline from buffer
    fgets(delete_title, MAX_NAME_LENGTH, stdin);
    delete_title[strcspn(delete_title, "\n")] = '\0';

    int found = 0;
    for (int i = 0; i < album_count; i++) {
        if (strcasecmp(albums[i].title, delete_title) == 0) {
            for (int j = i; j < album_count - 1; j++) {
                albums[j] = albums[j + 1]; // Shift albums to the left
            }

            album_count--;
            printf("Album deleted successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Album not found in the library.\n");
    }
}