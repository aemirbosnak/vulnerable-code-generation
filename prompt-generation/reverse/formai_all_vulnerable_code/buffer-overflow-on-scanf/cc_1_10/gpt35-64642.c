//FormAI DATASET v1.0 Category: Movie Rating System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 50
#define MAX_TITLE_LENGTH 50

// Define a movie struct
typedef struct {
    char title[MAX_TITLE_LENGTH];
    int rating;
} Movie;

// Define a function to add a movie to the movie array
void addMovie(Movie *movies, int *numMovies) {
    // Check for max number of movies
    if (*numMovies >= MAX_MOVIES) {
        printf("Sorry, you have reached the maximum number of movies.\n");
        return;
    }
    // Prompt user for movie title and rating
    char title[MAX_TITLE_LENGTH];
    int rating;
    printf("What is the title of the movie?\n");
    scanf("%s", title);
    printf("What is your rating of the movie (1-10)?\n");
    scanf("%d", &rating);
    // Create the movie struct and add it to the movie array
    Movie movie;
    strcpy(movie.title, title);
    movie.rating = rating;
    movies[*numMovies] = movie;
    // Increment the number of movies counter
    (*numMovies)++;
    printf("Movie added successfully!\n");
}

// Define a function to display all movies in the movie array
void displayMovies(Movie *movies, int numMovies) {
    // Check for no movies
    if (numMovies == 0) {
        printf("You have no movies to display.\n");
        return;
    }
    // Display the header
    printf("Medieval Movie List:\n");
    printf("--------------------\n");
    // Loop through all movies and display them
    for (int i = 0; i < numMovies; i++) {
        printf("%s - ", movies[i].title);
        int rating = movies[i].rating;
        for (int j = 0; j < rating; j++) {
            printf("*");
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Initialize the movie array and number of movies counter
    Movie movies[MAX_MOVIES];
    int numMovies = 0;
    // Display a welcome message and menu options
    printf("Welcome to the Medieval Movie Rating System!\n");
    printf("---------------------------------------------\n");
    printf("1) Add a movie\n");
    printf("2) Display all movies\n");
    printf("3) Quit\n");
    // Start the menu loop
    int choice;
    do {
        // Prompt user for choice
        printf("What would you like to do?\n");
        scanf("%d", &choice);
        // Call the appropriate function based on user choice
        switch (choice) {
            case 1:
                addMovie(movies, &numMovies);
                break;
            case 2:
                displayMovies(movies, numMovies);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 3);
    return 0;
}