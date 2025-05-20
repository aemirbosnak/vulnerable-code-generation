//FormAI DATASET v1.0 Category: Music Library Management System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 1000

struct Song {
    char title[100];
    char artist[100];
    char album[100];
    int year;
};

struct Library {
    struct Song songs[MAX_SONGS];
    int num_songs;
};

void add_song(struct Library *library);
void remove_song(struct Library *library);
void search_song(struct Library *library);
void display_library(struct Library *library);

int main() {
    struct Library library = {0};

    int choice;
    do {
        printf("\n---C Music Library Management System---\n");
        printf("\n1. Add a song");
        printf("\n2. Remove a song");
        printf("\n3. Search for a song");
        printf("\n4. Display library");
        printf("\n5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_song(&library);
            break;
        case 2:
            remove_song(&library);
            break;
        case 3:
            search_song(&library);
            break;
        case 4:
            display_library(&library);
            break;
        case 5:
            printf("\nGoodbye!\n");
            break;
        default:
            printf("\nInvalid choice, please try again.\n");
            break;
        }
    } while (choice != 5);

    return 0;
}

void add_song(struct Library *library) {
    if (library->num_songs >= MAX_SONGS) {
        printf("\nCannot add song, library is full.\n");
        return;
    }

    struct Song song = {0};

    printf("\nEnter song title: ");
    scanf(" %[^\n]%*c", song.title);

    printf("\nEnter artist name: ");
    scanf(" %[^\n]%*c", song.artist);

    printf("\nEnter album name: ");
    scanf(" %[^\n]%*c", song.album);

    printf("\nEnter year released: ");
    scanf("%d", &song.year);

    library->songs[library->num_songs++] = song;

    printf("\nSong added successfully!\n");
}

void remove_song(struct Library *library) {
    if (library->num_songs == 0) {
        printf("\nCannot remove song, library is empty.\n");
        return;
    }

    char title[100];
    printf("\nEnter the title of the song you want to remove: ");
    scanf(" %[^\n]%*c", title);

    int i;
    for (i = 0; i < library->num_songs; i++) {
        if (strcmp(library->songs[i].title, title) == 0) {
            int j;
            for (j = i; j < library->num_songs - 1; j++) {
                library->songs[j] = library->songs[j + 1];
            }

            library->num_songs--;

            printf("\nSong removed successfully!\n");
            return;
        }
    }

    printf("\nSong not found.\n");
}

void search_song(struct Library *library) {
    if (library->num_songs == 0) {
        printf("\nCannot search for song, library is empty.\n");
        return;
    }

    char title[100];
    printf("\nEnter the title of the song you want to search: ");
    scanf(" %[^\n]%*c", title);

    int i;
    for (i = 0; i < library->num_songs; i++) {
        if (strcmp(library->songs[i].title, title) == 0) {
            printf("\nTitle: %s", library->songs[i].title);
            printf("\nArtist: %s", library->songs[i].artist);
            printf("\nAlbum: %s", library->songs[i].album);
            printf("\nYear: %d\n", library->songs[i].year);
            return;
        }
    }

    printf("\nSong not found.\n");
}

void display_library(struct Library *library) {
    if (library->num_songs == 0) {
        printf("\nLibrary is empty.\n");
        return;
    }

    printf("\n%-30s %-30s %-30s %-30s\n", "Title", "Artist", "Album", "Year");

    int i;
    for (i = 0; i < library->num_songs; i++) {
        printf("\n%-30s %-30s %-30s %-30d\n", library->songs[i].title, library->songs[i].artist,
               library->songs[i].album, library->songs[i].year);
    }
}