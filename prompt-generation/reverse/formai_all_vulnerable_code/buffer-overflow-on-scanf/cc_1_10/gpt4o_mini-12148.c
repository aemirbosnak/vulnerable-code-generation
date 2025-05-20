//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRACKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_ARTIST_LENGTH 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    int year;
} Track;

Track musicLibrary[MAX_TRACKS];
int trackCount = 0;

void addTrack() {
    if (trackCount >= MAX_TRACKS) {
        printf("Music library is full!\n");
        return;
    }
    Track newTrack;
    printf("Enter track title: ");
    fgets(newTrack.title, MAX_TITLE_LENGTH, stdin);
    newTrack.title[strcspn(newTrack.title, "\n")] = 0;  // Remove newline character
    printf("Enter artist: ");
    fgets(newTrack.artist, MAX_ARTIST_LENGTH, stdin);
    newTrack.artist[strcspn(newTrack.artist, "\n")] = 0;
    printf("Enter year: ");
    scanf("%d", &newTrack.year);
    getchar();  // Clear newline character from input buffer

    musicLibrary[trackCount++] = newTrack;
    printf("Track added successfully!\n");
}

void viewTracks() {
    if (trackCount == 0) {
        printf("No tracks in the library.\n");
        return;
    }
    printf("\nMusic Library:\n");
    for (int i = 0; i < trackCount; i++) {
        printf("%d: %s by %s (%d)\n", i + 1, musicLibrary[i].title, musicLibrary[i].artist, musicLibrary[i].year);
    }
}

void searchTrack() {
    char query[MAX_TITLE_LENGTH];
    printf("Enter track title or artist to search: ");
    fgets(query, MAX_TITLE_LENGTH, stdin);
    query[strcspn(query, "\n")] = 0;  // Remove newline character

    printf("\nSearch Results:\n");
    for (int i = 0; i < trackCount; i++) {
        if (strstr(musicLibrary[i].title, query) || strstr(musicLibrary[i].artist, query)) {
            printf("%d: %s by %s (%d)\n", i + 1, musicLibrary[i].title, musicLibrary[i].artist, musicLibrary[i].year);
        }
    }
}

void deleteTrack() {
    int index;
    viewTracks();
    if (trackCount == 0) return;

    printf("Enter the track number to delete: ");
    scanf("%d", &index);
    getchar();  // Clear newline character from input buffer

    if (index < 1 || index > trackCount) {
        printf("Invalid track number.\n");
    } else {
        for (int i = index - 1; i < trackCount - 1; i++) {
            musicLibrary[i] = musicLibrary[i + 1];
        }
        trackCount--;
        printf("Track deleted successfully!\n");
    }
}

void displayMenu() {
    printf("\nMusic Library Management System\n");
    printf("1. Add Track\n");
    printf("2. View Tracks\n");
    printf("3. Search Track\n");
    printf("4. Delete Track\n");
    printf("5. Exit\n");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar();  // Clear newline character from input buffer

        switch (choice) {
            case 1:
                addTrack();
                break;
            case 2:
                viewTracks();
                break;
            case 3:
                searchTrack();
                break;
            case 4:
                deleteTrack();
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}