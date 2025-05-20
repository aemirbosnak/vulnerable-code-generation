//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: single-threaded
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
    float duration; // in minutes
} Music;

// Function prototypes
void addMusic(Music *library, int *count);
void viewMusic(const Music *library, int count);
void searchMusic(const Music *library, int count);
void deleteMusic(Music *library, int *count);
void displayMenu();

int main() {
    Music library[MAX_MUSIC];
    int count = 0;
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addMusic(library, &count);
                break;
            case 2:
                viewMusic(library, count);
                break;
            case 3:
                searchMusic(library, count);
                break;
            case 4:
                deleteMusic(library, &count);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void addMusic(Music *library, int *count) {
    if (*count >= MAX_MUSIC) {
        printf("Library is full! Cannot add more music.\n");
        return;
    }

    Music newMusic;
    printf("Enter title: ");
    getchar(); // Consume newline character
    fgets(newMusic.title, TITLE_LENGTH, stdin);
    newMusic.title[strcspn(newMusic.title, "\n")] = '\0'; // Remove newline

    printf("Enter artist: ");
    fgets(newMusic.artist, ARTIST_LENGTH, stdin);
    newMusic.artist[strcspn(newMusic.artist, "\n")] = '\0';

    printf("Enter album: ");
    fgets(newMusic.album, ALBUM_LENGTH, stdin);
    newMusic.album[strcspn(newMusic.album, "\n")] = '\0';

    printf("Enter year: ");
    scanf("%d", &newMusic.year);
    
    printf("Enter duration (in minutes): ");
    scanf("%f", &newMusic.duration);

    library[*count] = newMusic;
    (*count)++;
    printf("Music added successfully!\n");
}

void viewMusic(const Music *library, int count) {
    if (count == 0) {
        printf("No music in the library.\n");
        return;
    }
    
    printf("\nMusic Library:\n");
    printf("--------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s | Artist: %s | Album: %s | Year: %d | Duration: %.2f mins\n",
               library[i].title, library[i].artist, library[i].album,
               library[i].year, library[i].duration);
    }
    printf("--------------------------------------------------------\n");
}

void searchMusic(const Music *library, int count) {
    if (count == 0) {
        printf("Library is empty. Cannot search music.\n");
        return;
    }

    char query[TITLE_LENGTH];
    printf("Enter title or artist to search: ");
    getchar(); // Consume newline character
    fgets(query, TITLE_LENGTH, stdin);
    query[strcspn(query, "\n")] = '\0'; // Remove newline

    printf("Search results:\n");
    printf("--------------------------------------------------------\n");
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strstr(library[i].title, query) || strstr(library[i].artist, query)) {
            printf("Title: %s | Artist: %s | Album: %s | Year: %d | Duration: %.2f mins\n",
                   library[i].title, library[i].artist, library[i].album,
                   library[i].year, library[i].duration);
            found = 1;
        }
    }
    if (!found) {
        printf("No results found.\n");
    }
    printf("--------------------------------------------------------\n");
}

void deleteMusic(Music *library, int *count) {
    if (*count == 0) {
        printf("Library is empty. Nothing to delete.\n");
        return;
    }

    char title[TITLE_LENGTH];
    printf("Enter the title of the music to delete: ");
    getchar(); // Consume newline character
    fgets(title, TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = '\0'; // Remove newline

    for (int i = 0; i < *count; i++) {
        if (strcmp(library[i].title, title) == 0) {
            for (int j = i; j < *count - 1; j++) {
                library[j] = library[j + 1]; // Shift music down
            }
            (*count)--;
            printf("Music deleted successfully!\n");
            return;
        }
    }
    printf("Music not found in the library.\n");
}

void displayMenu() {
    printf("\n----- Music Library Management System -----\n");
    printf("1. Add Music\n");
    printf("2. View Music\n");
    printf("3. Search Music\n");
    printf("4. Delete Music\n");
    printf("5. Exit\n");
}