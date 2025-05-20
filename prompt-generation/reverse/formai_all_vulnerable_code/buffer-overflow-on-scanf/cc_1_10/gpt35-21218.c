//FormAI DATASET v1.0 Category: Movie Rating System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

// Define the struct for storing movie data
typedef struct {
    char title[50];
    char genre[20];
    int year;
    float rating;
} Movie;

// Define a function to add a new movie to the system
void addMovie(Movie movies[], int *numMovies) {
    // Check if the maximum number of movies has been reached
    if (*numMovies >= 50) {
        printf("Cannot add new movie, maximum number of movies reached!\n");
        return;
    }
    // Ask user for movie data
    Movie newMovie;
    printf("Enter movie title: ");
    fgets(newMovie.title, 50, stdin);
    printf("Enter movie genre: ");
    fgets(newMovie.genre, 20, stdin);
    printf("Enter movie year: ");
    scanf("%d", &newMovie.year);
    printf("Enter movie rating (out of 10): ");
    scanf("%f", &newMovie.rating);
    // Add the movie to the array
    movies[*numMovies] = newMovie;
    // Increment the number of movies
    (*numMovies)++;
}

// Define a function to display the movie data
void displayMovies(Movie movies[], int numMovies) {
    // Check if there are no movies in the system
    if (numMovies == 0) {
        printf("No movies in the system!\n");
        return;
    }
    // Display the header row
    printf("%-50s %-20s %-10s %-10s\n", "Title", "Genre", "Year", "Rating");
    // Loop through movies array and display movie data
    for (int i = 0; i < numMovies; i++) {
        printf("%-50s %-20s %-10d %-10.1f\n", movies[i].title, movies[i].genre, movies[i].year, movies[i].rating);
    }
}

// Define the main function
int main() {
    // Declare variables and arrays
    int choice, numMovies = 0;
    Movie movies[50];
    // Loop through menu options until user chooses to exit
    while (1) {
        printf("\n***** C Movie Rating System *****\n");
        printf("1. Add a movie\n");
        printf("2. Display all movies\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addMovie(movies, &numMovies);
                break;
            case 2:
                displayMovies(movies, numMovies);
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}