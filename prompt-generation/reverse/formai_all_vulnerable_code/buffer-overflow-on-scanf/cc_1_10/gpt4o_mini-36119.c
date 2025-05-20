//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum number of songs
#define MAX_SONGS 100
#define MAX_TITLE 100
#define MAX_ARTIST 100

typedef struct {
    char title[MAX_TITLE];
    char artist[MAX_ARTIST];
} Song;

Song library[MAX_SONGS];
int song_count = 0;

// Function prototypes
void add_song();
void view_songs();
void delete_song();
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;
    do {
        printf("\n--- Music Library Management System ---\n");
        printf("1. Add Song\n");
        printf("2. View Songs\n");
        printf("3. Delete Song\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: add_song(); break;
            case 2: view_songs(); break;
            case 3: delete_song(); break;
            case 4: printf("Exiting... Goodbye!\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);
}

void add_song() {
    if (song_count >= MAX_SONGS) {
        printf("Library is full! Can't add more songs.\n");
        return;
    }
    Song new_song;
    printf("Enter song title: ");
    getchar();  // Clear the newline from buffer
    fgets(new_song.title, MAX_TITLE, stdin);
    new_song.title[strcspn(new_song.title, "\n")] = 0;  // Remove newline
    printf("Enter artist name: ");
    fgets(new_song.artist, MAX_ARTIST, stdin);
    new_song.artist[strcspn(new_song.artist, "\n")] = 0;  // Remove newline
    library[song_count++] = new_song;
    printf("Song added successfully!\n");
}

void view_songs() {
    if (song_count == 0) {
        printf("No songs in the library!\n");
        return;
    }
    printf("\n--- Your Music Library ---\n");
    for (int i = 0; i < song_count; i++) {
        printf("%d. Title: %s | Artist: %s\n", i + 1, library[i].title, library[i].artist);
    }
}

void delete_song() {
    if (song_count == 0) {
        printf("No songs to delete!\n");
        return;
    }
    int index;
    printf("Enter the song number to delete: ");
    scanf("%d", &index);
    if (index < 1 || index > song_count) {
        printf("Invalid song number!\n");
        return;
    }
    for (int i = index - 1; i < song_count - 1; i++) {
        library[i] = library[i + 1];  // Shift songs to the left
    }
    song_count--;
    printf("Song deleted successfully!\n");
}