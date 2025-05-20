//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 1000

struct movie{
    char title[MAX_SIZE];
    char director[MAX_SIZE];
    char cast[MAX_SIZE];
    char genre[MAX_SIZE];
    char rating[MAX_SIZE];
};

struct movie create_movie(){
    struct movie movie;
    printf("Enter movie title: ");
    scanf("%s",movie.title);
    printf("Enter movie director: ");
    scanf("%s",movie.director);
    printf("Enter movie cast: ");
    scanf("%s",movie.cast);
    printf("Enter movie genre: ");
    scanf("%s",movie.genre);
    printf("Enter movie rating: ");
    scanf("%s",movie.rating);
    return movie;
}

void display_movie(struct movie movie){
    printf("\nMovie Title: %s\n",movie.title);
    printf("Movie Director: %s\n",movie.director);
    printf("Movie Cast: %s\n",movie.cast);
    printf("Movie Genre: %s\n",movie.genre);
    printf("Movie Rating: %s\n",movie.rating);
}

int main(){
    char choice;
    struct movie movie;
    do{
        printf("\n\nWelcome to the Movie Rating System\n");
        printf("1. Create a new movie\n");
        printf("2. Display all movies\n");
        printf("3. Search for a movie\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c",&choice);
        switch(choice){
            case '1':
                movie = create_movie();
                break;
            case '2':
                printf("All Movies:\n");
                break;
            case '3':
                printf("Enter movie title to search: ");
                scanf("%s",movie.title);
                printf("Movie Found:\n");
                display_movie(movie);
                break;
            case '4':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }while(choice!= '4');
    return 0;
}