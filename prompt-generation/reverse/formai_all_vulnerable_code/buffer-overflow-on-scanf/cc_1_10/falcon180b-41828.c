//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100

typedef struct {
    char title[100];
    char artist[100];
    int duration;
    int genre;
} Song;

Song library[MAX_SONGS];
int num_songs = 0;

void add_song() {
    if (num_songs >= MAX_SONGS) {
        printf("Library is full!\n");
        return;
    }

    printf("Enter song title: ");
    scanf("%s", library[num_songs].title);

    printf("Enter artist name: ");
    scanf("%s", library[num_songs].artist);

    printf("Enter song duration (in seconds): ");
    scanf("%d", &library[num_songs].duration);

    printf("Enter song genre (1 for pop, 2 for rock, 3 for jazz): ");
    scanf("%d", &library[num_songs].genre);

    num_songs++;
    printf("Song added to library!\n");
}

void display_library() {
    printf("Library:\n");
    for (int i = 0; i < num_songs; i++) {
        printf("%d. %s - %s (%d seconds)\n", i+1, library[i].title, library[i].artist, library[i].duration);
    }
}

void search_song() {
    char query[100];
    printf("Enter search query: ");
    scanf("%s", query);

    int found = 0;
    for (int i = 0; i < num_songs; i++) {
        if (strstr(library[i].title, query)!= NULL || strstr(library[i].artist, query)!= NULL) {
            printf("%d. %s - %s (%d seconds)\n", i+1, library[i].title, library[i].artist, library[i].duration);
            found = 1;
        }
    }

    if (!found) {
        printf("No results found.\n");
    }
}

int main() {
    printf("Welcome to Music Library Management System!\n");

    while (1) {
        printf("\n1. Add song\n2. Display library\n3. Search song\n4. Exit\n");
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
                printf("Invalid choice!\n");
        }
    }

    return 0;
}