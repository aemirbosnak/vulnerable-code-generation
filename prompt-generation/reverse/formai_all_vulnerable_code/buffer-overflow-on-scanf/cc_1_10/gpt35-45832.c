//FormAI DATASET v1.0 Category: Music Library Management System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song {
    char title[50];
    char artist[50];
    int year;
};

void add_song(struct song library[], int *size) {
    printf("Enter song title: ");
    fgets(library[*size].title, 50, stdin);
    library[*size].title[strcspn(library[*size].title, "\n")] = 0;

    printf("Enter artist name: ");
    fgets(library[*size].artist, 50, stdin);
    library[*size].artist[strcspn(library[*size].artist, "\n")] = 0;

    printf("Enter song release year: ");
    scanf("%d", &library[*size].year);
    getchar(); // to remove the newline character from buffer

    printf("\nSong added successfully!\n\n");
    (*size)++;
}

void display_library(struct song library[], int size) {
    printf("-------------------\n");
    printf("Title\tArtist\tYear\n");
    printf("-------------------\n");

    for (int i = 0; i < size; i++) {
        printf("%s\t%s\t%d\n", library[i].title, library[i].artist, library[i].year);
    }

    printf("-------------------\n\n");
}

int main() {
    struct song library[100]; // maximum capacity of library
    int size = 0; // initially library is empty
    int choice;

    do {
        printf("Choose an option:\n");
        printf("1. Add a song to the library\n");
        printf("2. Display the library\n");
        printf("3. Exit\n\n");

        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
        getchar(); // to remove the newline character from buffer

        switch (choice) {
            case 1: add_song(library, &size); break;
            case 2: display_library(library, size); break;
            case 3: printf("Goodbye!\n"); break;
            default: printf("Invalid choice. Please enter a number between 1 and 3.\n\n");
        }

    } while (choice != 3);

    return 0;
}