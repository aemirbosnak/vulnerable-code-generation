//FormAI DATASET v1.0 Category: Movie Rating System ; Style: cheerful
#include <stdio.h>

// define constants
#define MAX_RATINGS 5
#define MIN_RATINGS 0

// define functions
char getGrade(double rating) {
    if (rating >= 4.5) {
        return 'A';
    } else if (rating >= 3.5) {
        return 'B';
    } else if (rating >= 2.5) {
        return 'C';
    } else if (rating >= 1.5) {
        return 'D';
    } else {
        return 'F';
    }
}

int main() {
    double ratings[MAX_RATINGS];
    int numRatings = 0;
    printf("Welcome to the C Movie Rating System!\n");

    while (numRatings < MAX_RATINGS) {
        printf("Please enter your rating (between %d and %d, or -1 to exit): ", MIN_RATINGS, MAX_RATINGS);
        double rating;
        scanf("%lf", &rating);
        if (rating == -1) {
            printf("Thank you for using the C Movie Rating System!\n");
            break;
        } else if (rating < MIN_RATINGS || rating > MAX_RATINGS) {
            printf("Invalid rating! Please try again.\n");
            continue;
        } else {
            ratings[numRatings] = rating;
            numRatings++;
        }
    }

    if (numRatings == 0) {
        printf("You did not rate any movies!\n");
    } else {
        double totalRating = 0;
        for (int i = 0; i < numRatings; i++) {
            totalRating += ratings[i];
        }
        double averageRating = totalRating / numRatings;
        char grade = getGrade(averageRating);
        printf("Your average rating is %.1lf, and your grade is %c!\n", averageRating, grade);
    }

    return 0;
}