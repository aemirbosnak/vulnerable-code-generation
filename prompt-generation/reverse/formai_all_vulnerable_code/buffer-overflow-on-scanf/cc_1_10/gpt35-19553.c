//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum number of movies
#define MAX_MOVIES 100

// Define movie rating structure
typedef struct movieRating {
    char title[50];
    int rating;
} MovieRating;

// Define array to store movies
MovieRating movies[MAX_MOVIES];

// Define total number of movies
int numberOfMovies = 0;

// Function to add a new movie
void addMovie() {
    // Check if the number of movies has not exceeded the limit
    if (numberOfMovies >= MAX_MOVIES) {
        printf("Error: Maximum number of movies (%d) reached\n", MAX_MOVIES);
        return;
    }
    // Get movie title from user
    char title[50];
    printf("Enter movie title: ");
    scanf("%s", title);

    // Check if movie already exists in the array
    for (int i = 0; i < numberOfMovies; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            printf("Error: Movie already exists\n");
            return;
        }
    }

    // Get movie rating from user
    int rating;
    printf("Enter movie rating (1-10): ");
    scanf("%d", &rating);

    // Check if movie rating is valid
    if (rating < 1 || rating > 10) {
        printf("Error: Invalid rating\n");
        return;
    }

    // Add movie to array
    strcpy(movies[numberOfMovies].title, title);
    movies[numberOfMovies].rating = rating;
    numberOfMovies++;

    printf("Movie added successfully!\n");
}

// Function to display all movies
void displayMovies() {
    // Check if there are no movies
    if (numberOfMovies == 0) {
        printf("No movies found\n");
        return;
    }

    printf("Title\t\tRating\n");
    printf("========================\n");
    for (int i = 0; i < numberOfMovies; i++) {
        printf("%s\t%d\n", movies[i].title, movies[i].rating);
    }
}

// Function to search for a movie
void searchMovie() {
    // Check if there are no movies
    if (numberOfMovies == 0) {
        printf("No movies found\n");
        return;
    }

    // Get movie title from user
    char title[50];
    printf("Enter movie title to search: ");
    scanf("%s", title);

    // Search for movie in array
    for (int i = 0; i < numberOfMovies; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            printf("Title\t\tRating\n");
            printf("========================\n");
            printf("%s\t%d\n", movies[i].title, movies[i].rating);
            return;
        }
    }

    printf("Movie not found\n");
}

// Main function
int main() {
    // Define variables for user input
    char choice;
    int isValidChoice = 0;

    // Display main menu
    printf("=====================================\n");
    printf("  C MOVIE RATING SYSTEM BY LINUS T.  \n");
    printf("=====================================\n\n");

    while (1) {
        printf("Choose an option:\n");
        printf("1. Add a movie\n");
        printf("2. Display all movies\n");
        printf("3. Search for a movie\n");
        printf("4. Quit\n");

        // Get user choice
        while (!isValidChoice) {
            printf("Enter your choice: ");
            scanf("%s", &choice);

            if (choice < '1' || choice > '4') {
                printf("Invalid choice, please try again\n");
            } else {
                isValidChoice = 1;
            }
        }
        isValidChoice = 0;

        switch (choice) {
            case '1':
                addMovie();
                break;
            case '2':
                displayMovies();
                break;
            case '3':
                searchMovie();
                break;
            case '4':
                printf("Goodbye!\n");
                return 0;
        }
        printf("\n");
    }
}