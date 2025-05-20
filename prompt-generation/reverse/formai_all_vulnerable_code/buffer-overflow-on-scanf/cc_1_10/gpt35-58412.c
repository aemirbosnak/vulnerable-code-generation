//FormAI DATASET v1.0 Category: Music Library Management System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define struct for Library
typedef struct music_library {
    char artist[50];
    char album[50];
    int release_year;
    float rating;
} MusicLibrary;

// Function definitions
void add_song(MusicLibrary *, int *);
void delete_song(MusicLibrary *, int *);
void search_song(MusicLibrary *, int *);
void display_library(MusicLibrary *, int *);
void sort_library(MusicLibrary *, int *);
void modify_rating(MusicLibrary *, int *);

int main() {
    int count = 0, option;
    MusicLibrary library[100];

    printf("*** Welcome to the Shape-Shifting Music Library Management System ***\n");

    do {
        printf("\nEnter an option:\n");
        printf("1. Add a Song\n");
        printf("2. Delete a Song\n");
        printf("3. Search for a Song\n");
        printf("4. Display Music Library\n");
        printf("5. Sort Music Library\n");
        printf("6. Modify Rating\n");
        printf("7. Exit\n");
        scanf("%d", &option);

        switch(option) {
            case 1:
                add_song(library, &count);
                break;
            case 2:
                delete_song(library, &count);
                break;
            case 3:
                search_song(library, &count);
                break;
            case 4:
                display_library(library, &count);
                break;
            case 5:
                sort_library(library, &count);
                break;
            case 6:
                modify_rating(library, &count);
                break;
            case 7:
                printf("\nThank you for using the Music Library Management System.\n");
                exit(0);
                break;
            default:
                printf("\nInvalid option!\n");
                break;
        }
    } while (true);

    return 0;
}

void add_song(MusicLibrary *library, int *count) {
    printf("\nEnter the music details:\n");
    printf("- Artist: ");
    scanf(" %[^\n]s", library[*count].artist);
    printf("- Album: ");
    scanf(" %[^\n]s", library[*count].album);
    printf("- Release Year: ");
    scanf("%d", &library[*count].release_year);
    printf("- Rating (out of 5): ");
    scanf("%f", &library[*count].rating);

    printf("\nSong added successfully!\n");
    *count += 1;
}

void delete_song(MusicLibrary *library, int *count) {
    char artist_name[50];
    printf("\nEnter the artist name to be deleted: ");
    scanf(" %[^\n]s", artist_name);

    for (int i = 0; i < *count; i++) {
        if (strcmp(library[i].artist, artist_name) == 0) {
            for (int j = i; j < *count-1; j++) {
                strcpy(library[j].artist, library[j+1].artist);
                strcpy(library[j].album, library[j+1].album);
                library[j].release_year = library[j+1].release_year;
                library[j].rating = library[j+1].rating;
            }
            *count -= 1;
            printf("\nSong deleted successfully!\n");
            return;
        }
    }

    printf("\nSong not found!\n");
}

void search_song(MusicLibrary *library, int *count) {
    char artist_name[50];
    printf("\nEnter the artist name to be searched: ");
    scanf(" %[^\n]s", artist_name);

    for (int i = 0; i < *count; i++) {
        if (strcmp(library[i].artist, artist_name) == 0) {
            printf("\nMusic details:\n");
            printf("- Artist: %s\n", library[i].artist);
            printf("- Album: %s\n", library[i].album);
            printf("- Release Year: %d\n", library[i].release_year);
            printf("- Rating: %.2f\n", library[i].rating);
            return;
        }
    }

    printf("\nSong not found!\n");
}

void display_library(MusicLibrary *library, int *count) {
    if (*count == 0) {
        printf("\nNo songs found!\n");
        return;
    }

    printf("\nMusic Library:\n");
    printf("| %-20s | %-20s | %-10s | %-10s |\n", "Artist", "Album", "Year", "Rating");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < *count; i++) {
        printf("| %-20s | %-20s | %-10d | %-10.2f |\n", library[i].artist, library[i].album, library[i].release_year, library[i].rating);
    }
}

void sort_library(MusicLibrary *library, int *count) {
    if (*count == 0) {
        printf("\nNo songs found!\n");
        return;
    }

    int i, j;
    for (i = 0; i < *count-1; i++) {   
        for (j = 0; j < *count-i-1; j++) {
            if (strcmp(library[j].artist, library[j+1].artist) > 0 ) {
                MusicLibrary temp = library[j];
                library[j] = library[j+1];
                library[j+1] = temp;
            }
        }
    }

    printf("\nMusic Library sorted successfully!\n");
}

void modify_rating(MusicLibrary *library, int *count) {
    char artist_name[50];
    printf("\nEnter the artist name to modify the rating: ");
    scanf(" %[^\n]s", artist_name);

    for (int i = 0; i < *count; i++) {
        if (strcmp(library[i].artist, artist_name) == 0) {
            printf("\nEnter the new rating: ");
            scanf("%f", &library[i].rating);
            printf("\nRating modified successfully!\n");
            return;
        }
    }

    printf("\nSong not found!\n");
}