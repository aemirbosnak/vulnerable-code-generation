//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define TITLE_LENGTH 100

typedef struct {
    char title[TITLE_LENGTH];
    float rating;
    int numRatings;
} Movie;

void addMovie(Movie movies[], int *count);
void rateMovie(Movie movies[], int count);
void listMovies(Movie movies[], int count);
void menu();

int main() {
    Movie movies[MAX_MOVIES];
    int movieCount = 0;
    int choice;

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(movies, &movieCount);
                break;
            case 2:
                rateMovie(movies, movieCount);
                break;
            case 3:
                listMovies(movies, movieCount);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void menu() {
    printf("\n--- Movie Rating System Menu ---\n");
    printf("1. Add Movie\n");
    printf("2. Rate Movie\n");
    printf("3. List Movies\n");
    printf("4. Exit\n");
}

void addMovie(Movie movies[], int *count) {
    if (*count >= MAX_MOVIES) {
        printf("Cannot add more movies. Maximum limit reached.\n");
        return;
    }

    printf("Enter movie title: ");
    getchar(); // Consume newline character from previous input
    fgets(movies[*count].title, TITLE_LENGTH, stdin);
    movies[*count].title[strcspn(movies[*count].title, "\n")] = 0; // Remove newline character

    movies[*count].rating = 0.0;
    movies[*count].numRatings = 0;
    (*count)++;
    printf("Movie '%s' added successfully!\n", movies[*count - 1].title);
}

void rateMovie(Movie movies[], int count) {
    if (count <= 0) {
        printf("No movies available to rate.\n");
        return;
    }

    printf("Available movies:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, movies[i].title);
    }

    int choice;
    printf("Select a movie to rate (1 - %d): ", count);
    scanf("%d", &choice);
    
    if (choice < 1 || choice > count) {
        printf("Invalid selection.\n");
        return;
    }

    float rating;
    printf("Enter your rating for '%s' (0.0 - 10.0): ", movies[choice - 1].title);
    scanf("%f", &rating);

    if (rating < 0.0 || rating > 10.0) {
        printf("Invalid rating. Please enter a value between 0.0 and 10.0.\n");
        return;
    }

    movies[choice - 1].rating = (movies[choice - 1].rating * movies[choice - 1].numRatings + rating) / (movies[choice - 1].numRatings + 1);
    movies[choice - 1].numRatings++;
    printf("Thank you for rating '%s'. New average rating: %.2f\n", movies[choice - 1].title, movies[choice - 1].rating);
}

void listMovies(Movie movies[], int count) {
    if (count <= 0) {
        printf("No movies available to list.\n");
        return;
    }

    printf("\n--- Movie Ratings ---\n");
    for (int i = 0; i < count; i++) {
        printf("%s - Average Rating: %.2f (Rated by %d users)\n", movies[i].title, movies[i].rating, movies[i].numRatings);
    }
}