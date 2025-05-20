//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE 100
#define MAX_GENRE 50
#define MAX_REVIEW 500

typedef struct {
    char title[MAX_TITLE];
    char genre[MAX_GENRE];
    float rating;
    char review[MAX_REVIEW];
} Movie;

int movieCount = 0;
Movie movieList[MAX_MOVIES];

void addMovie() {
    if (movieCount >= MAX_MOVIES) {
        printf("Cannot add more movies. Maximum limit reached.\n");
        return;
    }

    Movie newMovie;
    printf("Enter movie title: ");
    getchar(); // to consume leftover newline character
    fgets(newMovie.title, MAX_TITLE, stdin);
    newMovie.title[strcspn(newMovie.title, "\n")] = 0; // remove newline

    printf("Enter movie genre: ");
    fgets(newMovie.genre, MAX_GENRE, stdin);
    newMovie.genre[strcspn(newMovie.genre, "\n")] = 0; // remove newline

    printf("Enter movie rating (0.0 - 10.0): ");
    scanf("%f", &newMovie.rating);
    while (newMovie.rating < 0.0 || newMovie.rating > 10.0) {
        printf("Invalid rating! Please enter a rating between 0.0 and 10.0: ");
        scanf("%f", &newMovie.rating);
    }

    printf("Enter your review: ");
    getchar(); // consume newline from previous input
    fgets(newMovie.review, MAX_REVIEW, stdin);
    newMovie.review[strcspn(newMovie.review, "\n")] = 0; // remove newline

    movieList[movieCount] = newMovie;
    movieCount++;
    printf("Movie added successfully!\n");
}

void displayMovies() {
    if (movieCount == 0) {
        printf("No movies to display.\n");
        return;
    }

    printf("\nMovies List:\n");
    for (int i = 0; i < movieCount; i++) {
        printf("Movie %d:\n", i + 1);
        printf("Title: %s\n", movieList[i].title);
        printf("Genre: %s\n", movieList[i].genre);
        printf("Rating: %.1f\n", movieList[i].rating);
        printf("Review: %s\n", movieList[i].review);
        printf("-------------------------------------------\n");
    }
}

void searchMovie() {
    char searchTitle[MAX_TITLE];
    printf("Enter the movie title to search: ");
    getchar(); // consume newline from previous input
    fgets(searchTitle, MAX_TITLE, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // remove newline

    int found = 0;
    for (int i = 0; i < movieCount; i++) {
        if (strcasecmp(movieList[i].title, searchTitle) == 0) {
            printf("Movie found:\n");
            printf("Title: %s\n", movieList[i].title);
            printf("Genre: %s\n", movieList[i].genre);
            printf("Rating: %.1f\n", movieList[i].rating);
            printf("Review: %s\n", movieList[i].review);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Movie not found.\n");
    }
}

void editMovie() {
    char searchTitle[MAX_TITLE];
    printf("Enter the movie title to edit: ");
    getchar(); // consume newline from previous input
    fgets(searchTitle, MAX_TITLE, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // remove newline

    for (int i = 0; i < movieCount; i++) {
        if (strcasecmp(movieList[i].title, searchTitle) == 0) {
            printf("Editing movie: %s\n", movieList[i].title);
            printf("Enter new genre: ");
            fgets(movieList[i].genre, MAX_GENRE, stdin);
            movieList[i].genre[strcspn(movieList[i].genre, "\n")] = 0; // remove newline

            printf("Enter new rating (0.0 - 10.0): ");
            scanf("%f", &movieList[i].rating);
            while (movieList[i].rating < 0.0 || movieList[i].rating > 10.0) {
                printf("Invalid rating! Please enter a rating between 0.0 and 10.0: ");
                scanf("%f", &movieList[i].rating);
            }

            printf("Enter new review: ");
            getchar(); // consume newline
            fgets(movieList[i].review, MAX_REVIEW, stdin);
            movieList[i].review[strcspn(movieList[i].review, "\n")] = 0; // remove newline

            printf("Movie updated successfully!\n");
            return;
        }
    }
    printf("Movie not found.\n");
}

void deleteMovie() {
    char searchTitle[MAX_TITLE];
    printf("Enter the movie title to delete: ");
    getchar(); // consume newline
    fgets(searchTitle, MAX_TITLE, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // remove newline

    for (int i = 0; i < movieCount; i++) {
        if (strcasecmp(movieList[i].title, searchTitle) == 0) {
            for (int j = i; j < movieCount - 1; j++) {
                movieList[j] = movieList[j + 1];
            }
            movieCount--;
            printf("Movie deleted successfully!\n");
            return;
        }
    }
    printf("Movie not found.\n");
}

void displayMenu() {
    printf("\nMovie Rating System\n");
    printf("1. Add Movie\n");
    printf("2. Display Movies\n");
    printf("3. Search Movie\n");
    printf("4. Edit Movie\n");
    printf("5. Delete Movie\n");
    printf("6. Exit\n");
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
                searchMovie();
                break;
            case 4:
                editMovie();
                break;
            case 5:
                deleteMovie();
                break;
            case 6:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }

    return 0;
}