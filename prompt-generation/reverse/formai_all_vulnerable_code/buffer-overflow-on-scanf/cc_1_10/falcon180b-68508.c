//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_MOVIES 100

//Movie structure
typedef struct {
    char title[50];
    char director[50];
    char actors[100];
    int year;
    char genre[20];
    char rating;
} movie;

//Function to add a movie to the database
void add_movie(movie *movies, int *num_movies) {
    char title[50];
    char director[50];
    char actors[100];
    int year;
    char genre[20];
    char rating;

    //Get movie information from user
    printf("Enter movie title: ");
    scanf("%s", title);
    printf("Enter director name: ");
    scanf("%s", director);
    printf("Enter actor(s) name(s): ");
    scanf("%s", actors);
    printf("Enter year of release: ");
    scanf("%d", &year);
    printf("Enter movie genre: ");
    scanf("%s", genre);
    printf("Enter movie rating (G, PG, PG-13, R, NC-17): ");
    scanf(" %c", &rating);

    //Add movie to database
    strcpy(movies[*num_movies].title, title);
    strcpy(movies[*num_movies].director, director);
    strcpy(movies[*num_movies].actors, actors);
    movies[*num_movies].year = year;
    strcpy(movies[*num_movies].genre, genre);
    movies[*num_movies].rating = rating;

    (*num_movies)++;
}

//Function to search for a movie in the database
int search_movie(movie *movies, int num_movies, char *title) {
    int i;

    //Search for movie
    for(i=0; i<num_movies; i++) {
        if(strcmp(movies[i].title, title) == 0) {
            return i;
        }
    }

    //Movie not found
    return -1;
}

//Function to display all movies in the database
void display_movies(movie *movies, int num_movies) {
    int i;

    //Display movies
    for(i=0; i<num_movies; i++) {
        printf("Movie %d:\n", i+1);
        printf("Title: %s\n", movies[i].title);
        printf("Director: %s\n", movies[i].director);
        printf("Actors: %s\n", movies[i].actors);
        printf("Year of release: %d\n", movies[i].year);
        printf("Genre: %s\n", movies[i].genre);
        printf("Rating: %c\n\n", movies[i].rating);
    }
}

//Function to calculate average rating of all movies in the database
double calculate_average_rating(movie *movies, int num_movies) {
    int i, total_rating=0;

    //Calculate total rating
    for(i=0; i<num_movies; i++) {
        total_rating += movies[i].rating;
    }

    //Calculate average rating
    return (double)total_rating/num_movies;
}

int main() {
    movie movies[MAX_MOVIES];
    int num_movies=0;

    //Initialize database
    memset(movies, 0, sizeof(movies));
    num_movies = 0;

    //Add movies to database
    add_movie(movies, &num_movies);
    add_movie(movies, &num_movies);
    add_movie(movies, &num_movies);

    //Display all movies in the database
    printf("All movies:\n");
    display_movies(movies, num_movies);

    //Calculate average rating of all movies
    double average_rating = calculate_average_rating(movies, num_movies);
    printf("\nAverage rating: %.2f\n", average_rating);

    return 0;
}