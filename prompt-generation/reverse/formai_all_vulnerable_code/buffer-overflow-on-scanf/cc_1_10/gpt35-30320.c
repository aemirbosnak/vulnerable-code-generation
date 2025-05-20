//FormAI DATASET v1.0 Category: Music Library Management System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of albums in the library
#define MAX_ALBUMS 1000

struct Album {
    char title[50];
    char artist[50];
    char genre[20];
    int year;
};

int num_albums = 0;
struct Album library[MAX_ALBUMS];

// Function to add an album to the library
void add_album(char* title, char* artist, char* genre, int year) {
    if (num_albums >= MAX_ALBUMS) {
        printf("Error: Library is full.\n");
        return;
    }
    struct Album new_album;
    strcpy(new_album.title, title);
    strcpy(new_album.artist, artist);
    strcpy(new_album.genre, genre);
    new_album.year = year;
    library[num_albums] = new_album;
    num_albums++;
}

// Function to search the library for albums by a particular artist
void search_by_artist(char* artist) {
    int found = 0;
    for (int i = 0; i < num_albums; i++) {
        if (strcmp(library[i].artist, artist) == 0) {
            printf("%s by %s (%s, %d)\n", library[i].title, library[i].artist, library[i].genre, library[i].year);
            found = 1;
        }
    }
    if (!found) {
        printf("No albums found by %s.\n", artist);
    }
}

// Function to calculate the average year of all albums in the library
float average_year() {
    int total = 0;
    for (int i = 0; i < num_albums; i++) {
        total += library[i].year;
    }
    return (float)total / (float)num_albums;
}

// Main function to manage the library
int main() {
    printf("Welcome to the Music Library Management System.\n");
    printf("Please enter a command:\n");

    while (1) {
        char command[10];
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            char title[50], artist[50], genre[20];
            int year;
            printf("Enter the album title: ");
            scanf("%s", title);
            printf("Enter the album artist: ");
            scanf("%s", artist);
            printf("Enter the album genre: ");
            scanf("%s", genre);
            printf("Enter the album year: ");
            scanf("%d", &year);
            add_album(title, artist, genre, year);
            printf("Album added.\n");
        }

        else if (strcmp(command, "search") == 0) {
            char artist[50];
            printf("Enter the artist name: ");
            scanf("%s", artist);
            search_by_artist(artist);
        }

        else if (strcmp(command, "average") == 0) {
            float avg_year = average_year();
            printf("The average year of all albums in the library is %.2f.\n", avg_year);
        }

        else if (strcmp(command, "exit") == 0) {
            printf("Exiting Music Library Management System...\n");
            return 0;
        }

        else {
            printf("Invalid command. Please try again.\n");
        }
    }
}