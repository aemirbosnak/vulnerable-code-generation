//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRACKS 100
#define MAX_TITLE 100
#define MAX_ARTIST 100

typedef struct {
    char title[MAX_TITLE];
    char artist[MAX_ARTIST];
    int duration; // duration in seconds
} MusicTrack;

typedef struct {
    MusicTrack tracks[MAX_TRACKS];
    int count;
} MusicLibrary;

void initializeLibrary(MusicLibrary *library) {
    library->count = 0;
}

void addTrack(MusicLibrary *library, const char *title, const char *artist, int duration) {
    if (library->count < MAX_TRACKS) {
        strncpy(library->tracks[library->count].title, title, MAX_TITLE);
        strncpy(library->tracks[library->count].artist, artist, MAX_ARTIST);
        library->tracks[library->count].duration = duration;
        library->count++;
        printf("\"%s\" by %s added to the library.\n", title, artist);
    } else {
        printf("The library is full, cannot add more tracks.\n");
    }
}

void displayTracks(const MusicLibrary *library) {
    if (library->count == 0) {
        printf("The music library is currently empty.\n");
        return;
    }
    printf("\n*** Music Library ***\n");
    for (int i = 0; i < library->count; i++) {
        printf("Track %d: \"%s\" by %s (%d seconds)\n", i + 1, library->tracks[i].title, library->tracks[i].artist, library->tracks[i].duration);
    }
}

void searchTrack(const MusicLibrary *library, const char *title) {
    printf("Searching for track: \"%s\"...\n", title);
    for (int i = 0; i < library->count; i++) {
        if (strcasecmp(library->tracks[i].title, title) == 0) {
            printf("Track found: \"%s\" by %s (%d seconds)\n", library->tracks[i].title, library->tracks[i].artist, library->tracks[i].duration);
            return;
        }
    }
    printf("Track \"%s\" not found in the library.\n", title);
}

void removeTrack(MusicLibrary *library, const char *title) {
    int found = 0;
    for (int i = 0; i < library->count; i++) {
        if (strcasecmp(library->tracks[i].title, title) == 0) {
            found = 1;
            for (int j = i; j < library->count - 1; j++) {
                library->tracks[j] = library->tracks[j + 1]; // Shift the tracks left
            }
            library->count--;
            printf("Track \"%s\" has been removed from the library.\n", title);
            break;
        }
    }
    if (!found) {
        printf("Track \"%s\" was not found, thus could not be removed from the library.\n", title);
    }
}

int main() {
    MusicLibrary library;
    initializeLibrary(&library);
    int choice;
    char title[MAX_TITLE], artist[MAX_ARTIST];
    int duration;

    do {
        printf("\n*** Sherlock's Music Library Management System ***\n");
        printf("1. Add Track\n");
        printf("2. Display Tracks\n");
        printf("3. Search Track\n");
        printf("4. Remove Track\n");
        printf("5. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter track title: ");
                getchar(); // Clear the newline character left by previous input
                fgets(title, MAX_TITLE, stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline character

                printf("Enter artist name: ");
                fgets(artist, MAX_ARTIST, stdin);
                artist[strcspn(artist, "\n")] = 0;

                printf("Enter duration (in seconds): ");
                scanf("%d", &duration);
                
                addTrack(&library, title, artist, duration);
                break;

            case 2:
                displayTracks(&library);
                break;

            case 3:
                printf("Enter track title to search: ");
                getchar();
                fgets(title, MAX_TITLE, stdin);
                title[strcspn(title, "\n")] = 0;
                searchTrack(&library, title);
                break;

            case 4:
                printf("Enter track title to remove: ");
                getchar();
                fgets(title, MAX_TITLE, stdin);
                title[strcspn(title, "\n")] = 0;
                removeTrack(&library, title);
                break;

            case 5:
                printf("Exiting the music library system. Farewell!\n");
                break;

            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    } while (choice != 5);
    
    return 0;
}