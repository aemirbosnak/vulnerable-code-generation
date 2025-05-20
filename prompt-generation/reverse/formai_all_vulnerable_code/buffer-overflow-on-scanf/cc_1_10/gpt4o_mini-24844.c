//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_NAME_LENGTH 100

typedef struct {
    char title[MAX_NAME_LENGTH];
    float rating; // Scale of 0.0 to 10.0
    int year;
} Movie;

Movie movieList[MAX_MOVIES];
int movieCount = 0;

void addMovie() {
    if (movieCount >= MAX_MOVIES) {
        printf("Cannot add more movies. Limit reached!\n");
        return;
    }

    Movie newMovie;
    printf("Enter movie title: ");
    getchar(); // Consume newline character
    fgets(newMovie.title, MAX_NAME_LENGTH, stdin);
    newMovie.title[strcspn(newMovie.title, "\n")] = 0; // Remove newline

    printf("Enter movie rating (0.0 to 10.0): ");
    scanf("%f", &newMovie.rating);
    if (newMovie.rating < 0.0 || newMovie.rating > 10.0) {
        printf("Invalid rating! It must be within 0.0 to 10.0.\n");
        return;
    }

    printf("Enter release year: ");
    scanf("%d", &newMovie.year);

    movieList[movieCount] = newMovie;
    movieCount++;
    printf("Movie added successfully!\n");
}

void listMovies() {
    if (movieCount == 0) {
        printf("No movies to display.\n");
        return;
    }

    printf("\nList of Movies:\n");
    for (int i = 0; i < movieCount; i++) {
        printf("Title: %s, Rating: %.1f, Year: %d\n", movieList[i].title, movieList[i].rating, movieList[i].year);
    }
}

void searchMovie() {
    char searchTitle[MAX_NAME_LENGTH];
    printf("Enter the title of the movie to search: ");
    getchar(); // Consume newline character
    fgets(searchTitle, MAX_NAME_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // Remove newline

    int found = 0;
    for (int i = 0; i < movieCount; i++) {
        if (strcasecmp(movieList[i].title, searchTitle) == 0) {
            printf("Found Movie - Title: %s, Rating: %.1f, Year: %d\n", 
                   movieList[i].title, movieList[i].rating, movieList[i].year);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Movie '%s' not found in the list.\n", searchTitle);
    }
}

void deleteMovie() {
    char deleteTitle[MAX_NAME_LENGTH];
    printf("Enter the title of the movie to delete: ");
    getchar(); // Consume newline character
    fgets(deleteTitle, MAX_NAME_LENGTH, stdin);
    deleteTitle[strcspn(deleteTitle, "\n")] = 0; // Remove newline

    int found = 0;
    for (int i = 0; i < movieCount; i++) {
        if (strcasecmp(movieList[i].title, deleteTitle) == 0) {
            found = 1;
            for (int j = i; j < movieCount - 1; j++) {
                movieList[j] = movieList[j + 1]; // Shift movies
            }
            movieCount--;
            printf("Movie '%s' deleted successfully.\n", deleteTitle);
            break;
        }
    }

    if (!found) {
        printf("Movie '%s' not found in the list.\n", deleteTitle);
    }
}

void displayMenu() {
    printf("\n--- Movie Rating System Menu ---\n");
    printf("1. Add Movie\n");
    printf("2. List Movies\n");
    printf("3. Search Movie\n");
    printf("4. Delete Movie\n");
    printf("0. Exit\n");
    printf("Choose an option: ");
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
                listMovies();
                break;
            case 3:
                searchMovie();
                break;
            case 4:
                deleteMovie();
                break;
            case 0:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 0);

    return 0;
}