//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    int ratings[MAX_MOVIES];
    int ratingCount;
} Movie;

void addMovie(Movie *movies, int *movieCount);
void rateMovie(Movie *movies, int movieCount);
void showRatings(Movie *movies, int movieCount);
void displayMenu();
float calculateAverageRating(int ratings[], int count);

int main() {
    Movie movies[MAX_MOVIES];
    int movieCount = 0;
    int choice;

    while (1) {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from input buffer

        switch (choice) {
            case 1:
                addMovie(movies, &movieCount);
                break;
            case 2:
                rateMovie(movies, movieCount);
                break;
            case 3:
                showRatings(movies, movieCount);
                break;
            case 4:
                printf("Exiting the program. Thank you!\n");
                return 0;
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n--- Movie Rating System ---\n");
    printf("1. Add Movie\n");
    printf("2. Rate Movie\n");
    printf("3. Show Ratings\n");
    printf("4. Exit\n");
}

void addMovie(Movie *movies, int *movieCount) {
    if (*movieCount >= MAX_MOVIES) {
        printf("Cannot add more movies. Maximum limit reached.\n");
        return;
    }
    
    printf("Enter movie title: ");
    fgets(movies[*movieCount].title, MAX_TITLE_LENGTH, stdin);
    movies[*movieCount].title[strcspn(movies[*movieCount].title, "\n")] = 0; // Remove newline character
    movies[*movieCount].ratingCount = 0;
    (*movieCount)++;
    
    printf("Movie '%s' added successfully!\n", movies[*movieCount - 1].title);
}

void rateMovie(Movie *movies, int movieCount) {
    char title[MAX_TITLE_LENGTH];
    printf("Enter movie title to rate: ");
    fgets(title, MAX_TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline character

    for (int i = 0; i < movieCount; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            if (movies[i].ratingCount >= MAX_MOVIES) {
                printf("Maximum ratings reached for movie '%s'.\n", movies[i].title);
                return;
            }
            int rating;
            printf("Enter your rating (1-5): ");
            scanf("%d", &rating);
            getchar(); // Clear newline character from input buffer
            
            if (rating < 1 || rating > 5) {
                printf("Invalid rating! Please enter a number between 1 and 5.\n");
            } else {
                movies[i].ratings[movies[i].ratingCount] = rating;
                movies[i].ratingCount++;
                printf("Rating of %d added to movie '%s'.\n", rating, movies[i].title);
            }
            return;
        }
    }
    printf("Movie '%s' not found.\n", title);
}

void showRatings(Movie *movies, int movieCount) {
    if (movieCount == 0) {
        printf("No movies to display ratings for.\n");
        return;
    }

    for (int i = 0; i < movieCount; i++) {
        printf("--- Ratings for '%s' ---\n", movies[i].title);
        if (movies[i].ratingCount == 0) {
            printf("No ratings yet.\n");
        } else {
            for (int j = 0; j < movies[i].ratingCount; j++) {
                printf("Rating %d: %d\n", j + 1, movies[i].ratings[j]);
            }
            float average = calculateAverageRating(movies[i].ratings, movies[i].ratingCount);
            printf("Average Rating: %.2f\n", average);
        }
    }
}

float calculateAverageRating(int ratings[], int count) {
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += ratings[i];
    }
    return (float)sum / count;
}