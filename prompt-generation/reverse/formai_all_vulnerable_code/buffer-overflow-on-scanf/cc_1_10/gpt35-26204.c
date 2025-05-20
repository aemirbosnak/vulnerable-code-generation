//FormAI DATASET v1.0 Category: Movie Rating System ; Style: intelligent
#include <stdio.h>

/**
 * This program is a movie rating system that allows users to rate movies.
 * The program keeps track of the title, genre, and rating for each movie.
 * Users can add new movies, rate existing movies, and view all movies and their ratings.
 */

// Struct to store information about a movie
typedef struct {
    char title[50];
    char genre[20];
    int rating;
} Movie;

// Function to add a new movie
void add_movie(Movie movies[], int *num_movies) {
    // Get input from user
    printf("Enter movie title: ");
    scanf("%s", movies[*num_movies].title);
    printf("Enter movie genre: ");
    scanf("%s", movies[*num_movies].genre);
    printf("Enter movie rating (0-10): ");
    scanf("%d", &movies[*num_movies].rating);
    
    // Increment num_movies
    (*num_movies)++;
    
    // Print success message
    printf("Movie added successfully!\n");
}

// Function to rate an existing movie
void rate_movie(Movie movies[], int num_movies) {
    // Get input from user
    char title[50];
    int new_rating;
    printf("Enter movie title: ");
    scanf("%s", title);
    printf("Enter new rating (0-10): ");
    scanf("%d", &new_rating);
    
    // Find movie with matching title and update rating
    int found = 0;
    for (int i = 0; i < num_movies; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            movies[i].rating = new_rating;
            found = 1;
            break;
        }
    }
    
    // Print success or error message
    if (found) {
        printf("Rating updated successfully!\n");
    } else {
        printf("Movie not found.\n");
    }
}

// Function to display all movies and their ratings
void display_movies(Movie movies[], int num_movies) {
    // Check if there are any movies
    if (num_movies == 0) {
        printf("No movies found.\n");
        return;
    }
    
    // Print header
    printf("%-50s %-20s %-10s\n", "Title", "Genre", "Rating");
    
    // Print each movie
    for (int i = 0; i < num_movies; i++) {
        printf("%-50s %-20s %-10d\n", movies[i].title, movies[i].genre, movies[i].rating);
    }
}

int main() {
    // Initialize variables
    Movie movies[50];
    int num_movies = 0;
    int choice;
    
    // Display menu and get user input
    printf("Welcome to the Movie Rating System!\n");
    while (1) {
        printf("\nMenu:\n1. Add new movie\n2. Rate movie\n3. Display all movies\n4. Quit\nEnter choice: ");
        scanf("%d", &choice);
        
        // Call appropriate function based on user choice
        switch (choice) {
            case 1:
                add_movie(movies, &num_movies);
                break;
            case 2:
                rate_movie(movies, num_movies);
                break;
            case 3:
                display_movies(movies, num_movies);
                break;
            case 4:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
}