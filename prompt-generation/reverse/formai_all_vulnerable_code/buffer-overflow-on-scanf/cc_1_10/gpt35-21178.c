//FormAI DATASET v1.0 Category: Music Library Management System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Struct for Music Library */
typedef struct song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
} t_song;

/* Global variables */
t_song library[100]; // Max limit of 100 songs
int song_count = 0;

/* Function to add new song to library */
void add_song() {
    char temp[50];
    printf("Enter song title: ");
    fgets(temp, 50, stdin);
    sscanf(temp, "%[^\n]", library[song_count].title);
    printf("Enter artist name: ");
    fgets(temp, 50, stdin);
    sscanf(temp, "%[^\n]", library[song_count].artist);
    printf("Enter album name: ");
    fgets(temp, 50, stdin);
    sscanf(temp, "%[^\n]", library[song_count].album);
    printf("Enter release year: ");
    scanf("%d", &library[song_count].year);
    getchar(); // clear buffer
    song_count++;
    printf("\nSong added successfully!\n");
    printf("------------------------\n\n");
}

/* Function to search for song by title */
void search_song() {
    char search_title[50];
    int found = 0;
    printf("Enter song title to search: ");
    fgets(search_title, 50, stdin);
    sscanf(search_title, "%[^\n]", search_title);
    printf("\nSearch Results:\n");
    printf("------------------------\n");
    for (int i = 0; i < song_count; i++) {
        if (strcmp(library[i].title, search_title) == 0) {
            printf("Title    : %s\n", library[i].title);
            printf("Artist   : %s\n", library[i].artist);
            printf("Album    : %s\n", library[i].album);
            printf("Year     : %d\n", library[i].year);
            printf("------------------------\n");
            found = 1;
        }
    }
    if (!found) {
        printf("No matching results found.\n");
        printf("------------------------\n");
    }
}

/* Function to display all songs in library */
void display_library() {
    printf("\nAll Songs:\n");
    printf("------------------------\n");
    for (int i = 0; i < song_count; i++) {
        printf("Title    : %s\n", library[i].title);
        printf("Artist   : %s\n", library[i].artist);
        printf("Album    : %s\n", library[i].album);
        printf("Year     : %d\n", library[i].year);
        printf("------------------------\n");
    }
}

/* Main function */
int main() {
    int choice;
    do {
        printf("Welcome to Music Library Management System\n\n");
        printf("1. Add new song\n");
        printf("2. Search for a song\n");
        printf("3. Display all songs in the library\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear buffer
        switch (choice) {
            case 1:
                add_song();
                break;
            case 2:
                search_song();
                break;
            case 3:
                display_library();
                break;
            case 4:
                printf("\nThank you for using Music Library Management System!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (1);
    return 0;
}