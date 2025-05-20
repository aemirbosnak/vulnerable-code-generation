//FormAI DATASET v1.0 Category: Movie Rating System ; Style: scientific
#include <stdio.h>

// Function to calculate the overall rating of the movie
int calculateOverallRating(int story, int acting, int direction, int music) {
    int overall_rating = (story + acting + direction + music) / 4;
    return overall_rating;
}

// Function to determine the rating scale based on overall rating
char* determineRatingScale(int overall_rating) {
    if (overall_rating >= 90) {
        return "A+";
    } else if (overall_rating >= 80) {
        return "A";
    } else if (overall_rating >= 70) {
        return "B";
    } else if (overall_rating >= 60) {
        return "C";
    } else if (overall_rating >= 50) {
        return "D";
    } else {
        return "F";
    }
}

int main() {
    int story, acting, direction, music;

    // Getting the user inputs
    printf("Enter the story rating (out of 100): ");
    scanf("%d", &story);
    printf("Enter the acting rating (out of 100): ");
    scanf("%d", &acting);
    printf("Enter the direction rating (out of 100): ");
    scanf("%d", &direction);
    printf("Enter the music rating (out of 100): ");
    scanf("%d", &music);

    // Calculating the overall rating
    int overall_rating = calculateOverallRating(story, acting, direction, music);

    // Determining the rating scale
    char* rating_scale = determineRatingScale(overall_rating);

    // Displaying the overall rating and rating scale
    printf("\nOverall rating: %d%%\n", overall_rating);
    printf("Rating scale: %s\n", rating_scale);

    return 0;
}