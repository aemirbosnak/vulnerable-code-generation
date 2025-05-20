//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define NAME_LENGTH 100

typedef struct {
    char title[NAME_LENGTH];
    char genre[NAME_LENGTH];
    float rating;
} Movie;

typedef struct {
    Movie movies[MAX_MOVIES];
    int count;
} MovieDatabase;

void initializeDatabase(MovieDatabase *db) {
    db->count = 0;
}

void addMovie(MovieDatabase *db, const char *title, const char *genre, float rating) {
    if (db->count < MAX_MOVIES) {
        strncpy(db->movies[db->count].title, title, NAME_LENGTH);
        strncpy(db->movies[db->count].genre, genre, NAME_LENGTH);
        db->movies[db->count].rating = rating;
        db->count++;
        printf("Movie added successfully!\n");
    } else {
        printf("Database is full, cannot add more movies!\n");
    }
}

void displayMovies(const MovieDatabase *db) {
    printf("\nMovies in the Database:\n");
    if (db->count == 0) {
        printf("No movies found!\n");
        return;
    }
    for (int i = 0; i < db->count; i++) {
        printf("Title: %s, Genre: %s, Rating: %.1f\n", db->movies[i].title, db->movies[i].genre, db->movies[i].rating);
    }
    printf("\n");
}

void searchMovieByTitle(const MovieDatabase *db, const char *title) {
    printf("\nSearching for \"%s\":\n", title);
    for (int i = 0; i < db->count; i++) {
        if (strcmp(db->movies[i].title, title) == 0) {
            printf("Found! Title: %s, Genre: %s, Rating: %.1f\n", db->movies[i].title, db->movies[i].genre, db->movies[i].rating);
            return;
        }
    }
    printf("Movie not found.\n");
}

void averageRating(const MovieDatabase *db) {
    if (db->count == 0) {
        printf("No movies to calculate average rating.\n");
        return;
    }
    float totalRating = 0;
    for (int i = 0; i < db->count; i++) {
        totalRating += db->movies[i].rating;
    }
    printf("Average Rating of all movies: %.1f\n", totalRating / db->count);
}

void sortMoviesByRating(MovieDatabase *db) {
    for (int i = 0; i < db->count - 1; i++) {
        for (int j = 0; j < db->count - i - 1; j++) {
            if (db->movies[j].rating < db->movies[j + 1].rating) {
                Movie temp = db->movies[j];
                db->movies[j] = db->movies[j + 1];
                db->movies[j + 1] = temp;
            }
        }
    }
    printf("Movies sorted by rating in descending order!\n");
}

int main() {
    MovieDatabase db;
    initializeDatabase(&db);

    int choice;
    char title[NAME_LENGTH], genre[NAME_LENGTH];
    float rating;

    while (1) {
        printf("\n--- Movie Rating System ---\n");
        printf("1. Add Movie\n");
        printf("2. Display Movies\n");
        printf("3. Search Movie By Title\n");
        printf("4. Average Rating\n");
        printf("5. Sort Movies By Rating\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter movie title: ");
                scanf(" %[^\n]", title);
                printf("Enter movie genre: ");
                scanf(" %[^\n]", genre);
                printf("Enter movie rating (0.0 to 10.0): ");
                scanf("%f", &rating);
                addMovie(&db, title, genre, rating);
                break;

            case 2:
                displayMovies(&db);
                break;

            case 3:
                printf("Enter movie title to search: ");
                scanf(" %[^\n]", title);
                searchMovieByTitle(&db, title);
                break;

            case 4:
                averageRating(&db);
                break;

            case 5:
                sortMoviesByRating(&db);
                displayMovies(&db);
                break;

            case 6:
                printf("Exiting the program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice! Please enter a number between 1 and 6.\n");
        }
    }

    return 0;
}