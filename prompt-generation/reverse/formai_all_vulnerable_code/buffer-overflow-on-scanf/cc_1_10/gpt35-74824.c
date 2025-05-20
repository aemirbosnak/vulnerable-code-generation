//FormAI DATASET v1.0 Category: Music Library Management System ; Style: lively
#include <stdio.h>
#include <string.h>

/* Define struct for storing music information */
struct music {
    char title[50];
    char artist[30];
    int year;
};

/* Define function for adding new music */
void add_music(struct music lib[], int *num_songs) {
    printf("Enter the title of the song: ");
    scanf("%s", lib[*num_songs].title);
    printf("Enter the artist of the song: ");
    scanf("%s", lib[*num_songs].artist);
    printf("Enter the year the song was released: ");
    scanf("%d", &lib[*num_songs].year);
    (*num_songs)++;
}

/* Define function for searching for music by title */
void search_title(struct music lib[], int num_songs) {
    char title[50];
    printf("Enter the title of the song you want to find: ");
    scanf("%s", title);
    for (int i = 0; i < num_songs; i++) {
        if (strcmp(title, lib[i].title) == 0) {
            printf("Title: %s\nArtist: %s\nYear: %d\n", lib[i].title, lib[i].artist, lib[i].year);
            return;
        }
    }
    printf("Song not found.\n");
}

/* Define function for searching for music by artist */
void search_artist(struct music lib[], int num_songs) {
    char artist[30];
    printf("Enter the artist whose songs you want to find: ");
    scanf("%s", artist);
    int found_songs = 0;
    for (int i = 0; i < num_songs; i++) {
        if (strcmp(artist, lib[i].artist) == 0) {
            printf("Title: %s\nArtist: %s\nYear: %d\n\n", lib[i].title, lib[i].artist, lib[i].year);
            found_songs++;
        }
    }
    if (found_songs == 0) {
        printf("No songs found for artist %s.\n", artist);
    }
}

int main() {
    struct music library[100];
    int num_songs = 0;
    char choice;
    do {
        printf("Choose an action:\n");
        printf("1. Add new music\n");
        printf("2. Search for music by title\n");
        printf("3. Search for music by artist\n");
        printf("4. Exit\n");
        scanf(" %c", &choice);
        switch (choice) {
            case '1':
                add_music(library, &num_songs);
                break;
            case '2':
                search_title(library, num_songs);
                break;
            case '3':
                search_artist(library, num_songs);
                break;
            case '4':
                printf("Exiting music library management system...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != '4');
    return 0;
}