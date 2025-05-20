//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LENGTH 100
#define MAX_DIRECTOR_LENGTH 50
#define MAX_ACTORS_LENGTH 200
#define MAX_GENRE_LENGTH 50
#define MAX_PLOT_LENGTH 500
#define MAX_RATING 5

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char actors[MAX_ACTORS_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    char plot[MAX_PLOT_LENGTH];
    int rating;
} Movie;

void print_movie(Movie movie) {
    printf("Title: %s\n", movie.title);
    printf("Director: %s\n", movie.director);
    printf("Actors: %s\n", movie.actors);
    printf("Genre: %s\n", movie.genre);
    printf("Plot: %s\n", movie.plot);
    printf("Rating: %d\n\n", movie.rating);
}

int main() {
    int num_movies;
    scanf("%d", &num_movies);

    Movie movies[num_movies];

    for (int i = 0; i < num_movies; i++) {
        printf("Enter movie #%d information:\n", i + 1);
        printf("Title: ");
        scanf("%s", movies[i].title);
        printf("Director: ");
        scanf("%s", movies[i].director);
        printf("Actors: ");
        scanf("%s", movies[i].actors);
        printf("Genre: ");
        scanf("%s", movies[i].genre);
        printf("Plot: ");
        scanf("%s", movies[i].plot);
        printf("Rating (1-5): ");
        scanf("%d", &movies[i].rating);
    }

    printf("Movie Ratings:\n");

    for (int i = 0; i < num_movies; i++) {
        print_movie(movies[i]);
    }

    return 0;
}