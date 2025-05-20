//FormAI DATASET v1.0 Category: Music Library Management System ; Style: ultraprecise
#include<stdio.h>
#include<string.h>
#define MAX 100
typedef struct {
  char title[MAX];
  char artist[MAX];
  char genre[MAX];
  int year;
}Album;

int main(){
   Album all_albums[MAX];
   int option=0, album_count=0;

   while(option!=4){
    printf("\nWelcome to the Music Library Management System \n");
    printf("1. Add Album\n");
    printf("2. Display all Albums\n");
    printf("3. Search Albums\n");
    printf("4. Exit\n");
    printf("\nEnter your option: ");
    scanf("%d", &option);

    switch(option){
        case 1:
            if(album_count==MAX){
                printf("The music library is full!");
                break;
            }
            printf("\nEnter Album Details:\n");
            printf("Title: ");
            scanf("%s", all_albums[album_count].title);
            printf("Artist: ");
            scanf("%s", all_albums[album_count].artist);
            printf("Genre: ");
            scanf("%s", all_albums[album_count].genre);
            printf("Year: ");
            scanf("%d", &all_albums[album_count].year);
            printf("Album Successfully Added!\n");
            album_count++;
            break;

        case 2:
            if(album_count==0){
                printf("No Albums in the Music Library.\n");
            }else{
                printf("\nAll Albums in the Music Library:\n");
                printf("%-20s %-20s %-20s %-6s\n", "Title", "Artist", "Genre", "Year");
                for(int i = 0; i<album_count; i++){
                   printf("%-20s %-20s %-20s %-6d\n", all_albums[i].title, all_albums[i].artist, all_albums[i].genre, all_albums[i].year);
                }
            }
            break;
        case 3:
            if(album_count==0){
                printf("No Albums in the Music Library.\n");
            }else{
                char search_title[MAX];
                printf("Enter album title to search: ");
                scanf("%s", search_title);
                printf("%-20s %-20s %-20s %-6s\n", "Title", "Artist", "Genre", "Year");
                for(int i = 0; i<album_count; i++){
                    if(strcmp(search_title,all_albums[i].title)==0){
                        printf("%-20s %-20s %-20s %-6d\n", all_albums[i].title, all_albums[i].artist, all_albums[i].genre, all_albums[i].year);
                    }
                }
            }
            break;
        case 4:
            printf("\nExiting the Music Library Management System...\n");
            break;
        default:
            printf("\nInvalid Option. Please try again.\n");
        }   
    }
    return 0;
}