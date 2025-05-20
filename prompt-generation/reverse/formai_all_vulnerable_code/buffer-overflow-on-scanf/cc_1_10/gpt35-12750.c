//FormAI DATASET v1.0 Category: Music Library Management System ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SONGS 1000

struct Song {
    char title[50];
    char artist[30];
    int year;
};

struct Library {
    struct Song songs[MAX_SONGS];
    int num_songs;
};

void addSong(struct Library *lib) {
    if (lib->num_songs == MAX_SONGS) {
        printf("The library is full!\n");
        return;
    }

    struct Song new_song;

    printf("Enter song title: ");
    fgets(new_song.title, 50, stdin);
    strtok(new_song.title, "\n");

    printf("Enter artist name: ");
    fgets(new_song.artist, 30, stdin);
    strtok(new_song.artist, "\n");

    printf("Enter year released: ");
    scanf("%d", &new_song.year);
    getchar(); // to clear the '\n' in the input buffer

    lib->songs[lib->num_songs++] = new_song;

    printf("Song added successfully!\n");
}

void searchSongByTitle(struct Library *lib) {
    char title[50];
    int found = 0;

    printf("Enter the title to search for: ");
    fgets(title, 50, stdin);
    strtok(title, "\n");

    for (int i = 0; i < lib->num_songs; i++) {
        if (strcmp(title, lib->songs[i].title) == 0) {
            printf("Title: %s\nArtist: %s\nYear released: %d\n",
                   lib->songs[i].title, lib->songs[i].artist, lib->songs[i].year);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Song not found in the library!\n");
    }
}

int main() {
    struct Library my_library;
    my_library.num_songs = 0;

    int choice;

    do {
        printf("1. Add song\n2. Search song by title\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: addSong(&my_library); break;
            case 2: searchSongByTitle(&my_library); break;
            case 3: printf("Goodbye!\n"); break;
            default: printf("Invalid choice. Please try again.\n"); break;
        }
    } while (choice != 3);

    return 0;
}