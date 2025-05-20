//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define TITLE_LENGTH 100

// Structure to hold movie information
typedef struct {
    char title[TITLE_LENGTH];
    float rating;
} Movie;

// Function prototypes
void inputMovies(Movie movies[], int *count);
void displayMovies(const Movie movies[], int count);
float calculateAverageRating(const Movie movies[], int count);
void sortMovies(Movie movies[], int count);
void displayHighestRated(const Movie movies[], int count);

// Main Function
int main() {
    Movie movies[MAX_MOVIES];
    int count = 0; // Number of movies entered by the user
    char choice;

    printf("Welcome to the Unique C Movie Rating System!\n");

    do {
        inputMovies(movies, &count);
        displayMovies(movies, count);
        printf("Average rating: %.2f\n", calculateAverageRating(movies, count));
        sortMovies(movies, count);
        displayHighestRated(movies, count);

        printf("\nDo you want to enter more movies? (y/n): ");
        scanf(" %c", &choice);
        
    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the Unique C Movie Rating System! Goodbye!\n");
    return 0;
}

// Function to input movie titles and ratings
void inputMovies(Movie movies[], int *count) {
    int i;
    printf("\nHow many movies do you want to enter (max %d)? ", MAX_MOVIES);
    scanf("%d", &i);
    if (i > MAX_MOVIES) {
        i = MAX_MOVIES;
        printf("Limiting to %d movies.\n", MAX_MOVIES);
    }
    
    for (int j = 0; j < i; j++) {
        printf("\nEnter the title of movie %d: ", j + 1);
        getchar(); // Clear the newline character from input buffer
        fgets(movies[*count].title, TITLE_LENGTH, stdin);
        movies[*count].title[strcspn(movies[*count].title, "\n")] = 0; // Remove newline
        printf("Enter the rating for '%s' (0.0 - 10.0): ", movies[*count].title);
        scanf("%f", &movies[*count].rating);
        (*count)++;
    }
}

// Function to display all movies and their ratings
void displayMovies(const Movie movies[], int count) {
    printf("\nMovies Entered:\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s, Rating: %.1f\n", movies[i].title, movies[i].rating);
    }
}

// Function to calculate the average rating
float calculateAverageRating(const Movie movies[], int count) {
    float total = 0.0;
    for (int i = 0; i < count; i++) {
        total += movies[i].rating;
    }
    return count > 0 ? total / count : 0.0;
}

// Function to sort movies by rating (bubble sort)
void sortMovies(Movie movies[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (movies[j].rating < movies[j + 1].rating) {
                // Swap
                Movie temp = movies[j];
                movies[j] = movies[j + 1];
                movies[j + 1] = temp;
            }
        }
    }
}

// Function to display the highest rated movie
void displayHighestRated(const Movie movies[], int count) {
    if (count == 0) {
        printf("No movies to display.\n");
        return;
    }

    printf("\nHighest Rated Movie:\n");
    printf("Title: %s, Rating: %.1f\n", movies[0].title, movies[0].rating);
}