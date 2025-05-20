//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for maximum values
#define MAX_MOVIES 100
#define TITLE_LENGTH 100

// Function prototypes
void addMovie(char movies[MAX_MOVIES][TITLE_LENGTH], int ratings[MAX_MOVIES], int *movieCount);
void displayMovies(char movies[MAX_MOVIES][TITLE_LENGTH], int ratings[MAX_MOVIES], int movieCount);
float calculateAverageRating(int ratings[MAX_MOVIES], int movieCount);
void filterHighRatings(char movies[MAX_MOVIES][TITLE_LENGTH], int ratings[MAX_MOVIES], int movieCount, int threshold);
void printInstructions();

// Main function
int main() {
    char movies[MAX_MOVIES][TITLE_LENGTH];
    int ratings[MAX_MOVIES];
    int movieCount = 0;
    int choice;

    printInstructions();

    do {
        printf("\nChoose an option (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(movies, ratings, &movieCount);
                break;
            case 2:
                displayMovies(movies, ratings, movieCount);
                break;
            case 3:
                {
                    float average = calculateAverageRating(ratings, movieCount);
                    printf("Average Movie Rating: %.2f\n", average);
                }
                break;
            case 4:
                {
                    int threshold;
                    printf("Enter rating threshold: ");
                    scanf("%d", &threshold);
                    filterHighRatings(movies, ratings, movieCount, threshold);
                }
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to add a movie and its rating
void addMovie(char movies[MAX_MOVIES][TITLE_LENGTH], int ratings[MAX_MOVIES], int *movieCount) {
    if (*movieCount >= MAX_MOVIES) {
        printf("Movie limit reached! Cannot add more movies.\n");
        return;
    }

    printf("Enter the movie title: ");
    scanf(" %[^\n]", movies[*movieCount]); // Read string with spaces

    printf("Enter your rating (0-10): ");
    scanf("%d", &ratings[*movieCount]);

    if (ratings[*movieCount] < 0 || ratings[*movieCount] > 10) {
        printf("Invalid rating! Please enter a rating between 0 and 10.\n");
        return;
    }

    (*movieCount)++;
    printf("Movie added successfully!\n");
}

// Function to display all movies and their ratings
void displayMovies(char movies[MAX_MOVIES][TITLE_LENGTH], int ratings[MAX_MOVIES], int movieCount) {
    if (movieCount == 0) {
        printf("No movies to display.\n");
        return;
    }

    printf("\nList of Movies and Ratings:\n");
    for (int i = 0; i < movieCount; i++) {
        printf("%d. %s - Rating: %d\n", i + 1, movies[i], ratings[i]);
    }
}

// Function to calculate and return average rating
float calculateAverageRating(int ratings[MAX_MOVIES], int movieCount) {
    if (movieCount == 0) return 0.0;

    int total = 0;
    for (int i = 0; i < movieCount; i++) {
        total += ratings[i];
    }
    return (float)total / movieCount;
}

// Function to filter and display movies above a certain rating
void filterHighRatings(char movies[MAX_MOVIES][TITLE_LENGTH], int ratings[MAX_MOVIES], int movieCount, int threshold) {
    printf("\nMovies with ratings above %d:\n", threshold);
    for (int i = 0; i < movieCount; i++) {
        if (ratings[i] > threshold) {
            printf("%s - Rating: %d\n", movies[i], ratings[i]);
        }
    }
}

// Function to print available actions
void printInstructions() {
    printf("Movie Rating System\n");
    printf("1. Add a Movie\n");
    printf("2. Display Movies\n");
    printf("3. Calculate Average Rating\n");
    printf("4. Filter Movies by Ratings\n");
    printf("5. Exit\n");
}