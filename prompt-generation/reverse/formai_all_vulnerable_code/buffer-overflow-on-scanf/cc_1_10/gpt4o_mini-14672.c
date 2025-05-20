//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRACKS 100
#define TITLE_LENGTH 100
#define ARTIST_LENGTH 100

typedef struct {
    char title[TITLE_LENGTH];
    char artist[ARTIST_LENGTH];
    int duration; // in seconds
} MusicTrack;

MusicTrack library[MAX_TRACKS];
int trackCount = 0;

void addTrack() {
    if (trackCount >= MAX_TRACKS) {
        printf("Library is full, cannot add more tracks.\n");
        return;
    }
    
    MusicTrack newTrack;
    printf("Enter track title: ");
    getchar(); // consume leftover newline
    fgets(newTrack.title, TITLE_LENGTH, stdin);
    newTrack.title[strcspn(newTrack.title, "\n")] = 0; // remove newline

    printf("Enter artist name: ");
    fgets(newTrack.artist, ARTIST_LENGTH, stdin);
    newTrack.artist[strcspn(newTrack.artist, "\n")] = 0; // remove newline

    printf("Enter duration in seconds: ");
    scanf("%d", &newTrack.duration);
    
    library[trackCount++] = newTrack;
    printf("Track added successfully!\n");
}

void displayTracks() {
    if (trackCount == 0) {
        printf("No tracks in the library.\n");
        return;
    }
    
    printf("Music Library:\n");
    for (int i = 0; i < trackCount; i++) {
        printf("Track %d: %s by %s, Duration: %d seconds\n", 
               i + 1, library[i].title, library[i].artist, library[i].duration);
    }
}

void searchTrack() {
    char searchTitle[TITLE_LENGTH];
    printf("Enter track title to search for: ");
    getchar(); // consume leftover newline
    fgets(searchTitle, TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // remove newline
    
    int found = 0;
    for (int i = 0; i < trackCount; i++) {
        if (strcasecmp(library[i].title, searchTitle) == 0) {
            printf("Found: %s by %s, Duration: %d seconds\n", 
                   library[i].title, library[i].artist, library[i].duration);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Track not found in the library.\n");
    }
}

void deleteTrack() {
    char deleteTitle[TITLE_LENGTH];
    printf("Enter track title to delete: ");
    getchar(); // consume leftover newline
    fgets(deleteTitle, TITLE_LENGTH, stdin);
    deleteTitle[strcspn(deleteTitle, "\n")] = 0; // remove newline
    
    int found = 0;
    for (int i = 0; i < trackCount; i++) {
        if (strcasecmp(library[i].title, deleteTitle) == 0) {
            for (int j = i; j < trackCount - 1; j++) {
                library[j] = library[j + 1]; // shift left
            }
            trackCount--;
            printf("Track deleted successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Track not found. Unable to delete.\n");
    }
}

int main() {
    int choice;
    
    do {
        printf("\n--- Music Library Management System ---\n");
        printf("1. Add Track\n");
        printf("2. Display Tracks\n");
        printf("3. Search Track\n");
        printf("4. Delete Track\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
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
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);

    return 0;
}