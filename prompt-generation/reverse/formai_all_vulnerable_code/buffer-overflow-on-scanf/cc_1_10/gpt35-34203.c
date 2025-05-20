//FormAI DATASET v1.0 Category: Music Library Management System ; Style: excited
// Welcome to the C Music Library Management System!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALBUMS 100

struct Album {
    char name[30];
    char artist[30];
    char genre[30];
};

// Function prototypes
void addAlbum(struct Album albums[], int *numAlbums);
void displayAlbums(struct Album albums[], int numAlbums);
void searchAlbums(struct Album albums[], int numAlbums);

int main() {
    // Initialize variables
    struct Album albums[MAX_ALBUMS];
    int numAlbums = 0, choice;

    printf("Welcome to the Music Library Management System!\n");

    do {
        // Display menu options
        printf("\nChoose an option:\n");
        printf("1. Add an album\n");
        printf("2. Display albums\n");
        printf("3. Search albums\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addAlbum(albums, &numAlbums);
                break;
            case 2:
                displayAlbums(albums, numAlbums);
                break;
            case 3:
                searchAlbums(albums, numAlbums);
                break;
            case 4:
                printf("Thank you for using the Music Library Management System!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 4);

    return 0;
}

void addAlbum(struct Album albums[], int *numAlbums) {
    // Check if maximum number of albums has been reached
    if(*numAlbums == MAX_ALBUMS) {
        printf("Maximum number of albums reached.\n");
        return;
    }

    // Prompt user for album details and store in array
    printf("\nEnter album name: ");
    scanf("%s", albums[*numAlbums].name);
    printf("Enter artist name: ");
    scanf("%s", albums[*numAlbums].artist);
    printf("Enter genre: ");
    scanf("%s", albums[*numAlbums].genre);

    *numAlbums += 1;

    printf("Album added!\n");
}

void displayAlbums(struct Album albums[], int numAlbums) {
    // Check if there are any albums to display
    if(numAlbums == 0) {
        printf("\nNo albums to display.\n");
        return;
    }

    printf("\nAlbums in library:\n");
    for(int i = 0; i < numAlbums; i++) {
        printf("%d. %s - %s (%s)\n", i+1, albums[i].name, albums[i].artist, albums[i].genre);
    }
}

void searchAlbums(struct Album albums[], int numAlbums) {
    // Prompt user for search term
    char searchTerm[30];
    printf("\nEnter search term: ");
    scanf("%s", searchTerm);

    // Search albums for matching title or artist
    printf("\nSearch results:\n");
    for(int i = 0; i < numAlbums; i++) {
        if(strstr(albums[i].name, searchTerm) != NULL || strstr(albums[i].artist, searchTerm) != NULL) {
            printf("%d. %s - %s (%s)\n", i+1, albums[i].name, albums[i].artist, albums[i].genre);
        }
    }
}