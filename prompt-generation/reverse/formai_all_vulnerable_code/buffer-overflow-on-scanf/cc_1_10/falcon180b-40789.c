//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LEN 80
#define MAX_DIRECTOR_LEN 50
#define MAX_ACTOR_LEN 50
#define MAX_GENRE_LEN 30
#define MAX_RATING_LEN 10
#define MAX_REVIEW_LEN 200

typedef struct {
    char title[MAX_TITLE_LEN+1];
    char director[MAX_DIRECTOR_LEN+1];
    char actor[MAX_ACTOR_LEN+1];
    char genre[MAX_GENRE_LEN+1];
    char rating[MAX_RATING_LEN+1];
    char review[MAX_REVIEW_LEN+1];
} movie_t;

int main(void) {
    movie_t movie;
    char input[MAX_REVIEW_LEN+1];
    int i, j;

    printf("Enter movie title: ");
    scanf("%s", movie.title);

    printf("Enter director name: ");
    scanf("%s", movie.director);

    printf("Enter lead actor name: ");
    scanf("%s", movie.actor);

    printf("Enter movie genre: ");
    scanf("%s", movie.genre);

    printf("Enter movie rating (G, PG, PG-13, R, NC-17): ");
    scanf("%s", movie.rating);

    printf("Enter your review of the movie:\n");
    fgets(input, MAX_REVIEW_LEN+1, stdin);
    strcpy(movie.review, input);

    printf("Movie Title: %s\n", movie.title);
    printf("Director: %s\n", movie.director);
    printf("Lead Actor: %s\n", movie.actor);
    printf("Genre: %s\n", movie.genre);
    printf("Rating: %s\n", movie.rating);
    printf("Review:\n%s\n", movie.review);

    return 0;
}