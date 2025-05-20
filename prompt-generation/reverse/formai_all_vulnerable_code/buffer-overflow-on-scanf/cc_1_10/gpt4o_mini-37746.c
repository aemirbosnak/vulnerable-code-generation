//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define TITLE_LENGTH 100
#define RATING_LENGTH 10

typedef struct {
    char title[TITLE_LENGTH];
    char rating[RATING_LENGTH];
    int year;
} Movie;

void addMovie(Movie movies[], int *count) {
    if (*count >= MAX_MOVIES) {
        printf("Cannot add more movies!\n");
        return;
    }
    printf("Enter movie title: ");
    getchar(); // Consume leftover newline
    fgets(movies[*count].title, TITLE_LENGTH, stdin);
    movies[*count].title[strcspn(movies[*count].title, "\n")] = 0; // Remove newline

    printf("Enter movie rating (e.g., PG, PG-13, R): ");
    fgets(movies[*count].rating, RATING_LENGTH, stdin);
    movies[*count].rating[strcspn(movies[*count].rating, "\n")] = 0; // Remove newline

    printf("Enter year of release: ");
    scanf("%d", &movies[*count].year);

    (*count)++;
    printf("Movie added successfully!\n");
}

void displayMovies(Movie movies[], int count) {
    if (count == 0) {
        printf("No movies to display!\n");
        return;
    }
    printf("\n--- Movie List ---\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s, Rating: %s, Year: %d\n", 
                movies[i].title, movies[i].rating, movies[i].year);
    }
}

void searchMovies(Movie movies[], int count) {
    if (count == 0) {
        printf("No movies to search!\n");
        return;
    }

    char title[TITLE_LENGTH];
    printf("Enter the title of the movie to search: ");
    getchar(); // Consume leftover newline
    fgets(title, TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline

    for (int i = 0; i < count; i++) {
        if (strcasecmp(movies[i].title, title) == 0) {
            printf("Movie found! Title: %s, Rating: %s, Year: %d\n", 
                   movies[i].title, movies[i].rating, movies[i].year);
            return;
        }
    }
    printf("Movie not found!\n");
}

void removeMovie(Movie movies[], int *count) {
    if (*count == 0) {
        printf("No movies to remove!\n");
        return;
    }

    char title[TITLE_LENGTH];
    printf("Enter the title of the movie to remove: ");
    getchar(); // Consume leftover newline
    fgets(title, TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline

    for (int i = 0; i < *count; i++) {
        if (strcasecmp(movies[i].title, title) == 0) {
            for (int j = i; j < *count - 1; j++) {
                movies[j] = movies[j + 1];
            }
            (*count)--;
            printf("Movie removed successfully!\n");
            return;
        }
    }
    printf("Movie not found!\n");
}

void displayMenu() {
    printf("\n--- Movie Rating System Menu ---\n");
    printf("1. Add Movie\n");
    printf("2. Display Movies\n");
    printf("3. Search Movie\n");
    printf("4. Remove Movie\n");
    printf("5. Exit\n");
}

int main() {
    Movie movies[MAX_MOVIES];
    int count = 0;
    int choice;

    do {
        displayMenu();
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
                searchMovies(movies, count);
                break;
            case 4:
                removeMovie(movies, &count);
                break;
            case 5:
                printf("Exiting the movie rating system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 5.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}