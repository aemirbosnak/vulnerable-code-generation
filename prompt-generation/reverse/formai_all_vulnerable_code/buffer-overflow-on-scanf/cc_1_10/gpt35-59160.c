//FormAI DATASET v1.0 Category: Music Library Management System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRACKS 100

typedef struct {
    char title[30];
    char artist[30];
    char genre[20];
    int duration;
} Track;

typedef struct {
    int numTracks;
    Track tracks[MAX_TRACKS];
} Library;

void addTrack(Library *lib) {
    if (lib->numTracks >= MAX_TRACKS) {
        printf("Error: library is full\n");
        return;
    }
    Track track;
    printf("Enter the track title: ");
    scanf(" %[^\n]", track.title);
    printf("Enter the artist name: ");
    scanf(" %[^\n]", track.artist);
    printf("Enter the genre: ");
    scanf(" %[^\n]", track.genre);
    printf("Enter the duration (in seconds): ");
    scanf("%d", &track.duration);
    lib->tracks[lib->numTracks] = track;
    lib->numTracks++;
    printf("Track added successfully!\n");
}

void displayLibrary(Library *lib) {
    printf("Title\t\tArtist\t\tGenre\t\tDuration (s)\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < lib->numTracks; i++) {
        printf("%s\t\t%s\t\t%s\t\t%d\n", 
            lib->tracks[i].title, lib->tracks[i].artist, 
            lib->tracks[i].genre, lib->tracks[i].duration);
    }
}

void searchByTitle(Library *lib) {
    char title[30];
    printf("Enter the track title to search for: ");
    scanf(" %[^\n]", title);
    for (int i = 0; i < lib->numTracks; i++) {
        if (strcmp(lib->tracks[i].title, title) == 0) {
            printf("%s\t\t%s\t\t%s\t\t%d\n", 
            lib->tracks[i].title, lib->tracks[i].artist, 
            lib->tracks[i].genre, lib->tracks[i].duration);
            return;
        }
    }
    printf("Track not found!\n");
}

void searchByArtist(Library *lib) {
    char artist[30];
    printf("Enter the artist name to search for: ");
    scanf(" %[^\n]", artist);
    int found = 0;
    for (int i = 0; i < lib->numTracks; i++) {
        if (strcmp(lib->tracks[i].artist, artist) == 0) {
            printf("%s\t\t%s\t\t%s\t\t%d\n", 
            lib->tracks[i].title, lib->tracks[i].artist, 
            lib->tracks[i].genre, lib->tracks[i].duration);
            found = 1;
        }
    }
    if (!found) {
        printf("No tracks found for %s\n", artist);
    }
}

int main() {
    Library lib = {0};
    int choice;
    do {
        printf("\n");
        printf("1. Add a track\n");
        printf("2. Display library\n");
        printf("3. Search by title\n");
        printf("4. Search by artist\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addTrack(&lib); break;
            case 2: displayLibrary(&lib); break;
            case 3: searchByTitle(&lib); break;
            case 4: searchByArtist(&lib); break;
            case 5: printf("Goodbye!\n"); break;
            default: printf("Invalid choice\n"); break;
        }
    } while (choice != 5);
    return 0;
}