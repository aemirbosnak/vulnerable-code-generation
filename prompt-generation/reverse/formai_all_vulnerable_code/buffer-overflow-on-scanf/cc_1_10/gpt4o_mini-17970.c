//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define NAME_LENGTH 100

typedef struct {
    char name[NAME_LENGTH];
    int ratingsCount;
    double totalRating;
} Movie;

void addMovie(Movie movies[], int *movieCount);
void rateMovie(Movie movies[], int movieCount);
void displayMovies(Movie movies[], int movieCount);
void calculateAverageRatings(Movie movies[], int movieCount);

int main() {
    Movie movies[MAX_MOVIES];
    int movieCount = 0;
    int choice;

    do {
        printf("\n--- Movie Rating System ---\n");
        printf("1. Add Movie\n");
        printf("2. Rate Movie\n");
        printf("3. Display Movies and Ratings\n");
        printf("4. Exit\n");
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(movies, &movieCount);
                break;
            case 2:
                rateMovie(movies, movieCount);
                break;
            case 3:
                displayMovies(movies, movieCount);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void addMovie(Movie movies[], int *movieCount) {
    if (*movieCount >= MAX_MOVIES) {
        printf("Movie list is full. Cannot add more movies.\n");
        return;
    }

    printf("Enter movie name: ");
    getchar(); // Clear the newline from previous input
    fgets(movies[*movieCount].name, NAME_LENGTH, stdin);
    movies[*movieCount].name[strcspn(movies[*movieCount].name, "\n")] = 0; // Remove newline

    movies[*movieCount].ratingsCount = 0;
    movies[*movieCount].totalRating = 0.0;

    (*movieCount)++;
    printf("Movie '%s' added successfully!\n", movies[*movieCount - 1].name);
}

void rateMovie(Movie movies[], int movieCount) {
    if (movieCount == 0) {
        printf("No movies available to rate. Add some movies first.\n");
        return;
    }

    char movieName[NAME_LENGTH];
    double rating;

    printf("Enter movie name to rate: ");
    getchar(); // Clear the newline
    fgets(movieName, NAME_LENGTH, stdin);
    movieName[strcspn(movieName, "\n")] = 0; // Remove newline

    int found = 0;
    for (int i = 0; i < movieCount; i++) {
        if (strcmp(movies[i].name, movieName) == 0) {
            found = 1;
            printf("Enter rating for '%s' (1-5): ", movies[i].name);
            scanf("%lf", &rating);
            
            if (rating < 1 || rating > 5) {
                printf("Rating must be between 1 and 5!\n");
                return;
            }

            movies[i].totalRating += rating;
            movies[i].ratingsCount++;
            printf("Rating of %.1f added for '%s'.\n", rating, movies[i].name);
            break;
        }
    }

    if (!found) {
        printf("Movie '%s' not found.\n", movieName);
    }
}

void displayMovies(Movie movies[], int movieCount) {
    if (movieCount == 0) {
        printf("No movies available.\n");
        return;
    }

    printf("\n--- Movie List with Average Ratings ---\n");
    for (int i = 0; i < movieCount; i++) {
        printf("Movie: %s\n", movies[i].name);
        if (movies[i].ratingsCount > 0) {
            double averageRating = movies[i].totalRating / movies[i].ratingsCount;
            printf("Average Rating: %.2f from %d ratings\n", averageRating, movies[i].ratingsCount);
        } else {
            printf("No ratings yet.\n");
        }
        printf("\n");
    }
}