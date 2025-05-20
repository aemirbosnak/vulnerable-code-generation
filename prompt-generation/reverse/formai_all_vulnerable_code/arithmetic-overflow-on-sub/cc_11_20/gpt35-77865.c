//FormAI DATASET v1.0 Category: Music Library Management System ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Defining the structure of album
struct album{
    char artist[50];
    char album_title[50];
    int release_year;
    float price;
    int tracks;
};

int main(void){
    int i, n, flag = 0;
    float budget;
    char search_title[50];

    // Taking input of number of albums
    printf("Enter the number of albums in your collection: ");
    scanf("%d", &n);

    // Allocate memory for array of structures
    struct album* albums = (struct album *)malloc(n * sizeof(struct album));

    // Taking input of album information from user
    for(i=0; i<n; i++){
        printf("\nAlbum %d:\n", i+1);
        printf("Artist Name: ");
        scanf(" %[^\n]%*c", albums[i].artist);

        printf("Album Title: ");
        scanf(" %[^\n]%*c", albums[i].album_title);

        printf("Release Year: ");
        scanf("%d", &albums[i].release_year);

        printf("Price: ");
        scanf("%f", &albums[i].price);

        printf("Number of Tracks: ");
        scanf("%d", &albums[i].tracks);
    }

    // Printing the album list
    printf("\nAlbum List:\n");
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("| S.No |     Artist Name     |               Album Title               | Release Year |  Price  | Tracks |\n");
    printf("--------------------------------------------------------------------------------------------------\n");
    for(i=0; i<n; i++){
        printf("|  %2d  | %-20s | %-40s | %12d | $%7.2f | %6d |\n", i+1, albums[i].artist, albums[i].album_title, albums[i].release_year, albums[i].price, albums[i].tracks);
    }
    printf("--------------------------------------------------------------------------------------------------\n");

    // Searching for an album
    printf("\nEnter the title of the album you want to search: ");
    scanf(" %[^\n]%*c", search_title);

    for(i=0; i<n; i++){
        if(strcmp(search_title, albums[i].album_title) == 0){
            printf("\nThe album \"%s\" is found in your collection!\n", search_title);
            flag = 1;
            break;
        }
    }
    if(flag == 0)
        printf("\nThe album \"%s\" is not found in your collection!\n", search_title);

    // Sorting the album list based on release year
    struct album temp;
    for(i=0; i<n-1; i++){
        if(albums[i].release_year > albums[i+1].release_year){
            temp = albums[i];
            albums[i] = albums[i+1];
            albums[i+1] = temp;
            i = -1;
        }
    }

    // Printing the sorted album list
    printf("\nAlbum List sorted based on Release Year:\n");
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("| S.No |     Artist Name     |               Album Title               | Release Year |  Price  | Tracks |\n");
    printf("--------------------------------------------------------------------------------------------------\n");
    for(i=0; i<n; i++){
        printf("|  %2d  | %-20s | %-40s | %12d | $%7.2f | %6d |\n", i+1, albums[i].artist, albums[i].album_title, albums[i].release_year, albums[i].price, albums[i].tracks);
    }
    printf("--------------------------------------------------------------------------------------------------\n");

    // Finding albums within a budget
    printf("\nEnter your budget for buying albums: $");
    scanf("%f", &budget);

    printf("\nAlbums within your budget:\n");
    printf("------------------------------------------------------------------\n");
    printf("| S.No |     Artist Name     |               Album Title               |  Price  |\n");
    printf("------------------------------------------------------------------\n");
    for(i=0; i<n; i++){
        if(albums[i].price <= budget){
            printf("|  %2d  | %-20s | %-40s | $%7.2f |\n", i+1, albums[i].artist, albums[i].album_title, albums[i].price);
        }
    }
    printf("------------------------------------------------------------------\n\n");

    // Free the allocated memory
    free(albums);

    return 0;
}