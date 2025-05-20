//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[50];
    char artist[50];    
    int year;
    int duration;
} Song;

Song library[100];
int num_songs = 0;

void add_song() {
    printf("What is the title of the song? ");
    scanf("%s", library[num_songs].title);

    printf("Who is the artist? ");
    scanf("%s", library[num_songs].artist);

    printf("What year was the song released? ");
    scanf("%d", &library[num_songs].year);

    printf("How long is the song (in seconds)? ");
    scanf("%d", &library[num_songs].duration);

    num_songs++;
}

void print_library() {
    printf("Here is your music library:\n");
    for (int i = 0; i < num_songs; i++) {
        printf("%s - %s (%d, %d seconds)\n", library[i].title, library[i].artist, library[i].year, library[i].duration);
    }
}

void search_library() {
    char search_term[50];
    printf("What are you looking for? ");
    scanf("%s", search_term);

    int found = 0;
    for (int i = 0; i < num_songs; i++) {
        if (strstr(library[i].title, search_term) != NULL || strstr(library[i].artist, search_term) != NULL) {
            printf("%s - %s (%d, %d seconds)\n", library[i].title, library[i].artist, library[i].year, library[i].duration);
            found = 1;
        }
    }

    if (!found) {
        printf("No results found.\n");
    }
}

int main() {
    int choice;

    do {
        printf("What would you like to do?\n");
        printf("1. Add a song\n");
        printf("2. Print the library\n");
        printf("3. Search the library\n");
        printf("4. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_song();
                break;
            case 2:
                print_library();
                break;
            case 3:
                search_library();
                break;
            case 4:
                printf("Thanks for using the music library! Come again soon.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}