//Falcon2-11B DATASET v1.0 Category: Movie Rating System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to get the user input for rating
int getRating() {
    int rating;
    printf("Enter your rating (1-5): ");
    scanf("%d", &rating);
    return rating;
}

// Function to generate random review for the movie
void generateReview(int rating) {
    switch (rating) {
        case 1:
            printf("I hated this movie!\n");
            break;
        case 2:
            printf("It was okay, but not great.\n");
            break;
        case 3:
            printf("It was just alright.\n");
            break;
        case 4:
            printf("I really enjoyed this movie!\n");
            break;
        case 5:
            printf("I absolutely loved this movie!\n");
            break;
        default:
            printf("Invalid rating entered.\n");
    }
}

// Function to print the movie review
void printReview(int rating) {
    printf("Movie Review:\n");
    generateReview(rating);
    printf("\n\n");
}

int main() {
    srand(time(NULL));  // Seed the random number generator
    int rating;

    do {
        rating = getRating();
    } while (rating < 1 || rating > 5);

    printf("Your rating is: %d\n", rating);
    printReview(rating);

    return 0;
}