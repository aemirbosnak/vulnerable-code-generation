//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

struct movie {
    char title[MAX_LENGTH];
    char director[MAX_LENGTH];
    char actors[MAX_LENGTH];
    char genre[MAX_LENGTH];
    int runtime;
    int rating;
};

void print_movie(struct movie movie) {
    printf("Title: %s\n", movie.title);
    printf("Director: %s\n", movie.director);
    printf("Actors: %s\n", movie.actors);
    printf("Genre: %s\n", movie.genre);
    printf("Runtime: %d minutes\n", movie.runtime);
    printf("Rating: %d/10\n\n", movie.rating);
}

int main() {
    int num_movies;
    struct movie movies[MAX_LENGTH];

    printf("Enter number of movies: ");
    scanf("%d", &num_movies);

    for (int i = 0; i < num_movies; i++) {
        printf("Enter movie %d details:\n", i+1);
        printf("Title: ");
        scanf("%s", movies[i].title);
        printf("Director: ");
        scanf("%s", movies[i].director);
        printf("Actors: ");
        scanf("%s", movies[i].actors);
        printf("Genre: ");
        scanf("%s", movies[i].genre);
        printf("Runtime: ");
        scanf("%d", &movies[i].runtime);
        printf("Rating: ");
        scanf("%d", &movies[i].rating);
    }

    printf("Movie Ratings:\n");
    for (int i = 0; i < num_movies; i++) {
        print_movie(movies[i]);
    }

    return 0;
}