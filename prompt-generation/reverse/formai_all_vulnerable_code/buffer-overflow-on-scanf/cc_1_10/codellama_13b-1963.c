//Code Llama-13B DATASET v1.0 Category: Movie Rating System ; Style: shocked
/*
 * Unique C Movie Rating System
 *
 * This program allows users to rate movies from 1 to 5 stars.
 * The program also allows users to add and remove movies from the database.
 *
 * Author: [Your Name]
 * Date: [Current Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a movie
typedef struct {
    char title[50];
    int rating;
} Movie;

// Function to add a movie to the database
void addMovie(Movie *movies, int *numMovies) {
    // Get the title and rating of the movie from the user
    printf("Enter the title of the movie: ");
    scanf("%s", movies[*numMovies].title);
    printf("Enter the rating of the movie (1-5): ");
    scanf("%d", &movies[*numMovies].rating);

    // Increment the number of movies in the database
    (*numMovies)++;
}

// Function to remove a movie from the database
void removeMovie(Movie *movies, int *numMovies) {
    // Get the index of the movie to remove from the user
    int index;
    printf("Enter the index of the movie to remove: ");
    scanf("%d", &index);

    // Check if the index is valid
    if (index < 0 || index >= *numMovies) {
        printf("Invalid index.\n");
        return;
    }

    // Remove the movie from the database
    for (int i = index; i < *numMovies - 1; i++) {
        movies[i] = movies[i + 1];
    }

    // Decrement the number of movies in the database
    (*numMovies)--;
}

// Function to display the movies in the database
void displayMovies(Movie *movies, int numMovies) {
    printf("Movies in the database:\n");
    for (int i = 0; i < numMovies; i++) {
        printf("%d. %s (%d stars)\n", i + 1, movies[i].title, movies[i].rating);
    }
}

int main() {
    // Initialize the database with 0 movies
    Movie movies[100];
    int numMovies = 0;

    // Loop until the user exits the program
    char choice;
    do {
        // Display the menu
        printf("Menu:\n");
        printf("a) Add a movie\n");
        printf("r) Remove a movie\n");
        printf("d) Display the movies\n");
        printf("q) Quit\n");
        scanf(" %c", &choice);

        // Handle the user's choice
        switch (choice) {
            case 'a':
                addMovie(movies, &numMovies);
                break;
            case 'r':
                removeMovie(movies, &numMovies);
                break;
            case 'd':
                displayMovies(movies, numMovies);
                break;
            case 'q':
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 'q');

    return 0;
}