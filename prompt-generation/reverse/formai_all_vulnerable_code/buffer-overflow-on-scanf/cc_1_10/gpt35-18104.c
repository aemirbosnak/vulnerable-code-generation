//FormAI DATASET v1.0 Category: Music Library Management System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Song {
    int id;
    char title[50];
    char artist[50];
    char album[50];
    int release_year;
};

void add_song(struct Song *library, int *num_songs) {
    struct Song new_song;

    printf("Enter song title: ");
    fgets(new_song.title, 50, stdin);
    new_song.title[strcspn(new_song.title, "\n")] = 0;

    printf("Enter artist name: ");
    fgets(new_song.artist, 50, stdin);
    new_song.artist[strcspn(new_song.artist, "\n")] = 0;

    printf("Enter album name: ");
    fgets(new_song.album, 50, stdin);
    new_song.album[strcspn(new_song.album, "\n")] = 0;

    printf("Enter release year: ");
    scanf("%d", &new_song.release_year);
    getchar();

    new_song.id = *num_songs + 1;
    library[*num_songs] = new_song;
    (*num_songs)++;
}

void display_library(struct Song *library, int num_songs) {
    printf("ID\tTitle\t\tArtist\t\tAlbum\t\tYear\n");
    for (int i = 0; i < num_songs; i++) {
        printf("%d\t%s\t\t%s\t\t%s\t\t%d\n", library[i].id, library[i].title, library[i].artist, library[i].album, library[i].release_year);
    }
}

void search_title(struct Song *library, int num_songs) {
    char search_title[50];

    printf("Enter title to search for: ");
    fgets(search_title, 50, stdin);
    search_title[strcspn(search_title, "\n")] = 0;

    printf("ID\tTitle\t\tArtist\t\tAlbum\t\tYear\n");
    for (int i = 0; i < num_songs; i++) {
        if (strcmp(search_title, library[i].title) == 0) {
            printf("%d\t%s\t\t%s\t\t%s\t\t%d\n", library[i].id, library[i].title, library[i].artist, library[i].album, library[i].release_year);
        }
    }
}

void search_artist(struct Song *library, int num_songs) {
    char search_artist[50];

    printf("Enter artist to search for: ");
    fgets(search_artist, 50, stdin);
    search_artist[strcspn(search_artist, "\n")] = 0;

    printf("ID\tTitle\t\tArtist\t\tAlbum\t\tYear\n");
    for (int i = 0; i < num_songs; i++) {
        if (strcmp(search_artist, library[i].artist) == 0) {
            printf("%d\t%s\t\t%s\t\t%s\t\t%d\n", library[i].id, library[i].title, library[i].artist, library[i].album, library[i].release_year);
        }
    }
}

int main() {
    struct Song library[50];
    int num_songs = 0;
    int choice;

    while (1) {
        printf("\n");
        printf("1. Add song to library\n");
        printf("2. Display library\n");
        printf("3. Search for song by title\n");
        printf("4. Search for song by artist\n");
        printf("5. Quit\n");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                add_song(library, &num_songs);
                break;

            case 2:
                display_library(library, num_songs);
                break;

            case 3:
                search_title(library, num_songs);
                break;

            case 4:
                search_artist(library, num_songs);
                break;

            case 5:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}