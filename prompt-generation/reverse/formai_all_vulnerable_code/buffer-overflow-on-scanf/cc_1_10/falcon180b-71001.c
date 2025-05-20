//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 100
#define MAX_TITLE_LENGTH 200
#define MAX_GENRE_LENGTH 30
#define MAX_RATING_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char title[MAX_TITLE_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    char rating[MAX_RATING_LENGTH];
} Movie;

void print_movie_info(Movie* movie) {
    printf("Name: %s\n", movie->name);
    printf("Title: %s\n", movie->title);
    printf("Genre: %s\n", movie->genre);
    printf("Rating: %s\n", movie->rating);
}

int main() {
    int num_movies;
    Movie* movies = NULL;

    printf("Enter the number of movies: ");
    scanf("%d", &num_movies);

    movies = (Movie*) malloc(num_movies * sizeof(Movie));

    for (int i = 0; i < num_movies; i++) {
        printf("Enter movie %d info:\n", i+1);
        printf("Name: ");
        scanf("%s", movies[i].name);

        printf("Title: ");
        scanf("%s", movies[i].title);

        printf("Genre: ");
        scanf("%s", movies[i].genre);

        printf("Rating: ");
        scanf("%s", movies[i].rating);
    }

    printf("Movie 1 Info:\n");
    print_movie_info(&movies[0]);

    printf("Movie 2 Info:\n");
    print_movie_info(&movies[1]);

    printf("Movie 3 Info:\n");
    print_movie_info(&movies[2]);

    return 0;
}