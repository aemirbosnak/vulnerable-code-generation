//FormAI DATASET v1.0 Category: Music Library Management System ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>

struct song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    char genre[50];
    char location[50];
    int rating;
};

void print_song(struct song s) {
    printf("Title: %s\n", s.title);
    printf("Artist: %s\n", s.artist);
    printf("Album: %s\n", s.album);
    printf("Year: %d\n", s.year);
    printf("Genre: %s\n", s.genre);
    printf("Location: %s\n", s.location);
    printf("Rating: %d\n", s.rating);
}

void add_song(struct song library[], int *count) {
    if (*count >= 50) {
        printf("Cannot add song! Library is full.\n");
        return;
    }

    printf("Enter song title: ");
    fgets(library[*count].title, 50, stdin);
    library[*count].title[strcspn(library[*count].title, "\n")] = '\0';

    printf("Enter artist name: ");
    fgets(library[*count].artist, 50, stdin);
    library[*count].artist[strcspn(library[*count].artist, "\n")] = '\0';

    printf("Enter album name: ");
    fgets(library[*count].album, 50, stdin);
    library[*count].album[strcspn(library[*count].album, "\n")] = '\0';

    printf("Enter year of release: ");
    scanf("%d", &library[*count].year);
    getchar();

    printf("Enter genre: ");
    fgets(library[*count].genre, 50, stdin);
    library[*count].genre[strcspn(library[*count].genre, "\n")] = '\0';

    printf("Enter location: ");
    fgets(library[*count].location, 50, stdin);
    library[*count].location[strcspn(library[*count].location, "\n")] = '\0';

    printf("Enter rating (out of 10): ");
    scanf("%d", &library[*count].rating);
    getchar();

    printf("Song added to library!\n");

    (*count)++;
}

void search_library(struct song library[], int count) {
    char query[50];

    printf("Enter search query: ");
    fgets(query, 50, stdin);
    query[strcspn(query, "\n")] = '\0';

    int found_songs = 0;

    for (int i = 0; i < count; i++) {
        if (strstr(library[i].title, query) != NULL ||
            strstr(library[i].artist, query) != NULL ||
            strstr(library[i].album, query) != NULL ||
            strstr(library[i].genre, query) != NULL ||
            strstr(library[i].location, query) != NULL) {
            printf("-------------------------\n");
            print_song(library[i]);
            found_songs++;
        }
    }

    if (found_songs == 0) {
        printf("No results found!\n");
    }
}

int main() {
    struct song library[50];
    int count = 0;
    int choice;

    printf("Welcome to the Music Library Management System!\n");

    do {
        printf("\nMenu:\n");
        printf("1. Add song to library\n");
        printf("2. Search library\n");
        printf("3. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                add_song(library, &count);
                break;
            case 2:
                search_library(library, count);
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}