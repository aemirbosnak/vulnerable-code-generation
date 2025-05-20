//FormAI DATASET v1.0 Category: Music Library Management System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Album {
    char title[50];
    char artist[50];
    char genre[20];
    int releaseYear;
};

void addAlbum(struct Album *library, int *numberOfAlbums);
void removeAlbum(struct Album *library, int *numberOfAlbums);
void searchAlbum(struct Album *library, int numberOfAlbums);
void printAlbum(struct Album album);

int main() {
    struct Album library[100];
    int numberOfAlbums = 0;
    char selection;

    while (1) {
        printf("\n─────── C MUSIC LIBRARY MANAGEMENT SYSTEM ───────\n\n");
        printf("1. Add Album\n");
        printf("2. Remove Album\n");
        printf("3. Search Album\n");
        printf("4. Print Library\n");
        printf("5. Exit\n\n");
        printf("Enter selection (1-5): ");

        scanf(" %c", &selection);

        switch(selection) {
            case '1': addAlbum(library, &numberOfAlbums);
                      break;
            case '2': removeAlbum(library, &numberOfAlbums);
                      break;
            case '3': searchAlbum(library, numberOfAlbums);
                      break;
            case '4': printf("\nLibrary:\n\n");
                      for (int i = 0; i < numberOfAlbums; i++) {
                          printAlbum(library[i]);
                      }
                      break;
            case '5': printf("\nExiting program...\n");
                      exit(0);
                      break;
            default: printf("\nInvalid selection. Please enter a number from 1-5.\n");
                     break;
        }
    }

    return 0;
}

void addAlbum(struct Album *library, int *numberOfAlbums) {
    if (*numberOfAlbums == 100) {
        printf("\nCannot add album. Library is full.\n");
        return;
    }

    printf("\nEnter album title: ");
    scanf("\n%[^\n]", library[*numberOfAlbums].title);
    printf("Enter artist name: ");
    scanf("\n%[^\n]", library[*numberOfAlbums].artist);
    printf("Enter genre: ");
    scanf("\n%[^\n]", library[*numberOfAlbums].genre);
    printf("Enter release year: ");
    scanf("%d", &library[*numberOfAlbums].releaseYear);

    (*numberOfAlbums)++;
}

void removeAlbum(struct Album *library, int *numberOfAlbums) {
    char title[50];
    int found = 0;

    printf("\nEnter album title to remove: ");
    scanf("\n%[^\n]", title);

    for (int i = 0; i < *numberOfAlbums; i++) {
        if (strcmp(library[i].title, title) == 0) {
            found = 1;
            printf("\nRemoved album:\n\n");
            printAlbum(library[i]);
            for (int j = i; j < *numberOfAlbums - 1; j++) {
                library[j] = library[j+1];
            }
            (*numberOfAlbums)--;
            break;
        }
    }

    if (!found) {
        printf("\nAlbum not found.\n");
    }
}

void searchAlbum(struct Album *library, int numberOfAlbums) {
    char title[50];
    int found = 0;

    printf("\nEnter album title to search: ");
    scanf("\n%[^\n]", title);

    for (int i = 0; i < numberOfAlbums; i++) {
        if (strcmp(library[i].title, title) == 0) {
            found = 1;
            printf("\nAlbum found:\n\n");
            printAlbum(library[i]);
            break;
        }
    }

    if (!found) {
        printf("\nAlbum not found.\n");
    }
}

void printAlbum(struct Album album) {
    printf("%-30s %-30s %-20s %d\n", album.title, album.artist,
           album.genre, album.releaseYear);
}