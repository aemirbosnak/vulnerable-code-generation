//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for a music album
struct Album {
    char name[100];
    char artist[100];
    char genre[50];
    int year;
};

// Define a struct for a music library
struct Library {
    struct Album *albums;
    int num_albums;
};

// Function to add a new album to the library
void addAlbum(struct Library *library) {
    // Create a new album struct
    struct Album newAlbum;
    printf("Enter album name: ");
    scanf("%s", newAlbum.name);
    printf("Enter artist name: ");
    scanf("%s", newAlbum.artist);
    printf("Enter genre: ");
    scanf("%s", newAlbum.genre);
    printf("Enter release year: ");
    scanf("%d", &newAlbum.year);
    
    // Reallocate memory for the albums array
    library->albums = (struct Album*) realloc(library->albums, (library->num_albums + 1) * sizeof(struct Album));
    
    // Add the new album to the library
    library->albums[library->num_albums] = newAlbum;
    library->num_albums++;
    printf("Album added successfully!\n");
}

// Function to remove an album from the library
void removeAlbum(struct Library *library) {
    char albumName[100];
    printf("Enter the name of the album to remove: ");
    scanf("%s", albumName);
    
    // Find the album in the library and remove it
    int index = -1;
    for (int i = 0; i < library->num_albums; i++) {
        if (strcmp(library->albums[i].name, albumName) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Album not found!\n");
    } else {
        for (int i = index; i < library->num_albums - 1; i++) {
            library->albums[i] = library->albums[i+1];
        }
        library->num_albums--;
        printf("Album removed successfully!\n");
    }
}

// Function to print all the albums in the library
void printLibrary(struct Library library) {
    printf("%-30s%-20s%-15s%-10s\n", "Name", "Artist", "Genre", "Year");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < library.num_albums; i++) {
        printf("%-30s%-20s%-15s%-10d\n", library.albums[i].name, library.albums[i].artist, library.albums[i].genre, library.albums[i].year);
    }
}

int main() {
    // Create a new empty music library
    struct Library library;
    library.albums = NULL;
    library.num_albums = 0;
    
    int choice = 0;
    while (choice != 4) {
        printf("\n1. Add album\n2. Remove album\n3. Search library\n4. Exit\n\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addAlbum(&library); // pass the address of the library struct to the function
                break;
            case 2:
                removeAlbum(&library); // pass the address of the library struct to the function
                break;
            case 3:
                printLibrary(library);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    
    // Free the memory allocated for the library albums array
    free(library.albums);
    
    return 0;
}