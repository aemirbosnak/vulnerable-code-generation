//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_TITLE_LEN 50
#define MAX_DIRECTOR_LEN 50
#define MAX_ACTORS_LEN 200
#define MAX_GENRE_LEN 20

typedef struct {
    char title[MAX_TITLE_LEN];
    char director[MAX_DIRECTOR_LEN];
    char actors[MAX_ACTORS_LEN];
    char genre[MAX_GENRE_LEN];
    int runtime;
    int rating;
} Movie;

void read_movie_data(Movie *movie) {
    printf("Enter movie title: ");
    scanf("%s", movie->title);

    printf("Enter movie director: ");
    scanf("%s", movie->director);

    printf("Enter movie actors (separated by commas): ");
    scanf("%s", movie->actors);

    printf("Enter movie genre: ");
    scanf("%s", movie->genre);

    printf("Enter movie runtime (in minutes): ");
    scanf("%d", &movie->runtime);

    printf("Enter movie rating (1-10): ");
    scanf("%d", &movie->rating);
}

void print_movie_data(const Movie *movie) {
    printf("Title: %s\n", movie->title);
    printf("Director: %s\n", movie->director);
    printf("Actors: %s\n", movie->actors);
    printf("Genre: %s\n", movie->genre);
    printf("Runtime: %d minutes\n", movie->runtime);
    printf("Rating: %d\n", movie->rating);
}

int main() {
    Movie movie;
    read_movie_data(&movie);
    print_movie_data(&movie);

    return 0;
}