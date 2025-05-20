//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define TITLE_LENGTH 100
#define MAX_RATINGS 5

typedef struct {
    char title[TITLE_LENGTH];
    int ratings[MAX_RATINGS];
    int ratingCount;
} Movie;

typedef struct {
    Movie movies[MAX_MOVIES];
    int movieCount;
} MovieDatabase;

void initializeDatabase(MovieDatabase *db) {
    db->movieCount = 0;
}

void addMovie(MovieDatabase *db, const char *title) {
    if (db->movieCount >= MAX_MOVIES) {
        printf("Error: Unable to add more movies. Maximum limit reached.\n");
        return;
    }
    strncpy(db->movies[db->movieCount].title, title, TITLE_LENGTH);
    db->movies[db->movieCount].ratingCount = 0;
    db->movieCount++;
    printf("Movie '%s' added successfully.\n", title);
}

void rateMovie(MovieDatabase *db, const char *title, int rating) {
    if (rating < 1 || rating > 5) {
        printf("Error: Rating must be between 1 and 5.\n");
        return;
    }
    for (int i = 0; i < db->movieCount; i++) {
        if (strcmp(db->movies[i].title, title) == 0) {
            if (db->movies[i].ratingCount >= MAX_RATINGS) {
                printf("Error: Maximum ratings reached for movie '%s'.\n", title);
                return;
            }
            db->movies[i].ratings[db->movies[i].ratingCount++] = rating;
            printf("Rating of %d added to movie '%s'.\n", rating, title);
            return;
        }
    }
    printf("Error: Movie '%s' not found.\n", title);
}

float calculateAverageRating(const Movie *movie) {
    int sum = 0;
    for (int i = 0; i < movie->ratingCount; i++) {
        sum += movie->ratings[i];
    }
    return (float)sum / movie->ratingCount;
}

void displayMovieRatings(const MovieDatabase *db) {
    if (db->movieCount == 0) {
        printf("No movies to display ratings.\n");
        return;
    }
    printf("\nMovie Ratings:\n");
    for (int i = 0; i < db->movieCount; i++) {
        printf("Title: %s | ", db->movies[i].title);
        if (db->movies[i].ratingCount == 0) {
            printf("No ratings yet.\n");
        } else {
            float average = calculateAverageRating(&db->movies[i]);
            printf("Average Rating: %.2f\n", average);
        }
    }
    printf("\n");
}

void clearDatabase(MovieDatabase *db) {
    db->movieCount = 0;
    printf("Movie database cleared.\n");
}

int main() {
    MovieDatabase db;
    initializeDatabase(&db);
    
    int choice;
    char title[TITLE_LENGTH];
    int rating;

    do {
        printf("\nMovie Rating System\n");
        printf("1. Add Movie\n");
        printf("2. Rate Movie\n");
        printf("3. Display Movie Ratings\n");
        printf("4. Clear Movie Database\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter movie title: ");
                getchar(); // consume newline
                fgets(title, TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = 0; // remove newline
                addMovie(&db, title);
                break;
            case 2:
                printf("Enter movie title to rate: ");
                getchar(); // consume newline
                fgets(title, TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = 0; // remove newline
                printf("Enter rating (1-5): ");
                scanf("%d", &rating);
                rateMovie(&db, title, rating);
                break;
            case 3:
                displayMovieRatings(&db);
                break;
            case 4:
                clearDatabase(&db);
                break;
            case 5:
                printf("Exiting the system.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}