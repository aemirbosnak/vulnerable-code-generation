//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define BUFFER_SIZE 256

typedef struct {
    char title[BUFFER_SIZE];
    char artist[BUFFER_SIZE];
    char album[BUFFER_SIZE];
    int year;
} Song;

void addSong(Song *library, int *count);
void deleteSong(Song *library, int *count);
void displaySongs(const Song *library, int count);
void menu();
void flushInput();

int main() {
    Song musicLibrary[MAX_SONGS];
    int songCount = 0;
    int choice;

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        flushInput();
        
        switch (choice) {
            case 1:
                addSong(musicLibrary, &songCount);
                break;
            case 2:
                deleteSong(musicLibrary, &songCount);
                break;
            case 3:
                displaySongs(musicLibrary, songCount);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void menu() {
    printf("\n=== Music Library Management ===\n");
    printf("1. Add a new song\n");
    printf("2. Delete a song\n");
    printf("3. Display all songs\n");
    printf("4. Exit\n");
}

void addSong(Song *library, int *count) {
    if (*count >= MAX_SONGS) {
        printf("Library is full! Cannot add more songs.\n");
        return;
    }

    printf("Enter song title: ");
    fgets(library[*count].title, BUFFER_SIZE, stdin);
    library[*count].title[strcspn(library[*count].title, "\n")] = '\0';  // Remove newline

    printf("Enter artist name: ");
    fgets(library[*count].artist, BUFFER_SIZE, stdin);
    library[*count].artist[strcspn(library[*count].artist, "\n")] = '\0';

    printf("Enter album name: ");
    fgets(library[*count].album, BUFFER_SIZE, stdin);
    library[*count].album[strcspn(library[*count].album, "\n")] = '\0';

    printf("Enter year of release: ");
    scanf("%d", &library[*count].year);
    flushInput();

    (*count)++;
    printf("Song added successfully!\n");
}

void deleteSong(Song *library, int *count) {
    if (*count == 0) {
        printf("No songs available to delete.\n");
        return;
    }

    char title[BUFFER_SIZE];
    printf("Enter the title of the song to delete: ");
    fgets(title, BUFFER_SIZE, stdin);
    title[strcspn(title, "\n")] = '\0';  // Remove newline

    for (int i = 0; i < *count; i++) {
        if (strcmp(library[i].title, title) == 0) {
            // Shift songs down to fill the gap
            for (int j = i; j < *count - 1; j++) {
                library[j] = library[j + 1];
            }
            (*count)--;
            printf("Song deleted successfully!\n");
            return;
        }
    }
    printf("Song not found in the library.\n");
}

void displaySongs(const Song *library, int count) {
    if (count == 0) {
        printf("No songs in the library.\n");
        return;
    }

    printf("\n=== List of Songs in Library ===\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s, Artist: %s, Album: %s, Year: %d\n", 
                library[i].title, 
                library[i].artist, 
                library[i].album, 
                library[i].year);
    }
}

void flushInput() {
    // Clear the input buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}