//FormAI DATASET v1.0 Category: Music Library Management System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// struct for storing information on a single music track
typedef struct {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    int track_num;
} MusicTrack;

// function for adding a new music track to the library
void addTrack(MusicTrack* library, int* num_tracks) {
    printf("\nAdding a new track to the library...");
    printf("\nEnter the track title: ");
    scanf("%s", library[*num_tracks].title);
    printf("Enter the artist name: ");
    scanf("%s", library[*num_tracks].artist);
    printf("Enter the album name: ");
    scanf("%s", library[*num_tracks].album);
    printf("Enter the year of release: ");
    scanf("%d", &library[*num_tracks].year);
    printf("Enter the track number: ");
    scanf("%d", &library[*num_tracks].track_num);

    printf("\nTrack added successfully!\n");
    (*num_tracks)++;
}

// function for searching for a track in the library
void searchTrack(MusicTrack* library, int num_tracks) {
    printf("\nSearching for a track in the library...");
    char search_title[50];
    printf("\nEnter the track title: ");
    scanf("%s", search_title);

    for (int i = 0; i < num_tracks; i++) {
        if (strcmp(library[i].title, search_title) == 0) {
            printf("\nTrack found!\n");
            printf("Title: %s\n", library[i].title);
            printf("Artist: %s\n", library[i].artist);
            printf("Album: %s\n", library[i].album);
            printf("Year of release: %d\n", library[i].year);
            printf("Track number: %d\n", library[i].track_num);
            return;
        }
    }

    printf("\nTrack not found :(\n");
}

// function for printing all tracks in the library
void printLibrary(MusicTrack* library, int num_tracks) {
    printf("\nPrinting all tracks in the library...\n");

    for (int i = 0; i < num_tracks; i++) {
        printf("Title: %s\n", library[i].title);
        printf("Artist: %s\n", library[i].artist);
        printf("Album: %s\n", library[i].album);
        printf("Year of release: %d\n", library[i].year);
        printf("Track number: %d\n\n", library[i].track_num);
    }
}

int main() {
    int option;
    int num_tracks = 0;
    MusicTrack library[100];

    while (true) {
        printf("\n===== C Music Library Management System =====");
        printf("\n1 - Add a new track");
        printf("\n2 - Search for a track");
        printf("\n3 - Print library");
        printf("\n4 - Exit");
        
        printf("\n\nEnter an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                addTrack(library, &num_tracks);
                break;
            case 2:
                searchTrack(library, num_tracks);
                break;
            case 3:
                printLibrary(library, num_tracks);
                break;
            case 4:
                printf("\nExiting... Bye!\n");
                exit(0);
            default:
                printf("\nInvalid option. Try again!\n");
        }
    }

    return 0;
}