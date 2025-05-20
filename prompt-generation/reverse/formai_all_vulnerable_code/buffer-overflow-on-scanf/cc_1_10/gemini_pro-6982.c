//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: Sherlock Holmes
// A Sherlockian Movie Rating System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the possible ratings
#define TERRIBLE  0
#define BAD       1
#define AVERAGE   2
#define GOOD      3
#define EXCELLENT 4

// Define the list of movies
char *movies[] = {
    "The Hound of the Baskervilles",
    "The Case of the Speckled Band",
    "The Adventure of the Blue Carbuncle",
    "The Red-Headed League",
    "The Five Orange Pips"
};

// Get the user's rating for a movie
int getRating(char *movie) {
    int rating;
    printf("Rate %s (0-4): ", movie);
    scanf("%d", &rating);
    return rating;
}

// Print the average rating for all movies
void printAverageRating() {
    int totalRating = 0;
    int numMovies = sizeof(movies) / sizeof(char *);
    for (int i = 0; i < numMovies; i++) {
        totalRating += getRating(movies[i]);
    }
    float averageRating = (float)totalRating / numMovies;
    printf("Average rating: %.2f\n", averageRating);
}

// Print the best and worst movies
void printBestAndWorstMovies() {
    int bestRating = TERRIBLE;
    char *bestMovie = NULL;
    int worstRating = EXCELLENT;
    char *worstMovie = NULL;
    int numMovies = sizeof(movies) / sizeof(char *);
    for (int i = 0; i < numMovies; i++) {
        int rating = getRating(movies[i]);
        if (rating > bestRating) {
            bestRating = rating;
            bestMovie = movies[i];
        }
        if (rating < worstRating) {
            worstRating = rating;
            worstMovie = movies[i];
        }
    }
    printf("Best movie: %s (%d)\n", bestMovie, bestRating);
    printf("Worst movie: %s (%d)\n", worstMovie, worstRating);
}

// Main function
int main() {
    // Welcome the user
    printf("Welcome to the Sherlock Holmes Movie Rating System!\n");

    // Get the user's ratings for all movies
    int numMovies = sizeof(movies) / sizeof(char *);
    for (int i = 0; i < numMovies; i++) {
        getRating(movies[i]);
    }

    // Print the average rating for all movies
    printAverageRating();

    // Print the best and worst movies
    printBestAndWorstMovies();

    // Thank the user
    printf("\nThank you for using the Sherlock Holmes Movie Rating System!\n");

    return 0;
}