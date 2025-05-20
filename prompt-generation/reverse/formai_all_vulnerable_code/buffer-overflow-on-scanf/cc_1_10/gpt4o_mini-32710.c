//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: thoughtful
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
        printf("Music library is full!\n");
        return;
    }

    Music new_music;
    printf("Enter title: ");
    fgets(new_music.title, TITLE_LEN, stdin);
    new_music.title[strcspn(new_music.title, "\n")] = '\0'; // Remove newline

    printf("Enter artist: ");
    fgets(new_music.artist, ARTIST_LEN, stdin);
    new_music.artist[strcspn(new_music.artist, "\n")] = '\0'; // Remove newline

    printf("Enter year: ");
    scanf("%d", &new_music.year);
    getchar(); // Consume leftover newline

    library->collection[library->count] = new_music;
    library->count++;
    printf("Music added successfully!\n");
}

void displayLibrary(MusicLibrary *library) {
    if (library->count == 0) {
        printf("No music in the library!\n");
        return;
    }

    printf("\nMusic Library:\n");
    for (int i = 0; i < library->count; i++) {
        printf("ID: %d | Title: \"%s\" | Artist: \"%s\" | Year: %d\n", 
                i + 1, library->collection[i].title, 
                library->collection[i].artist, 
                library->collection[i].year);
    }
}

void searchMusic(MusicLibrary *library) {
    char search_title[TITLE_LEN];
    printf("Enter title to search: ");
    fgets(search_title, TITLE_LEN, stdin);
    search_title[strcspn(search_title, "\n")] = '\0'; // Remove newline

    int found = 0;
    for (int i = 0; i < library->count; i++) {
        if (strcasecmp(library->collection[i].title, search_title) == 0) {
            printf("Found: ID: %d | Title: \"%s\" | Artist: \"%s\" | Year: %d\n", 
                    i + 1, library->collection[i].title, 
                    library->collection[i].artist, 
                    library->collection[i].year);
            found = 1;
        }
    }
    if (!found) {
        printf("No music found with title \"%s\".\n", search_title);
    }
}

void deleteMusic(MusicLibrary *library) {
    int id;
    printf("Enter the ID of the music to delete: ");
    scanf("%d", &id);
    getchar(); // Consume leftover newline

    if (id < 1 || id > library->count) {
        printf("Invalid ID!\n");
        return;
    }

    for (int i = id - 1; i < library->count - 1; i++) {
        library->collection[i] = library->collection[i + 1];
    }
    library->count--;
    printf("Music deleted successfully!\n");
}

int main() {
    MusicLibrary library;
    initializeLibrary(&library);
    int choice;

    do {
        printf("\n--- Music Library Management System ---\n");
        printf("1. Add Music\n");
        printf("2. Display Library\n");
        printf("3. Search Music\n");
        printf("4. Delete Music\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume leftover newline

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
                printf("Exiting the Music Library Management System. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);

    return 0;
}