//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_ARTIST_LENGTH 100
#define MAX_TRACKS 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    int year;
} Track;

typedef struct {
    Track* tracks;
    int size;
} MusicLibrary;

MusicLibrary* createLibrary() {
    MusicLibrary* library = malloc(sizeof(MusicLibrary));
    if (!library) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    library->tracks = malloc(MAX_TRACKS * sizeof(Track));
    library->size = 0;
    return library;
}

void addTrack(MusicLibrary* library) {
    if (library->size >= MAX_TRACKS) {
        printf("Music library is full, cannot add more tracks.\n");
        return;
    }
    
    Track* track = &library->tracks[library->size];
    
    printf("Enter track title: ");
    fgets(track->title, MAX_TITLE_LENGTH, stdin);
    track->title[strcspn(track->title, "\n")] = 0; // Remove newline

    printf("Enter artist name: ");
    fgets(track->artist, MAX_ARTIST_LENGTH, stdin);
    track->artist[strcspn(track->artist, "\n")] = 0; // Remove newline

    printf("Enter release year: ");
    scanf("%d", &track->year);
    getchar(); // Consume newline left by scanf

    library->size++;
    printf("Track added successfully!\n");
}

void viewTracks(MusicLibrary* library) {
    if (library->size == 0) {
        printf("No tracks in the library.\n");
        return;
    }

    printf("\nMusic Library:\n");
    for (int i = 0; i < library->size; i++) {
        Track* track = &library->tracks[i];
        printf("Title: %s, Artist: %s, Year: %d\n", track->title, track->artist, track->year);
    }
}

void deleteTrack(MusicLibrary* library) {
    if (library->size == 0) {
        printf("No tracks to delete.\n");
        return;
    }

    int index;
    printf("Enter track index to delete (0 to %d): ", library->size - 1);
    scanf("%d", &index);
    getchar(); // Consume newline left by scanf

    if (index < 0 || index >= library->size) {
        printf("Invalid index.\n");
        return;
    }

    for (int i = index; i < library->size - 1; i++) {
        library->tracks[i] = library->tracks[i + 1];
    }
    library->size--;
    printf("Track deleted successfully!\n");
}

void freeLibrary(MusicLibrary* library) {
    free(library->tracks);
    free(library);
}

int main() {
    MusicLibrary* musicLibrary = createLibrary();
    int choice;

    while (1) {
        printf("\nMusic Library Management System\n");
        printf("1. Add Track\n");
        printf("2. View Tracks\n");
        printf("3. Delete Track\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input. Exiting...\n");
            freeLibrary(musicLibrary);
            exit(EXIT_FAILURE);
        }
        getchar(); // Consume newline left by scanf

        switch (choice) {
            case 1:
                addTrack(musicLibrary);
                break;
            case 2:
                viewTracks(musicLibrary);
                break;
            case 3:
                deleteTrack(musicLibrary);
                break;
            case 4:
                freeLibrary(musicLibrary);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option, please try again.\n");
        }
    }

    return 0;
}