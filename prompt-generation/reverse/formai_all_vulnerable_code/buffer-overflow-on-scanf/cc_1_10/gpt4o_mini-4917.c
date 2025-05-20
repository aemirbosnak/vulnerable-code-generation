//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 100
#define MAX_GENRE_LENGTH 50

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    float rating;
} Movie;

Movie movies[MAX_MOVIES];
int movieCount = 0;

void addMovie() {
    if (movieCount >= MAX_MOVIES) {
        printf("Movie list is full!\n");
        return;
    }
    Movie newMovie;
    printf("Enter movie title: ");
    getchar(); // Clear buffer
    fgets(newMovie.title, MAX_TITLE_LENGTH, stdin);
    newMovie.title[strcspn(newMovie.title, "\n")] = 0; // Remove trailing newline

    printf("Enter movie genre: ");
    fgets(newMovie.genre, MAX_GENRE_LENGTH, stdin);
    newMovie.genre[strcspn(newMovie.genre, "\n")] = 0; // Remove trailing newline

    printf("Enter movie rating (0.0 - 5.0): ");
    scanf("%f", &newMovie.rating);

    if (newMovie.rating < 0.0 || newMovie.rating > 5.0) {
        printf("Invalid rating! Please enter a rating between 0.0 and 5.0\n");
        return;
    }

    movies[movieCount] = newMovie;
    movieCount++;
    printf("Movie added successfully!\n");
}

void displayMovies() {
    if (movieCount == 0) {
        printf("No movies to display!\n");
        return;
    }

    printf("\n--- Movie List ---\n");
    for (int i = 0; i < movieCount; i++) {
        printf("Title: %s\n", movies[i].title);
        printf("Genre: %s\n", movies[i].genre);
        printf("Rating: %.1f\n", movies[i].rating);
        printf("-------------------------------\n");
    }
}

void searchMovie() {
    char searchTitle[MAX_TITLE_LENGTH];
    printf("Enter movie title to search for: ");
    getchar(); // Clear buffer
    fgets(searchTitle, MAX_TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // Remove trailing newline

    int found = 0;
    for (int i = 0; i < movieCount; i++) {
        if (strcasecmp(movies[i].title, searchTitle) == 0) {
            printf("Movie found:\n");
            printf("Title: %s\n", movies[i].title);
            printf("Genre: %s\n", movies[i].genre);
            printf("Rating: %.1f\n", movies[i].rating);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Movie not found!\n");
    }
}

void deleteMovie() {
    char deleteTitle[MAX_TITLE_LENGTH];
    printf("Enter movie title to delete: ");
    getchar(); // Clear buffer
    fgets(deleteTitle, MAX_TITLE_LENGTH, stdin);
    deleteTitle[strcspn(deleteTitle, "\n")] = 0; // Remove trailing newline

    int found = 0;
    for (int i = 0; i < movieCount; i++) {
        if (strcasecmp(movies[i].title, deleteTitle) == 0) {
            for (int j = i; j < movieCount - 1; j++) {
                movies[j] = movies[j + 1];
            }
            movieCount--;
            printf("Movie '%s' deleted successfully!\n", deleteTitle);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Movie not found!\n");
    }
}

void displayMenu() {
    printf("\n--- Movie Rating System ---\n");
    printf("1. Add Movie\n");
    printf("2. Display Movies\n");
    printf("3. Search Movie\n");
    printf("4. Delete Movie\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

int main() {
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addMovie();
                break;
            case 2:
                displayMovies();
                break;
            case 3:
                searchMovie();
                break;
            case 4:
                deleteMovie();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}