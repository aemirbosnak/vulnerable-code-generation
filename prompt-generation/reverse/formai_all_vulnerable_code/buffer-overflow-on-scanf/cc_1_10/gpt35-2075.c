//FormAI DATASET v1.0 Category: Movie Rating System ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>

//Struct to hold details of a movie
struct movie{
    int rating; //Movie rating on a scale of 1-10
    char title[50]; //Title of the movie
    char director[50]; //Director of the movie
};

/*
This function takes an array of movies 
and prints out the details of all the movies in the array 
*/
void display_movies(struct movie movies[],int count){
    printf("\n\n******* MOVIES *******\n\n");
    for(int i=0;i<count;i++){
        printf("Title: %s\nDirector: %s\nRating: %d/10\n\n",movies[i].title,movies[i].director,movies[i].rating);
    }
}

/*
This function takes an array of movies
and returns the average rating of all the movies in the array
*/
float get_average_rating(struct movie movies[],int count){
    float sum=0;
    for(int i=0;i<count;i++){
        sum+=movies[i].rating;
    }
    return sum/count;
}


int main(){
    //welcome message
    printf("**** WELCOME TO THE FUTURE MOVIE RATING SYSTEM ****\n\n");

    //ask user to enter the number of movies they want to rate
    printf("How many movies do you want to rate? ");
    int count;
    scanf("%d",&count);

    //allocate memory for the movie array
    struct movie *movies=(struct movie*)malloc(count*sizeof(struct movie));

    //ask user to enter the details of the movies
    for(int i=0;i<count;i++){
        printf("\n\n---- DETAILS OF MOVIE %d ----\n\n",i+1);
        printf("Enter title: ");
        scanf("%s",movies[i].title);
        printf("Enter director: ");
        scanf("%s",movies[i].director);

        //ask user to enter the rating of the movie
        int rating;
        do{
            printf("Enter rating (1-10): ");
            scanf("%d",&rating);
        }while(rating<1 || rating>10);
        movies[i].rating=rating;
    }

    //display all the movies and their details
    display_movies(movies,count);

    //calculate and display the average rating of all the movies
    printf("Average rating of all the movies: %.2f/10",get_average_rating(movies,count));

    //free the memory allocated for the movie array
    free(movies);

    return 0;
}