//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define MAX_TITLE 50
#define MAX_ARTIST 50
#define MAX_GENRE 30

typedef struct {
    char title[MAX_TITLE];
    char artist[MAX_ARTIST];
    char genre[MAX_GENRE];
    int duration; // duration in seconds
} Song;

Song musicLibrary[MAX_SONGS];
int songCount = 0;

void addSong() {
    if (songCount >= MAX_SONGS) {
        printf("Music Library is full!\n");
        return;
    }

    Song newSong;
    printf("Enter Song Title: ");
    getchar(); // clear the newline
    fgets(newSong.title, MAX_TITLE, stdin);
    strtok(newSong.title, "\n"); // remove newline

    printf("Enter Artist Name: ");
    fgets(newSong.artist, MAX_ARTIST, stdin);
    strtok(newSong.artist, "\n"); // remove newline

    printf("Enter Genre: ");
    fgets(newSong.genre, MAX_GENRE, stdin);
    strtok(newSong.genre, "\n"); // remove newline

    printf("Enter Duration (in seconds): ");
    scanf("%d", &newSong.duration);

    musicLibrary[songCount++] = newSong;
    printf("Song added successfully!\n");
}

void viewSongs() {
    printf("\n--- Music Library ---\n");
    if (songCount == 0) {
        printf("No songs in the library.\n");
        return;
    }

    for (int i = 0; i < songCount; i++) {
        printf("Song %d:\n", i + 1);
        printf("  Title: %s\n", musicLibrary[i].title);
        printf("  Artist: %s\n", musicLibrary[i].artist);
        printf("  Genre: %s\n", musicLibrary[i].genre);
        printf("  Duration: %d seconds\n", musicLibrary[i].duration);
        printf("------------------------\n");
    }
}

void deleteSong() {
    if (songCount == 0) {
        printf("No songs to delete.\n");
        return;
    }

    int index;
    printf("Enter the index of the song to delete (1 to %d): ", songCount);
    scanf("%d", &index);

    if (index < 1 || index > songCount) {
        printf("Invalid index!\n");
        return;
    }

    for (int i = index - 1; i < songCount - 1; i++) {
        musicLibrary[i] = musicLibrary[i + 1];
    }
    songCount--;
    printf("Song deleted successfully!\n");
}

void displayMenu() {
    printf("\n--- Music Library Management System ---\n");
    printf("1. Add Song\n");
    printf("2. View Songs\n");
    printf("3. Delete Song\n");
    printf("4. Exit\n");
    printf("--------------------------------------\n");
    printf("Choose an option: ");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addSong();
                break;
            case 2:
                viewSongs();
                break;
            case 3:
                deleteSong();
                break;
            case 4:
                printf("Exiting the Music Library. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}