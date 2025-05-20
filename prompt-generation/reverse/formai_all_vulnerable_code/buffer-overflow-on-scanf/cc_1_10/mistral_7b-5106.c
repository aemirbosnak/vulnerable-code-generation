//MISTRAL-7B DATASET v1.0 Category: Music Library Management System ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SONGS 50

typedef struct {
    char title[50];
    char artist[50];
    int year;
} Song;

Song library[MAX_SONGS];
int num_songs = 0;

void add_song() {
    if (num_songs >= MAX_SONGS) {
        printf("Songs library is full.\n");
        return;
    }

    printf("Enter song title: ");
    scanf("%s", library[num_songs].title);

    printf("Enter artist name: ");
    scanf("%s", library[num_songs].artist);

    printf("Enter year of release: ");
    scanf("%d", &library[num_songs].year);

    num_songs++;
    printf("Song added successfully.\n");
}

void remove_song(char title[]) {
    int i;

    for (i = 0; i < num_songs; i++) {
        if (strcmp(library[i].title, title) == 0) {
            for (int j = i; j < num_songs - 1; j++) {
                library[j] = library[j + 1];
            }
            num_songs--;
            printf("Song removed successfully.\n");
            return;
        }
    }

    printf("Song not found in the library.\n");
}

void search_song(char title[]) {
    int i;

    for (i = 0; i < num_songs; i++) {
        if (strcmp(library[i].title, title) == 0) {
            printf("Title: %s\n", library[i].title);
            printf("Artist: %s\n", library[i].artist);
            printf("Year: %d\n", library[i].year);
            return;
        }
    }

    printf("Song not found in the library.\n");
}

void display_library() {
    int i;

    printf("\nSongs in the library:\n");

    for (i = 0; i < num_songs; i++) {
        printf("Title: %s\n", library[i].title);
        printf("Artist: %s\n", library[i].artist);
        printf("Year: %d\n", library[i].year);
        printf("\n");
    }
}

int main() {
    int choice;
    char title[50];

    while (1) {
        printf("\n1. Add song\n2. Remove song\n3. Search song\n4. Display library\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_song();
                break;
            case 2:
                printf("Enter song title to remove: ");
                scanf("%s", title);
                remove_song(title);
                break;
            case 3:
                printf("Enter song title to search: ");
                scanf("%s", title);
                search_song(title);
                break;
            case 4:
                display_library();
                break;
            case 5:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}