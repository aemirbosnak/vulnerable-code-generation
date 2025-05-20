//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 100
#define MAX_REVIEW_LENGTH 500

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char review[MAX_REVIEW_LENGTH];
    int ratings[5]; // Ratings from 0 to 4 stars
    float averageRating;
} Movie;

void addMovie(Movie movies[], int *count);
void displayMovies(const Movie movies[], int count);
void calculateAverageRating(Movie *movie);
int compareMovies(const void *a, const void *b);
void sortMoviesByRating(Movie movies[], int count);

int main() {
    Movie movies[MAX_MOVIES];
    int count = 0;
    int choice;

    do {
        printf("\n--- Movie Rating System ---\n");
        printf("1. Add Movie\n");
        printf("2. Display Movies\n");
        printf("3. Sort Movies by Rating\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                addMovie(movies, &count);
                break;
            case 2:
                displayMovies(movies, count);
                break;
            case 3:
                sortMoviesByRating(movies, count);
                printf("Movies sorted by rating.\n");
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    } while (choice != 4);

    return 0;
}

void addMovie(Movie movies[], int *count) {
    if (*count >= MAX_MOVIES) {
        printf("Maximum movie limit reached.\n");
        return;
    }

    Movie newMovie;
    printf("Enter movie title: ");
    fgets(newMovie.title, MAX_TITLE_LENGTH, stdin);
    newMovie.title[strcspn(newMovie.title, "\n")] = 0; // Remove newline

    printf("Enter review: ");
    fgets(newMovie.review, MAX_REVIEW_LENGTH, stdin);
    newMovie.review[strcspn(newMovie.review, "\n")] = 0; // Remove newline

    for (int i = 0; i < 5; i++) {
        printf("Enter rating (0-4 stars) for category %d (0 for no rating): ", i + 1);
        scanf("%d", &newMovie.ratings[i]);
        if (newMovie.ratings[i] < 0 || newMovie.ratings[i] > 4) {
            printf("Invalid rating. Please enter a value between 0 and 4.\n");
            i--; // Decrement to redo this iteration
        }
        getchar(); // Consume newline character
    }

    calculateAverageRating(&newMovie);
    movies[*count] = newMovie;
    (*count)++;
    printf("Movie added successfully!\n");
}

void calculateAverageRating(Movie *movie) {
    int total = 0, count = 0;
    for (int i = 0; i < 5; i++) {
        total += movie->ratings[i];
        if (movie->ratings[i] > 0) count++; // Only count non-zero ratings
    }

    movie->averageRating = count > 0 ? (float) total / count : 0.0;
}

void displayMovies(const Movie movies[], int count) {
    if (count == 0) {
        printf("No movies to display.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("\n--- Movie %d ---\n", i + 1);
        printf("Title: %s\n", movies[i].title);
        printf("Review: %s\n", movies[i].review);
        printf("Average Rating: %.2f\n", movies[i].averageRating);
        for (int j = 0; j < 5; j++) {
            printf("Rating for category %d: %d\n", j + 1, movies[i].ratings[j]);
        }
    }
}

int compareMovies(const void *a, const void *b) {
    Movie *movie1 = (Movie *)a;
    Movie *movie2 = (Movie *)b;

    return (movie2->averageRating - movie1->averageRating) > 0 ? 1 : -1;
}

void sortMoviesByRating(Movie movies[], int count) {
    qsort(movies, count, sizeof(Movie), compareMovies);
}