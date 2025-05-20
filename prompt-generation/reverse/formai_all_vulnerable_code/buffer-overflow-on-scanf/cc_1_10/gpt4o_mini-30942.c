//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALBUMS 100
#define TITLE_LENGTH 100
#define ARTIST_LENGTH 100

typedef struct {
    char title[TITLE_LENGTH];
    char artist[ARTIST_LENGTH];
    int year;
} Album;

typedef struct {
    Album albums[MAX_ALBUMS];
    int count;
} MusicLibrary;

void initializeLibrary(MusicLibrary *library) {
    library->count = 0;
    printf("Music library initialized! Ready to manage your albums!\n");
}

void addAlbum(MusicLibrary *library) {
    if (library->count >= MAX_ALBUMS) {
        printf("Library is full! Cannot add more albums.\n");
        return;
    }
    
    Album newAlbum;
    printf("Enter album title: ");
    scanf(" %[^\n]", newAlbum.title);
    printf("Enter artist name: ");
    scanf(" %[^\n]", newAlbum.artist);
    printf("Enter release year: ");
    scanf("%d", &newAlbum.year);
    
    library->albums[library->count] = newAlbum;
    library->count++;
    printf("Album added successfully: '%s' by %s (%d)\n", 
           newAlbum.title, newAlbum.artist, newAlbum.year);
}

void displayAlbums(const MusicLibrary *library) {
    if (library->count == 0) {
        printf("No albums available in the library.\n");
        return;
    }
    
    printf("---- Music Library ----\n");
    for (int i = 0; i < library->count; i++) {
        printf("%d. '%s' by %s (%d)\n", 
               i + 1, library->albums[i].title, 
               library->albums[i].artist, library->albums[i].year);
    }
}

void searchAlbum(const MusicLibrary *library) {
    char title[TITLE_LENGTH];
    printf("Enter the album title to search: ");
    scanf(" %[^\n]", title);
    
    int found = 0;
    for (int i = 0; i < library->count; i++) {
        if (strcmp(library->albums[i].title, title) == 0) {
            printf("Album found: '%s' by %s (%d)\n", 
                   library->albums[i].title, 
                   library->albums[i].artist, 
                   library->albums[i].year);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No album found with the title '%s'.\n", title);
    }
}

void deleteAlbum(MusicLibrary *library) {
    char title[TITLE_LENGTH];
    printf("Enter the album title to delete: ");
    scanf(" %[^\n]", title);
    
    int index = -1;
    for (int i = 0; i < library->count; i++) {
        if (strcmp(library->albums[i].title, title) == 0) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("No album found with the title '%s'.\n", title);
        return;
    }
    
    for (int i = index; i < library->count - 1; i++) {
        library->albums[i] = library->albums[i + 1];
    }
    
    library->count--;
    printf("Album '%s' deleted successfully.\n", title);
}

void displayMenu() {
    printf("\n---- Music Library Menu ----\n");
    printf("1. Add Album\n");
    printf("2. Display Albums\n");
    printf("3. Search Album\n");
    printf("4. Delete Album\n");
    printf("5. Exit\n");
}

int main() {
    MusicLibrary library;
    initializeLibrary(&library);
    
    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addAlbum(&library);
                break;
            case 2:
                displayAlbums(&library);
                break;
            case 3:
                searchAlbum(&library);
                break;
            case 4:
                deleteAlbum(&library);
                break;
            case 5:
                printf("Exiting the music library. Happy listening!\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
                break;
        }
    } while (choice != 5);
    
    return 0;
}