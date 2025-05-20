//FormAI DATASET v1.0 Category: Movie Rating System ; Style: cheerful
#include <stdio.h>

// function to calculate average rating
float calculateAverage(int ratings[], int size) {
    int totalRatings = 0;
    float averageRating;

    for(int i = 0; i < size; i++) {
        totalRatings += ratings[i];
    }

    averageRating = (float)totalRatings / size;

    return averageRating;
}

int main() {
    int numRatings, rating;
    char movieName[50];

    // getting movie name input
    printf("Welcome to the C Movie Rating System!\n\n");
    printf("Please enter the name of the movie: ");
    scanf("%[^\n]", movieName);

    printf("\nHow many ratings would you like to enter for %s?: ", movieName);
    scanf("%d", &numRatings);

    int movieRatings[numRatings];

    // getting each rating input
    for(int i = 0; i < numRatings; i++) {
        printf("\nEnter rating %d: ", i+1);
        scanf("%d", &rating);

        // validating rating range
        if(rating > 10 || rating < 1) {
            printf("\nError: Invalid rating range. Ratings must be between 1-10.\n");

            // decrementing i to take another valid input
            i--;
        } else {
            movieRatings[i] = rating;
        }
    }

    float averageRating = calculateAverage(movieRatings, numRatings);

    printf("\n\nThank you for rating %s!\n\n", movieName);

    if(averageRating >= 9) {
        printf("Wow, %s is a fantastic movie!\n", movieName);
    } else if(averageRating > 6 && averageRating < 9) {
        printf("%s is a solid movie with some room for improvement. Keep up the good work!\n", movieName);
    } else {
        printf("Unfortunately, %s may not be the best movie to watch right now. But hey, there's always room for improvement, right?\n", movieName);
    }

    printf("\n%s has received an average rating of %.2f out of 10.", movieName, averageRating);

    return 0;
}