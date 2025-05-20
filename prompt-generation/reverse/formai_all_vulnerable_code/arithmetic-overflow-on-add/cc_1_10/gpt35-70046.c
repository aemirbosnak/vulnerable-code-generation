//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define MAX_ALBUMS 100
#define MAX_TITLE_SIZE 50
#define MAX_ARTIST_SIZE 30
#define MAX_GENRE_SIZE 10

// Define structs
typedef struct {
    char title[MAX_TITLE_SIZE];
    char artist[MAX_ARTIST_SIZE];
    int year;
    char genre[MAX_GENRE_SIZE];
} album;

typedef struct {
    album albums[MAX_ALBUMS];
    int size;
} music_library;

// Declare functions
void add_album(music_library *library);
void remove_album(music_library *library);
void display_library(music_library library);
void search_library(music_library library);

// Main function
int main() {
    music_library library = {0};

    int choice = 0;
    while (choice != 5) {
        printf("\n1. Add album\n");
        printf("2. Remove album\n");
        printf("3. Display library\n");
        printf("4. Search library\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_album(&library);
                break;
            case 2:
                remove_album(&library);
                break;
            case 3:
                display_library(library);
                break;
            case 4:
                search_library(library);
                break;
            case 5:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice.\n");
        }
    }

    return 0;
}

// Function to add album to library
void add_album(music_library *library) {
    if (library->size < MAX_ALBUMS) {
        printf("\nEnter the album title: ");
        scanf("%s", library->albums[library->size].title);
        printf("Enter the artist name: ");
        scanf("%s", library->albums[library->size].artist);
        printf("Enter the year of release: ");
        scanf("%d", &library->albums[library->size].year);
        printf("Enter the album genre: ");
        scanf("%s", library->albums[library->size].genre);
        library->size++;
        printf("\nAlbum added to library.\n");
    } else {
        printf("\nLibrary is full, cannot add album.\n");
    }
}

// Function to remove album from library
void remove_album(music_library *library) {
    char title[MAX_TITLE_SIZE];
    printf("\nEnter the title of the album to remove: ");
    scanf("%s", title);

    int i, j;
    for (i = 0; i < library->size; i++) {
        if (strcmp(library->albums[i].title, title) == 0) {
            // Album found, shift all subsequent albums back by one
            for (j = i; j < library->size - 1; j++) {
                strcpy(library->albums[j].title, library->albums[j+1].title);
                strcpy(library->albums[j].artist, library->albums[j+1].artist);
                library->albums[j].year = library->albums[j+1].year;
                strcpy(library->albums[j].genre, library->albums[j+1].genre);
            }
            library->size--;
            printf("\nAlbum removed from library.\n");
            return;
        }
    }

    printf("\nAlbum not found in library.\n");
}

// Function to display entire library
void display_library(music_library library) {
    if (library.size == 0) {
        printf("\nLibrary is empty.\n");
        return;
    }

    printf("\nNumber of albums in library: %d\n", library.size);
    printf("Title\t\tArtist\t\tYear\tGenre\n");
    int i;
    for (i = 0; i < library.size; i++) {
        printf("%s\t\t%s\t\t%d\t%s\n", library.albums[i].title, library.albums[i].artist, library.albums[i].year, library.albums[i].genre);
    }
}

// Function to search library for specific album(s)
void search_library(music_library library) {
    char search_term[MAX_TITLE_SIZE];
    printf("\nEnter the title or artist to search for: ");
    scanf("%s", search_term);

    int i;
    for (i = 0; i < library.size; i++) {
        if (strstr(library.albums[i].title, search_term) != NULL || strstr(library.albums[i].artist, search_term) != NULL) {
            printf("%s\t\t%s\t\t%d\t%s\n", library.albums[i].title, library.albums[i].artist, library.albums[i].year, library.albums[i].genre);
        }
    }
}