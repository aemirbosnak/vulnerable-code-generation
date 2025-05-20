//FormAI DATASET v1.0 Category: Movie Rating System ; Style: optimized
#include <stdio.h>

// Global variables
int rating_count[5] = {0, 0, 0, 0, 0};        // keep count of the number of each rating
int total_movies = 0;                 // keep count of the total number of movies

// Function to get the movie rating from the user
int get_rating() {
    int rating;

    printf("Enter rating (1-5): ");
    scanf("%d", &rating);

    // Validation
    if (rating < 1 || rating > 5) {
        printf("Invalid rating entered\n");
        return get_rating();        // recursively call function until valid rating is entered
    } else {
        return rating;
    }
}

// Function to add a movie to the system
void add_movie() {
    int rating = get_rating();

    // Update global variables
    rating_count[rating-1]++;
    total_movies++;

    printf("Movie added successfully\n");
}

// Function to get the average rating of all movies
float get_average_rating() {
    float sum = 0;

    for (int i = 0; i < 5; i++) {
        sum += (rating_count[i] * (i+1));       // multiply count of rating by rating value
    }

    // Return the average rating
    return sum / total_movies;
}

// Function to print the movie ratings distribution
void print_distribution() {
    printf("Ratings distribution:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d star: %d\n", i+1, rating_count[i]);
    }
}

int main() {
    int choice = 0;
    float average_rating;

    // Loop until user chooses to exit
    while (choice != 4) {
        printf("\n========= Movie Rating System =========\n");
        printf("1. Add a movie\n");
        printf("2. Get average rating\n");
        printf("3. Print ratings distribution\n");
        printf("4. Exit\n");

        // Get user choice
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_movie();
                break;
            case 2:
                if (total_movies == 0) {
                    printf("No movies added yet\n");
                    break;
                }
                average_rating = get_average_rating();
                printf("Average rating: %.2f\n", average_rating);
                break;
            case 3:
                if (total_movies == 0) {
                    printf("No movies added yet\n");
                    break;
                }
                print_distribution();
                break;
            case 4:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice entered\n");
        }
    }

    return 0;
}