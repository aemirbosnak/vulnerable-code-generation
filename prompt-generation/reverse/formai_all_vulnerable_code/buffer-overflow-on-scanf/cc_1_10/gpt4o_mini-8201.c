//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 100
#define MAX_GENRE_LENGTH 30
#define MAX_RATING_LENGTH 10

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    char rating[MAX_RATING_LENGTH];
} Movie;

void displayMenu() {
    printf("\n=============================\n");
    printf("   CYBERPUNK MOVIE RATING    \n");
    printf("=============================\n");
    printf("1. Add Movie\n");
    printf("2. Display Movies\n");
    printf("3. Search by Genre\n");
    printf("4. Rate a Movie\n");
    printf("5. Exit\n");
    printf("=============================\n");
    printf("Select an option: ");
}

int addMovie(Movie *movies, int *movieCount) {
    if (*movieCount >= MAX_MOVIES) {
        printf("Database full. Can't add more movies!\n");
        return 0;
    }

    printf("Enter movie title: ");
    getchar();  // Clear previous input buffer
    fgets(movies[*movieCount].title, MAX_TITLE_LENGTH, stdin);
    movies[*movieCount].title[strcspn(movies[*movieCount].title, "\n")] = 0; // Remove newline

    printf("Enter movie genre: ");
    fgets(movies[*movieCount].genre, MAX_GENRE_LENGTH, stdin);
    movies[*movieCount].genre[strcspn(movies[*movieCount].genre, "\n")] = 0; // Remove newline

    strcpy(movies[*movieCount].rating, "Unrated");

    (*movieCount)++;
    printf("Movie added successfully!\n");
    return 1;
}

void displayMovies(Movie *movies, int movieCount) {
    if (movieCount == 0) {
        printf("No movies available in the database.\n");
        return;
    }

    printf("\n=== MOVIE DATABASE ===\n");
    for (int i = 0; i < movieCount; i++) {
        printf("Title: %s\n", movies[i].title);
        printf("Genre: %s\n", movies[i].genre);
        printf("Rating: %s\n", movies[i].rating);
        printf("---------------------\n");
    }
}

void searchByGenre(Movie *movies, int movieCount) {
    if (movieCount == 0) {
        printf("No movies available in the database.\n");
        return;
    }

    char genre[MAX_GENRE_LENGTH];
    printf("Enter genre to search: ");
    getchar(); // Clear previous input buffer
    fgets(genre, MAX_GENRE_LENGTH, stdin);
    genre[strcspn(genre, "\n")] = 0; // Remove newline

    printf("\n=== SEARCH RESULTS ===\n");
    int found = 0;
    for (int i = 0; i < movieCount; i++) {
        if (strcasecmp(movies[i].genre, genre) == 0) {
            found = 1;
            printf("Title: %s\n", movies[i].title);
            printf("Rating: %s\n", movies[i].rating);
            printf("---------------------\n");
        }
    }
    if (!found) {
        printf("No movies found for genre: %s\n", genre);
    }
}

void rateMovie(Movie *movies, int movieCount) {
    if (movieCount == 0) {
        printf("No movies available in the database.\n");
        return;
    }

    char title[MAX_TITLE_LENGTH];
    printf("Enter movie title to rate: ");
    getchar(); // Clear previous input buffer
    fgets(title, MAX_TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline

    for (int i = 0; i < movieCount; i++) {
        if (strcasecmp(movies[i].title, title) == 0) {
            char rating[MAX_RATING_LENGTH];
            printf("Enter new rating (e.g., 8.5): ");
            fgets(rating, MAX_RATING_LENGTH, stdin);
            rating[strcspn(rating, "\n")] = 0; // Remove newline
            strcpy(movies[i].rating, rating);
            printf("Rating updated for %s!\n", movies[i].title);
            return;
        }
    }
    printf("Movie not found: %s\n", title);
}

int main() {
    Movie movies[MAX_MOVIES];
    int movieCount = 0;
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1: addMovie(movies, &movieCount); break;
            case 2: displayMovies(movies, movieCount); break;
            case 3: searchByGenre(movies, movieCount); break;
            case 4: rateMovie(movies, movieCount); break;
            case 5: printf("Exiting the Cyberpunk Movie Rating System...\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}