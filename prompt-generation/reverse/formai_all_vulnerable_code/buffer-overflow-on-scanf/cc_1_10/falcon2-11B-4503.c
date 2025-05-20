//Falcon2-11B DATASET v1.0 Category: Movie Rating System ; Style: accurate
#include <stdio.h>

// Define the number of movie ratings
#define RATING_COUNT 5

// Define the rating levels
#define MIN_RATING 1
#define MAX_RATING 5

int main() {
    // Initialize the ratings array
    int ratings[RATING_COUNT] = {0};

    // Prompt the user for movie ratings
    for (int i = 0; i < RATING_COUNT; i++) {
        printf("Enter the rating for movie %d: ", i+1);
        scanf("%d", &ratings[i]);
    }

    // Print the movie ratings
    printf("Movie ratings:\n");
    for (int i = 0; i < RATING_COUNT; i++) {
        printf("%d - ", ratings[i]);
    }
    printf("\n");

    // Calculate the average rating
    int sum = 0;
    for (int i = 0; i < RATING_COUNT; i++) {
        sum += ratings[i];
    }
    double avg_rating = (double)sum / RATING_COUNT;
    printf("Average rating: %.2f\n", avg_rating);

    // Determine the highest rated movie
    int max_rating = 0;
    int max_movie = 0;
    for (int i = 0; i < RATING_COUNT; i++) {
        if (ratings[i] > max_rating) {
            max_rating = ratings[i];
            max_movie = i+1;
        }
    }
    printf("Highest rated movie: %s (%d)\n", "Movie", max_movie);

    // Determine the lowest rated movie
    int min_rating = MAX_RATING;
    int min_movie = 0;
    for (int i = 0; i < RATING_COUNT; i++) {
        if (ratings[i] < min_rating) {
            min_rating = ratings[i];
            min_movie = i+1;
        }
    }
    printf("Lowest rated movie: %s (%d)\n", "Movie", min_movie);

    return 0;
}