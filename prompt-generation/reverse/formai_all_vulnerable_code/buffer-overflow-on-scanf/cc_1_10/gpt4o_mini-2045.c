//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: all-encompassing
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
    double rating;
} Movie;

int movieCount = 0;
Movie movieList[MAX_MOVIES];

void addMovie() {
    if (movieCount >= MAX_MOVIES) {
        printf("Movie list is full!\n");
        return;
    }

    printf("Enter movie title: ");
    scanf(" %[^\n]", movieList[movieCount].title);

    printf("Enter movie genre: ");
    scanf(" %[^\n]", movieList[movieCount].genre);

    printf("Enter movie rating (0.0 to 10.0): ");
    scanf("%lf", &movieList[movieCount].rating);

    if (movieList[movieCount].rating < 0.0 || movieList[movieCount].rating > 10.0) {
        printf("Invalid rating! Please enter a rating between 0.0 and 10.0\n");
        return;
    }

    movieCount++;
    printf("Movie added successfully!\n");
}

void displayMovies() {
    if (movieCount == 0) {
        printf("No movies to display!\n");
        return;
    }

    printf("\n=== Movie List ===\n");
    for (int i = 0; i < movieCount; i++) {
        printf("Title: %s, Genre: %s, Rating: %.1f\n", movieList[i].title, movieList[i].genre, movieList[i].rating);
    }
    printf("===================\n");
}

void findHighestRated() {
    if (movieCount == 0) {
        printf("No movies in the list to evaluate!\n");
        return;
    }

    int highestIndex = 0;
    for (int i = 1; i < movieCount; i++) {
        if (movieList[i].rating > movieList[highestIndex].rating) {
            highestIndex = i;
        }
    }

    printf("\nHighest Rated Movie:\n");
    printf("Title: %s, Genre: %s, Rating: %.1f\n", movieList[highestIndex].title, movieList[highestIndex].genre, movieList[highestIndex].rating);
}

void deleteMovie() {
    if (movieCount == 0) {
        printf("No movies to delete!\n");
        return;
    }

    displayMovies();

    printf("Enter the index of the movie to delete (0 to %d): ", movieCount - 1);
    int index;
    scanf("%d", &index);

    if (index < 0 || index >= movieCount) {
        printf("Invalid index!\n");
        return;
    }

    for (int i = index; i < movieCount - 1; i++) {
        movieList[i] = movieList[i + 1];
    }
    
    movieCount--;
    printf("Movie deleted successfully!\n");
}

void displayMenu() {
    printf("\n=== Movie Rating System ===\n");
    printf("1. Add Movie\n");
    printf("2. Display Movies\n");
    printf("3. Find Highest Rated Movie\n");
    printf("4. Delete Movie\n");
    printf("5. Exit\n");
    printf("============================\n");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie();
                break;
            case 2:
                displayMovies();
                break;
            case 3:
                findHighestRated();
                break;
            case 4:
                deleteMovie();
                break;
            case 5:
                printf("Exiting the Movie Rating System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}