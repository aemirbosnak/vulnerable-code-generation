//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LEN 100
#define MAX_DIRECTOR_LEN 50
#define MAX_ACTORS_LEN 200
#define MAX_GENRE_LEN 50
#define MAX_PLOT_LEN 200
#define MAX_RATING 5

typedef struct {
    char title[MAX_TITLE_LEN];
    char director[MAX_DIRECTOR_LEN];
    char actors[MAX_ACTORS_LEN];
    char genre[MAX_GENRE_LEN];
    char plot[MAX_PLOT_LEN];
    int rating;
} Movie;

void print_movie(Movie *movie) {
    printf("Title: %s\n", movie->title);
    printf("Director: %s\n", movie->director);
    printf("Actors: %s\n", movie->actors);
    printf("Genre: %s\n", movie->genre);
    printf("Plot: %s\n", movie->plot);
    printf("Rating: %d\n", movie->rating);
}

void read_movie(Movie *movie) {
    printf("Enter movie title: ");
    scanf("%s", movie->title);

    printf("Enter director name: ");
    scanf("%s", movie->director);

    printf("Enter actors (comma-separated): ");
    scanf("%s", movie->actors);

    printf("Enter genre: ");
    scanf("%s", movie->genre);

    printf("Enter plot: ");
    scanf("%s", movie->plot);

    printf("Enter rating (0-5): ");
    scanf("%d", &movie->rating);
}

int main() {
    int num_movies;
    printf("Enter number of movies: ");
    scanf("%d", &num_movies);

    Movie movies[num_movies];

    for (int i = 0; i < num_movies; i++) {
        read_movie(&movies[i]);
    }

    printf("List of movies:\n");
    for (int i = 0; i < num_movies; i++) {
        print_movie(&movies[i]);
    }

    return 0;
}