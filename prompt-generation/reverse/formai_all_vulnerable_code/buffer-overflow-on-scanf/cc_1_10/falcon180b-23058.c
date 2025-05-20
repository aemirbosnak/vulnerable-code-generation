//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LENGTH 100
#define MAX_DIRECTOR_LENGTH 50
#define MAX_ACTOR_LENGTH 50
#define MAX_GENRE_LENGTH 30
#define MAX_SYNOPSIS_LENGTH 200
#define MAX_RATING_LENGTH 10

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char actor[MAX_ACTOR_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    char synopsis[MAX_SYNOPSIS_LENGTH];
    char rating[MAX_RATING_LENGTH];
} Movie;

void print_movie(Movie* movie) {
    printf("Title: %s\n", movie->title);
    printf("Director: %s\n", movie->director);
    printf("Actor: %s\n", movie->actor);
    printf("Genre: %s\n", movie->genre);
    printf("Synopsis: %s\n", movie->synopsis);
    printf("Rating: %s\n", movie->rating);
}

int main() {
    Movie movie;

    printf("Enter the movie title: ");
    scanf("%s", movie.title);

    printf("Enter the director name: ");
    scanf("%s", movie.director);

    printf("Enter the actor name: ");
    scanf("%s", movie.actor);

    printf("Enter the movie genre: ");
    scanf("%s", movie.genre);

    printf("Enter the movie synopsis: ");
    scanf("%s", movie.synopsis);

    printf("Enter the movie rating: ");
    scanf("%s", movie.rating);

    printf("\n");
    print_movie(&movie);

    return 0;
}