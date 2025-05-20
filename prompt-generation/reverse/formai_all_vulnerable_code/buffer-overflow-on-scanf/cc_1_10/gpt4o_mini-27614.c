//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC 100
#define MAX_NAME 100
#define MAX_ARTIST 100

typedef struct {
    char title[MAX_NAME];
    char artist[MAX_ARTIST];
    int year;
    float duration; // in minutes
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
        printf("Music collection is full!\n");
        return;
    }
    
    Music newMusic;
    
    printf("Enter title: ");
    fgets(newMusic.title, MAX_NAME, stdin);
    strtok(newMusic.title, "\n"); // Remove newline character
    
    printf("Enter artist: ");
    fgets(newMusic.artist, MAX_ARTIST, stdin);
    strtok(newMusic.artist, "\n");
    
    printf("Enter year: ");
    scanf("%d", &newMusic.year);
    
    printf("Enter duration (in minutes): ");
    scanf("%f", &newMusic.duration);
    getchar(); // To consume the newline after the float input
    
    library->collection[library->count] = newMusic;
    library->count++;
    printf("Music added successfully!\n");
}

void displayMusic(MusicLibrary *library) {
    if (library->count == 0) {
        printf("No music in the library.\n");
        return;
    }
    
    printf("\nMusic Collection:\n");
    for (int i = 0; i < library->count; i++) {
        printf("%d. Title: %s, Artist: %s, Year: %d, Duration: %.2f mins\n",
               i + 1, library->collection[i].title, library->collection[i].artist,
               library->collection[i].year, library->collection[i].duration);
    }
}

void searchMusic(MusicLibrary *library) {
    char searchTerm[MAX_NAME];
    printf("Enter title or artist to search: ");
    fgets(searchTerm, MAX_NAME, stdin);
    strtok(searchTerm, "\n"); // Remove newline character
    
    printf("Search results:\n");
    int found = 0;
    for (int i = 0; i < library->count; i++) {
        if (strstr(library->collection[i].title, searchTerm) != NULL ||
            strstr(library->collection[i].artist, searchTerm) != NULL) {
            printf("%d. Title: %s, Artist: %s, Year: %d, Duration: %.2f mins\n",
                   i + 1, library->collection[i].title, library->collection[i].artist,
                   library->collection[i].year, library->collection[i].duration);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No music found matching '%s'.\n", searchTerm);
    }
}

void deleteMusic(MusicLibrary *library) {
    if (library->count == 0) {
        printf("No music to delete.\n");
        return;
    }
    
    displayMusic(library);
    
    int index;
    printf("Enter the number of the music to delete: ");
    scanf("%d", &index);
    getchar(); // To consume the newline after integer input
    
    if (index < 1 || index > library->count) {
        printf("Invalid selection!\n");
        return;
    }
    
    for (int i = index - 1; i < library->count - 1; i++) {
        library->collection[i] = library->collection[i + 1];
    }
    
    library->count--;
    printf("Music deleted successfully!\n");
}

void menu() {
    printf("\n--- Music Library Management System ---\n");
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
    
    int choice;
    do {
        menu();
        scanf("%d", &choice);
        getchar(); // To consume the newline after integer input

        switch (choice) {
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
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}