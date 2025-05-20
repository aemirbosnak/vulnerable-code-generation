//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LENGTH 100
#define MAX_DIRECTOR_LENGTH 50
#define MAX_ACTORS_LENGTH 200
#define MAX_GENRE_LENGTH 50
#define MAX_RATING 5

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char actors[MAX_ACTORS_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    int rating;
} Movie;

void print_movie(Movie *movie) {
    printf("Title: %s\n", movie->title);
    printf("Director: %s\n", movie->director);
    printf("Actors: %s\n", movie->actors);
    printf("Genre: %s\n", movie->genre);
    printf("Rating: %d\n", movie->rating);
}

int main() {
    Movie movies[10];
    int num_movies = 0;

    while (num_movies < 10) {
        printf("Enter movie information:\n");
        printf("Title: ");
        scanf("%s", movies[num_movies].title);
        printf("Director: ");
        scanf("%s", movies[num_movies].director);
        printf("Actors: ");
        scanf("%s", movies[num_movies].actors);
        printf("Genre: ");
        scanf("%s", movies[num_movies].genre);
        printf("Rating (1-5): ");
        scanf("%d", &movies[num_movies].rating);
        num_movies++;
    }

    printf("Movie Ratings:\n");
    for (int i = 0; i < num_movies; i++) {
        print_movie(&movies[i]);
    }

    return 0;
}