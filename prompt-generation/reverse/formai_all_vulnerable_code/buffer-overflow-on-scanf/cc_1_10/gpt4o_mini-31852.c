//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: peaceful
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

void initializeLibrary(MusicLibrary* library) {
    library->count = 0;
}

void addTrack(MusicLibrary* library) {
    if (library->count >= MAX_TRACKS) {
        printf("Library is full! Cannot add more tracks.\n");
        return;
    }
    Track newTrack;
    printf("Enter the track title: ");
    getchar(); // Clear newline from previous input
    fgets(newTrack.title, MAX_TITLE_LENGTH, stdin);
    newTrack.title[strcspn(newTrack.title, "\n")] = 0; // Remove newline
    
    printf("Enter the artist name: ");
    fgets(newTrack.artist, MAX_ARTIST_LENGTH, stdin);
    newTrack.artist[strcspn(newTrack.artist, "\n")] = 0; // Remove newline

    library->tracks[library->count] = newTrack;
    library->count++;
    printf("Track added successfully!\n");
}

void viewTracks(const MusicLibrary* library) {
    if (library->count == 0) {
        printf("Your music library is empty.\n");
        return;
    }
    printf("Your Music Library:\n");
    for (int i = 0; i < library->count; i++) {
        printf("%d. %s by %s\n", i + 1, library->tracks[i].title, library->tracks[i].artist);
    }
}

void searchTrack(const MusicLibrary* library) {
    char searchTitle[MAX_TITLE_LENGTH];
    printf("Enter the track title to search: ");
    getchar(); // Clear newline from previous input
    fgets(searchTitle, MAX_TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // Remove newline
    
    printf("Search Results:\n");
    int found = 0;
    for (int i = 0; i < library->count; i++) {
        if (strstr(library->tracks[i].title, searchTitle) != NULL) {
            printf("%d. %s by %s\n", i + 1, library->tracks[i].title, library->tracks[i].artist);
            found = 1;
        }
    }
    if (!found) {
        printf("No tracks found with that title.\n");
    }
}

void deleteTrack(MusicLibrary* library) {
    int index;
    printf("Enter the track number to delete: ");
    scanf("%d", &index);
    
    if (index < 1 || index > library->count) {
        printf("Invalid track number!\n");
        return;
    }
    for (int i = index - 1; i < library->count - 1; i++) {
        library->tracks[i] = library->tracks[i + 1];
    }
    library->count--;
    printf("Track deleted successfully!\n");
}

void displayMenu() {
    printf("\n--- Music Library Management System ---\n");
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
    while (1) {
        displayMenu();
        printf("Choose an option: ");
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
                printf("Exiting the Music Library. Have a wonderful day!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}