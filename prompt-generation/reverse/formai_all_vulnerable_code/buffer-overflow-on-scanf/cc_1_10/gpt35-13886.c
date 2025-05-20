//FormAI DATASET v1.0 Category: Music Library Management System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[50];
    char artist[50];
    int year;
    char genre[20];
} song;

song library[1000];
int num_songs = 0;

void add_song()
{
    printf("Enter song title:\n");
    scanf("%s", library[num_songs].title);
    printf("Enter artist name:\n");
    scanf("%s", library[num_songs].artist);
    printf("Enter year of release:\n");
    scanf("%d", &library[num_songs].year);
    printf("Enter genre:\n");
    scanf("%s", library[num_songs].genre);
    num_songs++;
    printf("\nSong added to library!\n\n");
}

void search_library()
{
    char search_term[50];
    int results = 0;
    printf("Enter search term:\n");
    scanf("%s", search_term);
    for (int i = 0; i < num_songs; i++) {
        if (strstr(library[i].title, search_term) != NULL ||
            strstr(library[i].artist, search_term) != NULL ||
            strstr(library[i].genre, search_term) != NULL)
        {
            printf("%s - %s (%d) - %s\n",
                   library[i].artist, library[i].title,
                   library[i].year, library[i].genre);
            results++;
        }
    }
    if (results == 0) {
        printf("No results found for '%s'\n\n", search_term);
    } else {
        printf("%d results found for '%s'\n\n", results, search_term);
    }
}

void display_library()
{
    for (int i = 0; i < num_songs; i++) {
        printf("%s - %s (%d) - %s\n",
               library[i].artist, library[i].title,
               library[i].year, library[i].genre);
    }
    printf("\n");
}

int main()
{
    int choice;
    while (1) {
        printf("Welcome to the Music Library Management System!\n");
        printf("1. Add song to library\n");
        printf("2. Search library\n");
        printf("3. Display library\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                add_song();
                break;
            case 2:
                search_library();
                break;
            case 3:
                display_library();
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n\n");
                break;
        }
    }

    return 0;
}