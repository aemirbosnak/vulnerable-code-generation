//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_MOVIES 5
#define MAX_NAME_LEN 100
#define MAX_RATING_LEN 10
#define MAX_REVIEW_LEN 200

typedef struct {
    char name[MAX_NAME_LEN];
    char rating[MAX_RATING_LEN];
    char review[MAX_REVIEW_LEN];
} Movie;

void print_movie(Movie* movie) {
    printf("Name: %s\n", movie->name);
    printf("Rating: %s\n", movie->rating);
    printf("Review: %s\n\n", movie->review);
}

int main() {
    Movie movies[NUM_MOVIES];
    char input[MAX_NAME_LEN + MAX_RATING_LEN + MAX_REVIEW_LEN + 1];
    int i, j;

    printf("Enter movie names, ratings, and reviews (separated by spaces):\n");
    for (i = 0; i < NUM_MOVIES; i++) {
        fgets(input, sizeof(input), stdin);
        j = 0;
        while (input[j]!= '\n') {
            if (j < MAX_NAME_LEN) {
                movies[i].name[j] = input[j];
                j++;
            } else if (j < MAX_NAME_LEN + MAX_RATING_LEN) {
                movies[i].rating[j - MAX_NAME_LEN] = input[j];
                j++;
            } else {
                movies[i].review[j - MAX_NAME_LEN - MAX_RATING_LEN] = input[j];
                j++;
            }
        }
        movies[i].name[j] = '\0';
        movies[i].rating[j - MAX_NAME_LEN] = '\0';
        movies[i].review[j - MAX_NAME_LEN - MAX_RATING_LEN] = '\0';
    }

    printf("Movie Ratings:\n");
    for (i = 0; i < NUM_MOVIES; i++) {
        print_movie(&movies[i]);
    }

    return 0;
}