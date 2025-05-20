//Falcon2-11B DATASET v1.0 Category: Music Library Management System ; Style: shape shifting
#include<stdio.h>
#include<string.h>

typedef struct library{
    char title[50];
    int year;
    int genre;
}library;

void main(){
    int choice;
    library lib[10];

    printf("Welcome to the C Music Library!\n");

    while(1){
        printf("\n1. Add a song\n2. Search a song\n3. List all songs\n4. Update a song\n5. Delete a song\n6. Quit\n");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter the title of the song: ");
                scanf("%s",lib[0].title);
                printf("Enter the year of the song: ");
                scanf("%d",&lib[0].year);
                printf("Enter the genre of the song: ");
                scanf("%d",&lib[0].genre);
                break;
            case 2:
                printf("Enter the title of the song you want to search: ");
                scanf("%s",lib[0].title);
                for(int i=0;i<10;i++){
                    if(strcmp(lib[i].title,lib[0].title)==0){
                        printf("Song: %s\nYear: %d\nGenre: %d\n",lib[i].title,lib[i].year,lib[i].genre);
                    }
                }
                break;
            case 3:
                for(int i=0;i<10;i++){
                    printf("Song: %s\nYear: %d\nGenre: %d\n",lib[i].title,lib[i].year,lib[i].genre);
                }
                break;
            case 4:
                printf("Enter the title of the song you want to update: ");
                scanf("%s",lib[0].title);
                printf("Enter the new title: ");
                scanf("%s",lib[0].title);
                break;
            case 5:
                printf("Enter the title of the song you want to delete: ");
                scanf("%s",lib[0].title);
                for(int i=0;i<10;i++){
                    if(strcmp(lib[i].title,lib[0].title)==0){
                        for(int j=i;j<10;j++){
                            lib[j] = lib[j+1];
                        }
                        break;
                    }
                }
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!");
        }
    }
}