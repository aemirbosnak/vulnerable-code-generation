//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRACKS 100
#define TITLE_LENGTH 50
#define ARTIST_LENGTH 50
#define ALBUM_LENGTH 50

typedef struct {
    char title[TITLE_LENGTH];
    char artist[ARTIST_LENGTH];
    char album[ALBUM_LENGTH];
    int year;
} Track;

void addTrack(Track *library, int *count) {
    if (*count >= MAX_TRACKS) {
        printf("Library is full! Cannot add more tracks.\n");
        return;
    }

    printf("Enter track title: ");
    getchar(); // clear the newline character leftover
    fgets(library[*count].title, TITLE_LENGTH, stdin);
    library[*count].title[strcspn(library[*count].title, "\n")] = 0; // remove newline

    printf("Enter artist name: ");
    fgets(library[*count].artist, ARTIST_LENGTH, stdin);
    library[*count].artist[strcspn(library[*count].artist, "\n")] = 0;

    printf("Enter album name: ");
    fgets(library[*count].album, ALBUM_LENGTH, stdin);
    library[*count].album[strcspn(library[*count].album, "\n")] = 0;

    printf("Enter release year: ");
    scanf("%d", &library[*count].year);

    (*count)++;
    printf("Track added successfully!\n");
}

void displayTracks(Track *library, int count) {
    if (count == 0) {
        printf("No tracks in the library.\n");
        return;
    }

    printf("\n--- Music Library ---\n");
    for (int i = 0; i < count; i++) {
        printf("Track %d:\n", i + 1);
        printf("Title: %s\n", library[i].title);
        printf("Artist: %s\n", library[i].artist);
        printf("Album: %s\n", library[i].album);
        printf("Release Year: %d\n\n", library[i].year);
    }
}

void searchTrack(Track *library, int count) {
    char searchTitle[TITLE_LENGTH];
    printf("Enter track title to search: ");
    getchar(); // clear the newline character
    fgets(searchTitle, TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // remove newline

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcasecmp(library[i].title, searchTitle) == 0) {
            printf("Track found:\n");
            printf("Title: %s\n", library[i].title);
            printf("Artist: %s\n", library[i].artist);
            printf("Album: %s\n", library[i].album);
            printf("Release Year: %d\n", library[i].year);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Track not found.\n");
    }
}

int main() {
    Track musicLibrary[MAX_TRACKS];
    int trackCount = 0;
    int choice;

    while (1) {
        printf("\n--- Music Library Management System ---\n");
        printf("1. Add Track\n");
        printf("2. Display Tracks\n");
        printf("3. Search Track\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTrack(musicLibrary, &trackCount);
                break;
            case 2:
                displayTracks(musicLibrary, trackCount);
                break;
            case 3:
                searchTrack(musicLibrary, trackCount);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}