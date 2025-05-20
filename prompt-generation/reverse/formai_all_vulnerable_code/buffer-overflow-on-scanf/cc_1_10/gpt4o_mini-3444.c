//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define MAX_TITLE_LENGTH 100
#define MAX_ARTIST_LENGTH 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    int year;
} Song;

typedef struct {
    Song songs[MAX_SONGS];
    int count;
} MusicLibrary;

void initializeLibrary(MusicLibrary *library) {
    library->count = 0;
}

void addSong(MusicLibrary *library) {
    if (library->count >= MAX_SONGS) {
        printf("Music library is full. Cannot add more songs.\n");
        return;
    }
    
    Song newSong;
    printf("Enter song title: ");
    getchar(); // To consume newline character
    fgets(newSong.title, MAX_TITLE_LENGTH, stdin);
    newSong.title[strcspn(newSong.title, "\n")] = 0; // Remove newline
    
    printf("Enter artist name: ");
    fgets(newSong.artist, MAX_ARTIST_LENGTH, stdin);
    newSong.artist[strcspn(newSong.artist, "\n")] = 0; // Remove newline

    printf("Enter release year: ");
    scanf("%d", &newSong.year);
    
    library->songs[library->count] = newSong;
    library->count++;
    printf("Song added successfully!\n");
}

void displaySongs(MusicLibrary *library) {
    if (library->count == 0) {
        printf("No songs in the library.\n");
        return;
    }
    
    printf("\n--- Music Library ---\n");
    for (int i = 0; i < library->count; i++) {
        printf("Song %d: Title: %s, Artist: %s, Year: %d\n", 
            i + 1, library->songs[i].title, library->songs[i].artist, library->songs[i].year);
    }
}

void searchSong(MusicLibrary *library) {
    if (library->count == 0) {
        printf("No songs in the library to search.\n");
        return;
    }
    
    char searchTitle[MAX_TITLE_LENGTH];
    printf("Enter the title of the song to search: ");
    getchar(); // To consume newline
    fgets(searchTitle, MAX_TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // Remove newline
    
    for (int i = 0; i < library->count; i++) {
        if (strcmp(library->songs[i].title, searchTitle) == 0) {
            printf("Song found: Title: %s, Artist: %s, Year: %d\n", 
                library->songs[i].title, library->songs[i].artist, library->songs[i].year);
            return;
        }
    }
    
    printf("Song not found in the library.\n");
}

void displayMenu() {
    printf("\n--- Music Library Management System ---\n");
    printf("1. Add Song\n");
    printf("2. Display Songs\n");
    printf("3. Search Song\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    MusicLibrary library;
    initializeLibrary(&library);
    
    int option;
    
    while (1) {
        displayMenu();
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                addSong(&library);
                break;
            case 2:
                displaySongs(&library);
                break;
            case 3:
                searchSong(&library);
                break;
            case 4:
                printf("Exiting the Music Library Management System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }
    }
    
    return 0;
}