//FormAI DATASET v1.0 Category: Movie Rating System ; Style: configurable
#include <stdio.h>
#include <string.h>

#define MAX_MOVIES 10
#define MAX_RATINGS 5

int movieCount = 0;
int ratingsCount = 0;

// Struct to represent a movie
struct Movie {
    char title[50];
    char genre[20];
    float rating[MAX_RATINGS];
    int numRatings;
};

// Array of movie objects
struct Movie movies[MAX_MOVIES];

// Function to display menu options
void displayMenu() {
    printf("\n--- Movie Rating System ---\n");
    printf("1. Add a movie\n");
    printf("2. Rate a movie\n");
    printf("3. View movie ratings\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

// Function to add a movie to the system
void addMovie() {
    if (movieCount == MAX_MOVIES) {
        printf("Sorry, cannot add more movies.\n");
        return;
    }

    struct Movie newMovie;

    printf("Enter movie title: ");
    fflush(stdin);
    fgets(newMovie.title, 50, stdin);
    newMovie.title[strcspn(newMovie.title, "\n")] = 0; // Remove trailing newline

    printf("Enter movie genre: ");
    fflush(stdin);
    fgets(newMovie.genre, 20, stdin);
    newMovie.genre[strcspn(newMovie.genre, "\n")] = 0; // Remove trailing newline

    newMovie.numRatings = 0;

    movies[movieCount++] = newMovie;
    printf("Movie added successfully.\n");
}

// Function to rate a movie
void rateMovie() {
    if (movieCount == 0) {
        printf("Sorry, no movies added to the system.\n");
        return;
    }

    char movieTitle[50];
    int i, j;
    float rating;

    printf("Enter movie title: ");
    fflush(stdin);
    fgets(movieTitle, 50, stdin);
    movieTitle[strcspn(movieTitle, "\n")] = 0; // Remove trailing newline

    for (i = 0; i < movieCount; i++) {
        if (strcmp(movies[i].title, movieTitle) == 0) {
            printf("Enter rating (0.0 - 10.0): ");
            fflush(stdin);
            scanf("%f", &rating);

            if (rating < 0.0 || rating > 10.0) {
                printf("Invalid rating. Rating must be between 0.0 and 10.0.\n");
                return;
            }

            if (movies[i].numRatings == MAX_RATINGS) {
                printf("Maximum number of ratings reached.\n");
                return;
            }

            movies[i].rating[movies[i].numRatings++] = rating;
            printf("Rating added successfully.\n");
            return;
        }
    }

    printf("Movie not found.\n");
}

// Function to view ratings of a movie
void viewRatings() {
    if (movieCount == 0) {
        printf("Sorry, no movies added to the system.\n");
        return;
    }

    char movieTitle[50];
    int i, j;

    printf("Enter movie title: ");
    fflush(stdin);
    fgets(movieTitle, 50, stdin);
    movieTitle[strcspn(movieTitle, "\n")] = 0; // Remove trailing newline

    for (i = 0; i < movieCount; i++) {
        if (strcmp(movies[i].title, movieTitle) == 0) {
            if (movies[i].numRatings == 0) {
                printf("No ratings found for this movie.\n");
                return;
            }

            printf("Ratings for %s:\n", movies[i].title);
            for (j = 0; j < movies[i].numRatings; j++) {
                printf("%.1f\n", movies[i].rating[j]);
            }
            return;
        }
    }

    printf("Movie not found.\n");
}

int main() {
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addMovie();
                break;
            case 2:
                rateMovie();
                break;
            case 3:
                viewRatings();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}