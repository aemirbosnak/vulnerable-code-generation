//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: cheerful
#include <stdio.h>

// Define the maximum number of movies
#define MAX_MOVIES 10

// Define the structure of a movie
typedef struct {
    char title[50];
    int rating;
    char review[200];
} Movie;

// Define the array of movies
Movie movies[MAX_MOVIES];

// Get the user's input
void get_input() {
    int i;

    for (i = 0; i < MAX_MOVIES; i++) {
        printf("Enter the title of movie %d: ", i + 1);
        scanf("%s", movies[i].title);

        printf("Enter the rating of movie %d (1-5): ", i + 1);
        scanf("%d", &movies[i].rating);

        printf("Enter a review of movie %d: ", i + 1);
        scanf(" %[^\n]s", movies[i].review);  // Read a line of text with spaces
    }
}

// Print the movie ratings
void print_ratings() {
    int i;

    printf("\nMovie Ratings:\n");

    for (i = 0; i < MAX_MOVIES; i++) {
        printf("%s: %d\n", movies[i].title, movies[i].rating);
    }
}

// Get the average rating
double get_average_rating() {
    int i;
    double average_rating;

    average_rating = 0.0;

    for (i = 0; i < MAX_MOVIES; i++) {
        average_rating += movies[i].rating;
    }

    average_rating /= MAX_MOVIES;

    return average_rating;
}

// Print the average rating
void print_average_rating() {
    double average_rating;

    average_rating = get_average_rating();

    printf("\nAverage Rating: %.2f\n", average_rating);
}

// Main function
int main() {
    // Get the user's input
    get_input();

    // Print the movie ratings
    print_ratings();

    // Print the average rating
    print_average_rating();

    return 0;
}