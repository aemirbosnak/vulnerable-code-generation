//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 100
#define MAX_TITLE_LEN 100
#define MAX_DIRECTOR_LEN 100
#define MAX_ACTOR_LEN 100
#define MAX_GENRE_LEN 100
#define MAX_RATING_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char title[MAX_TITLE_LEN];
    char director[MAX_DIRECTOR_LEN];
    char actor[MAX_ACTOR_LEN];
    char genre[MAX_GENRE_LEN];
    char rating[MAX_RATING_LEN];
} movie_t;

int main() {
    int num_movies, i, j;
    movie_t *movies;

    printf("Enter number of movies: ");
    scanf("%d", &num_movies);
    movies = (movie_t *)malloc(num_movies * sizeof(movie_t));

    for (i = 0; i < num_movies; i++) {
        printf("Enter movie %d details:\n", i+1);
        printf("Name: ");
        scanf("%s", movies[i].name);
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
    }

    printf("\nMovie Ratings:\n");
    printf("Name\tTitle\tDirector\tActor\tGenre\tRating\n");

    for (i = 0; i < num_movies; i++) {
        printf("%s\t%s\t%s\t%s\t%s\t%s\n", movies[i].name, movies[i].title, movies[i].director, movies[i].actor, movies[i].genre, movies[i].rating);
    }

    free(movies);
    return 0;
}