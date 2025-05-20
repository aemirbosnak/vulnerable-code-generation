//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define TITLE_LEN 100

typedef struct {
    char title[TITLE_LEN];
    float rating;
} Movie;

Movie movieCatalog[MAX_MOVIES];
int movieCount = 0;

void addMovie(const char *title, float rating) {
    if (movieCount < MAX_MOVIES) {
        strcpy(movieCatalog[movieCount].title, title);
        movieCatalog[movieCount].rating = rating;
        movieCount++;
        printf("Movie '%s' added with rating %.1f!\n", title, rating);
    } else {
        printf("Catalog is full! Cannot add more movies.\n");
    }
}

void displayMovies() {
    if (movieCount == 0) {
        printf("No movies in the catalog!\n");
        return;
    }

    printf("\n--- Movie Catalog ---\n");
    for (int i = 0; i < movieCount; i++) {
        printf("Title: %s, Rating: %.1f\n", movieCatalog[i].title, movieCatalog[i].rating);
    }
    printf("------------------------------\n");
}

void displayRatingStatistics() {
    if (movieCount == 0) {
        printf("No movies to display statistics for!\n");
        return;
    }

    float totalRating = 0;
    float highestRating = 0;
    float lowestRating = 10;
    int highCount = 0;

    for (int i = 0; i < movieCount; i++) {
        float currentRating = movieCatalog[i].rating;
        totalRating += currentRating;
        if (currentRating > highestRating) {
            highestRating = currentRating;
        }
        if (currentRating < lowestRating) {
            lowestRating = currentRating;
        }
        if (currentRating >= 8.0) {
            highCount++;
        }
    }

    printf("\n--- Rating Statistics ---\n");
    printf("Average Rating: %.1f\n",
           (totalRating / movieCount));
    printf("Highest Rating: %.1f\n", highestRating);
    printf("Lowest Rating: %.1f\n", lowestRating);
    printf("Number of High Rated (8.0 and above) Movies: %d\n", highCount);
    printf("------------------------------\n");
}

int main() {
    int choice;
    char title[TITLE_LEN];
    float rating;

    while (1) {
        printf("=== Movie Rating System ===\n");
        printf("1. Add Movie\n");
        printf("2. Display All Movies\n");
        printf("3. Display Rating Statistics\n");
        printf("4. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character left by scanf

        switch (choice) {
            case 1:
                printf("Enter movie title: ");
                fgets(title, TITLE_LEN, stdin);
                title[strcspn(title, "\n")] = '\0'; // Remove newline
                printf("Enter movie rating (0.0 to 10.0): ");
                scanf("%f", &rating);
                if (rating < 0.0 || rating > 10.0) {
                    printf("Invalid rating! Please enter a value between 0.0 and 10.0.\n");
                } else {
                    addMovie(title, rating);
                }
                break;

            case 2:
                displayMovies();
                break;

            case 3:
                displayRatingStatistics();
                break;

            case 4:
                printf("Exiting program. Thank you!\n");
                exit(0);
                break;

            default:
                printf("Invalid choice! Please choose again.\n");
                break;
        }
    }
    return 0;
}