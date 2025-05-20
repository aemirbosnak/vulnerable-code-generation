//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the average rating
double calculate_average_rating(int ratings[], int num_ratings) {
    int sum = 0;
    for (int i = 0; i < num_ratings; i++) {
        sum += ratings[i];
    }
    return (double)sum / num_ratings;
}

// Function to print the movie ratings
void print_movie_ratings(int ratings[], int num_ratings) {
    printf("Movie Ratings:\n");
    for (int i = 0; i < num_ratings; i++) {
        printf("%d stars\n", ratings[i]);
    }
}

int main() {
    int num_movies;
    printf("Enter the number of movies: ");
    scanf("%d", &num_movies);

    // Dynamically allocate memory for the movie ratings
    int **ratings = (int **)malloc(num_movies * sizeof(int *));
    for (int i = 0; i < num_movies; i++) {
        ratings[i] = (int *)malloc(10 * sizeof(int)); // Assume at most 10 ratings for each movie
    }

    // Get the ratings for each movie
    for (int i = 0; i < num_movies; i++) {
        printf("Enter the ratings for movie %d (0-10): ", i + 1);
        for (int j = 0; j < 10; j++) {
            scanf("%d", &ratings[i][j]);
        }
    }

    // Calculate the average ratings for each movie
    for (int i = 0; i < num_movies; i++) {
        int num_ratings = 0;
        while (ratings[i][num_ratings]!= 0) {
            num_ratings++;
        }
        double avg_rating = calculate_average_rating(ratings[i], num_ratings);
        printf("Average rating for movie %d: %.2f stars\n", i + 1, avg_rating);
    }

    // Free the dynamically allocated memory
    for (int i = 0; i < num_movies; i++) {
        free(ratings[i]);
    }
    free(ratings);

    return 0;
}