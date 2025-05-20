//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RATING_COUNT 5
#define RATING_MAX 10

int main() {
    char movie_title[100];
    int rating_array[RATING_COUNT] = {0};
    double avg_rating = 0.0;
    int i, j;

    // Prompt user for movie title
    printf("Enter movie title: ");
    scanf("%s", movie_title);

    // Get rating from user
    printf("Enter rating (0-10): ");
    scanf("%d", &rating_array[0]);

    // Generate random ratings
    srand(time(NULL));
    for (i = 1; i < RATING_COUNT; i++) {
        rating_array[i] = rand() % RATING_MAX + 1;
    }

    // Calculate average rating
    for (i = 0; i < RATING_COUNT; i++) {
        avg_rating += rating_array[i];
    }
    avg_rating /= RATING_COUNT;

    // Print rating summary
    printf("\n%s\n", movie_title);
    printf("Average rating: %.1f\n", avg_rating);
    printf("Ratings:\n");
    for (i = 0; i < RATING_COUNT; i++) {
        printf(" %d", rating_array[i]);
    }
    printf("\n");

    // Get user's age
    printf("Enter your age: ");
    scanf("%d", &j);

    // Print appropriate message based on age
    if (j < 13) {
        printf("Sorry, you are too young to watch this movie.\n");
    } else if (j >= 13 && j < 18) {
        printf("You can watch this movie with parental guidance.\n");
    } else {
        printf("You can watch this movie.\n");
    }

    return 0;
}