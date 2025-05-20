//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define TITLE_LENGTH 100
#define RATING_LENGTH 5

typedef struct {
    char title[TITLE_LENGTH];
    float rating;
    char genre[TITLE_LENGTH];
} Movie;

typedef struct {
    Movie movies[MAX_MOVIES];
    int count;
} MovieDatabase;

void initializeDatabase(MovieDatabase *db) {
    db->count = 0;
}

void addMovie(MovieDatabase *db, const char *title, float rating, const char *genre) {
    if (db->count < MAX_MOVIES) {
        strncpy(db->movies[db->count].title, title, TITLE_LENGTH);
        db->movies[db->count].rating = rating;
        strncpy(db->movies[db->count].genre, genre, TITLE_LENGTH);
        db->count++;
        printf("Movie Added: %s | Rating: %.1f | Genre: %s\n", title, rating, genre);
    } else {
        printf("Database is full! Cannot add more movies.\n");
    }
}

void displayMovies(MovieDatabase *db) {
    if (db->count == 0) {
        printf("No movies found in the database.\n");
        return;
    }
    
    printf("\n--- Movie Database ---\n");
    for (int i = 0; i < db->count; i++) {
        printf("Title: %s | Rating: %.1f | Genre: %s\n",
               db->movies[i].title,
               db->movies[i].rating,
               db->movies[i].genre);
    }
}

void searchMovieByTitle(MovieDatabase *db, const char *title) {
    for (int i = 0; i < db->count; i++) {
        if (strcasecmp(db->movies[i].title, title) == 0) {
            printf("Found Movie: %s | Rating: %.1f | Genre: %s\n",
                   db->movies[i].title,
                   db->movies[i].rating,
                   db->movies[i].genre);
            return;
        }
    }
    printf("Movie titled '%s' not found in the database.\n", title);
}

void deleteMovie(MovieDatabase *db, const char *title) {
    int found = 0;
    for (int i = 0; i < db->count; i++) {
        if (strcasecmp(db->movies[i].title, title) == 0) {
            found = 1;
            for (int j = i; j < db->count - 1; j++) {
                db->movies[j] = db->movies[j + 1];
            }
            db->count--;
            printf("Movie '%s' removed from the database.\n", title);
            break;
        }
    }
    if (!found) {
        printf("Movie titled '%s' not found in the database.\n", title);
    }
}

void displayHighestRatedMovie(MovieDatabase *db) {
    if (db->count == 0) {
        printf("No movies to evaluate.\n");
        return;
    }
    
    Movie highestRated = db->movies[0];
    for (int i = 1; i < db->count; i++) {
        if (db->movies[i].rating > highestRated.rating) {
            highestRated = db->movies[i];
        }
    }
    
    printf("Highest Rated Movie: %s | Rating: %.1f | Genre: %s\n",
           highestRated.title,
           highestRated.rating,
           highestRated.genre);
}

int main() {
    MovieDatabase db;
    initializeDatabase(&db);
    
    int choice;
    char title[TITLE_LENGTH];
    float rating;
    char genre[TITLE_LENGTH];

    while (1) {
        printf("\n----- Movie Rating System -----\n");
        printf("1. Add Movie\n");
        printf("2. Search Movie by Title\n");
        printf("3. Delete Movie\n");
        printf("4. Display All Movies\n");
        printf("5. Display Highest Rated Movie\n");
        printf("6. Exit\n");
        printf("Choose an option (1-6): ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                printf("Enter movie title: ");
                fgets(title, TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline
                printf("Enter movie rating (0.0 - 10.0): ");
                scanf("%f", &rating);
                getchar(); // Consume newline character
                printf("Enter movie genre: ");
                fgets(genre, TITLE_LENGTH, stdin);
                genre[strcspn(genre, "\n")] = 0; // Remove newline
                addMovie(&db, title, rating, genre);
                break;

            case 2:
                printf("Enter movie title to search: ");
                fgets(title, TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline
                searchMovieByTitle(&db, title);
                break;

            case 3:
                printf("Enter movie title to delete: ");
                fgets(title, TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline
                deleteMovie(&db, title);
                break;

            case 4:
                displayMovies(&db);
                break;

            case 5:
                displayHighestRatedMovie(&db);
                break;

            case 6:
                printf("Exiting the program...\n");
                exit(0);

            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}