//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Donald Knuth
// C Movie Rating System
// By: Your Name

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of movies and their titles
#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 50

// Define a struct to hold movie data
struct movie {
    char title[MAX_TITLE_LENGTH];
    int rating;
};

// Declare functions
void addMovie(struct movie *movies, int *numMovies);
void printMovies(struct movie *movies, int numMovies);
void rateMovie(struct movie *movies, int numMovies, char *title);

int main() {
    struct movie movies[MAX_MOVIES]; // Array to hold movies
    int numMovies = 0; // Counter for number of movies

    // Display the menu and handle user input
    while (1) {
        printf("Welcome to the C Movie Rating System!\n");
        printf("1. Add a movie\n");
        printf("2. Print movies\n");
        printf("3. Rate a movie\n");
        printf("4. Exit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Add a movie
                addMovie(movies, &numMovies);
                break;

            case 2: // Print movies
                printMovies(movies, numMovies);
                break;

            case 3: // Rate a movie
                {
                    char title[MAX_TITLE_LENGTH];
                    printf("Enter the title of the movie: ");
                    scanf(" %[^\n]s", title);
                    rateMovie(movies, numMovies, title);
                }
                break;

            case 4: // Exit the program
                printf("Thanks for using the C Movie Rating System!\n");
                exit(0);

            default:
                printf("Invalid choice, please enter a number from 1 to 4.\n");
                break;
        }
    }

    return 0;
}

// Function to add a movie to the list
void addMovie(struct movie *movies, int *numMovies) {
    if (*numMovies >= MAX_MOVIES) {
        printf("Sorry, you have reached the maximum number of movies.\n");
        return;
    }

    char title[MAX_TITLE_LENGTH];
    printf("Enter the title of the movie: ");
    scanf(" %[^\n]s", title);

    int rating;
    printf("Enter your rating for %s (1-10): ", title);
    scanf("%d", &rating);

    // Create a new movie struct and add it to the array
    struct movie newMovie;
    strcpy(newMovie.title, title);
    newMovie.rating = rating;

    movies[*numMovies] = newMovie;
    (*numMovies)++;

    printf("Movie added successfully.\n");
}

// Function to print all movies in the list
void printMovies(struct movie *movies, int numMovies) {
    if (numMovies == 0) {
        printf("There are no movies to display.\n");
        return;
    }

    printf("Movie List:\n");
    for (int i = 0; i < numMovies; i++) {
        printf("%s (%d/10)\n", movies[i].title, movies[i].rating);
    }
}

// Function to rate a movie
void rateMovie(struct movie *movies, int numMovies, char *title) {
    for (int i = 0; i < numMovies; i++) {
        if (strcmp(movies[i].title, title) == 0) { // If the title is found
            int rating;
            printf("Enter your rating for %s (1-10): ", title);
            scanf("%d", &rating);
            movies[i].rating = rating;
            printf("Movie rating updated successfully.\n");
            return;
        }
    }

    printf("Sorry, the movie \"%s\" was not found.\n", title);
}