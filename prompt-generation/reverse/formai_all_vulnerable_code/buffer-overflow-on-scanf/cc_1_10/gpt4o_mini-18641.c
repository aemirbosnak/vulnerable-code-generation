//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: enthusiastic
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
} MusicTrack;

MusicTrack library[MAX_TRACKS];
int trackCount = 0;

// Function to add a new track
void addTrack() {
    if (trackCount < MAX_TRACKS) {
        printf("Enter track title: ");
        getchar(); // Clear newline character from input buffer
        fgets(library[trackCount].title, sizeof(library[trackCount].title), stdin);
        library[trackCount].title[strcspn(library[trackCount].title, "\n")] = 0; // Remove newline

        printf("Enter track artist: ");
        fgets(library[trackCount].artist, sizeof(library[trackCount].artist), stdin);
        library[trackCount].artist[strcspn(library[trackCount].artist, "\n")] = 0; // Remove newline

        printf("Enter track duration (in seconds): ");
        scanf("%d", &library[trackCount].duration);

        trackCount++;
        printf("Track added successfully!\n");
    } else {
        printf("Library is full! Cannot add more tracks.\n");
    }
}

// Function to display all tracks
void displayTracks() {
    if (trackCount == 0) {
        printf("No tracks available in the library.\n");
        return;
    }
    
    printf("Music Library:\n");
    for (int i = 0; i < trackCount; i++) {
        printf("Track %d:\n", i + 1);
        printf("  Title: %s\n", library[i].title);
        printf("  Artist: %s\n", library[i].artist);
        printf("  Duration: %d seconds\n", library[i].duration);
    }
}

// Function to search for a track by title
void searchTrack() {
    char searchTitle[MAX_TITLE_LENGTH];
    printf("Enter track title to search: ");
    getchar(); // Clear newline character
    fgets(searchTitle, sizeof(searchTitle), stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // Remove newline

    for (int i = 0; i < trackCount; i++) {
        if (strcmp(library[i].title, searchTitle) == 0) {
            printf("Track found!\n");
            printf("Title: %s\n", library[i].title);
            printf("Artist: %s\n", library[i].artist);
            printf("Duration: %d seconds\n", library[i].duration);
            return;
        }
    }
    printf("Track not found in the library.\n");
}

// Function to delete a track
void deleteTrack() {
    char deleteTitle[MAX_TITLE_LENGTH];
    printf("Enter track title to delete: ");
    getchar(); // Clear newline character
    fgets(deleteTitle, sizeof(deleteTitle), stdin);
    deleteTitle[strcspn(deleteTitle, "\n")] = 0; // Remove newline

    for (int i = 0; i < trackCount; i++) {
        if (strcmp(library[i].title, deleteTitle) == 0) {
            for (int j = i; j < trackCount - 1; j++) {
                library[j] = library[j + 1];
            }
            trackCount--;
            printf("Track deleted successfully!\n");
            return;
        }
    }
    printf("Track not found. Unable to delete.\n");
}

// Display menu and handle user choices
void displayMenu() {
    int choice;
    do {
        printf("\n--- Music Library Management System ---\n");
        printf("1. Add Track\n");
        printf("2. Display Tracks\n");
        printf("3. Search Track\n");
        printf("4. Delete Track\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTrack();
                break;
            case 2:
                displayTracks();
                break;
            case 3:
                searchTrack();
                break;
            case 4:
                deleteTrack();
                break;
            case 5:
                printf("Exiting the program. Thank you!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
}

int main() {
    displayMenu();
    return 0;
}