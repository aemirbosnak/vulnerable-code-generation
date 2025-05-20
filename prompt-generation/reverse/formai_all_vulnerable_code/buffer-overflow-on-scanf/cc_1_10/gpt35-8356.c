//FormAI DATASET v1.0 Category: Movie Rating System ; Style: protected
#include <stdio.h>

// Define a structure to hold a movie's rating
typedef struct {
    int stars; // from 1 to 5 stars
    int num_reviews; // number of reviews
} Rating;

// Define a function to get a movie's rating from the user
Rating get_rating() {
    Rating rating;
    rating.stars = 0;
    rating.num_reviews = 0;

    // Prompt the user for the number of reviews
    printf("Enter the number of reviews: ");
    scanf("%d", &rating.num_reviews);

    // Prompt the user for the rating for each review
    for (int i = 0; i < rating.num_reviews; i++) {
        int stars = 0;
        printf("Enter the rating for review %d: ", i + 1);
        scanf("%d", &stars);

        // Make sure the rating is between 1 and 5 stars
        while (stars < 1 || stars > 5) {
            printf("Invalid rating. Enter a rating between 1 and 5: ");
            scanf("%d", &stars);
        }

        // Add the rating to the total number of stars
        rating.stars += stars;
    }

    return rating;
}

// Define a function to calculate a movie's average rating
float avg_rating(Rating rating) {
    if (rating.num_reviews == 0) {
        return 0.0;
    }

    return (float) rating.stars / rating.num_reviews;
}

int main() {
    // Get the ratings for two movies
    printf("Enter the ratings for movie 1:\n");
    Rating rating1 = get_rating();

    printf("\nEnter the ratings for movie 2:\n");
    Rating rating2 = get_rating();

    // Calculate the average ratings for the two movies
    float avg1 = avg_rating(rating1);
    float avg2 = avg_rating(rating2);

    // Display the movie ratings
    printf("\nMovie 1:\n");
    printf("Number of reviews: %d\n", rating1.num_reviews);
    printf("Average rating: %.2f stars\n", avg1);

    printf("\nMovie 2:\n");
    printf("Number of reviews: %d\n", rating2.num_reviews);
    printf("Average rating: %.2f stars\n", avg2);

    // Determine which movie has the higher rating
    if (avg1 > avg2) {
        printf("\nMovie 1 has a higher rating than movie 2!\n");
    } else if (avg2 > avg1) {
        printf("\nMovie 2 has a higher rating than movie 1!\n");
    } else {
        printf("\nBoth movies have the same rating!\n");
    }

    return 0;
}