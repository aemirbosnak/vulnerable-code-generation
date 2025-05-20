//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRACKS 100
#define TRACK_NAME_LEN 100
#define ARTIST_NAME_LEN 100

typedef struct {
    char name[TRACK_NAME_LEN];
    char artist[ARTIST_NAME_LEN];
    float duration; // in minutes
} MusicTrack;

typedef struct {
    MusicTrack tracks[MAX_TRACKS];
    int count;
} MusicLibrary;

void initializeLibrary(MusicLibrary *library);
void addTrack(MusicLibrary *library);
void displayTracks(const MusicLibrary *library);
void searchTrackByArtist(const MusicLibrary *library);

int main() {
    MusicLibrary library;
    initializeLibrary(&library);

    int choice;

    while (1) {
        printf("\n--- Music Library Management System ---\n");
        printf("1. Add Music Track\n");
        printf("2. Display All Tracks\n");
        printf("3. Search Track by Artist\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        
        scanf("%d", &choice);
        getchar(); // to consume trailing newline

        switch (choice) {
            case 1:
                addTrack(&library);
                break;
            case 2:
                displayTracks(&library);
                break;
            case 3:
                searchTrackByArtist(&library);
                break;
            case 4:
                printf("Exiting the Music Library. May your playlist be ever delightful!\n");
                exit(0);
            default:
                printf("Invalid option! Please choose again.\n");
        }
    }

    return 0;
}

void initializeLibrary(MusicLibrary *library) {
    library->count = 0;
}

void addTrack(MusicLibrary *library) {
    if (library->count >= MAX_TRACKS) {
        printf("Music Library is full! Can't add more tracks.\n");
        return;
    }

    MusicTrack track;
    printf("Enter track name: ");
    fgets(track.name, TRACK_NAME_LEN, stdin);
    track.name[strcspn(track.name, "\n")] = 0; // Removing newline character

    printf("Enter artist name: ");
    fgets(track.artist, ARTIST_NAME_LEN, stdin);
    track.artist[strcspn(track.artist, "\n")] = 0; // Removing newline character

    printf("Enter track duration (in minutes): ");
    scanf("%f", &track.duration);
    getchar(); // to consume trailing newline

    library->tracks[library->count++] = track;
    printf("Track '%s' by '%s' added to the library successfully!\n", track.name, track.artist);
}

void displayTracks(const MusicLibrary *library) {
    if (library->count == 0) {
        printf("No tracks available in the Music Library.\n");
        return;
    }

    printf("\n--- Music Tracks in the Library ---\n");
    for (int i = 0; i < library->count; i++) {
        printf("Track %d: %s | Artist: %s | Duration: %.2f minutes\n", 
               i + 1, library->tracks[i].name, library->tracks[i].artist, library->tracks[i].duration);
    }
}

void searchTrackByArtist(const MusicLibrary *library) {
    if (library->count == 0) {
        printf("No tracks available to search.\n");
        return;
    }

    char artist[ARTIST_NAME_LEN];
    printf("Enter artist name to search: ");
    fgets(artist, ARTIST_NAME_LEN, stdin);
    artist[strcspn(artist, "\n")] = 0; // Removing newline character

    int found = 0;
    printf("\n--- Search Results for Artist: %s ---\n", artist);
    for (int i = 0; i < library->count; i++) {
        if (strcasecmp(library->tracks[i].artist, artist) == 0) {
            printf("Track: %s | Duration: %.2f minutes\n", 
                   library->tracks[i].name, library->tracks[i].duration);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No tracks found by artist '%s'.\n", artist);
    }
}