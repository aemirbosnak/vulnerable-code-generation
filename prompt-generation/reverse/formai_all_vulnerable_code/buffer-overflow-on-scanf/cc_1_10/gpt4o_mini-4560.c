//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRACKS 100
#define TRACK_NAME_LENGTH 100

typedef struct {
    char name[TRACK_NAME_LENGTH];
    char artist[TRACK_NAME_LENGTH];
    char album[TRACK_NAME_LENGTH];
    int year;
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
        printf("Music Library is full! Cannot add more tracks.\n");
        return;
    }

    Track newTrack;
    printf("Enter track name: ");
    fgets(newTrack.name, TRACK_NAME_LENGTH, stdin);
    newTrack.name[strcspn(newTrack.name, "\n")] = 0; // Remove newline

    printf("Enter artist name: ");
    fgets(newTrack.artist, TRACK_NAME_LENGTH, stdin);
    newTrack.artist[strcspn(newTrack.artist, "\n")] = 0; // Remove newline

    printf("Enter album name: ");
    fgets(newTrack.album, TRACK_NAME_LENGTH, stdin);
    newTrack.album[strcspn(newTrack.album, "\n")] = 0; // Remove newline

    printf("Enter release year: ");
    scanf("%d", &newTrack.year);
    getchar(); // Consume newline left by scanf

    library->tracks[library->count] = newTrack;
    library->count++;
    printf("Track \"%s\" added to the library.\n", newTrack.name);
}

void listTracks(const MusicLibrary *library) {
    if (library->count == 0) {
        printf("No tracks in the library.\n");
        return;
    }

    printf("\nMusic Library Tracks:\n");
    for (int i = 0; i < library->count; i++) {
        Track track = library->tracks[i];
        printf("%d. \"%s\" by %s (Album: %s, Year: %d)\n",
               i + 1, track.name, track.artist, track.album, track.year);
    }
}

void searchTrack(const MusicLibrary *library) {
    char query[TRACK_NAME_LENGTH];
    printf("Enter track name to search: ");
    fgets(query, TRACK_NAME_LENGTH, stdin);
    query[strcspn(query, "\n")] = 0; // Remove newline

    int found = 0;
    for (int i = 0; i < library->count; i++) {
        if (strcasecmp(library->tracks[i].name, query) == 0) {
            Track track = library->tracks[i];
            printf("Found: \"%s\" by %s (Album: %s, Year: %d)\n",
                   track.name, track.artist, track.album, track.year);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Track \"%s\" not found in the library.\n", query);
    }
}

void displayMenu() {
    printf("\n=== Music Library Management System ===\n");
    printf("1. Add Track\n");
    printf("2. List Tracks\n");
    printf("3. Search Track\n");
    printf("4. Exit\n");
    printf("Select an option: ");
}

int main() {
    MusicLibrary library;
    initializeLibrary(&library);
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // Consume newline left by scanf

        switch (choice) {
            case 1:
                addTrack(&library);
                break;
            case 2:
                listTracks(&library);
                break;
            case 3:
                searchTrack(&library);
                break;
            case 4:
                printf("Exiting the Music Library Management System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}