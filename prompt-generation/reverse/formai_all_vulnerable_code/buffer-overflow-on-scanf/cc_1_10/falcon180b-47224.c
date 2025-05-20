//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define MAX_MOVIE 100
#define MAX_USER 100
#define MAX_RATE 5
#define MAX_NAME 50

typedef struct{
    char movie_name[MAX_NAME];
    int rating;
    char user_name[MAX_NAME];
    int year;
}movie;

movie movies[MAX_MOVIE];

int main(){
    int choice,i,j,n,m,flag=0;
    char name[MAX_NAME];

    printf("\nWelcome to the Movie Rating System\n");
    printf("Enter your name:");
    scanf("%s",name);

    for(i=0;i<MAX_MOVIE;i++){
        movies[i].movie_name[0]='\0';
        movies[i].rating=0;
        movies[i].user_name[0]='\0';
        movies[i].year=0;
    }

    while(1){
        printf("\nEnter your choice:\n");
        printf("1.Rate a Movie\n2.View Ratings\n3.Exit\n");
        scanf("%d",&choice);

        switch(choice){
            case 1:{
                printf("\nEnter the movie name:");
                scanf("%s",movies[n].movie_name);
                printf("Enter your rating(1-5):");
                scanf("%d",&movies[n].rating);
                printf("Enter the year of release:");
                scanf("%d",&movies[n].year);
                printf("Rating added successfully!\n");
                break;
            }
            case 2:{
                printf("\nMovie Ratings:\n");
                for(i=0;i<MAX_MOVIE;i++){
                    if(movies[i].movie_name[0]!='\0'){
                        printf("\n%s - %d - %s - %d\n",movies[i].movie_name,movies[i].rating,movies[i].user_name,movies[i].year);
                    }
                }
                break;
            }
            case 3:{
                printf("\nThank you for using the Movie Rating System\n");
                exit(0);
            }
            default:{
                printf("\nInvalid choice! Please try again\n");
            }
        }

    }

    return 0;
}