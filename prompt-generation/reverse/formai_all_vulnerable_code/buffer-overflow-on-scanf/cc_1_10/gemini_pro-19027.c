//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Create a structure to represent a movie
typedef struct {
    char title[50];
    int year;
    char genre[20];
    float rating;
} Movie;

// Create a function to print a movie's details
void printMovie(Movie movie) {
    printf("Title: %s\n", movie.title);
    printf("Year: %d\n", movie.year);
    printf("Genre: %s\n", movie.genre);
    printf("Rating: %.1f\n\n", movie.rating);
}

// Create a function to sort an array of movies by rating
void sortMoviesByRating(Movie movies[], int numMovies) {
    for (int i = 0; i < numMovies - 1; i++) {
        for (int j = 0; j < numMovies - i - 1; j++) {
            if (movies[j].rating < movies[j + 1].rating) {
                Movie temp = movies[j];
                movies[j] = movies[j + 1];
                movies[j + 1] = temp;
            }
        }
    }
}

// Create a function to get a movie's rating from the user
float getMovieRating() {
    float rating;
    printf("Enter the movie's rating (0.0 to 5.0): ");
    scanf("%f", &rating);

    // Validate the rating
    while (rating < 0.0 || rating > 5.0) {
        printf("Invalid rating. Please enter a rating between 0.0 and 5.0: ");
        scanf("%f", &rating);
    }

    return rating;
}

// Create a function to add a new movie to the array
void addMovie(Movie movies[], int *numMovies) {
    // Get the movie's details from the user
    printf("Enter the movie's title: ");
    scanf(" %[^\n]s", movies[*numMovies].title);

    printf("Enter the movie's year: ");
    scanf("%d", &movies[*numMovies].year);

    printf("Enter the movie's genre: ");
    scanf(" %[^\n]s", movies[*numMovies].genre);

    movies[*numMovies].rating = getMovieRating();

    // Increment the number of movies
    (*numMovies)++;
}

// Create a function to print a menu of options for the user
void printMenu() {
    printf("1. Add a movie\n");
    printf("2. Print all movies\n");
    printf("3. Sort movies by rating\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

// Create a function to get a valid choice from the user
int getChoice() {
    int choice;
    scanf("%d", &choice);

    // Validate the choice
    while (choice < 1 || choice > 4) {
        printf("Invalid choice. Please enter a number between 1 and 4: ");
        scanf("%d", &choice);
    }

    return choice;
}

int main() {
    // Create an array of movies
    Movie movies[100];

    // Initialize the number of movies to 0
    int numMovies = 0;

    // Create a loop to allow the user to select options from a menu
    int choice;
    do {
        // Print the menu of options
        printMenu();

        // Get the user's choice
        choice = getChoice();

        // Perform the selected action
        switch (choice) {
            case 1:
                // Add a new movie to the array
                addMovie(movies, &numMovies);
                break;
            case 2:
                // Print all movies
                for (int i = 0; i < numMovies; i++) {
                    printMovie(movies[i]);
                }
                break;
            case 3:
                // Sort the movies by rating
                sortMoviesByRating(movies, numMovies);
                break;
            case 4:
                // Exit the program
                break;
        }
    } while (choice != 4);

    return 0;
}