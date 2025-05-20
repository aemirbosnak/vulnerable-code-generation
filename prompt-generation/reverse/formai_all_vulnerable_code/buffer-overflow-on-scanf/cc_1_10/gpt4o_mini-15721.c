//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRACKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_ARTIST_LENGTH 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    int duration; // duration in seconds
} Track;

typedef struct {
    Track tracks[MAX_TRACKS];
    int count;
} MusicLibrary;

// Function declarations
void addTrack(MusicLibrary *library);
void searchTrack(MusicLibrary *library);
void deleteTrack(MusicLibrary *library);
void displayTracks(MusicLibrary *library);
void menu();

int main() {
    MusicLibrary library;
    library.count = 0;
    int choice;

    do {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addTrack(&library); break;
            case 2: searchTrack(&library); break;
            case 3: deleteTrack(&library); break;
            case 4: displayTracks(&library); break;
            case 5: printf("Exiting the program...\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void menu() {
    printf("\n--- Music Library Management System ---\n");
    printf("1. Add Track\n");
    printf("2. Search Track\n");
    printf("3. Delete Track\n");
    printf("4. Display All Tracks\n");
    printf("5. Exit\n");
}

void addTrack(MusicLibrary *library) {
    if (library->count >= MAX_TRACKS) {
        printf("Library is full! Cannot add more tracks.\n");
        return;
    }
    Track newTrack;
    printf("Enter track title: ");
    getchar(); // clear newline
    fgets(newTrack.title, MAX_TITLE_LENGTH, stdin);
    newTrack.title[strcspn(newTrack.title, "\n")] = '\0'; // remove newline
    
    printf("Enter artist name: ");
    fgets(newTrack.artist, MAX_ARTIST_LENGTH, stdin);
    newTrack.artist[strcspn(newTrack.artist, "\n")] = '\0'; // remove newline
    
    printf("Enter track duration (in seconds): ");
    scanf("%d", &newTrack.duration);
    
    library->tracks[library->count] = newTrack;
    library->count++;
    
    printf("Track added successfully!\n");
}

void searchTrack(MusicLibrary *library) {
    char searchTitle[MAX_TITLE_LENGTH];
    printf("Enter track title to search: ");
    getchar(); // clear newline
    fgets(searchTitle, MAX_TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = '\0'; // remove newline

    for (int i = 0; i < library->count; i++) {
        if (strcmp(library->tracks[i].title, searchTitle) == 0) {
            printf("Track Found: %s by %s, Duration: %d seconds\n", 
                   library->tracks[i].title, 
                   library->tracks[i].artist, 
                   library->tracks[i].duration);
            return;
        }
    }
    printf("Track not found!\n");
}

void deleteTrack(MusicLibrary *library) {
    char deleteTitle[MAX_TITLE_LENGTH];
    printf("Enter track title to delete: ");
    getchar(); // clear newline
    fgets(deleteTitle, MAX_TITLE_LENGTH, stdin);
    deleteTitle[strcspn(deleteTitle, "\n")] = '\0'; // remove newline

    for (int i = 0; i < library->count; i++) {
        if (strcmp(library->tracks[i].title, deleteTitle) == 0) {
            for (int j = i; j < library->count - 1; j++) {
                library->tracks[j] = library->tracks[j + 1];
            }
            library->count--;
            printf("Track deleted successfully!\n");
            return;
        }
    }
    printf("Track not found!\n");
}

void displayTracks(MusicLibrary *library) {
    if (library->count == 0) {
        printf("No tracks in the library.\n");
        return;
    }
    printf("\n--- Music Library ---\n");
    for (int i = 0; i < library->count; i++) {
        printf("Track %d: %s by %s, Duration: %d seconds\n", 
               i + 1, 
               library->tracks[i].title, 
               library->tracks[i].artist, 
               library->tracks[i].duration);
    }
}