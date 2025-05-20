//FormAI DATASET v1.0 Category: Music Library Management System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct song {
    char title[50];
    char artist[50];
    int year;
    char genre[20];
} song_t;

void add_song(song_t *library, int *num_songs);
void delete_song(song_t *library, int *num_songs);
void print_songs(song_t *library, int num_songs);

int main() {
    int num_songs = 0;
    song_t *library = malloc(sizeof(song_t));

    printf("Welcome to your C Music Library Management System!\n");

    while (1) {
        printf("\nWhat do you want to do?\n");
        printf("1. Add a song\n");
        printf("2. Delete a song\n");
        printf("3. Print all songs\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_song(library, &num_songs);
                break;
            case 2:
                delete_song(library, &num_songs);
                break;
            case 3:
                print_songs(library, num_songs);
                break;
            case 4:
                printf("Thank you for using your C Music Library Management System!\n");
                free(library);
                return 0;
        }
    }
}

void add_song(song_t *library, int *num_songs) {
    printf("\nEnter the title of the song: ");
    scanf("%s", library[*num_songs].title);
    printf("Enter the artist: ");
    scanf("%s", library[*num_songs].artist);
    printf("Enter the year of release: ");
    scanf("%d", &library[*num_songs].year);
    printf("Enter the genre: ");
    scanf("%s", library[*num_songs].genre);
    (*num_songs)++;
}

void delete_song(song_t *library, int *num_songs) {
    printf("\nEnter the title of the song to delete: ");
    char title[50];
    scanf("%s", title);

    int i;
    for (i = 0; i < *num_songs; i++) {
        if (strcmp(library[i].title, title) == 0) {
            int j;
            for (j = i; j < *num_songs - 1; j++) {
                library[j] = library[j + 1];
            }
            (*num_songs)--;
            printf("Song deleted!\n");
            return;
        }
    }

    printf("Song not found!\n");
}

void print_songs(song_t *library, int num_songs) {
    printf("\nYour music library contains:\n");

    int i;
    for (i = 0; i < num_songs; i++) {
        printf("%s by %s (%d) in %s\n", library[i].title, library[i].artist, library[i].year, library[i].genre);
    }
}