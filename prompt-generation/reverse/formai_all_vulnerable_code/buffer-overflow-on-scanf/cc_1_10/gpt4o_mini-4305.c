//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define TITLE_LEN 100
#define GENRE_LEN 50

typedef struct {
    char title[TITLE_LEN];
    char genre[GENRE_LEN];
    int rating; // 1 to 5 rating
} Movie;

void displayMovies(Movie movies[], int count);
void addMovie(Movie movies[], int *count);
void editRating(Movie movies[], int count);
void searchByGenre(Movie movies[], int count);
void viewAverageRating(Movie movies[], int count);
void clearBuffer();

int main() {
    Movie movies[MAX_MOVIES];
    int movieCount = 0;
    int choice;

    do {
        printf("\n--- Movie Rating System ---\n");
        printf("1. Add Movie\n");
        printf("2. Edit Movie Rating\n");
        printf("3. Search by Genre\n");
        printf("4. View Average Rating\n");
        printf("5. Display Movies\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
            case 1:
                addMovie(movies, &movieCount);
                break;
            case 2:
                editRating(movies, movieCount);
                break;
            case 3:
                searchByGenre(movies, movieCount);
                break;
            case 4:
                viewAverageRating(movies, movieCount);
                break;
            case 5:
                displayMovies(movies, movieCount);
                break;
            case 6:
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void displayMovies(Movie movies[], int count) {
    if (count == 0) {
        printf("No movies to display.\n");
        return;
    }
    printf("\n--- List of Movies ---\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s | Genre: %s | Rating: %d\n", movies[i].title, movies[i].genre, movies[i].rating);
    }
}

void addMovie(Movie movies[], int *count) {
    if (*count >= MAX_MOVIES) {
        printf("Movie list is full! Cannot add more movies.\n");
        return;
    }
    printf("Enter movie title: ");
    fgets(movies[*count].title, TITLE_LEN, stdin);
    movies[*count].title[strcspn(movies[*count].title, "\n")] = 0; // Remove newline

    printf("Enter movie genre: ");
    fgets(movies[*count].genre, GENRE_LEN, stdin);
    movies[*count].genre[strcspn(movies[*count].genre, "\n")] = 0; // Remove newline

    printf("Enter movie rating (1 to 5): ");
    scanf("%d", &movies[*count].rating);
    clearBuffer();

    if (movies[*count].rating < 1 || movies[*count].rating > 5) {
        printf("Invalid rating! Please enter a rating between 1 and 5.\n");
        return;
    }

    (*count)++;
    printf("Movie added successfully!\n");
}

void editRating(Movie movies[], int count) {
    if (count == 0) {
        printf("No movies to edit ratings for.\n");
        return;
    }
    char title[TITLE_LEN];
    printf("Enter the title of the movie you want to edit: ");
    fgets(title, TITLE_LEN, stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            printf("Current rating is %d. Enter new rating (1 to 5): ", movies[i].rating);
            scanf("%d", &movies[i].rating);
            clearBuffer();

            if (movies[i].rating < 1 || movies[i].rating > 5) {
                printf("Invalid rating! Please enter a rating between 1 and 5.\n");
                return;
            }

            printf("Rating updated successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Movie not found!\n");
    }
}

void searchByGenre(Movie movies[], int count) {
    if (count == 0) {
        printf("No movies available to search.\n");
        return;
    }
    char genre[GENRE_LEN];
    printf("Enter the genre to search for: ");
    fgets(genre, GENRE_LEN, stdin);
    genre[strcspn(genre, "\n")] = 0; // Remove newline

    int found = 0;
    printf("\n--- Movies of Genre: %s ---\n", genre);
    for (int i = 0; i < count; i++) {
        if (strcmp(movies[i].genre, genre) == 0) {
            printf("Title: %s | Rating: %d\n", movies[i].title, movies[i].rating);
            found = 1;
        }
    }
    if (!found) {
        printf("No movies found in this genre.\n");
    }
}

void viewAverageRating(Movie movies[], int count) {
    if (count == 0) {
        printf("No ratings available to calculate average.\n");
        return;
    }
    int total = 0;
    for (int i = 0; i < count; i++) {
        total += movies[i].rating;
    }
    double average = (double)total / count;
    printf("The average rating of all movies is: %.2f\n", average);
}

void clearBuffer() {
    while (getchar() != '\n');
}