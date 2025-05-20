//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define MAX_NAME 100
#define MAX_ARTIST 100
#define MAX_ALBUM 100
#define MAX_GENRE 100
#define MAX_YEAR 100

typedef struct song {
    char name[MAX_NAME];
    char artist[MAX_ARTIST];
    char album[MAX_ALBUM];
    char genre[MAX_GENRE];
    char year[MAX_YEAR];
    char file_path[MAX_SONGS];
} song;

song library[MAX_SONGS];
int num_songs;

void add_song() {
    printf("Enter song name: ");
    scanf("%s", library[num_songs].name);

    printf("Enter artist name: ");
    scanf("%s", library[num_songs].artist);

    printf("Enter album name: ");
    scanf("%s", library[num_songs].album);

    printf("Enter genre: ");
    scanf("%s", library[num_songs].genre);

    printf("Enter year: ");
    scanf("%s", library[num_songs].year);

    printf("Enter file path: ");
    scanf("%s", library[num_songs].file_path);

    num_songs++;
}

void display_library() {
    printf("\nLibrary:\n");
    printf("------------------------\n");
    printf("Name\tArtist\tAlbum\tGenre\tYear\tFile Path\n");

    for (int i = 0; i < num_songs; i++) {
        printf("%s\t%s\t%s\t%s\t%s\t%s\n", library[i].name, library[i].artist, library[i].album, library[i].genre, library[i].year, library[i].file_path);
    }

    printf("------------------------\n");
}

void search_song() {
    char search_term[MAX_NAME];

    printf("Enter search term: ");
    scanf("%s", search_term);

    int found = 0;

    for (int i = 0; i < num_songs; i++) {
        if (strcmp(library[i].name, search_term) == 0) {
            printf("\nSong found:\n");
            printf("------------------------\n");
            printf("Name\tArtist\tAlbum\tGenre\tYear\tFile Path\n");

            printf("%s\t%s\t%s\t%s\t%s\t%s\n", library[i].name, library[i].artist, library[i].album, library[i].genre, library[i].year, library[i].file_path);

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Song not found.\n");
    }
}

int main() {
    printf("Welcome to the C Music Library Management System!\n");

    printf("Enter 1 to add a song.\n");
    printf("Enter 2 to display the library.\n");
    printf("Enter 3 to search for a song.\n");

    int choice;

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            add_song();
            break;

        case 2:
            display_library();
            break;

        case 3:
            search_song();
            break;

        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}