//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure definition for Music Album
typedef struct album {
    char album_name[100];   // Album name
    char artist_name[100];  // Artist name
    int release_year;       // Year of release
    float price;            // Price of album
} Album;

// Function to add a new album to the library
void add_new_album(Album *library, int *num_albums) {
    printf("Enter the name of the album: ");
    scanf("%s", library[*num_albums].album_name);
    printf("Enter the name of the artist: ");
    scanf("%s", library[*num_albums].artist_name);
    printf("Enter the release year: ");
    scanf("%d", &library[*num_albums].release_year);
    printf("Enter the price of the album: ");
    scanf("%f", &library[*num_albums].price);
    *num_albums = *num_albums + 1;
}

// Function to print all the details of a specific album
void print_album_details(Album *album) {
    printf("Album Name: %s\n", album->album_name);
    printf("Artist Name: %s\n", album->artist_name);
    printf("Year of Release: %d\n", album->release_year);
    printf("Price: $%.2f\n", album->price);
}

// Function to search for an album by name and print its details
void search_by_name(Album *library, int num_albums) {
    char album_name[100];
    printf("Enter the name of the album to be searched: ");
    scanf("%s", album_name);
    int flag = 0;
    for (int i = 0; i < num_albums; i++) {
        if (strcmp(library[i].album_name, album_name) == 0) {
            print_album_details(&library[i]);
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        printf("Album not found in library!\n");
    }
}

// Function to search for an album by artist name and print its details
void search_by_artist_name(Album *library, int num_albums) {
    char artist_name[100];
    printf("Enter the name of the artist to be searched: ");
    scanf("%s", artist_name);
    int flag = 0;
    for (int i = 0; i < num_albums; i++) {
        if (strcmp(library[i].artist_name, artist_name) == 0) {
            print_album_details(&library[i]);
            flag = 1;
        }
    }
    if (flag == 0) {
        printf("Album not found in library!\n");
    }
}

// Function to view all albums in the library
void view_all_albums(Album *library, int num_albums) {
    printf("Total number of albums in the library: %d\n", num_albums);
    for (int i = 0; i < num_albums; i++) {
        printf("Album %d:\n", i+1);
        print_album_details(&library[i]);
    }
}

int main() {
    Album library[100];  // Maximum 100 albums can be stored in the library
    int num_albums = 0;  // Current number of albums in the library
    int choice;
    while (1) {
        // Display menu options
        printf("Menu Options:\n");
        printf("1. Add new album to the library\n");
        printf("2. Search for an album by name\n");
        printf("3. Search for an album by artist name\n");
        printf("4. View all albums in the library\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Execute the corresponding function based on user choice
        switch (choice) {
            case 1:
                add_new_album(library, &num_albums);
                break;
            case 2:
                search_by_name(library, num_albums);
                break;
            case 3:
                search_by_artist_name(library, num_albums);
                break;
            case 4:
                view_all_albums(library, num_albums);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}