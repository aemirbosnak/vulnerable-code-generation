//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 100
#define MAX_REVIEW_LENGTH 255

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char review[MAX_REVIEW_LENGTH];
    int rating; // 1 to 5
} Movie;

Movie movieDatabase[MAX_MOVIES];
int movieCount = 0;

void addMovie() {
    if (movieCount >= MAX_MOVIES) {
        printf("Movie database is full!\n");
        return;
    }

    Movie newMovie;
    printf("Enter movie title: ");
    scanf(" %[^\n]", newMovie.title); // Read string with spaces
    printf("Enter your review (max %d characters): ", MAX_REVIEW_LENGTH);
    scanf(" %[^\n]", newMovie.review); // Read string with spaces
    printf("Rate the movie (1 to 5): ");
    scanf("%d", &newMovie.rating);

    // Validate rating
    if (newMovie.rating < 1 || newMovie.rating > 5) {
        printf("Invalid rating. Please enter a rating between 1 and 5.\n");
        return;
    }

    movieDatabase[movieCount++] = newMovie;
    printf("Movie added successfully!\n");
}

void viewMovies() {
    if (movieCount == 0) {
        printf("No movies rated yet.\n");
        return;
    }

    printf("\nMovies rated:\n");
    for (int i = 0; i < movieCount; i++) {
        printf("Movie #%d:\n", i + 1);
        printf("Title: %s\n", movieDatabase[i].title);
        printf("Review: %s\n", movieDatabase[i].review);
        printf("Rating: %d/5\n", movieDatabase[i].rating);
        printf("--------------------\n");
    }
}

void searchMovie() {
    char searchTitle[MAX_TITLE_LENGTH];
    printf("Enter the movie title to search: ");
    scanf(" %[^\n]", searchTitle);
    
    int found = 0;
    for (int i = 0; i < movieCount; i++) {
        if (strcasecmp(movieDatabase[i].title, searchTitle) == 0) {
            found = 1;
            printf("Movie Details:\n");
            printf("Title: %s\n", movieDatabase[i].title);
            printf("Review: %s\n", movieDatabase[i].review);
            printf("Rating: %d/5\n", movieDatabase[i].rating);
            break;
        }
    }

    if (!found) {
        printf("Movie not found in the database.\n");
    }
}

void displayMenu() {
    printf("\nMovie Rating System\n");
    printf("---------------------\n");
    printf("1. Add a movie\n");
    printf("2. View all movies\n");
    printf("3. Search for a movie\n");
    printf("4. Exit\n");
}

int main() {
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie();
                break;
            case 2:
                viewMovies();
                break;
            case 3:
                searchMovie();
                break;
            case 4:
                printf("Exiting the Movie Rating System. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
        }

    } while (choice != 4);

    return 0;
}