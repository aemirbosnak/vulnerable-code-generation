//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRACKS 100
#define TITLE_LENGTH 100
#define ARTIST_LENGTH 100
#define ALBUM_LENGTH 100

typedef struct {
    char title[TITLE_LENGTH];
    char artist[ARTIST_LENGTH];
    char album[ALBUM_LENGTH];
    int year;
} MusicTrack;

typedef struct {
    MusicTrack tracks[MAX_TRACKS];
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

    MusicTrack newTrack;
    printf("Enter track title: ");
    getchar(); // to consume the newline character
    fgets(newTrack.title, TITLE_LENGTH, stdin);
    newTrack.title[strcspn(newTrack.title, "\n")] = 0; // remove newline

    printf("Enter track artist: ");
    fgets(newTrack.artist, ARTIST_LENGTH, stdin);
    newTrack.artist[strcspn(newTrack.artist, "\n")] = 0;

    printf("Enter track album: ");
    fgets(newTrack.album, ALBUM_LENGTH, stdin);
    newTrack.album[strcspn(newTrack.album, "\n")] = 0;

    printf("Enter track year: ");
    scanf("%d", &newTrack.year);

    library->tracks[library->count] = newTrack;
    library->count++;
    printf("Track added successfully to the library!\n");
}

void viewTracks(const MusicLibrary *library) {
    if (library->count == 0) {
        printf("No tracks found in the library.\n");
        return;
    }

    printf("\n--- Music Library ---\n");
    for (int i = 0; i < library->count; i++) {
        MusicTrack track = library->tracks[i];
        printf("Track %d:\n", i + 1);
        printf("Title: %s\n", track.title);
        printf("Artist: %s\n", track.artist);
        printf("Album: %s\n", track.album);
        printf("Year: %d\n", track.year);
        printf("---------------------\n");
    }
}

void searchTrack(const MusicLibrary *library) {
    char searchTitle[TITLE_LENGTH];
    printf("Enter the title of the track to search: ");
    getchar(); // to consume the newline character
    fgets(searchTitle, TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // remove newline

    int found = 0;
    for (int i = 0; i < library->count; i++) {
        if (strcmp(library->tracks[i].title, searchTitle) == 0) {
            found = 1;
            MusicTrack track = library->tracks[i];
            printf("\nTrack found!\n");
            printf("Title: %s\n", track.title);
            printf("Artist: %s\n", track.artist);
            printf("Album: %s\n", track.album);
            printf("Year: %d\n", track.year);
            printf("---------------------\n");
            break;
        }
    }

    if (!found) {
        printf("Track with the title '%s' not found in the library.\n", searchTitle);
    }
}

void menu() {
    printf("\n--- Music Library Management System ---\n");
    printf("1. Add Track\n");
    printf("2. View Tracks\n");
    printf("3. Search Track\n");
    printf("4. Exit\n");
    printf("Please select an option (1-4): ");
}

int main() {
    MusicLibrary library;
    initializeLibrary(&library);
    int choice;

    while (1) {
        menu();
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
                printf("Thank you for using the Music Library Management System! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please select again.\n");
        }
    }

    return 0;
}