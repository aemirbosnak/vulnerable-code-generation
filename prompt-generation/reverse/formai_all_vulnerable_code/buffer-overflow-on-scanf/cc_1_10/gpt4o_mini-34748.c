//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC 100
#define TITLE_LENGTH 50
#define ARTIST_LENGTH 50
#define ALBUM_LENGTH 50

typedef struct {
    char title[TITLE_LENGTH];
    char artist[ARTIST_LENGTH];
    char album[ALBUM_LENGTH];
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
        printf("Library is full! Cannot add more music.\n");
        return;
    }

    Music newMusic;
    printf("Enter Title: ");
    getchar();  // to consume any newline left by previous input
    fgets(newMusic.title, TITLE_LENGTH, stdin);
    newMusic.title[strcspn(newMusic.title, "\n")] = 0; // remove newline

    printf("Enter Artist: ");
    fgets(newMusic.artist, ARTIST_LENGTH, stdin);
    newMusic.artist[strcspn(newMusic.artist, "\n")] = 0;

    printf("Enter Album: ");
    fgets(newMusic.album, ALBUM_LENGTH, stdin);
    newMusic.album[strcspn(newMusic.album, "\n")] = 0;

    printf("Enter Year: ");
    scanf("%d", &newMusic.year);

    library->collection[library->count++] = newMusic;
    printf("Music added successfully!\n");
}

void displayMusic(const MusicLibrary *library) {
    if (library->count == 0) {
        printf("No music in the library.\n");
        return;
    }

    printf("\nMusic Collection:\n");
    for (int i = 0; i < library->count; i++) {
        printf("%d. Title: %s, Artist: %s, Album: %s, Year: %d\n",
            i + 1, library->collection[i].title,
            library->collection[i].artist,
            library->collection[i].album,
            library->collection[i].year);
    }
}

void removeMusic(MusicLibrary *library) {
    if (library->count == 0) {
        printf("No music to remove.\n");
        return;
    }

    int index;
    printf("Enter the index of the music to remove (1 to %d): ", library->count);
    scanf("%d", &index);

    if (index < 1 || index > library->count) {
        printf("Invalid index!\n");
        return;
    }

    for (int i = index - 1; i < library->count - 1; i++) {
        library->collection[i] = library->collection[i + 1];
    }

    library->count--;
    printf("Music removed successfully!\n");
}

void searchMusic(const MusicLibrary *library) {
    char searchTerm[TITLE_LENGTH];
    printf("Enter title or artist to search: ");
    getchar();  // to consume any newline left by previous input
    fgets(searchTerm, TITLE_LENGTH, stdin);
    searchTerm[strcspn(searchTerm, "\n")] = 0;

    printf("Search Results:\n");
    for (int i = 0; i < library->count; i++) {
        if (strstr(library->collection[i].title, searchTerm) != NULL ||
            strstr(library->collection[i].artist, searchTerm) != NULL) {
            printf("Title: %s, Artist: %s, Album: %s, Year: %d\n",
                library->collection[i].title, 
                library->collection[i].artist, 
                library->collection[i].album, 
                library->collection[i].year);
        }
    }
}

int main() {
    MusicLibrary myLibrary;
    initializeLibrary(&myLibrary);

    int option;

    do {
        printf("\n--- Music Library Management System ---\n");
        printf("1. Add Music\n");
        printf("2. Display Music\n");
        printf("3. Remove Music\n");
        printf("4. Search Music\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                addMusic(&myLibrary);
                break;
            case 2:
                displayMusic(&myLibrary);
                break;
            case 3:
                removeMusic(&myLibrary);
                break;
            case 4:
                searchMusic(&myLibrary);
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please choose again.\n");
                break;
        }
    } while (option != 5);

    return 0;
}