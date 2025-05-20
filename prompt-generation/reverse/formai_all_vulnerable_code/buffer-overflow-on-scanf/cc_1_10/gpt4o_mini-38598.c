//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRACKS 100
#define TRACK_NAME_LENGTH 100
#define ARTIST_NAME_LENGTH 100
#define FILENAME "music_library.txt"

typedef struct {
    char trackName[TRACK_NAME_LENGTH];
    char artistName[ARTIST_NAME_LENGTH];
    int duration;  // duration in seconds
} Track;

int trackCount = 0;
Track musicLibrary[MAX_TRACKS];

void loadMusicLibrary() {
    FILE *file = fopen(FILENAME, "rb");
    if (file) {
        trackCount = fread(musicLibrary, sizeof(Track), MAX_TRACKS, file);
        fclose(file);
    }
}

void saveMusicLibrary() {
    FILE *file = fopen(FILENAME, "wb");
    if (file) {
        fwrite(musicLibrary, sizeof(Track), trackCount, file);
        fclose(file);
    }
}

void addTrack() {
    if (trackCount >= MAX_TRACKS) {
        printf("Music library is full!\n");
        return;
    }

    Track newTrack;
    printf("Enter track name: ");
    getchar();  // To consume the newline character from previous input
    fgets(newTrack.trackName, TRACK_NAME_LENGTH, stdin);
    strtok(newTrack.trackName, "\n");  // Remove newline character

    printf("Enter artist name: ");
    fgets(newTrack.artistName, ARTIST_NAME_LENGTH, stdin);
    strtok(newTrack.artistName, "\n");  // Remove newline character

    printf("Enter duration in seconds: ");
    scanf("%d", &newTrack.duration);
    
    musicLibrary[trackCount++] = newTrack;
    saveMusicLibrary();
    printf("Track added successfully!\n");
}

void viewTracks() {
    if (trackCount == 0) {
        printf("No tracks available.\n");
        return;
    }
    printf("Music Library:\n");
    for (int i = 0; i < trackCount; i++) {
        printf("Track %d: %s by %s [%d seconds]\n", 
                i + 1, 
                musicLibrary[i].trackName, 
                musicLibrary[i].artistName, 
                musicLibrary[i].duration);
    }
}

void deleteTrack() {
    if (trackCount == 0) {
        printf("No tracks available to delete.\n");
        return;
    }

    int trackNumber;
    printf("Enter track number to delete (1 to %d): ", trackCount);
    scanf("%d", &trackNumber);

    if (trackNumber < 1 || trackNumber > trackCount) {
        printf("Invalid track number!\n");
        return;
    }

    for (int i = trackNumber - 1; i < trackCount - 1; i++) {
        musicLibrary[i] = musicLibrary[i + 1];
    }
    trackCount--;
    saveMusicLibrary();
    printf("Track deleted successfully!\n");
}

void displayMenu() {
    printf("\n=== Music Library Management System ===\n");
    printf("1. Add Track\n");
    printf("2. View Tracks\n");
    printf("3. Delete Track\n");
    printf("4. Exit\n");
    printf("Select an option: ");
}

int main() {
    loadMusicLibrary();

    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addTrack();
                break;
            case 2:
                viewTracks();
                break;
            case 3:
                deleteTrack();
                break;
            case 4:
                printf("Exiting the Music Library Management System. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}