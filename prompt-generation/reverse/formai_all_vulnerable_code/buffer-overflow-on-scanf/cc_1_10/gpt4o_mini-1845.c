//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRACKS 100
#define TITLE_LEN 50
#define ARTIST_LEN 50

typedef struct {
    char title[TITLE_LEN];
    char artist[ARTIST_LEN];
    int year;
} MusicTrack;

typedef struct {
    MusicTrack tracks[MAX_TRACKS];
    int count;
} MusicLibrary;

void addTrack(MusicLibrary *library, const char *title, const char *artist, int year) {
    if (library->count < MAX_TRACKS) {
        strncpy(library->tracks[library->count].title, title, TITLE_LEN);
        strncpy(library->tracks[library->count].artist, artist, ARTIST_LEN);
        library->tracks[library->count].year = year;
        library->count++;
        printf("Track added successfully.\n");
    } else {
        printf("Library is full, cannot add more tracks.\n");
    }
}

void viewTracks(const MusicLibrary *library) {
    if (library->count == 0) {
        printf("No tracks in the library.\n");
        return;
    }
    printf("Music Library:\n");
    for (int i = 0; i < library->count; i++) {
        printf("Track %d: Title: %s, Artist: %s, Year: %d\n", i+1, library->tracks[i].title, library->tracks[i].artist, library->tracks[i].year);
    }
}

int searchTrack(const MusicLibrary *library, const char *title) {
    for (int i = 0; i < library->count; i++) {
        if (strcmp(library->tracks[i].title, title) == 0) {
            return i;
        }
    }
    return -1;
}

void deleteTrack(MusicLibrary *library, const char *title) {
    int index = searchTrack(library, title);
    if (index != -1) {
        for (int i = index; i < library->count - 1; i++) {
            library->tracks[i] = library->tracks[i + 1];
        }
        library->count--;
        printf("Track deleted successfully.\n");
    } else {
        printf("Track not found.\n");
    }
}

void menu() {
    printf("\nMusic Library Management System\n");
    printf("1. Add Track\n");
    printf("2. View Tracks\n");
    printf("3. Search Track\n");
    printf("4. Delete Track\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    MusicLibrary library = { .count = 0 };
    int choice;
    char title[TITLE_LEN], artist[ARTIST_LEN];
    int year;

    while (1) {
        menu();
        scanf("%d", &choice);
        getchar(); // to consume newline left in buffer

        switch (choice) {
            case 1:
                printf("Enter title: ");
                fgets(title, TITLE_LEN, stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline

                printf("Enter artist: ");
                fgets(artist, ARTIST_LEN, stdin);
                artist[strcspn(artist, "\n")] = 0; // Remove newline

                printf("Enter year: ");
                scanf("%d", &year);
                addTrack(&library, title, artist, year);
                break;

            case 2:
                viewTracks(&library);
                break;

            case 3:
                printf("Enter title to search: ");
                fgets(title, TITLE_LEN, stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline

                if (searchTrack(&library, title) != -1) {
                    printf("Track found: Title: %s\n", title);
                } else {
                    printf("Track not found.\n");
                }
                break;

            case 4:
                printf("Enter title to delete: ");
                fgets(title, TITLE_LEN, stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline
                deleteTrack(&library, title);
                break;

            case 5:
                printf("Exiting the system.\n");
                exit(0);

            default:
                printf("Invalid option, please choose again.\n");
                break;
        }
    }

    return 0;
}