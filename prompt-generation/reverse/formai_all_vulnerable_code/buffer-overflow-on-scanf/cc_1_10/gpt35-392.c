//FormAI DATASET v1.0 Category: Music Library Management System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SONGS 100
#define MAX_TITLE_LENGTH 50
#define MAX_ARTIST_LENGTH 30
#define MAX_ALBUM_LENGTH 30

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    char album[MAX_ALBUM_LENGTH];
    int year;
    int track_number;
} song;

int menu();
void add_song(song[], int*);
void display_library(song[], int);
void search_library(song[], int);

int main() {
    song library[MAX_SONGS];
    int num_songs = 0;
    int choice;

    while (1) {
        choice = menu();

        switch(choice) {
            case 1:
                add_song(library, &num_songs);
                break;
            case 2:
                display_library(library, num_songs);
                break;
            case 3:
                search_library(library, num_songs);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Display the menu of options
int menu() {
    int choice;
    printf("-------Music Library Management System-------\n");
    printf("1. Add a song\n");
    printf("2. Display library\n");
    printf("3. Search library\n");
    printf("4. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Add a song to the library
void add_song(song library[], int *num_songs) {
    if (*num_songs == MAX_SONGS) {
        printf("Library is full.\n");
        return;
    }

    song s;
    printf("Enter the song title: ");
    scanf("%s", s.title);
    printf("Enter the artist name: ");
    scanf("%s", s.artist);
    printf("Enter the album name: ");
    scanf("%s", s.album);
    printf("Enter the year: ");
    scanf("%d", &s.year);
    printf("Enter the track number: ");
    scanf("%d", &s.track_number);

    library[*num_songs] = s;
    (*num_songs)++;
}

// Display the entire library
void display_library(song library[], int num_songs) {
    if (num_songs == 0) {
        printf("Library is empty.\n");
        return;
    }

    printf("%-50s | %-30s | %-30s | %-10s | %-15s\n",
           "Title", "Artist", "Album", "Year", "Track Number");
    printf("---------------------------------------------------------------------\n");

    for (int i = 0; i < num_songs; i++) {
        printf("%-50s | %-30s | %-30s | %-10d | %-15d\n",
               library[i].title, library[i].artist, library[i].album,
               library[i].year, library[i].track_number);
    }
}

// Search the library by title or artist
void search_library(song library[], int num_songs) {
    if (num_songs == 0) {
        printf("Library is empty.\n");
        return;
    }

    char term[MAX_TITLE_LENGTH];
    printf("Enter the search term: ");
    scanf("%s", term);

    int results = 0;
    printf("%-50s | %-30s | %-30s | %-10s | %-15s\n",
           "Title", "Artist", "Album", "Year", "Track Number");
    printf("---------------------------------------------------------------------\n");

    for (int i = 0; i < num_songs; i++) {
        if (strstr(library[i].title, term) || strstr(library[i].artist, term)) {
            printf("%-50s | %-30s | %-30s | %-10d | %-15d\n",
                   library[i].title, library[i].artist, library[i].album,
                   library[i].year, library[i].track_number);
            results++;
        }
    }

    if (results == 0) {
        printf("No matches found.\n");
    }
}