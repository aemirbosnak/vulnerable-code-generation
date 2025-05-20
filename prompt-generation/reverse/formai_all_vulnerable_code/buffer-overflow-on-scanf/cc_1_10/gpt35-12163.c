//FormAI DATASET v1.0 Category: Movie Rating System ; Style: ephemeral
#include <stdio.h>

// Define movie struct
typedef struct {
    char title[50];
    char director[50];
    int year;
    float rating;
} Movie;

// Function to get user rating input
float get_rating() {
    float rating;
    printf("Enter your rating (0.0 - 10.0): ");
    scanf("%f", &rating);
    // Validate rating input
    if (rating < 0.0 || rating > 10.0) {
        printf("Invalid rating. Please enter a rating between 0.0 and 10.0.\n");
        return get_rating();
    }
    return rating;
}

// Function to print movie information
void print_movie(Movie movie) {
    printf("Title: %s\n", movie.title);
    printf("Director: %s\n", movie.director);
    printf("Year: %d\n", movie.year);
    printf("Rating: %.1f\n\n", movie.rating);
}

int main() {
    // Declare array of 5 movies
    Movie movies[5];

    // Prompt user for movie information and rating for each movie
    for (int i = 0; i < 5; i++) {
        printf("Enter information for movie %d:\n", i+1);
        printf("Title: ");
        scanf("%s", movies[i].title);
        printf("Director: ");
        scanf("%s", movies[i].director);
        printf("Year: ");
        scanf("%d", &movies[i].year);
        // Get user rating input
        movies[i].rating = get_rating();
        printf("\n");
    }

    // Print movie information and average rating
    float total_rating = 0.0;
    printf("Movie Ratings:\n");
    for (int i = 0; i < 5; i++) {
        print_movie(movies[i]);
        total_rating += movies[i].rating;
    }
    // Calculate and print average rating
    float average_rating = total_rating / 5;
    printf("Average Rating: %.1f\n", average_rating);

    return 0;
}