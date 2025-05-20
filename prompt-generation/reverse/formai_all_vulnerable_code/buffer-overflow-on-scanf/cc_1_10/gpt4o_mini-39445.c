//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants for rating
#define SUPERB 5
#define GOOD 4
#define AVERAGE 3
#define POOR 2
#define TERRIBLE 1

// Structure for Movie
typedef struct {
    char title[100];
    char genre[50];
    int rating;
} Movie;

// Function prototypes
void addMovie(Movie *m);
void displayMovies(const Movie *movies, int count);
int calculateAverageRating(const Movie *movies, int count);
void bubbleSortMovies(Movie *movies, int count);

int main() {
    int numMovies = 0;
    Movie movies[100];
    int choice;

    while (1) {
        printf("\n--- Movie Rating System ---\n");
        printf("1. Add Movie\n");
        printf("2. Display Movies\n");
        printf("3. Show Average Rating\n");
        printf("4. Sort Movies by Rating\n");
        printf("5. Exit\n");
        printf("-------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline character from buffer

        switch (choice) {
            case 1:
                if (numMovies < 100) {
                    addMovie(&movies[numMovies]);
                    numMovies++;
                } else {
                    printf("Movie list is full!\n");
                }
                break;
            case 2:
                displayMovies(movies, numMovies);
                break;
            case 3:
                {
                    int avgRating = calculateAverageRating(movies, numMovies);
                    printf("Average Rating: %d\n", avgRating);
                }
                break;
            case 4:
                bubbleSortMovies(movies, numMovies);
                printf("Movies sorted by rating.\n");
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

// Function to add a movie
void addMovie(Movie *m) {
    printf("Enter movie title: ");
    fgets(m->title, 100, stdin);
    m->title[strcspn(m->title, "\n")] = 0; // Remove newline

    printf("Enter movie genre: ");
    fgets(m->genre, 50, stdin);
    m->genre[strcspn(m->genre, "\n")] = 0; // Remove newline

    printf("Rate the movie (1-Terrible to 5-Superb): ");
    scanf("%d", &m->rating);
    getchar(); // clear newline character from buffer

    if (m->rating < 1 || m->rating > 5) {
        printf("Invalid rating! Set to default (3)\n");
        m->rating = AVERAGE;
    }
}

// Function to display movies
void displayMovies(const Movie *movies, int count) {
    if (count == 0) {
        printf("No movies to display.\n");
        return;
    }
    printf("\n--- Movies List ---\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s | Genre: %s | Rating: %d\n", movies[i].title, movies[i].genre, movies[i].rating);
    }
}

// Function to calculate average rating
int calculateAverageRating(const Movie *movies, int count) {
    if (count == 0) return 0;

    int total = 0;
    for (int i = 0; i < count; i++) {
        total += movies[i].rating;
    }
    return total / count;
}

// Function to sort movies by rating (Bubble Sort)
void bubbleSortMovies(Movie *movies, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (movies[j].rating < movies[j + 1].rating) {
                // Swap movies
                Movie temp = movies[j];
                movies[j] = movies[j + 1];
                movies[j + 1] = temp;
            }
        }
    }
}