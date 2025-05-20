//FormAI DATASET v1.0 Category: Music Library Management System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100 // Maximum capacity of the music library
#define MAX_LENGTH 50 // Maximum length of each music name and artist name

typedef struct {
    char name[MAX_LENGTH];
    char artist[MAX_LENGTH];
    int year;
} Music;

Music music_library[MAX_SIZE]; // Global variable for the music library
int library_size = 0; // Global variable for the current size of the music library

// Function to add a music to the library
void add_music(char name[MAX_LENGTH], char artist[MAX_LENGTH], int year) {
    if (library_size == MAX_SIZE) {
        printf("The music library is full.\n");
        return;
    }
    strcpy(music_library[library_size].name, name);
    strcpy(music_library[library_size].artist, artist);
    music_library[library_size].year = year;
    library_size++;
    printf("%s by %s added to the library.\n", name, artist);
}

// Function to search for a music in the library by name
void search_music_by_name(char name[MAX_LENGTH]) {
    int found = 0;
    for (int i = 0; i < library_size; i++) {
        if (strcmp(music_library[i].name, name) == 0) {
            printf("%s by %s, released in %d\n", music_library[i].name, music_library[i].artist, music_library[i].year);
            found = 1;
        }
    }
    if (!found) {
        printf("Music not found.\n");
    }
}

// Function to search for a music in the library by artist
void search_music_by_artist(char artist[MAX_LENGTH]) {
    int found = 0;
    for (int i = 0; i < library_size; i++) {
        if (strcmp(music_library[i].artist, artist) == 0) {
            printf("%s by %s, released in %d\n", music_library[i].name, music_library[i].artist, music_library[i].year);
            found = 1;
        }
    }
    if (!found) {
        printf("Music not found.\n");
    }
}

// Function to print the entire music library
void print_library() {
    if (library_size == 0) {
        printf("The music library is empty.\n");
        return;
    }
    printf("Music Library:\n");
    for (int i = 0; i < library_size; i++) {
        printf("%s by %s, released in %d\n", music_library[i].name, music_library[i].artist, music_library[i].year);
    }
}

int main() {
    char command[MAX_LENGTH];
    char name[MAX_LENGTH];
    char artist[MAX_LENGTH];
    int year;

    printf("Welcome to the Music Library Management System!\n");

    while (1) {
        printf("Enter a command (add/search/print/exit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Enter the music name: ");
            scanf("%s", name);
            printf("Enter the artist name: ");
            scanf("%s", artist);
            printf("Enter the release year: ");
            scanf("%d", &year);
            add_music(name, artist, year);
        } else if (strcmp(command, "search") == 0) {
            printf("Enter the search keyword: ");
            scanf("%s", name);
            if (name[0] < '0' || name[0] > '9') {
                search_music_by_name(name);
            } else {
                search_music_by_artist(name);
            }
        } else if (strcmp(command, "print") == 0) {
            print_library();
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting the program.\n");
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}