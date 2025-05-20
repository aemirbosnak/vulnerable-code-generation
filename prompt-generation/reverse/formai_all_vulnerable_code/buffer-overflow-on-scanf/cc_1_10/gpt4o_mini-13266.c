//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MOVIES 100
#define TITLE_LENGTH 100
#define REVIEW_LENGTH 500

typedef struct {
    char title[TITLE_LENGTH];
    float rating; // Rating from 0 to 10
    char review[REVIEW_LENGTH];
} Movie;

void addMovie(Movie movies[], int *count) {
    if (*count >= MAX_MOVIES) {
        printf("Maximum movie limit reached!\n");
        return;
    }
    
    printf("Enter movie title: ");
    getchar(); // to consume newline
    fgets(movies[*count].title, TITLE_LENGTH, stdin);
    movies[*count].title[strcspn(movies[*count].title, "\n")] = 0; // Remove newline

    printf("Enter rating (0 to 10): ");
    scanf("%f", &movies[*count].rating);
    if (movies[*count].rating < 0 || movies[*count].rating > 10) {
        printf("Invalid rating! Please provide a rating between 0 and 10.\n");
        return;
    }

    printf("Enter your review: ");
    getchar(); // to consume newline
    fgets(movies[*count].review, REVIEW_LENGTH, stdin);
    movies[*count].review[strcspn(movies[*count].review, "\n")] = 0; // Remove newline

    (*count)++;
    printf("Movie added successfully!\n");
}

void displayMovies(Movie movies[], int count) {
    if (count == 0) {
        printf("No movies to display.\n");
        return;
    }

    printf("\n=== List of Movies ===\n");
    for (int i = 0; i < count; i++) {
        printf("Movie %d:\n", i + 1);
        printf("Title: %s\n", movies[i].title);
        printf("Rating: %.1f\n", movies[i].rating);
        printf("Review: %s\n\n", movies[i].review);
    }
}

void searchMovie(Movie movies[], int count) {
    char searchTitle[TITLE_LENGTH];
    printf("Enter the movie title to search: ");
    getchar(); // to consume newline
    fgets(searchTitle, TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // Remove newline

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(movies[i].title, searchTitle) == 0) {
            printf("Movie found!\n");
            printf("Title: %s\n", movies[i].title);
            printf("Rating: %.1f\n", movies[i].rating);
            printf("Review: %s\n", movies[i].review);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Movie not found!\n");
    }
}

void deleteMovie(Movie movies[], int *count) {
    char deleteTitle[TITLE_LENGTH];
    printf("Enter the movie title to delete: ");
    getchar(); // to consume newline
    fgets(deleteTitle, TITLE_LENGTH, stdin);
    deleteTitle[strcspn(deleteTitle, "\n")] = 0; // Remove newline

    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (strcmp(movies[i].title, deleteTitle) == 0) {
            found = 1;
            for (int j = i; j < *count - 1; j++) {
                movies[j] = movies[j + 1]; // Shift movies left
            }
            (*count)--;
            printf("Movie deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Movie not found!\n");
    }
}

int main() {
    Movie movies[MAX_MOVIES];
    int count = 0;
    int choice;

    while (1) {
        printf("\n=== Movie Rating System ===\n");
        printf("1. Add Movie\n");
        printf("2. Display Movies\n");
        printf("3. Search Movie\n");
        printf("4. Delete Movie\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(movies, &count);
                break;
            case 2:
                displayMovies(movies, count);
                break;
            case 3:
                searchMovie(movies, count);
                break;
            case 4:
                deleteMovie(movies, &count);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}