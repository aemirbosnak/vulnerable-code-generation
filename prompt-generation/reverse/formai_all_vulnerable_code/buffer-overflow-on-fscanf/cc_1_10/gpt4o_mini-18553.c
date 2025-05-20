//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_ARTIST_LENGTH 100
#define MAX_PLAYLIST_SIZE 1000
#define FILENAME "playlist.txt"

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    int duration; // duration in seconds
} Track;

void addTrack();
void viewPlaylist();
void deleteTrack();
void displayMenu();
void clearInputBuffer();

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1:
                addTrack();
                break;
            case 2:
                viewPlaylist();
                break;
            case 3:
                deleteTrack();
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    }

    return 0;
}

void addTrack() {
    Track newTrack;
    FILE *file = fopen(FILENAME, "a");

    if (!file) {
        perror("Unable to open file");
        return;
    }

    printf("Enter track title: ");
    fgets(newTrack.title, MAX_TITLE_LENGTH, stdin);
    newTrack.title[strcspn(newTrack.title, "\n")] = 0; // Remove newline character

    printf("Enter artist name: ");
    fgets(newTrack.artist, MAX_ARTIST_LENGTH, stdin);
    newTrack.artist[strcspn(newTrack.artist, "\n")] = 0; // Remove newline character

    printf("Enter track duration (in seconds): ");
    scanf("%d", &newTrack.duration);
    clearInputBuffer();

    fprintf(file, "%s;%s;%d\n", newTrack.title, newTrack.artist, newTrack.duration);
    fclose(file);
    printf("Track added to the playlist.\n");
}

void viewPlaylist() {
    FILE *file = fopen(FILENAME, "r");
    Track track;

    if (!file) {
        perror("Unable to open file");
        return;
    }

    printf("\nPlaylist:\n");
    printf("------------------------------------------------\n");
    while (fscanf(file, "%[^;];%[^;];%d\n", track.title, track.artist, &track.duration) != EOF) {
        printf("Title: %s | Artist: %s | Duration: %d seconds\n", track.title, track.artist, track.duration);
    }
    printf("------------------------------------------------\n");
    fclose(file);
}

void deleteTrack() {
    FILE *file = fopen(FILENAME, "r");
    FILE *tempFile = fopen("temp.txt", "w");
    Track track;
    char titleToDelete[MAX_TITLE_LENGTH];
    int found = 0;

    if (!file || !tempFile) {
        perror("Unable to open file");
        return;
    }

    printf("Enter the title of the track to delete: ");
    fgets(titleToDelete, MAX_TITLE_LENGTH, stdin);
    titleToDelete[strcspn(titleToDelete, "\n")] = 0; // Remove newline character

    while (fscanf(file, "%[^;];%[^;];%d\n", track.title, track.artist, &track.duration) != EOF) {
        if (strcmp(track.title, titleToDelete) == 0) {
            found = 1;
            printf("Track '%s' by '%s' deleted.\n", track.title, track.artist);
            continue; // Skip writing this track to temp file
        }
        fprintf(tempFile, "%s;%s;%d\n", track.title, track.artist, track.duration);
    }

    fclose(file);
    fclose(tempFile);

    remove(FILENAME);
    rename("temp.txt", FILENAME);

    if (!found) {
        printf("Track with the title '%s' not found in the playlist.\n", titleToDelete);
    }
}

void displayMenu() {
    printf("\n=== Playlist Manager ===\n");
    printf("1. Add Track\n");
    printf("2. View Playlist\n");
    printf("3. Delete Track\n");
    printf("4. Exit\n");
}

void clearInputBuffer() {
    while (getchar() != '\n');
}