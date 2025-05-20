//FormAI DATASET v1.0 Category: Music Library Management System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define SONG_LENGTH 50

typedef struct {
    char title[SONG_LENGTH];
    char artist[SONG_LENGTH];
    int year;
} Song;

void addSong(Song songs[], int *numSongs);
void viewSongs(Song songs[], int numSongs);
void searchSongs(Song songs[], int numSongs);
void deleteSong(Song songs[], int *numSongs);

int main() {
    Song songs[MAX_SONGS];
    int numSongs = 0;
    char choice;

    printf("Welcome to the C Music Library Management System!\n");

    do {
        printf("\nMenu:\n");
        printf("a) Add a song\n");
        printf("b) View all songs\n");
        printf("c) Search for a song\n");
        printf("d) Delete a song\n");
        printf("e) Quit\n");

        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                addSong(songs, &numSongs);
                break;
            case 'b':
                viewSongs(songs, numSongs);
                break;
            case 'c':
                searchSongs(songs, numSongs);
                break;
            case 'd':
                deleteSong(songs, &numSongs);
                break;
            case 'e':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 'e');

    return 0;
}

void addSong(Song songs[], int *numSongs) {
    if (*numSongs == MAX_SONGS) {
        printf("Error: Maximum number of songs reached.\n");
        return;
    }

    Song newSong;

    printf("Enter the title of the song: ");
    scanf(" %[^\n]", newSong.title);
    printf("Enter the artist of the song: ");
    scanf(" %[^\n]", newSong.artist);
    printf("Enter the year the song was released: ");
    scanf("%d", &newSong.year);

    songs[*numSongs] = newSong;
    *numSongs += 1;

    printf("Song added successfully.\n");
}

void viewSongs(Song songs[], int numSongs) {
    if (numSongs == 0) {
        printf("No songs to display.\n");
        return;
    }

    printf("%-30s %-30s %-10s\n", "Title", "Artist", "Year");
    printf("--------------------------------------------------\n");

    for (int i = 0; i < numSongs; i++) {
        printf("%-30s %-30s %-10d\n", songs[i].title, songs[i].artist, songs[i].year);
    }
}

void searchSongs(Song songs[], int numSongs) {
    if (numSongs == 0) {
        printf("No songs to search for.\n");
        return;
    }

    char search[SONG_LENGTH];
    int found = 0;

    printf("Enter the title or artist to search for: ");
    scanf(" %[^\n]", search);

    for (int i = 0; i < numSongs; i++) {
        if (strstr(songs[i].title, search) != NULL || strstr(songs[i].artist, search) != NULL) {
            printf("%-30s %-30s %-10d\n", songs[i].title, songs[i].artist, songs[i].year);
            found = 1;
        }
    }

    if (!found) {
        printf("No matching songs found.\n");
    }
}

void deleteSong(Song songs[], int *numSongs) {
    if (*numSongs == 0) {
        printf("No songs to delete.\n");
        return;
    }

    char deleteName[SONG_LENGTH];
    int deleteIndex = -1;

    printf("Enter the name of the song to delete: ");
    scanf(" %[^\n]", deleteName);

    for (int i = 0; i < *numSongs; i++) {
        if (strcmp(songs[i].title, deleteName) == 0) {
            deleteIndex = i;
            break;
        }
    }

    if (deleteIndex == -1) {
        printf("Song not found.\n");
        return;
    }

    for (int i = deleteIndex; i < *numSongs - 1; i++) {
        songs[i] = songs[i + 1];
    }

    *numSongs -= 1;

    printf("Song deleted successfully.\n");
}