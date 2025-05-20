//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSICS 100

typedef struct {
    char title[50];
    char artist[50];
    char genre[30];
    int year;
} Music;

typedef struct {
    Music collection[MAX_MUSICS];
    int count;
} MusicLibrary;

void initializeLibrary(MusicLibrary *library) {
    library->count = 0;
}

void addMusic(MusicLibrary *library) {
    if (library->count >= MAX_MUSICS) {
        printf("Library is full! Unable to add more music.\n");
        return;
    }
    Music m;
    printf("Enter title: ");
    getchar(); // to consume the newline character
    fgets(m.title, sizeof(m.title), stdin);
    m.title[strcspn(m.title, "\n")] = 0; // remove newline character

    printf("Enter artist: ");
    fgets(m.artist, sizeof(m.artist), stdin);
    m.artist[strcspn(m.artist, "\n")] = 0; // remove newline character

    printf("Enter genre: ");
    fgets(m.genre, sizeof(m.genre), stdin);
    m.genre[strcspn(m.genre, "\n")] = 0; // remove newline character

    printf("Enter year: ");
    scanf("%d", &m.year);

    library->collection[library->count++] = m;
    printf("Music added successfully.\n");
}

void displayLibrary(const MusicLibrary *library) {
    if (library->count == 0) {
        printf("The library is empty.\n");
        return;
    }
    printf("\nMusic Library:\n");
    for (int i = 0; i < library->count; i++) {
        printf("Title: %s, Artist: %s, Genre: %s, Year: %d\n",
               library->collection[i].title,
               library->collection[i].artist,
               library->collection[i].genre,
               library->collection[i].year);
    }
}

void searchMusic(const MusicLibrary *library) {
    char searchTerm[50];
    printf("Enter title or artist to search: ");
    getchar(); // consume newline character
    fgets(searchTerm, sizeof(searchTerm), stdin);
    searchTerm[strcspn(searchTerm, "\n")] = 0; // remove newline

    int found = 0;
    for (int i = 0; i < library->count; i++) {
        if (strstr(library->collection[i].title, searchTerm) != NULL ||
            strstr(library->collection[i].artist, searchTerm) != NULL) {
            printf("Found - Title: %s, Artist: %s, Genre: %s, Year: %d\n",
                   library->collection[i].title,
                   library->collection[i].artist,
                   library->collection[i].genre,
                   library->collection[i].year);
            found = 1;
        }
    }
    if (!found) {
        printf("No music found for the given search term.\n");
    }
}

void deleteMusic(MusicLibrary *library) {
    if (library->count == 0) {
        printf("The library is empty. Nothing to delete.\n");
        return;
    }
    
    char title[50];
    printf("Enter title of music to delete: ");
    getchar(); // consume newline character
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = 0; // remove newline

    int found = 0;
    for (int i = 0; i < library->count; i++) {
        if (strcmp(library->collection[i].title, title) == 0) {
            found = 1;
            for (int j = i; j < library->count - 1; j++) {
                library->collection[j] = library->collection[j + 1];
            }
            library->count--;
            printf("Music deleted successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("No music found with that title.\n");
    }
}

void displayMenu() {
    printf("\nMusic Library Management System\n");
    printf("1. Add Music\n");
    printf("2. Display Music Library\n");
    printf("3. Search Music\n");
    printf("4. Delete Music\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    MusicLibrary library;
    initializeLibrary(&library);
    int choice;
    
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addMusic(&library);
                break;
            case 2:
                displayLibrary(&library);
                break;
            case 3:
                searchMusic(&library);
                break;
            case 4:
                deleteMusic(&library);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    
    return 0;
}