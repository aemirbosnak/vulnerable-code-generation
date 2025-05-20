//MISTRAL-7B DATASET v1.0 Category: Music Library Management System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100

typedef struct {
    char title[50];
    char artist[50];
    char album[50];
    int year;
} Song;

Song library[MAX_SONGS];
int count = 0;

void add_song(Song song) {
    if (count < MAX_SONGS) {
        library[count] = song;
        count++;
    } else {
        printf("Library is full.\n");
    }
}

void display_library() {
    int i;
    for (i = 0; i < count; i++) {
        printf("\n%d. %s - %s (%d)", i + 1, library[i].title, library[i].artist, library[i].year);
    }
}

void search_song(char query[50]) {
    int i;
    int found = 0;
    for (i = 0; i < count; i++) {
        if (strstr(library[i].title, query) || strstr(library[i].artist, query)) {
            printf("\n%s - %s (%d)", library[i].title, library[i].artist, library[i].year);
            found = 1;
        }
    }
    if (!found) {
        printf("\nSong not found.\n");
    }
}

int main() {
    int choice;
    char query[50];

    while (1) {
        printf("\nMusic Library Management System\n");
        printf("\n1. Add Song\n");
        printf("\n2. Display Library\n");
        printf("\n3. Search Song\n");
        printf("\n4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter Title: ");
                scanf("%s", library[count].title);
                printf("\nEnter Artist: ");
                scanf("%s", library[count].artist);
                printf("\nEnter Album: ");
                scanf("%s", library[count].album);
                printf("\nEnter Year: ");
                scanf("%d", &library[count].year);
                add_song(library[count]);
                break;

            case 2:
                display_library();
                break;

            case 3:
                printf("\nEnter search query: ");
                scanf("%s", query);
                search_song(query);
                break;

            case 4:
                exit(0);

            default:
                printf("\nInvalid choice.\n");
        }
    }

    return 0;
}