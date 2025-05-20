//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC 100
#define MAX_TITLE_LEN 100
#define MAX_ARTIST_LEN 100

typedef struct {
    char title[MAX_TITLE_LEN];
    char artist[MAX_ARTIST_LEN];
    int year;
} Music;

typedef struct {
    Music collection[MAX_MUSIC];
    int count;
} MusicLibrary;

void displayMenu() {
    printf("\n--- Music Library Management System ---\n");
    printf("1. Add Music\n");
    printf("2. View Music\n");
    printf("3. Search Music\n");
    printf("4. Delete Music\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

void addMusic(MusicLibrary* library) {
    if (library->count >= MAX_MUSIC) {
        printf("Library is full! Cannot add more music.\n");
        return;
    }

    Music newMusic;

    printf("Enter music title: ");
    scanf(" %[^\n]", newMusic.title);
    printf("Enter artist name: ");
    scanf(" %[^\n]", newMusic.artist);
    printf("Enter release year: ");
    scanf("%d", &newMusic.year);
    
    library->collection[library->count] = newMusic;
    library->count++;
    printf("Music added successfully!\n");
}

void viewMusic(MusicLibrary library) {
    if (library.count == 0) {
        printf("No music in the library.\n");
        return;
    }
    
    printf("Music Collection:\n");
    for (int i = 0; i < library.count; i++) {
        printf("%d. %s by %s (%d)\n", i + 1, library.collection[i].title, 
               library.collection[i].artist, library.collection[i].year);
    }
}

void searchMusic(MusicLibrary library) {
    char searchTerm[MAX_TITLE_LEN];
    printf("Enter the title/artist to search: ");
    scanf(" %[^\n]", searchTerm);

    int found = 0;
    printf("Search Results:\n");
    for (int i = 0; i < library.count; i++) {
        if (strstr(library.collection[i].title, searchTerm) != NULL || 
            strstr(library.collection[i].artist, searchTerm) != NULL) {
            printf("%d. %s by %s (%d)\n", i + 1, library.collection[i].title, 
                   library.collection[i].artist, library.collection[i].year);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No matching music found.\n");
    }
}

void deleteMusic(MusicLibrary* library) {
    if (library->count == 0) {
        printf("No music to delete.\n");
        return;
    }

    int index;
    printf("Enter the number of the music to delete (1 - %d): ", library->count);
    scanf("%d", &index);
    if (index < 1 || index > library->count) {
        printf("Invalid number.\n");
        return;
    }
    
    for (int i = index - 1; i < library->count - 1; i++) {
        library->collection[i] = library->collection[i + 1];
    }
    library->count--;
    printf("Music deleted successfully!\n");
}

int main() {
    MusicLibrary library = {0};
    int option;

    while (1) {
        displayMenu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                addMusic(&library);
                break;
            case 2:
                viewMusic(library);
                break;
            case 3:
                searchMusic(library);
                break;
            case 4:
                deleteMusic(&library);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    
    return 0;
}