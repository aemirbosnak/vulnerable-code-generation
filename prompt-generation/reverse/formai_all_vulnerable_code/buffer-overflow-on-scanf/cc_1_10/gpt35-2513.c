//FormAI DATASET v1.0 Category: Music Library Management System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold album information
typedef struct Album {
    char title[50];
    char artist[50];
    int year;
} Album;

// Define a function to display the options menu
void displayMenu() {
    printf("\n\nWelcome to the Music Library Management System\n\n");
    printf("1. Add a new album\n");
    printf("2. Remove an album\n");
    printf("3. Search for an album\n");
    printf("4. Display all albums\n");
    printf("5. Quit\n\n");
}

// Define a function to add a new album
void addAlbum(Album *library, int *numAlbums) {
    char title[50], artist[50];
    int year;
    
    printf("Enter album title: ");
    scanf("%s", title);
    printf("Enter artist name: ");
    scanf("%s", artist);
    printf("Enter release year: ");
    scanf("%d", &year);

    // Create a new album struct and add it to the library
    Album newAlbum = {title, artist, year};
    library[*numAlbums] = newAlbum;
    (*numAlbums)++;
    
    printf("Album added to library!\n");
}

// Define a function to remove an album
void removeAlbum(Album *library, int *numAlbums) {
    char title[50], artist[50];
    int year;
    
    printf("Enter album title: ");
    scanf("%s", title);
    printf("Enter artist name: ");
    scanf("%s", artist);
    printf("Enter release year: ");
    scanf("%d", &year);

    // Loop through the library and find the matching album
    int indexToRemove = -1;
    for (int i = 0; i < *numAlbums; i++) {
        Album currentAlbum = library[i];
        if (strcmp(currentAlbum.title, title) == 0 && strcmp(currentAlbum.artist, artist) == 0 && currentAlbum.year == year) {
            indexToRemove = i;
            break;
        }
    }

    // If an album was found, remove it from the library
    if (indexToRemove != -1) {
        for (int i = indexToRemove; i < *numAlbums - 1; i++) {
            library[i] = library[i+1];
        }
        (*numAlbums)--;
        printf("Album removed from library!\n");
    } else {
        printf("Album not found in library.\n");
    }
}

// Define a function to search for an album
void searchAlbum(Album *library, int numAlbums) {
    char title[50], artist[50];
    int year;
    
    printf("Enter album title: ");
    scanf("%s", title);
    printf("Enter artist name: ");
    scanf("%s", artist);
    printf("Enter release year: ");
    scanf("%d", &year);

    // Loop through the library and find the matching album
    int indexToDisplay = -1;
    for (int i = 0; i < numAlbums; i++) {
        Album currentAlbum = library[i];
        if (strcmp(currentAlbum.title, title) == 0 && strcmp(currentAlbum.artist, artist) == 0 && currentAlbum.year == year) {
            indexToDisplay = i;
            break;
        }
    }

    // If an album was found, display its information
    if (indexToDisplay != -1) {
        Album foundAlbum = library[indexToDisplay];
        printf("\nTitle: %s\n", foundAlbum.title);
        printf("Artist: %s\n", foundAlbum.artist);
        printf("Year: %d\n", foundAlbum.year);
    } else {
        printf("Album not found in library.\n");
    }
}

// Define a function to display all albums in the library
void displayLibrary(Album *library, int numAlbums) {
    if (numAlbums == 0) {
        printf("Library is empty.\n");
    } else {
        for (int i = 0; i < numAlbums; i++) {
            Album currentAlbum = library[i];
            printf("\nTitle: %s\n", currentAlbum.title);
            printf("Artist: %s\n", currentAlbum.artist);
            printf("Year: %d\n", currentAlbum.year);
        }
    }
}

int main() {
    // Define an array to hold the albums in the library
    Album library[50];
    int numAlbums = 0;

    // Display the options menu and prompt the user for input
    int choice = 0;
    while (choice != 5) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addAlbum(library, &numAlbums);
                break;
            case 2:
                removeAlbum(library, &numAlbums);
                break;
            case 3:
                searchAlbum(library, numAlbums);
                break;
            case 4:
                displayLibrary(library, numAlbums);
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }

    return 0;
}