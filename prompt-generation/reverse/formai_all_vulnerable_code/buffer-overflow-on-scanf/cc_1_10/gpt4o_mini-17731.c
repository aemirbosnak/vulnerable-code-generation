//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRACKS 100
#define MAX_TITLE_LEN 100
#define MAX_ARTIST_LEN 100

typedef struct {
    char title[MAX_TITLE_LEN];
    char artist[MAX_ARTIST_LEN];
    int duration; // duration in seconds
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
        printf("Library is full! Cannot add more tracks.\n");
        return;
    }
    Track track;
    printf("Enter track title: ");
    getchar(); // consume newline character
    fgets(track.title, MAX_TITLE_LEN, stdin);
    track.title[strcspn(track.title, "\n")] = 0; // remove newline character

    printf("Enter artist name: ");
    fgets(track.artist, MAX_ARTIST_LEN, stdin);
    track.artist[strcspn(track.artist, "\n")] = 0; // remove newline character

    printf("Enter track duration (in seconds): ");
    scanf("%d", &track.duration);

    library->tracks[library->count++] = track;
    printf("Track added successfully!\n");
}

void viewTracks(MusicLibrary *library) {
    if (library->count == 0) {
        printf("No tracks available in the library.\n");
        return;
    }

    printf("\nMusic Library:\n");
    for (int i = 0; i < library->count; i++) {
        printf("Track %d: Title: %s | Artist: %s | Duration: %d seconds\n", 
                i + 1, library->tracks[i].title, library->tracks[i].artist, library->tracks[i].duration);
    }
}

void searchTrack(MusicLibrary *library) {
    char searchTerm[MAX_TITLE_LEN];
    printf("Enter track title to search: ");
    getchar(); // consume newline character
    fgets(searchTerm, MAX_TITLE_LEN, stdin);
    searchTerm[strcspn(searchTerm, "\n")] = 0; // remove newline character

    printf("Search results for '%s':\n", searchTerm);
    int found = 0;
    for (int i = 0; i < library->count; i++) {
        if (strstr(library->tracks[i].title, searchTerm) != NULL) {
            printf("Track %d: Title: %s | Artist: %s | Duration: %d seconds\n", 
                    i + 1, library->tracks[i].title, library->tracks[i].artist, library->tracks[i].duration);
            found = 1;
        }
    }
    if (!found) {
        printf("No matching tracks found.\n");
    }
}

void deleteTrack(MusicLibrary *library) {
    int index;
    printf("Enter track number to delete: ");
    scanf("%d", &index);
    if (index < 1 || index > library->count) {
        printf("Invalid track number.\n");
        return;
    }
    for (int i = index - 1; i < library->count - 1; i++) {
        library->tracks[i] = library->tracks[i + 1];
    }
    library->count--;
    printf("Track deleted successfully.\n");
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
    MusicLibrary library;
    initializeLibrary(&library);
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTrack(&library);
                break;
            case 2:
                viewTracks(&library);
                break;
            case 3:
                searchTrack(&library);
                break;
            case 4:
                deleteTrack(&library);
                break;
            case 5:
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}