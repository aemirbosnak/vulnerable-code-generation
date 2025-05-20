//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define TITLE_LENGTH 100
#define GENRE_LENGTH 50

typedef struct {
    char title[TITLE_LENGTH];
    char genre[GENRE_LENGTH];
    int rating; // Rating out of 10
} Movie;

void clearScreen() {
    printf("\033[H\033[J");
}

void displayMenu() {
    printf("Movie Rating System\n");
    printf("--------------------\n");
    printf("1. Add Movie\n");
    printf("2. Display Movies\n");
    printf("3. Update Movie Rating\n");
    printf("4. Delete Movie\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

void addMovie(Movie movies[], int *movieCount) {
    if (*movieCount >= MAX_MOVIES) {
        printf("Cannot add more movies.\n");
        return;
    }
    
    Movie newMovie;
    printf("Enter movie title: ");
    getchar(); // Clear the buffer
    fgets(newMovie.title, TITLE_LENGTH, stdin);
    newMovie.title[strcspn(newMovie.title, "\n")] = 0; // Remove trailing newline

    printf("Enter movie genre: ");
    fgets(newMovie.genre, GENRE_LENGTH, stdin);
    newMovie.genre[strcspn(newMovie.genre, "\n")] = 0; // Remove trailing newline

    printf("Enter movie rating (0-10): ");
    scanf("%d", &newMovie.rating);

    movies[*movieCount] = newMovie;
    (*movieCount)++;
    printf("Movie Added Successfully!\n");
}

void displayMovies(const Movie movies[], int movieCount) {
    if (movieCount == 0) {
        printf("No movies to display.\n");
        return;
    }
    
    printf("Movies List:\n");
    for (int i = 0; i < movieCount; i++) {
        printf("Title: %s, Genre: %s, Rating: %d\n", movies[i].title, movies[i].genre, movies[i].rating);
    }
}

void updateMovieRating(Movie movies[], int movieCount) {
    char title[TITLE_LENGTH];
    printf("Enter the title of the movie you want to update: ");
    getchar(); // Clear the buffer
    fgets(title, TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = 0; // Remove trailing newline

    for (int i = 0; i < movieCount; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            printf("Current Rating: %d\n", movies[i].rating);
            printf("Enter new rating (0-10): ");
            scanf("%d", &movies[i].rating);
            printf("Rating updated successfully!\n");
            return;
        }
    }
    printf("Movie not found.\n");
}

void deleteMovie(Movie movies[], int *movieCount) {
    char title[TITLE_LENGTH];
    printf("Enter the title of the movie you want to delete: ");
    getchar(); // Clear the buffer
    fgets(title, TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = 0; // Remove trailing newline

    for (int i = 0; i < *movieCount; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            for (int j = i; j < *movieCount - 1; j++) {
                movies[j] = movies[j + 1];
            }
            (*movieCount)--;
            printf("Movie deleted successfully!\n");
            return;
        }
    }
    printf("Movie not found.\n");
}

int main() {
    Movie movies[MAX_MOVIES];
    int movieCount = 0;
    int choice;

    do {
        clearScreen();
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(movies, &movieCount);
                break;
            case 2:
                displayMovies(movies, movieCount);
                break;
            case 3:
                updateMovieRating(movies, movieCount);
                break;
            case 4:
                deleteMovie(movies, &movieCount);
                break;
            case 5:
                printf("Exiting the Movie Rating System. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        printf("\nPress Enter to continue...");
        getchar(); // Wait for user input
        getchar(); // Also consume the newline character from previous input

    } while (choice != 5);

    return 0;
}