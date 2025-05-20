//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100

typedef struct {
    char title[50];
    char artist[50];
    char album[100];
    int duration;
    int year;
} Song;

Song library[MAX_SONGS];
int num_songs = 0;

void add_song() {
    if (num_songs == MAX_SONGS) {
        printf("Library is full\n");
        return;
    }

    Song new_song;

    printf("Enter song title: ");
    scanf("%s", new_song.title);

    printf("Enter artist name: ");
    scanf("%s", new_song.artist);

    printf("Enter album name: ");
    scanf("%s", new_song.album);

    printf("Enter song duration (in seconds): ");
    scanf("%d", &new_song.duration);

    printf("Enter release year: ");
    scanf("%d", &new_song.year);

    library[num_songs++] = new_song;
    printf("Song added to library\n");
}

void display_songs() {
    if (num_songs == 0) {
        printf("Library is empty\n");
        return;
    }

    printf("Song Library:\n");
    printf("--------------------\n");

    for (int i = 0; i < num_songs; i++) {
        printf("%d. %s - %s (%d)\n", i+1, library[i].title, library[i].artist, library[i].year);
    }
}

void search_song() {
    char query[100];

    printf("Enter search query: ");
    scanf("%s", query);

    int found = 0;

    for (int i = 0; i < num_songs; i++) {
        if (strstr(library[i].title, query) || strstr(library[i].artist, query) || strstr(library[i].album, query)) {
            printf("%s - %s (%d)\n", library[i].title, library[i].artist, library[i].year);
            found = 1;
        }
    }

    if (!found) {
        printf("No results found\n");
    }
}

int main() {
    int choice;

    do {
        printf("Music Library Management System\n");
        printf("---------------------------------\n");
        printf("1. Add song\n");
        printf("2. Display songs\n");
        printf("3. Search song\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_song();
                break;
            case 2:
                display_songs();
                break;
            case 3:
                search_song();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice!= 4);

    return 0;
}