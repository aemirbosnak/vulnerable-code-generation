//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE 100

typedef struct {
    char title[MAX_TITLE];
    float rating;
    char review[256];
} Movie;

Movie movieList[MAX_MOVIES];
int movieCount = 0;

// Function Prototypes
void addMovie();
void displayMovies();
void searchMovie();
void sortMovies();

int main() {
    int choice;

    printf("Welcome to the Sherlock Holmes Movie Rating System!\n");
    printf("Aiding you in solving the mystery of movie excellence.\n");

    do {
        printf("\nMenu:\n");
        printf("1. Add a movie\n");
        printf("2. Display all movies\n");
        printf("3. Search for a movie\n");
        printf("4. Sort movies by rating\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie();
                break;
            case 2:
                displayMovies();
                break;
            case 3:
                searchMovie();
                break;
            case 4:
                sortMovies();
                displayMovies();
                break;
            case 5:
                printf("Exiting the Sherlock Holmes Movie Rating System. Farewell!\n");
                break;
            default:
                printf("That choice is no good, Watson! Try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void addMovie() {
    if (movieCount >= MAX_MOVIES) {
        printf("To be or not to be, you cannot add more movies!\n");
        return;
    }

    printf("Enter the movie title: ");
    getchar(); // Clear buffer
    fgets(movieList[movieCount].title, MAX_TITLE, stdin);
    movieList[movieCount].title[strcspn(movieList[movieCount].title, "\n")] = '\0'; // Remove newline

    printf("Rate the movie (0.0 to 10.0): ");
    scanf("%f", &movieList[movieCount].rating);

    printf("Write your review (brief): ");
    getchar(); // Clear buffer
    fgets(movieList[movieCount].review, 256, stdin);
    movieList[movieCount].review[strcspn(movieList[movieCount].review, "\n")] = '\0'; // Remove newline

    movieCount++;
    printf("Elementary, my dear Watson! Movie added.\n");
}

void displayMovies() {
    if (movieCount == 0) {
        printf("Alas! There are no movies to display.\n");
        return;
    }

    printf("\nList of Movies:\n");
    for (int i = 0; i < movieCount; i++) {
        printf("Title: %s\n", movieList[i].title);
        printf("Rating: %.1f\n", movieList[i].rating);
        printf("Review: %s\n\n", movieList[i].review);
    }
}

void searchMovie() {
    char searchTitle[MAX_TITLE];
    printf("Enter the title of the movie you wish to search for: ");
    getchar(); // Clear buffer
    fgets(searchTitle, MAX_TITLE, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = '\0'; // Remove newline

    printf("Ah, the game is afoot! Searching for '%s'...\n", searchTitle);
    int found = 0;
    
    for (int i = 0; i < movieCount; i++) {
        if (strcasecmp(movieList[i].title, searchTitle) == 0) {
            printf("Title: %s\n", movieList[i].title);
            printf("Rating: %.1f\n", movieList[i].rating);
            printf("Review: %s\n", movieList[i].review);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No such movie found in our records, perplexing indeed.\n");
    }
}

void sortMovies() {
    for (int i = 0; i < movieCount - 1; i++) {
        for (int j = i + 1; j < movieCount; j++) {
            if (movieList[i].rating < movieList[j].rating) {
                // Swap movies
                Movie temp = movieList[i];
                movieList[i] = movieList[j];
                movieList[j] = temp;
            }
        }
    }
    printf("The movies have been arranged most splendidly!\n");
}