//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    float ratingSum;
    int ratingCount;
} Movie;

Movie movieList[MAX_MOVIES];
int movieCount = 0;

void addMovie(const char *title) {
    if (movieCount < MAX_MOVIES) {
        strncpy(movieList[movieCount].title, title, MAX_TITLE_LENGTH);
        movieList[movieCount].ratingSum = 0;
        movieList[movieCount].ratingCount = 0;
        movieCount++;
        printf("Movie '%s' added successfully!\n", title);
    } else {
        printf("Error: Movie list is full. Cannot add more movies.\n");
    }
}

void rateMovie(const char *title, float rating) {
    if (rating < 0 || rating > 10) {
        printf("Error: Rating must be between 0 and 10.\n");
        return;
    }

    for (int i = 0; i < movieCount; i++) {
        if (strcmp(movieList[i].title, title) == 0) {
            movieList[i].ratingSum += rating;
            movieList[i].ratingCount++;
            printf("Rated '%s' with %.1f. Total ratings: %d\n", title, rating, movieList[i].ratingCount);
            return;
        }
    }
    printf("Error: Movie '%s' not found.\n", title);
}

void displayRatings() {
    printf("%-30s%-15s\n", "Movie Title", "Average Rating");
    printf("%-30s%-15s\n", "-----------", "--------------");

    for (int i = 0; i < movieCount; i++) {
        float averageRating = (movieList[i].ratingCount == 0) ? 0 : (movieList[i].ratingSum / movieList[i].ratingCount);
        printf("%-30s%-15.1f\n", movieList[i].title, averageRating);
    }
}

void showMenu() {
    printf("\n---- Movie Rating System ----\n");
    printf("1. Add Movie\n");
    printf("2. Rate Movie\n");
    printf("3. Display Ratings\n");
    printf("4. Exit\n");
    printf("-----------------------------\n");
}

int main() {
    int choice;
    char title[MAX_TITLE_LENGTH];
    float rating;

    while (1) {
        showMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter movie title: ");
                scanf(" %[^\n]", title);
                addMovie(title);
                break;
            case 2:
                printf("Enter movie title to rate: ");
                scanf(" %[^\n]", title);
                printf("Enter rating (0-10): ");
                scanf("%f", &rating);
                rateMovie(title, rating);
                break;
            case 3:
                displayRatings();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Error: Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}