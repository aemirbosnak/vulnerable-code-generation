//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LEN 100
#define MAX_DIRECTOR_LEN 50
#define MAX_ACTOR_LEN 50
#define MAX_GENRE_LEN 30
#define MAX_RATING 5

typedef struct {
    char title[MAX_TITLE_LEN];
    char director[MAX_DIRECTOR_LEN];
    char actor[MAX_ACTOR_LEN];
    char genre[MAX_GENRE_LEN];
    int rating;
} Movie;

void print_movie(Movie* movie) {
    printf("Title: %s\nDirector: %s\nActor: %s\nGenre: %s\nRating: %d\n",
           movie->title, movie->director, movie->actor, movie->genre, movie->rating);
}

int main() {
    int num_movies;
    scanf("%d", &num_movies);

    Movie* movies = malloc(num_movies * sizeof(Movie));

    for (int i = 0; i < num_movies; i++) {
        printf("Enter movie #%d:\n", i+1);
        scanf("%s", movies[i].title);
        scanf("%s", movies[i].director);
        scanf("%s", movies[i].actor);
        scanf("%s", movies[i].genre);
        movies[i].rating = 0;
    }

    printf("Enter your ratings (0-5):\n");
    for (int i = 0; i < num_movies; i++) {
        scanf("%d", &movies[i].rating);
    }

    printf("Movie Ratings:\n");
    for (int i = 0; i < num_movies; i++) {
        print_movie(&movies[i]);
    }

    free(movies);
    return 0;
}