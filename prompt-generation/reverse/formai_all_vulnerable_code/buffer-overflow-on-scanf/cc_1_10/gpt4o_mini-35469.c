//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 50
#define MAX_RATINGS 10

typedef struct {
    char title[100];
    char genre[50];
    float ratings[MAX_RATINGS];
    int ratingCount;
} Movie;

typedef struct {
    Movie movies[MAX_MOVIES];
    int movieCount;
} MovieDatabase;

void initializeDatabase(MovieDatabase *db) {
    db->movieCount = 0;
}

void addMovie(MovieDatabase *db) {
    if (db->movieCount >= MAX_MOVIES) {
        printf("Error: Movie database is full!\n");
        return;
    }

    Movie newMovie;
    printf("Enter movie title: ");
    getchar(); // to consume newline from previous input
    fgets(newMovie.title, 100, stdin);
    newMovie.title[strcspn(newMovie.title, "\n")] = 0; // Remove newline character

    printf("Enter movie genre: ");
    fgets(newMovie.genre, 50, stdin);
    newMovie.genre[strcspn(newMovie.genre, "\n")] = 0; // Remove newline character

    newMovie.ratingCount = 0;

    db->movies[db->movieCount++] = newMovie;
    printf("Movie added successfully!\n");
}

void addRating(MovieDatabase *db) {
    char title[100];
    printf("Enter movie title to rate: ");
    getchar();
    fgets(title, 100, stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline character

    for (int i = 0; i < db->movieCount; i++) {
        if (strcmp(db->movies[i].title, title) == 0) {
            if (db->movies[i].ratingCount >= MAX_RATINGS) {
                printf("Error: Maximum ratings reached for this movie!\n");
                return;
            }

            float rating;
            printf("Enter rating (0-5): ");
            scanf("%f", &rating);

            if (rating < 0 || rating > 5) {
                printf("Error: Invalid rating. Rating must be between 0 and 5.\n");
                return;
            }

            db->movies[i].ratings[db->movies[i].ratingCount++] = rating;
            printf("Rating added successfully!\n");
            return;
        }
    }
    printf("Movie not found in the database.\n");
}

void displayMovieInfo(const Movie *movie) {
    printf("\nTitle: %s\n", movie->title);
    printf("Genre: %s\n", movie->genre);
    printf("Ratings: ");
    if (movie->ratingCount == 0) {
        printf("No ratings yet.\n");
    } else {
        for (int j = 0; j < movie->ratingCount; j++) {
            printf("%.2f ", movie->ratings[j]);
        }
        printf("\n");
    }
}

void displayDatabase(const MovieDatabase *db) {
    printf("\nMovie Database:\n");
    for (int i = 0; i < db->movieCount; i++) {
        displayMovieInfo(&db->movies[i]);
    }
}

float calculateAverageRating(const Movie *movie) {
    if (movie->ratingCount == 0) return 0.0;

    float sum = 0.0;
    for (int i = 0; i < movie->ratingCount; i++) {
        sum += movie->ratings[i];
    }
    return sum / movie->ratingCount;
}

void displayAverageRatings(const MovieDatabase *db) {
    printf("\nAverage Ratings:\n");
    for (int i = 0; i < db->movieCount; i++) {
        float average = calculateAverageRating(&db->movies[i]);
        printf("Movie: %s, Average Rating: %.2f\n", db->movies[i].title, average);
    }
}

int main() {
    MovieDatabase db;
    initializeDatabase(&db);
    int choice;

    do {
        printf("\n=== Movie Rating System ===\n");
        printf("1. Add Movie\n");
        printf("2. Add Rating\n");
        printf("3. Display Movies\n");
        printf("4. Show Average Ratings\n");
        printf("5. Exit\n");
        printf("Select an option (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(&db);
                break;
            case 2:
                addRating(&db);
                break;
            case 3:
                displayDatabase(&db);
                break;
            case 4:
                displayAverageRatings(&db);
                break;
            case 5:
                printf("Exiting the system.\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}