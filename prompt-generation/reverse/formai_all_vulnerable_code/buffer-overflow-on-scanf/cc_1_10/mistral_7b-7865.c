//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_NAME_LENGTH 50
#define RATING_SIZE 5

typedef struct {
    char name[MAX_NAME_LENGTH];
    int rating[RATING_SIZE];
} Movie;

void readMovies(Movie movies[], const char *filename) {
    FILE *file = fopen(filename, "rb");

    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        exit(EXIT_FAILURE);
    }

    fread(movies, sizeof(Movie), MAX_MOVIES, file);
    fclose(file);
}

void writeMovies(const Movie movies[], const char *filename) {
    FILE *file = fopen(filename, "wb");

    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        exit(EXIT_FAILURE);
    }

    fwrite(movies, sizeof(Movie), MAX_MOVIES, file);
    fclose(file);
}

void printMovie(const Movie movie) {
    printf("%s: ", movie.name);

    for (int i = 0; i < RATING_SIZE; i++) {
        printf("*%d", movie.rating[i]);
    }

    printf("\n");
}

void addRating(Movie *movies, const char *name, int rating) {
    int index = 0;

    for (; index < MAX_MOVIES; index++) {
        if (strcmp(movies[index].name, name) == 0) {
            for (int i = 0; i < RATING_SIZE; i++) {
                if (movies[index].rating[i] == 0) {
                    movies[index].rating[i] = rating;
                    break;
                }
            }
            break;
        }
    }

    if (index == MAX_MOVIES) {
        printf("Error: Movie not found.\n");
    }
}

int main() {
    Movie movies[MAX_MOVIES];
    char filename[] = "movies.dat";

    readMovies(movies, filename);

    while (1) {
        char name[MAX_NAME_LENGTH];
        int rating;

        printf("Enter a movie name (or 'q' to quit): ");
        scanf("%s", name);

        if (strcmp(name, "q") == 0) {
            break;
        }

        printf("Enter a rating (1-5): ");
        scanf("%d", &rating);

        addRating(movies, name, rating);

        printf("Rating added.\n");
    }

    writeMovies(movies, filename);

    printf("Ratings have been saved.\n");

    printf("Current ratings:\n");
    for (int i = 0; i < MAX_MOVIES; i++) {
        if (movies[i].name[0] != '\0') {
            printMovie(movies[i]);
        }
    }

    return 0;
}