//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define MAX_SONG_LENGTH 100

typedef struct {
    char title[MAX_SONG_LENGTH];
    char artist[MAX_SONG_LENGTH];
    char album[MAX_SONG_LENGTH];
    int length;
} song;

song library[MAX_SONGS];
int num_songs = 0;

void add_song() {
    if (num_songs >= MAX_SONGS) {
        printf("Library is full.\n");
        return;
    }

    printf("Enter song title: ");
    scanf("%s", library[num_songs].title);

    printf("Enter artist name: ");
    scanf("%s", library[num_songs].artist);

    printf("Enter album name: ");
    scanf("%s", library[num_songs].album);

    printf("Enter song length (in seconds): ");
    scanf("%d", &library[num_songs].length);

    num_songs++;
}

void display_library() {
    printf("Library:\n");
    for (int i = 0; i < num_songs; i++) {
        printf("%d. %s - %s\n", i+1, library[i].title, library[i].artist);
    }
}

void search_song() {
    char search_title[MAX_SONG_LENGTH];

    printf("Enter song title to search: ");
    scanf("%s", search_title);

    for (int i = 0; i < num_songs; i++) {
        if (strcmp(library[i].title, search_title) == 0) {
            printf("Song found:\n");
            printf("Title: %s\n", library[i].title);
            printf("Artist: %s\n", library[i].artist);
            printf("Album: %s\n", library[i].album);
            printf("Length: %d seconds\n", library[i].length);
        }
    }
}

int main() {
    printf("Welcome to the Music Library Management System!\n");

    while (1) {
        printf("\n");
        printf("1. Add song\n");
        printf("2. Display library\n");
        printf("3. Search song\n");
        printf("4. Exit\n");

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
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}