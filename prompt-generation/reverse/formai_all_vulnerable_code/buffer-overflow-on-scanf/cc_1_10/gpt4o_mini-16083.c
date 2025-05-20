//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define TITLE_LENGTH 100
#define ARTIST_LENGTH 100

typedef struct {
    char title[TITLE_LENGTH];
    char artist[ARTIST_LENGTH];
    int year;
    char genre[30];
} Song;

void addSong();
void viewSongs();
void searchSong();
void displaySong(Song song);

int main() {
    int choice;
    
    do {
        printf("\n--- Music Library Management System ---\n");
        printf("1. Add a song\n");
        printf("2. View all songs\n");
        printf("3. Search for a song\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character

        switch (choice) {
            case 1:
                addSong();
                break;
            case 2:
                viewSongs();
                break;
            case 3:
                searchSong();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void addSong() {
    FILE *file = fopen("music_library.dat", "ab");
    if (file == NULL) {
        perror("Unable to open file!");
        return;
    }

    Song newSong;
    printf("Enter song title: ");
    fgets(newSong.title, TITLE_LENGTH, stdin);
    strtok(newSong.title, "\n"); // Remove newline character

    printf("Enter artist name: ");
    fgets(newSong.artist, ARTIST_LENGTH, stdin);
    strtok(newSong.artist, "\n");

    printf("Enter release year: ");
    scanf("%d", &newSong.year);
    getchar(); // Clear newline character

    printf("Enter genre: ");
    fgets(newSong.genre, 30, stdin);
    strtok(newSong.genre, "\n");

    fwrite(&newSong, sizeof(Song), 1, file);
    fclose(file);
    printf("Song added successfully!\n");
}

void viewSongs() {
    FILE *file = fopen("music_library.dat", "rb");
    if (file == NULL) {
        perror("Unable to open file!");
        return;
    }

    Song song;
    printf("\n--- List of Songs ---\n");
    while (fread(&song, sizeof(Song), 1, file)) {
        displaySong(song);
    }

    fclose(file);
}

void searchSong() {
    FILE *file = fopen("music_library.dat", "rb");
    if (file == NULL) {
        perror("Unable to open file!");
        return;
    }

    char searchTitle[TITLE_LENGTH];
    printf("Enter song title to search: ");
    fgets(searchTitle, TITLE_LENGTH, stdin);
    strtok(searchTitle, "\n");

    Song song;
    int found = 0;
    
    while (fread(&song, sizeof(Song), 1, file)) {
        if (strcasecmp(song.title, searchTitle) == 0) {
            printf("\nSong found:\n");
            displaySong(song);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Song not found in the library.\n");
    }

    fclose(file);
}

void displaySong(Song song) {
    printf("Title: %s\n", song.title);
    printf("Artist: %s\n", song.artist);
    printf("Year: %d\n", song.year);
    printf("Genre: %s\n", song.genre);
    printf("------------------------------------\n");
}