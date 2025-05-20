//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 100
#define MAX_REVIEW_LENGTH 500

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char review[MAX_REVIEW_LENGTH];
    float rating;  // Rating between 0 and 10
} Movie;

void addMovie(Movie movies[], int *count) {
    if (*count >= MAX_MOVIES) {
        printf("Movie database full! Cannot add more movies.\n");
        return;
    }

    Movie newMovie;

    printf("Enter movie title: ");
    getchar(); // clear buffer before input
    fgets(newMovie.title, MAX_TITLE_LENGTH, stdin);
    newMovie.title[strcspn(newMovie.title, "\n")] = 0; // remove newline

    printf("Enter your review: ");
    fgets(newMovie.review, MAX_REVIEW_LENGTH, stdin);
    newMovie.review[strcspn(newMovie.review, "\n")] = 0; // remove newline

    printf("Rate the movie (0-10): ");
    scanf("%f", &newMovie.rating);

    if (newMovie.rating < 0 || newMovie.rating > 10) {
        printf("Invalid rating! Rating must be between 0 and 10. Movie not added.\n");
        return;
    }

    movies[*count] = newMovie;
    (*count)++;
    printf("Movie added successfully!\n");
}

void listMovies(const Movie movies[], int count) {
    if (count == 0) {
        printf("No movies to display!\n");
        return;
    }

    printf("\n--- Movie List ---\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s\n", movies[i].title);
        printf("Review: %s\n", movies[i].review);
        printf("Rating: %.1f/10\n", movies[i].rating);
        printf("-------------------\n");
    }
}

void searchMovie(const Movie movies[], int count) {
    char title[MAX_TITLE_LENGTH];
    printf("Enter the title of the movie to search: ");
    getchar(); // clear buffer before input
    fgets(title, MAX_TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = 0; // remove newline

    for (int i = 0; i < count; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            printf("Found Movie!\n");
            printf("Title: %s\n", movies[i].title);
            printf("Review: %s\n", movies[i].review);
            printf("Rating: %.1f/10\n", movies[i].rating);
            return;
        }
    }
    printf("Movie not found!\n");
}

void deleteMovie(Movie movies[], int *count) {
    char title[MAX_TITLE_LENGTH];
    printf("Enter the title of the movie to delete: ");
    getchar(); // clear buffer before input
    fgets(title, MAX_TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = 0; // remove newline

    for (int i = 0; i < *count; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            for (int j = i; j < *count - 1; j++) {
                movies[j] = movies[j + 1];
            }
            (*count)--;
            printf("Movie deleted successfully!\n");
            return;
        }
    }
    printf("Movie not found!\n");
}

int main() {
    Movie movies[MAX_MOVIES];
    int count = 0;
    int choice;

    while (1) {
        printf("\n--- Movie Rating System ---\n");
        printf("1. Add Movie\n");
        printf("2. List Movies\n");
        printf("3. Search Movie\n");
        printf("4. Delete Movie\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(movies, &count);
                break;
            case 2:
                listMovies(movies, count);
                break;
            case 3:
                searchMovie(movies, count);
                break;
            case 4:
                deleteMovie(movies, &count);
                break;
            case 5:
                printf("Thank you for using the Movie Rating System! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}