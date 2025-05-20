//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    int rating; // Rating out of 10
} Movie;

void addMovie(Movie movies[], int *count);
void displayMovies(const Movie movies[], int count);
void rateMovie(Movie movies[], int count);
void clearScreen();

int main() {
    Movie movies[MAX_MOVIES];
    int count = 0;
    int choice;

    do {
        clearScreen();
        printf("Welcome to the Relaxed Movie Rating System!\n");
        printf("--------------------------------------------\n");
        printf("1. Add Movie\n");
        printf("2. Display Movies\n");
        printf("3. Rate a Movie\n");
        printf("4. Exit\n");
        printf("Please choose an option (1-4): ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character

        switch (choice) {
            case 1:
                addMovie(movies, &count);
                break;
            case 2:
                displayMovies(movies, count);
                break;
            case 3:
                rateMovie(movies, count);
                break;
            case 4:
                printf("Thank you for using the Relaxed Movie Rating System! Bye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }

        if (choice != 4) {
            printf("Press Enter to continue...");
            getchar(); // Wait for the user to press Enter
        }
    } while (choice != 4);

    return 0;
}

void addMovie(Movie movies[], int *count) {
    if (*count >= MAX_MOVIES) {
        printf("Movie limit reached! Can't add more movies.\n");
        return;
    }

    printf("Enter movie title: ");
    fgets(movies[*count].title, MAX_TITLE_LENGTH, stdin);
    movies[*count].title[strcspn(movies[*count].title, "\n")] = 0; // Remove the newline
    movies[*count].rating = 0; // Initialize rating to 0
    (*count)++;
    printf("Movie added successfully!\n");
}

void displayMovies(const Movie movies[], int count) {
    if (count == 0) {
        printf("No movies to display yet!\n");
        return;
    }

    printf("List of Movies:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - Rating: %s\n", i + 1, movies[i].title, movies[i].rating > 0 ? (char[4]){movies[i].rating + '0', '\0'} : "N/A");
    }
}

void rateMovie(Movie movies[], int count) {
    if (count == 0) {
        printf("You have no movies to rate!\n");
        return;
    }

    int index;
    printf("Enter the movie number to rate (1-%d): ", count);
    scanf("%d", &index);
    getchar(); // Consume the newline character

    if (index < 1 || index > count) {
        printf("Invalid movie number!\n");
        return;
    }

    int rating;
    printf("Enter rating for '%s' (0-10): ", movies[index - 1].title);
    scanf("%d", &rating);
    getchar(); // Consume the newline character

    if (rating < 0 || rating > 10) {
        printf("Rating must be between 0 and 10. Try again!\n");
        return;
    }

    movies[index - 1].rating = rating;
    printf("Rating for '%s' updated to %d!\n", movies[index - 1].title, rating);
}

void clearScreen() {
    // Clear the screen -- this works on most Unix/Linux terminals
    printf("\033[H\033[J");
}