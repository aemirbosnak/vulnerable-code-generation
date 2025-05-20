//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC 100

typedef struct {
    char title[100];
    char artist[100];
    char genre[50];
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
        printf("Library is full! Cannot add more music.\n");
        return;
    }
    
    Music newMusic;

    printf("Enter Music Title: ");
    getchar(); // consume newline
    fgets(newMusic.title, sizeof(newMusic.title), stdin);
    newMusic.title[strcspn(newMusic.title, "\n")] = 0; // remove newline

    printf("Enter Artist Name: ");
    fgets(newMusic.artist, sizeof(newMusic.artist), stdin);
    newMusic.artist[strcspn(newMusic.artist, "\n")] = 0; // remove newline

    printf("Enter Genre: ");
    fgets(newMusic.genre, sizeof(newMusic.genre), stdin);
    newMusic.genre[strcspn(newMusic.genre, "\n")] = 0; // remove newline

    printf("Enter Year of Release: ");
    scanf("%d", &newMusic.year);

    lib->library[lib->count] = newMusic;
    lib->count++;

    printf("Music added successfully!\n");
}

void displayLibrary(const MusicLibrary *lib) {
    if (lib->count == 0) {
        printf("Music library is empty.\n");
        return;
    }

    printf("\n--- Music Library ---\n");
    for (int i = 0; i < lib->count; i++) {
        printf("Title: %s\n", lib->library[i].title);
        printf("Artist: %s\n", lib->library[i].artist);
        printf("Genre: %s\n", lib->library[i].genre);
        printf("Year: %d\n\n", lib->library[i].year);
    }
}

void searchMusic(const MusicLibrary *lib) {
    char searchTitle[100];
    printf("Enter the title of the music to search: ");
    getchar(); // consume newline
    fgets(searchTitle, sizeof(searchTitle), stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // remove newline

    int found = 0;
    for (int i = 0; i < lib->count; i++) {
        if (strcasecmp(lib->library[i].title, searchTitle) == 0) {
            printf("\nMusic Found!\n");
            printf("Title: %s\n", lib->library[i].title);
            printf("Artist: %s\n", lib->library[i].artist);
            printf("Genre: %s\n", lib->library[i].genre);
            printf("Year: %d\n\n", lib->library[i].year);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Music not found in the library.\n");
    }
}

void deleteMusic(MusicLibrary *lib) {
    if (lib->count == 0) {
        printf("Music library is empty. Cannot delete anything.\n");
        return;
    }

    char deleteTitle[100];
    printf("Enter the title of the music to delete: ");
    getchar(); // consume newline
    fgets(deleteTitle, sizeof(deleteTitle), stdin);
    deleteTitle[strcspn(deleteTitle, "\n")] = 0; // remove newline

    int found = 0;
    for (int i = 0; i < lib->count; i++) {
        if (strcasecmp(lib->library[i].title, deleteTitle) == 0) {
            found = 1;
            for (int j = i; j < lib->count - 1; j++) {
                lib->library[j] = lib->library[j + 1];
            }
            lib->count--;
            printf("Music deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Music not found in the library.\n");
    }
}

void menu() {
    printf("\n--- Music Library Management System ---\n");
    printf("1. Add Music\n");
    printf("2. Display Music Library\n");
    printf("3. Search Music\n");
    printf("4. Delete Music\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

int main() {
    MusicLibrary myLibrary;
    initializeLibrary(&myLibrary);

    int choice;
    do {
        menu();
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
                printf("Exiting the Music Library Management System. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}