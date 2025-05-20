//FormAI DATASET v1.0 Category: Movie Rating System ; Style: all-encompassing
#include <stdio.h>

// Function to display menu
void displayMenu() {
    printf("\n-------- C Movie Rating System --------\n");
    printf("1. Add a new movie\n");
    printf("2. View all movies\n");
    printf("3. Rate a movie\n");
    printf("4. View movie ratings\n");
    printf("5. Exit\n");
    printf("---------------------------------------\n");
}

// Structure to store movie info
struct Movie {
    char title[50];
    char genre[50];
    char rating[10];
};

// Global variables
const int MAX_MOVIES = 10;
int numMovies = 0;
struct Movie movies[10];

// Function to add a new movie
void addMovie() {
    if (numMovies == MAX_MOVIES) {
        printf("Sorry, the maximum number of movies has been reached.\n");
        return;
    }

    struct Movie movie;

    printf("\nEnter the movie title: ");
    scanf("%s", movie.title);

    printf("Enter the movie genre: ");
    scanf("%s", movie.genre);

    // Set initial rating to "Unrated"
    sprintf(movie.rating, "%s", "Unrated");

    // Add movie to array
    movies[numMovies++] = movie;

    printf("\nMovie '%s' added successfully!\n", movie.title);
}

// Function to display all movies
void viewMovies() {
    if (numMovies == 0) {
        printf("No movies added yet.\n");
        return;
    }

    printf("\n----- All Movies -----\n");

    for (int i = 0; i < numMovies; i++) {
        printf("Title: %s\n", movies[i].title);
        printf("Genre: %s\n", movies[i].genre);
        printf("Rating: %s\n", movies[i].rating);
        printf("-----------------------\n");
    }
}

// Function to rate a movie
void rateMovie() {
    if (numMovies == 0) {
        printf("No movies added yet.\n");
        return;
    }

    char movieTitle[50];
    printf("\nEnter the movie title: ");
    scanf("%s", movieTitle);

    // Find movie by title
    int movieIndex = -1;
    for (int i = 0; i < numMovies; i++) {
        if (strcmp(movies[i].title, movieTitle) == 0) {
            movieIndex = i;
            break;
        }
    }

    // If movie not found
    if (movieIndex == -1) {
        printf("Movie '%s' not found.\n", movieTitle);
        return;
    }

    int rating;
    printf("Enter the movie rating (1-5): ");
    scanf("%d", &rating);

    // Invalid rating
    if (rating < 1 || rating > 5) {
        printf("Invalid rating.\n");
        return;
    }

    // Update movie rating
    switch (rating) {
        case 1: sprintf(movies[movieIndex].rating, "%s", "Terrible"); break;
        case 2: sprintf(movies[movieIndex].rating, "%s", "Bad"); break;
        case 3: sprintf(movies[movieIndex].rating, "%s", "Average"); break;
        case 4: sprintf(movies[movieIndex].rating, "%s", "Good"); break;
        case 5: sprintf(movies[movieIndex].rating, "%s", "Excellent"); break;
    }

    printf("\nMovie '%s' rated successfully!\n", movieTitle);
}

// Function to view movie ratings
void viewRatings() {
    if (numMovies == 0) {
        printf("No movies added yet.\n");
        return;
    }

    printf("\n----- Movie Ratings -----\n");

    for (int i = 0; i < numMovies; i++) {
        printf("Title: %s\n", movies[i].title);
        printf("Genre: %s\n", movies[i].genre);
        printf("Rating: %s\n", movies[i].rating);
        printf("---------------------------\n");
    }
}

int main() {
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addMovie(); break;
            case 2: viewMovies(); break;
            case 3: rateMovie(); break;
            case 4: viewRatings(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }

    } while (choice != 5);

    return 0;
}