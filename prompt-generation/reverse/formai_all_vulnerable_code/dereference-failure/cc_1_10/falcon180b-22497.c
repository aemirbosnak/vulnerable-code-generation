//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_RATINGS 100
#define MAX_RATING_LENGTH 100

typedef struct {
    char *rating;
    int votes;
} Rating;

Rating ratings[MAX_RATINGS];
int num_ratings;

void add_rating(char *rating) {
    if (num_ratings >= MAX_RATINGS) {
        printf("Error: Maximum number of ratings reached.\n");
        return;
    }

    int i;
    for (i = 0; i < num_ratings; i++) {
        if (strcmp(ratings[i].rating, rating) == 0) {
            ratings[i].votes++;
            return;
        }
    }

    strncpy(ratings[num_ratings].rating, rating, MAX_RATING_LENGTH);
    ratings[num_ratings].votes = 1;
    num_ratings++;
}

void print_ratings() {
    printf("Movie Ratings:\n");
    for (int i = 0; i < num_ratings; i++) {
        printf("%s: %d votes\n", ratings[i].rating, ratings[i].votes);
    }
}

int main() {
    num_ratings = 0;

    char input[MAX_RATING_LENGTH];
    while (true) {
        printf("Enter a movie rating (or type 'exit' to quit): ");
        fgets(input, MAX_RATING_LENGTH, stdin);

        if (strcmp(input, "exit") == 0) {
            break;
        }

        add_rating(input);
    }

    print_ratings();

    return 0;
}