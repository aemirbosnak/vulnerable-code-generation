//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC 100
#define TITLE_LENGTH 50
#define ARTIST_LENGTH 50

typedef struct {
    char title[TITLE_LENGTH];
    char artist[ARTIST_LENGTH];
    int year;
} Music;

typedef struct {
    Music library[MAX_MUSIC];
    int count;
} MusicLibrary;

void initializeLibrary(MusicLibrary *lib) {
    lib->count = 0;
}

void addMusic(MusicLibrary *lib) {
    if (lib->count >= MAX_MUSIC) {
        printf("Library is full. Cannot add more music.\n");
        return;
    }
    Music newMusic;
    printf("Enter title of the music: ");
    getchar(); // Clear newline from buffer
    fgets(newMusic.title, TITLE_LENGTH, stdin);
    newMusic.title[strcspn(newMusic.title, "\n")] = 0; // Remove newline character

    printf("Enter artist name: ");
    fgets(newMusic.artist, ARTIST_LENGTH, stdin);
    newMusic.artist[strcspn(newMusic.artist, "\n")] = 0; // Remove newline character

    printf("Enter year of release: ");
    scanf("%d", &newMusic.year);

    lib->library[lib->count++] = newMusic;
    printf("Music added successfully.\n");
}

void displayLibrary(MusicLibrary *lib) {
    if (lib->count == 0) {
        printf("No music in library.\n");
        return;
    }

    printf("\n--- Music Library ---\n");
    for (int i = 0; i < lib->count; i++) {
        printf("Title: %s, Artist: %s, Year: %d\n", lib->library[i].title, lib->library[i].artist, lib->library[i].year);
    }
    printf("---------------------\n");
}

void searchMusic(MusicLibrary *lib) {
    char searchTitle[TITLE_LENGTH];
    printf("Enter title of the music to search: ");
    getchar(); // Clear newline from buffer
    fgets(searchTitle, TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // Remove newline character

    int found = 0;
    for (int i = 0; i < lib->count; i++) {
        if (strcasecmp(lib->library[i].title, searchTitle) == 0) {
            found = 1;
            printf("Found: Title: %s, Artist: %s, Year: %d\n",
                lib->library[i].title, lib->library[i].artist, lib->library[i].year);
        }
    }
    if (!found) {
        printf("Music not found in library.\n");
    }
}

void deleteMusic(MusicLibrary *lib) {
    char titleToDelete[TITLE_LENGTH];
    printf("Enter title of the music to delete: ");
    getchar(); // Clear newline from buffer
    fgets(titleToDelete, TITLE_LENGTH, stdin);
    titleToDelete[strcspn(titleToDelete, "\n")] = 0; // Remove newline character
    
    for (int i = 0; i < lib->count; i++) {
        if (strcasecmp(lib->library[i].title, titleToDelete) == 0) {
            for (int j = i; j < lib->count - 1; j++) {
                lib->library[j] = lib->library[j + 1]; // Shift left
            }
            lib->count--;
            printf("Music deleted successfully.\n");
            return;
        }
    }
    printf("Music not found. Cannot delete.\n");
}

void saveLibrary(MusicLibrary *lib) {
    FILE *file = fopen("music_library.dat", "wb");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    fwrite(lib, sizeof(MusicLibrary), 1, file);
    fclose(file);
    printf("Library saved successfully.\n");
}

void loadLibrary(MusicLibrary *lib) {
    FILE *file = fopen("music_library.dat", "rb");
    if (file == NULL) {
        printf("No existing library to load.\n");
        return;
    }
    fread(lib, sizeof(MusicLibrary), 1, file);
    fclose(file);
    printf("Library loaded successfully. Total music: %d\n", lib->count);
}

void showMenu() {
    printf("\n--- Music Library Menu ---\n");
    printf("1. Add Music\n");
    printf("2. Display Library\n");
    printf("3. Search Music\n");
    printf("4. Delete Music\n");
    printf("5. Save Library\n");
    printf("6. Load Library\n");
    printf("7. Exit\n");
    printf("---------------------------\n");
}

int main() {
    MusicLibrary myLibrary;
    initializeLibrary(&myLibrary);
    loadLibrary(&myLibrary);

    int choice;
    do {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addMusic(&myLibrary);
                break;
            case 2:
                displayLibrary(&myLibrary);
                break;
            case 3:
                searchMusic(&myLibrary);
                break;
            case 4:
                deleteMusic(&myLibrary);
                break;
            case 5:
                saveLibrary(&myLibrary);
                break;
            case 6:
                loadLibrary(&myLibrary);
                break;
            case 7:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}