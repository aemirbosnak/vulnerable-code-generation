//FormAI DATASET v1.0 Category: Movie Rating System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for movie
struct movie {
    char title[50];
    char genre[20];
    float rating;
};

// Function to display the movie details
void displayMovieDetails(struct movie m) {
    printf("\nMovie Title: %s\n", m.title);
    printf("Genre: %s\n", m.genre);
    printf("Movie Rating: %.1f\n", m.rating);
}

// Function to get user input for movie details
struct movie getMovieDetails() {
    struct movie m;
    printf("Enter the movie title: ");
    scanf("%[^\n]%*c", m.title);
    printf("Enter the movie genre: ");
    scanf("%[^\n]%*c", m.genre);
    printf("Enter the movie rating (out of 10): ");
    scanf("%f", &m.rating);
    return m;
}

int main() {
    //define an array of movies
    struct movie movies[50];
    int numMovies = 0;
    char choice = 'y';

    //Loop to get user input for movie ratings
    while (choice == 'y') {
        printf("\nEnter details for movie %d: \n", numMovies+1);
        movies[numMovies] = getMovieDetails();
        numMovies++;
        printf("\nDo you want to add another movie? (y/n): ");
        scanf(" %c", &choice);
    }

    //Display all movie information
    printf("\nHere are all of the movie details:\n");
    for (int i = 0; i < numMovies; i++) {
        displayMovieDetails(movies[i]);
    }

    //Calculate and display the average movie rating
    float totalRating = 0;
    for (int i = 0; i < numMovies; i++) {
        totalRating += movies[i].rating;
    }
    float averageRating = totalRating / numMovies;
    printf("\nAverage movie rating: %.1f\n", averageRating);

    //Display the movies with a rating above the average
    printf("\nHere are the movies with a rating above the average:\n");
    for (int i = 0; i < numMovies; i++) {
        if (movies[i].rating > averageRating) {
            displayMovieDetails(movies[i]);
        }
    }

    return 0;
}