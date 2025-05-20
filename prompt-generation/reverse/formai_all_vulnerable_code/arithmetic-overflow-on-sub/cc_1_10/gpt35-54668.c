//FormAI DATASET v1.0 Category: Music Library Management System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
};

int main() {
    int num_songs = 0;
    struct Song* library = NULL;

    // Prompt user for number of songs
    printf("How many songs are in your library? ");
    scanf("%d", &num_songs);

    // Allocate memory for song library
    library = malloc(num_songs * sizeof(struct Song));

    // Populate song library with user input
    for (int i = 0; i < num_songs; i++) {
        printf("\nSong %d:\n", i+1);
        printf("Title: ");
        scanf("%s", library[i].title);
        printf("Artist: ");
        scanf("%s", library[i].artist);
        printf("Album: ");
        scanf("%s", library[i].album);
        printf("Year: ");
        scanf("%d", &library[i].year);
    }

    // Sort song library by year
    for (int i = 0; i < num_songs-1; i++) {
        for (int j = 0; j < num_songs-i-1; j++) {
            if (library[j].year > library[j+1].year) {
                struct Song temp_song = library[j];
                library[j] = library[j+1];
                library[j+1] = temp_song;
            }
        }
    }

    // Print sorted song library
    printf("\nSorted Song Library\n");
    printf("--------------------\n");
    for (int i = 0; i < num_songs; i++) {
        printf("%s, %s, %s, %d\n", library[i].title, library[i].artist, library[i].album, library[i].year);
    }

    // Free allocated memory
    free(library);

    return 0;
}