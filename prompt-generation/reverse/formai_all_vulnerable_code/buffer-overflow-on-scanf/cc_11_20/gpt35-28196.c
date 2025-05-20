//FormAI DATASET v1.0 Category: Music Library Management System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song{
    char title[50];
    char artist[50];
    char genre[20];
    int year;
};

int main(){
    int choice, num_songs = 0, i;
    struct song *library = (struct song*)malloc(sizeof(struct song));
    printf("Welcome to the Medieval Music Library Management System!\n");

    while(1){
        printf("\n1. Add a song\n");
        printf("2. Display all songs\n");
        printf("3. Search for a song\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                library = (struct song*)realloc(library, (num_songs+1)*sizeof(struct song));
                printf("\nEnter song title: ");
                scanf("%s", library[num_songs].title);
                printf("Enter artist name: ");
                scanf("%s", library[num_songs].artist);
                printf("Enter genre: ");
                scanf("%s", library[num_songs].genre);
                printf("Enter year released: ");
                scanf("%d", &library[num_songs].year);
                num_songs++;
                break;
            case 2:
                if(num_songs == 0){
                    printf("\nNo songs added yet.\n");
                    break;
                }
                printf("\nList of all songs:\n");
                for(i=0; i<num_songs; i++){
                    printf("%d. %s - %s (%s %d)\n", i+1, library[i].title, library[i].artist, library[i].genre, library[i].year);
                }
                break;
            case 3:
                if(num_songs == 0){
                    printf("\nNo songs added yet.\n");
                    break;
                }
                char search_title[50], search_artist[50], search_genre[20];
                int search_year;
                printf("\nEnter song title: ");
                scanf("%s", search_title);
                printf("Enter artist name: ");
                scanf("%s", search_artist);
                printf("Enter genre: ");
                scanf("%s", search_genre);
                printf("Enter year released: ");
                scanf("%d", &search_year);
                for(i=0; i<num_songs; i++){
                    if(strcmp(library[i].title, search_title) == 0 && strcmp(library[i].artist, search_artist) == 0 && 
                    strcmp(library[i].genre, search_genre) == 0 && library[i].year == search_year){
                        printf("\nSong found at position %d:\n", i+1);
                        printf("%s - %s (%s %d)\n", library[i].title, library[i].artist, library[i].genre, library[i].year);
                        break;
                    }
                }
                if(i == num_songs)
                    printf("\nSong not found.\n");
                break;
            case 4:
                printf("\nThank you for using the Medieval Music Library Management System!\n");
                return 0;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
}