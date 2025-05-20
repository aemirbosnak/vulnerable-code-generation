//MISTRAL-7B DATASET v1.0 Category: Music Library Management System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100

typedef struct {
    char title[100];
    char artist[50];
    char genre[20];
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

    printf("Enter genre: ");
    scanf("%s", library[num_songs].genre);

    num_songs++;
    printf("Song added successfully.\n");
}

void display_library() {
    if (num_songs == 0) {
        printf("Library is empty.\n");
        return;
    }

    printf("\nMusic Library:\n");
    printf("-----------------\n");

    for (int i = 0; i < num_songs; i++) {
        printf("| %-30s | %-20s | %-10s |\n", library[i].title, library[i].artist, library[i].genre);
    }
}

void remove_song() {
    if (num_songs == 0) {
        printf("Library is empty.\n");
        return;
    }

    int index;
    printf("Enter index of the song you want to remove: ");
    scanf("%d", &index);

    if (index < 0 || index >= num_songs) {
        printf("Invalid index.\n");
        return;
    }

    for (int i = index; i < num_songs - 1; i++) {
        strcpy(library[i].title, library[i + 1].title);
        strcpy(library[i].artist, library[i + 1].artist);
        strcpy(library[i].genre, library[i + 1].genre);
    }

    num_songs--;
    printf("Song removed successfully.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\nMusic Library Management System\n");
        printf("1. Add song\n");
        printf("2. Display library\n");
        printf("3. Remove song\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_song();
                break;
            case 2:
                display_library();
                break;
            case 3:
                remove_song();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}