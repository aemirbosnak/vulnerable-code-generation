//Falcon2-11B DATASET v1.0 Category: Music Library Management System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50

typedef struct Album {
    char artist[MAX_LENGTH];
    char album[MAX_LENGTH];
    char genre[MAX_LENGTH];
    int year;
    int tracks;
    int rating;
} Album;

int main() {
    Album album1, album2, album3;
    char input;

    // Creating and initializing the albums
    strcpy(album1.artist, "Artist 1");
    strcpy(album1.album, "Album 1");
    strcpy(album1.genre, "Genre 1");
    album1.year = 2020;
    album1.tracks = 10;
    album1.rating = 4;

    strcpy(album2.artist, "Artist 2");
    strcpy(album2.album, "Album 2");
    strcpy(album2.genre, "Genre 2");
    album2.year = 2021;
    album2.tracks = 12;
    album2.rating = 3;

    strcpy(album3.artist, "Artist 3");
    strcpy(album3.album, "Album 3");
    strcpy(album3.genre, "Genre 3");
    album3.year = 2022;
    album3.tracks = 8;
    album3.rating = 5;

    // Displaying the albums
    printf("Album 1: %s - %s (%d) - %d tracks - Rating: %d\n", album1.artist, album1.album, album1.year, album1.tracks, album1.rating);
    printf("Album 2: %s - %s (%d) - %d tracks - Rating: %d\n", album2.artist, album2.album, album2.year, album2.tracks, album2.rating);
    printf("Album 3: %s - %s (%d) - %d tracks - Rating: %d\n", album3.artist, album3.album, album3.year, album3.tracks, album3.rating);

    // User input
    printf("Enter an option: ");
    scanf(" %c", &input);

    if (input == '1') {
        printf("Enter the artist: ");
        scanf(" %s", album1.artist);
        printf("Enter the album: ");
        scanf(" %s", album1.album);
        printf("Enter the genre: ");
        scanf(" %s", album1.genre);
        printf("Enter the year: ");
        scanf(" %d", &album1.year);
        printf("Enter the number of tracks: ");
        scanf(" %d", &album1.tracks);
        printf("Enter the rating: ");
        scanf(" %d", &album1.rating);

        printf("Album 1 updated:\n");
        printf("Artist: %s\n", album1.artist);
        printf("Album: %s\n", album1.album);
        printf("Genre: %s\n", album1.genre);
        printf("Year: %d\n", album1.year);
        printf("Tracks: %d\n", album1.tracks);
        printf("Rating: %d\n\n", album1.rating);
    } else if (input == '2') {
        printf("Enter the artist: ");
        scanf(" %s", album2.artist);
        printf("Enter the album: ");
        scanf(" %s", album2.album);
        printf("Enter the genre: ");
        scanf(" %s", album2.genre);
        printf("Enter the year: ");
        scanf(" %d", &album2.year);
        printf("Enter the number of tracks: ");
        scanf(" %d", &album2.tracks);
        printf("Enter the rating: ");
        scanf(" %d", &album2.rating);

        printf("Album 2 updated:\n");
        printf("Artist: %s\n", album2.artist);
        printf("Album: %s\n", album2.album);
        printf("Genre: %s\n", album2.genre);
        printf("Year: %d\n", album2.year);
        printf("Tracks: %d\n", album2.tracks);
        printf("Rating: %d\n\n", album2.rating);
    } else if (input == '3') {
        printf("Enter the artist: ");
        scanf(" %s", album3.artist);
        printf("Enter the album: ");
        scanf(" %s", album3.album);
        printf("Enter the genre: ");
        scanf(" %s", album3.genre);
        printf("Enter the year: ");
        scanf(" %d", &album3.year);
        printf("Enter the number of tracks: ");
        scanf(" %d", &album3.tracks);
        printf("Enter the rating: ");
        scanf(" %d", &album3.rating);

        printf("Album 3 updated:\n");
        printf("Artist: %s\n", album3.artist);
        printf("Album: %s\n", album3.album);
        printf("Genre: %s\n", album3.genre);
        printf("Year: %d\n", album3.year);
        printf("Tracks: %d\n", album3.tracks);
        printf("Rating: %d\n\n", album3.rating);
    } else {
        printf("Invalid option.\n");
    }

    return 0;
}