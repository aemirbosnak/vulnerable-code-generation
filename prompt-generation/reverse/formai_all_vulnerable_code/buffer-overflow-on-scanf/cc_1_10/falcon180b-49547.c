//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max (inclusive)
int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to print a movie rating
void print_rating(int num_stars) {
    for (int i = 0; i < num_stars; i++) {
        printf("*");
    }
    printf("\n");
}

// Function to get a movie rating from the user
int get_rating() {
    int rating = 0;
    while (rating < 1 || rating > 5) {
        printf("Enter a rating (1-5): ");
        scanf("%d", &rating);
    }
    return rating;
}

// Function to simulate a movie rating system
void simulate_rating_system() {
    srand(time(NULL)); // Seed the random number generator with the current time
    int num_movies = rand_int(10, 20); // Generate a random number of movies
    printf("Rating %d movies...\n", num_movies);
    for (int i = 0; i < num_movies; i++) {
        int num_ratings = rand_int(10, 20); // Generate a random number of ratings for each movie
        printf("Movie %d has %d ratings.\n", i+1, num_ratings);
        int total_rating = 0;
        for (int j = 0; j < num_ratings; j++) {
            int rating = get_rating(); // Get a rating from the user
            total_rating += rating;
            print_rating(rating); // Print the rating
        }
        double avg_rating = (double)total_rating / num_ratings;
        printf("Average rating for movie %d: %.2f\n\n", i+1, avg_rating);
    }
}

int main() {
    simulate_rating_system();
    return 0;
}