//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    char title[50];
    char director[50];
    char actors[100];
    int length;
    int rating;
} Movie;

void addMovie(Movie *movies, int numMovies, char *title, char *director, char *actors, int length, int rating) {
    strcpy(movies[numMovies].title, title);
    strcpy(movies[numMovies].director, director);
    strcpy(movies[numMovies].actors, actors);
    movies[numMovies].length = length;
    movies[numMovies].rating = rating;
}

void printMovies(Movie *movies, int numMovies) {
    for (int i = 0; i < numMovies; i++) {
        printf("Title: %s\n", movies[i].title);
        printf("Director: %s\n", movies[i].director);
        printf("Actors: %s\n", movies[i].actors);
        printf("Length: %d minutes\n", movies[i].length);
        printf("Rating: %d\n\n", movies[i].rating);
    }
}

int main() {
    srand(time(NULL));

    int numMovies;
    printf("Enter the number of movies: ");
    scanf("%d", &numMovies);

    Movie *movies = (Movie *)malloc(numMovies * sizeof(Movie));

    for (int i = 0; i < numMovies; i++) {
        char title[50];
        char director[50];
        char actors[100];
        int length, rating;

        printf("Enter movie %d details:\n", i+1);
        printf("Title: ");
        scanf("%s", title);

        printf("Director: ");
        scanf("%s", director);

        printf("Actors: ");
        scanf("%s", actors);

        printf("Length (in minutes): ");
        scanf("%d", &length);

        printf("Rating (out of 10): ");
        scanf("%d", &rating);

        addMovie(movies, numMovies, title, director, actors, length, rating);
    }

    printMovies(movies, numMovies);

    free(movies);
    return 0;
}