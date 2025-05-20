//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define TITLE_LENGTH 100
#define REVIEW_LENGTH 500

typedef struct {
    char title[TITLE_LENGTH];
    float rating;
    char review[REVIEW_LENGTH];
} Movie;

void addMovie(Movie *movies, int *count);
void displayMovies(Movie *movies, int count);
void sortMovies(Movie *movies, int count);
void clearInputBuffer();

int main() {
    Movie movies[MAX_MOVIES];
    int movieCount = 0;
    int choice;

    do {
        printf("\n--- Movie Rating System ---\n");
        printf("1. Add Movie\n");
        printf("2. Display Movies\n");
        printf("3. Sort Movies by Rating\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        
        if (scanf("%d", &choice) != 1) {
            clearInputBuffer();
            printf("Invalid input. Please enter a number between 1 and 4.\n");
            continue;
        }
        
        switch (choice) {
            case 1:
                addMovie(movies, &movieCount);
                break;
            case 2:
                displayMovies(movies, movieCount);
                break;
            case 3:
                sortMovies(movies, movieCount);
                displayMovies(movies, movieCount);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid option. Please choose again.\n");
        }
    } while (choice != 4);

    return 0;
}

void addMovie(Movie *movies, int *count) {
    if (*count >= MAX_MOVIES) {
        printf("Cannot add more movies. Maximum limit reached.\n");
        return;
    }

    printf("Enter movie title: ");
    clearInputBuffer();
    fgets(movies[*count].title, TITLE_LENGTH, stdin);
    strtok(movies[*count].title, "\n"); // Remove newline character

    printf("Enter movie rating (0.0 to 10.0): ");
    float rating;
    while (1) {
        if (scanf("%f", &rating) != 1 || rating < 0.0 || rating > 10.0) {
            clearInputBuffer();
            printf("Invalid rating. Please enter a value between 0.0 and 10.0: ");
        } else {
            break;
        }
    }
    movies[*count].rating = rating;

    printf("Enter your review: ");
    clearInputBuffer();
    fgets(movies[*count].review, REVIEW_LENGTH, stdin);
    strtok(movies[*count].review, "\n"); // Remove newline character

    (*count)++;
    printf("Movie added successfully!\n");
}

void displayMovies(Movie *movies, int count) {
    if (count == 0) {
        printf("No movies to display.\n");
        return;
    }

    printf("\n--- Movie List ---\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s\n", movies[i].title);
        printf("Rating: %.1f\n", movies[i].rating);
        printf("Review: %s\n\n", movies[i].review);
    }
}

void sortMovies(Movie *movies, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (movies[j].rating < movies[j + 1].rating) {
                Movie temp = movies[j];
                movies[j] = movies[j + 1];
                movies[j + 1] = temp;
            }
        }
    }
    printf("Movies sorted by rating successfully!\n");
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}