//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LENGTH 100
#define MAX_DIRECTOR_LENGTH 50
#define MAX_ACTORS_LENGTH 200
#define MAX_GENRE_LENGTH 50
#define MAX_RATING_LENGTH 10

typedef struct {
    char title[MAX_TITLE_LENGTH + 1];
    char director[MAX_DIRECTOR_LENGTH + 1];
    char actors[MAX_ACTORS_LENGTH + 1];
    char genre[MAX_GENRE_LENGTH + 1];
    char rating[MAX_RATING_LENGTH + 1];
} Movie;

void print_movie(Movie* movie) {
    printf("Title: %s\n", movie->title);
    printf("Director: %s\n", movie->director);
    printf("Actors: %s\n", movie->actors);
    printf("Genre: %s\n", movie->genre);
    printf("Rating: %s\n", movie->rating);
}

int main() {
    Movie movie;

    printf("Enter the movie title: ");
    scanf("%s", movie.title);

    printf("Enter the movie director: ");
    scanf("%s", movie.director);

    printf("Enter the movie actors (separated by commas): ");
    scanf("%s", movie.actors);

    printf("Enter the movie genre: ");
    scanf("%s", movie.genre);

    printf("Enter the movie rating (G, PG, PG-13, R): ");
    scanf("%s", movie.rating);

    printf("Movie details:\n");
    print_movie(&movie);

    return 0;
}