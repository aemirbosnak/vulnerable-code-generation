//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define TITLE_LENGTH 100

typedef struct {
    char title[TITLE_LENGTH];
    int rating;
} Movie;

Movie movieList[MAX_MOVIES];
int movieCount = 0;

// Function to add a movie
void addMovie() {
    if (movieCount >= MAX_MOVIES) {
        printf("Movie list is full!\n");
        return;
    }
    
    Movie newMovie;
    printf("Enter movie title: ");
    getchar(); // Clear newline from previous input
    fgets(newMovie.title, TITLE_LENGTH, stdin);
    newMovie.title[strcspn(newMovie.title, "\n")] = 0; // Remove newline

    printf("Enter rating (1-5): ");
    scanf("%d", &newMovie.rating);
    
    if(newMovie.rating < 1 || newMovie.rating > 5) {
        printf("Invalid rating! Rating must be between 1 and 5.\n");
        return;
    }

    movieList[movieCount++] = newMovie;
    printf("Movie added successfully!\n");
}

// Function to display all movies and their ratings
void displayMovies() {
    if (movieCount == 0) {
        printf("No movies found!\n");
        return;
    }
    
    printf("\nMovies and Ratings:\n");
    for (int i = 0; i < movieCount; i++) {
        printf("%d. %s - Rating: %d/5\n", i + 1, movieList[i].title, movieList[i].rating);
    }
}

// Function to search for a movie by title
void searchMovie() {
    char searchTitle[TITLE_LENGTH];
    printf("Enter the title of the movie to search: ");
    getchar(); // Clear newline from previous input
    fgets(searchTitle, TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // Remove newline

    for (int i = 0; i < movieCount; i++) {
        if (strcmp(movieList[i].title, searchTitle) == 0) {
            printf("Found: %s - Rating: %d/5\n", movieList[i].title, movieList[i].rating);
            return;
        }
    }
    printf("Movie not found!\n");
}

// Main menu function
void mainMenu() {
    int choice;
    do {
        printf("\nMovie Rating System\n");
        printf("1. Add Movie\n");
        printf("2. Display Movies\n");
        printf("3. Search Movie\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
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
                printf("Exiting the Movie Rating System. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);
}

// Main function
int main() {
    mainMenu();
    return 0;
}