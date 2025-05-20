//FormAI DATASET v1.0 Category: Movie Rating System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Configurable settings
#define MAX_MOVIES 100
#define MIN_RATING 1
#define MAX_RATING 5

// Struct to store movie details
typedef struct {
    char title[50];
    char director[50];
    int year;
    float rating;
} Movie;

// Function to add a new movie
void addMovie(Movie movies[], int *numMovies) {
    if (*numMovies >= MAX_MOVIES) {
        printf("Maximum limit of %d movies reached.\n", MAX_MOVIES);
        return;
    }

    Movie movie;
    printf("Enter movie title: ");
    scanf("%s", &movie.title);
    printf("Enter movie director: ");
    scanf("%s", &movie.director);
    printf("Enter movie release year: ");
    scanf("%d", &movie.year);
    printf("Enter movie rating (1-5): ");
    scanf("%f", &movie.rating);

    // Validate rating
    if (movie.rating < MIN_RATING || movie.rating > MAX_RATING) {
        printf("Invalid rating value. Rating should be between 1 and 5.\n");
        return;
    }

    movies[*numMovies] = movie;
    *numMovies += 1;
    printf("Movie added successfully!\n");
}

// Function to display all movies
void displayMovies(Movie movies[], int numMovies) {
    printf("Title\t\tDirector\tYear\tRating\n");
    for (int i = 0; i < numMovies; i++) {
        printf("%s\t%s\t%d\t%.1f\n", movies[i].title, movies[i].director, movies[i].year, movies[i].rating);
    }
}

// Function to get average rating of all movies
float getAverageRating(Movie movies[], int numMovies) {
    float total = 0.0;
    for (int i = 0; i < numMovies; i++) {
        total += movies[i].rating;
    }
    return total / numMovies;
}

// Main function
int main() {
    Movie movies[MAX_MOVIES];
    int numMovies = 0;
    int choice;

    while (1) {
        printf("\n-------Movie Rating System-------\n");
        printf("1. Add new movie\n");
        printf("2. Display all movies\n");
        printf("3. Get average rating of all movies\n");
        printf("4. Exit\n");
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
                printf("Average rating of all movies: %.1f\n", getAverageRating(movies, numMovies));
                break;
            case 4:
                printf("Thank you for using the Movie Rating System!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}