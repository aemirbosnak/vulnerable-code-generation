//FormAI DATASET v1.0 Category: Music Library Management System ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100
#define MAX_LENGTH 50

typedef struct{
    char album[MAX_LENGTH];
    char artist[MAX_LENGTH];
    char genre[MAX_LENGTH];
    char year[MAX_LENGTH];
} Album;

int main(){
    Album library[MAX_SIZE];
    int count = 0;
    int choice;

    do{
        printf("Welcome to the Music Library Management System!\n");
        printf("1. Add Album\n");
        printf("2. Search album\n");
        printf("3. Display Albums\n");
        printf("4. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter Album Details:\n");
                printf("Album Name: ");
                scanf("%s", library[count].album);
                printf("Artist Name: ");
                scanf("%s", library[count].artist);
                printf("Genre: ");
                scanf("%s", library[count].genre);
                printf("Year: ");
                scanf("%s", library[count].year);
                count++;
                printf("Album Added Successfully!\n");
                break;

            case 2:
                printf("Enter album name to search: ");
                char search_album[MAX_LENGTH];
                scanf("%s", search_album);
                int found_album = 0;
                for(int i=0;i<count;i++){
                    if(strcmp(search_album, library[i].album)==0){
                        printf("Album Found!\n");
                        printf("Album: %s\n", library[i].album);
                        printf("Artist: %s\n", library[i].artist);
                        printf("Genre: %s\n", library[i].genre);
                        printf("Year: %s\n", library[i].year);
                        found_album = 1;
                    }
                }
                if(found_album == 0){
                    printf("Album not found!\n");
                }
                break;

            case 3:
                printf("Albums in Library:\n");
                for(int i=0;i<count;i++){
                    printf("%d. %s\n", i+1, library[i].album);
                }
                break;

            case 4:
                printf("Thank you for using the Music Library Management System!\n");
                exit(0);
                break;

            default:
                printf("Invalid Choice!\n");

        } // end of switch

    }while(choice!=4);

    return 0;
}