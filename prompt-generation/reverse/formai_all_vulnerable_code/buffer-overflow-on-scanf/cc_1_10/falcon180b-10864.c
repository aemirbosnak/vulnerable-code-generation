//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_SIZE 1000

typedef struct rating{
    char movie_name[50];
    int rating;
    int votes;
}rating;

void main(){
    FILE *fp;
    fp=fopen("movies.txt","r");
    if(fp==NULL){
        printf("Error Opening File");
        exit(0);
    }
    char ch;
    int i=0,j=0;
    rating movies[MAX_SIZE];
    while((ch=fgetc(fp))!=EOF){
        if(ch=='\n'){
            movies[i].movie_name[j]='\0';
            i++;
            j=0;
        }
        else if(ch!=' '){
            movies[i].movie_name[j++]=ch;
        }
    }
    fclose(fp);
    int choice;
    do{
        printf("\n\n\t\tWelcome to Movie Rating System\n");
        printf("\n1.Rate a Movie\n2.View Ratings\n3.Exit");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("\nEnter Movie Name:");
                scanf("%s",movies[i].movie_name);
                printf("\nEnter Rating(1-5):");
                scanf("%d",&movies[i].rating);
                printf("\nEnter Number of Votes:");
                scanf("%d",&movies[i].votes);
                i++;
                break;
            case 2:
                printf("\n\nMovie Name\tRating\tVotes\n");
                for(int k=0;k<i;k++){
                    printf("%s\t%d\t%d\n",movies[k].movie_name,movies[k].rating,movies[k].votes);
                }
                break;
            case 3:
                printf("\nExiting...");
                break;
            default:
                printf("\nInvalid Choice");
        }
    }while(choice!=3);
}