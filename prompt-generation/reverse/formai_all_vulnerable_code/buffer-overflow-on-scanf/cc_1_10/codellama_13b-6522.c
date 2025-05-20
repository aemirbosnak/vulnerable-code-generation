//Code Llama-13B DATASET v1.0 Category: Movie Rating System ; Style: statistical
// Movie Rating System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RATINGS 10

// Structure to store movie details
struct Movie {
    char title[50];
    int rating;
};

// Function to get movie title and rating from user
void get_movie_details(struct Movie *movie) {
    printf("Enter movie title: ");
    scanf("%s", movie->title);
    printf("Enter movie rating: ");
    scanf("%d", &movie->rating);
}

// Function to calculate the average rating of all movies
double calculate_average_rating(struct Movie movies[], int num_movies) {
    double total_rating = 0;
    for (int i = 0; i < num_movies; i++) {
        total_rating += movies[i].rating;
    }
    return total_rating / num_movies;
}

// Function to calculate the variance of the ratings
double calculate_variance(struct Movie movies[], int num_movies, double average_rating) {
    double variance = 0;
    for (int i = 0; i < num_movies; i++) {
        variance += pow(movies[i].rating - average_rating, 2);
    }
    return variance / (num_movies - 1);
}

// Function to calculate the standard deviation of the ratings
double calculate_std_deviation(struct Movie movies[], int num_movies, double variance) {
    return sqrt(variance);
}

// Function to print the rating information of all movies
void print_rating_info(struct Movie movies[], int num_movies, double average_rating, double std_deviation) {
    printf("Average rating: %.2f\n", average_rating);
    printf("Standard deviation: %.2f\n", std_deviation);
    for (int i = 0; i < num_movies; i++) {
        printf("Movie: %s\tRating: %d\n", movies[i].title, movies[i].rating);
    }
}

int main() {
    // Initialize array of movies
    struct Movie movies[MAX_RATINGS];

    // Get movie details from user
    for (int i = 0; i < MAX_RATINGS; i++) {
        get_movie_details(&movies[i]);
    }

    // Calculate average rating and variance of ratings
    double average_rating = calculate_average_rating(movies, MAX_RATINGS);
    double variance = calculate_variance(movies, MAX_RATINGS, average_rating);
    double std_deviation = calculate_std_deviation(movies, MAX_RATINGS, variance);

    // Print rating information of all movies
    print_rating_info(movies, MAX_RATINGS, average_rating, std_deviation);

    return 0;
}