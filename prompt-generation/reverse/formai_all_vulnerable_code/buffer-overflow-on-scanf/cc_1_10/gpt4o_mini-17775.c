//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE 100
#define MAX_REVIEW 256

typedef struct {
    char title[MAX_TITLE];
    int year;
    float rating;        // Scale from 0.0 to 5.0
    char review[MAX_REVIEW];
} Movie;

void addMovie(Movie* movies, int* count);
void viewMovies(const Movie* movies, int count);
void shapeShiftMovie(Movie* movie);
void displayMenu();
void exitProgram();

int main() {
    Movie movies[MAX_MOVIES];
    int movieCount = 0;
    int choice;

    while (1) {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // clear newline from input buffer

        switch (choice) {
            case 1:
                addMovie(movies, &movieCount);
                break;
            case 2:
                viewMovies(movies, movieCount);
                break;
            case 3:
                if (movieCount > 0) {
                    printf("Shape-shifting movie...\n");
                    shapeShiftMovie(&movies[0]); // Transform first movie for fun
                } else {
                    printf("No movies to shape-shift!\n");
                }
                break;
            case 4:
                exitProgram();
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}

void addMovie(Movie* movies, int* count) {
    if (*count >= MAX_MOVIES) {
        printf("Movie limit reached! Cannot add more.\n");
        return;
    }
    Movie* newMovie = &movies[*count];

    printf("Enter movie title: ");
    fgets(newMovie->title, MAX_TITLE, stdin);
    newMovie->title[strcspn(newMovie->title, "\n")] = '\0'; // remove newline

    printf("Enter release year: ");
    scanf("%d", &newMovie->year);
    printf("Enter rating (0.0 - 5.0): ");
    scanf("%f", &newMovie->rating);
    getchar(); // clear newline

    printf("Enter review: ");
    fgets(newMovie->review, MAX_REVIEW, stdin);
    newMovie->review[strcspn(newMovie->review, "\n")] = '\0'; // remove newline

    (*count)++;
    printf("Movie added!\n");
}

void viewMovies(const Movie* movies, int count) {
    if (count == 0) {
        printf("No movies to display!\n");
    } else {
        printf("Movies:\n");
        for (int i = 0; i < count; i++) {
            printf("Title: %s\n", movies[i].title);
            printf("Year: %d\n", movies[i].year);
            printf("Rating: %.1f\n", movies[i].rating);
            printf("Review: %s\n", movies[i].review);
            printf("---------------------------\n");
        }
    }
}

void shapeShiftMovie(Movie* movie) {
    // Let's create a shape-shifting illusion
    printf("Transforming movie \"%s\"...\n", movie->title);
    printf("It's now a dance musical!\n");
    printf("Year: %d (reimagined)\n", movie->year + 5);
    printf("Rating: %.1f (flows like a melody)\n", movie->rating + 1.0);
    printf("Review: \"An expression of art beyond the screen!\"\n");
}

void displayMenu() {
    printf("\n--- Movie Rating System ---\n");
    printf("1. Add Movie\n");
    printf("2. View Movies\n");
    printf("3. Shape-Shift Movie\n");
    printf("4. Exit\n");
}

void exitProgram() {
    printf("Exiting the Movie Rating System. Have a great day!\n");
}