//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_MOVIE_TITLE_LENGTH 100
#define MAX_RATING_LENGTH 10
#define MAX_DIRECTOR_LENGTH 50
#define MAX_ACTOR_LENGTH 50
#define MAX_GENRE_LENGTH 50

typedef struct {
    char title[MAX_MOVIE_TITLE_LENGTH];
    char rating[MAX_RATING_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char actor[MAX_ACTOR_LENGTH];
    char genre[MAX_GENRE_LENGTH];
} Movie;

void readMovie(FILE* file, Movie* movie) {
    fscanf(file, "%s", movie->title);
    fscanf(file, "%s", movie->rating);
    fscanf(file, "%s", movie->director);
    fscanf(file, "%s", movie->actor);
    fscanf(file, "%s", movie->genre);
}

int main() {
    FILE* file = fopen("movies.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file\n");
        exit(1);
    }

    int numMovies = 0;
    Movie* movies = malloc(sizeof(Movie));
    while (fscanf(file, "%s", movies[numMovies].title)!= EOF) {
        numMovies++;
        movies = realloc(movies, sizeof(Movie) * numMovies);
        readMovie(file, &movies[numMovies - 1]);
    }
    fclose(file);

    char title[MAX_MOVIE_TITLE_LENGTH];
    printf("Enter a movie title to search for: ");
    scanf("%s", title);
    printf("Search results:\n");

    int numResults = 0;
    for (int i = 0; i < numMovies; i++) {
        if (strcasecmp(movies[i].title, title) == 0) {
            printf("Movie title: %s\n", movies[i].title);
            printf("Rating: %s\n", movies[i].rating);
            printf("Director: %s\n", movies[i].director);
            printf("Actor: %s\n", movies[i].actor);
            printf("Genre: %s\n", movies[i].genre);
            numResults++;
        }
    }

    if (numResults == 0) {
        printf("No results found.\n");
    }

    free(movies);
    return 0;
}