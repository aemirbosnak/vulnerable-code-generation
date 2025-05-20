//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: retro
#include <stdio.h>
#include <string.h>

#define MAX_MOVIES 100
#define TITLE_LENGTH 50
#define RATING_LENGTH 5

struct Movie {
    char title[TITLE_LENGTH];
    char rating[RATING_LENGTH];
};

void displayMenu();
void addMovie(struct Movie movies[], int *movieCount);
void displayMovies(struct Movie movies[], int movieCount);
void searchMovie(struct Movie movies[], int movieCount);
void rateMovie(struct Movie movies[], int movieCount);
void clearBuffer();

int main() {
    struct Movie movies[MAX_MOVIES];
    int movieCount = 0;
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
            case 1:
                addMovie(movies, &movieCount);
                break;
            case 2:
                displayMovies(movies, movieCount);
                break;
            case 3:
                searchMovie(movies, movieCount);
                break;
            case 4:
                rateMovie(movies, movieCount);
                break;
            case 0:
                printf("Exiting... Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

void displayMenu() {
    printf("\n========================\n");
    printf("    Retro Movie Rater   \n");
    printf("========================\n");
    printf("1. Add Movie\n");
    printf("2. Display Movies\n");
    printf("3. Search Movie\n");
    printf("4. Rate Movie\n");
    printf("0. Exit\n");
    printf("========================\n");
}

void addMovie(struct Movie movies[], int *movieCount) {
    if (*movieCount >= MAX_MOVIES) {
        printf("Movie list is full! Cannot add more movies.\n");
        return;
    }

    struct Movie newMovie;
    printf("Enter movie title: ");
    fgets(newMovie.title, TITLE_LENGTH, stdin);
    newMovie.title[strcspn(newMovie.title, "\n")] = 0; // Remove trailing newline

    printf("Enter movie rating (e.g., A, B, C, D, F): ");
    fgets(newMovie.rating, RATING_LENGTH, stdin);
    newMovie.rating[strcspn(newMovie.rating, "\n")] = 0; // Remove trailing newline

    movies[*movieCount] = newMovie;
    (*movieCount)++;
    printf("Movie '%s' added with rating '%s'.\n", newMovie.title, newMovie.rating);
}

void displayMovies(struct Movie movies[], int movieCount) {
    if (movieCount == 0) {
        printf("No movies to display.\n");
        return;
    }

    printf("\nList of Movies:\n");
    for (int i = 0; i < movieCount; i++) {
        printf("%d. %s - Rating: %s\n", i + 1, movies[i].title, movies[i].rating);
    }
}

void searchMovie(struct Movie movies[], int movieCount) {
    if (movieCount == 0) {
        printf("No movies to search.\n");
        return;
    }

    char searchTitle[TITLE_LENGTH];
    printf("Enter movie title to search: ");
    fgets(searchTitle, TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // Remove trailing newline

    int found = 0;
    for (int i = 0; i < movieCount; i++) {
        if (strcasecmp(movies[i].title, searchTitle) == 0) {
            printf("Movie Found: %s - Rating: %s\n", movies[i].title, movies[i].rating);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Movie '%s' not found in the list.\n", searchTitle);
    }
}

void rateMovie(struct Movie movies[], int movieCount) {
    if (movieCount == 0) {
        printf("No movies to rate.\n");
        return;
    }

    char title[TITLE_LENGTH];
    printf("Enter movie title to rate: ");
    fgets(title, TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = 0; // Remove trailing newline

    for (int i = 0; i < movieCount; i++) {
        if (strcasecmp(movies[i].title, title) == 0) {
            printf("Current rating of '%s' is '%s'.\n", movies[i].title, movies[i].rating);
            printf("Enter new rating (e.g., A, B, C, D, F): ");
            fgets(movies[i].rating, RATING_LENGTH, stdin);
            movies[i].rating[strcspn(movies[i].rating, "\n")] = 0; // Remove trailing newline
            printf("Rating updated to '%s'.\n", movies[i].rating);
            return;
        }
    }

    printf("Movie '%s' not found in the list.\n", title);
}

void clearBuffer() {
    while (getchar() != '\n');
}