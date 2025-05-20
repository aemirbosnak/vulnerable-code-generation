//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALBUMS 100
#define MAX_TRACKS 15
#define ALBUM_NAME_LEN 100
#define ARTIST_NAME_LEN 100
#define TRACK_NAME_LEN 100

typedef struct {
    char trackName[TRACK_NAME_LEN];
    int duration; // Duration in seconds
} Track;

typedef struct {
    char albumName[ALBUM_NAME_LEN];
    char artistName[ARTIST_NAME_LEN];
    Track tracks[MAX_TRACKS];
    int numberOfTracks;
} Album;

Album musicLibrary[MAX_ALBUMS];
int albumCount = 0;

void addAlbum() {
    if (albumCount >= MAX_ALBUMS) {
        printf("Music library is full! Cannot add more albums.\n");
        return;
    }

    Album newAlbum;

    printf("Enter album name: ");
    scanf(" %[^\n]%*c", newAlbum.albumName);
    printf("Enter artist name: ");
    scanf(" %[^\n]%*c", newAlbum.artistName);
    
    printf("Enter number of tracks: ");
    scanf("%d", &newAlbum.numberOfTracks);

    for (int i = 0; i < newAlbum.numberOfTracks; i++) {
        printf("Enter track %d name: ", i + 1);
        scanf(" %[^\n]%*c", newAlbum.tracks[i].trackName);
        printf("Enter duration (in seconds) for track %d: ", i + 1);
        scanf("%d", &newAlbum.tracks[i].duration);
    }

    musicLibrary[albumCount++] = newAlbum;
    printf("Album added successfully!\n");
}

void viewAlbums() {
    if (albumCount == 0) {
        printf("No albums found in the music library.\n");
        return;
    }

    printf("Music Library:\n");
    for (int i = 0; i < albumCount; i++) {
        printf("Album %d:\n", i + 1);
        printf("  Name: %s\n", musicLibrary[i].albumName);
        printf("  Artist: %s\n", musicLibrary[i].artistName);
        printf("  Tracks:\n");
        for (int j = 0; j < musicLibrary[i].numberOfTracks; j++) {
            printf("    %s (%d seconds)\n", musicLibrary[i].tracks[j].trackName, musicLibrary[i].tracks[j].duration);
        }
    }
}

void deleteAlbum() {
    if (albumCount == 0) {
        printf("No albums to delete!\n");
        return;
    }

    int index;
    printf("Enter album number to delete (1-%d): ", albumCount);
    scanf("%d", &index);
    
    if (index < 1 || index > albumCount) {
        printf("Invalid album number!\n");
        return;
    }

    for (int i = index - 1; i < albumCount - 1; i++) {
        musicLibrary[i] = musicLibrary[i + 1];
    }
    albumCount--;
    printf("Album deleted successfully!\n");
}

void menu() {
    int choice;
    do {
        printf("\n--- Music Library Management System ---\n");
        printf("1. Add Album\n");
        printf("2. View Albums\n");
        printf("3. Delete Album\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addAlbum();
                break;
            case 2:
                viewAlbums();
                break;
            case 3:
                deleteAlbum();
                break;
            case 4:
                printf("Exiting the application. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);
}

int main() {
    menu();
    return 0;
}