//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of movies that can be rated
#define MAX_MOVIES 100

// Define the structure for a movie rating
typedef struct {
    char title[100];
    int rating;
} MovieRating;

// Function to display the menu and get user input
void displayMenu(MovieRating movies[], int numMovies) {
    printf("Movie Rating System\n");
    printf("------------------\n");
    printf("1. Rate a movie\n");
    printf("2. View ratings\n");
    printf("3. Quit\n");
    printf("------------------\n");
    int choice;
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            // Get the title of the movie to rate
            printf("Enter the title of the movie: ");
            scanf("%s", movies[numMovies].title);
            // Get the rating for the movie
            printf("Enter the rating (1-5): ");
            scanf("%d", &movies[numMovies].rating);
            numMovies++;
            break;
        case 2:
            // Display the ratings for all movies
            printf("Movie Ratings:\n");
            for(int i=0; i<numMovies; i++) {
                printf("%s - %d\n", movies[i].title, movies[i].rating);
            }
            break;
        case 3:
            // Quit the program
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
    }
}

// Function to calculate the average rating for a movie
float calculateAverage(MovieRating movies[], int numMovies) {
    int totalRating = 0;
    for(int i=0; i<numMovies; i++) {
        totalRating += movies[i].rating;
    }
    return (float)totalRating / numMovies;
}

int main() {
    // Initialize the movie ratings array
    MovieRating movies[MAX_MOVIES];
    int numMovies = 0;

    // Display the menu and get user input
    while(1) {
        displayMenu(movies, numMovies);
    }

    return 0;
}