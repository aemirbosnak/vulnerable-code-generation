//MISTRAL-7B DATASET v1.0 Category: Music Library Management System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char title[50];
    char artist[50];
    char album[50];
} Song;

Song library[MAX_SIZE];
int count = 0;

void add_song() {
    if (count >= MAX_SIZE) {
        printf("Library is full.\n");
        return;
    }

    printf("Enter song title: ");
    scanf("%s", library[count].title);

    printf("Enter artist name: ");
    scanf("%s", library[count].artist);

    printf("Enter album name: ");
    scanf("%s", library[count].album);

    count++;
}

void search_song() {
    char title[50];

    printf("Enter song title to search: ");
    scanf("%s", title);

    for (int i = 0; i < count; i++) {
        if (strcmp(library[i].title, title) == 0) {
            printf("Song found!\n");
            printf("Title: %s\n", library[i].title);
            printf("Artist: %s\n", library[i].artist);
            printf("Album: %s\n", library[i].album);
            return;
        }
    }

    printf("Song not found.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Add song\n");
        printf("2. Search song\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_song();
                break;
            case 2:
                search_song();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}