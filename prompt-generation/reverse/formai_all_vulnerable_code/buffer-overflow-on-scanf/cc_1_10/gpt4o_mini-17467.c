//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 50

typedef struct {
    char title[MAX_TITLE_LENGTH];
    float rating;
} Movie;

typedef struct {
    Movie movie_list[MAX_MOVIES];
    int count;
} MovieDatabase;

void initialize_database(MovieDatabase *db) {
    db->count = 0;
}

void add_movie(MovieDatabase *db, const char *title, float rating) {
    if (db->count < MAX_MOVIES) {
        strcpy(db->movie_list[db->count].title, title);
        db->movie_list[db->count].rating = rating;
        db->count++;
    } else {
        printf("Movie database is full!\n");
    }
}

void display_movies(const MovieDatabase *db) {
    if (db->count == 0) {
        printf("No movies available in the database.\n");
        return;
    }

    printf("%-30s  Rating\n", "Title");
    printf("----------------------------------------\n");
    for (int i = 0; i < db->count; i++) {
        printf("%-30s  %.1f\n", db->movie_list[i].title, db->movie_list[i].rating);
    }
}

void search_movie(const MovieDatabase *db, const char *title) {
    for (int i = 0; i < db->count; i++) {
        if (strcmp(db->movie_list[i].title, title) == 0) {
            printf("Found: %s has a rating of %.1f\n", db->movie_list[i].title, db->movie_list[i].rating);
            return;
        }
    }
    printf("Movie \"%s\" not found in the database.\n", title);
}

void rate_movie(MovieDatabase *db, const char *title, float new_rating) {
    for (int i = 0; i < db->count; i++) {
        if (strcmp(db->movie_list[i].title, title) == 0) {
            db->movie_list[i].rating = new_rating;
            printf("Updated: %s new rating is %.1f\n", db->movie_list[i].title, new_rating);
            return;
        }
    }
    printf("Movie \"%s\" not found to update the rating.\n", title);
}

void remove_movie(MovieDatabase *db, const char *title) {
    for (int i = 0; i < db->count; i++) {
        if (strcmp(db->movie_list[i].title, title) == 0) {
            db->movie_list[i] = db->movie_list[db->count - 1]; // Replace with last movie
            db->count--;
            printf("Removed movie: %s\n", title);
            return;
        }
    }
    printf("Movie \"%s\" not found to remove.\n", title);
}

int main() {
    MovieDatabase db;
    initialize_database(&db);

    int choice;
    char title[MAX_TITLE_LENGTH];
    float rating;

    do {
        printf("\nMovie Rating System\n");
        printf("1. Add Movie\n");
        printf("2. Display Movies\n");
        printf("3. Search Movie\n");
        printf("4. Rate Movie\n");
        printf("5. Remove Movie\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                printf("Enter movie title: ");
                fgets(title, MAX_TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline character
                printf("Enter movie rating (0.0 - 10.0): ");
                scanf("%f", &rating);
                if (rating < 0.0 || rating > 10.0) {
                    printf("Invalid rating. Please enter a rating between 0.0 and 10.0.\n");
                } else {
                    add_movie(&db, title, rating);
                    printf("Movie added successfully!\n");
                }
                break;

            case 2:
                display_movies(&db);
                break;

            case 3:
                printf("Enter movie title to search: ");
                fgets(title, MAX_TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline character
                search_movie(&db, title);
                break;

            case 4:
                printf("Enter movie title to rate: ");
                fgets(title, MAX_TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline character
                printf("Enter new rating (0.0 - 10.0): ");
                scanf("%f", &rating);
                rate_movie(&db, title, rating);
                break;

            case 5:
                printf("Enter movie title to remove: ");
                fgets(title, MAX_TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline character
                remove_movie(&db, title);
                break;

            case 6:
                printf("Exiting the Movie Rating System. Farewell!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}