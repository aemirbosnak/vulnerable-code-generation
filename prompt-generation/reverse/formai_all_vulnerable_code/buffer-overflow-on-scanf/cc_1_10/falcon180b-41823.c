//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 10

typedef struct {
    char name[50];
    int ratings[MAX_RATINGS];
    int num_ratings;
    double avg_rating;
} Movie;

void read_movies(Movie movies[], int num_movies) {
    FILE *fp;
    char line[100];
    int i = 0;

    fp = fopen("movies.txt", "r");

    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        strcpy(movies[i].name, line);
        i++;
    }

    fclose(fp);
}

void read_ratings(Movie movies[], int num_movies) {
    FILE *fp;
    char line[100];
    int i, j;

    fp = fopen("ratings.txt", "r");

    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    for (i = 0; i < num_movies; i++) {
        movies[i].num_ratings = 0;
        movies[i].avg_rating = 0.0;
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        sscanf(line, "%s %d", movies[i].name, &movies[i].ratings[movies[i].num_ratings]);
        movies[i].num_ratings++;
    }

    for (i = 0; i < num_movies; i++) {
        for (j = 0; j < movies[i].num_ratings; j++) {
            movies[i].avg_rating += movies[i].ratings[j];
        }
        movies[i].avg_rating /= movies[i].num_ratings;
    }

    fclose(fp);
}

void print_movies(Movie movies[], int num_movies) {
    int i;

    for (i = 0; i < num_movies; i++) {
        printf("%s: %.2f\n", movies[i].name, movies[i].avg_rating);
    }
}

int main() {
    Movie movies[MAX_MOVIES];
    int num_movies;

    printf("Enter number of movies: ");
    scanf("%d", &num_movies);

    read_movies(movies, num_movies);
    read_ratings(movies, num_movies);
    print_movies(movies, num_movies);

    return 0;
}