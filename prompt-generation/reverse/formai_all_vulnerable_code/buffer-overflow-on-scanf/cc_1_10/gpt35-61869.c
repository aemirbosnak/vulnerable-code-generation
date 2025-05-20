//FormAI DATASET v1.0 Category: Movie Rating System ; Style: light-weight
#include <stdio.h>

// Global variables
int numReviews = 0;
float totalScore = 0;

// Function prototypes
void addReview(int score);
float calculateAverage();

int main() {
    int input;
    printf("Welcome to the C Movie Rating System!\n");
    printf("Enter a movie rating between 1 and 10 (press -1 to exit): ");

    while (1) {
        scanf("%d", &input);
        if (input == -1) {
            printf("Exiting...\n");
            break;
        } else if (input < 1 || input > 10) {
            printf("Error: invalid rating. Try again.\n");
            continue;
        } else {
            addReview(input);
            printf("Movie rating added. Enter another rating (press -1 to exit): ");
        }
    }

    float avgScore = calculateAverage();
    printf("Total movie ratings: %d\n", numReviews);
    printf("Average rating: %.2f\n", avgScore);

    if (avgScore >= 7) {
        printf("This movie is highly recommended!\n");
    } else if (avgScore >= 5) {
        printf("This movie is worth watching.\n");
    } else {
        printf("This movie is not recommended.\n");
    }

    return 0;
}

// Add a review to the total score
void addReview(int score) {
    numReviews++;
    totalScore += score;
}

// Calculate the average movie rating
float calculateAverage() {
    if (numReviews == 0) {
        return 0;
    }
    return totalScore / numReviews;
}