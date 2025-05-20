//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: creative
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
} Track;

Track musicLibrary[MAX_TRACKS];
int trackCount = 0;

// Function prototypes
void addTrack();
void deleteTrack();
void listTracks();
void searchTrack();
void menu();

int main() {
    while (1) {
        menu();
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: addTrack(); break;
            case 2: deleteTrack(); break;
            case 3: listTracks(); break;
            case 4: searchTrack(); break;
            case 5: 
                printf("Exiting Music Library Management System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void menu() {
    printf("\n--- Music Library Management System ---\n");
    printf("1. Add Track\n");
    printf("2. Delete Track\n");
    printf("3. List Tracks\n");
    printf("4. Search Track\n");
    printf("5. Exit\n");
}

void addTrack() {
    if (trackCount >= MAX_TRACKS) {
        printf("Music library is full! Cannot add more tracks.\n");
        return;
    }
    
    Track newTrack;
    printf("Enter track title: ");
    getchar(); // Clear newline from input buffer
    fgets(newTrack.title, TITLE_LENGTH, stdin);
    newTrack.title[strcspn(newTrack.title, "\n")] = 0; // Remove newline character
    
    printf("Enter artist name: ");
    fgets(newTrack.artist, ARTIST_LENGTH, stdin);
    newTrack.artist[strcspn(newTrack.artist, "\n")] = 0; // Remove newline character
    
    printf("Enter duration (in seconds): ");
    scanf("%d", &newTrack.duration);
    
    musicLibrary[trackCount++] = newTrack;
    printf("Track added successfully!\n");
}

void deleteTrack() {
    if (trackCount == 0) {
        printf("No tracks to delete.\n");
        return;
    }
    
    char title[TITLE_LENGTH];
    printf("Enter track title to delete: ");
    getchar(); // Clear newline from input buffer
    fgets(title, TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline character
    
    for (int i = 0; i < trackCount; i++) {
        if (strcmp(musicLibrary[i].title, title) == 0) {
            // Shift remaining tracks
            for (int j = i; j < trackCount - 1; j++) {
                musicLibrary[j] = musicLibrary[j + 1];
            }
            trackCount--;
            printf("Track deleted successfully!\n");
            return;
        }
    }
    printf("Track not found.\n");
}

void listTracks() {
    if (trackCount == 0) {
        printf("No tracks in music library.\n");
        return;
    }
    
    printf("\n--- List of Tracks ---\n");
    for (int i = 0; i < trackCount; i++) {
        printf("Title: %s, Artist: %s, Duration: %d seconds\n",
               musicLibrary[i].title, musicLibrary[i].artist, musicLibrary[i].duration);
    }
}

void searchTrack() {
    if (trackCount == 0) {
        printf("No tracks to search.\n");
        return;
    }
    
    char title[TITLE_LENGTH];
    printf("Enter track title to search: ");
    getchar(); // Clear newline from input buffer
    fgets(title, TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline character
    
    for (int i = 0; i < trackCount; i++) {
        if (strcmp(musicLibrary[i].title, title) == 0) {
            printf("Track found: Title: %s, Artist: %s, Duration: %d seconds\n",
                   musicLibrary[i].title, musicLibrary[i].artist, musicLibrary[i].duration);
            return;
        }
    }
    printf("Track not found.\n");
}