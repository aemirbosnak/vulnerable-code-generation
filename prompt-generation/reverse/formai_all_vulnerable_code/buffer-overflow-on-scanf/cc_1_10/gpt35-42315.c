//FormAI DATASET v1.0 Category: Movie Rating System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Movie struct to store movie information
typedef struct {
    char title[50];
    char director[50];
    int year;
    float rating;
} Movie;

// Function to rate a movie
void rateMovie(Movie* movie) {
    printf("\nHow would you rate '%s' out of 10?\n", movie->title);
    float rating;
    scanf("%f", &rating);
    if (rating < 0 || rating > 10) {
        printf("Invalid rating, please try again.\n");
        rateMovie(movie);
    } else {
        movie->rating = rating;
        printf("Thank you for rating '%s'!\n", movie->title);
    }
}

int main() {
    printf("Welcome to C Movie Rating System!\n");

    // Hardcoding 3 movies for demonstration
    Movie movies[3] = {
        {"The Shawshank Redemption", "Frank Darabont", 1994, 0},
        {"The Godfather", "Francis Ford Coppola", 1972, 0},
        {"The Dark Knight", "Christopher Nolan", 2008, 0}
    };

    // Displaying movie list to the user
    printf("Here are the available movies:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d. %s (%d) directed by %s\n", i+1, movies[i].title, movies[i].year, movies[i].director);
    }

    // Prompting user to select a movie to rate
    int choice;
    printf("\nWhich movie would you like to rate? Enter the movie number: ");
    scanf("%d", &choice);
    if (choice < 1 || choice > 3) {
        printf("Invalid choice, please try again.\n");
        main();
    } else {
        Movie* selectedMovie = &movies[choice-1];
        rateMovie(selectedMovie);
    }

    // Displaying final movie list with ratings
    printf("\nHere is the updated list of movies with ratings:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d. %s (%d) directed by %s, rated %.1f/10\n", i+1, movies[i].title, movies[i].year, movies[i].director, movies[i].rating);
    }

    return 0;
}