//FormAI DATASET v1.0 Category: Music Library Management System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing music album information
struct Album {
    char title[100];
    char artist[50];
    int year;
    float rating;
};

int main() {
    int option;
    int numAlbums = 0;
    struct Album *library = NULL;

    // Initial prompt to user
    printf("Welcome to the C Music Library Management System! What would you like to do?\n");

    // Menu options
    printf("1. Add an album\n");
    printf("2. Edit an album\n");
    printf("3. Delete an album\n");
    printf("4. Print all albums\n");
    printf("5. Quit\n");

    // Continuously prompt user until they choose to quit
    while (option != 5) {
        printf("> ");
        scanf("%d", &option);

        switch (option) {
            case 1: // Add an album
                numAlbums++;
                library = (struct Album *) realloc(library, numAlbums * sizeof(struct Album));

                printf("\nEnter album title: ");
                getchar(); // Flush newline from input buffer
                fgets(library[numAlbums - 1].title, 100, stdin);

                printf("Enter artist name: ");
                fgets(library[numAlbums - 1].artist, 50, stdin);

                printf("Enter release year: ");
                scanf("%d", &library[numAlbums - 1].year);

                printf("Enter rating (out of 10): ");
                scanf("%f", &library[numAlbums - 1].rating);

                printf("\nAlbum added successfully!\n");
                break;
            case 2: // Edit an album
                if (numAlbums == 0) {
                    printf("No albums currently in library.\n");
                } else {
                    int editIndex;
                    printf("\nEnter the index of the album to edit: ");
                    scanf("%d", &editIndex);

                    if (editIndex < 1 || editIndex > numAlbums) {
                        printf("Invalid album index.\n");
                    } else {
                        printf("Current title: %s", library[editIndex - 1].title);
                        printf("Enter new title (or press enter to leave unchanged): ");
                        getchar(); // Flush newline from input buffer
                        fgets(library[editIndex - 1].title, 100, stdin);

                        printf("Current artist name: %s", library[editIndex - 1].artist);
                        printf("Enter new artist name (or press enter to leave unchanged): ");
                        fgets(library[editIndex - 1].artist, 50, stdin);

                        printf("Current release year: %d\n", library[editIndex - 1].year);
                        printf("Enter new release year (or enter 0 to leave unchanged): ");
                        scanf("%d", &library[editIndex - 1].year);

                        printf("Current rating (out of 10): %.1f\n", library[editIndex - 1].rating);
                        printf("Enter new rating (out of 10) (or enter 0 to leave unchanged): ");
                        scanf("%f", &library[editIndex - 1].rating);
                    }
                }
                break;
            case 3: // Delete an album
                if (numAlbums == 0) {
                    printf("No albums currently in library.\n");
                } else {
                    int deleteIndex;
                    printf("\nEnter the index of the album to delete: ");
                    scanf("%d", &deleteIndex);

                    if (deleteIndex < 1 || deleteIndex > numAlbums) {
                        printf("Invalid album index.\n");
                    } else {
                        for (int i = deleteIndex - 1; i < numAlbums - 1; i++) {
                            strcpy(library[i].title, library[i + 1].title);
                            strcpy(library[i].artist, library[i + 1].artist);
                            library[i].year = library[i + 1].year;
                            library[i].rating = library[i + 1].rating;
                        }

                        numAlbums--;
                        library = (struct Album *) realloc(library, numAlbums * sizeof(struct Album));

                        printf("\nAlbum deleted successfully!\n");
                    }
                }
                break;
            case 4: // Print all albums
                if (numAlbums == 0) {
                    printf("No albums currently in library.\n");
                } else {
                    printf("\nAlbums in Library:\n");
                    for (int i = 0; i < numAlbums; i++) {
                        printf("%d. Title: %s", i + 1, library[i].title);
                        printf("   Artist: %s", library[i].artist);
                        printf("   Year: %d", library[i].year);
                        printf("   Rating: %.1f/10\n", library[i].rating);
                    }
                }
                break;
            default:
                printf("Invalid option selected. Please try again.\n");
                break;
        }
    }

    // Free allocated memory and exit program
    free(library);
    printf("\nThank you for using the C Music Library Management System!\n");
    return 0;
}