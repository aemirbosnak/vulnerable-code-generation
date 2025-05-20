//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

#define MAX_TITLE_LENGTH 100
#define MAX_DIRECTOR_LENGTH 50
#define MAX_ACTORS_LENGTH 200
#define MAX_REVIEWS_LENGTH 500
#define MAX_RATING_LENGTH 10

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char actors[MAX_ACTORS_LENGTH];
    char reviews[MAX_REVIEWS_LENGTH];
    char rating[MAX_RATING_LENGTH];
} Movie;

void print_movie(Movie *movie) {
    printf("Title: %s\n", movie->title);
    printf("Director: %s\n", movie->director);
    printf("Actors: %s\n", movie->actors);
    printf("Reviews: %s\n", movie->reviews);
    printf("Rating: %s\n", movie->rating);
}

void add_review(Movie *movie, char *review) {
    strcat(movie->reviews, review);
}

int main() {
    Movie movie;

    printf("Enter the movie title: ");
    scanf("%s", movie.title);

    printf("Enter the movie director: ");
    scanf("%s", movie.director);

    printf("Enter the movie actors: ");
    scanf("%s", movie.actors);

    printf("Enter the movie rating: ");
    scanf("%s", movie.rating);

    printf("Enter the movie reviews: ");
    scanf("%s", movie.reviews);

    printf("Movie Details:\n");
    print_movie(&movie);

    return 0;
}