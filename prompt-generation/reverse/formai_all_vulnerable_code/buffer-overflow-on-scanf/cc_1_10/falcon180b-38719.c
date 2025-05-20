//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LENGTH 100
#define MAX_DIRECTOR_LENGTH 50
#define MAX_ACTOR_LENGTH 50
#define MAX_GENRE_LENGTH 50
#define MAX_RATING_LENGTH 10
#define MAX_REVIEW_LENGTH 500

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char actor[MAX_ACTOR_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    char rating[MAX_RATING_LENGTH];
    char review[MAX_REVIEW_LENGTH];
} Movie;

int main() {
    int numMovies;

    printf("Enter the number of movies: ");
    scanf("%d", &numMovies);

    Movie movies[numMovies];

    for (int i = 0; i < numMovies; i++) {
        printf("Enter movie %d information:\n", i+1);

        printf("Title: ");
        scanf("%s", movies[i].title);

        printf("Director: ");
        scanf("%s", movies[i].director);

        printf("Actor: ");
        scanf("%s", movies[i].actor);

        printf("Genre: ");
        scanf("%s", movies[i].genre);

        printf("Rating: ");
        scanf("%s", movies[i].rating);

        printf("Review: ");
        scanf("%s", movies[i].review);
    }

    return 0;
}