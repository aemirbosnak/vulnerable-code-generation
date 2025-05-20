//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 100
#define MAX_REVIEW_LENGTH 256

typedef struct {
    char title[MAX_TITLE_LENGTH];
    int year;
    int rating; // 0 to 5 stars
    char review[MAX_REVIEW_LENGTH];
} Movie;

typedef struct {
    Movie movies[MAX_MOVIES];
    int count;
} MovieDatabase;

void initDatabase(MovieDatabase *db) {
    db->count = 0;
}

void addMovie(MovieDatabase *db, const char *title, int year, int rating, const char *review) {
    if (db->count < MAX_MOVIES) {
        strncpy(db->movies[db->count].title, title, MAX_TITLE_LENGTH);
        db->movies[db->count].year = year;
        db->movies[db->count].rating = rating;
        strncpy(db->movies[db->count].review, review, MAX_REVIEW_LENGTH);
        db->count++;
    } else {
        printf("The last movie store is full. Cannot add more movies!\n");
    }
}

void displayMovies(const MovieDatabase *db) {
    if (db->count == 0) {
        printf("No movies found in this desolate wasteland.\n");
        return;
    }
    printf("---- Survivors' Movie List ----\n");
    for (int i = 0; i < db->count; i++) {
        printf("Title: %s\n", db->movies[i].title);
        printf("Year: %d\n", db->movies[i].year);
        printf("Rating: %d/5\n", db->movies[i].rating);
        printf("Review: %s\n", db->movies[i].review);
        printf("-------------------------------\n");
    }
}

void searchMovie(const MovieDatabase *db, const char *title) {
    int found = 0;
    for (int i = 0; i < db->count; i++) {
        if (strcasecmp(db->movies[i].title, title) == 0) {
            printf("Found Movie - Title: %s, Year: %d, Rating: %d/5, Review: %s\n", 
                   db->movies[i].title, db->movies[i].year, db->movies[i].rating, db->movies[i].review);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("The movie '%s' cannot be found amidst the ruins.\n", title);
    }
}

void deleteMovie(MovieDatabase *db, const char *title) {
    for (int i = 0; i < db->count; i++) {
        if (strcasecmp(db->movies[i].title, title) == 0) {
            for (int j = i; j < db->count - 1; j++) {
                db->movies[j] = db->movies[j + 1];
            }
            db->count--;
            printf("The movie '%s' has been erased from memory.\n", title);
            return;
        }
    }
    printf("The movie '%s' cannot be deleted; it’s not part of the survivors’ records.\n", title);
}

void saveDatabase(const MovieDatabase *db, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Creature of the night! Cannot open the file to save movies!\n");
        return;
    }
    fwrite(db, sizeof(MovieDatabase), 1, file);
    fclose(file);
    printf("All records saved securely beneath the moonlight.\n");
}

void loadDatabase(MovieDatabase *db, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("The archive is empty, but you can still add more movies to the ledger.\n");
        return;
    }
    fread(db, sizeof(MovieDatabase), 1, file);
    fclose(file);
    printf("Movieland database loaded under the cover of darkness.\n");
}

int main() {
    MovieDatabase db;
    initDatabase(&db);
    loadDatabase(&db, "movies.dat");

    char command[50];
    char title[MAX_TITLE_LENGTH];
    int year, rating;
    char review[MAX_REVIEW_LENGTH];

    while (1) {
        printf("Enter a command (add, display, search, delete, save, exit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Enter movie title: ");
            scanf(" %[^\n]s", title);
            printf("Enter release year: ");
            scanf("%d", &year);
            printf("Enter rating (0 to 5): ");
            scanf("%d", &rating);
            printf("Enter review: ");
            scanf(" %[^\n]s", review);
            addMovie(&db, title, year, rating, review);
        } else if (strcmp(command, "display") == 0) {
            displayMovies(&db);
        } else if (strcmp(command, "search") == 0) {
            printf("Enter movie title to search: ");
            scanf(" %[^\n]s", title);
            searchMovie(&db, title);
        } else if (strcmp(command, "delete") == 0) {
            printf("Enter movie title to delete: ");
            scanf(" %[^\n]s", title);
            deleteMovie(&db, title);
        } else if (strcmp(command, "save") == 0) {
            saveDatabase(&db, "movies.dat");
        } else if (strcmp(command, "exit") == 0) {
            printf("Retreat into the shadows. Farewell!\n");
            break;
        } else {
            printf("Unknown command. The wasteland has many mysteries.\n");
        }
    }
    
    return 0;
}