//FormAI DATASET v1.0 Category: Music Library Management System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct song{
    char title[50];
    char artist[30];
    int rating;
    int year;
}Song;

int main(){
    int capacity = 10, numSongs = 0, option;
    Song *library = (Song*) malloc(capacity * sizeof(Song));
    
    printf("Welcome to our Romantic Music Library!\n");
    
    do{
        printf("\nWhat would you like to do?\n");
        printf("1. Add a new song\n");
        printf("2. Remove a song\n");
        printf("3. View library\n");
        printf("4. Search for a song\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &option);
        
        switch(option){
            case 1:
                printf("\nEnter the song's title: ");
                scanf("%s", library[numSongs].title);
                printf("Enter the artist's name: ");
                scanf("%s", library[numSongs].artist);
                printf("Enter the song's rating (1-5): ");
                scanf("%d", &library[numSongs].rating);
                printf("Enter the song's release year: ");
                scanf("%d", &library[numSongs].year);
                
                printf("\n%s by %s has been added to the library!\n", library[numSongs].title, library[numSongs].artist);
                numSongs++;
                
                if(numSongs == capacity){
                    capacity *= 2; //double capacity if reached initial capacity
                    Song *temp = (Song*) realloc(library, capacity * sizeof(Song));
                    
                    if(temp != NULL)
                        library = temp;
                    else
                        printf("Error. Not enough memory.");
                }
                break;
                
            case 2:
                if(numSongs == 0)
                    printf("\nYour library is empty!\n");
                else{
                    char removeTitle[50], removeArtist[30];
                    int found = 0, removeIndex;
                    
                    printf("\nEnter the title of the song you want to remove: ");
                    scanf("%s", removeTitle);
                    printf("Enter the artist name: ");
                    scanf("%s", removeArtist);
                    
                    for(int i = 0; i < numSongs; i++){
                        if(strcmp(removeTitle, library[i].title) == 0 && strcmp(removeArtist, library[i].artist) == 0){
                            found = 1;
                            removeIndex = i;
                            break;
                        }
                    }
                    
                    if(found){
                        printf("\n%s by %s has been removed from the library.\n", library[removeIndex].title, library[removeIndex].artist);
                        
                        for(int i = removeIndex; i < numSongs-1; i++)
                            library[i] = library[i+1];
                        
                        numSongs--;
                    }
                    else
                        printf("\nThe song you entered was not found in the library.\n");
                }
                break;
                
            case 3:
                if(numSongs == 0)
                    printf("\nYour library is empty!\n");
                else{
                    printf("\n------------------------------\n");
                    printf("%-33s%-23s%-8s%s\n", "Title", "Artist", "Rating", "Year Released");
                    printf("------------------------------\n");
                    
                    for(int i = 0; i < numSongs; i++)
                        printf("%-33s%-23s%-8d%d\n", library[i].title, library[i].artist, library[i].rating, library[i].year);
                }
                break;
                
            case 4:
                if(numSongs == 0)
                    printf("\nYour library is empty!\n");
                else{
                    char searchTitle[50], searchArtist[30];
                    int found = 0, searchIndex;
                    
                    printf("\nEnter the title of the song you want to search for: ");
                    scanf("%s", searchTitle);
                    printf("Enter the artist name: ");
                    scanf("%s", searchArtist);
                    
                    for(int i = 0; i < numSongs; i++){
                        if(strcmp(searchTitle, library[i].title) == 0 && strcmp(searchArtist, library[i].artist) == 0){
                            found = 1;
                            searchIndex = i;
                            break;
                        }
                    }
                    
                    if(found){
                        printf("\n------------------------------\n");
                        printf("%-33s%-23s%-8s%s\n", "Title", "Artist", "Rating", "Year Released");
                        printf("------------------------------\n");
                        
                        printf("%-33s%-23s%-8d%d\n", library[searchIndex].title, library[searchIndex].artist, library[searchIndex].rating, library[searchIndex].year);
                    }
                    else
                        printf("\nThe song you entered was not found in the library.\n");
                }
                break;
                
            case 5:
                printf("\nGoodbye and thank you for using our Romantic Music Library!\n");
                break;
                
            default:
                printf("\nInvalid input. Please try again.\n");
                break;
        }
        
    }while(option != 5);
    
    free(library);
    
    return 0;
}