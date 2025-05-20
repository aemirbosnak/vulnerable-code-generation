//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define TITLE_LENGTH 100

typedef struct {
    char title[TITLE_LENGTH];
    float rating;
    int year;
} Movie;

Movie movieList[MAX_MOVIES];
int movieCount = 0;

void addMovie() {
    if (movieCount >= MAX_MOVIES) {
        printf("Movie list is full!\n");
        return;
    }
    
    Movie newMovie;
    printf("Enter movie title: ");
    getchar(); // consume newline
    fgets(newMovie.title, TITLE_LENGTH, stdin);
    newMovie.title[strcspn(newMovie.title, "\n")] = 0; // remove newline

    printf("Enter movie rating (0.0 to 10.0): ");
    scanf("%f", &newMovie.rating);
    printf("Enter release year: ");
    scanf("%d", &newMovie.year);

    movieList[movieCount++] = newMovie;
    printf("Movie added successfully!\n");
}

void viewMovies() {
    if (movieCount == 0) {
        printf("No movies available.\n");
        return;
    }

    printf("Movies List:\n");
    for (int i = 0; i < movieCount; i++) {
        printf("Title: %s, Rating: %.1f, Year: %d\n", 
               movieList[i].title, movieList[i].rating, movieList[i].year);
    }
}

void deleteMovie() {
    if (movieCount == 0) {
        printf("No movies available to delete.\n");
        return;
    }

    char title[TITLE_LENGTH];
    printf("Enter the title of the movie to delete: ");
    getchar(); // consume newline
    fgets(title, TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = 0; // remove newline

    for (int i = 0; i < movieCount; i++) {
        if (strcmp(movieList[i].title, title) == 0) {
            for (int j = i; j < movieCount - 1; j++) {
                movieList[j] = movieList[j + 1];
            }
            movieCount--;
            printf("Movie deleted successfully!\n");
            return;
        }
    }
    printf("Movie not found!\n");
}

void averageRating() {
    if (movieCount == 0) {
        printf("No movies available to calculate average rating.\n");
        return;
    }
    
    float totalRating = 0;
    for (int i = 0; i < movieCount; i++) {
        totalRating += movieList[i].rating;
    }
    
    printf("Average Movie Rating: %.2f\n", totalRating / movieCount);
}

void displayMenu() {
    printf("\nMovie Rating System\n");
    printf("1. Add Movie\n");
    printf("2. View Movies\n");
    printf("3. Delete Movie\n");
    printf("4. Display Average Rating\n");
    printf("5. Exit\n");
}

int main() {
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie();
                break;
            case 2:
                viewMovies();
                break;
            case 3:
                deleteMovie();
                break;
            case 4:
                averageRating();
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}