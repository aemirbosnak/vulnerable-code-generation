//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC 100
#define TITLE_LEN 100
#define ARTIST_LEN 100

typedef struct {
    char title[TITLE_LEN];
    char artist[ARTIST_LEN];
    int year;
} Music;

typedef struct {
    Music collection[MAX_MUSIC];
    int count;
} MusicLibrary;

void initializeLibrary(MusicLibrary *library) {
    library->count = 0;
}

void addMusic(MusicLibrary *library) {
    if (library->count >= MAX_MUSIC) {
        printf("Library is full, cannot add more music.\n");
        return;
    }
    
    Music newMusic;
    
    printf("Enter music title: ");
    fgets(newMusic.title, TITLE_LEN, stdin);
    newMusic.title[strcspn(newMusic.title, "\n")] = 0; // Remove newline
    
    printf("Enter artist name: ");
    fgets(newMusic.artist, ARTIST_LEN, stdin);
    newMusic.artist[strcspn(newMusic.artist, "\n")] = 0; // Remove newline
    
    printf("Enter year of release: ");
    scanf("%d", &newMusic.year);
    getchar(); // Clear newline character from input buffer

    library->collection[library->count] = newMusic;
    library->count++;
    
    printf("Music added successfully!\n");
}

void displayMusic(const MusicLibrary *library) {
    if (library->count == 0) {
        printf("No music in the library.\n");
        return;
    }
    
    printf("\nMusic Library:\n");
    for (int i = 0; i < library->count; i++) {
        printf("Title: %s, Artist: %s, Year: %d\n", 
                library->collection[i].title, 
                library->collection[i].artist, 
                library->collection[i].year);
    }
}

void searchMusic(const MusicLibrary *library) {
    char query[TITLE_LEN];
    int found = 0;
    
    printf("Enter music title to search: ");
    fgets(query, TITLE_LEN, stdin);
    query[strcspn(query, "\n")] = 0; // Remove newline
    
    printf("\nSearch Results:\n");
    for (int i = 0; i < library->count; i++) {
        if (strstr(library->collection[i].title, query) != NULL) {
            printf("Found - Title: %s, Artist: %s, Year: %d\n", 
                    library->collection[i].title, 
                    library->collection[i].artist, 
                    library->collection[i].year);
            found = 1;
        }
    }
    if (!found) {
        printf("No matching music found.\n");
    }
}

void deleteMusic(MusicLibrary *library) {
    char query[TITLE_LEN];
    int found = 0;

    printf("Enter music title to delete: ");
    fgets(query, TITLE_LEN, stdin);
    query[strcspn(query, "\n")] = 0; // Remove newline
    
    for (int i = 0; i < library->count; i++) {
        if (strcmp(library->collection[i].title, query) == 0) {
            // Shift the rest of the elements
            for (int j = i; j < library->count - 1; j++) {
                library->collection[j] = library->collection[j + 1];
            }
            library->count--;
            found = 1;
            printf("Music deleted successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Music not found in the library.\n");
    }
}

void menu() {
    printf("\n=== Music Library Management System ===\n");
    printf("1. Add Music\n");
    printf("2. Display Music\n");
    printf("3. Search Music\n");
    printf("4. Delete Music\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

int main() {
    MusicLibrary library;
    initializeLibrary(&library);
    int option;

    while (1) {
        menu();
        scanf("%d", &option);
        getchar(); // Clear newline character from input buffer

        switch (option) {
            case 1:
                addMusic(&library);
                break;
            case 2:
                displayMusic(&library);
                break;
            case 3:
                searchMusic(&library);
                break;
            case 4:
                deleteMusic(&library);
                break;
            case 5:
                printf("Exiting the Music Library Management System.\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }
    }

    return 0;
}