//MISTRAL-7B DATASET v1.0 Category: Music Library Management System ; Style: light-weight
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SONGS 100

typedef struct Song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    int length;
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

    printf("Enter album name: ");
    scanf("%s", library[num_songs].album);

    printf("Enter year: ");
    scanf("%d", &library[num_songs].year);

    printf("Enter song length (in seconds): ");
    scanf("%d", &library[num_songs].length);

    num_songs++;
}

void delete_song() {
    int index;
    char title[50];

    printf("Enter song title to delete: ");
    scanf("%s", title);

    for (int i = 0; i < num_songs; i++) {
        if (strcmp(library[i].title, title) == 0) {
            index = i;
            break;
        }
    }

    if (index == num_songs) {
        printf("Song not found.\n");
        return;
    }

    for (int i = index; i < num_songs - 1; i++) {
        library[i] = library[i + 1];
    }

    num_songs--;
}

void search_song() {
    char title[50];

    printf("Enter song title to search: ");
    scanf("%s", title);

    for (int i = 0; i < num_songs; i++) {
        if (strcmp(library[i].title, title) == 0) {
            printf("Title: %s\n", library[i].title);
            printf("Artist: %s\n", library[i].artist);
            printf("Album: %s\n", library[i].album);
            printf("Year: %d\n", library[i].year);
            printf("Length: %d seconds\n", library[i].length);
            return;
        }
    }

    printf("Song not found.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\nMusic Library Management System\n");
        printf("1. Add Song\n");
        printf("2. Delete Song\n");
        printf("3. Search Song\n");
        printf("4. Quit\n");
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
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}