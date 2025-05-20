//FormAI DATASET v1.0 Category: Music Library Management System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100 // Maximum number of songs in library
#define MAX_TITLE_LEN 50 // Maximum length of song title
#define MAX_ARTIST_LEN 30 // Maximum length of artist name

// Song struct
typedef struct {
    char title[MAX_TITLE_LEN];
    char artist[MAX_ARTIST_LEN];
    int year;
} Song;

// Library struct
typedef struct {
    Song songs[MAX_SONGS];
    int num_songs;
} Library;

// Prototypes for functions
void add_song(Library* library);
void display_songs(Library* library);
void search_songs(Library* library);
void save_library(Library* library);
void load_library(Library* library);

int main() {
    Library library = { .songs = { 0 }, .num_songs = 0 }; // Create an empty library
    
    int choice;
    do {
        // Display menu
        printf("\n\nMusic Library Management System\n");
        printf("1. Add Song\n");
        printf("2. Display Songs\n");
        printf("3. Search Songs\n");
        printf("4. Save Library\n");
        printf("5. Load Library\n");
        printf("6. Exit\n");
        
        // Get user choice
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_song(&library);
                break;
            case 2:
                display_songs(&library);
                break;
            case 3:
                search_songs(&library);
                break;
            case 4:
                save_library(&library);
                break;
            case 5:
                load_library(&library);
                break;
            case 6:
                printf("\nGoodbye!\n\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
        
    } while (choice != 6);
    
    return 0;
}

// Add a new song to the library
void add_song(Library* library) {
    Song song;
    printf("\nEnter song title: ");
    scanf("%s", song.title);
    printf("Enter artist name: ");
    scanf("%s", song.artist);
    printf("Enter song year: ");
    scanf("%d", &song.year);
    
    if (library->num_songs == MAX_SONGS) {
        printf("\nLibrary is full. Song not added.\n");
        return;
    }
    
    library->songs[library->num_songs] = song;
    library->num_songs++;
    printf("\nSong added to library.\n");
}

// Display all songs in the library
void display_songs(Library* library) {
    if (library->num_songs == 0) {
        printf("\nLibrary is empty.\n");
        return;
    }
    
    printf("\nSongs in library:\n");
    for (int i = 0; i < library->num_songs; i++) {
        printf("%s - %s (%d)\n", library->songs[i].artist, library->songs[i].title, library->songs[i].year);
    }
}

// Search for a song in the library by title
void search_songs(Library* library) {
    if (library->num_songs == 0) {
        printf("\nLibrary is empty.\n");
        return;
    }
    
    char search_title[MAX_TITLE_LEN];
    printf("\nEnter song title to search: ");
    scanf("%s", search_title);
    
    int found = 0;
    for (int i = 0; i < library->num_songs; i++) {
        if (strcmp(search_title, library->songs[i].title) == 0) {
            printf("\n%s - %s (%d)\n", library->songs[i].artist, library->songs[i].title, library->songs[i].year);
            found = 1;
        }
    }
    
    if (!found) {
        printf("\nSong not found in library.\n");
    }
}

// Save the library to a file
void save_library(Library* library) {
    FILE* file = fopen("music_library.txt", "w");
    if (file == NULL) {
        printf("\nError opening file.\n");
        return;
    }
    
    for (int i = 0; i < library->num_songs; i++) {
        fprintf(file, "%s,%s,%d\n", library->songs[i].title, library->songs[i].artist, library->songs[i].year);
    }
    
    fclose(file);
    printf("\nLibrary saved to file.\n");
}

// Load library from a file
void load_library(Library* library) {
    FILE* file = fopen("music_library.txt", "r");
    if (file == NULL) {
        printf("\nError opening file.\n");
        return;
    }
    
    char line[MAX_TITLE_LEN + MAX_ARTIST_LEN + 10];
    while (fgets(line, sizeof(line), file)) {
        char *token;
        token = strtok(line, ",");
        strcpy(library->songs[library->num_songs].title, token);
        token = strtok(NULL, ",");
        strcpy(library->songs[library->num_songs].artist, token);
        token = strtok(NULL, ",");
        library->songs[library->num_songs].year = atoi(token);
        library->num_songs++;
        if (library->num_songs == MAX_SONGS) {
            break;
        }
    }
    
    fclose(file);
    printf("\nLibrary loaded from file.\n");
}