//FormAI DATASET v1.0 Category: Movie Rating System ; Style: systematic
#include <stdio.h>

// Function to get user input and validate the input
int getUserInput() {
    int rating;
    do {
        printf("Enter a rating between 1 and 5: ");
        scanf("%d", &rating);
        if (rating < 1 || rating > 5) {
            printf("Invalid Rating! Please enter a rating between 1 and 5.\n");
        }
    } while (rating < 1 || rating > 5);

    return rating;
}

int main() {
    // create an array for storing movie ratings
    int ratings[50];

    // Get the number of movies
    int n;
    printf("Enter the number of movies you want to rate: ");
    scanf("%d", &n);

    // Get ratings from user and store in the array
    for (int i = 0; i < n; i++) {
        printf("Enter rating for movie %d: \n", i+1);
        ratings[i] = getUserInput();
    }

    // calculate the average rating
    float averageRating = 0;
    for(int i = 0; i < n; i++) {
        averageRating += ratings[i];
    }
    averageRating /= n;

    printf("Average rating of %d movies: %.2f \n", n, averageRating);

    // Evaluate the rating
    if (averageRating < 2) {
        printf("This is a bad movie.");
    } else if (averageRating < 3) {
        printf("This is an average movie.");
    } else if (averageRating < 4) {
        printf("This is a good movie.");
    } else {
        printf("This is an excellent movie!");
    }

    return 0;
}