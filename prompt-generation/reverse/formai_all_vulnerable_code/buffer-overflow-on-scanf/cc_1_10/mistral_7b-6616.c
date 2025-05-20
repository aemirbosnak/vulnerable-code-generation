//MISTRAL-7B DATASET v1.0 Category: Music Library Management System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SONGS 100
#define MAX_TITLE_LEN 50
#define MAX_ARTIST_LEN 30

typedef struct Song {
    char title[MAX_TITLE_LEN];
    char artist[MAX_ARTIST_LEN];
} Song;

Song library[MAX_SONGS];
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

    num_songs++;
}

void list_songs() {
    int i;

    printf("\nSong List\n");
    for (i = 0; i < num_songs; i++) {
        printf("%d. %s - %s\n", i+1, library[i].title, library[i].artist);
    }
}

void search_song() {
    char title[MAX_TITLE_LEN];
    int i;

    printf("Enter song title to search: ");
    scanf("%s", title);

    for (i = 0; i < num_songs; i++) {
        if (strcmp(title, library[i].title) == 0) {
            printf("Song found: %s - %s\n", library[i].title, library[i].artist);
            return;
        }
    }

    printf("Song not found.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\nMusic Library Management System\n");
        printf("1. Add Song\n");
        printf("2. List Songs\n");
        printf("3. Search Song\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_song();
                break;
            case 2:
                list_songs();
                break;
            case 3:
                search_song();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}