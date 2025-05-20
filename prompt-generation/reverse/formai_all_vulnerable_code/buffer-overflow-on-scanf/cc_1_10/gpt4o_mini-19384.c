//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: scalable
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
} Track;

typedef struct {
    Track tracks[MAX_TRACKS];
    int track_count;
} MusicLibrary;

void initializeLibrary(MusicLibrary *library) {
    library->track_count = 0;
}

void addTrack(MusicLibrary *library) {
    if (library->track_count < MAX_TRACKS) {
        Track *t = &library->tracks[library->track_count];
        printf("Enter track title: ");
        scanf(" %[^\n]%*c", t->title);
        printf("Enter artist name: ");
        scanf(" %[^\n]%*c", t->artist);
        printf("Enter album name: ");
        scanf(" %[^\n]%*c", t->album);
        printf("Enter release year: ");
        scanf("%d", &t->year);
        library->track_count++;
        printf("Track added successfully!\n");
    } else {
        printf("Music library is full! Cannot add more tracks.\n");
    }
}

void searchTrackByTitle(MusicLibrary *library, const char *title) {
    int found = 0;
    for (int i = 0; i < library->track_count; i++) {
        if (strcasecmp(library->tracks[i].title, title) == 0) {
            printf("Track found:\n");
            printf("Title: %s\n", library->tracks[i].title);
            printf("Artist: %s\n", library->tracks[i].artist);
            printf("Album: %s\n", library->tracks[i].album);
            printf("Year: %d\n", library->tracks[i].year);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Track not found in the library.\n");
    }
}

void displayAllTracks(MusicLibrary *library) {
    if (library->track_count == 0) {
        printf("No tracks in the library.\n");
        return;
    }
    printf("Current tracks in the library:\n");
    for (int i = 0; i < library->track_count; i++) {
        printf("%d. %s by %s (Album: %s, Year: %d)\n", 
               i + 1, 
               library->tracks[i].title, 
               library->tracks[i].artist, 
               library->tracks[i].album, 
               library->tracks[i].year);
    }
}

void showMenu() {
    printf("\n--- Music Library Management System ---\n");
    printf("1. Add Track\n");
    printf("2. Search Track by Title\n");
    printf("3. Display All Tracks\n");
    printf("4. Exit\n");
    printf("Please choose an option: ");
}

int main() {
    MusicLibrary library;
    initializeLibrary(&library);
    
    while (1) {
        showMenu();
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addTrack(&library);
                break;
            case 2: {
                char title[TITLE_LENGTH];
                printf("Enter track title to search: ");
                scanf(" %[^\n]%*c", title);
                searchTrackByTitle(&library, title);
                break;
            }
            case 3:
                displayAllTracks(&library);
                break;
            case 4:
                printf("Exiting the Music Library Management System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }
    
    return 0;
}