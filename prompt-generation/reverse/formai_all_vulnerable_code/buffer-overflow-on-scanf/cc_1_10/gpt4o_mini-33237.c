//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define TITLE_LEN 100

typedef struct {
    char title[TITLE_LEN];
    int rating; // Rating out of 10
} Movie;

// Function to add a movie
void addMovie(Movie movies[], int *count) {
    if (*count >= MAX_MOVIES) {
        printf("Movie list is full!\n");
        return;
    }
    printf("Enter movie title: ");
    getchar(); // consume newline
    fgets(movies[*count].title, TITLE_LEN, stdin);
    movies[*count].title[strcspn(movies[*count].title, "\n")] = 0; // remove newline
    printf("Enter movie rating (0-10): ");
    scanf("%d", &movies[*count].rating);
    if (movies[*count].rating < 0 || movies[*count].rating > 10) {
        printf("Invalid rating, setting it to 0.\n");
        movies[*count].rating = 0;
    }
    (*count)++;
    printf("Movie added!\n");
}

// Function to display movies
void displayMovies(Movie movies[], int count) {
    if (count == 0) {
        printf("No movies available to display.\n");
        return;
    }
    printf("Movies List:\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s, Rating: %d\n", movies[i].title, movies[i].rating);
    }
}

// Function to compute average rating
void averageRating(Movie movies[], int count) {
    if (count == 0) {
        printf("No movies to rate.\n");
        return;
    }
    int totalRating = 0;
    for (int i = 0; i < count; i++) {
        totalRating += movies[i].rating;
    }
    printf("Average rating: %.2f\n", (float)totalRating / count);
}

int main() {
    Movie movies[MAX_MOVIES];
    int count = 0;
    int choice;

    while (1) {
        printf("=== Movie Rating System ===\n");
        printf("1. Add Movie\n");
        printf("2. Display Movies\n");
        printf("3. Average Rating\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addMovie(movies, &count);
                break;
            case 2:
                displayMovies(movies, count);
                break;
            case 3:
                averageRating(movies, count);
                break;
            case 4:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice, try again.\n");
                break;
        }
    }
    return 0; // End of the program
}