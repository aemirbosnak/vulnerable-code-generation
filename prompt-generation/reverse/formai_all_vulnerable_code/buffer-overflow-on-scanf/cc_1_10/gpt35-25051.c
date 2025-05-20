//FormAI DATASET v1.0 Category: Movie Rating System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define structure for movie rating
typedef struct {
    char title[50];
    int rating;
    int num_ratings;
    char comments[200];
} Movie_Rating;

// function prototypes
void display_movies(Movie_Rating[], int);
void add_movie(Movie_Rating[], int*);
void rate_movie(Movie_Rating[], int);
void search_movie(Movie_Rating[], int);

int main()
{
    int num_movies = 0;
    Movie_Rating movies[20];

    int choice = 0;
    do {
        printf("\n==== C MOVIE RATING SYSTEM ====\n");
        printf("1. Display all movies\n");
        printf("2. Add a movie\n");
        printf("3. Rate a movie\n");
        printf("4. Search for a movie\n");
        printf("5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: 
                display_movies(movies, num_movies); 
                break;
            case 2: 
                add_movie(movies, &num_movies); 
                break;
            case 3: 
                rate_movie(movies, num_movies); 
                break;
            case 4: 
                search_movie(movies, num_movies); 
                break;
            case 5:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while(choice != 5);

    return 0;
}

// display all movies in the system
void display_movies(Movie_Rating movies[], int num_movies)
{
    if(num_movies == 0) {
        printf("\nNo movies in the system.\n");
    } else {
        printf("\n====== ALL MOVIES ======\n");
        for(int i=0; i<num_movies; i++) {
            printf("Title: %s  Rating: %d  Number of Ratings: %d  Comments: %s\n",
                movies[i].title, movies[i].rating, movies[i].num_ratings, movies[i].comments);
        }
    }
}

// add a movie to the system
void add_movie(Movie_Rating movies[], int *num_movies)
{
    if(*num_movies == 20) {
        printf("\nMax number of movies reached. Cannot add any more movies.\n");
    } else {
        printf("\nEnter movie title: ");
        scanf(" %[^\n]", movies[*num_movies].title);
        printf("Enter movie rating (out of 10): ");
        scanf("%d", &movies[*num_movies].rating);
        movies[*num_movies].num_ratings = 0;
        printf("Enter any comments: ");
        scanf(" %[^\n]", movies[*num_movies].comments);

        (*num_movies)++;
        printf("\nMovie added to the system.\n");
    }
}

// rate a movie in the system
void rate_movie(Movie_Rating movies[], int num_movies)
{
    if(num_movies == 0) {
        printf("\nNo movies in the system to rate.\n");
    } else {
        char title[50];
        int found = 0;

        printf("\nEnter the title of the movie to rate: ");
        scanf(" %[^\n]", title);

        for(int i=0; i<num_movies; i++) {
            if(strcmp(title, movies[i].title) == 0) {
                int rating = 0;
                printf("Enter rating (out of 10) for the movie: ");
                scanf("%d", &rating);
                movies[i].num_ratings++;
                movies[i].rating = ((movies[i].rating * (movies[i].num_ratings-1)) + rating) / movies[i].num_ratings;
                printf("\nMovie rating updated.\n");
                found = 1;
            }
        }

        if(!found) {
            printf("\nMovie not found in the system.\n");
        }
    }
}

// search for a movie in the system
void search_movie(Movie_Rating movies[], int num_movies)
{
    if(num_movies == 0) {
        printf("\nNo movies in the system to search for.\n");
    } else {
        char title[50];
        int found = 0;

        printf("\nEnter the title of the movie to search for: ");
        scanf(" %[^\n]", title);

        for(int i=0; i<num_movies; i++) {
            if(strcmp(title, movies[i].title) == 0) {
                printf("\nMovie details:\n");
                printf("Title: %s  Rating: %d  Number of Ratings: %d  Comments: %s\n",
                    movies[i].title, movies[i].rating, movies[i].num_ratings, movies[i].comments);
                found = 1;
            }
        }

        if(!found) {
            printf("\nMovie not found in the system.\n");
        }
    }
}