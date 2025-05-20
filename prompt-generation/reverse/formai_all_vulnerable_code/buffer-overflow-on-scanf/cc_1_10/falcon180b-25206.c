//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC_FILES 100
#define MAX_STRING_SIZE 100

typedef struct {
    char title[MAX_STRING_SIZE];
    char artist[MAX_STRING_SIZE];
    char genre[MAX_STRING_SIZE];
    int duration;
} MusicFile;

MusicFile musicLibrary[MAX_MUSIC_FILES];
int numMusicFiles = 0;

void addMusicFile() {
    if (numMusicFiles >= MAX_MUSIC_FILES) {
        printf("Error: Music library is full.\n");
        return;
    }

    printf("Enter the title of the music file: ");
    scanf("%s", musicLibrary[numMusicFiles].title);

    printf("Enter the artist of the music file: ");
    scanf("%s", musicLibrary[numMusicFiles].artist);

    printf("Enter the genre of the music file: ");
    scanf("%s", musicLibrary[numMusicFiles].genre);

    printf("Enter the duration of the music file (in seconds): ");
    scanf("%d", &musicLibrary[numMusicFiles].duration);

    numMusicFiles++;
}

void displayMusicFiles() {
    if (numMusicFiles == 0) {
        printf("Music library is empty.\n");
        return;
    }

    printf("\nMusic Library:\n");
    printf("--------------------\n");
    printf("Title\tArtist\tGenre\tDuration\n");

    for (int i = 0; i < numMusicFiles; i++) {
        printf("%s\t%s\t%s\t%d seconds\n", musicLibrary[i].title, musicLibrary[i].artist, musicLibrary[i].genre, musicLibrary[i].duration);
    }
}

int main() {
    addMusicFile();
    addMusicFile();
    addMusicFile();

    displayMusicFiles();

    return 0;
}