//Falcon2-11B DATASET v1.0 Category: Music Library Management System ; Style: decentralized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Struct to represent a music track
struct Track {
    char title[50];
    char artist[50];
    int duration;
    int genre;
};

// Function to add a new track to the library
void addTrack(struct Track* tracks, int size, char* title, char* artist, int duration, int genre) {
    struct Track newTrack;
    strcpy(newTrack.title, title);
    strcpy(newTrack.artist, artist);
    newTrack.duration = duration;
    newTrack.genre = genre;
    tracks[size] = newTrack;
}

// Function to search for a track by artist
struct Track* searchArtist(struct Track* tracks, int size, char* artist) {
    for (int i = 0; i < size; i++) {
        if (strcmp(tracks[i].artist, artist) == 0) {
            return &tracks[i];
        }
    }
    return NULL;
}

// Function to search for a track by title
struct Track* searchTitle(struct Track* tracks, int size, char* title) {
    for (int i = 0; i < size; i++) {
        if (strcmp(tracks[i].title, title) == 0) {
            return &tracks[i];
        }
    }
    return NULL;
}

// Function to display the library
void displayLibrary(struct Track* tracks, int size) {
    printf("Music Library:\n");
    for (int i = 0; i < size; i++) {
        printf("Title: %s\nArtist: %s\nDuration: %d\nGenre: %d\n\n", tracks[i].title, tracks[i].artist, tracks[i].duration, tracks[i].genre);
    }
}

int main() {
    struct Track tracks[10];
    int size = 0;

    printf("Enter the number of tracks: ");
    int numTracks;
    scanf("%d", &numTracks);

    // Add tracks to the library
    for (int i = 0; i < numTracks; i++) {
        char title[50];
        char artist[50];
        int duration;
        int genre;

        printf("Enter track %d details:\n", i + 1);
        printf("Title: ");
        scanf("%s", title);
        printf("Artist: ");
        scanf("%s", artist);
        printf("Duration: ");
        scanf("%d", &duration);
        printf("Genre: ");
        scanf("%d", &genre);

        addTrack(tracks, size, title, artist, duration, genre);
    }

    // Search for a track by artist
    struct Track* track = searchArtist(tracks, size, "Bob Marley");
    if (track!= NULL) {
        printf("Track by Bob Marley found: %s\n", track->title);
    } else {
        printf("Track by Bob Marley not found.\n");
    }

    // Search for a track by title
    track = searchTitle(tracks, size, "Legend");
    if (track!= NULL) {
        printf("Track found: %s\n", track->title);
    } else {
        printf("Track not found.\n");
    }

    // Display the library
    displayLibrary(tracks, size);

    return 0;
}