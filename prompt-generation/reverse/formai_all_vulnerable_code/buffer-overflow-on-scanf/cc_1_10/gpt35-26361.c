//FormAI DATASET v1.0 Category: Music Library Management System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Song {
    char title[100];
    char artist[50];
    char album[50];
    char genre[20];
    int year;
};

void print_menu();
void add_song(struct Song library[], int *count);
void display_library(struct Song library[], int count);
void search_by_artist(struct Song library[], int count, char *keyword);
void search_by_album(struct Song library[], int count, char *keyword);
void search_by_genre(struct Song library[], int count, char *keyword);
void search_by_year(struct Song library[], int count, int keyword);

int main() {
    struct Song library[100];
    int count = 0;
    int choice;
    char keyword[50];
    int year;

    do {
        print_menu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_song(library, &count);
                break;
            case 2:
                display_library(library, count);
                break;
            case 3:
                printf("Enter artist keyword: ");
                scanf("%s", keyword);
                search_by_artist(library, count, keyword);
                break;
            case 4:
                printf("Enter album keyword: ");
                scanf("%s", keyword);
                search_by_album(library, count, keyword);
                break;
            case 5:
                printf("Enter genre keyword: ");
                scanf("%s", keyword);
                search_by_genre(library, count, keyword);
                break;
            case 6:
                printf("Enter year: ");
                scanf("%d", &year);
                search_by_year(library, count, year);
                break;
            case 7:
                printf("Exiting program...");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 7);

    return 0;
}

void print_menu() {
    printf("------------\n");
    printf("Music Library Management System\n");
    printf("------------\n");
    printf("1. Add Song\n");
    printf("2. Display Library\n");
    printf("3. Search by Artist\n");
    printf("4. Search by Album\n");
    printf("5. Search by Genre\n");
    printf("6. Search by Year\n");
    printf("7. Exit\n");
    printf("------------\n");
    printf("Enter your choice: ");
}

void add_song(struct Song library[], int *count) {
    if (*count >= 100) {
        printf("Library is full. Cannot add more songs.\n");
        return;
    }

    struct Song new_song;
    printf("Enter title: ");
    scanf(" %[^\n]s", new_song.title);
    printf("Enter artist: ");
    scanf(" %[^\n]s", new_song.artist);
    printf("Enter album: ");
    scanf(" %[^\n]s", new_song.album);
    printf("Enter genre: ");
    scanf(" %[^\n]s", new_song.genre);
    printf("Enter year: ");
    scanf("%d", &new_song.year);

    library[*count] = new_song;
    (*count)++;

    printf("Song added successfully.\n");
}

void display_library(struct Song library[], int count) {
    printf("------------\n");
    printf("Music Library\n");
    printf("------------\n");

    if (count == 0) {
        printf("Library is empty.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("%d. %s - %s (%s, %d)\n", i+1, library[i].title, library[i].artist, library[i].album, library[i].year);
    }
}

void search_by_artist(struct Song library[], int count, char *keyword) {
    printf("------------\n");
    printf("Search by Artist\n");
    printf("------------\n");

    int results_count = 0;
    for (int i = 0; i < count; i++) {
        if (strstr(library[i].artist, keyword) != NULL) {
            printf("%d. %s - %s (%s, %d)\n", results_count+1, library[i].title, library[i].artist, library[i].album, library[i].year);
            results_count++;
        }
    }

    if (results_count == 0) {
        printf("No songs found.\n");
    }

    printf("------------\n");
}

void search_by_album(struct Song library[], int count, char *keyword) {
    printf("------------\n");
    printf("Search by Album\n");
    printf("------------\n");

    int results_count = 0;
    for (int i = 0; i < count; i++) {
        if (strstr(library[i].album, keyword) != NULL) {
            printf("%d. %s - %s (%s, %d)\n", results_count+1, library[i].title, library[i].artist, library[i].album, library[i].year);
            results_count++;
        }
    }

    if (results_count == 0) {
        printf("No songs found.\n");
    }

    printf("------------\n");
}

void search_by_genre(struct Song library[], int count, char *keyword) {
    printf("------------\n");
    printf("Search by Genre\n");
    printf("------------\n");

    int results_count = 0;
    for (int i = 0; i < count; i++) {
        if (strstr(library[i].genre, keyword) != NULL) {
            printf("%d. %s - %s (%s, %d)\n", results_count+1, library[i].title, library[i].artist, library[i].album, library[i].year);
            results_count++;
        }
    }

    if (results_count == 0) {
        printf("No songs found.\n");
    }

    printf("------------\n");
}

void search_by_year(struct Song library[], int count, int keyword) {
    printf("------------\n");
    printf("Search by Year\n");
    printf("------------\n");

    int results_count = 0;
    for (int i = 0; i < count; i++) {
        if (library[i].year == keyword) {
            printf("%d. %s - %s (%s, %d)\n", results_count+1, library[i].title, library[i].artist, library[i].album, library[i].year);
            results_count++;
        }
    }

    if (results_count == 0) {
        printf("No songs found.\n");
    }

    printf("------------\n");
}