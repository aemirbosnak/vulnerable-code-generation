//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_MOVIE_COUNT 100
#define MAX_CHAR_COUNT 200

typedef struct {
    char title[MAX_CHAR_COUNT];
    char director[MAX_CHAR_COUNT];
    char actors[MAX_CHAR_COUNT];
    char genre[MAX_CHAR_COUNT];
    int rating;
} Movie;

void print_movie(Movie movie) {
    printf("Title: %s\n", movie.title);
    printf("Director: %s\n", movie.director);
    printf("Actors: %s\n", movie.actors);
    printf("Genre: %s\n", movie.genre);
    printf("Rating: %d\n\n", movie.rating);
}

int compare_movies(const void *a, const void *b) {
    Movie movie1 = *(Movie *)a;
    Movie movie2 = *(Movie *)b;

    if (movie1.rating > movie2.rating) {
        return -1;
    } else if (movie1.rating < movie2.rating) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int num_movies;
    scanf("%d", &num_movies);

    Movie movies[MAX_MOVIE_COUNT];

    for (int i = 0; i < num_movies; i++) {
        scanf("%s %s %s %s %d", movies[i].title, movies[i].director, movies[i].actors, movies[i].genre, &movies[i].rating);
    }

    qsort(movies, num_movies, sizeof(Movie), compare_movies);

    for (int i = 0; i < num_movies; i++) {
        print_movie(movies[i]);
    }

    return 0;
}