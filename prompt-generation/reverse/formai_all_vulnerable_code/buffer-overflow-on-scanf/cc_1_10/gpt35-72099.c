//FormAI DATASET v1.0 Category: Music Library Management System ; Style: ephemeral
#include <stdio.h> //Include standard Input/ Output library
#include <string.h> //Include string library

//Struct to store Album Details
struct Album {
    char albumName[50];
    char artist[30];
    int year;
    float price;
};

// Function to add a new album to the library
void addAlbum(struct Album* albumList, int* albumCount) {
    printf("\n\nEnter Album Name: ");
    scanf("%s", albumList[*albumCount].albumName);
    printf("\nEnter Artist Name: ");
    scanf("%s", albumList[*albumCount].artist);
    printf("\nEnter Year of Release: ");
    scanf("%d", &albumList[*albumCount].year);
    printf("\nEnter Price: ");
    scanf("%f", &albumList[*albumCount].price);

    (*albumCount)++; //Increase the current album count by 1
    printf("\n\nAlbum Successfully Added to the Library!\n\n");
}

//Function to browse through albums in the library
void browseAlbums(struct Album* albumList, int albumCount) {
    printf("\n\nALBUMS IN LIBRARY\n\n");
    printf("Album Title\t\t\tArtist Name\t\t\tYear of Release\t\tPrice\n");
    printf("-----------------------------------------------------------------------------\n");

    for (int i = 0; i < albumCount; i++) {
        printf("%-30s\t\t%-20s\t%d\t\t%.2f\n", albumList[i].albumName, albumList[i].artist, albumList[i].year, albumList[i].price);
    }

    printf("-----------------------------------------------------------------------------\n\n");
}

//Function to search for an album by name
void searchAlbum(struct Album* albumList, int albumCount) {
    char name[50];
    printf("\n\nEnter Album Name to search: ");
    scanf("%s", name);

    for (int i = 0; i < albumCount; i++) {
        if (strcmp(albumList[i].albumName, name) == 0) {
            printf("\n%s found in the Library!\n\n", albumList[i].albumName);
            printf("Album Title\t\t\tArtist Name\t\t\tYear of Release\t\tPrice\n");
            printf("-----------------------------------------------------------------------------\n");
            printf("%-30s\t\t%-20s\t%d\t\t%.2f\n", albumList[i].albumName, albumList[i].artist, albumList[i].year, albumList[i].price);
            return;
        }
    }
    printf("\n%s not found in the Library!\n\n", name);
}

int main() {
    struct Album albumList[100]; //Array to store album details
    int albumCount = 0; //Current album count

    int choice = 0;
    while (1) {
        printf("\n\n*******C MUSIC LIABRARY MANAGEMENT SYSTEM*******\n");
        printf("1. Add Album\n");
        printf("2. View Albums\n");
        printf("3. Search Album\n");
        printf("4. Exit\n");
        printf("\n\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addAlbum(albumList, &albumCount);
            break;
        case 2:
            browseAlbums(albumList, albumCount);
            break;
        case 3:
            searchAlbum(albumList, albumCount);
            break;
        case 4:
            printf("\n\nThank You for Using the Application!\n\n");
            return 0;
        default:
            printf("\n\nInvalid Choice!\n\n");
            break;
        }
    }

    return 0;
}