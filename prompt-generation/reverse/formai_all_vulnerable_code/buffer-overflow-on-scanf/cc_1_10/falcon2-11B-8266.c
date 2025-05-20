//Falcon2-11B DATASET v1.0 Category: Movie Rating System ; Style: futuristic
// Future Movie Rating System
#include <stdio.h>
#include <string.h>

// Function to calculate rating based on average score
float calculateRating(int numRatings, int* scores) {
    int sum = 0;
    for (int i = 0; i < numRatings; i++) {
        sum += scores[i];
    }
    return (float)sum / numRatings;
}

// Function to display movie rating
void displayRating(int rating) {
    if (rating < 0) {
        printf("Invalid rating\n");
    } else if (rating >= 0 && rating < 1) {
        printf("Horrible\n");
    } else if (rating >= 1 && rating < 2) {
        printf("Bad\n");
    } else if (rating >= 2 && rating < 3) {
        printf("Average\n");
    } else if (rating >= 3 && rating < 4) {
        printf("Good\n");
    } else if (rating >= 4 && rating < 5) {
        printf("Very Good\n");
    } else if (rating >= 5 && rating <= 6) {
        printf("Excellent\n");
    } else {
        printf("Perfect\n");
    }
}

int main() {
    int numRatings, rating;
    int scores[7];

    // Input number of ratings and scores
    printf("Enter number of ratings: ");
    scanf("%d", &numRatings);
    printf("Enter scores: ");
    for (int i = 0; i < numRatings; i++) {
        scanf("%d", &scores[i]);
    }

    // Calculate average rating
    float averageRating = calculateRating(numRatings, scores);

    // Display movie rating
    printf("Average Rating: %.2f\n", averageRating);
    displayRating(averageRating);

    return 0;
}