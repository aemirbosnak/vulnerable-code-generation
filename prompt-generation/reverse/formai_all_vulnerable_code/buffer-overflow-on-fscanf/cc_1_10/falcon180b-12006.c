//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_RATERS 100

typedef struct {
    char name[50];
    int num_ratings;
    int total_rating;
} Movie;

typedef struct {
    char name[50];
    int rating;
} Rater;

void read_movies(Movie* movies) {
    FILE* file = fopen("movies.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error: could not open movies.txt\n");
        exit(1);
    }

    int num_movies = 0;
    while (fscanf(file, "%s %d %d\n", movies[num_movies].name, &movies[num_movies].num_ratings, &movies[num_movies].total_rating) == 3) {
        num_movies++;
    }
    fclose(file);
}

void read_raters(Rater* raters) {
    FILE* file = fopen("raters.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error: could not open raters.txt\n");
        exit(1);
    }

    int num_raters = 0;
    while (fscanf(file, "%s %d\n", raters[num_raters].name, &raters[num_raters].rating) == 2) {
        num_raters++;
    }
    fclose(file);
}

void write_ratings(Movie* movies, Rater* raters) {
    FILE* file = fopen("ratings.txt", "w");
    if (file == NULL) {
        fprintf(stderr, "Error: could not open ratings.txt\n");
        exit(1);
    }

    for (int i = 0; i < MAX_MOVIES; i++) {
        if (movies[i].num_ratings > 0) {
            fprintf(file, "%s %d\n", movies[i].name, movies[i].total_rating / movies[i].num_ratings);
        }
    }

    for (int i = 0; i < MAX_RATERS; i++) {
        fprintf(file, "%s %d\n", raters[i].name, raters[i].rating);
    }

    fclose(file);
}

int main() {
    Movie movies[MAX_MOVIES];
    Rater raters[MAX_RATERS];

    read_movies(movies);
    read_raters(raters);

    for (int i = 0; i < MAX_RATERS; i++) {
        for (int j = 0; j < MAX_MOVIES; j++) {
            if (strcmp(raters[i].name, movies[j].name) == 0) {
                movies[j].num_ratings++;
                movies[j].total_rating += raters[i].rating;
            }
        }
    }

    write_ratings(movies, raters);

    return 0;
}