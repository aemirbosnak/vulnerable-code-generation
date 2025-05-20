//MISTRAL-7B DATASET v1.0 Category: Music Library Management System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 50
#define SONG_SIZE 100

typedef struct {
    char title[50];
    char artist[50];
    char album[50];
} Song;

Song library[MAX_SONGS];
int count = 0;

void add_song(char *title, char *artist, char *album) {
    if (count < MAX_SONGS) {
        strcpy(library[count].title, title);
        strcpy(library[count].artist, artist);
        strcpy(library[count].album, album);
        count++;
    } else {
        printf("Music Library is Full!\n");
    }
}

void display_library() {
    if (count > 0) {
        printf("Music Library:\n");
        printf("------------------\n");
        for (int i = 0; i < count; i++) {
            printf("| %d | %s by %s from %s |\n", i + 1, library[i].title, library[i].artist, library[i].album);
        }
    } else {
        printf("Music Library is Empty!\n");
    }
}

void delete_song(int index) {
    if (index >= 0 && index < count) {
        memmove(&library[index], &library[index + 1], (count - index - 1) * sizeof(Song));
        count--;
    } else {
        printf("Invalid Index!\n");
    }
}

int main() {
    char title[50], artist[50], album[50];
    int choice, index;

    while (1) {
        printf("\n1. Add Song\n2. Display Library\n3. Delete Song\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Title: ");
                scanf("%s", title);
                printf("Enter Artist: ");
                scanf("%s", artist);
                printf("Enter Album: ");
                scanf("%s", album);
                add_song(title, artist, album);
                break;
            case 2:
                display_library();
                break;
            case 3:
                printf("Enter Index: ");
                scanf("%d", &index);
                delete_song(index);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}