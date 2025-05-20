//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define TITLE_LENGTH 100
#define ARTIST_LENGTH 100

typedef struct {
    char title[TITLE_LENGTH];
    char artist[ARTIST_LENGTH];
    int year;
} Song;

void addSong(Song *library, int *count);
void viewSongs(Song *library, int count);
void deleteSong(Song *library, int *count);
void searchSong(Song *library, int count);

int main() {
    Song library[MAX_SONGS];
    int songCount = 0;
    int choice;

    do {
        printf("\n--- Music Library Management System ---\n");
        printf("1. Add Song\n");
        printf("2. View Songs\n");
        printf("3. Delete Song\n");
        printf("4. Search for a Song\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline from buffer

        switch (choice) {
            case 1:
                addSong(library, &songCount);
                break;
            case 2:
                viewSongs(library, songCount);
                break;
            case 3:
                deleteSong(library, &songCount);
                break;
            case 4:
                searchSong(library, songCount);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void addSong(Song *library, int *count) {
    if (*count >= MAX_SONGS) {
        printf("Library is full! Cannot add more songs.\n");
        return;
    }
    Song newSong;
    printf("Enter song title: ");
    fgets(newSong.title, TITLE_LENGTH, stdin);
    newSong.title[strcspn(newSong.title, "\n")] = 0; // Remove newline
    printf("Enter artist name: ");
    fgets(newSong.artist, ARTIST_LENGTH, stdin);
    newSong.artist[strcspn(newSong.artist, "\n")] = 0; // Remove newline
    printf("Enter release year: ");
    scanf("%d", &newSong.year);
    getchar(); // Clear newline from buffer
    library[*count] = newSong;
    (*count)++;
    printf("Song added successfully!\n");
}

void viewSongs(Song *library, int count) {
    if (count == 0) {
        printf("No songs in the library.\n");
        return;
    }
    printf("\n--- List of Songs in the Library ---\n");
    for (int i = 0; i < count; i++) {
        printf("Song %d: %s by %s (%d)\n", i + 1, library[i].title, library[i].artist, library[i].year);
    }
}

void deleteSong(Song *library, int *count) {
    if (*count == 0) {
        printf("No songs to delete.\n");
        return;
    }
    int index;
    printf("Enter the song number to delete (1-%d): ", *count);
    scanf("%d", &index);
    getchar(); // Clear newline from buffer
    if (index < 1 || index > *count) {
        printf("Invalid song number.\n");
        return;
    }
    for (int i = index - 1; i < *count - 1; i++) {
        library[i] = library[i + 1];
    }
    (*count)--;
    printf("Song deleted successfully!\n");
}

void searchSong(Song *library, int count) {
    if (count == 0) {
        printf("No songs in the library to search.\n");
        return;
    }
    char searchTerm[TITLE_LENGTH];
    printf("Enter song title or artist to search: ");
    fgets(searchTerm, TITLE_LENGTH, stdin);
    searchTerm[strcspn(searchTerm, "\n")] = 0; // Remove newline
    int found = 0;
    printf("\n--- Search Results ---\n");
    for (int i = 0; i < count; i++) {
        if (strstr(library[i].title, searchTerm) != NULL || strstr(library[i].artist, searchTerm) != NULL) {
            printf("Found: %s by %s (%d)\n", library[i].title, library[i].artist, library[i].year);
            found = 1;
        }
    }
    if (!found) {
        printf("No songs found matching the search term.\n");
    }
}