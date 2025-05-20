//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define NAME_LENGTH 100

typedef struct {
    char title[NAME_LENGTH];
    char director[NAME_LENGTH];
    float rating;
} Movie;

typedef struct {
    Movie movies[MAX_MOVIES];
    int count;
} MovieDatabase;

// Function prototypes
void addMovie(MovieDatabase *db);
void displayMovies(const MovieDatabase *db);
void rateMovie(MovieDatabase *db);
void displayMenu();
void clearBuffer();

int main() {
    MovieDatabase db;
    db.count = 0;
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer(); // Clear the input buffer

        switch (choice) {
            case 1:
                addMovie(&db);
                break;
            case 2:
                displayMovies(&db);
                break;
            case 3:
                rateMovie(&db);
                break;
            case 4:
                printf("Exiting the Movie Rating System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void displayMenu() {
    printf("Welcome to the Movie Rating System\n");
    printf("1. Add a Movie\n");
    printf("2. Display Movies\n");
    printf("3. Rate a Movie\n");
    printf("4. Exit\n");
}

void clearBuffer() {
    // Clear any extra input in the buffer
    while (getchar() != '\n');
}

void addMovie(MovieDatabase *db) {
    if (db->count >= MAX_MOVIES) {
        printf("Movie database is full. Cannot add more movies.\n");
        return;
    }

    Movie newMovie;
    printf("Enter movie title: ");
    fgets(newMovie.title, NAME_LENGTH, stdin);
    newMovie.title[strcspn(newMovie.title, "\n")] = 0; // Remove newline character

    printf("Enter director name: ");
    fgets(newMovie.director, NAME_LENGTH, stdin);
    newMovie.director[strcspn(newMovie.director, "\n")] = 0; // Remove newline character

    printf("Enter initial rating (0.0 - 10.0): ");
    scanf("%f", &newMovie.rating);
    clearBuffer();  // Clear buffer after reading float

    if (newMovie.rating < 0.0 || newMovie.rating > 10.0) {
        printf("Invalid rating. Please enter a value between 0.0 and 10.0.\n");
        return;
    }

    db->movies[db->count++] = newMovie;
    printf("Movie added successfully!\n");
}

void displayMovies(const MovieDatabase *db) {
    if (db->count == 0) {
        printf("No movies in the database.\n");
        return;
    }

    printf("Movies in the Database:\n");
    for (int i = 0; i < db->count; i++) {
        printf("(%d) Title: %s, Director: %s, Rating: %.2f\n",
               i + 1, db->movies[i].title, db->movies[i].director, db->movies[i].rating);
    }
}

void rateMovie(MovieDatabase *db) {
    if (db->count == 0) {
        printf("No movies available to rate.\n");
        return;
    }

    int movieIndex;
    printf("Enter the movie number you want to rate (1 to %d): ", db->count);
    scanf("%d", &movieIndex);
    clearBuffer(); // Clear buffer after reading index

    if (movieIndex < 1 || movieIndex > db->count) {
        printf("Invalid movie number. Please try again.\n");
        return;
    }

    printf("Current rating of '%s': %.2f\n", db->movies[movieIndex - 1].title,
           db->movies[movieIndex - 1].rating);
    printf("Enter new rating (0.0 - 10.0): ");
    float newRating;
    scanf("%f", &newRating);
    clearBuffer(); // Clear buffer after reading float

    if (newRating < 0.0 || newRating > 10.0) {
        printf("Invalid rating. Please enter a value between 0.0 and 10.0.\n");
        return;
    }

    db->movies[movieIndex - 1].rating = newRating;
    printf("Rating updated successfully!\n");
}