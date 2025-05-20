//Falcon2-11B DATASET v1.0 Category: Music Library Management System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structures for Music Library management
typedef struct {
    char name[50];
    int rating;
} Music;

typedef struct {
    char title[50];
    Music artist;
    int year;
} Album;

// Define global variables
Music library[100];
int num_songs = 0;
int num_artists = 0;

int main() {
    // Read in the number of songs and artists
    printf("Enter the number of songs: ");
    scanf("%d", &num_songs);
    printf("Enter the number of artists: ");
    scanf("%d", &num_artists);

    // Allocate memory for the library
    for (int i = 0; i < num_songs; i++) {
        library[i].name[0] = '\0';
        library[i].rating = 0;
    }
    for (int i = 0; i < num_artists; i++) {
        library[i].rating = 0;
    }

    // Read in the songs and artists
    printf("Enter the names of the songs: ");
    for (int i = 0; i < num_songs; i++) {
        scanf("%s", library[i].name);
    }
    printf("Enter the names of the artists: ");
    for (int i = 0; i < num_artists; i++) {
        scanf("%s", library[i].name);
    }

    // Calculate the average rating
    int total_rating = 0;
    for (int i = 0; i < num_songs; i++) {
        total_rating += library[i].rating;
    }
    printf("Average rating: %.2f\n", (double)total_rating / num_songs);

    // Print out the library
    printf("Library:\n");
    for (int i = 0; i < num_songs; i++) {
        printf("%s, Rating: %d\n", library[i].name, library[i].rating);
    }

    // Free the memory
    for (int i = 0; i < num_songs; i++) {
        free(library[i].name);
    }
    free(library);

    return 0;
}