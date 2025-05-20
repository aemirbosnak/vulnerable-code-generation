//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRACKS 100
#define TITLE_LEN 100
#define ARTIST_LEN 100
#define ALBUM_LEN 100

typedef struct {
    char title[TITLE_LEN];
    char artist[ARTIST_LEN];
    char album[ALBUM_LEN];
    int year;
} Track;

Track library[MAX_TRACKS];
int trackCount = 0;

void loadLibrary() {
    FILE *file = fopen("music_library.txt", "r");
    if (file) {
        while (fscanf(file, "%99[^\n] %99[^\n] %99[^\n] %d\n", library[trackCount].title, library[trackCount].artist, library[trackCount].album, &library[trackCount].year) == 4) {
            trackCount++;
        }
        fclose(file);
    }
}

void saveLibrary() {
    FILE *file = fopen("music_library.txt", "w");
    for (int i = 0; i < trackCount; i++) {
        fprintf(file, "%s\n%s\n%s\n%d\n", library[i].title, library[i].artist, library[i].album, library[i].year);
    }
    fclose(file);
}

void addTrack() {
    if (trackCount >= MAX_TRACKS) {
        printf("Library is full! Cannot add more tracks.\n");
        return;
    }
    printf("Enter track title: ");
    getchar(); // to clear the newline from previous input
    fgets(library[trackCount].title, TITLE_LEN, stdin);
    strtok(library[trackCount].title, "\n"); // remove newline

    printf("Enter artist: ");
    fgets(library[trackCount].artist, ARTIST_LEN, stdin);
    strtok(library[trackCount].artist, "\n");

    printf("Enter album: ");
    fgets(library[trackCount].album, ALBUM_LEN, stdin);
    strtok(library[trackCount].album, "\n");

    printf("Enter release year: ");
    scanf("%d", &library[trackCount].year);

    trackCount++;
    printf("Track added successfully!\n");
}

void displayLibrary() {
    if (trackCount == 0) {
        printf("No tracks in the library.\n");
        return;
    }
    for (int i = 0; i < trackCount; i++) {
        printf("Track %d:\n", i + 1);
        printf("Title: %s\n", library[i].title);
        printf("Artist: %s\n", library[i].artist);
        printf("Album: %s\n", library[i].album);
        printf("Year: %d\n", library[i].year);
        printf("----------------\n");
    }
}

void searchTrack() {
    char query[TITLE_LEN];
    printf("Enter title/artist/album to search: ");
    getchar(); // clearing the buffer
    fgets(query, TITLE_LEN, stdin);
    strtok(query, "\n");

    int found = 0;
    for (int i = 0; i < trackCount; i++) {
        if (strstr(library[i].title, query) || strstr(library[i].artist, query) || strstr(library[i].album, query)) {
            printf("Found Track %d:\n", i + 1);
            printf("Title: %s\n", library[i].title);
            printf("Artist: %s\n", library[i].artist);
            printf("Album: %s\n", library[i].album);
            printf("Year: %d\n", library[i].year);
            found = 1;
        }
    }
    if (!found) {
        printf("No tracks found matching your query.\n");
    }
}

void deleteTrack() {
    int index;
    printf("Enter track number to delete (1 to %d): ", trackCount);
    scanf("%d", &index);
    if (index < 1 || index > trackCount) {
        printf("Invalid track number.\n");
        return;
    }

    for (int i = index - 1; i < trackCount - 1; i++) {
        library[i] = library[i + 1];
    }
    trackCount--;
    printf("Track deleted successfully!\n");
}

int main() {
    loadLibrary();
    int choice;

    while (1) {
        printf("\n--- Music Library Management System ---\n");
        printf("1. Add Track\n");
        printf("2. Display Library\n");
        printf("3. Search Track\n");
        printf("4. Delete Track\n");
        printf("5. Save and Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTrack();
                break;
            case 2:
                displayLibrary();
                break;
            case 3:
                searchTrack();
                break;
            case 4:
                deleteTrack();
                break;
            case 5:
                saveLibrary();
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}