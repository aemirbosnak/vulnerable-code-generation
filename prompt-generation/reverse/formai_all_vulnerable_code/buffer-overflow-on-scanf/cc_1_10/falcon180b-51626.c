//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_RATINGS 100
#define MAX_RATING_LENGTH 5

struct rating {
    char name[MAX_RATING_LENGTH];
    int value;
};

int main() {
    int num_movies, num_ratings, i, j;
    char movie_name[MAX_RATING_LENGTH];
    struct rating ratings[MAX_RATINGS];

    // Get number of movies
    printf("Enter the number of movies: ");
    scanf("%d", &num_movies);

    // Get movie names and ratings
    for (i = 0; i < num_movies; i++) {
        printf("Enter movie %d name: ", i + 1);
        scanf("%s", movie_name);

        // Get number of ratings for the movie
        printf("Enter the number of ratings for %s: ", movie_name);
        scanf("%d", &num_ratings);

        // Get ratings for the movie
        for (j = 0; j < num_ratings; j++) {
            printf("Enter rating %d for %s: ", j + 1, movie_name);
            scanf("%s", ratings[j].name);
            ratings[j].value = atoi(ratings[j].name);
        }
    }

    // Calculate average rating for each movie
    for (i = 0; i < num_movies; i++) {
        int total_rating = 0;
        for (j = 0; j < num_ratings; j++) {
            total_rating += ratings[j].value;
        }
        double avg_rating = (double) total_rating / num_ratings;

        printf("Average rating for %s: %.2f\n", movie_name, avg_rating);
    }

    return 0;
}