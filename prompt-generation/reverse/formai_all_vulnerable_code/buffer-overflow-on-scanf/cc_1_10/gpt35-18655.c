//FormAI DATASET v1.0 Category: Music Library Management System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define constants */
#define MAX_LENGTH 100
#define MAX_SONGS 100

/* Define functions */
void display_menu();
void add_song();
void delete_song();
void search_song();
void display_songs();

/* Define structures */
struct Song {
    char title[MAX_LENGTH];
    char artist[MAX_LENGTH];
    char genre[MAX_LENGTH];
    int year;
};

/* Declare global variables */
struct Song music_library[MAX_SONGS];
int num_songs = 0;

int main() {
    display_menu();
    return 0;
}

void display_menu() {
    int option = 0;

    do {
        printf("Music Library Management System\n");
        printf("-------------------------------\n");
        printf("1. Add Song\n");
        printf("2. Delete Song\n");
        printf("3. Search Song\n");
        printf("4. Display Songs\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                add_song();
                break;
            case 2:
                delete_song();
                break;
            case 3:
                search_song();
                break;
            case 4:
                display_songs();
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");

        }
    } while (option != 5);

}

void add_song() {
    printf("Enter the song title: ");
    scanf("%s", music_library[num_songs].title);

    printf("Enter the artist name: ");
    scanf("%s", music_library[num_songs].artist);

    printf("Enter the genre: ");
    scanf("%s", music_library[num_songs].genre);

    printf("Enter the year the song was released: ");
    scanf("%d", &music_library[num_songs].year);

    printf("Song successfully added!\n");

    num_songs++;
}

void delete_song() {
    int i, j;
    char title[MAX_LENGTH];

    printf("Enter the title of the song you want to delete: ");
    scanf("%s", title);

    for (i = 0; i < num_songs; i++) {
        if (strcmp(music_library[i].title, title) == 0) {
            for (j = i; j < num_songs - 1; j++) {
                music_library[j] = music_library[j + 1];
            }

            num_songs--;
            printf("Song successfully deleted!\n");
            return;
        }
    }

    printf("Song not found. Please try again.\n");
}

void search_song() {
    int i;
    char title[MAX_LENGTH];

    printf("Enter the title of the song you want to search: ");
    scanf("%s", title);

    for (i = 0; i < num_songs; i++) {
        if (strcmp(music_library[i].title, title) == 0) {
            printf("Song title: %s\n", music_library[i].title);
            printf("Artist name: %s\n", music_library[i].artist);
            printf("Genre: %s\n", music_library[i].genre);
            printf("Year released: %d\n", music_library[i].year);
            return;
        }
    }

    printf("Song not found. Please try again.\n");
}

void display_songs() {
    int i;

    printf("Song List\n");
    printf("---------\n");

    for (i = 0; i < num_songs; i++) {
        printf("Song title: %s\n", music_library[i].title);
        printf("Artist name: %s\n", music_library[i].artist);
        printf("Genre: %s\n", music_library[i].genre);
        printf("Year released: %d\n\n", music_library[i].year);
    }
}