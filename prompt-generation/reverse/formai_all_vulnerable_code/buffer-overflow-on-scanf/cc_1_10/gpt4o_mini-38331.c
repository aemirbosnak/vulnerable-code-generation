//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define TITLE_LENGTH 100

typedef struct {
    char title[TITLE_LENGTH];
    int rating;
} Movie;

typedef struct {
    Movie *movies;
    int count;
} MovieRatingSystem;

void initRatingSystem(MovieRatingSystem *system) {
    system->movies = (Movie *)malloc(MAX_MOVIES * sizeof(Movie));
    system->count = 0;
}

void addMovie(MovieRatingSystem *system) {
    if (system->count >= MAX_MOVIES) {
        printf("Movie limit reached. Cannot add more movies!\n");
        return;
    }

    Movie newMovie;
    printf("Enter movie title: ");
    getchar(); // To consume newline character left by previous input
    fgets(newMovie.title, TITLE_LENGTH, stdin);
    newMovie.title[strcspn(newMovie.title, "\n")] = 0; // Remove newline character

    printf("Enter movie rating (1 to 5): ");
    scanf("%d", &newMovie.rating);

    if (newMovie.rating < 1 || newMovie.rating > 5) {
        printf("Invalid rating! Rating should be between 1 and 5.\n");
        return;
    }

    system->movies[system->count] = newMovie;
    system->count++;
    printf("Movie added successfully!\n");
}

void displayMovies(const MovieRatingSystem *system) {
    if (system->count == 0) {
        printf("No movies rated yet!\n");
        return;
    }

    printf("\nRated Movies:\n");
    for (int i = 0; i < system->count; i++) {
        printf("Title: %s, Rating: %d\n", system->movies[i].title, system->movies[i].rating);
    }
}

void freeMemory(MovieRatingSystem *system) {
    free(system->movies);
}

int main() {
    MovieRatingSystem system;
    initRatingSystem(&system);

    int choice;
    do {
        printf("\nMovie Rating System\n");
        printf("1. Add Movie\n");
        printf("2. Display Rated Movies\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(&system);
                break;
            case 2:
                displayMovies(&system);
                break;
            case 3:
                printf("Exiting the system.\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (choice != 3);

    freeMemory(&system);
    return 0;
}