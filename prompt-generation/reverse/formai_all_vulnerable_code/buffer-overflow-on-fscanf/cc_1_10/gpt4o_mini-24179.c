//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 50
#define TITLE_LENGTH 100

// Structure for storing movie information
typedef struct {
    char title[TITLE_LENGTH];
    float rating;
} Movie;

// Function prototypes
void addMovie(Movie movies[], int *movieCount);
void displayMovies(Movie movies[], int movieCount);
void readRatingsFromFile(Movie movies[], int *movieCount, const char *filename);
void saveRatingsToFile(Movie movies[], int movieCount, const char *filename);
void sortMoviesByRating(Movie movies[], int movieCount);
void displayMenu();
void clearInputBuffer();

int main() {
    Movie movies[MAX_MOVIES];
    int movieCount = 0;
    int choice;
    const char *filename = "movie_ratings.txt";

    readRatingsFromFile(movies, &movieCount, filename);
    
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch(choice) {
            case 1:
                addMovie(movies, &movieCount);
                break;
            case 2:
                displayMovies(movies, movieCount);
                break;
            case 3:
                sortMoviesByRating(movies, movieCount);
                printf("Movies sorted by rating!\n");
                break;
            case 4:
                saveRatingsToFile(movies, movieCount, filename);
                printf("Movie ratings saved to %s!\n", filename);
                break;
            case 5:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void addMovie(Movie movies[], int *movieCount) {
    if (*movieCount >= MAX_MOVIES) {
        printf("Movie list is full. Cannot add more movies.\n");
        return;
    }

    Movie newMovie;
    printf("Enter movie title: ");
    fgets(newMovie.title, TITLE_LENGTH, stdin);
    newMovie.title[strcspn(newMovie.title, "\n")] = 0; // Remove newline character

    printf("Enter movie rating (0-10): ");
    scanf("%f", &newMovie.rating);
    clearInputBuffer();

    if (newMovie.rating < 0 || newMovie.rating > 10) {
        printf("Invalid rating. Please enter a value between 0 and 10.\n");
        return;
    }

    movies[*movieCount] = newMovie;
    (*movieCount)++;
    printf("Movie added successfully!\n");
}

void displayMovies(Movie movies[], int movieCount) {
    if (movieCount == 0) {
        printf("No movies to display.\n");
        return;
    }

    printf("\nList of Movies:\n");
    for (int i = 0; i < movieCount; i++) {
        printf("%d. %s - Rating: %.2f\n", i + 1, movies[i].title, movies[i].rating);
    }
}

void readRatingsFromFile(Movie movies[], int *movieCount, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Could not open file %s for reading. Starting with an empty list.\n", filename);
        return;
    }

    while (fscanf(file, " %[^\n] %f", movies[*movieCount].title, &movies[*movieCount].rating) == 2) {
        (*movieCount)++;
    }

    fclose(file);
    printf("Loaded %d movies from %s.\n", *movieCount, filename);
}

void saveRatingsToFile(Movie movies[], int movieCount, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Could not open file %s for writing.\n", filename);
        return;
    }

    for (int i = 0; i < movieCount; i++) {
        fprintf(file, "%s %.2f\n", movies[i].title, movies[i].rating);
    }

    fclose(file);
}

void sortMoviesByRating(Movie movies[], int movieCount) {
    for (int i = 0; i < movieCount - 1; i++) {
        for (int j = 0; j < movieCount - i - 1; j++) {
            if (movies[j].rating < movies[j + 1].rating) {
                Movie temp = movies[j];
                movies[j] = movies[j + 1];
                movies[j + 1] = temp;
            }
        }
    }
}

void displayMenu() {
    printf("\n--- Movie Rating System ---\n");
    printf("1. Add Movie\n");
    printf("2. Display Movies\n");
    printf("3. Sort Movies by Rating\n");
    printf("4. Save Ratings to File\n");
    printf("5. Exit\n");
}

void clearInputBuffer() {
    while (getchar() != '\n'); // Clear input buffer
}