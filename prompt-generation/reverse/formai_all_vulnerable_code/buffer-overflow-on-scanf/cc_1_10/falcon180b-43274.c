//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char title[50];
    char artist[50];
    int duration;
    int year;
    int genre;
} Song;

void addSong(Song* songs, int count, char* title, char* artist, int duration, int year, int genre) {
    if (count >= MAX_SIZE) {
        printf("Library is full!\n");
        return;
    }

    strcpy(songs[count].title, title);
    strcpy(songs[count].artist, artist);
    songs[count].duration = duration;
    songs[count].year = year;
    songs[count].genre = genre;

    count++;
}

void displaySongs(Song* songs, int count) {
    printf("\nList of songs:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - %s (%d)\n", i+1, songs[i].title, songs[i].artist, songs[i].duration);
    }
}

void searchSong(Song* songs, int count, char* query) {
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(songs[i].title, query) == 0 || strcmp(songs[i].artist, query) == 0) {
            printf("\nSong found:\n");
            printf("%s - %s\n", songs[i].title, songs[i].artist);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Song not found.\n");
    }
}

int main() {
    Song songs[MAX_SIZE];
    int count = 0;

    addSong(songs, count, "Bohemian Rhapsody", "Queen", 6, 1975, 1);
    addSong(songs, count, "Stairway to Heaven", "Led Zeppelin", 8, 1971, 2);
    addSong(songs, count, "Smells Like Teen Spirit", "Nirvana", 5, 1991, 3);

    displaySongs(songs, count);

    char query[50];
    printf("\nEnter a song title or artist to search: ");
    scanf("%s", query);

    searchSong(songs, count, query);

    return 0;
}