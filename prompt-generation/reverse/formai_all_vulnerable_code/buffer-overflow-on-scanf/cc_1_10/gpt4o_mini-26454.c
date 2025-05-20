//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: all-encompassing
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
    int rating; // Rating out of 10
    char review[MAX_REVIEW];
} Movie;

void printMovie(const Movie *movie) {
    printf("Title: %s\n", movie->title);
    printf("Genre: %s\n", movie->genre);
    printf("Rating: %d/10\n", movie->rating);
    printf("Review: %s\n\n", movie->review);
}

void addMovie(Movie *movies, int *count) {
    if (*count >= MAX_MOVIES) {
        printf("Movie list is full!\n");
        return;
    }
    
    Movie newMovie;
    printf("Enter movie title: ");
    getchar(); // Clear newline from the input buffer
    fgets(newMovie.title, MAX_TITLE, stdin);
    newMovie.title[strcspn(newMovie.title, "\n")] = 0; // Remove newline character
    
    printf("Enter movie genre: ");
    fgets(newMovie.genre, MAX_GENRE, stdin);
    newMovie.genre[strcspn(newMovie.genre, "\n")] = 0; // Remove newline character

    printf("Enter movie rating (0-10): ");
    scanf("%d", &newMovie.rating);

    printf("Enter your review: ");
    getchar(); // Clear newline from the input buffer
    fgets(newMovie.review, MAX_REVIEW, stdin);
    newMovie.review[strcspn(newMovie.review, "\n")] = 0; // Remove newline character

    movies[*count] = newMovie;
    (*count)++;
    printf("Movie added!\n\n");
}

void viewMovies(const Movie *movies, int count) {
    if (count == 0) {
        printf("No movies to display.\n\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("Movie %d:\n", i + 1);
        printMovie(&movies[i]);
    }
}

void searchMovie(const Movie *movies, int count) {
    if (count == 0) {
        printf("No movies to search.\n\n");
        return;
    }
    
    char searchTerm[MAX_TITLE];
    printf("Enter title to search: ");
    getchar(); // Clear newline from the input buffer
    fgets(searchTerm, MAX_TITLE, stdin);
    searchTerm[strcspn(searchTerm, "\n")] = 0; // Remove newline character

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strstr(movies[i].title, searchTerm) != NULL) {
            printMovie(&movies[i]);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No movies found with title containing '%s'.\n\n", searchTerm);
    }
}

void deleteMovie(Movie *movies, int *count) {
    if (*count == 0) {
        printf("No movies to delete.\n\n");
        return;
    }

    int index;
    printf("Enter the index of the movie to delete (1 to %d): ", *count);
    scanf("%d", &index);
    
    if (index < 1 || index > *count) {
        printf("Invalid index.\n\n");
        return;
    }

    for (int i = index - 1; i < *count - 1; i++) {
        movies[i] = movies[i + 1];
    }
    
    (*count)--;
    printf("Movie deleted!\n\n");
}

int main() {
    Movie movies[MAX_MOVIES];
    int movieCount = 0;
    int choice;

    do {
        printf("Movie Rating System\n");
        printf("1. Add Movie\n");
        printf("2. View Movies\n");
        printf("3. Search Movie\n");
        printf("4. Delete Movie\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(movies, &movieCount);
                break;
            case 2:
                viewMovies(movies, movieCount);
                break;
            case 3:
                searchMovie(movies, movieCount);
                break;
            case 4:
                deleteMovie(movies, &movieCount);
                break;
            case 5:
                printf("Exiting the Movie Rating System.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n\n");
                break;
        }
    } while (choice != 5);
    
    return 0;
}