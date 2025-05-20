//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRACKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_ARTIST_LENGTH 100
#define FILENAME "music_library.txt"

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    int duration; // in seconds
} Track;

void addTrack();
void removeTrack();
void displayTracks();
void searchTrack();
void loadTracks();
void saveTrack(const Track *track);
int findTrackIndex(const char *title);
void clearScreen();

int main() {
    int choice;

    loadTracks();

    while (1) {
        clearScreen();
        printf("Music Library Management System\n");
        printf("1. Add Track\n");
        printf("2. Remove Track\n");
        printf("3. Display Tracks\n");
        printf("4. Search Track\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline

        switch (choice) {
            case 1:
                addTrack();
                break;
            case 2:
                removeTrack();
                break;
            case 3:
                displayTracks();
                break;
            case 4:
                searchTrack();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}

void addTrack() {
    Track track;
    printf("Enter track title: ");
    fgets(track.title, MAX_TITLE_LENGTH, stdin);
    track.title[strcspn(track.title, "\n")] = 0; // Remove newline

    printf("Enter artist name: ");
    fgets(track.artist, MAX_ARTIST_LENGTH, stdin);
    track.artist[strcspn(track.artist, "\n")] = 0; // Remove newline

    printf("Enter track duration (in seconds): ");
    scanf("%d", &track.duration);
    getchar(); // Consume the newline

    saveTrack(&track);
    printf("Track added successfully!\n");
    getchar(); // Wait for user input
}

void removeTrack() {
    char title[MAX_TITLE_LENGTH];
    printf("Enter track title to remove: ");
    fgets(title, MAX_TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline

    int index = findTrackIndex(title);
    if (index == -1) {
        printf("Track not found.\n");
    } else {
        FILE *file = fopen(FILENAME, "r");
        FILE *tempFile = fopen("temp.txt", "w");
        Track track;

        while (fread(&track, sizeof(Track), 1, file)) {
            if (strcmp(track.title, title) != 0) {
                fwrite(&track, sizeof(Track), 1, tempFile);
            }
        }

        fclose(file);
        fclose(tempFile);

        remove(FILENAME);
        rename("temp.txt", FILENAME);
        printf("Track removed successfully!\n");
    }
    getchar(); // Wait for user input
}

void displayTracks() {
    FILE *file = fopen(FILENAME, "r");
    Track track;

    printf("\nMusic Library:\n");
    while (fread(&track, sizeof(Track), 1, file)) {
        printf("Title: %s, Artist: %s, Duration: %d seconds\n", track.title, track.artist, track.duration);
    }

    fclose(file);
    getchar(); // Wait for user input
}

void searchTrack() {
    char title[MAX_TITLE_LENGTH];
    printf("Enter track title to search: ");
    fgets(title, MAX_TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline

    int index = findTrackIndex(title);
    if (index == -1) {
        printf("Track not found.\n");
    } else {
        printf("Track \"%s\" found at index %d.\n", title, index);
    }
    getchar(); // Wait for user input
}

void loadTracks() {
    FILE *file = fopen(FILENAME, "a+");
    fclose(file); // Just create the file if it doesn't exist
}

void saveTrack(const Track *track) {
    FILE *file = fopen(FILENAME, "a");
    fwrite(track, sizeof(Track), 1, file);
    fclose(file);
}

int findTrackIndex(const char *title) {
    FILE *file = fopen(FILENAME, "r");
    if (!file) return -1;

    Track track;
    int index = 0;

    while (fread(&track, sizeof(Track), 1, file)) {
        if (strcmp(track.title, title) == 0) {
            fclose(file);
            return index;
        }
        index++;
    }

    fclose(file);
    return -1; // Not found
}

void clearScreen() {
    printf("\033[H\033[J");
}