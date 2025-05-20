//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define TITLE_LENGTH 100
#define RATING_LENGTH 10
#define REVIEW_LENGTH 500

typedef struct {
    char title[TITLE_LENGTH];
    char rating[RATING_LENGTH];
    char review[REVIEW_LENGTH];
} Movie;

void addMovie(Movie *movies, int *movieCount) {
    if (*movieCount >= MAX_MOVIES) {
        printf("Movie list is full!\n");
        return;
    }

    printf("Enter movie title: ");
    fgets(movies[*movieCount].title, TITLE_LENGTH, stdin);
    movies[*movieCount].title[strcspn(movies[*movieCount].title, "\n")] = 0; // Remove newline

    printf("Enter movie rating (e.g., A+, B, C-): ");
    fgets(movies[*movieCount].rating, RATING_LENGTH, stdin);
    movies[*movieCount].rating[strcspn(movies[*movieCount].rating, "\n")] = 0; // Remove newline

    printf("Enter your review: ");
    fgets(movies[*movieCount].review, REVIEW_LENGTH, stdin);
    movies[*movieCount].review[strcspn(movies[*movieCount].review, "\n")] = 0; // Remove newline

    (*movieCount)++;
    printf("Movie added successfully!\n");
}

void displayMovies(Movie *movies, int movieCount) {
    if (movieCount == 0) {
        printf("No movies to display.\n");
        return;
    }

    printf("\nList of Movies:\n");
    for (int i = 0; i < movieCount; i++) {
        printf("%d. Title: %s\n", i + 1, movies[i].title);
        printf("   Rating: %s\n", movies[i].rating);
        printf("   Review: %s\n\n", movies[i].review);
    }
}

void deleteMovie(Movie *movies, int *movieCount) {
    if (*movieCount == 0) {
        printf("No movies to delete.\n");
        return;
    }

    displayMovies(movies, *movieCount);
    printf("Enter the number of the movie to delete: ");
    int index;
    scanf("%d", &index);
    getchar(); // consume newline

    if (index < 1 || index > *movieCount) {
        printf("Invalid selection.\n");
    } else {
        for (int i = index - 1; i < *movieCount - 1; i++) {
            movies[i] = movies[i + 1];
        }
        (*movieCount)--;
        printf("Movie deleted successfully.\n");
    }
}

void searchMovie(Movie *movies, int movieCount) {
    if (movieCount == 0) {
        printf("No movies to search.\n");
        return;
    }

    char searchTerm[TITLE_LENGTH];
    printf("Enter movie title to search: ");
    fgets(searchTerm, TITLE_LENGTH, stdin);
    searchTerm[strcspn(searchTerm, "\n")] = 0; // Remove newline

    int found = 0;
    printf("\nSearch Results:\n");
    for (int i = 0; i < movieCount; i++) {
        if (strstr(movies[i].title, searchTerm) != NULL) {
            printf("%d. Title: %s\n", i + 1, movies[i].title);
            printf("   Rating: %s\n", movies[i].rating);
            printf("   Review: %s\n\n", movies[i].review);
            found = 1;
        }
    }
    if (!found) {
        printf("No movies found matching \"%s\".\n", searchTerm);
    }
}

int main() {
    Movie movies[MAX_MOVIES];
    int movieCount = 0;
    int choice;

    while (1) {
        printf("\n--- Movie Rating System ---\n");
        printf("1. Add Movie\n");
        printf("2. Display Movies\n");
        printf("3. Delete Movie\n");
        printf("4. Search Movie\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                addMovie(movies, &movieCount);
                break;
            case 2:
                displayMovies(movies, movieCount);
                break;
            case 3:
                deleteMovie(movies, &movieCount);
                break;
            case 4:
                searchMovie(movies, movieCount);
                break;
            case 5:
                printf("Exiting the program. Happy watching!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}