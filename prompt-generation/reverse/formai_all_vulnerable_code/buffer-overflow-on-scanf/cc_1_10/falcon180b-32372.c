//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_TITLE_LENGTH 100
#define MAX_DIRECTOR_LENGTH 50
#define MAX_ACTOR_LENGTH 50
#define MAX_GENRE_LENGTH 20
#define MAX_RATING 5

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char actor[MAX_ACTOR_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    int rating;
} Movie;

void print_movie(Movie *movie) {
    printf("Title: %s\n", movie->title);
    printf("Director: %s\n", movie->director);
    printf("Actor: %s\n", movie->actor);
    printf("Genre: %s\n", movie->genre);
    printf("Rating: %d\n\n", movie->rating);
}

int main() {
    int num_movies, i;
    Movie *movies;

    printf("Enter the number of movies: ");
    scanf("%d", &num_movies);

    movies = (Movie *)malloc(num_movies * sizeof(Movie));

    for (i = 0; i < num_movies; i++) {
        printf("Enter movie %d:\n", i+1);
        printf("Title: ");
        scanf("%s", movies[i].title);
        printf("Director: ");
        scanf("%s", movies[i].director);
        printf("Actor: ");
        scanf("%s", movies[i].actor);
        printf("Genre: ");
        scanf("%s", movies[i].genre);
        printf("Rating (1-5): ");
        scanf("%d", &movies[i].rating);
    }

    printf("Movie Ratings:\n");

    for (i = 0; i < num_movies; i++) {
        print_movie(&movies[i]);
    }

    return 0;
}