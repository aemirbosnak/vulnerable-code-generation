//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 30

//Define struct for music albums
typedef struct Album{
    char name[MAX_SIZE];
    char artist[MAX_SIZE];
    int year;
    float rating;
}Album;

//Function to print the albums
void printAlbums(Album albums[], int count){
    int i;
    printf("----------------------------------\n");
    for(i=0;i<count;i++){
        printf("Album Name: %s\n", albums[i].name);
        printf("Artist: %s\n", albums[i].artist);
        printf("Year: %d\n", albums[i].year);
        printf("Rating: %.2f\n\n", albums[i].rating);
    }
}

//Function to add an album
int addAlbum(Album albums[],int count, char name[], char artist[], int year, float rating){
    int i;
    for(i=0;i<count;i++){
        if(strcmp(name, albums[i].name) == 0 && strcmp(artist, albums[i].artist) == 0){
            return -1;
        }
    }
    //Add new album
    strcpy(albums[count].name,name);
    strcpy(albums[count].artist,artist);
    albums[count].year = year;
    albums[count].rating = rating;
    printf("Album added successfully!\n\n");
    return count+1;
}

//Function to update an album's rating
void updateAlbumRating(Album albums[], int count, char name[], char artist[], float rating){
    int i, found = 0;
    for(i=0;i<count;i++){
        if(strcmp(name, albums[i].name) == 0 && strcmp(artist, albums[i].artist) == 0){
            albums[i].rating = rating;
            found = 1;
            break;
        }
    }
    if(found){
        printf("Album rating updated successfully!\n\n");
    }
    else{
        printf("Album not found!\n\n");
    }
}

//Function to delete an album
void deleteAlbum(Album albums[], int count, char name[], char artist[]){
    int i, found = 0, j;
    for(i=0;i<count;i++){
        if(strcmp(name, albums[i].name) == 0 && strcmp(artist, albums[i].artist) == 0){
            found = 1;
            break;
        }
    }
    if(found){
        for(j=i;j<count-1;j++){
            strcpy(albums[j].name,albums[j+1].name);
            strcpy(albums[j].artist,albums[j+1].artist);
            albums[j].year = albums[j+1].year;
            albums[j].rating = albums[j+1].rating;
        }
        printf("Album deleted successfully!\n\n");
    }
    else{
        printf("Album not found!\n\n");
    }
}

int main(){
    Album albums[MAX_SIZE];
    int count = 0, choice = 0;
    char name[MAX_SIZE], artist[MAX_SIZE];
    int year;
    float rating;
    printf("Welcome to the Cyberpunk Music Library Management System!\n\n");
    while(1) {
        printf("Please select an option:\n");
        printf("1. View all albums\n");
        printf("2. Add a new album\n");
        printf("3. Update an album rating\n");
        printf("4. Delete an album\n");
        printf("5. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                //View all albums
                printAlbums(albums,count);
                break;
            case 2:
                //Add an album
                printf("Enter the album name: ");
                scanf("%s",name);
                printf("Enter the artist name: ");
                scanf("%s",artist);
                printf("Enter the album year: ");
                scanf("%d",&year);
                printf("Enter the album rating: ");
                scanf("%f",&rating);
                count = addAlbum(albums,count,name,artist,year,rating);
                break;
            case 3:
                //Update an album rating
                printf("Enter the album name: ");
                scanf("%s",name);
                printf("Enter the artist name: ");
                scanf("%s",artist);
                printf("Enter the new rating: ");
                scanf("%f",&rating);
                updateAlbumRating(albums,count,name,artist,rating);
                break;
            case 4:
                //Delete an album
                printf("Enter the album name: ");
                scanf("%s",name);
                printf("Enter the artist name: ");
                scanf("%s",artist);
                deleteAlbum(albums,count,name,artist);
                count--;
                break;
            case 5:
                //Exit
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Please enter a valid choice!\n");
        }
    }
    return 0;
}