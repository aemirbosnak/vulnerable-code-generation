//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRACKS 100
#define TITLE_LENGTH 50
#define ARTIST_LENGTH 50
#define ALBUM_LENGTH 50

typedef struct {
    char title[TITLE_LENGTH];
    char artist[ARTIST_LENGTH];
    char album[ALBUM_LENGTH];
    int year;
} Track;

Track musicLibrary[MAX_TRACKS];
int trackCount = 0;

void addTrack() {
    if (trackCount >= MAX_TRACKS) {
        printf("Music Library is full. Cannot add more tracks.\n");
        return;
    }
    
    Track newTrack;
    printf("Enter track title: ");
    scanf(" %[^\n]s", newTrack.title);
    printf("Enter artist name: ");
    scanf(" %[^\n]s", newTrack.artist);
    printf("Enter album name: ");
    scanf(" %[^\n]s", newTrack.album);
    printf("Enter release year: ");
    scanf("%d", &newTrack.year);

    musicLibrary[trackCount] = newTrack;
    trackCount++;
    printf("Track added successfully!\n");
}

void viewAllTracks() {
    if (trackCount == 0) {
        printf("No tracks available in the library.\n");
        return;
    }

    printf("Music Library:\n");
    for (int i = 0; i < trackCount; i++) {
        printf("%d. Title: %s, Artist: %s, Album: %s, Year: %d\n", 
               i + 1, musicLibrary[i].title, musicLibrary[i].artist, musicLibrary[i].album, musicLibrary[i].year);
    }
}

void searchTrack() {
    char searchTerm[TITLE_LENGTH];
    printf("Enter track title to search: ");
    scanf(" %[^\n]s", searchTerm);

    int found = 0;
    for (int i = 0; i < trackCount; i++) {
        if (strstr(musicLibrary[i].title, searchTerm) != NULL) {
            printf("Found Track - Title: %s, Artist: %s, Album: %s, Year: %d\n", 
                   musicLibrary[i].title, musicLibrary[i].artist, musicLibrary[i].album, musicLibrary[i].year);
            found = 1;
        }
    }
    if (!found) {
        printf("No tracks found matching: %s\n", searchTerm);
    }
}

void displayMenu() {
    printf("\n=========================\n");
    printf("   Music Library Menu    \n");
    printf("=========================\n");
    printf("1. Add Track\n");
    printf("2. View All Tracks\n");
    printf("3. Search Track\n");
    printf("4. Exit\n");
    printf("=========================\n");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTrack();
                break;
            case 2:
                viewAllTracks();
                break;
            case 3:
                searchTrack();
                break;
            case 4:
                printf("Exiting Music Library Management System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please select again.\n");
        }
    }

    return 0;
}