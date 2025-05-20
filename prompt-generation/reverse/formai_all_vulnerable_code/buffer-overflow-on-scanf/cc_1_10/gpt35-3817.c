//FormAI DATASET v1.0 Category: Music Library Management System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct album {
    char title[50];
    char artist[50];
    char genre[20];
    int year;
    float rating;
} Album;

void addAlbum(Album **library, int *size);
void deleteAlbum(Album **library, int *size);
void printLibrary(Album *library, int size);
void rateAlbum(Album *library, int size);

int main() {
    Album *library = NULL;
    int size = 0, choice;

    while(1) {
        printf("\nWelcome to the Surreal Music Library Management System!\n");
        printf("\n1. Add Album\n2. Delete Album\n3. Print Library\n4. Rate Album\n5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: 
                addAlbum(&library, &size);
                break;
            case 2: 
                deleteAlbum(&library, &size);
                break;
            case 3:
                printLibrary(library, size);
                break;
            case 4:
                rateAlbum(library, size);
                break;
            case 5:
                printf("\nThank you for using the Surreal Music Library Management System!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}

void addAlbum(Album **library, int *size) {
    Album *temp;
    temp = (Album*) malloc((*size + 1) * sizeof(Album));

    for(int i = 0; i < *size; i++) {
        temp[i] = (*library)[i];
    }

    printf("\nEnter album title: ");
    scanf(" %[^\n]", temp[*size].title);
    printf("Enter artist name: ");
    scanf(" %[^\n]", temp[*size].artist);
    printf("Enter genre: ");
    scanf(" %[^\n]", temp[*size].genre);
    printf("Enter year of release: ");
    scanf("%d", &temp[*size].year);
    printf("Enter your rating out of 5: ");
    scanf("%f", &temp[*size].rating);
    printf("\nAlbum added successfully!");

    free(*library);
    *size += 1;
    *library = temp;
}

void deleteAlbum(Album **library, int *size) {
    Album *temp;
    temp = (Album*) malloc((*size - 1) * sizeof(Album));

    printf("\nEnter the title of the album you want to delete: ");
    char title[50];
    scanf(" %[^\n]", title);

    int found = 0;
    for(int i = 0, j = 0; i < *size; i++) {
        if(strcmp((*library)[i].title, title) == 0) {
            found = 1;
            continue;
        }
        temp[j++] = (*library)[i];
    }

    if(found) {
        printf("\nAlbum deleted successfully!");
        free(*library);
        *size -= 1;
        *library = temp;
    } else {
        printf("\nAlbum not found!");
        free(temp);
    }
}

void printLibrary(Album *library, int size) {
    printf("\n\n\t\tSurreal Music Library\n\n");
    printf("Title\t\tArtist\t\tGenre\t\tYear\t\tRating\n");

    for(int i = 0; i < size; i++) {
        printf("%s\t\t%s\t\t%s\t%d\t\t%.2f\n", library[i].title, library[i].artist, library[i].genre, library[i].year, library[i].rating);
    }
}

void rateAlbum(Album *library, int size) {
    printf("\nEnter the album title you want to rate: ");
    char title[50];
    scanf(" %[^\n]", title);

    int found = 0;
    for(int i = 0; i < size; i++) {
        if(strcmp(library[i].title, title) == 0) {
            found = 1;
            printf("Enter your new rating out of 5: ");
            scanf("%f", &library[i].rating);
            printf("\nAlbum rated successfully!\n");
            break;
        }
    }

    if(!found) {
        printf("\nAlbum not found!");
    }
}