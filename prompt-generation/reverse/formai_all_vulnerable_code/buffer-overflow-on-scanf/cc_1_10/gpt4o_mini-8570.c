//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 50
#define MAX_REVIEWER_NAME 30

typedef struct {
    char title[MAX_TITLE_LENGTH];
    float rating;
    char reviewerName[MAX_REVIEWER_NAME];
} Movie;

Movie movieDatabase[MAX_MOVIES];
int movieCount = 0;

void addMovie(char *title, float rating, char *reviewerName) {
    if (movieCount >= MAX_MOVIES) {
        printf("Database is full, cannot add more movies.\n");
        return;
    }
    strncpy(movieDatabase[movieCount].title, title, MAX_TITLE_LENGTH);
    movieDatabase[movieCount].rating = rating;
    strncpy(movieDatabase[movieCount].reviewerName, reviewerName, MAX_REVIEWER_NAME);
    movieCount++;
    printf("Movie added successfully.\n");
}

void listMovies() {
    if (movieCount == 0) {
        printf("No movies in the database.\n");
        return;
    }
    printf("\nMovie List:\n");
    for (int i = 0; i < movieCount; i++) {
        printf("Title: %s, Rating: %.1f, Reviewed by: %s\n", 
               movieDatabase[i].title, movieDatabase[i].rating, movieDatabase[i].reviewerName);
    }
}

void searchMovie(char *title) {
    for (int i = 0; i < movieCount; i++) {
        if (strcasecmp(movieDatabase[i].title, title) == 0) {
            printf("Found Movie: %s, Rating: %.1f, Reviewed by: %s\n", 
                   movieDatabase[i].title, movieDatabase[i].rating, movieDatabase[i].reviewerName);
            return;
        }
    }
    printf("Movie with title '%s' not found.\n", title);
}

void rateMovie(char *title, float rating) {
    for (int i = 0; i < movieCount; i++) {
        if (strcasecmp(movieDatabase[i].title, title) == 0) {
            movieDatabase[i].rating = rating;
            printf("Rating updated for movie '%s' to %.1f\n", title, rating);
            return;
        }
    }
    printf("Movie with title '%s' not found.\n", title);
}

void deleteMovie(char *title) {
    for (int i = 0; i < movieCount; i++) {
        if (strcasecmp(movieDatabase[i].title, title) == 0) {
            for (int j = i; j < movieCount - 1; j++) {
                movieDatabase[j] = movieDatabase[j + 1];
            }
            movieCount--;
            printf("Movie '%s' deleted successfully.\n", title);
            return;
        }
    }
    printf("Movie with title '%s' not found.\n", title);
}

void displayMenu() {
    printf("\n--- Movie Rating System ---\n");
    printf("1. Add Movie\n");
    printf("2. List Movies\n");
    printf("3. Search Movie\n");
    printf("4. Rate Movie\n");
    printf("5. Delete Movie\n");
    printf("6. Exit\n");
}

int main() {
    int choice;
    char title[MAX_TITLE_LENGTH], reviewerName[MAX_REVIEWER_NAME];
    float rating;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter movie title: ");
                scanf(" %[^\n]s", title);
                printf("Enter rating (0 to 10): ");
                scanf("%f", &rating);
                printf("Enter reviewer name: ");
                scanf(" %[^\n]s", reviewerName);
                addMovie(title, rating, reviewerName);
                break;
            case 2:
                listMovies();
                break;
            case 3:
                printf("Enter movie title to search: ");
                scanf(" %[^\n]s", title);
                searchMovie(title);
                break;
            case 4:
                printf("Enter movie title to rate: ");
                scanf(" %[^\n]s", title);
                printf("Enter new rating (0 to 10): ");
                scanf("%f", &rating);
                rateMovie(title, rating);
                break;
            case 5:
                printf("Enter movie title to delete: ");
                scanf(" %[^\n]s", title);
                deleteMovie(title);
                break;
            case 6:
                printf("Exiting the Movie Rating System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}