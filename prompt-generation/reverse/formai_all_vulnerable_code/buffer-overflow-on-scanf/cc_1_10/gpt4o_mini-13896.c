//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 100
#define MAX_GENRE_LENGTH 50

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char genre[MAX_GENRE_LENGTH];
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
        strncpy(db->movies[db->count].title, title, MAX_TITLE_LENGTH);
        strncpy(db->movies[db->count].genre, genre, MAX_GENRE_LENGTH);
        db->movies[db->count].rating = rating;
        db->count++;
    } else {
        printf("Movie database is full!\n");
    }
}

void displayMovies(const MovieDatabase *db) {
    printf("\n----- Movie Database -----\n");
    for (int i = 0; i < db->count; i++) {
        printf("Title: %s\n", db->movies[i].title);
        printf("Genre: %s\n", db->movies[i].genre);
        printf("Rating: %.1f\n", db->movies[i].rating);
        printf("-------------------------------\n");
    }
}

void displayAverageRating(const MovieDatabase *db) {
    if (db->count == 0) {
        printf("No movies in the database.\n");
        return;
    }
    
    float totalRating = 0.0;
    for (int i = 0; i < db->count; i++) {
        totalRating += db->movies[i].rating;
    }

    float average = totalRating / db->count;
    printf("Average Rating: %.1f\n", average);
}

void searchByGenre(const MovieDatabase *db, const char *genre) {
    int found = 0;
    printf("\n----- Movies in Genre: %s -----\n", genre);
    for (int i = 0; i < db->count; i++) {
        if (strcmp(db->movies[i].genre, genre) == 0) {
            printf("Title: %s, Rating: %.1f\n", db->movies[i].title, db->movies[i].rating);
            found = 1;
        }
    }
    if (!found) {
        printf("No movies found in this genre.\n");
    }
}

int main() {
    MovieDatabase db;
    initializeDatabase(&db);
    
    int choice;
    char title[MAX_TITLE_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    float rating;

    do {
        printf("\n----- Movie Rating System -----\n");
        printf("1. Add Movie\n");
        printf("2. Display Movies\n");
        printf("3. Display Average Rating\n");
        printf("4. Search Movies by Genre\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline after the choice

        switch (choice) {
            case 1:
                printf("Enter movie title: ");
                fgets(title, MAX_TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline character
                printf("Enter movie genre: ");
                fgets(genre, MAX_GENRE_LENGTH, stdin);
                genre[strcspn(genre, "\n")] = 0; // Remove newline character
                printf("Enter movie rating (0.0 to 10.0): ");
                scanf("%f", &rating);

                // Input validation
                if (rating < 0.0 || rating > 10.0) {
                    printf("Invalid rating! It must be between 0.0 and 10.0.\n");
                    break;
                }
                
                addMovie(&db, title, genre, rating);
                break;

            case 2:
                displayMovies(&db);
                break;

            case 3:
                displayAverageRating(&db);
                break;

            case 4:
                printf("Enter genre to search: ");
                fgets(genre, MAX_GENRE_LENGTH, stdin);
                genre[strcspn(genre, "\n")] = 0; // Remove newline character
                searchByGenre(&db, genre);
                break;

            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Please choose again.\n");
        }
    } while (choice != 5);
    
    return 0;
}