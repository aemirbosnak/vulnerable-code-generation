//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_REVIEW_LENGTH 500

typedef struct {
    char title[MAX_TITLE_LENGTH];
    float rating;
    char review[MAX_REVIEW_LENGTH];
} Movie;

typedef struct {
    Movie *movies;
    int count;
    int capacity;
} MovieDatabase;

void initializeDatabase(MovieDatabase *db) {
    db->count = 0;
    db->capacity = 10;
    db->movies = (Movie *)malloc(db->capacity * sizeof(Movie));
    if (db->movies == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
}

void freeDatabase(MovieDatabase *db) {
    free(db->movies);
}

void addMovie(MovieDatabase *db, const char *title, float rating, const char *review) {
    if (db->count == db->capacity) {
        db->capacity *= 2;
        db->movies = (Movie *)realloc(db->movies, db->capacity * sizeof(Movie));
        if (db->movies == NULL) {
            fprintf(stderr, "Memory reallocation failed!\n");
            exit(EXIT_FAILURE);
        }
    }
    strncpy(db->movies[db->count].title, title, MAX_TITLE_LENGTH);
    db->movies[db->count].rating = rating;
    strncpy(db->movies[db->count].review, review, MAX_REVIEW_LENGTH);
    db->count++;
}

void displayMovies(const MovieDatabase *db) {
    for (int i = 0; i < db->count; i++) {
        printf("Movie #%d:\n", i + 1);
        printf("Title: %s\n", db->movies[i].title);
        printf("Rating: %.1f/10\n", db->movies[i].rating);
        printf("Review: %s\n\n", db->movies[i].review);
    }
}

void deleteMovie(MovieDatabase *db, int index) {
    if (index < 0 || index >= db->count) {
        printf("Invalid index, cannot delete movie.\n");
        return;
    }
    for (int i = index; i < db->count - 1; i++) {
        db->movies[i] = db->movies[i + 1];
    }
    db->count--;
}

int main() {
    MovieDatabase db;
    initializeDatabase(&db);

    int choice;
    char title[MAX_TITLE_LENGTH];
    float rating;
    char review[MAX_REVIEW_LENGTH];

    while (1) {
        printf("Movie Rating System\n");
        printf("1. Add Movie\n");
        printf("2. Display Movies\n");
        printf("3. Delete Movie\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Clear newline

        switch (choice) {
            case 1:
                printf("Enter movie title: ");
                fgets(title, MAX_TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline
                
                printf("Enter movie rating (0-10): ");
                scanf("%f", &rating);
                getchar(); // Clear newline

                printf("Enter review: ");
                fgets(review, MAX_REVIEW_LENGTH, stdin);
                review[strcspn(review, "\n")] = 0; // Remove newline

                addMovie(&db, title, rating, review);
                break;
            case 2:
                displayMovies(&db);
                break;
            case 3:
                printf("Enter movie index to delete: ");
                int index;
                scanf("%d", &index);
                deleteMovie(&db, index - 1); // Convert to 0-based index
                break;
            case 4:
                freeDatabase(&db);
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid option. Please try again.\n");
        }
        printf("\n");
    }

    return 0;
}