//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LENGTH 100
#define MAX_DIRECTOR_LENGTH 50
#define MAX_ACTORS_LENGTH 200
#define MAX_RATING_LENGTH 20
#define MAX_REVIEW_LENGTH 500

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char actors[MAX_ACTORS_LENGTH];
    char rating[MAX_RATING_LENGTH];
    char review[MAX_REVIEW_LENGTH];
} Movie;

int main() {
    int numMovies, i;
    Movie movies[100];

    printf("Enter number of movies: ");
    scanf("%d", &numMovies);

    for (i = 0; i < numMovies; i++) {
        printf("Enter details for movie %d:\n", i+1);
        printf("Title: ");
        scanf("%s", movies[i].title);
        printf("Director: ");
        scanf("%s", movies[i].director);
        printf("Actors: ");
        scanf("%s", movies[i].actors);
        printf("Rating: ");
        scanf("%s", movies[i].rating);
        printf("Review: ");
        scanf("%s", movies[i].review);
    }

    printf("\nMovie Ratings:\n");
    for (i = 0; i < numMovies; i++) {
        printf("Movie %d:\n", i+1);
        printf("Title: %s\n", movies[i].title);
        printf("Director: %s\n", movies[i].director);
        printf("Actors: %s\n", movies[i].actors);
        printf("Rating: %s\n", movies[i].rating);
        printf("Review: %s\n\n", movies[i].review);
    }

    return 0;
}