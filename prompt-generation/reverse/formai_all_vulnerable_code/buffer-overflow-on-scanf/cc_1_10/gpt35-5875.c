//FormAI DATASET v1.0 Category: Movie Rating System ; Style: thoughtful
#include <stdio.h>

// Function to calculate the overall rating of a movie based on plot, acting, and special effects
int calculateOverallRating(int plot, int acting, int specialEffects) {
    int overallRating = (plot + acting + specialEffects) / 3;
    return overallRating;
}

// Function to display rating category based on overall rating
void displayRatingCategory(int overallRating) {
    if (overallRating >= 90) {
        printf("Rating Category: Outstanding\n");
    } else if (overallRating >= 80) {
        printf("Rating Category: Excellent\n");
    } else if (overallRating >= 70) {
        printf("Rating Category: Good\n");
    } else if (overallRating >= 60) {
        printf("Rating Category: Average\n");
    } else {
        printf("Rating Category: Below Average\n");
    }
}

// Main function
int main() {
    // Input variables
    int plot, acting, specialEffects;

    // Get user input for plot rating
    printf("Enter Plot Rating (out of 100): ");
    scanf("%d", &plot);

    // Get user input for acting rating
    printf("Enter Acting Rating (out of 100): ");
    scanf("%d", &acting);

    // Get user input for special effects rating
    printf("Enter Special Effects Rating (out of 100): ");
    scanf("%d", &specialEffects);

    // Calculate overall rating
    int overallRating = calculateOverallRating(plot, acting, specialEffects);

    // Display overall rating
    printf("Overall Rating: %d\n", overallRating);

    // Display rating category
    displayRatingCategory(overallRating);

    return 0;
}