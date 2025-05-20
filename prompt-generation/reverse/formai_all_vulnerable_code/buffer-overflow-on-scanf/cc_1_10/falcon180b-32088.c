//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 80
#define MAX_DIRECTOR_LENGTH 50
#define MAX_ACTORS_LENGTH 100
#define MAX_RATING 5

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char actors[MAX_ACTORS_LENGTH];
    int rating;
} Movie;

void print_movie(Movie *movie) {
    printf("Title: %s\n", movie->title);
    printf("Director: %s\n", movie->director);
    printf("Actors: %s\n", movie->actors);
    printf("Rating: %d\n\n", movie->rating);
}

int main() {
    int num_movies;
    scanf("%d", &num_movies);

    Movie *movies = malloc(num_movies * sizeof(Movie));

    for (int i = 0; i < num_movies; i++) {
        scanf(" %[^\n]", movies[i].title);
        scanf(" %[^\n]", movies[i].director);
        scanf(" %[^\n]", movies[i].actors);
        scanf("%d", &movies[i].rating);
    }

    int total_rating = 0;
    int num_rated = 0;

    for (int i = 0; i < num_movies; i++) {
        if (movies[i].rating > 0) {
            total_rating += movies[i].rating;
            num_rated++;
        }
    }

    if (num_rated == 0) {
        printf("No movies rated.\n");
    } else {
        double average_rating = (double)total_rating / num_rated;
        printf("Average rating: %.2f\n", average_rating);
    }

    free(movies);
    return 0;
}