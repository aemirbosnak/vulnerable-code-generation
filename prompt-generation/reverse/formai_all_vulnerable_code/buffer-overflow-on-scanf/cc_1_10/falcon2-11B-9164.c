//Falcon2-11B DATASET v1.0 Category: Movie Rating System ; Style: brave
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Movie {
    char* title;
    int rating;
} Movie;

Movie* makeMovie(char* title, int rating) {
    Movie* movie = malloc(sizeof(Movie));
    if (movie == NULL) {
        fprintf(stderr, "Failed to allocate memory for movie\n");
        exit(1);
    }
    movie->title = strdup(title);
    movie->rating = rating;
    return movie;
}

void showMovie(Movie* movie) {
    printf("Title: %s\n", movie->title);
    printf("Rating: %d\n", movie->rating);
}

void sortMovies(Movie* movies, int numMovies) {
    for (int i = 0; i < numMovies - 1; i++) {
        for (int j = 0; j < numMovies - i - 1; j++) {
            if (movies[j].rating > movies[j + 1].rating) {
                Movie temp = movies[j];
                movies[j] = movies[j + 1];
                movies[j + 1] = temp;
            }
        }
    }
}

int main() {
    Movie* movies = NULL;
    int numMovies = 0;

    while (true) {
        char title[100];
        int rating;
        printf("Enter movie title: ");
        fgets(title, sizeof(title), stdin);
        if (title[0] == '\0') {
            break;
        }
        printf("Enter movie rating (1-10): ");
        scanf("%d", &rating);
        if (rating < 1 || rating > 10) {
            printf("Invalid rating, must be between 1 and 10\n");
            continue;
        }
        Movie* movie = makeMovie(title, rating);
        if (movies == NULL) {
            movies = movie;
            numMovies = 1;
        } else {
            movies = realloc(movies, (numMovies + 1) * sizeof(Movie));
            if (movies == NULL) {
                fprintf(stderr, "Failed to allocate memory for movies\n");
                exit(1);
            }
            movies[numMovies] = *movie;
            numMovies++;
        }
    }

    sortMovies(movies, numMovies);
    for (int i = 0; i < numMovies; i++) {
        showMovie(movies + i);
    }

    free(movies);
    return 0;
}