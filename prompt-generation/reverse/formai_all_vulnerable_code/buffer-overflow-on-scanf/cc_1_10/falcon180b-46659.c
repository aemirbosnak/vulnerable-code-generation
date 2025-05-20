//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LEN 100
#define MAX_DIRECTOR_LEN 50
#define MAX_ACTOR_LEN 50
#define MAX_GENRE_LEN 50
#define MAX_RATING 5

typedef struct {
    char title[MAX_TITLE_LEN];
    char director[MAX_DIRECTOR_LEN];
    char actors[MAX_ACTOR_LEN];
    char genre[MAX_GENRE_LEN];
    int rating;
} Movie;

void print_movie(Movie* movie) {
    printf("Title: %s\n", movie->title);
    printf("Director: %s\n", movie->director);
    printf("Actors: %s\n", movie->actors);
    printf("Genre: %s\n", movie->genre);
    printf("Rating: %d\n", movie->rating);
}

int main() {
    int num_movies;
    scanf("%d", &num_movies);

    Movie* movies = malloc(num_movies * sizeof(Movie));

    for (int i = 0; i < num_movies; i++) {
        char title[MAX_TITLE_LEN];
        scanf(" %[^\n]", title);
        strcpy(movies[i].title, title);

        char director[MAX_DIRECTOR_LEN];
        scanf(" %[^\n]", director);
        strcpy(movies[i].director, director);

        char actors[MAX_ACTOR_LEN];
        scanf(" %[^\n]", actors);
        strcpy(movies[i].actors, actors);

        char genre[MAX_GENRE_LEN];
        scanf(" %[^\n]", genre);
        strcpy(movies[i].genre, genre);

        movies[i].rating = 0;
    }

    for (int i = 0; i < num_movies; i++) {
        printf("Enter rating for %s (0-5): ", movies[i].title);
        scanf("%d", &movies[i].rating);
    }

    for (int i = 0; i < num_movies; i++) {
        print_movie(&movies[i]);
    }

    return 0;
}