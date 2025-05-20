//MISTRAL-7B DATASET v1.0 Category: Music Library Management System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char title[50];
    char artist[50];
    char genre[20];
} Song;

Song library[MAX_SIZE];
int count = 0;

void addSong();
void removeSong();
void searchSong();
void displayLibrary();

int main() {
    int choice;

    while (1) {
        printf("\n1. Add Song\n2. Remove Song\n3. Search Song\n4. Display Library\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addSong();
                break;
            case 2:
                removeSong();
                break;
            case 3:
                searchSong();
                break;
            case 4:
                displayLibrary();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

void addSong() {
    if (count >= MAX_SIZE) {
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

    printf("Song added successfully.\n");
}

void removeSong() {
    int index, i;
    char title[50];

    printf("Enter the title of the song to be removed: ");
    scanf("%s", title);

    for (index = 0; index < count; index++) {
        if (strcmp(library[index].title, title) == 0) {
            for (i = index; i < count - 1; i++) {
                library[i] = library[i + 1];
            }
            count--;
            break;
        }
    }

    if (index == count) {
        printf("Song not found.\n");
    } else {
        printf("Song removed successfully.\n");
    }
}

void searchSong() {
    int index, i;
    char title[50];

    printf("Enter the title of the song to search: ");
    scanf("%s", title);

    for (index = 0; index < count; index++) {
        if (strcmp(library[index].title, title) == 0) {
            printf("Title: %s\n", library[index].title);
            printf("Artist: %s\n", library[index].artist);
            printf("Genre: %s\n", library[index].genre);
            return;
        }
    }

    printf("Song not found.\n");
}

void displayLibrary() {
    int i;

    printf("\nMusic Library:\n");

    for (i = 0; i < count; i++) {
        printf("Title: %s\n", library[i].title);
        printf("Artist: %s\n", library[i].artist);
        printf("Genre: %s\n", library[i].genre);
        printf("\n");
    }
}