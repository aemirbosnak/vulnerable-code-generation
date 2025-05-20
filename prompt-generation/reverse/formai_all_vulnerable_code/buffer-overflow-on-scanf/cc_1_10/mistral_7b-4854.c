//MISTRAL-7B DATASET v1.0 Category: Music Library Management System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100

typedef struct {
    char title[50];
    char artist[50];
    char genre[20];
} Song;

Song library[MAX_SONGS];
int count = 0;

void add_song() {
    if (count >= MAX_SONGS) {
        printf("Music library is full.\n");
        return;
    }

    printf("Enter song title: ");
    scanf("%s", library[count].title);

    printf("Enter artist name: ");
    scanf("%s", library[count].artist);

    printf("Enter genre: ");
    scanf("%s", library[count].genre);

    count++;
}

void search_song() {
    char title[50];

    printf("Enter song title to search: ");
    scanf("%s", title);

    for (int i = 0; i < count; i++) {
        if (strcmp(library[i].title, title) == 0) {
            printf("Song found:\n");
            printf("Title: %s\n", library[i].title);
            printf("Artist: %s\n", library[i].artist);
            printf("Genre: %s\n", library[i].genre);
            return;
        }
    }

    printf("Song not found.\n");
}

void delete_song() {
    char title[50];
    int index = -1;

    printf("Enter song title to delete: ");
    scanf("%s", title);

    for (int i = 0; i < count; i++) {
        if (strcmp(library[i].title, title) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Song not found.\n");
        return;
    }

    for (int i = index; i < count - 1; i++) {
        library[i] = library[i + 1];
    }

    count--;
}

void print_library() {
    printf("\nMusic Library:\n");

    for (int i = 0; i < count; i++) {
        printf("Title: %s\n", library[i].title);
        printf("Artist: %s\n", library[i].artist);
        printf("Genre: %s\n", library[i].genre);
        printf("\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nMusic Library Management System\n");
        printf("1. Add Song\n");
        printf("2. Search Song\n");
        printf("3. Delete Song\n");
        printf("4. Print Library\n");
        printf("5. Exit\n");
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
                delete_song();
                break;
            case 4:
                print_library();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}