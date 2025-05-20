//FormAI DATASET v1.0 Category: Music Library Management System ; Style: mind-bending
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct album {
    int albumID;
    char albumName[50];
    char artist[50];
    int year;
    int rating;
} albums[100];

int numAlbums = 0;

void addAlbum() {
    char albumName[50];
    char artist[50];
    int year, rating;

    printf("Enter the album name: ");
    scanf("%s", albumName);

    printf("Enter the artist name: ");
    scanf("%s", artist);

    printf("Enter the year: ");
    scanf("%d", &year);

    printf("Enter the rating (1-10): ");
    scanf("%d", &rating);

    albums[numAlbums].albumID = numAlbums+1;
    strcpy(albums[numAlbums].albumName, albumName);
    strcpy(albums[numAlbums].artist, artist);
    albums[numAlbums].year = year;
    albums[numAlbums].rating = rating;

    numAlbums++;

    printf("Album added successfully!\n");
}

void displayAlbums() {
    printf("Album ID\tAlbum Name\tArtist\tYear\tRating\n");

    for(int i=0; i<numAlbums; i++) {
        printf("%d\t\t%s\t\t%s\t%d\t%d\n", 
        albums[i].albumID, albums[i].albumName, albums[i].artist, albums[i].year, albums[i].rating);
    }
}

void searchAlbum() {
    char albumName[50];
    int found = 0;

    printf("Enter the album name: ");
    scanf("%s", albumName);

    for(int i=0; i<numAlbums; i++) {
        if(strcmp(albums[i].albumName, albumName) == 0) {
            printf("Album found at position %d!\n", i+1);
            printf("Album ID\tAlbum Name\tArtist\tYear\tRating\n");
            printf("%d\t\t%s\t\t%s\t%d\t%d\n", 
            albums[i].albumID, albums[i].albumName, albums[i].artist, albums[i].year, albums[i].rating);
            found = 1;
        }
    }

    if(!found) {
        printf("Album not found!\n");
    }
}

void deleteAlbum() {
    int albumID;
    int found = 0;

    printf("Enter the album ID: ");
    scanf("%d", &albumID);

    for(int i=0; i<numAlbums; i++) {
        if(albums[i].albumID == albumID) {
            printf("%s album by %s deleted successfully!\n", albums[i].albumName, albums[i].artist);

            for(int j=i; j<numAlbums-1; j++) {
                albums[j] = albums[j+1];
            }

            numAlbums--;
            found = 1;
        }
    }

    if(!found) {
        printf("Album not found!\n");
    }
}

void updateAlbum() {
    int albumID, fieldID;
    char fieldValue[50];
    int found = 0;

    printf("Enter the album ID: ");
    scanf("%d", &albumID);

    printf("Enter the field ID to be updated:\n");
    printf("1. Album name\n");
    printf("2. Artist\n");
    printf("3. Year\n");
    printf("4. Rating\n");
    scanf("%d", &fieldID);

    printf("Enter the new value: ");
    scanf("%s", fieldValue);

    for(int i=0; i<numAlbums; i++) {
        if(albums[i].albumID == albumID) {
            switch(fieldID) {
                case 1:
                    strcpy(albums[i].albumName, fieldValue);
                    break;
                case 2:
                    strcpy(albums[i].artist, fieldValue);
                    break;
                case 3:
                    albums[i].year = atoi(fieldValue);
                    break;
                case 4:
                    albums[i].rating = atoi(fieldValue);
                    break;
                default:
                    printf("Invalid field ID!\n");
                    return;
            }
            printf("Album %d updated successfully!\n", albumID);
            found = 1;
        }
    }

    if(!found) {
        printf("Album not found!\n");
    }
}

int main() {
    int choice;

    while(1) {
        printf("Welcome to the Music Library Management System!\n");
        printf("1. Add album\n");
        printf("2. Display all albums\n");
        printf("3. Search for an album\n");
        printf("4. Delete an album\n");
        printf("5. Update an album\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAlbum();
                break;
            case 2:
                displayAlbums();
                break;
            case 3:
                searchAlbum();
                break;
            case 4:
                deleteAlbum();
                break;
            case 5:
                updateAlbum();
                break;
            case 6:
                printf("Thank you for using the Music Library Management System!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}