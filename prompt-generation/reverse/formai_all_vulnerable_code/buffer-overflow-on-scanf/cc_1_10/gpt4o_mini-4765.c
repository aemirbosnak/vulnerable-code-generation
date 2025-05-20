//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define TITLE_LENGTH 100
#define RATING_LENGTH 10

typedef struct {
    char title[TITLE_LENGTH];
    char rating[RATING_LENGTH];
} Movie;

void addMovie(Movie movies[], int *count) {
    if (*count >= MAX_MOVIES) {
        printf("Movie database is full!\n");
        return;
    }
    
    printf("Enter movie title: ");
    fgets(movies[*count].title, TITLE_LENGTH, stdin);
    movies[*count].title[strcspn(movies[*count].title, "\n")] = 0; // Remove newline

    printf("Rate the movie (1-5): ");
    fgets(movies[*count].rating, RATING_LENGTH, stdin);
    movies[*count].rating[strcspn(movies[*count].rating, "\n")] = 0; // Remove newline
    
    (*count)++;
    printf("Movie added successfully!\n");
}

void displayMovies(const Movie movies[], int count) {
    if (count == 0) {
        printf("No movies to display.\n");
        return;
    }
    
    printf("\nMovie List:\n");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s, Rating: %s\n", movies[i].title, movies[i].rating);
    }
    printf("---------------------------------------------------\n");
}

void searchMovie(const Movie movies[], int count) {
    char searchTitle[TITLE_LENGTH];
    printf("Enter movie title to search: ");
    fgets(searchTitle, TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // Remove newline

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcasecmp(movies[i].title, searchTitle) == 0) {
            printf("Found Movie: Title: %s, Rating: %s\n", movies[i].title, movies[i].rating);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Movie not found.\n");
    }
}

void deleteMovie(Movie movies[], int *count) {
    char deleteTitle[TITLE_LENGTH];
    printf("Enter the title of the movie to delete: ");
    fgets(deleteTitle, TITLE_LENGTH, stdin);
    deleteTitle[strcspn(deleteTitle, "\n")] = 0; // Remove newline
    
    int found = -1;
    for (int i = 0; i < *count; i++) {
        if (strcasecmp(movies[i].title, deleteTitle) == 0) {
            found = i;
            break;
        }
    }

    if (found != -1) {
        for (int j = found; j < *count - 1; j++) {
            movies[j] = movies[j + 1];
        }
        (*count)--;
        printf("Movie deleted successfully.\n");
    } else {
        printf("Movie not found for deletion.\n");
    }
}

void updateMovie(Movie movies[], int count) {
    char updateTitle[TITLE_LENGTH];
    printf("Enter the title of the movie to update: ");
    fgets(updateTitle, TITLE_LENGTH, stdin);
    updateTitle[strcspn(updateTitle, "\n")] = 0; // Remove newline

    for (int i = 0; i < count; i++) {
        if (strcasecmp(movies[i].title, updateTitle) == 0) {
            printf("Current Rating: %s\n", movies[i].rating);
            printf("Enter new rating (1-5): ");
            fgets(movies[i].rating, RATING_LENGTH, stdin);
            movies[i].rating[strcspn(movies[i].rating, "\n")] = 0; // Remove newline
            printf("Movie updated successfully!\n");
            return;
        }
    }
    printf("Movie not found for updating.\n");
}

int main() {
    Movie movies[MAX_MOVIES];
    int movieCount = 0;
    int choice;

    do {
        printf("\nMovie Rating System\n");
        printf("1. Add Movie\n");
        printf("2. Display Movies\n");
        printf("3. Search Movie\n");
        printf("4. Delete Movie\n");
        printf("5. Update Movie\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

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
                deleteMovie(movies, &movieCount);
                break;
            case 5:
                updateMovie(movies, movieCount);
                break;
            case 6:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}