//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define TITLE_LENGTH 100
#define GENRE_LENGTH 50

typedef struct {
    char title[TITLE_LENGTH];
    char genre[GENRE_LENGTH];
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
        strncpy(db->movies[db->count].title, title, TITLE_LENGTH);
        strncpy(db->movies[db->count].genre, genre, GENRE_LENGTH);
        db->movies[db->count].rating = rating;
        db->count++;
    } else {
        printf("Database is full! Cannot add more movies.\n");
    }
}

void displayMovies(const MovieDatabase *db) {
    printf("\n------ Movie List ------\n");
    for (int i = 0; i < db->count; i++) {
        printf("Title: %s\n", db->movies[i].title);
        printf("Genre: %s\n", db->movies[i].genre);
        printf("Rating: %.1f\n", db->movies[i].rating);
        printf("------------------------\n");
    }
}

void searchMovieByTitle(const MovieDatabase *db, const char *title) {
    int found = 0;
    for (int i = 0; i < db->count; i++) {
        if (strcasecmp(db->movies[i].title, title) == 0) {
            printf("Found Movie:\n");
            printf("Title: %s\n", db->movies[i].title);
            printf("Genre: %s\n", db->movies[i].genre);
            printf("Rating: %.1f\n", db->movies[i].rating);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Movie with title '%s' not found!\n", title);
    }
}

void editMovieRating(MovieDatabase *db, const char *title, float newRating) {
    for (int i = 0; i < db->count; i++) {
        if (strcasecmp(db->movies[i].title, title) == 0) {
            db->movies[i].rating = newRating;
            printf("Updated rating for '%s' to %.1f\n", title, newRating);
            return;
        }
    }
    printf("Movie with title '%s' not found!\n", title);
}

void saveDatabaseToFile(const MovieDatabase *db, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error opening file");
        return;
    }
    fwrite(db, sizeof(MovieDatabase), 1, file);
    fclose(file);
    printf("Database saved to '%s'\n", filename);
}

void loadDatabaseFromFile(MovieDatabase *db, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return;
    }
    fread(db, sizeof(MovieDatabase), 1, file);
    fclose(file);
    printf("Database loaded from '%s'\n", filename);
}

int main() {
    MovieDatabase db;
    initializeDatabase(&db);

    int choice;
    char title[TITLE_LENGTH], genre[GENRE_LENGTH];
    float rating;
    char filename[100];

    while (1) {
        printf("\n--- Movie Rating System Menu ---\n");
        printf("1. Add Movie\n");
        printf("2. Display Movies\n");
        printf("3. Search Movie\n");
        printf("4. Edit Movie Rating\n");
        printf("5. Save Database\n");
        printf("6. Load Database\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Clear newline character from buffer

        switch (choice) {
            case 1:
                printf("Enter Movie Title: ");
                fgets(title, TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline character
                printf("Enter Genre: ");
                fgets(genre, GENRE_LENGTH, stdin);
                genre[strcspn(genre, "\n")] = 0; // Remove newline character
                printf("Enter Rating (0.0 to 10.0): ");
                scanf("%f", &rating);
                addMovie(&db, title, genre, rating);
                break;

            case 2:
                displayMovies(&db);
                break;

            case 3:
                printf("Enter Movie Title to Search: ");
                fgets(title, TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline character
                searchMovieByTitle(&db, title);
                break;

            case 4:
                printf("Enter Movie Title to Edit: ");
                fgets(title, TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline character
                printf("Enter New Rating: ");
                scanf("%f", &rating);
                editMovieRating(&db, title, rating);
                break;

            case 5:
                printf("Enter filename to save database: ");
                scanf("%s", filename);
                saveDatabaseToFile(&db, filename);
                break;

            case 6:
                printf("Enter filename to load database: ");
                scanf("%s", filename);
                loadDatabaseFromFile(&db, filename);
                break;

            case 7:
                printf("Exiting the program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}