//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define TITLE_LENGTH 50
#define RATING_LENGTH 10

typedef struct {
    char title[TITLE_LENGTH];
    char rating[RATING_LENGTH];
} Movie;

Movie movieDB[MAX_MOVIES];
int movieCount = 0;

void addMovie() {
    if (movieCount >= MAX_MOVIES) {
        printf("Movie database is full!\n");
        return;
    }
    printf("Enter movie title: ");
    scanf(" %[^\n]", movieDB[movieCount].title);
    printf("Enter movie rating (e.g. G, PG, PG-13, R): ");
    scanf(" %[^\n]", movieDB[movieCount].rating);
    movieCount++;
    printf("Movie added successfully!\n");
}

void displayMovies() {
    if (movieCount == 0) {
        printf("No movies in the database.\n");
        return;
    }
    printf("Movies in Database:\n");
    for (int i = 0; i < movieCount; i++) {
        printf("%d. %s - %s\n", i + 1, movieDB[i].title, movieDB[i].rating);
    }
}

void searchMovie() {
    char searchTitle[TITLE_LENGTH];
    printf("Enter movie title to search: ");
    scanf(" %[^\n]", searchTitle);

    for (int i = 0; i < movieCount; i++) {
        if (strcasecmp(movieDB[i].title, searchTitle) == 0) {
            printf("Found: %s - %s\n", movieDB[i].title, movieDB[i].rating);
            return;
        }
    }
    
    printf("Movie not found.\n");
}

void rateMovie() {
    char rateTitle[TITLE_LENGTH];
    char newRating[RATING_LENGTH];
    printf("Enter movie title to rate: ");
    scanf(" %[^\n]", rateTitle);

    for (int i = 0; i < movieCount; i++) {
        if (strcasecmp(movieDB[i].title, rateTitle) == 0) {
            printf("Current rating of %s is %s\n", movieDB[i].title, movieDB[i].rating);
            printf("Enter new rating: ");
            scanf(" %[^\n]", newRating);
            strcpy(movieDB[i].rating, newRating);
            printf("Rating updated successfully!\n");
            return;
        }
    }
    
    printf("Movie not found.\n");
}

void deleteMovie() {
    char deleteTitle[TITLE_LENGTH];
    printf("Enter movie title to delete: ");
    scanf(" %[^\n]", deleteTitle);

    for (int i = 0; i < movieCount; i++) {
        if (strcasecmp(movieDB[i].title, deleteTitle) == 0) {
            for (int j = i; j < movieCount - 1; j++) {
                movieDB[j] = movieDB[j+1];
            }
            movieCount--;
            printf("Movie deleted successfully!\n");
            return;
        }
    }
    
    printf("Movie not found.\n");
}

void displayMenu() {
    printf("\n--- Movie Rating System ---\n");
    printf("1. Add Movie\n");
    printf("2. Display Movies\n");
    printf("3. Search Movie\n");
    printf("4. Rate Movie\n");
    printf("5. Delete Movie\n");
    printf("6. Exit\n");
    printf("--------------------------\n");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
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
                rateMovie();
                break;
            case 5:
                deleteMovie();
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}