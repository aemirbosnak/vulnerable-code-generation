//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define TITLE_LENGTH 50

typedef struct {
    char title[TITLE_LENGTH];
    float rating;
    int ratings_count;
} Movie;

Movie movies[MAX_MOVIES];
int movie_count = 0;

void clearScreen() {
    // Clear the terminal screen
    printf("\033[H\033[J");
}

void displayMenu() {
    printf("\n=== Movie Rating System ===\n");
    printf("1. Add Movie\n");
    printf("2. Rate Movie\n");
    printf("3. View Movies\n");
    printf("4. Exit\n");
    printf("===========================\n");
    printf("Select an option: ");
}

void addMovie() {
    if (movie_count >= MAX_MOVIES) {
        printf("Movie list is full!\n");
        return;
    }

    printf("Enter movie title: ");
    scanf(" %[^\n]", movies[movie_count].title);
    movies[movie_count].rating = 0.0;
    movies[movie_count].ratings_count = 0;
    movie_count++;
    printf("Movie '%s' added successfully!\n", movies[movie_count - 1].title);
}

void rateMovie() {
    char title[TITLE_LENGTH];
    printf("Enter movie title to rate: ");
    scanf(" %[^\n]", title);

    for (int i = 0; i < movie_count; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            float rating;
            printf("Enter your rating (0.0 - 5.0): ");
            scanf("%f", &rating);

            if (rating < 0.0 || rating > 5.0) {
                printf("Invalid rating! Please enter a rating between 0.0 and 5.0.\n");
                return;
            }

            movies[i].ratings_count++;
            movies[i].rating += (rating - movies[i].rating) / movies[i].ratings_count;
            printf("Thank you for rating '%s' with %.1f!\n", movies[i].title, movies[i].rating);
            return;
        }
    }

    printf("Movie '%s' not found!\n", title);
}

void viewMovies() {
    if (movie_count == 0) {
        printf("No movies available!\n");
        return;
    }

    printf("\n=== Movie List ===\n");
    for (int i = 0; i < movie_count; i++) {
        printf("Title: %s | Rating: %.1f (%d ratings)\n", movies[i].title, movies[i].rating, movies[i].ratings_count);
    }
    printf("===================\n");
}

int main() {
    int option;

    while (1) {
        clearScreen();
        displayMenu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                addMovie();
                break;
            case 2:
                rateMovie();
                break;
            case 3:
                viewMovies();
                break;
            case 4:
                printf("Exiting the Movie Rating System. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option! Please try again.\n");
        }

        printf("\nPress Enter to continue...");
        while (getchar() != '\n'); // Wait for user to press Enter
        getchar(); // Consume Enter key
    }

    return 0;
}