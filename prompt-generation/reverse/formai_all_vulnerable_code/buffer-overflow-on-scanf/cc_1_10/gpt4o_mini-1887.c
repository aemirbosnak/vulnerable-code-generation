//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 100
#define MAX_GENRE_LENGTH 30
#define MAX_DESCRIPTION_LENGTH 256

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    int year;
    float rating;
    char description[MAX_DESCRIPTION_LENGTH];
} Movie;

typedef struct {
    Movie movies[MAX_MOVIES];
    int count;
} MovieDatabase;

void initializeDatabase(MovieDatabase *db) {
    db->count = 0;
}

void addMovie(MovieDatabase *db) {
    if (db->count >= MAX_MOVIES) {
        printf("Database is full! Can't add more movies.\n");
        return;
    }

    Movie new_movie;
    printf("Enter movie title: ");
    getchar();  // Remove newline character from previous input
    fgets(new_movie.title, MAX_TITLE_LENGTH, stdin);
    new_movie.title[strcspn(new_movie.title, "\n")] = 0; // Remove newline character

    printf("Enter movie genre: ");
    fgets(new_movie.genre, MAX_GENRE_LENGTH, stdin);
    new_movie.genre[strcspn(new_movie.genre, "\n")] = 0; // Remove newline character

    printf("Enter release year: ");
    scanf("%d", &new_movie.year);

    printf("Enter movie rating (0.0 to 10.0): ");
    scanf("%f", &new_movie.rating);

    printf("Enter movie description: ");
    getchar();  // Remove newline character from previous input
    fgets(new_movie.description, MAX_DESCRIPTION_LENGTH, stdin);
    new_movie.description[strcspn(new_movie.description, "\n")] = 0; // Remove newline character

    db->movies[db->count++] = new_movie;
    printf("Movie added successfully!\n");
}

void listMovies(MovieDatabase *db) {
    if (db->count == 0) {
        printf("No movies in the database!\n");
        return;
    }

    printf("\n--- Movie List ---\n");
    for (int i = 0; i < db->count; i++) {
        printf("Title: %s\n", db->movies[i].title);
        printf("Genre: %s\n", db->movies[i].genre);
        printf("Year: %d\n", db->movies[i].year);
        printf("Rating: %.1f\n", db->movies[i].rating);
        printf("Description: %s\n\n", db->movies[i].description);
    }
}

void searchMovieByTitle(MovieDatabase *db) {
    char title[MAX_TITLE_LENGTH];
    printf("Enter movie title to search: ");
    getchar();  // Remove newline character
    fgets(title, MAX_TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline character

    printf("\n--- Search Results ---\n");
    for (int i = 0; i < db->count; i++) {
        if (strcasecmp(db->movies[i].title, title) == 0) {
            printf("Title: %s\n", db->movies[i].title);
            printf("Genre: %s\n", db->movies[i].genre);
            printf("Year: %d\n", db->movies[i].year);
            printf("Rating: %.1f\n", db->movies[i].rating);
            printf("Description: %s\n\n", db->movies[i].description);
            return;
        }
    }
    printf("Movie not found in database.\n");
}

void filterMoviesByRating(MovieDatabase *db) {
    float minRating;
    printf("Enter minimum rating to filter: ");
    scanf("%f", &minRating);

    printf("\n--- Filter Results ---\n");
    int found = 0;
    for (int i = 0; i < db->count; i++) {
        if (db->movies[i].rating >= minRating) {
            printf("Title: %s\n", db->movies[i].title);
            printf("Genre: %s\n", db->movies[i].genre);
            printf("Year: %d\n", db->movies[i].year);
            printf("Rating: %.1f\n", db->movies[i].rating);
            printf("Description: %s\n\n", db->movies[i].description);
            found = 1;
        }
    }
    if (!found) {
        printf("No movies found with the rating %.1f or higher.\n", minRating);
    }
}

int main() {
    MovieDatabase db;
    initializeDatabase(&db);
    int choice;

    do {
        printf("\n--- Futuristic Movie Rating System ---\n");
        printf("1. Add Movie\n");
        printf("2. List Movies\n");
        printf("3. Search Movie by Title\n");
        printf("4. Filter Movies by Rating\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(&db);
                break;
            case 2:
                listMovies(&db);
                break;
            case 3:
                searchMovieByTitle(&db);
                break;
            case 4:
                filterMoviesByRating(&db);
                break;
            case 5:
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}