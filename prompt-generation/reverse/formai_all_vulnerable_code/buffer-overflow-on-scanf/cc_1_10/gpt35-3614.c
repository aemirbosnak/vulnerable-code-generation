//FormAI DATASET v1.0 Category: Movie Rating System ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Defining structure for movie
struct movie{
    char name[50];
    char genre[20];
    int rating;
};

//Defining functions to add and view movies
void add_movie(struct movie m[], int n){
    fflush(stdin);
    printf("\nEnter movie name: ");
    fgets(m[n].name, 50, stdin);
    printf("Enter genre: ");
    fgets(m[n].genre, 20, stdin);
    printf("Enter rating out of 10: ");
    scanf("%d", &m[n].rating);
    printf("Movie added successfully!\n\n");
}

void view_movies(struct movie m[], int n){
    printf("\tMovie Name\t\tGenre\t\tRating\n");
    for(int i=0; i<n; i++){
        printf("%d.\t%s", i+1, m[i].name);
        printf("\t\t%s", m[i].genre);
        printf("\t%d/10\n", m[i].rating);
    }
}

//Main function to implement the rating system
int main(){

    int n=0, choice;

    //Defining array of structures to store movies
    struct movie m[100];

    printf("\n\tC Movie Rating System\n");
    printf("\n1. Add movie\n2. View movies\n3. Exit\n\n");

    //Loop to ask user for choice
    do{
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: 
                if(n<100){
                    add_movie(m, n);
                    n++;
                }
                else{
                    printf("\nMemory full! Can't add any more movies!\n\n");
                }break;

            case 2: 
                if(n>0){
                    view_movies(m, n);
                }
                else{
                    printf("\nNo movies found!\n\n");
                }break;

            case 3: 
                printf("\nExiting the program! Have a nice day!\n\n");break;

            default:
                printf("\nInvalid choice! Please try again!\n\n");
        }

    }while(choice!=3);

    return 0;
}