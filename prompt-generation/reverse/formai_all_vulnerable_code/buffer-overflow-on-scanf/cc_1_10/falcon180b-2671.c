//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LENGTH 100
#define MAX_DIRECTOR_LENGTH 50
#define MAX_ACTORS_LENGTH 200
#define MAX_RATING_LENGTH 10
#define MAX_GENRE_LENGTH 50
#define MAX_PLOT_LENGTH 500
#define MAX_REVIEW_LENGTH 1000

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char actors[MAX_ACTORS_LENGTH];
    char rating[MAX_RATING_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    char plot[MAX_PLOT_LENGTH];
    char review[MAX_REVIEW_LENGTH];
} Movie;

void print_movie_info(Movie *movie) {
    printf("Title: %s\n", movie->title);
    printf("Director: %s\n", movie->director);
    printf("Actors: %s\n", movie->actors);
    printf("Rating: %s\n", movie->rating);
    printf("Genre: %s\n", movie->genre);
    printf("Plot: %s\n", movie->plot);
    printf("Review: %s\n", movie->review);
}

int main() {
    int num_movies;
    scanf("%d", &num_movies);

    Movie *movies = malloc(num_movies * sizeof(Movie));

    for (int i = 0; i < num_movies; i++) {
        printf("Enter movie %d info:\n", i+1);
        scanf(" %[^\n]", movies[i].title);
        getchar();
        printf("Enter director:\n");
        scanf(" %[^\n]", movies[i].director);
        getchar();
        printf("Enter actors:\n");
        scanf(" %[^\n]", movies[i].actors);
        getchar();
        printf("Enter rating:\n");
        scanf(" %[^\n]", movies[i].rating);
        getchar();
        printf("Enter genre:\n");
        scanf(" %[^\n]", movies[i].genre);
        getchar();
        printf("Enter plot:\n");
        scanf(" %[^\n]", movies[i].plot);
        getchar();
        printf("Enter review:\n");
        scanf(" %[^\n]", movies[i].review);
        getchar();
    }

    for (int i = 0; i < num_movies; i++) {
        print_movie_info(&movies[i]);
    }

    free(movies);

    return 0;
}