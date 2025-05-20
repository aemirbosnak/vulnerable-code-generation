//FormAI DATASET v1.0 Category: Movie Rating System ; Style: accurate
#include <stdio.h>

// Function to get user input for the ratings
void get_ratings(int ratings[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter rating for movie %d (out of 10): ", i+1);
        scanf("%d", &ratings[i]);
    }
}

// Function to calculate average rating of all the movies
float get_average_rating(int ratings[], int n) {
    float sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += ratings[i];
    }
    return sum / n;
}

// Function to print the ratings of all the movies
void print_ratings(int ratings[], int n) {
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("Movie %d: %d/10\n", i+1, ratings[i]);
    }
}

// Function to print recommended movies based on the ratings
void print_recommendations(int ratings[], int n) {
    printf("\n************* Recommended Movies *************\n");
    for (int i = 0; i < n; i++) {
        if (ratings[i] >= 8) {
            printf("Movie %d\n", i+1);
        }
    }
}

int main() {
    int n;
    printf("How many movies are you rating? ");
    scanf("%d", &n);
    
    // Allocate memory for ratings array dynamically
    int *ratings = malloc(sizeof(int) * n);
    
    // Get user input for the ratings
    get_ratings(ratings, n);
    
    // Calculate the average rating of all the movies
    float avg_rating = get_average_rating(ratings, n);
    
    // Print the ratings of all the movies
    print_ratings(ratings, n);
    
    // Print the average rating of all the movies
    printf("\nAverage Rating: %.2f/10\n", avg_rating);
    
    // Print recommended movies based on the ratings
    print_recommendations(ratings, n);
    
    // Free the dynamically allocated memory
    free(ratings);
    
    return 0;
}