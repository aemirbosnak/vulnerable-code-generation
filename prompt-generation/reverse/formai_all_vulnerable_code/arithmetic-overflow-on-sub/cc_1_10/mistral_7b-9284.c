//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_MOVIES 1000
#define MAX_RATINGS 10
#define MAX_NAME_LENGTH 50

typedef struct {
    char title[MAX_NAME_LENGTH];
    float average_rating;
    int num_ratings;
} Movie;

void read_ratings(Movie movies[], int *num_movies) {
    char filename[MAX_NAME_LENGTH] = "ratings.txt";
    FILE *file = fopen(filename, "r");
    char title[MAX_NAME_LENGTH];
    float rating;
    int movie_index = 0;

    while (fscanf(file, "%s %f", title, &rating) == 2 && movie_index < MAX_MOVIES) {
        strcpy(movies[movie_index].title, title);
        movies[movie_index].num_ratings++;
        movies[movie_index].average_rating = (movies[movie_index].average_rating * (movies[movie_index].num_ratings - 1) + rating) / movies[movie_index].num_ratings;
        movie_index++;
    }

    fclose(file);
    *num_movies = movie_index;
}

void print_movies(Movie movies[], int num_movies) {
    for (int i = 0; i < num_movies; i++) {
        printf("%s: %.2f\n", movies[i].title, movies[i].average_rating);
    }
}

int main() {
    Movie movies[MAX_MOVIES];
    int num_movies = 0;

    read_ratings(movies, &num_movies);

    if (num_movies == 0) {
        printf("No movies found.\n");
        return 1;
    }

    print_movies(movies, num_movies);

    return 0;
}