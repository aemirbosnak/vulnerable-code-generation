//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 50

/* Define struct to hold music details */
struct music {
    char title[MAX_LENGTH];
    char artist[MAX_LENGTH];
    char genre[MAX_LENGTH];
    int year;
};

/* Define function to add new music to library */
struct music add_music() {
    struct music new_music;

    printf("Enter the title: ");
    scanf("%s", new_music.title);
    
    printf("Enter the artist: ");
    scanf("%s", new_music.artist);

    printf("Enter the genre: ");
    scanf("%s", new_music.genre);

    printf("Enter the year: ");
    scanf("%d", &new_music.year);

    return new_music;
}

/* Define function to print all music in library */
void print_all(struct music* library, int count) {
    printf("Music Library:\n");
    for(int i = 0; i < count; i++) {
        printf("Title: %s | Artist: %s | Genre: %s | Year: %d\n", library[i].title, library[i].artist, library[i].genre, library[i].year);
    }
}

/* Define function to search for music by title or artist */
void search(struct music* library, int count) {
    char search_term[MAX_LENGTH];
    printf("Enter a title or artist to search: ");
    scanf("%s", search_term);

    int match_count = 0;
    for (int i = 0; i < count; i++) {
        if (strstr(library[i].title, search_term) != NULL || strstr(library[i].artist, search_term) != NULL) {
            printf("Title: %s | Artist: %s | Genre: %s | Year: %d\n", library[i].title, library[i].artist, library[i].genre, library[i].year);
            match_count++;
        }
    }
    if (match_count == 0) {
        printf("No matches found.\n");
    }
}

int main() {
    struct music library[100];
    int count = 0;
    char selection;

    printf("C Music Library Management System\n");
    printf("------------------------------------------------\n");

    do {
        printf("\nEnter a selection:\n");
        printf("a: add music to library\n");
        printf("p: print all music in library\n");
        printf("s: search for music by title or artist\n");
        printf("q: quit\n");

        scanf(" %c", &selection);

        switch(selection) {
            case 'a':
                library[count] = add_music();
                count++;
                printf("Music added to library.\n");
                break;
            case 'p':
                print_all(library, count);
                break;
            case 's':
                search(library, count);
                break;
            case 'q':
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid selection, try again.\n");
                break;
        }
    } while (selection != 'q');

    return 0;
}