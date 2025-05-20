//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_MOVIES 100
#define MAX_NAME 100
#define MAX_GENRE 50
#define MAX_RATING 10
#define MAX_REVIEW 500

typedef struct Movie{
    char name[MAX_NAME];
    char genre[MAX_GENRE];
    int rating;
    char review[MAX_REVIEW];
}movie;

void add_movie(movie* m){
    char choice;
    printf("Enter movie name: ");
    scanf("%s",m->name);
    printf("Enter movie genre: ");
    scanf("%s",m->genre);
    printf("Enter movie rating: ");
    scanf("%d",&m->rating);
    printf("Enter movie review: ");
    scanf("%s",m->review);
}

void display_movies(movie m[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("\nMovie name: %s",m[i].name);
        printf("\nMovie genre: %s",m[i].genre);
        printf("\nMovie rating: %d",m[i].rating);
        printf("\nMovie review: %s",m[i].review);
    }
}

void search_movie(movie m[],int n,char* name){
    int i;
    for(i=0;i<n;i++){
        if(strcmp(m[i].name,name)==0){
            printf("\nMovie found! ");
            display_movies(m,1);
        }
    }
}

int main(){
    int choice,n=0;
    movie m[MAX_MOVIES];
    char name[MAX_NAME];
    while(1){
        printf("\nWelcome to the Movie Rating System\n");
        printf("1.Add movie\n2.Display movies\n3.Search movie\n4.Exit");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                if(n==MAX_MOVIES){
                    printf("\nMaximum number of movies reached! ");
                }else{
                    n++;
                    add_movie(&m[n-1]);
                }
                break;
            case 2:
                if(n==0){
                    printf("\nNo movies added yet! ");
                }else{
                    display_movies(m,n);
                }
                break;
            case 3:
                printf("\nEnter movie name to search: ");
                scanf("%s",name);
                search_movie(m,n,name);
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice! ");
        }
    }
    return 0;
}