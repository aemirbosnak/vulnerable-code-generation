//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    int ratingSum;
    int ratingCount;
} Movie;

Movie movieDatabase[MAX_MOVIES];
int movieCount = 0;

void addMovie(const char *title) {
    if (movieCount < MAX_MOVIES) {
        strncpy(movieDatabase[movieCount].title, title, MAX_TITLE_LENGTH);
        movieDatabase[movieCount].ratingSum = 0;
        movieDatabase[movieCount].ratingCount = 0;
        movieCount++;
    } else {
        printf("Movie database is full! Cannot add more movies.\n");
    }
}

void rateMovie(const char *title, int rating) {
    for (int i = 0; i < movieCount; i++) {
        if (strcmp(movieDatabase[i].title, title) == 0) {
            movieDatabase[i].ratingSum += rating;
            movieDatabase[i].ratingCount++;
            printf("You rated '%s' with a score of %d.\n", title, rating);
            return;
        }
    }
    printf("Movie '%s' not found in the database.\n", title);
}

void displayMovies() {
    printf("\n=== Movie Ratings ===\n");
    for (int i = 0; i < movieCount; i++) {
        if (movieDatabase[i].ratingCount > 0) {
            float averageRating = (float)movieDatabase[i].ratingSum / movieDatabase[i].ratingCount;
            printf("Movie: %s | Average Rating: %.2f\n", movieDatabase[i].title, averageRating);
        } else {
            printf("Movie: %s | No ratings yet.\n", movieDatabase[i].title);
        }
    }
    printf("======================\n");
}

void searchMovie(const char *title) {
    for (int i = 0; i < movieCount; i++) {
        if (strcmp(movieDatabase[i].title, title) == 0) {
            float averageRating = (movieDatabase[i].ratingCount > 0) 
                                  ? (float)movieDatabase[i].ratingSum / movieDatabase[i].ratingCount 
                                  : 0.0f;
            printf("Found Movie: %s | Average Rating: %.2f\n", movieDatabase[i].title, averageRating);
            return;
        }
    }
    printf("Movie '%s' not found in the database.\n", title);
}

int main() {
    char command[50];
    char title[MAX_TITLE_LENGTH];
    int rating;

    printf("Welcome to the Unique Movie Rating System!\n");

    while (1) {
        printf("\nAvailable commands:\n");
        printf("1. Add Movie\n");
        printf("2. Rate Movie\n");
        printf("3. Display Movies\n");
        printf("4. Search Movie\n");
        printf("5. Exit\n");
        printf("Enter a command: ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; // Remove newline character

        if (strcmp(command, "1") == 0) {
            printf("Enter movie title: ");
            fgets(title, sizeof(title), stdin);
            title[strcspn(title, "\n")] = 0; // Remove newline character
            addMovie(title);
        } else if (strcmp(command, "2") == 0) {
            printf("Enter movie title to rate: ");
            fgets(title, sizeof(title), stdin);
            title[strcspn(title, "\n")] = 0; // Remove newline character
            printf("Enter rating (1-5): ");
            scanf("%d", &rating);
            getchar(); // Consume the newline left by scanf
            if (rating >= 1 && rating <= 5) {
                rateMovie(title, rating);
            } else {
                printf("Rating must be between 1 and 5.\n");
            }
        } else if (strcmp(command, "3") == 0) {
            displayMovies();
        } else if (strcmp(command, "4") == 0) {
            printf("Enter movie title to search: ");
            fgets(title, sizeof(title), stdin);
            title[strcspn(title, "\n")] = 0; // Remove newline character
            searchMovie(title);
        } else if (strcmp(command, "5") == 0) {
            printf("Thank you for using the Unique Movie Rating System! Goodbye!\n");
            break;
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }

    return 0;
}