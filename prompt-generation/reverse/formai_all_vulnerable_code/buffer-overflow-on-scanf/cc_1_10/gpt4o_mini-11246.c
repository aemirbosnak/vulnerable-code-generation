//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 100

// Struct to store movie information
typedef struct {
    char title[MAX_TITLE_LENGTH];
    float rating;
} Movie;

// Function prototypes
void addMovie(Movie movies[], int *numMovies);
void viewMovies(Movie movies[], int numMovies);
void calculateAverageRating(Movie movies[], int numMovies);
void displayMenu();
void clearScreen();

int main() {
    Movie movies[MAX_MOVIES];
    int numMovies = 0;
    int choice;

    printf("🎬 Welcome to the Movie Rating System! 🎬\n\n");

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(movies, &numMovies);
                break;
            case 2:
                viewMovies(movies, numMovies);
                break;
            case 3:
                calculateAverageRating(movies, numMovies);
                break;
            case 4:
                printf("🌟 Thank you for using the Movie Rating System! 🌟\n");
                break;
            default:
                printf("🚨 Invalid choice, please try again! 🚨\n");
                break;
        }
        printf("\n");
    } while (choice != 4);

    return 0;
}

void displayMenu() {
    clearScreen();
    printf("🌟 Movie Rating System Menu 🌟\n");
    printf("1. Add a Movie\n");
    printf("2. View Movies\n");
    printf("3. Calculate Average Rating\n");
    printf("4. Exit\n");
}

void clearScreen() {
    // Clear the console screen for better visibility
    printf("\e[1;1H\e[2J");
}

void addMovie(Movie movies[], int *numMovies) {
    if (*numMovies >= MAX_MOVIES) {
        printf("🚫 Movie list is full! Cannot add more! 🚫\n");
        return;
    }

    Movie newMovie;
    printf("Enter the title of the movie: ");
    getchar(); // Clear the newline character from input buffer
    fgets(newMovie.title, MAX_TITLE_LENGTH, stdin);
    newMovie.title[strcspn(newMovie.title, "\n")] = 0; // Remove newline

    printf("Rate the movie (0.0 - 5.0): ");
    scanf("%f", &newMovie.rating);

    if (newMovie.rating < 0.0 || newMovie.rating > 5.0) {
        printf("🚨 Invalid rating! Please enter a rating between 0.0 and 5.0. 🚨\n");
        return;
    }

    movies[*numMovies] = newMovie;
    (*numMovies)++;
    printf("🎉 Movie '%s' added with a rating of %.1f! 🎉\n", newMovie.title, newMovie.rating);
}

void viewMovies(Movie movies[], int numMovies) {
    if (numMovies == 0) {
        printf("🧐 No movies available to display! Please add some movies! 🧐\n");
        return;
    }

    printf("📽️ List of Movies 📽️\n");
    for (int i = 0; i < numMovies; i++) {
        printf("%d. '%s' - Rating: %.1f\n", i + 1, movies[i].title, movies[i].rating);
    }
}

void calculateAverageRating(Movie movies[], int numMovies) {
    if (numMovies == 0) {
        printf("🧐 No ratings available to calculate average! Please add some movies! 🧐\n");
        return;
    }

    float totalRating = 0;
    for (int i = 0; i < numMovies; i++) {
        totalRating += movies[i].rating;
    }

    float average = totalRating / numMovies;
    printf("🌈 The average rating of all movies is %.2f 🌈\n", average);
}