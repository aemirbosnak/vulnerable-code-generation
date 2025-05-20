//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LEN 100
#define MAX_GENRE_LEN 50

typedef struct {
    char title[MAX_TITLE_LEN];
    char genre[MAX_GENRE_LEN];
    int year;
    float rating; // Scale 1.0 to 10.0
} Movie;

typedef struct {
    Movie movies[MAX_MOVIES];
    int count;
} MovieDatabase;

void addMovie(MovieDatabase *db) {
    if (db->count >= MAX_MOVIES) {
        printf("Movie database is full!\n");
        return;
    }
    Movie newMovie;
    printf("Enter movie title: ");
    getchar(); // To consume newline from previous input
    fgets(newMovie.title, MAX_TITLE_LEN, stdin);
    newMovie.title[strcspn(newMovie.title, "\n")] = 0; // Remove newline

    printf("Enter movie genre: ");
    fgets(newMovie.genre, MAX_GENRE_LEN, stdin);
    newMovie.genre[strcspn(newMovie.genre, "\n")] = 0; // Remove newline

    printf("Enter movie release year: ");
    scanf("%d", &newMovie.year);

    printf("Enter movie rating (1.0 - 10.0): ");
    scanf("%f", &newMovie.rating);
    
    // Validate rating
    while (newMovie.rating < 1.0 || newMovie.rating > 10.0) {
        printf("Invalid rating! Please enter a rating between 1.0 and 10.0: ");
        scanf("%f", &newMovie.rating);
    }

    db->movies[db->count++] = newMovie;
    printf("Movie added successfully!\n");
}

void listMovies(MovieDatabase *db) {
    if (db->count == 0) {
        printf("No movies available in the database.\n");
        return;
    }

    printf("\nList of Movies:\n");
    for (int i = 0; i < db->count; i++) {
        printf("Title: %s\n", db->movies[i].title);
        printf("Genre: %s\n", db->movies[i].genre);
        printf("Year: %d\n", db->movies[i].year);
        printf("Rating: %.1f\n", db->movies[i].rating);
        printf("-----------------------\n");
    }
}

void searchByTitle(MovieDatabase *db) {
    char title[MAX_TITLE_LEN];
    printf("Enter movie title to search: ");
    getchar(); // To consume newline from previous input
    fgets(title, MAX_TITLE_LEN, stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline

    for (int i = 0; i < db->count; i++) {
        if (strcmp(db->movies[i].title, title) == 0) {
            printf("Movie found!\n");
            printf("Title: %s\n", db->movies[i].title);
            printf("Genre: %s\n", db->movies[i].genre);
            printf("Year: %d\n", db->movies[i].year);
            printf("Rating: %.1f\n", db->movies[i].rating);
            return;
        }
    }
    printf("Movie not found.\n");
}

void rateMovie(MovieDatabase *db) {
    char title[MAX_TITLE_LEN];
    printf("Enter movie title to rate: ");
    getchar(); // To consume newline from previous input
    fgets(title, MAX_TITLE_LEN, stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline

    for (int i = 0; i < db->count; i++) {
        if (strcmp(db->movies[i].title, title) == 0) {
            float newRating;
            printf("Current rating is %.1f. Enter new rating (1.0 - 10.0): ", db->movies[i].rating);
            scanf("%f", &newRating);

            // Validate rating
            while (newRating < 1.0 || newRating > 10.0) {
                printf("Invalid rating! Please enter a rating between 1.0 and 10.0: ");
                scanf("%f", &newRating);
            }

            db->movies[i].rating = newRating;
            printf("Movie rating updated successfully!\n");
            return;
        }
    }
    printf("Movie not found.\n");
}

int main() {
    MovieDatabase db;
    db.count = 0;
    int choice;

    do {
        printf("\nMovie Rating System\n");
        printf("1. Add Movie\n");
        printf("2. List Movies\n");
        printf("3. Search Movie by Title\n");
        printf("4. Rate a Movie\n");
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
                searchByTitle(&db);
                break;
            case 4:
                rateMovie(&db);
                break;
            case 5:
                printf("Exiting... Thank you for using the Movie Rating System!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}