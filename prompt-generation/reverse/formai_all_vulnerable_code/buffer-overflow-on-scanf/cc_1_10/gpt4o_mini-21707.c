//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define MAX_LENGTH 256

typedef struct {
    char title[MAX_LENGTH];
    char artist[MAX_LENGTH];
    char album[MAX_LENGTH];
    int year;
} Song;

Song library[MAX_SONGS];
int song_count = 0;

// Function prototypes
int addSong();
void listSongs();
void searchSong();
void deleteSong();
void paranoidSafetyCheck();

int main() {
    int choice;
    printf("=== Welcome to the Paranoid Music Library Management System ===\n");
    
    while (1) {
        printf("\n1. Add Song\n2. List Songs\n3. Search Song\n4. Delete Song\n5. Safety Check\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume leftover newline

        switch (choice) {
            case 1: 
                addSong(); 
                break;
            case 2: 
                listSongs(); 
                break;
            case 3: 
                searchSong(); 
                break;
            case 4: 
                deleteSong(); 
                break;
            case 5:
                paranoidSafetyCheck();
                break;
            case 6:
                printf("Exiting the system. Stay safe!\n");
                exit(0);
            default: 
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

int addSong() {
    if (song_count >= MAX_SONGS) {
        printf("Library is full! Unable to add more songs.\n");
        return -1;
    }

    printf("Enter song title: ");
    fgets(library[song_count].title, MAX_LENGTH, stdin);
    library[song_count].title[strcspn(library[song_count].title, "\n")] = 0; // Remove newline

    printf("Enter artist name: ");
    fgets(library[song_count].artist, MAX_LENGTH, stdin);
    library[song_count].artist[strcspn(library[song_count].artist, "\n")] = 0; // Remove newline

    printf("Enter album name: ");
    fgets(library[song_count].album, MAX_LENGTH, stdin);
    library[song_count].album[strcspn(library[song_count].album, "\n")] = 0; // Remove newline

    printf("Enter release year: ");
    scanf("%d", &library[song_count].year);
    getchar(); // consume leftover newline

    song_count++;
    printf("Song added successfully!\n");
    return 0;
}

void listSongs() {
    if (song_count == 0) {
        printf("No songs in the library.\n");
        return;
    }

    printf("=== Music Library ===\n");
    for (int i = 0; i < song_count; i++) {
        printf("%d. Title: %s | Artist: %s | Album: %s | Year: %d\n", 
               i+1, library[i].title, library[i].artist, library[i].album, library[i].year);
    }
}

void searchSong() {
    char title[MAX_LENGTH];
    printf("Enter the title of the song you want to search: ");
    fgets(title, MAX_LENGTH, stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline

    for (int i = 0; i < song_count; i++) {
        if (strcmp(library[i].title, title) == 0) {
            printf("Song found: %s | Artist: %s | Album: %s | Year: %d\n", 
                   library[i].title, library[i].artist, library[i].album, library[i].year);
            return;
        }
    }
    printf("Song not found in the library.\n");
}

void deleteSong() {
    int index;
    printf("Enter song number to delete: ");
    scanf("%d", &index);
    getchar(); // consume leftover newline

    if (index < 1 || index > song_count) {
        printf("Invalid song number!\n");
        return;
    }

    for (int i = index - 1; i < song_count - 1; i++) {
        library[i] = library[i + 1]; // Shift songs left
    }
    song_count--;
    printf("Song deleted successfully!\n");
}

void paranoidSafetyCheck() {
    printf("=== Performing Paranoid Safety Check ===\n");
    if (song_count < 0) {
        printf("Warning! Negative song count detected! Potential data corruption!\n");
    } else {
        printf("Library is safe. Total songs: %d\n", song_count);
    }
}