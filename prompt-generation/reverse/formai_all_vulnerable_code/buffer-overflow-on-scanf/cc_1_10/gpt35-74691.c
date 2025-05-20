//FormAI DATASET v1.0 Category: Movie Rating System ; Style: multiplayer
#include <stdio.h>
#include <stdbool.h>

// Define Movie struct
typedef struct {
    char title[50];
    int rating;
} Movie;

// Define function to create new movie
Movie createMovie(char title[50], int rating) {
    Movie newMovie;
    strcpy(newMovie.title, title);
    newMovie.rating = rating;
    return newMovie;
}

// Define function to update movie rating
void updateRating(Movie *movie, int newRating) {
    movie->rating = newRating;
}

// Define function to display movie info
void displayMovie(Movie movie) {
    printf("Title: %s\n", movie.title);
    printf("Rating: %d\n", movie.rating);
}

// Main function
int main() {
    // Define array of 10 movies
    Movie movieList[10];
    int numMovies = 0;

    // Start multiplayer rating system
    bool continueRating = true;
    while (continueRating) {
        // Display menu options
        printf("\nWhat would you like to do?\n");
        printf("1. Add a new movie\n");
        printf("2. View a movie's info\n");
        printf("3. Update a movie's rating\n");
        printf("4. Exit the program\n");
        printf("Enter an option number: ");

        // Get user input
        int choice;
        scanf("%d", &choice);

        // Determine action based on user input
        switch(choice) {
            case 1:
                // Add a new movie
                printf("\nEnter the movie title: ");
                char title[50];
                scanf("%s", title);

                printf("Enter the movie rating (out of 10): ");
                int rating;
                scanf("%d", &rating);

                Movie newMovie = createMovie(title, rating);
                movieList[numMovies] = newMovie;
                numMovies++;

                printf("\n*** Movie added! ***\n");
                break;
            case 2:
                // View a movie's info
                printf("\nEnter the index (starting at 0) of the movie you would like to view: ");
                int index;
                scanf("%d", &index);

                if (index >= 0 && index < numMovies) {
                    displayMovie(movieList[index]);
                } else {
                    printf("\n*** Invalid index! ***\n");
                }
                break;
            case 3:
                // Update a movie's rating
                printf("\nEnter the index (starting at 0) of the movie you would like to update: ");
                int indexToUpdate;
                scanf("%d", &indexToUpdate);

                if (indexToUpdate >= 0 && indexToUpdate < numMovies) {
                    printf("Enter the new rating (out of 10) for the movie: ");
                    int newRating;
                    scanf("%d", &newRating);

                    updateRating(&(movieList[indexToUpdate]), newRating);
                    printf("\n*** Movie rating updated! ***\n");
                } else {
                    printf("\n*** Invalid index! ***\n");
                }
                break;
            case 4:
                // Exit the program
                continueRating = false;
                break;
            default:
                printf("\n*** Invalid option! ***\n");
                break;
        }
    }

    return 0;
}