//FormAI DATASET v1.0 Category: Music Library Management System ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure for a single music album
struct album {
    char name[50];
    char artist[50];
    char genre[20];
    int year;
};

// Function to add a new album to the library
void add_album(struct album *library, int *num_albums) {
    printf("Enter album name: ");
    scanf("%s", library[*num_albums].name);
    printf("Enter artist name: ");
    scanf("%s", library[*num_albums].artist);
    printf("Enter album genre: ");
    scanf("%s", library[*num_albums].genre);
    printf("Enter release year: ");
    scanf("%d", &library[*num_albums].year);
    (*num_albums)++;
    printf("Album added successfully!\n");
}

// Function to remove an album from the library
void remove_album(struct album *library, int *num_albums) {
    char name[50];
    printf("Enter album name: ");
    scanf("%s", name);
    for (int i=0; i<*num_albums; i++) {
        if (strcmp(library[i].name, name) == 0) {
            // Shift all the albums after the removed album one position to the left
            for (int j=i; j<*num_albums-1; j++) {
                strcpy(library[j].name, library[j+1].name);
                strcpy(library[j].artist, library[j+1].artist);
                strcpy(library[j].genre, library[j+1].genre);
                library[j].year = library[j+1].year;
            }
            (*num_albums)--;
            printf("Album removed successfully!\n");
            return;
        }
    }
    printf("Album not found in library!\n");
}

// Function to display the list of albums in the library
void display_library(struct album *library, int num_albums) {
    printf("Name\t\tArtist\t\tGenre\t\tYear\n");
    for (int i=0; i<num_albums; i++) {
        printf("%s\t\t%s\t\t%s\t\t%d\n", library[i].name, library[i].artist, library[i].genre, library[i].year);
    }
}

int main() {
    struct album library[50];   // maximum of 50 albums can be stored
    int num_albums = 0;         // number of albums currently in the library
    int choice;
    while (1) {
        printf("\n");
        printf("Welcome to the C Music Library Management System!\n");
        printf("1. Add an album\n");
        printf("2. Remove an album\n");
        printf("3. Display the library\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_album(library, &num_albums);
                break;
            case 2:
                remove_album(library, &num_albums);
                break;
            case 3:
                display_library(library, num_albums);
                break;
            case 4:
                printf("Thank you for using the Music Library Management System!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}