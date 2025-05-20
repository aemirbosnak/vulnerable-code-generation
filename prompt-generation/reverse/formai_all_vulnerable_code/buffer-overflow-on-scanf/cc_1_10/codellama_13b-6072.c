//Code Llama-13B DATASET v1.0 Category: Music Library Management System ; Style: ephemeral
// Music Library Management System
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Structure to represent a song
struct song {
    char title[50];
    char artist[50];
    int year;
    int duration;
};

// Function to display a song
void display_song(struct song song) {
    printf("Title: %s\n", song.title);
    printf("Artist: %s\n", song.artist);
    printf("Year: %d\n", song.year);
    printf("Duration: %d\n", song.duration);
}

// Function to add a song to the library
void add_song(struct song *songs, int *song_count) {
    // Prompt user for input
    printf("Enter the title: ");
    scanf("%s", songs[*song_count].title);
    printf("Enter the artist: ");
    scanf("%s", songs[*song_count].artist);
    printf("Enter the year: ");
    scanf("%d", &songs[*song_count].year);
    printf("Enter the duration: ");
    scanf("%d", &songs[*song_count].duration);

    // Increment song count
    *song_count += 1;
}

// Function to search for a song by title
void search_song(struct song *songs, int song_count) {
    // Prompt user for input
    char search_title[50];
    printf("Enter the title: ");
    scanf("%s", search_title);

    // Loop through songs and display matching titles
    for (int i = 0; i < song_count; i++) {
        if (strcmp(songs[i].title, search_title) == 0) {
            display_song(songs[i]);
        }
    }
}

int main() {
    // Initialize song count
    int song_count = 0;

    // Create an array of 100 songs
    struct song songs[100];

    // Add songs to library
    add_song(&songs, &song_count);
    add_song(&songs, &song_count);
    add_song(&songs, &song_count);

    // Search for a song
    search_song(songs, song_count);

    return 0;
}