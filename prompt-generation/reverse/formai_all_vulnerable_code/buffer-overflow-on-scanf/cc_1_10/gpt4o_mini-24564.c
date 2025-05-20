//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[50];
    char artist[50];
    char genre[30];
    int year;
} Music;

typedef struct {
    Music *collection;
    int size;
    int capacity;
} MusicLibrary;

// Function to create a new music library
MusicLibrary* createLibrary(int capacity) {
    MusicLibrary *library = (MusicLibrary *)malloc(sizeof(MusicLibrary));
    library->size = 0;
    library->capacity = capacity;
    library->collection = (Music *)malloc(capacity * sizeof(Music));
    return library;
}

// Function to add a music item to the library
void addMusic(MusicLibrary *library) {
    if (library->size >= library->capacity) {
        library->capacity *= 2;
        library->collection = (Music *)realloc(library->collection, library->capacity * sizeof(Music));
    }
    
    Music newMusic;
    printf("Enter Music Title: ");
    scanf(" %[^\n]", newMusic.title);
    printf("Enter Artist: ");
    scanf(" %[^\n]", newMusic.artist);
    printf("Enter Genre: ");
    scanf(" %[^\n]", newMusic.genre);
    printf("Enter Release Year: ");
    scanf("%d", &newMusic.year);

    library->collection[library->size++] = newMusic;
    printf("Music added successfully!\n");
}

// Function to display all music in the library
void displayLibrary(const MusicLibrary *library) {
    if (library->size == 0) {
        printf("Library is empty.\n");
        return;
    }
    printf("\nMusic Library:\n");
    for (int i = 0; i < library->size; i++) {
        printf("%d. Title: %s, Artist: %s, Genre: %s, Year: %d\n", 
                i + 1, library->collection[i].title, 
                library->collection[i].artist,
                library->collection[i].genre, 
                library->collection[i].year);
    }
}

// Function to find music by title
void findMusicByTitle(const MusicLibrary *library) {
    char title[50];
    printf("Enter the title of the music you want to find: ");
    scanf(" %[^\n]", title);
    
    for (int i = 0; i < library->size; i++) {
        if (strcmp(library->collection[i].title, title) == 0) {
            printf("Found! Title: %s, Artist: %s, Genre: %s, Year: %d\n",
                    library->collection[i].title,
                    library->collection[i].artist,
                    library->collection[i].genre,
                    library->collection[i].year);
            return;
        }
    }
    printf("Music not found.\n");
}

// Function to free the music library's memory
void freeLibrary(MusicLibrary *library) {
    free(library->collection);
    free(library);
}

int main() {
    MusicLibrary *library = createLibrary(5);
    int choice;

    do {
        printf("\n=== Music Library Management System ===\n");
        printf("1. Add Music\n");
        printf("2. Display Library\n");
        printf("3. Find Music by Title\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMusic(library);
                break;
            case 2:
                displayLibrary(library);
                break;
            case 3:
                findMusicByTitle(library);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    freeLibrary(library);
    return 0;
}