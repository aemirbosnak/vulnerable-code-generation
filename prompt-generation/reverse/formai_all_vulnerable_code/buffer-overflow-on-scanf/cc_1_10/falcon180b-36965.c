//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LEN 100
#define MAX_DIRECTOR_LEN 50
#define MAX_ACTORS_LEN 200
#define MAX_GENRE_LEN 50
#define MAX_PLOT_LEN 500
#define MAX_RATING 5
#define MAX_REVIEW_LEN 200

typedef struct {
    char title[MAX_TITLE_LEN];
    char director[MAX_DIRECTOR_LEN];
    char actors[MAX_ACTORS_LEN];
    char genre[MAX_GENRE_LEN];
    char plot[MAX_PLOT_LEN];
    int rating;
    char review[MAX_REVIEW_LEN];
} Movie;

void print_movie(Movie* movie) {
    printf("Title: %s\n", movie->title);
    printf("Director: %s\n", movie->director);
    printf("Actors: %s\n", movie->actors);
    printf("Genre: %s\n", movie->genre);
    printf("Plot: %s\n", movie->plot);
    printf("Rating: %d\n", movie->rating);
    printf("Review: %s\n", movie->review);
}

int main() {
    Movie movie;
    char input[100];
    int i = 0;

    printf("Enter movie title: ");
    scanf("%s", movie.title);

    printf("Enter director name: ");
    scanf("%s", movie.director);

    printf("Enter actors (comma separated): ");
    scanf("%s", movie.actors);

    printf("Enter genre: ");
    scanf("%s", movie.genre);

    printf("Enter plot: ");
    scanf("%s", movie.plot);

    printf("Enter rating (1-5): ");
    scanf("%d", &movie.rating);

    printf("Enter review: ");
    scanf("%s", movie.review);

    printf("Movie details:\n");
    print_movie(&movie);

    return 0;
}