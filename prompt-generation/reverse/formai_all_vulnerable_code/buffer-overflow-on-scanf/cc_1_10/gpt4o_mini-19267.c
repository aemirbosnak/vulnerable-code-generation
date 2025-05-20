//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRACKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_ARTIST_LENGTH 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
} Track;

typedef struct {
    Track tracks[MAX_TRACKS];
    int count;
} MusicLibrary;

void addTrack(MusicLibrary *library) {
    if (library->count >= MAX_TRACKS) {
        printf("Library is full! Cannot add more tracks.\n");
        return;
    }

    Track newTrack;
    printf("Enter track title: ");
    scanf("%s", newTrack.title);
    printf("Enter track artist: ");
    scanf("%s", newTrack.artist);

    library->tracks[library->count] = newTrack;
    library->count++;
    printf("Track added successfully!\n");
}

void deleteTrack(MusicLibrary *library) {
    if (library->count == 0) {
        printf("No tracks to delete.\n");
        return;
    }

    char title[MAX_TITLE_LENGTH];
    printf("Enter the title of the track to delete: ");
    scanf("%s", title);

    int i;
    for (i = 0; i < library->count; i++) {
        if (strcmp(library->tracks[i].title, title) == 0) {
            // Shift the remaining tracks down
            for (int j = i; j < library->count - 1; j++) {
                library->tracks[j] = library->tracks[j + 1];
            }
            library->count--;
            printf("Track deleted successfully.\n");
            return;
        }
    }
    printf("Track not found.\n");
}

void displayTracks(MusicLibrary *library) {
    if (library->count == 0) {
        printf("No tracks to display.\n");
        return;
    }

    printf("Music Library Tracks:\n");
    for (int i = 0; i < library->count; i++) {
        printf("Title: %s, Artist: %s\n", library->tracks[i].title, library->tracks[i].artist);
    }
}

void searchTrack(MusicLibrary *library) {
    if (library->count == 0) {
        printf("No tracks in the library.\n");
        return;
    }

    char title[MAX_TITLE_LENGTH];
    printf("Enter the title of the track to search: ");
    scanf("%s", title);

    for (int i = 0; i < library->count; i++) {
        if (strcmp(library->tracks[i].title, title) == 0) {
            printf("Track found: Title: %s, Artist: %s\n", library->tracks[i].title, library->tracks[i].artist);
            return;
        }
    }
    printf("Track not found.\n");
}

void displayMenu() {
    printf("\nMusic Library Management System\n");
    printf("1. Add Track\n");
    printf("2. Delete Track\n");
    printf("3. Display Tracks\n");
    printf("4. Search Track\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

int main() {
    MusicLibrary library = {0};

    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTrack(&library);
                break;
            case 2:
                deleteTrack(&library);
                break;
            case 3:
                displayTracks(&library);
                break;
            case 4:
                searchTrack(&library);
                break;
            case 5:
                printf("Exiting Music Library Management System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}