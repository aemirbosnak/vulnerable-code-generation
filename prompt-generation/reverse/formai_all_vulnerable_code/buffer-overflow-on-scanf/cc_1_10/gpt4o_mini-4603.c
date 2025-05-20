//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define TITLE_LENGTH 100

typedef struct {
    char title[TITLE_LENGTH];
    float rating;
    int year;
} Movie;

typedef struct {
    Movie movies[MAX_MOVIES];
    int count;
} MovieDatabase;

void initialize_database(MovieDatabase *db) {
    db->count = 0;
}

void add_movie(MovieDatabase *db, const char *title, float rating, int year) {
    if (db->count < MAX_MOVIES) {
        strncpy(db->movies[db->count].title, title, TITLE_LENGTH);
        db->movies[db->count].rating = rating;
        db->movies[db->count].year = year;
        db->count++;
        printf("Movie added: %s (%d) with rating %.1f\n", title, year, rating);
    } else {
        printf("Database full! Cannot add more movies.\n");
    }
}

void display_movies(MovieDatabase *db) {
    if (db->count == 0) {
        printf("No movies in the database.\n");
        return;
    }

    printf("\nMovie List:\n");
    for (int i = 0; i < db->count; i++) {
        printf("Title: %s, Year: %d, Rating: %.1f\n", 
               db->movies[i].title, db->movies[i].year, db->movies[i].rating);
    }
}

void search_movie_by_title(MovieDatabase *db, const char *title) {
    int found = 0;
    for (int i = 0; i < db->count; i++) {
        if (strcasecmp(db->movies[i].title, title) == 0) {
            printf("Found movie: %s, Year: %d, Rating: %.1f\n", 
                   db->movies[i].title, db->movies[i].year, db->movies[i].rating);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Movie titled '%s' not found.\n", title);
    }
}

void delete_movie_by_title(MovieDatabase *db, const char *title) {
    int found = 0;
    for (int i = 0; i < db->count; i++) {
        if (strcasecmp(db->movies[i].title, title) == 0) {
            found = 1;
            for (int j = i; j < db->count - 1; j++) {
                db->movies[j] = db->movies[j + 1];
            }
            db->count--;
            printf("Movie '%s' deleted successfully.\n", title);
            break;
        }
    }
    if (!found) {
        printf("Movie titled '%s' not found. Cannot delete.\n", title);
    }
}

void rate_movie(MovieDatabase *db, const char *title, float new_rating) {
    int found = 0;
    for (int i = 0; i < db->count; i++) {
        if (strcasecmp(db->movies[i].title, title) == 0) {
            db->movies[i].rating = new_rating;
            printf("Updated rating for '%s' to %.1f\n", title, new_rating);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Movie titled '%s' not found. Cannot update rating.\n", title);
    }
}

void display_average_rating(MovieDatabase *db) {
    if (db->count == 0) {
        printf("No movies to calculate average rating.\n");
        return;
    }

    float total_rating = 0;
    for (int i = 0; i < db->count; i++) {
        total_rating += db->movies[i].rating;
    }
    float average = total_rating / db->count;
    printf("Average Movie Rating: %.1f\n", average);
}

int main() {
    MovieDatabase db;
    initialize_database(&db);
    int choice;
    char title[TITLE_LENGTH];
    float rating;
    int year;

    do {
        printf("\nMovie Rating System Menu:\n");
        printf("1. Add Movie\n");
        printf("2. Display Movies\n");
        printf("3. Search Movie by Title\n");
        printf("4. Delete Movie by Title\n");
        printf("5. Rate Movie\n");
        printf("6. Display Average Rating\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Consume newline character

        switch (choice) {
            case 1:
                printf("Enter movie title: ");
                fgets(title, TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = '\0'; // Remove newline
                printf("Enter movie rating (0-10): ");
                scanf("%f", &rating);
                printf("Enter movie release year: ");
                scanf("%d", &year);
                add_movie(&db, title, rating, year);
                break;
            case 2:
                display_movies(&db);
                break;
            case 3:
                printf("Enter movie title to search: ");
                fgets(title, TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = '\0'; // Remove newline
                search_movie_by_title(&db, title);
                break;
            case 4:
                printf("Enter movie title to delete: ");
                fgets(title, TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = '\0'; // Remove newline
                delete_movie_by_title(&db, title);
                break;
            case 5:
                printf("Enter movie title to rate: ");
                fgets(title, TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = '\0'; // Remove newline
                printf("Enter new rating: ");
                scanf("%f", &rating);
                rate_movie(&db, title, rating);
                break;
            case 6:
                display_average_rating(&db);
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}