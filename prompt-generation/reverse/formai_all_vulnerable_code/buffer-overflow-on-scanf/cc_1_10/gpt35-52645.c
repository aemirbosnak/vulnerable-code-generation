//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Struct for Music Library
 */
struct MusicLibrary {
    char artist[50];
    char album[50];
    char genre[20];
    int year;
};

/*
 * Function to add a new album to the library
 */
void addAlbum(struct MusicLibrary *library, int *size) {
    // Get input from user
    printf("Enter the artist name: ");
    scanf("%s", library[*size].artist);

    printf("Enter the album name: ");
    scanf("%s", library[*size].album);

    printf("Enter the genre: ");
    scanf("%s", library[*size].genre);

    printf("Enter the release year: ");
    scanf("%d", &library[*size].year);

    // Increment the size of the library
    (*size)++;
}

/*
 * Function to display all albums in the library
 */
void displayLibrary(struct MusicLibrary *library, int size) {
    printf("\n\nArtist\t\tAlbum\t\tGenre\t\tYear\n\n");
    for (int i = 0; i < size; i++) {
        printf("%s\t\t%s\t\t%s\t\t%d\n", library[i].artist, library[i].album, library[i].genre, library[i].year);
    }
    printf("\n");
}

/*
 * Main function
 */
int main() {
    struct MusicLibrary library[100];
    int size = 0;
    int choice;

    do {
        printf("Music Library Management System\n");
        printf("1. Add new album\n");
        printf("2. View library\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addAlbum(library, &size);
                break;
            case 2:
                displayLibrary(library, size);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while(1);

    return 0;
}