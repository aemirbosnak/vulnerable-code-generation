//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define NAME_LEN 50

typedef struct {
    char name[NAME_LEN];
    float storyRating;
    float actingRating;
    float directionRating;
    float overallRating;
} Movie;

void inputMovieData(Movie *movie) {
    printf("Enter movie name: ");
    getchar(); // Clear newline from previous input
    fgets(movie->name, NAME_LEN, stdin);
    movie->name[strcspn(movie->name, "\n")] = 0; // Remove newline

    printf("Rate the story (0 to 10): ");
    scanf("%f", &movie->storyRating);
    printf("Rate the acting (0 to 10): ");
    scanf("%f", &movie->actingRating);
    printf("Rate the direction (0 to 10): ");
    scanf("%f", &movie->directionRating);

    // Calculate overall rating
    movie->overallRating = (movie->storyRating + movie->actingRating + movie->directionRating) / 3.0f;
}

void displayMovieData(const Movie *movie) {
    printf("\nMovie Name: %s\n", movie->name);
    printf("Story Rating: %.2f\n", movie->storyRating);
    printf("Acting Rating: %.2f\n", movie->actingRating);
    printf("Direction Rating: %.2f\n", movie->directionRating);
    printf("Overall Rating: %.2f\n", movie->overallRating);
}

void displayAllMovies(Movie movies[], int count) {
    printf("\n--- Movies Rating List ---\n");
    for (int i = 0; i < count; i++) {
        displayMovieData(&movies[i]);
    }
}

int main() {
    Movie movies[MAX_MOVIES];
    int movieCount = 0;
    int choice;

    do {
        printf("\n--- Movie Rating System ---\n");
        printf("1. Add Movie\n");
        printf("2. Display Movies\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (movieCount < MAX_MOVIES) {
                    inputMovieData(&movies[movieCount]);
                    movieCount++;
                } else {
                    printf("Movie list is full!\n");
                }
                break;
            case 2:
                if (movieCount > 0) {
                    displayAllMovies(movies, movieCount);
                } else {
                    printf("No movies to display!\n");
                }
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please select again.\n");
        }
    } while (choice != 3);

    return 0;
}