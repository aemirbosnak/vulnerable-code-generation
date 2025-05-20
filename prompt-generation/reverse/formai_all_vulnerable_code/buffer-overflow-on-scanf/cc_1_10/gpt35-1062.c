//FormAI DATASET v1.0 Category: Music Library Management System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 1000
#define MAX_TITLE_LENGTH 50
#define MAX_ARTIST_LENGTH 30

struct Song {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    int year;
};

struct Library {
    struct Song songs[MAX_SONGS];
    int num_songs;
};

void add_song(struct Library *lib) {
    struct Song new_song;
    printf("Enter the song title: ");
    fgets(new_song.title, MAX_TITLE_LENGTH, stdin);
    printf("Enter the artist name: ");
    fgets(new_song.artist, MAX_ARTIST_LENGTH, stdin);
    printf("Enter the release year: ");
    scanf("%d", &new_song.year);
    while (getchar() != '\n') {} // clear input buffer
    lib->songs[lib->num_songs++] = new_song;
    printf("\nSong added successfully!\n\n");
}

void remove_song(struct Library *lib) {
    if (lib->num_songs == 0) {
        printf("No songs in library!\n\n");
        return;
    }

    printf("Enter the index of the song to remove: ");
    int index;
    scanf("%d", &index);
    while (getchar() != '\n') {} // clear input buffer

    if (index < 0 || index >= lib->num_songs) {
        printf("Invalid index entered. No song removed.\n\n");
        return;
    }

    memmove(&lib->songs[index], &lib->songs[index+1], 
        sizeof(struct Song)*(lib->num_songs-index-1));
    lib->num_songs--;
    printf("\nSong removed successfully!\n\n");
}

void search_song(struct Library *lib) {
    if (lib->num_songs == 0) {
        printf("No songs in library!\n\n");
        return;
    }

    printf("Enter part of the song title or artist name to search: ");
    char search_term[MAX_TITLE_LENGTH+MAX_ARTIST_LENGTH];
    fgets(search_term, MAX_TITLE_LENGTH+MAX_ARTIST_LENGTH, stdin);

    int results = 0;
    printf("\nSearch results:\n");
    for (int i = 0; i < lib->num_songs; i++) {
        if (strstr(lib->songs[i].title, search_term) != NULL || 
            strstr(lib->songs[i].artist, search_term) != NULL) {
            printf("%d. %s - %s (%d)\n", i, lib->songs[i].title, 
                lib->songs[i].artist, lib->songs[i].year);
            results++;
        }
    }

    if (results == 0) {
        printf("No results found.\n\n");
    } else {
        printf("Found %d result(s).\n\n", results);
    }
}

void print_library(struct Library *lib) {
    if (lib->num_songs == 0) {
        printf("No songs in library!\n\n");
        return;
    }

    printf("Library contents:\n");
    for (int i = 0; i < lib->num_songs; i++) {
        printf("%d. %s - %s (%d)\n", i, lib->songs[i].title, 
            lib->songs[i].artist, lib->songs[i].year);
    }
    printf("\n");
}

int main() {
    struct Library my_library;
    my_library.num_songs = 0;

    while (1) {
        printf("Menu:\n");
        printf("1. Add song\n");
        printf("2. Remove song\n");
        printf("3. Search song\n");
        printf("4. Print library\n");
        printf("5. Exit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        while (getchar() != '\n') {} // clear input buffer

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
            case 4:
                print_library(&my_library);
                break;
            case 5:
                printf("\nGoodbye!\n");
                return 0; // exit program
            default:
                printf("\nInvalid choice entered. Please try again.\n\n");
                break;
        }
    }
}