//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LENGTH 100
#define MAX_DIRECTOR_LENGTH 50
#define MAX_ACTORS_LENGTH 200
#define MAX_GENRE_LENGTH 50
#define MAX_PLOT_LENGTH 200
#define MAX_RATING 5
#define MAX_REVIEW_LENGTH 500

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char actors[MAX_ACTORS_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    char plot[MAX_PLOT_LENGTH];
    int rating;
    char review[MAX_REVIEW_LENGTH];
} Movie;

void print_movie_info(Movie *movie) {
    printf("Title: %s\n", movie->title);
    printf("Director: %s\n", movie->director);
    printf("Actors: %s\n", movie->actors);
    printf("Genre: %s\n", movie->genre);
    printf("Plot: %s\n", movie->plot);
    printf("Rating: %d\n", movie->rating);
    printf("Review: %s\n", movie->review);
}

int main() {
    Movie movie;
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char actors[MAX_ACTORS_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    char plot[MAX_PLOT_LENGTH];
    int rating;
    char review[MAX_REVIEW_LENGTH];

    // Get movie information from user
    printf("Enter movie title: ");
    scanf("%s", title);
    strcpy(movie.title, title);

    printf("Enter movie director: ");
    scanf("%s", director);
    strcpy(movie.director, director);

    printf("Enter movie actors (comma-separated): ");
    scanf("%s", actors);
    strcpy(movie.actors, actors);

    printf("Enter movie genre: ");
    scanf("%s", genre);
    strcpy(movie.genre, genre);

    printf("Enter movie plot: ");
    scanf("%s", plot);
    strcpy(movie.plot, plot);

    printf("Enter movie rating (1-5): ");
    scanf("%d", &rating);
    movie.rating = rating;

    printf("Enter movie review: ");
    scanf("%s", review);
    strcpy(movie.review, review);

    // Print movie information
    print_movie_info(&movie);

    return 0;
}