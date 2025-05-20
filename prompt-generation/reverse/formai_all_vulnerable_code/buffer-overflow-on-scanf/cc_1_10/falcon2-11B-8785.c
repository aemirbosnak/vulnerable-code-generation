//Falcon2-11B DATASET v1.0 Category: Music Library Management System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Song {
    char title[100];
    int duration;
} Song;

void addSong(Song* library, int size) {
    printf("Enter song title: ");
    fgets(library[size].title, sizeof(library[size].title), stdin);
    library[size].duration = 0;
    printf("Enter song duration (in seconds): ");
    scanf("%d", &library[size].duration);
}

void removeSong(Song* library, int size) {
    printf("Enter song title to remove: ");
    fgets(library[size].title, sizeof(library[size].title), stdin);
    for (int i = 0; i < size; i++) {
        if (strcmp(library[i].title, library[size].title) == 0) {
            for (int j = i; j < size - 1; j++) {
                library[j] = library[j + 1];
            }
            size--;
            break;
        }
    }
}

int searchSong(Song* library, int size) {
    printf("Enter song title to search: ");
    fgets(library[size].title, sizeof(library[size].title), stdin);
    for (int i = 0; i < size; i++) {
        if (strcmp(library[i].title, library[size].title) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    Song library[100];
    int size = 0;
    int choice;

    while (1) {
        printf("1. Add a song\n2. Remove a song\n3. Search for a song\n4. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addSong(library, size);
                break;
            case 2:
                removeSong(library, size);
                break;
            case 3:
                printf("Song found at index %d\n", searchSong(library, size));
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}