//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define TITLE_LENGTH 50
#define REVIEW_LENGTH 200

typedef struct {
    char title[TITLE_LENGTH];
    float rating;
    char review[REVIEW_LENGTH];
} Movie;

typedef struct {
    Movie movies[MAX_MOVIES];
    int count;
} MovieDatabase;

void initializeDatabase(MovieDatabase *db) {
    db->count = 0;
}

void addMovie(MovieDatabase *db, const char *title, float rating, const char *review) {
    if (db->count >= MAX_MOVIES) {
        printf("Error: Database is full!\n");
        return;
    }
    
    strncpy(db->movies[db->count].title, title, TITLE_LENGTH);
    db->movies[db->count].rating = rating;
    strncpy(db->movies[db->count].review, review, REVIEW_LENGTH);
    db->count++;
}

void displayMovies(const MovieDatabase *db) {
    if (db->count == 0) {
        printf("No movies found in the database.\n");
        return;
    }

    printf("\nMovie Database:\n");
    for (int i = 0; i < db->count; i++) {
        printf("Title: %s\n", db->movies[i].title);
        printf("Rating: %.1f\n", db->movies[i].rating);
        printf("Review: %s\n\n", db->movies[i].review);
    }
}

float calculateAverageRating(const MovieDatabase *db) {
    if (db->count == 0) {
        return 0.0;
    }

    float totalRating = 0.0;
    for (int i = 0; i < db->count; i++) {
        totalRating += db->movies[i].rating;
    }
    return totalRating / db->count;
}

int main() {
    MovieDatabase db;
    initializeDatabase(&db);

    int choice;
    char title[TITLE_LENGTH];
    float rating;
    char review[REVIEW_LENGTH];

    while (1) {
        printf("\nMovie Rating System\n");
        printf("1. Add Movie\n");
        printf("2. Display Movies\n");
        printf("3. Calculate Average Rating\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character after number input

        switch (choice) {
            case 1:
                printf("Enter title of the movie: ");
                fgets(title, TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = '\0';  // Remove newline from fgets

                printf("Enter rating (0.0 to 10.0): ");
                scanf("%f", &rating);
                getchar(); // Consume newline character after float input

                printf("Enter review: ");
                fgets(review, REVIEW_LENGTH, stdin);
                review[strcspn(review, "\n")] = '\0';  // Remove newline from fgets

                addMovie(&db, title, rating, review);
                break;
            case 2:
                displayMovies(&db);
                break;
            case 3:
                printf("Average Rating: %.1f\n", calculateAverageRating(&db));
                break;
            case 4:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}