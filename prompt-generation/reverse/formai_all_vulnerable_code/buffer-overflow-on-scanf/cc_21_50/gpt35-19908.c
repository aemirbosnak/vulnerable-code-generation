//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 50
#define MAX_ARTIST_LENGTH 50
#define MAX_ALBUM_LENGTH 50
#define MAX_TRACKS 20

/* Structure to store album information */
struct Album {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    char name[MAX_ALBUM_LENGTH];
    int year;
    int num_tracks;
    char tracks[MAX_TRACKS][MAX_TITLE_LENGTH];
};

int main() {
    struct Album library[100];
    int n = 0; // Number of albums in the library
    int choice;

    do {
        printf("Welcome to C Music Library Management System!\n");
        printf("1. Add a new album\n");
        printf("2. View all albums\n");
        printf("3. Search for an album by title\n");
        printf("4. Search for an album by artist\n");
        printf("5. Search for an album by year\n");
        printf("6. Delete an album\n");
        printf("7. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: // Add a new album
                if (n < 100) { // Check if there is space in the library
                    struct Album album;
                    printf("Please enter album name: ");
                    scanf("%s", album.name);
                    printf("Please enter artist: ");
                    scanf("%s", album.artist);
                    printf("Please enter album title: ");
                    scanf("%s", album.title);
                    printf("Please enter year: ");
                    scanf("%d", &album.year);
                    printf("Please enter number of tracks: ");
                    scanf("%d", &album.num_tracks);
                    for (int i = 0; i < album.num_tracks; i++) {
                        printf("Please enter name of track %d: ", i+1);
                        scanf("%s", album.tracks[i]);
                    }
                    library[n++] = album; // Add album to library
                } else {
                    printf("The library is full.\n");
                }
                break;
            case 2: // View all albums
                if (n == 0) { // Check if library is empty
                    printf("The library is empty.\n");
                } else {
                    printf("Albums in the library:\n");
                    for (int i = 0; i < n; i++) {
                        printf("%d. %s by %s (%d)\n", i+1, library[i].title,
                            library[i].artist, library[i].year);
                    }
                }
                break;
            case 3: // Search for an album by title
                if (n == 0) { // Check if library is empty
                    printf("The library is empty.\n");
                } else {
                    char search_title[MAX_TITLE_LENGTH];
                    printf("Please enter album title: ");
                    scanf("%s", search_title);
                    int found = 0;
                    for (int i = 0; i < n; i++) {
                        if (strcmp(search_title, library[i].title) == 0) {
                            printf("%s by %s (%d)\n", library[i].title,
                                library[i].artist, library[i].year);
                            for (int j = 0; j < library[i].num_tracks; j++) {
                                printf("%d. %s\n", j+1, library[i].tracks[j]);
                            }
                            found = 1;
                            break;
                        }
                    }
                    if (!found) {
                        printf("Album not found.\n");
                    }
                }
                break;
            case 4: // Search for an album by artist
                if (n == 0) { // Check if library is empty
                    printf("The library is empty.\n");
                } else {
                    char search_artist[MAX_ARTIST_LENGTH];
                    printf("Please enter artist: ");
                    scanf("%s", search_artist);
                    int found = 0;
                    for (int i = 0; i < n; i++) {
                        if (strcmp(search_artist, library[i].artist) == 0) {
                            printf("%s by %s (%d)\n", library[i].title,
                                library[i].artist, library[i].year);
                            for (int j = 0; j < library[i].num_tracks; j++) {
                                printf("%d. %s\n", j+1, library[i].tracks[j]);
                            }
                            found = 1;
                        }
                    }
                    if (!found) {
                        printf("Album not found.\n");
                    }
                }
                break;
            case 5: // Search for an album by year
                if (n == 0) { // Check if library is empty
                    printf("The library is empty.\n");
                } else {
                    int search_year;
                    printf("Please enter year: ");
                    scanf("%d", &search_year);
                    int found = 0;
                    for (int i = 0; i < n; i++) {
                        if (search_year == library[i].year) {
                            printf("%s by %s (%d)\n", library[i].title,
                                library[i].artist, library[i].year);
                            for (int j = 0; j < library[i].num_tracks; j++) {
                                printf("%d. %s\n", j+1, library[i].tracks[j]);
                            }
                            found = 1;
                        }
                    }
                    if (!found) {
                        printf("Album not found.\n");
                    }
                }
                break;
            case 6: // Delete an album
                if (n == 0) { // Check if library is empty
                    printf("The library is empty.\n");
                } else {
                    char delete_title[MAX_TITLE_LENGTH];
                    printf("Please enter album title: ");
                    scanf("%s", delete_title);
                    int found = 0;
                    for (int i = 0; i < n; i++) {
                        if (strcmp(delete_title, library[i].title) == 0) {
                            printf("%s by %s (%d) has been deleted.\n",
                                library[i].title, library[i].artist, library[i].year);
                            for (int j = i; j < n-1; j++) {
                                library[j] = library[j+1];
                            }
                            n--;
                            found = 1;
                            break;
                        }
                    }
                    if (!found) {
                        printf("Album not found.\n");
                    }
                }
                break;
            case 7: // Exit
                printf("Thank you for using C Music Library Management System.\n");
                break;
            default: // Invalid choice
                printf("Invalid choice.\n");
        }
    } while (choice != 7);

    return 0;
}