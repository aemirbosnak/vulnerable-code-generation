//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define TITLE_LENGTH 50

typedef struct {
    char title[TITLE_LENGTH];
    float rating;  // Rating between 0 to 10
} Movie;

typedef struct {
    Movie movies[MAX_MOVIES];
    int count;
} MovieDatabase;

// Function prototypes
void initializeDatabase(MovieDatabase *db);
void addMovie(MovieDatabase *db);
void displayMovies(const MovieDatabase *db);
void calculateEntropy(const MovieDatabase *db);
int menu();

int main() {
    MovieDatabase db;
    initializeDatabase(&db);

    int choice;
    do {
        choice = menu();
        switch (choice) {
            case 1:
                addMovie(&db);
                break;
            case 2:
                displayMovies(&db);
                break;
            case 3:
                calculateEntropy(&db);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void initializeDatabase(MovieDatabase *db) {
    db->count = 0;
}

void addMovie(MovieDatabase *db) {
    if (db->count >= MAX_MOVIES) {
        printf("Database is full. Cannot add more movies.\n");
        return;
    }

    Movie newMovie;
    printf("Enter movie title: ");
    getchar(); // Clear newline from buffer
    fgets(newMovie.title, TITLE_LENGTH, stdin);
    newMovie.title[strcspn(newMovie.title, "\n")] = 0; // Remove newline

    printf("Enter movie rating (0 to 10): ");
    scanf("%f", &newMovie.rating);

    // Validate rating
    if (newMovie.rating < 0 || newMovie.rating > 10) {
        printf("Rating must be between 0 and 10.\n");
        return;
    }

    db->movies[db->count++] = newMovie;
    printf("Movie '%s' added with rating %.1f.\n", newMovie.title, newMovie.rating);
}

void displayMovies(const MovieDatabase *db) {
    if (db->count == 0) {
        printf("No movies in the database.\n");
        return;
    }

    printf("\nMovie List:\n");
    for (int i = 0; i < db->count; i++) {
        printf("%d. %s - Rating: %.1f\n", i + 1, db->movies[i].title, db->movies[i].rating);
    }
    printf("\n");
}

void calculateEntropy(const MovieDatabase *db) {
    if (db->count == 0) {
        printf("No movies to analyze.\n");
        return;
    }

    float totalRatings = 0;
    float entropy = 0;
    int ratingCount[11] = {0}; // Count occurrences of each rating

    // Count occurrences of each rating
    for (int i = 0; i < db->count; i++) {
        int r = (int)(db->movies[i].rating);
        ratingCount[r]++;
        totalRatings++;
    }

    // Calculate entropy
    for (int i = 0; i < 11; i++) {
        if (ratingCount[i] > 0) {
            float p = ratingCount[i] / totalRatings;
            entropy -= p * log2(p);
        }
    }

    printf("Rating Entropy: %.4f\n", entropy);
}

int menu() {
    int choice;
    printf("\nMovie Rating System\n");
    printf("1. Add Movie\n");
    printf("2. Display Movies\n");
    printf("3. Calculate Rating Entropy\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}