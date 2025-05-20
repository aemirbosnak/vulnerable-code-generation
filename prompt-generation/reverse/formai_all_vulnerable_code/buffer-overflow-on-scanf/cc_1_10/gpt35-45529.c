//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Romeo and Juliet
// Romeo and Juliet: A Music Library System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char artistName[50];
    char albumName[50];
    char genre[20];
    int numTracks;
    float price;
} album;

void addAlbum(album **library, int *numAlbums) {
    album *newAlbum = (album*) malloc(sizeof(album));
    printf("\nEnter artist name: ");
    scanf("%s", newAlbum->artistName);
    printf("Enter album name: ");
    scanf("%s", newAlbum->albumName);
    printf("Enter genre: ");
    scanf("%s", newAlbum->genre);
    printf("Enter number of tracks: ");
    scanf("%d", &newAlbum->numTracks);
    printf("Enter price: ");
    scanf("%f", &newAlbum->price);

    (*numAlbums)++;
    *library = (album*) realloc(*library, (*numAlbums)*sizeof(album));
    *(*library+(*numAlbums)-1) = *newAlbum;

    printf("\nAdded \"%s - %s\" to the library.\n", newAlbum->artistName, newAlbum->albumName);
}

void displayLibrary(album *library, int numAlbums) {
    printf("\n%-20s %-20s %-20s %10s %10s\n", "Artist", "Album", "Genre", "Tracks", "Price");
    printf("-------------------------------------------------------------------------------------\n");
    for(int i = 0; i < numAlbums; i++) {
        printf("%-20s %-20s %-20s %10d %10.2f\n", (library+i)->artistName, (library+i)->albumName, (library+i)->genre, (library+i)->numTracks, (library+i)->price);
    }
}

void searchAlbum(album *library, int numAlbums) {
    char searchTerm[50];
    printf("\nEnter search term: ");
    scanf("%s", searchTerm);

    for(int i = 0; i < numAlbums; i++) {
        if(strstr((library+i)->artistName, searchTerm) || strstr((library+i)->albumName, searchTerm) || strstr((library+i)->genre, searchTerm)) {
            printf("\nFound \"%s - %s\" in the library.\n", (library+i)->artistName, (library+i)->albumName);
            return;
        }
    }

    printf("\nNo albums found in the library.\n");
}

int main() {
    album *library = NULL;
    int numAlbums = 0;
    int choice = 0;

    do {
        printf("\nMusic Library System\n");
        printf("1) Add album\n");
        printf("2) Display library\n");
        printf("3) Search album\n");
        printf("4) Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addAlbum(&library, &numAlbums);
                break;
            case 2:
                if(numAlbums == 0) {
                    printf("\nThere are no albums in the library.\n");
                } else {
                    displayLibrary(library, numAlbums);
                }
                break;
            case 3:
                if(numAlbums == 0) {
                    printf("\nThere are no albums in the library.\n");
                } else {
                    searchAlbum(library, numAlbums);
                }
                break;
            case 4:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice.\n");
        }
    } while(choice != 4);

    free(library);

    return 0;
}