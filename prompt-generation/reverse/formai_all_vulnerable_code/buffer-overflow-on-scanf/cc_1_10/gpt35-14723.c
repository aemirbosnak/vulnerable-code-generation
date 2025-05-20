//FormAI DATASET v1.0 Category: Music Library Management System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50

typedef struct {
    char title[MAX_LENGTH];
    char artist[MAX_LENGTH];
    char genre[MAX_LENGTH];
} Album;

Album albums[10];
int count = 0;

void displayMenu() {
    printf("Welcome to the C Music Library Management System! \n");
    printf("1. Search for an album\n");
    printf("2. Add a new album\n");
    printf("3. Delete an album\n");
    printf("4. Display all albums\n");
    printf("5. Exit\n");
}

void searchAlbum() {
    char searchTerm[MAX_LENGTH];
    int found = 0;
    
    printf("Enter the title of the album you want to search for: ");
    scanf("%s", searchTerm);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(albums[i].title, searchTerm) == 0) {
            printf("Album found!\n");
            printf("Title: %s\n", albums[i].title);
            printf("Artist: %s\n", albums[i].artist);
            printf("Genre: %s\n", albums[i].genre);
            found = 1;
        }
    }
    
    if (!found) {
        printf("Album not found.\n");
    }
}

void addAlbum() {
    Album newAlbum;
    
    printf("Enter the title of the album: ");
    scanf("%s", newAlbum.title);
    
    printf("Enter the artist of the album: ");
    scanf("%s", newAlbum.artist);
    
    printf("Enter the genre of the album: ");
    scanf("%s", newAlbum.genre);
    
    albums[count] = newAlbum;
    count++;
    
    printf("Album added successfully!\n");
}

void deleteAlbum() {
    char searchTerm[MAX_LENGTH];
    int foundIndex = -1;
    
    printf("Enter the title of the album you want to delete: ");
    scanf("%s", searchTerm);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(albums[i].title, searchTerm) == 0) {
            foundIndex = i;
        }
    }
    
    if (foundIndex == -1) {
        printf("Album not found.\n");
    } else {
        for (int i = foundIndex; i < count-1; i++) {
            albums[i] = albums[i+1];
        }
        count--;
        printf("Album deleted successfully!\n");
    }
}

void displayAllAlbums() {
    printf("%-30s%-30s%-30s\n", "Title", "Artist", "Genre");
    printf("--------------------------------------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        printf("%-30s%-30s%-30s\n", albums[i].title, albums[i].artist, albums[i].genre);
    }
}

int main() {
    int choice = 0;
    
    while (choice != 5) {
        displayMenu();
        
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                searchAlbum();
                break;
            case 2:
                addAlbum();
                break;
            case 3:
                deleteAlbum();
                break;
            case 4:
                displayAllAlbums();
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    
    return 0;
}