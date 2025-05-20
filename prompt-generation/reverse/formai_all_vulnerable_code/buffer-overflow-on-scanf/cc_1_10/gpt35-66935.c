//FormAI DATASET v1.0 Category: Movie Rating System ; Style: beginner-friendly
#include <stdio.h>

// Movie Rating Struct
typedef struct {
    char title[50];
    int releaseYear;
    float rating;
} Movie;

// Function to get user input for a movie 
void getMovieInput(Movie *movie) {
    printf("Enter the movie title: ");
    scanf("%[^\n]", movie->title); // read input until newline character is encountered
    printf("Enter the release year: ");
    scanf("%d", &movie->releaseYear);
    printf("Enter the rating (out of 10): ");
    scanf("%f", &movie->rating);
    // clear buffer
    while(getchar() != '\n');
}

// Function to display a movie's details
void displayMovieDetails(Movie movie) {
    printf("\nTitle: %s\n", movie.title);
    printf("Release Year: %d\n", movie.releaseYear);
    printf("Rating: %.1f/10\n", movie.rating);
}

// Function to rate a movie
void rateMovie(Movie *movie) {
    float newRating;
    printf("Enter a new rating (out of 10): ");
    scanf("%f", &newRating);
    // calculate new rating based on the average of old and new rating
    movie->rating = (movie->rating + newRating) / 2.0;
    printf("Updated rating for %s: %.1f/10\n", movie->title, movie->rating);
}

int main() {
    Movie movies[10];
    int numMovies = 0;
    int choice;
    do {
        // Display menu options
        printf("\nSelect an option:\n");
        printf("1. Add a new movie\n");
        printf("2. View movie details\n");
        printf("3. Rate a movie\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        // clear buffer
        while(getchar() != '\n');

        switch(choice) {
            // Add a new movie to the system
            case 1:
                if(numMovies >= 10) {
                    printf("\nMaximum number of movies reached!\n");
                    break;
                }
                Movie newMovie;
                getMovieInput(&newMovie);
                movies[numMovies] = newMovie;
                numMovies++;
                printf("\nNew movie added to the system!\n");
                break;
            // View details of an existing movie
            case 2:
                if(numMovies == 0) {
                    printf("\nNo movies in the system yet!\n");
                    break;
                }
                int movieIndex;
                printf("Enter the index of the movie (0-%d): ", numMovies-1);
                scanf("%d", &movieIndex);
                // clear buffer
                while(getchar() != '\n');
                if(movieIndex < 0 || movieIndex >= numMovies) {
                    printf("\nInvalid movie index!\n");
                    break;
                }
                displayMovieDetails(movies[movieIndex]);
                break;
            // Rate an existing movie
            case 3:
                if(numMovies == 0) {
                    printf("\nNo movies in the system yet!\n");
                    break;
                }
                int movieIndex2;
                printf("Enter the index of the movie (0-%d): ", numMovies-1);
                scanf("%d", &movieIndex2);
                // clear buffer
                while(getchar() != '\n');
                if(movieIndex2 < 0 || movieIndex2 >= numMovies) {
                    printf("\nInvalid movie index!\n");
                    break;
                }
                rateMovie(&movies[movieIndex2]);
                break;
            // Exit the program
            case 4:
                printf("\nExiting the program...\n");
                break;
            // Invalid choice
            default:
                printf("\nInvalid choice!\n");
        }
    } while(choice != 4);

    return 0;
}