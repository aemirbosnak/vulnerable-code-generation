//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100

struct Song {
    char title[81];
    char artist[81];
    int duration;
    int year;
};

void addSong(struct Song* library[], int size) {
    printf("Enter song title: ");
    scanf("%s", library[size]->title);
    printf("Enter artist name: ");
    scanf("%s", library[size]->artist);
    printf("Enter song duration (in seconds): ");
    scanf("%d", &library[size]->duration);
    printf("Enter song release year: ");
    scanf("%d", &library[size]->year);
    printf("\nSong added successfully!\n");
}

void displaySongs(struct Song* library[], int size) {
    printf("\nSongs in the library:\n");
    for (int i = 0; i < size; i++) {
        printf("%s - %s (%d seconds, %d)\n", library[i]->title, library[i]->artist, library[i]->duration, library[i]->year);
    }
}

void searchSong(struct Song* library[], int size) {
    char searchTitle[81];
    printf("Enter song title to search: ");
    scanf("%s", searchTitle);
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(library[i]->title, searchTitle) == 0) {
            printf("\nSong found:\n");
            printf("%s - %s (%d seconds, %d)\n", library[i]->title, library[i]->artist, library[i]->duration, library[i]->year);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Song not found.\n");
    }
}

int main() {
    struct Song library[MAX_SONGS];
    int size = 0;

    while (size < MAX_SONGS) {
        int choice;
        printf("\nMusic Library Management System\n");
        printf("1. Add song\n");
        printf("2. Display songs\n");
        printf("3. Search song\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addSong(library, size);
                size++;
                break;
            case 2:
                displaySongs(library, size);
                break;
            case 3:
                searchSong(library, size);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}