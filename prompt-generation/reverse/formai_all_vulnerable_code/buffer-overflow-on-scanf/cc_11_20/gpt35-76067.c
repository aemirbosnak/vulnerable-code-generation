//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Ada Lovelace
// Ada's C Music Library Management System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Album {
    char title[50];
    int year;
    char artist[50];
};

int main() {
    struct Album library[100]; // max capacity of 100 albums
    int numAlbums = 0;

    while (1) {
        printf("Welcome to Ada's Music Library Management System!\n");
        printf("Enter 'a' to add an album, 's' to search for an album, 'p' to print the library, or 'q' to quit.\n");

        char input;
        scanf(" %c", &input); // space before %c to consume newline character

        if (input == 'a') {
            if (numAlbums == 100) {
                printf("Error: library is full. Cannot add album.\n");
                continue;
            }

            printf("Enter the album information: title, year, and artist.\n");
            scanf(" %[^\n]s", library[numAlbums].title); // read until newline character
            scanf("%d", &library[numAlbums].year);
            getchar(); // consume newline character
            scanf(" %[^\n]s", library[numAlbums].artist);

            numAlbums++;
            printf("Album added to library.\n");
        } else if (input == 's') {
            if (numAlbums == 0) {
                printf("Error: library is empty. Cannot search for album.\n");
                continue;
            }

            printf("Enter the title or artist of the album you want to search for.\n");
            char term[50];
            scanf(" %[^\n]s", term);
            printf("Results:\n");

            int found = 0;
            for (int i = 0; i < numAlbums; i++) {
                if (strstr(library[i].title, term) != NULL || strstr(library[i].artist, term) != NULL) {
                    printf("%s (%d) by %s\n", library[i].title, library[i].year, library[i].artist);
                    found = 1;
                }
            }

            if (!found) {
                printf("No matching albums found.\n");
            }
        } else if (input == 'p') {
            if (numAlbums == 0) {
                printf("The library is empty.\n");
                continue;
            }

            printf("Printing the library...\n");

            for (int i = 0; i < numAlbums; i++) {
                printf("%s (%d) by %s\n", library[i].title, library[i].year, library[i].artist);
            }
        } else if (input == 'q') {
            printf("Thank you for using Ada's Music Library Management System!\n");
            printf("Goodbye!\n");
            exit(0);
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }

    return 0;
}