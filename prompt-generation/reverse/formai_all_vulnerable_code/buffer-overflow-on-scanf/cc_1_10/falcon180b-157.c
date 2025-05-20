//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_RATERS 1000
#define MAX_RATINGS 10000
#define MAX_NAME_LENGTH 50
#define MAX_RATING 5
#define MIN_RATERS 3

typedef struct {
    char name[MAX_NAME_LENGTH];
    int num_raters;
    int total_rating;
} Movie;

void init_movie(Movie *movie, char *name) {
    strcpy(movie->name, name);
    movie->num_raters = 0;
    movie->total_rating = 0;
}

void print_movie(Movie *movie) {
    printf("%s: %d (%.2f)\n", movie->name, movie->num_raters, (float)movie->total_rating/movie->num_raters);
}

typedef struct {
    char name[MAX_NAME_LENGTH];
    int rating;
} Rater;

void init_rater(Rater *rater, char *name) {
    strcpy(rater->name, name);
    rater->rating = 0;
}

void print_rater(Rater *rater) {
    printf("%s: %d\n", rater->name, rater->rating);
}

void rate_movie(Movie *movie, Rater *rater) {
    if (rater->rating < 0 || rater->rating > MAX_RATING) {
        printf("Invalid rating!\n");
        return;
    }
    movie->num_raters++;
    movie->total_rating += rater->rating;
}

int main() {
    Movie movies[MAX_MOVIES];
    Rater raters[MAX_RATERS];
    int num_movies, num_raters;
    char movie_name[MAX_NAME_LENGTH];
    char rater_name[MAX_NAME_LENGTH];
    int rating;
    int i, j;

    printf("Welcome to the C Movie Rating System!\n");
    printf("Please enter the number of movies: ");
    scanf("%d", &num_movies);
    for (i = 0; i < num_movies; i++) {
        printf("Enter movie name %d: ", i+1);
        scanf("%s", movie_name);
        init_movie(&movies[i], movie_name);
    }
    printf("\n");

    printf("Please enter the number of raters: ");
    scanf("%d", &num_raters);
    for (i = 0; i < num_raters; i++) {
        printf("Enter rater name %d: ", i+1);
        scanf("%s", rater_name);
        init_rater(&raters[i], rater_name);
    }
    printf("\n");

    printf("Please enter ratings for each movie:\n");
    for (i = 0; i < num_movies; i++) {
        printf("Movie %s:\n", movies[i].name);
        for (j = 0; j < num_raters; j++) {
            printf("Rater %s: ", raters[j].name);
            scanf("%d", &rating);
            rate_movie(&movies[i], &raters[j]);
        }
        printf("\n");
    }

    printf("Movie ratings:\n");
    for (i = 0; i < num_movies; i++) {
        print_movie(&movies[i]);
    }

    printf("Rater ratings:\n");
    for (i = 0; i < num_raters; i++) {
        print_rater(&raters[i]);
    }

    return 0;
}