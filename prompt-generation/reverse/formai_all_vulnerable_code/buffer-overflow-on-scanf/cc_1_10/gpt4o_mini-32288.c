//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC 100
#define TITLE_LEN 100
#define ARTIST_LEN 100

// Structure to represent a music track
typedef struct {
    char title[TITLE_LEN];
    char artist[ARTIST_LEN];
    int year;
} MusicTrack;

// Function prototypes
void addTrack(MusicTrack *tracks, int *count);
void displayTracks(const MusicTrack *tracks, int count);
void searchByArtist(const MusicTrack *tracks, int count);
void deleteTrack(MusicTrack *tracks, int *count);
void menu();

int main() {
    MusicTrack tracks[MAX_MUSIC];
    int count = 0;
    int option;

    while (1) {
        menu();
        printf("Select an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                addTrack(tracks, &count);
                break;
            case 2:
                displayTracks(tracks, count);
                break;
            case 3:
                searchByArtist(tracks, count);
                break;
            case 4:
                deleteTrack(tracks, &count);
                break;
            case 5:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }
    }

    return 0;
}

void menu() {
    printf("\n--- Music Library Management System ---\n");
    printf("1. Add Music Track\n");
    printf("2. Display All Tracks\n");
    printf("3. Search by Artist\n");
    printf("4. Delete a Track\n");
    printf("5. Exit\n");
}

void addTrack(MusicTrack *tracks, int *count) {
    if (*count >= MAX_MUSIC) {
        printf("Library is full, cannot add more tracks.\n");
        return;
    }

    printf("Enter track title: ");
    getchar();  // Consume newline
    fgets(tracks[*count].title, TITLE_LEN, stdin);
    strtok(tracks[*count].title, "\n"); // Remove newline character

    printf("Enter artist name: ");
    fgets(tracks[*count].artist, ARTIST_LEN, stdin);
    strtok(tracks[*count].artist, "\n"); // Remove newline character

    printf("Enter release year: ");
    scanf("%d", &tracks[*count].year);

    (*count)++;
    printf("Track added successfully!\n");
}

void displayTracks(const MusicTrack *tracks, int count) {
    if (count == 0) {
        printf("No tracks to display.\n");
        return;
    }

    printf("\n--- Music Tracks ---\n");
    for (int i = 0; i < count; i++) {
        printf("Track %d: \"%s\" by %s (%d)\n", i + 1, tracks[i].title, tracks[i].artist, tracks[i].year);
    }
}

void searchByArtist(const MusicTrack *tracks, int count) {
    char artist[ARTIST_LEN];
    int found = 0;

    printf("Enter the artist name to search: ");
    getchar(); // Consume newline
    fgets(artist, ARTIST_LEN, stdin);
    strtok(artist, "\n"); // Remove newline character

    printf("\n--- Search Results ---\n");
    for (int i = 0; i < count; i++) {
        if (strcasecmp(tracks[i].artist, artist) == 0) {
            printf("Found: \"%s\" by %s (%d)\n", tracks[i].title, tracks[i].artist, tracks[i].year);
            found = 1;
        }
    }

    if (!found) {
        printf("No tracks found for artist: %s\n", artist);
    }
}

void deleteTrack(MusicTrack *tracks, int *count) {
    if (*count == 0) {
        printf("No tracks to delete.\n");
        return;
    }

    int index;
    printf("Enter the track number to delete (1 to %d): ", *count);
    scanf("%d", &index);
    
    if (index < 1 || index > *count) {
        printf("Invalid track number.\n");
        return;
    }

    for (int i = index - 1; i < *count - 1; i++) {
        tracks[i] = tracks[i + 1];
    }
    (*count)--;
    printf("Track deleted successfully!\n");
}