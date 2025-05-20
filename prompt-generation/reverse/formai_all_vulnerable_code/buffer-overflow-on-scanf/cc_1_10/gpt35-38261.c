//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Struct for holding music album information */
typedef struct music {
    char artist[50];
    char album[50];
    int year;
    char genre[20];
} Music;

/* Function to add an album to the library */
void addAlbum(Music *library, int *size) {
    printf("\nAdding a new album:\n");
    printf("Enter artist name: ");
    scanf("%s", library[*size].artist);
    printf("Enter album name: ");
    scanf("%s", library[*size].album);
    printf("Enter year of release: ");
    scanf("%d", &library[*size].year);
    printf("Enter genre: ");
    scanf("%s", library[*size].genre);
    (*size)++;
    printf("\nAlbum added.\n");
}

/* Function to display all albums in the library */
void displayLibrary(Music *library, int size) {
    printf("\nCurrent music library:\n");
    printf("-----------------------\n");
    for (int i = 0; i < size; i++) {
        printf("%s - %s (%d) [%s]\n", library[i].artist, library[i].album, library[i].year, library[i].genre);
    }
}

/* Function to search for an album in the library */
void searchAlbum(Music *library, int size) {
    char search[50];
    printf("\nEnter artist or album name to search: ");
    scanf("%s", search);
    printf("\nSearch results:\n");
    printf("----------------\n");
    for (int i = 0; i < size; i++) {
        if (strcmp(search, library[i].artist) == 0 || strcmp(search, library[i].album) == 0) {
            printf("%s - %s (%d) [%s]\n", library[i].artist, library[i].album, library[i].year, library[i].genre);
        }
    }
}

/* Main function */
int main() {
    Music library[100];
    int size = 0;
    char choice;
    printf("Welcome to the Cyberpunk Music Library Management System.\n\n");

    while (1) {
        printf("Select an option:\n");
        printf("1. Add an album\n");
        printf("2. Display library\n");
        printf("3. Search for an album\n");
        printf("4. Exit\n-> ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                addAlbum(library, &size);
                break;
            case '2':
                displayLibrary(library, size);
                break;
            case '3':
                searchAlbum(library, size);
                break;
            case '4':
                printf("\nExiting program.\n");
                exit(0);
                break;
            default:
                printf("\nInvalid input.\n");
                break;
        }
    }

    return 0;
}