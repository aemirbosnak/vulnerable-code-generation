//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC_COUNT 1000
#define MAX_MUSIC_TITLE_LENGTH 100
#define MAX_MUSIC_ARTIST_LENGTH 50
#define MAX_MUSIC_ALBUM_LENGTH 100
#define MAX_MUSIC_GENRE_LENGTH 50

typedef struct {
    char title[MAX_MUSIC_TITLE_LENGTH];
    char artist[MAX_MUSIC_ARTIST_LENGTH];
    char album[MAX_MUSIC_ALBUM_LENGTH];
    char genre[MAX_MUSIC_GENRE_LENGTH];
    int duration;
} Music;

void addMusic(Music* music, int count) {
    if (count >= MAX_MUSIC_COUNT) {
        printf("Error: Music library is full.\n");
        return;
    }
    printf("Enter the duration of the music (in seconds): ");
    scanf("%d", &music->duration);
    printf("Enter the title of the music: ");
    scanf("%s", music->title);
    printf("Enter the artist of the music: ");
    scanf("%s", music->artist);
    printf("Enter the album of the music: ");
    scanf("%s", music->album);
    printf("Enter the genre of the music: ");
    scanf("%s", music->genre);
}

void displayMusic(Music* music, int count) {
    printf("Music library:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - %s (%s) [%s] - %d seconds\n", i+1, music[i].title, music[i].artist, music[i].album, music[i].genre, music[i].duration);
    }
}

int main() {
    Music music[MAX_MUSIC_COUNT];
    int count = 0;
    char choice;
    do {
        printf("Music library management system\n");
        printf("1. Add music\n");
        printf("2. Display music\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);
        switch (choice) {
            case '1':
                addMusic(music, count);
                count++;
                break;
            case '2':
                displayMusic(music, count);
                break;
            case '3':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= '3');
    return 0;
}