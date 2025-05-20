//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of movies
#define MAX_MOVIES 100

typedef struct {
    char title[100];
    char genre[100];
    int year;
    double rating;
} Movie;

int main() {
    // Initialize the number of movies to 0
    int numMovies = 0;

    // Initialize an array of movies
    Movie movies[MAX_MOVIES];

    // Loop until the user is done adding movies
    while (1) {
        // Display the current list of movies
        printf("Current list of movies:\n");
        for (int i = 0; i < numMovies; i++) {
            printf("%s (%s, %d) - %.1f/10\n", movies[i].title, movies[i].genre, movies[i].year, movies[i].rating);
        }

        // Ask the user if they want to add a movie
        char choice[100];
        printf("Do you want to add a movie? (y/n): ");
        scanf("%s", choice);

        // If the user does not want to add a movie, break out of the loop
        if (strcmp(choice, "n") == 0) {
            break;
        }

        // Get the movie information from the user
        printf("Enter the movie title: ");
        scanf("%s", movies[numMovies].title);

        printf("Enter the movie genre: ");
        scanf("%s", movies[numMovies].genre);

        printf("Enter the movie year: ");
        scanf("%d", &movies[numMovies].year);

        printf("Enter the movie rating (out of 10): ");
        scanf("%lf", &movies[numMovies].rating);

        // Increment the number of movies
        numMovies++;
    }

    // Sort the movies by rating in descending order
    for (int i = 0; i < numMovies - 1; i++) {
        for (int j = i + 1; j < numMovies; j++) {
            if (movies[i].rating < movies[j].rating) {
                Movie temp = movies[i];
                movies[i] = movies[j];
                movies[j] = temp;
            }
        }
    }

    // Print the final list of movies
    printf("\nFinal list of movies:\n");
    for (int i = 0; i < numMovies; i++) {
        printf("%s (%s, %d) - %.1f/10\n", movies[i].title, movies[i].genre, movies[i].year, movies[i].rating);
    }

    return 0;
}