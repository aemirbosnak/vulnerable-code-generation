//FormAI DATASET v1.0 Category: Music Library Management System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for storing music library information
struct music {
    int id;
    char title[50];
    char artist[50];
    char album[50];
    int year;
};

// Function to display music library information
void display_library(struct music lib[], int size) {
    printf("ID\tTitle\t\tArtist\t\tAlbum\t\tYear\n");
    printf("========================================================\n");
    for(int i=0; i<size; i++) {
        printf("%d\t%s\t\t%s\t\t%s\t\t%d\n", lib[i].id, lib[i].title, lib[i].artist, lib[i].album, lib[i].year);
    }
    printf("========================================================\n");
}

// Function to add new music to the library
void add_music(struct music lib[], int size) {
    printf("Enter the title: ");
    fgets(lib[size].title, 50, stdin);
    printf("Enter the artist: ");
    fgets(lib[size].artist, 50, stdin);
    printf("Enter the album: ");
    fgets(lib[size].album, 50, stdin);
    printf("Enter the year: ");
    scanf("%d", &lib[size].year);
    lib[size].id = size + 1;
    printf("New music added with ID: %d\n", lib[size].id);
}

// Function to search for music by artist
void search_by_artist(struct music lib[], int size) {
    char artist[50];
    printf("Enter the artist name: ");
    fgets(artist, 50, stdin);
    for(int i=0; i<size; i++) {
        if(strcmp(artist, lib[i].artist) == 0) {
            printf("ID: %d\nTitle: %sArtist: %sAlbum: %sYear: %d\n", lib[i].id, lib[i].title, lib[i].artist, lib[i].album, lib[i].year);
        }
    }
}

int main() {
    int choice = 0;  // Variable to store user's choice
    int size = 0;  // Variable to store the size of the music library
    struct music library[100];  // Array to store music library information
    
    while(choice != 4) {
        printf("\n1. Display music library\n2. Add new music\n3. Search by artist\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();  // Consume newline character left in buffer
        switch(choice) {
            case 1:
                display_library(library, size);
                break;
            case 2:
                add_music(library, size);
                size++;
                break;
            case 3:
                search_by_artist(library, size);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}