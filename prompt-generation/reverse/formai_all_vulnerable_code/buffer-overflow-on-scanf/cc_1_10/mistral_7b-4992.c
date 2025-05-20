//MISTRAL-7B DATASET v1.0 Category: Music Library Management System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Song {
    char title[100];
    char artist[100];
    char genre[50];
    int duration;
    struct Song *next;
} Song;

Song *root = NULL;

void add_song_recursive(Song *current, char title[], char artist[], char genre[], int duration) {
    if (current == NULL) {
        current = (Song *)malloc(sizeof(Song));
        strcpy(current->title, title);
        strcpy(current->artist, artist);
        strcpy(current->genre, genre);
        current->duration = duration;
        current->next = NULL;
    } else if (strcmp(title, current->title) < 0) {
        add_song_recursive(current->next, title, artist, genre, duration);
    } else {
        printf("Song already exists!\n");
        free(current);
    }
}

void print_songs_recursive(Song *current) {
    if (current != NULL) {
        print_songs_recursive(current->next);
        printf("Title: %s\nArtist: %s\nGenre: %s\nDuration: %d\n", current->title, current->artist, current->genre, current->duration);
    }
}

int main() {
    char title[100], artist[100], genre[50];
    int duration;

    printf("Enter number of songs to add: ");
    int num_songs;
    scanf("%d", &num_songs);

    for (int i = 0; i < num_songs; i++) {
        printf("\nEnter title %d: ", i + 1);
        scanf("%s", title);

        printf("Enter artist %d: ", i + 1);
        scanf("%s", artist);

        printf("Enter genre %d: ", i + 1);
        scanf("%s", genre);

        printf("Enter duration %d (in seconds): ", i + 1);
        scanf("%d", &duration);

        add_song_recursive(root, title, artist, genre, duration);
    }

    printf("\nPrinting songs in the library:\n");
    print_songs_recursive(root);

    return 0;
}