//FormAI DATASET v1.0 Category: Movie Rating System ; Style: systematic
#include <stdio.h>

// Define the maximum number of ratings to be collected
#define MAX_RATINGS 10

int main() {
    // Declare variables for collecting ratings and calculating average
    int ratings[MAX_RATINGS];
    int num_ratings = 0;
    int total_rating = 0;

    // Loop until the maximum number of ratings is collected or the user enters -1
    while (num_ratings < MAX_RATINGS) {
        printf("Enter a rating (1-10) or enter -1 to finish: ");
        int rating;
        scanf("%d", &rating);

        // Exit the loop if the user enters -1
        if (rating == -1) {
            break;
        }

        // Validate the rating and add to the ratings array
        if (rating >= 1 && rating <= 10) {
            ratings[num_ratings] = rating;
            num_ratings++;
            total_rating += rating;
        } else {
            printf("Invalid rating. Please enter a rating between 1 and 10.\n");
        }
    }

    // Calculate the average rating and print the result
    float avg_rating = (float) total_rating / num_ratings;
    printf("Number of ratings: %d\n", num_ratings);
    printf("Average rating: %.2f\n\n", avg_rating);

    // Print a visual representation of the rating scale
    printf("Rating Scale:\n");
    printf(" 1  2  3  4  5  6  7  8  9  10\n");

    // Count the number of occurrences of each rating and print the result
    printf("Distribution of Ratings:\n");
    for (int i = 1; i <= 10; i++) {
        int count = 0;
        for (int j = 0; j < num_ratings; j++) {
            if (ratings[j] == i) {
                count++;
            }
        }
        printf("%2d ", count);
        for (int k = 0; k < count; k++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}