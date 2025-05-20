//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 50

typedef struct {
    char title[MAX_TITLE_LENGTH];
    float rating;
} Movie;

void addMovie(Movie movies[], int *count);
void viewMovies(Movie movies[], int count);
void calculateAverageRating(Movie movies[], int count);
void clearBuffer();

int main() {
    Movie movies[MAX_MOVIES];
    int count = 0;
    int choice;

    printf("*******************************\n");
    printf("     Retro Movie Rating System   \n");
    printf("*******************************\n");

    do {
        printf("\nMenu:\n");
        printf("1. Add Movie\n");
        printf("2. View Movies\n");
        printf("3. Calculate Average Rating\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer(); // Clear newline left by scanf

        switch (choice) {
            case 1:
                if (count < MAX_MOVIES) {
                    addMovie(movies, &count);
                } else {
                    printf("Movie list is full!\n");
                }
                break;
            case 2:
                viewMovies(movies, count);
                break;
            case 3:
                calculateAverageRating(movies, count);
                break;
            case 4:
                printf("Exiting... Thank you for using the Retro Movie Rating System!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}

void addMovie(Movie movies[], int *count) {
    Movie newMovie;
    printf("Enter movie title: ");
    fgets(newMovie.title, MAX_TITLE_LENGTH, stdin);
    newMovie.title[strcspn(newMovie.title, "\n")] = 0; // Remove trailing newline

    printf("Enter rating (0.0 to 5.0): ");
    scanf("%f", &newMovie.rating);
    clearBuffer(); // Clear newline left by scanf

    if (newMovie.rating < 0.0 || newMovie.rating > 5.0) {
        printf("Invalid rating! Rating must be between 0.0 and 5.0.\n");
    } else {
        movies[*count] = newMovie;
        (*count)++;
        printf("Movie added successfully!\n");
    }
}

void viewMovies(Movie movies[], int count) {
    if (count == 0) {
        printf("No movies to display!\n");
        return;
    }

    printf("\nList of Movies:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. \"%s\" - Rating: %.1f\n", i + 1, movies[i].title, movies[i].rating);
    }
}

void calculateAverageRating(Movie movies[], int count) {
    if (count == 0) {
        printf("No ratings available for calculation!\n");
        return;
    }

    float total = 0.0;
    for (int i = 0; i < count; i++) {
        total += movies[i].rating;
    }
    float average = total / count;
    printf("Average rating of added movies: %.2f\n", average);
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}