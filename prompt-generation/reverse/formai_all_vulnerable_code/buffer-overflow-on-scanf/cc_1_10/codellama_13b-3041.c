//Code Llama-13B DATASET v1.0 Category: Music Library Management System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Song {
    char* name;
    char* artist;
    int year;
    float rating;
};

void addSong(struct Song* songs, int* numSongs, char* name, char* artist, int year, float rating) {
    if (*numSongs >= 100) {
        printf("Sorry, the music library is full.\n");
        return;
    }
    songs[*numSongs].name = strdup(name);
    songs[*numSongs].artist = strdup(artist);
    songs[*numSongs].year = year;
    songs[*numSongs].rating = rating;
    (*numSongs)++;
}

void removeSong(struct Song* songs, int* numSongs, int index) {
    if (index < 0 || index >= *numSongs) {
        printf("Invalid index.\n");
        return;
    }
    for (int i = index; i < *numSongs - 1; i++) {
        songs[i] = songs[i + 1];
    }
    (*numSongs)--;
}

void sortSongs(struct Song* songs, int numSongs) {
    for (int i = 0; i < numSongs; i++) {
        for (int j = i + 1; j < numSongs; j++) {
            if (songs[i].rating < songs[j].rating) {
                struct Song temp = songs[i];
                songs[i] = songs[j];
                songs[j] = temp;
            }
        }
    }
}

void printSongs(struct Song* songs, int numSongs) {
    for (int i = 0; i < numSongs; i++) {
        printf("%d. %s - %s (%d) - %f\n", i + 1, songs[i].name, songs[i].artist, songs[i].year, songs[i].rating);
    }
}

int main() {
    struct Song songs[100];
    int numSongs = 0;
    char name[50], artist[50];
    int year;
    float rating;
    char command;
    while (1) {
        printf("Enter a command (a/r/s/p/q): ");
        scanf(" %c", &command);
        switch (command) {
            case 'a':
                printf("Enter song name: ");
                scanf(" %s", name);
                printf("Enter artist name: ");
                scanf(" %s", artist);
                printf("Enter release year: ");
                scanf(" %d", &year);
                printf("Enter rating: ");
                scanf(" %f", &rating);
                addSong(songs, &numSongs, name, artist, year, rating);
                break;
            case 'r':
                printf("Enter song index to remove: ");
                scanf(" %d", &index);
                removeSong(songs, &numSongs, index);
                break;
            case 's':
                sortSongs(songs, numSongs);
                break;
            case 'p':
                printSongs(songs, numSongs);
                break;
            case 'q':
                return 0;
        }
    }
    return 0;
}