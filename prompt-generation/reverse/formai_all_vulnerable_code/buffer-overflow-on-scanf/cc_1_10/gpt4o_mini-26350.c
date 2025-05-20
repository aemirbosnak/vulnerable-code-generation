//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for maximum inputs
#define MAX_MOVIES 100
#define MAX_TITLE 100
#define MAX_REVIEW 256

// Structure to hold movie details
typedef struct {
    char title[MAX_TITLE];
    float rating; // User rating out of 10
    char review[MAX_REVIEW];
} Movie;

// Function prototypes
void addMovie(Movie movies[], int *count);
void viewMovies(Movie movies[], int count);
void rateMovie(Movie movies[], int count);
void listMenu();

// Main function
int main() {
    Movie movies[MAX_MOVIES];
    int count = 0;
    int choice;

    do {
        listMenu();
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // Clear the newline after the number input

        switch (choice) {
            case 1:
                addMovie(movies, &count);
                break;
            case 2:
                viewMovies(movies, count);
                break;
            case 3:
                rateMovie(movies, count);
                break;
            case 4:
                printf("Exiting... Thank you for using the Movie Rating System!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
        printf("\n");
    } while (choice != 4);

    return 0;
}

// Function to display menu options
void listMenu() {
    printf("=== Movie Rating System ===\n");
    printf("1. Add Movie\n");
    printf("2. View Movies\n");
    printf("3. Rate Movie\n");
    printf("4. Exit\n");
}

// Function to add a movie
void addMovie(Movie movies[], int *count) {
    if (*count >= MAX_MOVIES) {
        printf("Movie list is full! Cannot add more movies.\n");
        return;
    }
    
    printf("Enter movie title: ");
    fgets(movies[*count].title, MAX_TITLE, stdin);
    movies[*count].title[strcspn(movies[*count].title, "\n")] = '\0'; // Remove newline

    printf("Enter review: ");
    fgets(movies[*count].review, MAX_REVIEW, stdin);
    movies[*count].review[strcspn(movies[*count].review, "\n")] = '\0'; // Remove newline

    movies[*count].rating = 0.0; // Initialize rating to zero
    (*count)++;
    printf("Movie added successfully!\n");
}

// Function to view all added movies
void viewMovies(Movie movies[], int count) {
    if (count == 0) {
        printf("No movies added yet!\n");
        return;
    }
    
    printf("=== List of Movies ===\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s\n", movies[i].title);
        printf("Review: %s\n", movies[i].review);
        printf("Rating: %.1f\n", movies[i].rating);
        printf("-------------------------\n");
    }
}

// Function to rate a movie
void rateMovie(Movie movies[], int count) {
    if (count == 0) {
        printf("No movies to rate! Please add a movie first.\n");
        return;
    }
    
    int index;
    printf("Enter the movie number (1-%d) to rate: ", count);
    scanf("%d", &index);
    getchar(); // Clear the newline

    if (index < 1 || index > count) {
        printf("Invalid movie number! Please try again.\n");
        return;
    }

    printf("Current Rating for '%s': %.1f\n", movies[index - 1].title, movies[index - 1].rating);
    printf("Enter new rating (0 to 10): ");
    float newRating;
    scanf("%f", &newRating);
    getchar(); // Clear the newline

    if (newRating < 0 || newRating > 10) {
        printf("Invalid rating! Rating must be between 0 and 10.\n");
        return;
    }

    movies[index - 1].rating = newRating;
    printf("Rating updated successfully for '%s'!\n", movies[index - 1].title);
}