//FormAI DATASET v1.0 Category: Music Library Management System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 1000
#define MAX_TITLE_SIZE 50
#define MAX_ARTIST_SIZE 50
#define MAX_GENRE_SIZE 20
#define MAX_YEAR_SIZE 10

typedef struct song_t {
    char title[MAX_TITLE_SIZE];
    char artist[MAX_ARTIST_SIZE];
    char genre[MAX_GENRE_SIZE];
    char year[MAX_YEAR_SIZE];
} song;

void add_song(song *songs, int *num_songs) {
    if (*num_songs == MAX_SONGS) {
        printf("The library is full. Cannot add anymore songs.\n");
        return;
    }

    printf("Enter the details of the song:\n");

    printf("Title: ");
    scanf("%s", (songs + *num_songs)->title);

    printf("Artist: ");
    scanf("%s", (songs + *num_songs)->artist);

    printf("Genre: ");
    scanf("%s", (songs + *num_songs)->genre);

    printf("Year: ");
    scanf("%s", (songs + *num_songs)->year);

    printf("\nSong added successfully!\n");

    (*num_songs)++;
}

void search_song_by_title(song *songs, int num_songs) {
    char title[MAX_TITLE_SIZE];
    int found = 0;

    printf("Enter the title of the song you want to search for: ");
    scanf("%s", title);

    printf("\n");

    for (int i = 0; i < num_songs; i++) {
        if (strcmp((songs + i)->title, title) == 0) {
            printf("Title: %s\nArtist: %s\nGenre: %s\nYear: %s\n\n", 
                (songs + i)->title, (songs + i)->artist, (songs + i)->genre, (songs + i)->year);
            found = 1;
        }
    }

    if (!found) {
        printf("Song not found.\n");
    }
}

void display_all_songs(song *songs, int num_songs) {
    if (num_songs == 0) {
        printf("The library is empty.\n");
        return;
    }

    printf("*******************************\n");
    printf("     MEDIEVAL MUSIC LIBRARY     \n");
    printf("*******************************\n\n");

    for (int i = 0; i < num_songs; i++) {
        printf("Title: %s\nArtist: %s\nGenre: %s\nYear: %s\n\n", 
            (songs + i)->title, (songs + i)->artist, (songs + i)->genre, (songs + i)->year);
    }
}

int main() {
    song songs[MAX_SONGS];
    int num_songs = 0;
    int choice;

    printf("Welcome to the MEDIEVAL MUSIC LIBRARY!\n");

    do {
        printf("Please select an option:\n");
        printf("1. Add a new song\n");
        printf("2. Search for a song by title\n");
        printf("3. Display all songs\n");
        printf("4. Exit\n\n");
        printf("Choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                add_song(songs, &num_songs);
                break;
            case 2:
                search_song_by_title(songs, num_songs);
                break;
            case 3:
                display_all_songs(songs, num_songs);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\n");
    } while (choice != 4);

    return 0;
}