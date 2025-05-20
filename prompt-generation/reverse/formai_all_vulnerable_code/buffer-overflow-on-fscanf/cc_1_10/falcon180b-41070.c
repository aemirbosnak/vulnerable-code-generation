//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LENGTH 100
#define MAX_DIRECTOR_LENGTH 50
#define MAX_ACTORS_LENGTH 100
#define MAX_GENRE_LENGTH 50
#define MAX_PLOT_LENGTH 500
#define MAX_RATING 5

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char actors[MAX_ACTORS_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    char plot[MAX_PLOT_LENGTH];
    int rating;
} Movie;

void print_movie(Movie* movie) {
    printf("Title: %s\n", movie->title);
    printf("Director: %s\n", movie->director);
    printf("Actors: %s\n", movie->actors);
    printf("Genre: %s\n", movie->genre);
    printf("Plot: %s\n", movie->plot);
    printf("Rating: %d\n", movie->rating);
}

void read_movie(FILE* file, Movie* movie) {
    fscanf(file, "%s", movie->title);
    fscanf(file, "%s", movie->director);
    fscanf(file, "%s", movie->actors);
    fscanf(file, "%s", movie->genre);
    fscanf(file, "%s", movie->plot);
    fscanf(file, "%d", &movie->rating);
}

void write_movie(FILE* file, Movie* movie) {
    fprintf(file, "%s\n", movie->title);
    fprintf(file, "%s\n", movie->director);
    fprintf(file, "%s\n", movie->actors);
    fprintf(file, "%s\n", movie->genre);
    fprintf(file, "%s\n", movie->plot);
    fprintf(file, "%d\n", movie->rating);
}

int main() {
    Movie movie;
    FILE* file = fopen("movies.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fscanf(file, "%s", movie.title)!= EOF) {
        read_movie(file, &movie);
        printf("Title: %s\n", movie.title);
        printf("Director: %s\n", movie.director);
        printf("Actors: %s\n", movie.actors);
        printf("Genre: %s\n", movie.genre);
        printf("Plot: %s\n", movie.plot);
        printf("Rating: %d\n", movie.rating);
        printf("\n");
    }

    fclose(file);

    return 0;
}