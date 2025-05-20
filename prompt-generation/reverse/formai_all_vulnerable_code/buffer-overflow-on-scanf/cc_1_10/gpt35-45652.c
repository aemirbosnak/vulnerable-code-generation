//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Alan Touring
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure to store music album information
struct album {
    char name[50];
    char artist[50];
    char genre[20];
    int year;
};

// Function to display menu
void displayMenu() {
    printf("\n===== C Music Library Management System =====\n\n");
    printf("1. Add New Album\n");
    printf("2. List All Albums\n");
    printf("3. Search Album by Name\n");
    printf("4. Search Album by Artist\n");
    printf("5. Search Album by Genre\n");
    printf("6. Delete Album\n");
    printf("7. Exit\n");
}

// Function to add new album to the library
void addNewAlbum(struct album *albums, int *albumCount) {
    printf("Enter album name: ");
    scanf("%s", albums[*albumCount].name);
    
    printf("Enter artist name: ");
    scanf("%s", albums[*albumCount].artist);
    
    printf("Enter genre: ");
    scanf("%s", albums[*albumCount].genre);
    
    printf("Enter year of release: ");
    scanf("%d", &albums[*albumCount].year);
    
    (*albumCount)++;
    
    printf("\nAlbum added successfully!\n");
}

// Function to list all albums in the library
void listAllAlbums(struct album *albums, int albumCount) {
    if(albumCount == 0) {
        printf("No albums found in the library.\n");
        return;
    }
    
    printf("%-30s %-30s %-20s %-10s\n", "Album Name", "Artist", "Genre", "Year");
    printf("==========================================================================================\n");
    
    for(int i=0; i<albumCount; i++) {
        printf("%-30s %-30s %-20s %-10d\n", albums[i].name, albums[i].artist, albums[i].genre, albums[i].year);
    }
}

// Function to search album by name
void searchAlbumByName(struct album *albums, int albumCount) {
    char name[50];
    printf("Enter album name: ");
    scanf("%s", name);
    
    int found = 0;
    
    printf("%-30s %-30s %-20s %-10s\n", "Album Name", "Artist", "Genre", "Year");
    printf("==========================================================================================\n");
    
    for(int i=0; i<albumCount; i++) {
        if(strcmp(albums[i].name, name) == 0) {
            printf("%-30s %-30s %-20s %-10d\n", albums[i].name, albums[i].artist, albums[i].genre, albums[i].year);
            found = 1;
        }
    }
    
    if(!found) {
        printf("Album not found.\n");
    }
}

// Function to search album by artist
void searchAlbumByArtist(struct album *albums, int albumCount) {
    char artist[50];
    printf("Enter artist name: ");
    scanf("%s", artist);
    
    int found = 0;
    
    printf("%-30s %-30s %-20s %-10s\n", "Album Name", "Artist", "Genre", "Year");
    printf("==========================================================================================\n");
    
    for(int i=0; i<albumCount; i++) {
        if(strcmp(albums[i].artist, artist) == 0) {
            printf("%-30s %-30s %-20s %-10d\n", albums[i].name, albums[i].artist, albums[i].genre, albums[i].year);
            found = 1;
        }
    }
    
    if(!found) {
        printf("Album not found.\n");
    }
}

// Function to search album by genre
void searchAlbumByGenre(struct album *albums, int albumCount) {
    char genre[20];
    printf("Enter genre: ");
    scanf("%s", genre);
    
    int found = 0;
    
    printf("%-30s %-30s %-20s %-10s\n", "Album Name", "Artist", "Genre", "Year");
    printf("==========================================================================================\n");
    
    for(int i=0; i<albumCount; i++) {
        if(strcmp(albums[i].genre, genre) == 0) {
            printf("%-30s %-30s %-20s %-10d\n", albums[i].name, albums[i].artist, albums[i].genre, albums[i].year);
            found = 1;
        }
    }
    
    if(!found) {
        printf("Album not found.\n");
    }
}

// Function to delete album from the library
void deleteAlbum(struct album *albums, int *albumCount) {
    char name[50];
    printf("Enter album name: ");
    scanf("%s", name);
    
    int found = 0;
    
    for(int i=0; i<*albumCount; i++) {
        if(strcmp(albums[i].name, name) == 0) {
            found = 1;
            
            for(int j=i; j<(*albumCount)-1; j++) {
                strcpy(albums[j].name, albums[j+1].name);
                strcpy(albums[j].artist, albums[j+1].artist);
                strcpy(albums[j].genre, albums[j+1].genre);
                albums[j].year = albums[j+1].year;
            }
            
            (*albumCount)--;
            printf("\nAlbum deleted successfully!\n");
            break;
        }
    }
    
    if(!found) {
        printf("Album not found.\n");
    }
}

// Main function
int main() {
    int choice, albumCount = 0;
    struct album albums[100];
    
    do {
        displayMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addNewAlbum(albums, &albumCount);
                break;
            case 2:
                listAllAlbums(albums, albumCount);
                break;
            case 3:
                searchAlbumByName(albums, albumCount);
                break;
            case 4:
                searchAlbumByArtist(albums, albumCount);
                break;
            case 5:
                searchAlbumByGenre(albums, albumCount);
                break;
            case 6:
                deleteAlbum(albums, &albumCount);
                break;
            case 7:
                printf("\nExiting program... Thank you for using C Music Library Management System.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 7);
    
    return 0;
}