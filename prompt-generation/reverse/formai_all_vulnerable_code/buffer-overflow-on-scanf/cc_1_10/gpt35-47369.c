//FormAI DATASET v1.0 Category: Movie Rating System ; Style: thoughtful
#include <stdio.h>

// Function to calculate the average of an array
float calculateAverage(int ratings[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ratings[i];
    }
    return (float) sum / n;
}

int main() {
    // Declare variables
    int n, rating, sum = 0;
    float average;

    // Ask user for input on number of ratings
    printf("How many ratings do you want to enter? ");
    scanf("%d", &n);

    // Create array to store ratings
    int ratings[n];

    // Ask user to enter ratings
    for (int i = 0; i < n; i++) {
        printf("Enter rating %d: ", i + 1);
        scanf("%d", &rating);

        // Check if rating is valid (must be between 1 and 5)
        if (rating < 1 || rating > 5) {
            printf("Invalid rating. Rating must be between 1 and 5.\n");
            i--;
        } else {
            ratings[i] = rating;
            sum += rating;
        }
    }

    // Calculate and display average rating
    average = calculateAverage(ratings, n);
    printf("The average rating is %.1f\n", average);

    // Determine rating level based on average
    if (average >= 4.5) {
        printf("This movie is amazing!\n");
    } else if (average >= 3.5) {
        printf("This movie is good.\n");
    } else if (average >= 2.5) {
        printf("This movie is average.\n");
    } else if (average >= 1.5) {
        printf("This movie is below average.\n");
    } else {
        printf("This movie is terrible!\n");
    }

    return 0;
}