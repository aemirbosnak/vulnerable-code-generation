//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LEN 100
#define MAX_DIRECTOR_LEN 50
#define MAX_ACTORS_LEN 200
#define MAX_GENRE_LEN 50
#define MAX_RATING 5
#define MAX_REVIEW_LEN 200

typedef struct movie {
    char title[MAX_TITLE_LEN];
    char director[MAX_DIRECTOR_LEN];
    char actors[MAX_ACTORS_LEN];
    char genre[MAX_GENRE_LEN];
    int rating;
    char review[MAX_REVIEW_LEN];
} Movie;

int main() {
    int num_movies;
    Movie movies[100];

    printf("Enter number of movies: ");
    scanf("%d", &num_movies);

    printf("Enter movie details:\n");
    for (int i = 0; i < num_movies; i++) {
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

    printf("Movie Ratings:\n");
    for (int i = 0; i < num_movies; i++) {
        printf("%s (%s)\n", movies[i].title, movies[i].director);
        printf("Rating: %d\n", movies[i].rating);
        printf("Genre: %s\n", movies[i].genre);
        printf("Review: %s\n\n", movies[i].review);
    }

    return 0;
}