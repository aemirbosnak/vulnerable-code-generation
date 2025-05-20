//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALBUMS 100
#define TITLE_LENGTH 100
#define ARTIST_LENGTH 100
#define GENRE_LENGTH 50

typedef struct {
    char title[TITLE_LENGTH];
    char artist[ARTIST_LENGTH];
    char genre[GENRE_LENGTH];
    int year;
} Album;

typedef struct {
    Album albums[MAX_ALBUMS];
    int count;
} MusicLibrary;

void initializeLibrary(MusicLibrary *library) {
    library->count = 0;
}

void addAlbum(MusicLibrary *library) {
    if (library->count >= MAX_ALBUMS) {
        printf("Library is full, cannot add more albums.\n");
        return;
    }
    Album newAlbum;
    printf("Enter album title: ");
    fgets(newAlbum.title, TITLE_LENGTH, stdin);
    newAlbum.title[strcspn(newAlbum.title, "\n")] = 0;  // Remove newline

    printf("Enter artist name: ");
    fgets(newAlbum.artist, ARTIST_LENGTH, stdin);
    newAlbum.artist[strcspn(newAlbum.artist, "\n")] = 0;

    printf("Enter genre: ");
    fgets(newAlbum.genre, GENRE_LENGTH, stdin);
    newAlbum.genre[strcspn(newAlbum.genre, "\n")] = 0;

    printf("Enter release year: ");
    scanf("%d", &newAlbum.year);
    getchar(); // Clear newline after integer input

    library->albums[library->count++] = newAlbum;
    printf("Album added successfully!\n");
}

void displayAlbums(const MusicLibrary *library) {
    if (library->count == 0) {
        printf("No albums in the library!\n");
        return;
    }
    printf("\n--- Music Albums ---\n");
    for (int i = 0; i < library->count; i++) {
        printf("Album %d:\n", i + 1);
        printf("Title: %s\n", library->albums[i].title);
        printf("Artist: %s\n", library->albums[i].artist);
        printf("Genre: %s\n", library->albums[i].genre);
        printf("Year: %d\n", library->albums[i].year);
        printf("-------------------\n");
    }
}

void searchAlbum(const MusicLibrary *library) {
    char searchTitle[TITLE_LENGTH];
    printf("Enter the title of the album to search: ");
    fgets(searchTitle, TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0;

    for (int i = 0; i < library->count; i++) {
        if (strcasecmp(library->albums[i].title, searchTitle) == 0) {
            printf("Album found:\n");
            printf("Title: %s\nArtist: %s\nGenre: %s\nYear: %d\n",
                   library->albums[i].title,
                   library->albums[i].artist,
                   library->albums[i].genre,
                   library->albums[i].year);
            return;
        }
    }
    printf("Album not found.\n");
}

void deleteAlbum(MusicLibrary *library) {
    char deleteTitle[TITLE_LENGTH];
    printf("Enter the title of the album to delete: ");
    fgets(deleteTitle, TITLE_LENGTH, stdin);
    deleteTitle[strcspn(deleteTitle, "\n")] = 0;

    for (int i = 0; i < library->count; i++) {
        if (strcasecmp(library->albums[i].title, deleteTitle) == 0) {
            for (int j = i; j < library->count - 1; j++) {
                library->albums[j] = library->albums[j + 1];
            }
            library->count--;
            printf("Album deleted successfully!\n");
            return;
        }
    }
    printf("Album not found.\n");
}

int main() {
    MusicLibrary myLibrary;
    initializeLibrary(&myLibrary);
    int choice;

    while (1) {
        printf("\n--- Music Library Management System ---\n");
        printf("1. Add Album\n");
        printf("2. Display Albums\n");
        printf("3. Search Album\n");
        printf("4. Delete Album\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1: // Add Album
                addAlbum(&myLibrary);
                break;
            case 2: // Display Albums
                displayAlbums(&myLibrary);
                break;
            case 3: // Search Album
                searchAlbum(&myLibrary);
                break;
            case 4: // Delete Album
                deleteAlbum(&myLibrary);
                break;
            case 5: // Exit
                printf("Thank you for using the Music Library Management System!\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}