//Code Llama-13B DATASET v1.0 Category: Music Library Management System ; Style: satisfied
/*
 * Music Library Management System
 *
 * This program allows users to add, remove, and view songs in a music library.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100

typedef struct {
    char title[50];
    char artist[50];
    int length;
} Song;

void addSong(Song* songs, int* numSongs) {
    if (*numSongs >= MAX_SONGS) {
        printf("Sorry, the library is full.\n");
        return;
    }
    printf("Enter the song title: ");
    scanf("%s", songs[*numSongs].title);
    printf("Enter the artist name: ");
    scanf("%s", songs[*numSongs].artist);
    printf("Enter the song length (in seconds): ");
    scanf("%d", &songs[*numSongs].length);
    (*numSongs)++;
}

void removeSong(Song* songs, int* numSongs) {
    if (*numSongs <= 0) {
        printf("There are no songs in the library.\n");
        return;
    }
    int index;
    printf("Enter the index of the song to remove: ");
    scanf("%d", &index);
    if (index < 0 || index >= *numSongs) {
        printf("Invalid index.\n");
        return;
    }
    for (int i = index; i < *numSongs - 1; i++) {
        songs[i] = songs[i + 1];
    }
    (*numSongs)--;
}

void viewSongs(Song* songs, int numSongs) {
    if (numSongs <= 0) {
        printf("There are no songs in the library.\n");
        return;
    }
    printf("Song list:\n");
    for (int i = 0; i < numSongs; i++) {
        printf("%d. %s by %s (%d seconds)\n", i + 1, songs[i].title, songs[i].artist, songs[i].length);
    }
}

int main() {
    Song songs[MAX_SONGS];
    int numSongs = 0;

    char choice;
    while (1) {
        printf("Enter your choice (A)dd, (R)emove, or (V)iew songs: ");
        scanf(" %c", &choice);
        switch (choice) {
            case 'A':
                addSong(songs, &numSongs);
                break;
            case 'R':
                removeSong(songs, &numSongs);
                break;
            case 'V':
                viewSongs(songs, numSongs);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}