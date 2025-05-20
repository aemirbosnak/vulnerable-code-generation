//MISTRAL-7B DATASET v1.0 Category: Music Library Management System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRACKS 100
#define MAX_TITLE_LENGTH 50
#define MAX_ARTIST_LENGTH 30

typedef struct {
    char artist[MAX_ARTIST_LENGTH];
    char title[MAX_TITLE_LENGTH];
} Track;

Track library[MAX_TRACKS];
int num_tracks = 0;

void add_track() {
    if (num_tracks >= MAX_TRACKS) {
        printf("Library is full.\n");
        return;
    }

    printf("Enter artist name: ");
    scanf("%s", library[num_tracks].artist);

    printf("Enter track title: ");
    scanf("%s", library[num_tracks].title);

    num_tracks++;
}

void print_library() {
    printf("\nCurrent library:\n");

    for (int i = 0; i < num_tracks; i++) {
        printf("%d. %s - %s\n", i+1, library[i].title, library[i].artist);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Add track\n2. Print library\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_track();
                break;
            case 2:
                print_library();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}