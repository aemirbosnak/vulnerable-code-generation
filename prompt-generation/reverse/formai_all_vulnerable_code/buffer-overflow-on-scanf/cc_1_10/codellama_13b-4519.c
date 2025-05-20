//Code Llama-13B DATASET v1.0 Category: Music Library Management System ; Style: brave
/*
 * Brave C Music Library Management System
 *
 * This program allows users to manage their music library by adding, editing, and
 * deleting tracks. It also provides a simple search function to find tracks by
 * name or artist.
 *
 * Author: [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRACKS 100
#define MAX_NAME_LENGTH 100
#define MAX_ARTIST_LENGTH 100

// Structure to represent a track
typedef struct {
    char name[MAX_NAME_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    int length;
} Track;

// Function to add a new track
void addTrack(Track *tracks, int *numTracks) {
    if (*numTracks >= MAX_TRACKS) {
        printf("Library is full.\n");
        return;
    }

    printf("Enter name: ");
    fgets(tracks[*numTracks].name, MAX_NAME_LENGTH, stdin);
    printf("Enter artist: ");
    fgets(tracks[*numTracks].artist, MAX_ARTIST_LENGTH, stdin);
    printf("Enter length: ");
    scanf("%d", &tracks[*numTracks].length);
    (*numTracks)++;
}

// Function to edit a track
void editTrack(Track *tracks, int numTracks, int index) {
    if (index < 0 || index >= numTracks) {
        printf("Invalid index.\n");
        return;
    }

    printf("Enter new name: ");
    fgets(tracks[index].name, MAX_NAME_LENGTH, stdin);
    printf("Enter new artist: ");
    fgets(tracks[index].artist, MAX_ARTIST_LENGTH, stdin);
    printf("Enter new length: ");
    scanf("%d", &tracks[index].length);
}

// Function to delete a track
void deleteTrack(Track *tracks, int *numTracks, int index) {
    if (index < 0 || index >= *numTracks) {
        printf("Invalid index.\n");
        return;
    }

    // Move all tracks after the deleted track to the left
    for (int i = index; i < *numTracks - 1; i++) {
        tracks[i] = tracks[i + 1];
    }

    // Decrement number of tracks
    (*numTracks)--;
}

// Function to search for a track by name or artist
void searchTrack(Track *tracks, int numTracks, char *searchTerm) {
    for (int i = 0; i < numTracks; i++) {
        if (strstr(tracks[i].name, searchTerm) != NULL ||
            strstr(tracks[i].artist, searchTerm) != NULL) {
            printf("Track found: %s by %s\n", tracks[i].name, tracks[i].artist);
        }
    }
}

int main() {
    Track tracks[MAX_TRACKS];
    int numTracks = 0;

    // Add some tracks to the library
    addTrack(tracks, &numTracks);
    addTrack(tracks, &numTracks);
    addTrack(tracks, &numTracks);

    // Edit a track
    editTrack(tracks, numTracks, 1);

    // Delete a track
    deleteTrack(tracks, &numTracks, 2);

    // Search for a track
    searchTrack(tracks, numTracks, "track");

    return 0;
}