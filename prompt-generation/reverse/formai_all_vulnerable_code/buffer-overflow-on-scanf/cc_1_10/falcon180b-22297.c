//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_TITLE_LEN 100
#define MAX_DIRECTOR_LEN 50
#define MAX_ACTORS_LEN 200
#define MAX_GENRE_LEN 50
#define MAX_RATING 5
#define MAX_REVIEW_LEN 500

typedef struct {
    char title[MAX_TITLE_LEN+1];
    char director[MAX_DIRECTOR_LEN+1];
    char actors[MAX_ACTORS_LEN+1];
    char genre[MAX_GENRE_LEN+1];
    int rating;
    char review[MAX_REVIEW_LEN+1];
} Movie;

void print_movie(Movie* movie) {
    printf("Title: %s\n", movie->title);
    printf("Director: %s\n", movie->director);
    printf("Actors: %s\n", movie->actors);
    printf("Genre: %s\n", movie->genre);
    printf("Rating: %d\n", movie->rating);
    printf("Review: %s\n", movie->review);
}

int main() {
    int num_movies, i;
    Movie movies[100];

    printf("Enter the number of movies to rate (1-100): ");
    scanf("%d", &num_movies);

    for (i = 0; i < num_movies; i++) {
        printf("Enter movie %d:\n", i+1);
        printf("Title: ");
        scanf("%s", movies[i].title);
        printf("Director: ");
        scanf("%s", movies[i].director);
        printf("Actors: ");
        scanf("%s", movies[i].actors);
        printf("Genre: ");
        scanf("%s", movies[i].genre);
        printf("Rating (1-5): ");
        scanf("%d", &movies[i].rating);
        printf("Review: ");
        scanf("%s", movies[i].review);
    }

    for (i = 0; i < num_movies; i++) {
        printf("\nMovie %d:\n", i+1);
        print_movie(&movies[i]);
    }

    return 0;
}