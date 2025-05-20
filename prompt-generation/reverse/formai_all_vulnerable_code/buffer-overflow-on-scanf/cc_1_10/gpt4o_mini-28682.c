//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC 100
#define TITLE_LENGTH 50
#define ARTIST_LENGTH 50

typedef struct {
    char title[TITLE_LENGTH];
    char artist[ARTIST_LENGTH];
    int duration; // in seconds
    int year;
} MusicTrack;

typedef struct {
    MusicTrack tracks[MAX_MUSIC];
    int count;
} MusicLibrary;

void initializeLibrary(MusicLibrary *library) {
    library->count = 0;
}

void addTrack(MusicLibrary *library) {
    if (library->count >= MAX_MUSIC) {
        printf("Library is full! Cannot add more tracks.\n");
        return;
    }
    
    MusicTrack newTrack;
    printf("Enter track title: ");
    getchar(); // to clear buffer
    fgets(newTrack.title, TITLE_LENGTH, stdin);
    strtok(newTrack.title, "\n"); // remove newline
    printf("Enter artist name: ");
    fgets(newTrack.artist, ARTIST_LENGTH, stdin);
    strtok(newTrack.artist, "\n"); // remove newline
    printf("Enter track duration (in seconds): ");
    scanf("%d", &newTrack.duration);
    printf("Enter release year: ");
    scanf("%d", &newTrack.year);
    
    library->tracks[library->count++] = newTrack;
    printf("Track added successfully!\n");
}

void displayTracks(const MusicLibrary *library) {
    if (library->count == 0) {
        printf("No tracks available in the library.\n");
        return;
    }
    
    printf("\nMusic Library:\n");
    for (int i = 0; i < library->count; i++) {
        printf("%d. Title: %s | Artist: %s | Duration: %d seconds | Year: %d\n",
               i+1, library->tracks[i].title, library->tracks[i].artist,
               library->tracks[i].duration, library->tracks[i].year);
    }
}

void deleteTrack(MusicLibrary *library) {
    if (library->count == 0) {
        printf("No tracks to delete.\n");
        return;
    }
    
    int trackNumber;
    printf("Enter track number to delete: ");
    scanf("%d", &trackNumber);
    
    if (trackNumber < 1 || trackNumber > library->count) {
        printf("Invalid track number!\n");
        return;
    }

    for (int i = trackNumber - 1; i < library->count - 1; i++) {
        library->tracks[i] = library->tracks[i + 1];
    }
    
    library->count--;
    printf("Track deleted successfully!\n");
}

void searchTrack(const MusicLibrary *library) {
    if (library->count == 0) {
        printf("No tracks in library to search.\n");
        return;
    }

    char searchTerm[TITLE_LENGTH];
    printf("Enter the title or artist to search: ");
    getchar(); // to clear buffer
    fgets(searchTerm, TITLE_LENGTH, stdin);
    strtok(searchTerm, "\n"); // remove newline
    
    printf("\nSearch Results:\n");
    int found = 0;
    for (int i = 0; i < library->count; i++) {
        if (strstr(library->tracks[i].title, searchTerm) != NULL ||
            strstr(library->tracks[i].artist, searchTerm) != NULL) {
            printf("%d. Title: %s | Artist: %s | Duration: %d seconds | Year: %d\n",
                   i + 1, library->tracks[i].title, library->tracks[i].artist,
                   library->tracks[i].duration, library->tracks[i].year);
            found = 1;
        }
    }
    if (!found) {
        printf("No matching tracks found.\n");
    }
}

void displayMenu() {
    printf("\n--- Music Library Management System ---\n");
    printf("1. Add Music Track\n");
    printf("2. Display All Tracks\n");
    printf("3. Delete a Track\n");
    printf("4. Search for a Track\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    MusicLibrary library;
    initializeLibrary(&library);
    
    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addTrack(&library);
                break;
            case 2:
                displayTracks(&library);
                break;
            case 3:
                deleteTrack(&library);
                break;
            case 4:
                searchTrack(&library);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }
    
    return 0;
}