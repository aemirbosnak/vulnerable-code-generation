//FormAI DATASET v1.0 Category: Movie Rating System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 50

// Data structure to hold a movie
typedef struct {
    char title[MAX_TITLE_LENGTH];
    int year;
    float rating;
} movie_t;

// Function to compute the rating of a movie based on its year of release
float computeMovieRating(movie_t movie) {
    int age = 2021 - movie.year;
    float rating = 0.0;
    if(age <= 1) {
        rating = 5.0;
    } else if(age <= 5) {
        rating = 4.0;
    } else if(age <= 10) {
        rating = 3.0;
    } else {
        rating = 2.0;
    }
    rating += movie.rating;
    return rating;
}

// Function to display a movie's details
void displayMovie(movie_t movie) {
    printf("Title: %s\n", movie.title);
    printf("Year of release: %d\n", movie.year);
    printf("Rating: %.2f\n", movie.rating);
}

// Function to get user's rating input
float getRatingInput() {
    float rating = -1.0;
    while(rating < 0.0 || rating > 5.0) {
        printf("Enter rating (0.0 - 5.0): ");
        scanf("%f", &rating);
    }
    return rating;
}

// Function to add a new movie to the database
void addNewMovie(movie_t *movies, int *numMovies) {
    movie_t newMovie;
    printf("Enter movie title: ");
    scanf("%s", newMovie.title);
    printf("Enter year of release: ");
    scanf("%d", &newMovie.year);
    newMovie.rating = getRatingInput();
    movies[*numMovies] = newMovie;
    (*numMovies)++;
}

// Function to get a movie's index in the database
int getMovieIndex(movie_t *movies, int numMovies, char *title) {
    for(int i=0; i<numMovies; i++) {
        if(strcmp(movies[i].title, title) == 0) {
            return i;
        }
    }
    return -1;
}

// Main function to run the movie rating system
int main() {
    // Initialize variables
    movie_t movies[100];
    int numMovies = 0;
    int choice;

    // Display menu and get user's choice
    do {
        printf("\n~~~ Movie Rating System ~~~\n");
        printf("1. View all movies\n");
        printf("2. Add a new movie\n");
        printf("3. Update a movie's rating\n");
        printf("4. Delete a movie\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: // View all movies
                for(int i=0; i<numMovies; i++) {
                    printf("\nMovie %d:\n", i+1);
                    displayMovie(movies[i]);
                    printf("Computed rating: %.2f\n", computeMovieRating(movies[i]));
                }
                break;

            case 2: // Add a new movie
                addNewMovie(movies, &numMovies);
                break;

            case 3: // Update a movie's rating
                printf("Enter movie title: ");
                char title[MAX_TITLE_LENGTH];
                scanf("%s", title);
                int index = getMovieIndex(movies, numMovies, title);
                if(index == -1) {
                    printf("Movie not found.\n");
                } else {
                    printf("Enter new rating: ");
                    movies[index].rating = getRatingInput();
                }
                break;

            case 4: // Delete a movie
                printf("Enter movie title: ");
                char titleToDelete[MAX_TITLE_LENGTH];
                scanf("%s", titleToDelete);
                int indexToDelete = getMovieIndex(movies, numMovies, titleToDelete);
                if(indexToDelete == -1) {
                    printf("Movie not found.\n");
                } else {
                    for(int i=indexToDelete; i<numMovies-1; i++) {
                        movies[i] = movies[i+1];
                    }
                    numMovies--;
                    printf("Movie deleted.\n");
                }
                break;

            case 5: // Exit
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
                break;
        }

    } while(choice != 5);

    return 0;
}