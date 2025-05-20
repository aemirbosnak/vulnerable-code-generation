//FormAI DATASET v1.0 Category: Music Library Management System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Album {
    char name[50];
    char artist[50];
    int year;
};

void displayAlbums(struct Album albums[], int size);
void addAlbum(struct Album albums[], int *size);
void searchAlbums(struct Album albums[], int size);

int main() {
    printf("Welcome to the Happy Music Library Management System!\n");

    int size = 0;
    struct Album albums[100];

    int option = 0;
    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Display all albums\n");
        printf("2. Add a new album\n");
        printf("3. Search for an album\n");
        printf("4. Exit\n");
        printf("Your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                displayAlbums(albums, size);
                break;
            case 2:
                addAlbum(albums, &size);
                break;
            case 3:
                searchAlbums(albums, size);
                break;
            case 4:
                printf("\nHave a happy day! Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid option! Please try again.\n");
        }
    } while (option != 4);

    return 0;
}

void displayAlbums(struct Album albums[], int size) {
    if (size == 0) {
        printf("\nThere are no albums in the library yet.\n");
    } else {
        printf("\nAlbums in the library:\n");
        for (int i = 0; i < size; i++) {
            printf("%d. \"%s\" by %s (%d)\n", i+1, albums[i].name, albums[i].artist, albums[i].year);
        }
    }
}

void addAlbum(struct Album albums[], int *size) {
    printf("\nEnter album details:\n");
    printf("Name: ");
    scanf(" %[^\n]s", albums[*size].name);
    printf("Artist: ");
    scanf(" %[^\n]s", albums[*size].artist);
    printf("Year: ");
    scanf("%d", &albums[*size].year);
    printf("\n\"%s\" by %s (%d) has been added to the library.\n", albums[*size].name, albums[*size].artist, albums[*size].year);
    (*size)++;
}

void searchAlbums(struct Album albums[], int size) {
    if (size == 0) {
        printf("\nThere are no albums in the library yet.\n");
    } else {
        char searchName[50];
        printf("\nEnter the name of the album you want to search for: ");
        scanf(" %[^\n]s", searchName);

        int found = 0;
        for (int i = 0; i < size; i++) {
            if (strcmp(searchName, albums[i].name) == 0) {
                printf("\n\"%s\" by %s (%d) was found in the library.\n", albums[i].name, albums[i].artist, albums[i].year);
                found = 1;
            }
        }

        if (!found) {
            printf("\n\"%s\" was not found in the library.\n", searchName);
        }
    }
}