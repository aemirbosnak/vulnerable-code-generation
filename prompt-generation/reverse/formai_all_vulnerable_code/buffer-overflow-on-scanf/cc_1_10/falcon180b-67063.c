//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_MOVIES 100
#define MAX_CHARACTERS_PER_LINE 80

typedef struct {
    char title[MAX_CHARACTERS_PER_LINE];
    char director[MAX_CHARACTERS_PER_LINE];
    int year;
    char genre[MAX_CHARACTERS_PER_LINE];
    float rating;
} Movie;

void print_movie(Movie movie) {
    printf("%-40s %-30s %d %-20s %.2f\n", movie.title, movie.director, movie.year, movie.genre, movie.rating);
}

int compare_movies(const void* a, const void* b) {
    const Movie* movie1 = (const Movie*)a;
    const Movie* movie2 = (const Movie*)b;

    if (movie1->rating > movie2->rating) {
        return -1;
    } else if (movie1->rating < movie2->rating) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int num_movies;
    scanf("%d", &num_movies);

    Movie movies[MAX_MOVIES];

    for (int i = 0; i < num_movies; i++) {
        scanf("%s %s %d %s %f", movies[i].title, movies[i].director, &movies[i].year, movies[i].genre, &movies[i].rating);
    }

    qsort(movies, num_movies, sizeof(Movie), compare_movies);

    for (int i = 0; i < num_movies; i++) {
        print_movie(movies[i]);
    }

    return 0;
}