//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define TITLE_LENGTH 50
#define ARTIST_LENGTH 50

// Structure to hold song information
typedef struct {
    char title[TITLE_LENGTH];
    char artist[ARTIST_LENGTH];
} Song;

// Function declarations
void addSong(Song *library, int *count);
void viewSongs(Song *library, int count);
void deleteSong(Song *library, int *count);

int main() {
    Song library[MAX_SONGS];
    int songCount = 0;
    int choice = 0;

    printf("🎶 Welcome to the Music Library Management System! 🎶\n");

    while (1) {
        printf("\n🎵 Choose an option: 🎵\n");
        printf("1. Add a new song\n");
        printf("2. View all songs\n");
        printf("3. Delete a song\n");
        printf("4. Exit the program\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        getchar(); // flush the newline character from input buffer

        switch (choice) {
            case 1:
                if (songCount < MAX_SONGS) {
                    addSong(library, &songCount);
                } else {
                    printf("❌ Library is full! Cannot add more songs.\n");
                }
                break;
            case 2:
                viewSongs(library, songCount);
                break;
            case 3:
                deleteSong(library, &songCount);
                break;
            case 4:
                printf("📅 Thank you for using the Music Library Management System! Goodbye! 👋\n");
                return 0;
            default:
                printf("🚫 Invalid option! Please choose a valid option.\n");
        }
    }
    return 0;
}

void addSong(Song *library, int *count) {
    printf("📀 Enter Song Title: ");
    fgets(library[*count].title, TITLE_LENGTH, stdin);
    library[*count].title[strcspn(library[*count].title, "\n")] = 0; // Remove newline character

    printf("🎤 Enter Artist: ");
    fgets(library[*count].artist, ARTIST_LENGTH, stdin);
    library[*count].artist[strcspn(library[*count].artist, "\n")] = 0; // Remove newline character

    (*count)++;
    printf("✅ Song added: '%s' by %s!\n", library[*count - 1].title, library[*count - 1].artist);
}

void viewSongs(Song *library, int count) {
    if (count == 0) {
        printf("🎶 No songs in the library yet! Add some songs to get started! 🎶\n");
        return;
    }

    printf("\n🎵 Your Music Library: 🎵\n");
    for (int i = 0; i < count; i++) {
        printf("%d. '%s' by %s\n", i + 1, library[i].title, library[i].artist);
    }
}

void deleteSong(Song *library, int *count) {
    if (*count == 0) {
        printf("❌ No songs to delete! Add some songs first! 🎤\n");
        return;
    }

    int index;
    viewSongs(library, *count);
    printf("📉 Enter the number of the song you want to delete: ");
    scanf("%d", &index);
    getchar(); // flush newline

    if (index < 1 || index > *count) {
        printf("🚫 Invalid song number! No song deleted.\n");
    } else {
        index--; // Adjusting for 0-based index
        printf("🗑️ Deleting song: '%s' by %s...\n", library[index].title, library[index].artist);
        for (int i = index; i < *count - 1; i++) {
            library[i] = library[i + 1]; // Shift songs left
        }
        (*count)--; // Decrease the count of songs
        printf("✅ Song deleted successfully!\n");
    }
}