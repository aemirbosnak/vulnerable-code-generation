//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100

// Song structure
typedef struct {
    char title[50];
    char artist[50];
    char genre[20];
    int year;
    float duration;
} Song;

// Function to compare two songs by title
int compareSongs(const void *a, const void *b) {
    Song *songA = (Song *)a;
    Song *songB = (Song *)b;

    return strcmp(songA->title, songB->title);
}

// Function to print a song
void printSong(Song song) {
    printf("Title: %s\n", song.title);
    printf("Artist: %s\n", song.artist);
    printf("Genre: %s\n", song.genre);
    printf("Year: %d\n", song.year);
    printf("Duration: %.2f seconds\n\n", song.duration);
}

// Function to search for a song by title
Song* searchSong(Song songs[], int numSongs, char* title) {
    Song key = {.title = title };
    Song* result = bsearch(&key, songs, numSongs, sizeof(Song), compareSongs);

    if (result == NULL) {
        printf("Song not found.\n");
    } else {
        printSong(*result);
    }

    return result;
}

// Main function
int main() {
    Song songs[MAX_SONGS];
    int numSongs = 0;

    // Add some songs
    songs[numSongs++] = (Song) {.title = "Bohemian Rhapsody",.artist = "Queen",.genre = "Rock",.year = 1975,.duration = 183.0 };
    songs[numSongs++] = (Song) {.title = "Stairway to Heaven",.artist = "Led Zeppelin",.genre = "Rock",.year = 1971,.duration = 420.0 };
    songs[numSongs++] = (Song) {.title = "Billie Jean",.artist = "Michael Jackson",.genre = "Pop",.year = 1982,.duration = 251.0 };

    // Sort the songs by title
    qsort(songs, numSongs, sizeof(Song), compareSongs);

    // Print the sorted list of songs
    for (int i = 0; i < numSongs; i++) {
        printSong(songs[i]);
    }

    // Search for a song
    char title[50];
    printf("Enter a song title to search for: ");
    scanf("%s", title);
    searchSong(songs, numSongs, title);

    return 0;
}