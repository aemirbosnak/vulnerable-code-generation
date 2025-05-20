//FormAI DATASET v1.0 Category: Movie Rating System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Movie structure
typedef struct {
    char title[50];
    char director[50];
    int year;
    float rating;
} Movie;

// Function declarations
void addMovie(Movie *movies, int *count);
void deleteMovie(Movie *movies, int *count);
void rateMovie(Movie *movies, int count);
void viewMovies(Movie *movies, int count);

// Main function
int main() {
    int option, count = 0;
    Movie movies[50];

    do {
        // Display menu options
        printf("\nWelcome to Unique C Movie Rating System");
        printf("\n1. Add movie");
        printf("\n2. Delete movie");
        printf("\n3. Rate movie");
        printf("\n4. View movies");
        printf("\n5. Exit");
        printf("\nEnter option: ");
        scanf("%d", &option);

        switch(option) {
            case 1: 
                // Add movie
                addMovie(movies, &count);
                break;
            case 2:
                // Delete movie
                deleteMovie(movies, &count);
                break;
            case 3:
                // Rate movie
                rateMovie(movies, count);
                break;
            case 4:
                // View movies
                viewMovies(movies, count);
                break;
            case 5:
                // Exit program
                printf("\nThank you for using Unique C Movie Rating System!\n");
                break;
            default:
                printf("\nInvalid option, please try again.\n");
                break;
        }
    } while(option != 5);

    return 0;
}

// Function to add a movie
void addMovie(Movie *movies, int *count) {
    Movie newMovie;

    // Get user input for new movie
    printf("\nEnter movie title: ");
    scanf("%s", newMovie.title);
    printf("Enter movie director: ");
    scanf("%s", newMovie.director);
    printf("Enter year released: ");
    scanf("%d", &newMovie.year);

    // Add new movie to array of movies
    movies[*count] = newMovie;
    *count += 1;

    printf("\nMovie added successfully!\n");
}

// Function to delete a movie
void deleteMovie(Movie *movies, int *count) {
    int i, deleteIndex;
    char title[50];

    // Prompt user for movie title to delete
    printf("\nEnter title of movie to delete: ");
    scanf("%s", title);

    for(i = 0; i < *count; i++) {
        // Check if movie title matches user input
        if(strcmp(movies[i].title, title) == 0) {
            // Shift movie elements left and decrement count
            for(deleteIndex = i; deleteIndex < *count-1; deleteIndex++) {
                movies[deleteIndex] = movies[deleteIndex+1];
            }
            *count -= 1;
            printf("\nMovie deleted successfully!\n");
            return;
        }
    }
    printf("\nMovie not found.\n");
}

// Function to rate a movie
void rateMovie(Movie *movies, int count) {
    int i;
    char title[50];
    float rating;

    // Prompt user for movie title to rate
    printf("\nEnter title of movie to rate: ");
    scanf("%s", title);

    for(i = 0; i < count; i++) {
        // Check if movie title matches user input
        if(strcmp(movies[i].title, title) == 0) {
            // Get user input for rating
            printf("Enter rating (0.0 - 10.0): ");
            scanf("%f", &rating);

            // Update movie rating
            movies[i].rating = rating;

            printf("\nMovie rating updated successfully!\n");
            return;
        }
    }
    printf("\nMovie not found.\n");
}

// Function to display all movies
void viewMovies(Movie *movies, int count) {
    int i;

    if(count == 0) {
        printf("\nNo movies to display.\n");
    } else {
        printf("\n%-25s%-25s%-10s%-10s\n", "Title", "Director", "Year", "Rating");
        for(i = 0; i < count; i++) {
            printf("%-25s%-25s%-10d%-10.1f\n", movies[i].title, movies[i].director, movies[i].year, movies[i].rating);
        }
    }
}