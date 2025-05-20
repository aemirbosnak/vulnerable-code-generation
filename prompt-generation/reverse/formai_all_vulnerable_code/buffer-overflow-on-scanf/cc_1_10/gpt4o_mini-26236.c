//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 100
#define MAX_REVIEW_LENGTH 500

typedef struct {
    char title[MAX_TITLE_LENGTH];
    int year;
    float rating;
    char review[MAX_REVIEW_LENGTH];
} Movie;

// Function prototypes
void addMovie(Movie movies[], int *count);
void viewMovies(Movie movies[], int count);
void searchMovie(Movie movies[], int count);
void deleteMovie(Movie movies[], int *count);
void displayMenu();

int main() {
    Movie movies[MAX_MOVIES];
    int count = 0;
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(movies, &count);
                break;
            case 2:
                viewMovies(movies, count);
                break;
            case 3:
                searchMovie(movies, count);
                break;
            case 4:
                deleteMovie(movies, &count);
                break;
            case 5:
                printf("Exiting the Movie Rating System.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void displayMenu() {
    printf("\n--- Movie Rating System ---\n");
    printf("1. Add Movie\n");
    printf("2. View Movies\n");
    printf("3. Search Movie\n");
    printf("4. Delete Movie\n");
    printf("5. Exit\n");
}

void addMovie(Movie movies[], int *count) {
    if (*count >= MAX_MOVIES) {
        printf("Movie list is full. Can't add more movies.\n");
        return;
    }

    printf("Enter movie title: ");
    getchar(); // To consume the newline character left by scanf
    fgets(movies[*count].title, MAX_TITLE_LENGTH, stdin);
    strtok(movies[*count].title, "\n"); // Remove newline character

    printf("Enter release year: ");
    scanf("%d", &movies[*count].year);

    printf("Enter your rating (0-10): ");
    scanf("%f", &movies[*count].rating);

    printf("Enter your review: ");
    getchar();
    fgets(movies[*count].review, MAX_REVIEW_LENGTH, stdin);
    strtok(movies[*count].review, "\n"); // Remove newline character

    (*count)++;
    printf("Movie added successfully!\n");
}

void viewMovies(Movie movies[], int count) {
    if (count == 0) {
        printf("No movies to display.\n");
        return;
    }

    printf("\n--- Movie List ---\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s\n", movies[i].title);
        printf("Year: %d\n", movies[i].year);
        printf("Rating: %.1f\n", movies[i].rating);
        printf("Review: %s\n\n", movies[i].review);
    }
}

void searchMovie(Movie movies[], int count) {
    char title[MAX_TITLE_LENGTH];
    printf("Enter the title of the movie to search: ");
    getchar(); // To consume the newline character left by scanf
    fgets(title, MAX_TITLE_LENGTH, stdin);
    strtok(title, "\n"); // Remove newline character

    for (int i = 0; i < count; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            printf("Movie found:\n");
            printf("Title: %s\n", movies[i].title);
            printf("Year: %d\n", movies[i].year);
            printf("Rating: %.1f\n", movies[i].rating);
            printf("Review: %s\n", movies[i].review);
            return;
        }
    }
    printf("Movie not found.\n");
}

void deleteMovie(Movie movies[], int *count) {
    char title[MAX_TITLE_LENGTH];
    printf("Enter the title of the movie to delete: ");
    getchar(); // To consume the newline character left by scanf
    fgets(title, MAX_TITLE_LENGTH, stdin);
    strtok(title, "\n"); // Remove newline character

    for (int i = 0; i < *count; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            for (int j = i; j < *count - 1; j++) {
                movies[j] = movies[j + 1]; // Shift movies to the left
            }
            (*count)--; // Reduce movie count
            printf("Movie deleted successfully!\n");
            return;
        }
    }
    printf("Movie not found.\n");
}