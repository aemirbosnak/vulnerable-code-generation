//FormAI DATASET v1.0 Category: Music Library Management System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for storing music information
struct music {
    char title[50];
    char artist[50];
    char genre[20];
    int year;
};

// Function to add a new music entry to the library
int add_music(struct music *lib, int size) {
    printf("Enter the title: ");
    scanf("%s", lib[size].title);
    printf("Enter the artist: ");
    scanf("%s", lib[size].artist);
    printf("Enter the genre: ");
    scanf("%s", lib[size].genre);
    printf("Enter the year: ");
    scanf("%d", &lib[size].year);
    printf("New music added to the library!\n");
    return size+1;
}

// Function to search for a music entry in the library
void search_music(struct music *lib, int size) {
    char keyword[50];
    printf("Enter a keyword to search for: ");
    scanf("%s", keyword);

    int count = 0;
    for (int i = 0; i < size; i++) {
        if (strstr(lib[i].title, keyword) != NULL || strstr(lib[i].artist, keyword) != NULL || strstr(lib[i].genre, keyword) != NULL) {
            printf("Title: %s\n", lib[i].title);
            printf("Artist: %s\n", lib[i].artist);
            printf("Genre: %s\n", lib[i].genre);
            printf("Year: %d\n\n", lib[i].year);
            count++;
        }
    }
    if (count == 0) {
        printf("No results found.\n");
    }
}

// Function to sort the music library by title
void sort_music(struct music *lib, int size) {
    for (int i = 0; i < size-1; i++) {
        for (int j = i+1; j < size; j++) {
            if (strcmp(lib[i].title, lib[j].title) > 0) {
                struct music temp = lib[i];
                lib[i] = lib[j];
                lib[j] = temp;
            }
        }
    }
    printf("Music library sorted by title!\n");
}

int main() {
    struct music library[100];
    int count = 0;

    printf("What would you like to do?\n");
    printf("1. Add music\n");
    printf("2. Search for music\n");
    printf("3. Sort library by title\n");
    printf("4. Exit\n");

    int choice;
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                count = add_music(library, count);
                break;
            case 2:
                search_music(library, count);
                break;
            case 3:
                sort_music(library, count);
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
        printf("What would you like to do next?\n");
    }
    return 0;
}