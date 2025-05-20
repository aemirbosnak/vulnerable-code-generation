//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define TITLE_LENGTH 100
#define REVIEW_LENGTH 500

// Structure to hold movie information
typedef struct Movie {
    char title[TITLE_LENGTH];
    char review[REVIEW_LENGTH];
    int rating; // Rating between 1 and 5
} Movie;

// Function prototypes
void addMovie(Movie movies[], int *count);
void viewMovies(Movie movies[], int count);
void rateMovies(Movie movies[], int count);
void displayMenu();

int main() {
    Movie movies[MAX_MOVIES];
    int count = 0;
    int choice;

    printf("🎬 Welcome to the Movie Rating System! 🎥\n");
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to consume the newline character

        switch (choice) {
            case 1:
                addMovie(movies, &count);
                break;
            case 2:
                viewMovies(movies, count);
                break;
            case 3:
                rateMovies(movies, count);
                break;
            case 0:
                printf("🛑 Exiting the Movie Rating System! Happy watching! 🎉\n");
                break;
            default:
                printf("🚫 Invalid choice! Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

// Function to display menu
void displayMenu() {
    printf("\n--- Menu ---\n");
    printf("1. Add a Movie\n");
    printf("2. View Movies\n");
    printf("3. Rate Movies\n");
    printf("0. Exit\n");
}

// Function to add a movie
void addMovie(Movie movies[], int *count) {
    if (*count >= MAX_MOVIES) {
        printf("🚫 Cannot add more movies! Maximum limit reached.\n");
        return;
    }

    printf("🎥 Enter the movie title: ");
    fgets(movies[*count].title, TITLE_LENGTH, stdin);
    movies[*count].title[strcspn(movies[*count].title, "\n")] = 0; // remove newline

    printf("✍️ Enter your review: ");
    fgets(movies[*count].review, REVIEW_LENGTH, stdin);
    movies[*count].review[strcspn(movies[*count].review, "\n")] = 0; // remove newline

    movies[*count].rating = 0; // Initialize rating to zero

    printf("✅ Movie \"%s\" added successfully! 🎉\n", movies[*count].title);
    (*count)++;
}

// Function to view movies
void viewMovies(Movie movies[], int count) {
    if (count == 0) {
        printf("🚫 No movies to display! Please add movies first.\n");
        return;
    }

    printf("\n📽️ List of Movies:\n");
    for (int i = 0; i < count; i++) {
        printf("🎬 Movie %d: \"%s\"\n", i + 1, movies[i].title);
        printf("📝 Review: %s\n", movies[i].review);
        if (movies[i].rating > 0) {
            printf("⭐ Rating: %d/5\n", movies[i].rating);
        } else {
            printf("⭐ Rating: Not rated yet.\n");
        }
        printf("\n");
    }
}

// Function to rate movies
void rateMovies(Movie movies[], int count) {
    if (count == 0) {
        printf("🚫 No movies to rate! Please add movies first.\n");
        return;
    }

    int movieIndex;
    printf("📊 Enter the movie number you want to rate (1 - %d): ", count);
    scanf("%d", &movieIndex);

    if (movieIndex < 1 || movieIndex > count) {
        printf("🚫 Invalid movie number! Please try again.\n");
        return;
    }

    int rating;
    printf("🌟 Enter your rating for \"%s\" (1-5): ", movies[movieIndex - 1].title);
    scanf("%d", &rating);

    if (rating < 1 || rating > 5) {
        printf("🚫 Invalid rating! Please give a rating between 1 and 5.\n");
        return;
    }

    movies[movieIndex - 1].rating = rating;
    printf("✅ Thank you! You've rated \"%s\" %d/5! 🥳\n", movies[movieIndex - 1].title, movies[movieIndex - 1].rating);
}