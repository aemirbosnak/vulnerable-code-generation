//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100

typedef struct {
    char title[100];
    char artist[100];
    int duration;
    int genre;
} Song;

void addSong(Song* songs, int count) {
    printf("Enter song title: ");
    scanf("%s", songs[count].title);
    printf("Enter artist name: ");
    scanf("%s", songs[count].artist);
    printf("Enter song duration (in seconds): ");
    scanf("%d", &songs[count].duration);
    printf("Enter song genre (0 for pop, 1 for rock, 2 for hip hop): ");
    scanf("%d", &songs[count].genre);
}

void displaySongs(Song* songs, int count) {
    for (int i = 0; i < count; i++) {
        printf("Song %d:\nTitle: %s\nArtist: %s\nDuration: %d seconds\nGenre: ", i+1, songs[i].title, songs[i].artist, songs[i].duration);
        if (songs[i].genre == 0) {
            printf("Pop\n");
        } else if (songs[i].genre == 1) {
            printf("Rock\n");
        } else {
            printf("Hip Hop\n");
        }
    }
}

int main() {
    Song songs[MAX_SONGS];
    int count = 0;

    while (count < MAX_SONGS) {
        printf("\nDo you want to add a song? (y/n): ");
        char choice;
        scanf("%c", &choice);
        if (choice == 'y') {
            addSong(songs, count);
            count++;
        } else {
            displaySongs(songs, count);
            break;
        }
    }

    return 0;
}