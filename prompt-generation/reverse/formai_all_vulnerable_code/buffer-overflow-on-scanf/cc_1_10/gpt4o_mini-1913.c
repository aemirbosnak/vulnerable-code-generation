//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    int rating; // Rating from 1 to 10
} Movie;

void displayMenu() {
    printf("\n--- Movie Rating System ---\n");
    printf("1. Add Movie\n");
    printf("2. Rate Movie\n");
    printf("3. Display Movies\n");
    printf("4. Exit\n");
    printf("Please choose an option: ");
}

void addMovie(Movie movies[], int *count) {
    if (*count >= MAX_MOVIES) {
        printf("Cannot add more movies! Max limit reached.\n");
        return;
    }

    printf("Enter movie title: ");
    fgets(movies[*count].title, MAX_TITLE_LENGTH, stdin);
    movies[*count].title[strcspn(movies[*count].title, "\n")] = 0; // Remove newline
    movies[*count].rating = 0; // Initialize rating to 0 for new movies
    (*count)++;
    printf("Movie '%s' added successfully!\n", movies[*count - 1].title);
}

void rateMovie(Movie movies[], int count) {
    if (count == 0) {
        printf("No movies available to rate!\n");
        return;
    }

    printf("Select a movie to rate (1 to %d):\n", count);
    for (int i = 0; i < count; i++) {
        printf("%d. %s (Current Rating: %d)\n", i + 1, movies[i].title, movies[i].rating);
    }

    int choice;
    printf("Enter the movie number to rate: ");
    scanf("%d", &choice);
    getchar(); // Clear newline from input buffer

    if (choice < 1 || choice > count) {
        printf("Invalid choice, please try again!\n");
        return;
    }

    int newRating;
    printf("Enter a new rating for '%s' (1 to 10): ", movies[choice - 1].title);
    scanf("%d", &newRating);
    getchar(); // Clear newline from input buffer

    if (newRating < 1 || newRating > 10) {
        printf("Invalid rating! Please rate between 1 and 10.\n");
    } else {
        movies[choice - 1].rating = newRating;
        printf("Rating updated for '%s' to %d!\n", movies[choice - 1].title, newRating);
    }
}

void displayMovies(Movie movies[], int count) {
    if (count == 0) {
        printf("No movies stored.\n");
        return;
    }

    printf("\n--- Movies and Ratings ---\n");
    for (int i=0; i < count; i++) {
        printf("Title: %s | Rating: %d\n", movies[i].title, movies[i].rating);
    }
}

int main() {
    Movie movies[MAX_MOVIES];
    int count = 0;
    int option;

    while (1) {
        displayMenu();
        scanf("%d", &option);
        getchar(); // Clear newline from input buffer

        switch (option) {
            case 1:
                addMovie(movies, &count);
                break;
            case 2:
                rateMovie(movies, count);
                break;
            case 3:
                displayMovies(movies, count);
                break;
            case 4:
                printf("Exiting the Movie Rating System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please select again.\n");
        }
    }

    return 0;
}