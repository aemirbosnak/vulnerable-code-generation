//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 100
#define MAX_DIRECTOR_LENGTH 50
#define MAX_ACTOR_LENGTH 50
#define MAX_GENRE_LENGTH 30
#define MAX_YEAR_LENGTH 10
#define MAX_RATING_LENGTH 10

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char actors[MAX_ACTOR_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    int year;
    float rating;
} Movie;

void loadMovies(Movie* movies) {
    FILE* file = fopen("movies.txt", "r");
    if (file == NULL) {
        printf("Error loading movies.\n");
        exit(1);
    }

    int numMovies = 0;
    while (fscanf(file, "%s %s %s %s %d %f\n", movies[numMovies].title, movies[numMovies].director, movies[numMovies].actors, movies[numMovies].genre, &movies[numMovies].year, &movies[numMovies].rating)!= EOF) {
        numMovies++;
    }

    fclose(file);
}

void saveMovies(Movie* movies, int numMovies) {
    FILE* file = fopen("movies.txt", "w");
    if (file == NULL) {
        printf("Error saving movies.\n");
        exit(1);
    }

    for (int i = 0; i < numMovies; i++) {
        fprintf(file, "%s %s %s %s %d %f\n", movies[i].title, movies[i].director, movies[i].actors, movies[i].genre, movies[i].year, movies[i].rating);
    }

    fclose(file);
}

void printMovie(Movie movie) {
    printf("Title: %s\n", movie.title);
    printf("Director: %s\n", movie.director);
    printf("Actors: %s\n", movie.actors);
    printf("Genre: %s\n", movie.genre);
    printf("Year: %d\n", movie.year);
    printf("Rating: %.1f\n\n", movie.rating);
}

int main() {
    srand(time(NULL));

    Movie movies[MAX_MOVIES];
    loadMovies(movies);

    int numMovies = 0;
    while (numMovies < MAX_MOVIES && movies[numMovies].title[0]!= '\0') {
        movies[numMovies].title[0] = toupper(movies[numMovies].title[0]);
        numMovies++;
    }

    char input[MAX_TITLE_LENGTH];
    while (true) {
        printf("Enter a movie title to search for (or type 'exit' to quit):\n");
        scanf("%s", input);

        if (strcmp(input, "exit") == 0) {
            break;
        }

        bool found = false;
        for (int i = 0; i < numMovies; i++) {
            if (strcmp(movies[i].title, input) == 0) {
                printMovie(movies[i]);
                found = true;
                break;
            }
        }

        if (!found) {
            printf("Movie not found.\n");
        }
    }

    return 0;
}