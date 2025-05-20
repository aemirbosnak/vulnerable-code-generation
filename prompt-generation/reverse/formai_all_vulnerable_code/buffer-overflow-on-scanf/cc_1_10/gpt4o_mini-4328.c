//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRACKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_ARTIST_LENGTH 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    int duration; // Duration in seconds
} Track;

typedef struct {
    Track tracks[MAX_TRACKS];
    int count;
} MusicLibrary;

void initializeLibrary(MusicLibrary *library) {
    library->count = 0;
}

void addTrack(MusicLibrary *library) {
    if (library->count >= MAX_TRACKS) {
        printf("Music library is full. Cannot add more tracks.\n");
        return;
    }
    
    Track newTrack;
    printf("Enter track title: ");
    fgets(newTrack.title, MAX_TITLE_LENGTH, stdin);
    newTrack.title[strcspn(newTrack.title, "\n")] = 0; // Remove newline

    printf("Enter artist name: ");
    fgets(newTrack.artist, MAX_ARTIST_LENGTH, stdin);
    newTrack.artist[strcspn(newTrack.artist, "\n")] = 0; // Remove newline

    printf("Enter duration (in seconds): ");
    scanf("%d", &newTrack.duration);
    getchar(); // Consume newline character after integer input

    library->tracks[library->count++] = newTrack;
    printf("Track added successfully!\n");
}

void displayTracks(const MusicLibrary *library) {
    if (library->count == 0) {
        printf("No tracks found in the library.\n");
        return;
    }

    printf("\n--- Music Library ---\n");
    for (int i = 0; i < library->count; i++) {
        printf("Track %d: \n", i + 1);
        printf("  Title: %s\n", library->tracks[i].title);
        printf("  Artist: %s\n", library->tracks[i].artist);
        printf("  Duration: %d seconds\n", library->tracks[i].duration);
    }
    printf("---------------------\n");
}

void searchTrack(const MusicLibrary *library) {
    char searchTitle[MAX_TITLE_LENGTH];
    printf("Enter the track title to search for: ");
    fgets(searchTitle, MAX_TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0;

    int found = 0;
    for (int i = 0; i < library->count; i++) {
        if (strcasecmp(library->tracks[i].title, searchTitle) == 0) {
            printf("Track found:\n");
            printf("  Title: %s\n", library->tracks[i].title);
            printf("  Artist: %s\n", library->tracks[i].artist);
            printf("  Duration: %d seconds\n", library->tracks[i].duration);
            found = 1;
        }
    }

    if (!found) {
        printf("No track found with the title '%s'.\n", searchTitle);
    }
}

void displayMenu() {
    printf("\n--- Music Library Management System ---\n");
    printf("1. Add Track\n");
    printf("2. Display Tracks\n");
    printf("3. Search Track\n");
    printf("4. Exit\n");
    printf("Select an option (1-4): ");
}

int main() {
    MusicLibrary myLibrary;
    initializeLibrary(&myLibrary);
    
    int option;
    while (1) {
        displayMenu();
        scanf("%d", &option);
        getchar(); // Consume newline character
        switch (option) {
            case 1:
                addTrack(&myLibrary);
                break;
            case 2:
                displayTracks(&myLibrary);
                break;
            case 3:
                searchTrack(&myLibrary);
                break;
            case 4:
                printf("Exiting Music Library Management System. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option. Please select again.\n");
        }
    }
    return 0;
}