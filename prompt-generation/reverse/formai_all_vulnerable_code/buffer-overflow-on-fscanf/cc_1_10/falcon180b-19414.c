//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

typedef struct {
    char title[MAX_LENGTH];
    int year;
    int duration;
    char director[MAX_LENGTH];
    char actors[MAX_LENGTH];
    int rating;
} Movie;

void read_movie(FILE *fp, Movie *movie) {
    fscanf(fp, "%s %d %d %s %s %d\n", movie->title, &movie->year, &movie->duration, movie->director, movie->actors, &movie->rating);
}

int compare_movies(const void *a, const void *b) {
    const Movie *movie1 = a;
    const Movie *movie2 = b;

    if (movie1->rating > movie2->rating) {
        return -1;
    } else if (movie1->rating < movie2->rating) {
        return 1;
    } else {
        return 0;
    }
}

void print_movies(Movie movies[], int count) {
    qsort(movies, count, sizeof(Movie), compare_movies);

    for (int i = 0; i < count; i++) {
        printf("%s (%d) - %s - %d minutes - Directed by %s - Starring %s - Rated %d\n", movies[i].title, movies[i].year, movies[i].director, movies[i].duration, movies[i].actors, movies[i].rating);
    }
}

int main() {
    FILE *input_file = fopen("movies.txt", "r");

    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    Movie movies[MAX_LENGTH];
    int count = 0;

    while (fscanf(input_file, "%s", movies[count].title)!= EOF) {
        count++;
    }

    fclose(input_file);

    input_file = fopen("movies.txt", "r");

    if (input_file == NULL) {
        printf("Error reopening input file.\n");
        return 1;
    }

    rewind(input_file);

    for (int i = 0; i < count; i++) {
        read_movie(input_file, &movies[i]);
    }

    fclose(input_file);

    print_movies(movies, count);

    return 0;
}