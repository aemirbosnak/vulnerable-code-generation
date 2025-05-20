//FormAI DATASET v1.0 Category: Music Library Management System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 50
#define LIBRARY_CAPACITY 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_TITLE_LENGTH];
    int year;
    int num_tracks;
    float rating;
} Album;

int num_albums;
Album library[LIBRARY_CAPACITY];


// Function prototypes
int menu();
int add_album();
int delete_album();
int view_album();
void view_all();

int main() {
    // Initialize the library
    num_albums = 0;

    int choice = menu();

    while (choice != 5) {
        switch (choice) {
            case 1: add_album();
                break;
            case 2: delete_album();
                break;
            case 3: view_album();
                break;
            case 4: view_all();
                break;
            default: printf("Invalid choice. Please try again.\n");
        }

        choice = menu();
    }

    printf("Thank you for using the Music Library Management System.\n");
    return 0;
}


// Function definitions
int menu() {
    printf("\n");
    printf("Welcome to the Music Library Management System.\n");
    printf("Please select an option:\n");
    printf("1. Add an album\n");
    printf("2. Delete an album\n");
    printf("3. View an album\n");
    printf("4. View all albums\n");
    printf("5. Quit\n");
    printf("> ");

    int choice;
    scanf("%d", &choice);

    return choice;
}

int add_album() {
    if (num_albums == LIBRARY_CAPACITY) {
        printf("Sorry, the music library is already full.\n");
        return 0;
    }

    Album new_album;
    printf("Please enter the album's title: ");
    scanf("%s", new_album.title);

    printf("Please enter the album's artist: ");
    scanf("%s", new_album.artist);

    printf("Please enter the album's release year: ");
    scanf("%d", &new_album.year);

    printf("Please enter the number of tracks on the album: ");
    scanf("%d", &new_album.num_tracks);

    printf("Please enter the album's rating (out of 10): ");
    scanf("%f", &new_album.rating);

    library[num_albums] = new_album;
    num_albums++;

    printf("Album added successfully.\n");

    return 1;
}

int delete_album() {
    if (num_albums == 0) {
        printf("Sorry, there are no albums in the music library to delete.\n");
        return 0;
    }

    char title[MAX_TITLE_LENGTH];

    printf("Please enter the title of the album you want to delete: ");
    scanf("%s", title);

    int i;
    for (i = 0; i < num_albums; i++) {
        if (strcmp(library[i].title, title) == 0) {
            // Found the album
            int j;
            for (j = i; j < num_albums - 1; j++) {
                library[j] = library[j+1]; // Shift all the albums down by one
            }
            num_albums--;
            printf("Album deleted successfully.\n");
            return 1;
        }
    }

    printf("Sorry, the album with title '%s' was not found.\n", title);

    return 0;
}

int view_album() {
    if (num_albums == 0) {
        printf("Sorry, there are no albums in the music library to view.\n");
        return 0;
    }

    char title[MAX_TITLE_LENGTH];

    printf("Please enter the title of the album you want to view: ");
    scanf("%s", title);

    int i;
    for (i = 0; i < num_albums; i++) {
        if (strcmp(library[i].title, title) == 0) {
            // Found the album
            printf("Title: %s\n", library[i].title);
            printf("Artist: %s\n", library[i].artist);
            printf("Release Year: %d\n", library[i].year);
            printf("Number of Tracks: %d\n", library[i].num_tracks);
            printf("Rating: %.1f/10\n", library[i].rating);
            return 1;
        }
    }

    printf("Sorry, the album with title '%s' was not found.\n", title);

    return 0;
}

void view_all() {
    if (num_albums == 0) {
        printf("Sorry, there are no albums in the music library to view.\n");
        return;
    }

    printf("Title\t\tArtist\t\tYear\tTracks\tRating\n"); // Table header

    int i;
    for (i = 0; i < num_albums; i++) {
        printf("%-15s%-15s%-8d%-8d%.1f/10\n", library[i].title,
                                                library[i].artist,
                                                library[i].year,
                                                library[i].num_tracks,
                                                library[i].rating);
    }
}