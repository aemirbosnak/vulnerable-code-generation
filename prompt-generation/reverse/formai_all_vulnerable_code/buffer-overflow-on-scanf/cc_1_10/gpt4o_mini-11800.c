//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRACKS 100
#define TITLE_LENGTH 100
#define ARTIST_LENGTH 50

typedef struct {
    char title[TITLE_LENGTH];
    char artist[ARTIST_LENGTH];
    int duration; // duration in seconds
} Track;

void addTrack();
void displayTracks();
void searchTrack();

int main() {
    int choice;
    
    while (1) {
        printf("\nMusic Library Management System\n");
        printf("1. Add Track\n");
        printf("2. Display Tracks\n");
        printf("3. Search Track\n");
        printf("4. Exit\n");
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
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}

void addTrack() {
    Track newTrack;
    FILE *file = fopen("music_library.txt", "a");
    if (file == NULL) {
        printf("Could not open file!\n");
        return;
    }
    
    printf("Enter track title: ");
    getchar(); // To consume the newline left by previous input
    fgets(newTrack.title, TITLE_LENGTH, stdin);
    newTrack.title[strcspn(newTrack.title, "\n")] = 0; // Remove newline character

    printf("Enter artist name: ");
    fgets(newTrack.artist, ARTIST_LENGTH, stdin);
    newTrack.artist[strcspn(newTrack.artist, "\n")] = 0; // Remove newline character

    printf("Enter track duration (in seconds): ");
    scanf("%d", &newTrack.duration);
    
    fwrite(&newTrack, sizeof(Track), 1, file);
    fclose(file);
    
    printf("Track added successfully!\n");
}

void displayTracks() {
    Track track;
    FILE *file = fopen("music_library.txt", "r");
    if (file == NULL) {
        printf("Could not open file!\n");
        return;
    }
    
    printf("\nList of tracks:\n");
    printf("%-30s %-20s %-10s\n", "Title", "Artist", "Duration");
    printf("-----------------------------------------------------------\n");
    
    while (fread(&track, sizeof(Track), 1, file)) {
        printf("%-30s %-20s %-10d\n", track.title, track.artist, track.duration);
    }
    fclose(file);
}

void searchTrack() {
    char searchTitle[TITLE_LENGTH];
    Track track;
    int found = 0;
    
    printf("Enter track title to search: ");
    getchar(); // To consume newline character
    fgets(searchTitle, TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // Remove newline character
    
    FILE *file = fopen("music_library.txt", "r");
    if (file == NULL) {
        printf("Could not open file!\n");
        return;
    }
    
    while (fread(&track, sizeof(Track), 1, file)) {
        if (strcasecmp(track.title, searchTitle) == 0) {
            printf("Track found!\n");
            printf("Title: %s\n", track.title);
            printf("Artist: %s\n", track.artist);
            printf("Duration: %d seconds\n", track.duration);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Track not found in the library.\n");
    }
    
    fclose(file);
}