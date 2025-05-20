//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char title[MAX_NAME_LENGTH];
    int ratings[5];
    int totalRatings;
    int ratingCount;
} Movie;

Movie movieList[MAX_MOVIES];
int movieCount = 0;

void addMovie(const char *title) {
    if (movieCount < MAX_MOVIES) {
        strcpy(movieList[movieCount].title, title);
        for (int i = 0; i < 5; i++) {
            movieList[movieCount].ratings[i] = 0;
        }
        movieList[movieCount].totalRatings = 0;
        movieList[movieCount].ratingCount = 0;
        movieCount++;
        printf("Movie \"%s\" added successfully!\n", title);
    } else {
        printf("Movie list is full!\n");
    }
}

void rateMovie(const char *title, int rating) {
    for (int i = 0; i < movieCount; i++) {
        if (strcmp(movieList[i].title, title) == 0) {
            if (rating >= 1 && rating <= 5) {
                movieList[i].ratings[rating - 1]++;
                movieList[i].totalRatings += rating;
                movieList[i].ratingCount++;
                printf("Rating of %d added to \"%s\".\n", rating, title);
            } else {
                printf("Rating must be between 1 and 5!\n");
            }
            return;
        }
    }
    printf("Movie \"%s\" not found!\n", title);
}

void displayMovieInfo(const char *title) {
    for (int i = 0; i < movieCount; i++) {
        if (strcmp(movieList[i].title, title) == 0) {
            printf("Movie Title: %s\n", movieList[i].title);
            printf("Total Ratings: %d\n", movieList[i].ratingCount);
            if (movieList[i].ratingCount > 0) {
                double averageRating = (double)movieList[i].totalRatings / movieList[i].ratingCount;
                printf("Average Rating: %.2f\n", averageRating);
            } else {
                printf("No ratings yet.\n");
            }
            printf("Rating Distribution:\n");
            for (int j = 0; j < 5; j++) {
                printf("Rating %d: %d\n", j + 1, movieList[i].ratings[j]);
            }
            return;
        }
    }
    printf("Movie \"%s\" not found!\n", title);
}

void displayAllMovies() {
    printf("Movies in the system:\n");
    for (int i = 0; i < movieCount; i++) {
        printf("%d. %s\n", i + 1, movieList[i].title);
    }
}

int main() {
    int choice;
    char title[MAX_NAME_LENGTH];
    int rating;

    while (1) {
        printf("\n--- Movie Rating System ---\n");
        printf("1. Add Movie\n");
        printf("2. Rate Movie\n");
        printf("3. View Movie Info\n");
        printf("4. List All Movies\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter movie title: ");
                scanf(" %[^\n]", title); // To read string with spaces
                addMovie(title);
                break;
            case 2:
                printf("Enter movie title to rate: ");
                scanf(" %[^\n]", title);
                printf("Enter your rating (1-5): ");
                scanf("%d", &rating);
                rateMovie(title, rating);
                break;
            case 3:
                printf("Enter movie title to view info: ");
                scanf(" %[^\n]", title);
                displayMovieInfo(title);
                break;
            case 4:
                displayAllMovies();
                break;
            case 5:
                printf("Exiting system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}