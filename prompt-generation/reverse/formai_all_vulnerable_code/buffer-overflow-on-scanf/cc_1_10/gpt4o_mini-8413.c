//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_MOVIES 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    float rating;
} Movie;

Movie* movieCollection[MAX_MOVIES];
int movieCount = 0;

void addMovie() {
    if (movieCount >= MAX_MOVIES) {
        printf("Movie collection is full!\n");
        return;
    }

    Movie* newMovie = (Movie*)malloc(sizeof(Movie));
    if (newMovie == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter the title of the movie: ");
    getchar(); // clear buffer
    fgets(newMovie->title, MAX_TITLE_LENGTH, stdin);
    newMovie->title[strcspn(newMovie->title, "\n")] = 0; // remove newline

    printf("Enter your rating (0.0 - 5.0): ");
    scanf("%f", &(newMovie->rating));

    movieCollection[movieCount++] = newMovie;
    printf("Movie '%s' added with rating %.1f!\n", newMovie->title, newMovie->rating);
}

void viewMovies() {
    if (movieCount == 0) {
        printf("No movies to display!\n");
        return;
    }

    printf("\nMovie Collection:\n");
    for (int i = 0; i < movieCount; i++) {
        printf("%d. %s - Rating: %.1f\n", i + 1, movieCollection[i]->title, movieCollection[i]->rating);
    }
}

void averageRating() {
    if (movieCount == 0) {
        printf("No movies to calculate average!\n");
        return;
    }

    float totalRating = 0.0;
    for (int i = 0; i < movieCount; i++) {
        totalRating += movieCollection[i]->rating;
    }

    float average = totalRating / movieCount;
    printf("The average rating of the movies is: %.2f\n", average);
}

void freeMemory() {
    for (int i = 0; i < movieCount; i++) {
        free(movieCollection[i]);
    }
}

int main() {
    int choice;

    do {
        printf("\n=== Movie Rating System ===\n");
        printf("1. Add Movie\n");
        printf("2. View Movies\n");
        printf("3. View Average Rating\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie();
                break;
            case 2:
                viewMovies();
                break;
            case 3:
                averageRating();
                break;
            case 4:
                printf("Exiting...\n");
                freeMemory();
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}