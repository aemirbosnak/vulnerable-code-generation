//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC 100
#define MAX_TITLE_LENGTH 100
#define MAX_ARTIST_LENGTH 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
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
        printf("Library is full, cannot add more music.\n");
        return;
    }

    Music music;
    printf("Enter title: ");
    getchar(); // to consume the newline
    fgets(music.title, MAX_TITLE_LENGTH, stdin);
    strtok(music.title, "\n"); // remove newline character

    printf("Enter artist: ");
    fgets(music.artist, MAX_ARTIST_LENGTH, stdin);
    strtok(music.artist, "\n");

    printf("Enter year: ");
    scanf("%d", &music.year);

    printf("Enter duration (in minutes): ");
    scanf("%f", &music.duration);

    library->collection[library->count++] = music;
    printf("Music added successfully!\n");
}

void displayMusic(const MusicLibrary *library) {
    if (library->count == 0) {
        printf("No music in the library.\n");
        return;
    }

    printf("\n--- Music Library ---\n");
    for (int i = 0; i < library->count; i++) {
        printf("Title: %s, Artist: %s, Year: %d, Duration: %.2f mins\n",
               library->collection[i].title,
               library->collection[i].artist,
               library->collection[i].year,
               library->collection[i].duration);
    }
}

void searchMusic(const MusicLibrary *library) {
    char searchTerm[MAX_TITLE_LENGTH];
    printf("Enter music title or artist to search: ");
    getchar(); // to consume the newline
    fgets(searchTerm, MAX_TITLE_LENGTH, stdin);
    strtok(searchTerm, "\n");

    printf("\n--- Search Results ---\n");
    for (int i = 0; i < library->count; i++) {
        if (strstr(library->collection[i].title, searchTerm) ||
            strstr(library->collection[i].artist, searchTerm)) {
            printf("Title: %s, Artist: %s, Year: %d, Duration: %.2f mins\n",
                   library->collection[i].title,
                   library->collection[i].artist,
                   library->collection[i].year,
                   library->collection[i].duration);
        }
    }
}

void deleteMusic(MusicLibrary *library) {
    char titleToDelete[MAX_TITLE_LENGTH];
    printf("Enter title of the music to delete: ");
    getchar(); // to consume the newline
    fgets(titleToDelete, MAX_TITLE_LENGTH, stdin);
    strtok(titleToDelete, "\n");

    for (int i = 0; i < library->count; i++) {
        if (strcmp(library->collection[i].title, titleToDelete) == 0) {
            for (int j = i; j < library->count - 1; j++) {
                library->collection[j] = library->collection[j + 1];
            }
            library->count--;
            printf("Music deleted successfully!\n");
            return;
        }
    }
    printf("Music not found in the library.\n");
}

void displayMenu() {
    printf("\n--- Music Library Management System ---\n");
    printf("1. Add Music\n");
    printf("2. Display Music\n");
    printf("3. Search Music\n");
    printf("4. Delete Music\n");
    printf("5. Exit\n");
}

int main() {
    MusicLibrary library;
    initializeLibrary(&library);

    int choice;
    while (1) {
        displayMenu();
        printf("Select an option: ");
        scanf("%d", &choice);

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
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}