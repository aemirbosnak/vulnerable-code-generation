//FormAI DATASET v1.0 Category: Music Library Management System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 1000

// Data structure to represent a song
struct Song {
    char title[50];
    char artist[50];
    char genre[20];
    int year;
};

struct Library {
    struct Song songs[MAX_SONGS];
    int count;
};

// Functions to manage the library
void add_song(struct Library *library);
void print_library(struct Library *library);
struct Song make_song();
void print_song(struct Song song);

int main() {
    struct Library library;
    library.count = 0;

    int option;
    do {
        printf("\n--- C Music Library Management System ---\n");
        printf("1. Add Song\n");
        printf("2. Print Library\n");
        printf("3. Exit\n");

        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                add_song(&library);
                break;
            case 2:
                print_library(&library);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option.\n");
                break;
        }

    } while (option != 3);

    return 0;
}

void add_song(struct Library *library) {
    if (library->count >= MAX_SONGS) {
        printf("Library is full.\n");
        return;
    }

    struct Song song = make_song();
    library->songs[library->count++] = song;

    printf("'%s' by %s added to library.\n", song.title, song.artist);
}

void print_library(struct Library *library) {
    if (library->count == 0) {
        printf("Library is empty.\n");
        return;
    }

    printf("Library:\n");
    for (int i = 0; i < library->count; i++) {
        printf("%d. ", i+1);
        print_song(library->songs[i]);
    }
}

struct Song make_song() {
    struct Song song;

    printf("Enter song title: ");
    scanf("%s", song.title);

    printf("Enter artist: ");
    scanf("%s", song.artist);

    printf("Enter genre: ");
    scanf("%s", song.genre);

    printf("Enter year: ");
    scanf("%d", &song.year);

    return song;
}

void print_song(struct Song song) {
    printf("'%s' by %s (%s, %d)\n", song.title, song.artist, song.genre, song.year);
}