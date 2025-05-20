//FormAI DATASET v1.0 Category: Music Library Management System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing album information
struct album {
    char title[50];
    char artist[50];
    int year;
    int rating;
};

// Function for adding a new album to the library
void add_album(struct album *library, int *num_albums) {
    printf("Enter album title: ");
    scanf("%s", library[*num_albums].title);

    printf("Enter artist name: ");
    scanf("%s", library[*num_albums].artist);

    printf("Enter release year: ");
    scanf("%d", &library[*num_albums].year);

    printf("Enter rating (out of 10): ");
    scanf("%d", &library[*num_albums].rating);

    (*num_albums)++;
}

// Function for searching for an album by title or artist
void search_albums(struct album *library, int num_albums) {
    char search_query[50];
    printf("Enter search query: ");
    scanf("%s", search_query);

    printf("Search results:\n");
    for (int i = 0; i < num_albums; i++) {
        if (strstr(library[i].title, search_query) != NULL ||
            strstr(library[i].artist, search_query) != NULL) {
            printf("%s - %s (%d) Rated: %d/10\n", library[i].artist, library[i].title, library[i].year, library[i].rating);
        }
    }
}

// Function for displaying all albums in the library
void display_all(struct album *library, int num_albums) {
    printf("Albums in library (%d total):\n", num_albums);
    for (int i = 0; i < num_albums; i++) {
        printf("%s - %s (%d) Rated: %d/10\n", library[i].artist, library[i].title, library[i].year, library[i].rating);
    }
}

int main() {
    int num_albums = 0;
    struct album library[100];

    while (1) {
        printf("\n--- MUSIC LIBRARY MANAGEMENT SYSTEM ---\n");
        printf("1. Add a new album\n");
        printf("2. Search for an album\n");
        printf("3. Display all albums\n");
        printf("4. Exit\n");
        printf("Enter option: ");

        int option;
        scanf("%d", &option);

        switch (option) {
            case 1:
                add_album(library, &num_albums);
                break;
            case 2:
                search_albums(library, num_albums);
                break;
            case 3:
                display_all(library, num_albums);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}