//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define TITLE_LENGTH 100

typedef struct {
    char title[TITLE_LENGTH];
    int rating; // Rating out of 10
} Movie;

typedef struct {
    Movie movies[MAX_MOVIES];
    int count;
} MovieDB;

void initializeDB(MovieDB* db) {
    db->count = 0;
}

void addMovie(MovieDB* db) {
    if (db->count < MAX_MOVIES) {
        Movie new_movie;
        printf("Enter movie title: ");
        getchar(); // to consume the newline character
        fgets(new_movie.title, TITLE_LENGTH, stdin);
        new_movie.title[strcspn(new_movie.title, "\n")] = 0; // Remove newline
        printf("Enter movie rating (0-10): ");
        scanf("%d", &new_movie.rating);

        if (new_movie.rating < 0 || new_movie.rating > 10) {
            printf("Invalid rating! Rating should be between 0 and 10.\n");
            return;
        }

        db->movies[db->count] = new_movie;
        db->count++;
        printf("Movie added successfully!\n");
    } else {
        printf("Movie database is full!\n");
    }
}

void displayMovies(const MovieDB* db) {
    if (db->count == 0) {
        printf("No movies in the database.\n");
        return;
    }
    
    printf("\n--- Movie List ---\n");
    for (int i = 0; i < db->count; i++) {
        printf("Title: %s | Rating: %d/10\n", db->movies[i].title, db->movies[i].rating);
    }
}

void averageRating(const MovieDB* db) {
    if (db->count == 0) {
        printf("No movies to rate.\n");
        return;
    }

    int totalRating = 0;
    for (int i = 0; i < db->count; i++) {
        totalRating += db->movies[i].rating;
    }

    float average = (float)totalRating / db->count;
    printf("Average Rating: %.2f/10\n", average);
}

void menu() {
    printf("\n--- Movie Rating System ---\n");
    printf("1. Add Movie\n");
    printf("2. Display Movies\n");
    printf("3. Calculate Average Rating\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    MovieDB movie_db;
    initializeDB(&movie_db);
    int option;

    while (1) {
        menu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                addMovie(&movie_db);
                break;
            case 2:
                displayMovies(&movie_db);
                break;
            case 3:
                averageRating(&movie_db);
                break;
            case 4:
                printf("Exiting the Movie Rating System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}