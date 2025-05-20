//MISTRAL-7B DATASET v1.0 Category: Music Library Management System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLES 100
#define MAX_ARTISTS 50
#define MAX_TRACKS 20

typedef struct Song {
    char title[MAX_TITLES];
    char artist[MAX_ARTISTS];
    int track_number;
} Song;

typedef struct Library {
    Song songs[MAX_TRACKS];
    int num_songs;
} Library;

void print_menu();
void add_song(Library *library);
void remove_song(Library *library);
void search_song(Library *library);
void print_library(Library library);

int main() {
    Library my_library = {0};

    int choice;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_song(&my_library);
                break;
            case 2:
                remove_song(&my_library);
                break;
            case 3:
                search_song(&my_library);
                break;
            case 0:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        print_library(my_library);
    }

    return 0;
}

void print_menu() {
    printf("\nMusic Library Management System\n");
    printf("---------------------------------\n");
    printf("1. Add a Song\n");
    printf("2. Remove a Song\n");
    printf("3. Search a Song\n");
    printf("0. Exit\n");
}

void add_song(Library *library) {
    if (library->num_songs >= MAX_TRACKS) {
        printf("Maximum number of songs reached.\n");
        return;
    }

    printf("Enter title: ");
    scanf("%s", library->songs[library->num_songs].title);

    printf("Enter artist: ");
    scanf("%s", library->songs[library->num_songs].artist);

    printf("Enter track number: ");
    scanf("%d", &library->songs[library->num_songs].track_number);

    library->num_songs++;
}

void remove_song(Library *library) {
    int index;
    char title[MAX_TITLES];

    printf("Enter title of the song to remove: ");
    scanf("%s", title);

    for (index = 0; index < library->num_songs; index++) {
        if (strcmp(title, library->songs[index].title) == 0) {
            break;
        }
    }

    if (index >= library->num_songs) {
        printf("Song not found.\n");
        return;
    }

    for (int i = index; i < library->num_songs - 1; i++) {
        library->songs[i] = library->songs[i + 1];
    }

    library->num_songs--;
}

void search_song(Library *library) {
    char title[MAX_TITLES];
    int index = -1;

    printf("Enter title of the song to search: ");
    scanf("%s", title);

    for (int i = 0; i < library->num_songs; i++) {
        if (strcmp(title, library->songs[i].title) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Song not found.\n");
        return;
    }

    printf("Title: %s\n", library->songs[index].title);
    printf("Artist: %s\n", library->songs[index].artist);
    printf("Track Number: %d\n", library->songs[index].track_number);
}

void print_library(Library library) {
    printf("\nLibrary:\n");
    printf("---------------------------------\n");

    for (int i = 0; i < library.num_songs; i++) {
        printf("| %-20s | %-20s | %-10d |\n", library.songs[i].title, library.songs[i].artist, library.songs[i].track_number);
    }
}