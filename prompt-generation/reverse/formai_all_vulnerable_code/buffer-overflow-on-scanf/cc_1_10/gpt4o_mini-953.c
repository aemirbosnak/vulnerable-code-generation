//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 100

// Structure to hold movie details
typedef struct {
    char title[MAX_TITLE_LENGTH];
    int rating; // Rating from 1 to 10
} Movie;

// Function to display the menu
void displayMenu() {
    printf("\n*** Shocked Movie Rating System ***\n");
    printf("1. Add Movie\n");
    printf("2. View All Movies\n");
    printf("3. Rate a Movie\n");
    printf("4. Exit\n");
    printf("************************************\n");
    printf("Choose an option: ");
}

// Function to add a movie
void addMovie(Movie *movies, int *count) {
    if (*count >= MAX_MOVIES) {
        printf("Oh no! We've reached the maximum number of movies!\n");
        return;
    }

    printf("Enter movie title: ");
    fgets(movies[*count].title, MAX_TITLE_LENGTH, stdin);
    strtok(movies[*count].title, "\n"); // Remove the trailing newline
    movies[*count].rating = 0; // Initialize rating to 0

    (*count)++;
    printf("Wow! Movie '%s' added successfully!\n", movies[*count - 1].title);
}

// Function to view all movies
void viewMovies(Movie *movies, int count) {
    if (count == 0) {
        printf("Yikes! No movies to display. Please add movies first.\n");
        return;
    }

    printf("\n*** List of Movies ***\n");
    for (int i = 0; i < count; i++) {
        printf("Movie %d: %s, Rating: %d\n", i + 1, movies[i].title, movies[i].rating);
    }
    printf("************************\n");
}

// Function to rate a movie
void rateMovie(Movie *movies, int count) {
    if (count == 0) {
        printf("What a disaster! No movies available to rate. Please add movies first.\n");
        return;
    }

    int choice;
    printf("Enter the number of the movie to rate (1-%d): ", count);
    scanf("%d", &choice);
    getchar(); // Consume the trailing newline

    if (choice < 1 || choice > count) {
        printf("Oops! You've chosen an invalid movie number. Try again!\n");
        return;
    }

    int rating;
    printf("Rate '%s' (1-10): ", movies[choice - 1].title);
    scanf("%d", &rating);
    getchar(); // Consume the trailing newline

    if (rating < 1 || rating > 10) {
        printf("Whoa! Invalid rating. Please use a rating between 1 and 10.\n");
        return;
    }

    movies[choice - 1].rating = rating;
    printf("Wow! You rated '%s' with a score of %d!\n", movies[choice - 1].title, movies[choice - 1].rating);
}

int main() {
    printf("Welcome to the Shocked Movie Rating System!\n");
    Movie movies[MAX_MOVIES];
    int movieCount = 0;
    int option;

    do {
        displayMenu();
        scanf("%d", &option);
        getchar(); // Consume the trailing newline

        switch (option) {
            case 1:
                addMovie(movies, &movieCount);
                break;
            case 2:
                viewMovies(movies, movieCount);
                break;
            case 3:
                rateMovie(movies, movieCount);
                break;
            case 4:
                printf("Exiting... Please come again for more shocked movie ratings!\n");
                break;
            default:
                printf("Unexpected input! Please try again!\n");
                break;
        }
    } while (option != 4);

    return 0;
}