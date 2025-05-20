//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC_COUNT 100
#define MAX_TITLE_LENGTH 100
#define MAX_ARTIST_LENGTH 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    int year;
} MusicTrack;

void addMusicTrack(MusicTrack tracks[], int *count) {
    if (*count >= MAX_MUSIC_COUNT) {
        printf("Music library is full!\n");
        return;
    }

    MusicTrack newTrack;
    printf("Enter music title: ");
    scanf(" %[^\n]", newTrack.title);
    printf("Enter artist name: ");
    scanf(" %[^\n]", newTrack.artist);
    printf("Enter release year: ");
    scanf("%d", &newTrack.year);

    tracks[*count] = newTrack;
    (*count)++;
    printf("Track added successfully!\n");
}

void viewMusicTracks(MusicTrack tracks[], int count) {
    if (count == 0) {
        printf("No music tracks available.\n");
        return;
    }

    printf("\nMusic Library:\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d. Title: %s | Artist: %s | Year: %d\n", 
                (i + 1), tracks[i].title, tracks[i].artist, tracks[i].year);
    }
    printf("--------------------------------------------------\n");
}

void searchMusicTrack(MusicTrack tracks[], int count) {
    char title[MAX_TITLE_LENGTH];
    printf("Enter the title of the music track to search: ");
    scanf(" %[^\n]", title);

    for (int i = 0; i < count; i++) {
        if (strcmp(tracks[i].title, title) == 0) {
            printf("Track found: Title: %s | Artist: %s | Year: %d\n", 
                    tracks[i].title, tracks[i].artist, tracks[i].year);
            return;
        }
    }
    printf("Track not found.\n");
}

void deleteMusicTrack(MusicTrack tracks[], int *count) {
    char title[MAX_TITLE_LENGTH];
    printf("Enter the title of the music track to delete: ");
    scanf(" %[^\n]", title);

    for (int i = 0; i < *count; i++) {
        if (strcmp(tracks[i].title, title) == 0) {
            for (int j = i; j < *count - 1; j++) {
                tracks[j] = tracks[j + 1];
            }
            (*count)--;
            printf("Track '%s' deleted successfully!\n", title);
            return;
        }
    }
    printf("Track not found.\n");
}

void displayMenu() {
    printf("\n--- Music Library Management System ---\n");
    printf("1. Add Music Track\n");
    printf("2. View Music Tracks\n");
    printf("3. Search Music Track\n");
    printf("4. Delete Music Track\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

int main() {
    MusicTrack musicLibrary[MAX_MUSIC_COUNT];
    int musicCount = 0;
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMusicTrack(musicLibrary, &musicCount);
                break;
            case 2:
                viewMusicTracks(musicLibrary, musicCount);
                break;
            case 3:
                searchMusicTrack(musicLibrary, musicCount);
                break;
            case 4:
                deleteMusicTrack(musicLibrary, &musicCount);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}