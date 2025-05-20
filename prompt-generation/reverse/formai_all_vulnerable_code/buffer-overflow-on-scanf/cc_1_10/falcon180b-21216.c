//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_RATINGS 10
#define MAX_RATING_NAME_LENGTH 50
#define MAX_RATING_VALUE_LENGTH 10

typedef struct {
    char name[MAX_RATING_NAME_LENGTH];
    char value[MAX_RATING_VALUE_LENGTH];
} Rating;

int main() {
    int numRatings;
    Rating ratings[MAX_RATINGS];
    char movieName[MAX_RATING_NAME_LENGTH];

    printf("Welcome to the C Movie Rating System!\n\n");

    // Get number of ratings from user
    printf("How many ratings do you want to enter? ");
    scanf("%d", &numRatings);

    // Get movie name
    printf("Enter the name of the movie: ");
    scanf("%s", movieName);

    // Get ratings from user
    for (int i = 0; i < numRatings; i++) {
        printf("Enter rating #%d:\n", i+1);
        printf("Name: ");
        scanf("%s", ratings[i].name);
        printf("Value: ");
        scanf("%s", ratings[i].value);
    }

    // Calculate average rating
    double totalRating = 0.0;
    for (int i = 0; i < numRatings; i++) {
        double ratingValue = atof(ratings[i].value);
        totalRating += ratingValue;
    }
    double averageRating = totalRating / numRatings;

    // Display ratings and average rating
    printf("\nRatings for %s:\n", movieName);
    for (int i = 0; i < numRatings; i++) {
        printf("Name: %s\nValue: %s\n", ratings[i].name, ratings[i].value);
    }
    printf("\nAverage rating: %.2f\n", averageRating);

    return 0;
}