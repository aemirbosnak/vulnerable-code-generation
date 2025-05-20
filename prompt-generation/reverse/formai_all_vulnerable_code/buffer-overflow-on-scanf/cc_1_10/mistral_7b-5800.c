//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_NAME_LENGTH 50
#define RATING_SIZE sizeof(float)

typedef struct {
    char name[MAX_NAME_LENGTH];
    float rating;
} Movie;

void read_movies_from_file(Movie movies[], const char *filename);
void write_movies_to_file(const Movie movies[], const char *filename);
void get_movie_rating(Movie *movie, const char *name);
void add_movie_rating(Movie *movies, const char *name, float rating);
float get_average_rating(const Movie movies[]);

int main() {
    char name[MAX_NAME_LENGTH];
    float rating;
    Movie movies[MAX_MOVIES];
    char filename[] = "movies.dat";

    read_movies_from_file(movies, filename);

    while (1) {
        printf("Enter a movie name to rate or type 'exit' to quit: ");
        scanf("%s", name);

        if (strcmp(name, "exit") == 0) {
            break;
        }

        printf("Enter a rating for %s (1 to 10): ", name);
        scanf("%f", &rating);

        add_movie_rating(movies, name, rating);
        write_movies_to_file(movies, filename);
    }

    printf("Average rating of all movies: %.2f\n", get_average_rating(movies));

    return 0;
}

void read_movies_from_file(Movie movies[], const char *filename) {
    FILE *file = fopen(filename, "rb");

    if (file == NULL) {
        printf("Error: Could not open file %s for reading.\n", filename);
        return;
    }

    fread(movies, sizeof(Movie), MAX_MOVIES, file);
    fclose(file);
}

void write_movies_to_file(const Movie movies[], const char *filename) {
    FILE *file = fopen(filename, "wb");

    if (file == NULL) {
        printf("Error: Could not open file %s for writing.\n", filename);
        return;
    }

    fwrite(movies, sizeof(Movie), MAX_MOVIES, file);
    fclose(file);
}

void get_movie_rating(Movie *movie, const char *name) {
    strcpy(movie->name, name);
}

void add_movie_rating(Movie *movies, const char *name, float rating) {
    int index = 0;

    for (; index < MAX_MOVIES; index++) {
        if (strcmp(movies[index].name, name) == 0) {
            movies[index].rating += rating;
            break;
        }
    }

    if (index == MAX_MOVIES) {
        printf("Error: Movie %s not found.\n", name);
    }
}

float get_average_rating(const Movie movies[]) {
    float sum = 0;
    int count = 0;

    for (int i = 0; i < MAX_MOVIES; i++) {
        if (movies[i].rating > 0) {
            sum += movies[i].rating;
            count++;
        }
    }

    if (count > 0) {
        return sum / count;
    } else {
        return 0;
    }
}