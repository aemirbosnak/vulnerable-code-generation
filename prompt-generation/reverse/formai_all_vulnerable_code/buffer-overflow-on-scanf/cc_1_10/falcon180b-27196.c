//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC_COUNT 100
#define MAX_SONG_LENGTH 50

typedef struct {
    char title[MAX_SONG_LENGTH];
    char artist[MAX_SONG_LENGTH];
    char genre[MAX_SONG_LENGTH];
    int length;
} Music;

Music library[MAX_MUSIC_COUNT];
int music_count = 0;

void add_music() {
    printf("Enter music title: ");
    scanf("%s", library[music_count].title);

    printf("Enter music artist: ");
    scanf("%s", library[music_count].artist);

    printf("Enter music genre: ");
    scanf("%s", library[music_count].genre);

    printf("Enter music length (in seconds): ");
    scanf("%d", &library[music_count].length);

    music_count++;
}

void display_music() {
    int i;
    for (i = 0; i < music_count; i++) {
        printf("Music #%d:\n");
        printf("Title: %s\n", library[i].title);
        printf("Artist: %s\n", library[i].artist);
        printf("Genre: %s\n", library[i].genre);
        printf("Length: %d seconds\n\n", library[i].length);
    }
}

int main() {
    int choice;

    do {
        printf("Music Library Management System\n");
        printf("1. Add music\n2. Display music\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_music();
            break;
        case 2:
            display_music();
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    } while (1);

    return 0;
}