//FormAI DATASET v1.0 Category: Music Library Management System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining a structure to hold album details
struct Album {
    char title[100];
    char artist[100];
    char genre[100];
    int year;
};

// Defining a function to add new album to the library
void add_album(struct Album *lib, int *count) {
    printf("Enter album details:\n");
    printf("Title: ");
    scanf(" %[^\n]s", lib[*count].title);
    printf("Artist: ");
    scanf(" %[^\n]s", lib[*count].artist);
    printf("Genre: ");
    scanf(" %[^\n]s", lib[*count].genre);
    printf("Year: ");
    scanf("%d", &lib[*count].year);
    (*count)++;
    printf("Album added successfully!\n\n");
}

// Defining a function to search for an album by title
void search_by_title(struct Album *lib, int count) {
    char query[100];
    printf("Enter album title to search: ");
    scanf(" %[^\n]s", query);
    for(int i=0;i<count;i++) {
        if(!strcmp(lib[i].title, query)) {
            printf("\nAlbum found!\n");
            printf("Title: %s, Artist: %s, Genre: %s, Year: %d\n", lib[i].title, lib[i].artist, lib[i].genre, lib[i].year);
            return;
        }
    }
    printf("Album not found in the library!\n");
}

int main() {
    struct Album library[100];
    int count = 0;

    printf("\n\t\tWelcome to C Music Library Management System!");
    printf("\n\t\t=============================================\n\n");

    while(1) {
        printf("Enter your choice:\n");
        printf("1. Add new album\n");
        printf("2. Search album by title\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1: add_album(library, &count); break;
            case 2: search_by_title(library, count); break;
            case 3: printf("\nThank you for using C Music Library Management System!\n"); exit(0);
            default: printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}