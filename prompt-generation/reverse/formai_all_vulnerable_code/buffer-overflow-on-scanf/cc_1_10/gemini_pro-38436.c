//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: curious
#include <stdio.h>

// Declare a few constants for our rating system
#define AWFUL          0
#define BAD            1
#define OK             2
#define GOOD           3
#define EXCELLENT      4

// Declare a function to get the user's input
int get_rating(void) {
    int rating;

    // Prompt the user for their rating
    printf("Please enter your rating (0-4): ");

    // Get the user's input
    scanf("%d", &rating);

    // Return the user's rating
    return rating;
}

// Declare a function to print the rating
void print_rating(int rating) {
    switch (rating) {
        case AWFUL:
            printf("Awful\n");
            break;
        case BAD:
            printf("Bad\n");
            break;
        case OK:
            printf("OK\n");
            break;
        case GOOD:
            printf("Good\n");
            break;
        case EXCELLENT:
            printf("Excellent\n");
            break;
        default:
            printf("Invalid rating\n");
    }
}

// Declare a function to calculate the average rating
double calculate_average_rating(int *ratings, int num_ratings) {
    int sum = 0;
    double average;

    // Calculate the sum of the ratings
    for (int i = 0; i < num_ratings; i++) {
        sum += ratings[i];
    }

    // Calculate the average rating
    average = (double)sum / num_ratings;

    // Return the average rating
    return average;
}

// Declare a function to print the average rating
void print_average_rating(double average_rating) {
    printf("The average rating is: %.2f\n", average_rating);
}

// Declare a function to main
int main(void) {
    int ratings[5];
    double average_rating;

    // Get the user's ratings
    for (int i = 0; i < 5; i++) {
        ratings[i] = get_rating();
    }

    // Calculate the average rating
    average_rating = calculate_average_rating(ratings, 5);

    // Print the average rating
    print_average_rating(average_rating);

    return 0;
}