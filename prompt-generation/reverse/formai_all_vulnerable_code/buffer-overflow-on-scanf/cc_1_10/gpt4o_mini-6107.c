//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    float rating;
    int numRatings;
} Movie;

Movie movieList[MAX_MOVIES];
int movieCount = 0;

// Function prototypes
void addMovie();
void rateMovie();
void displayMovies();
float calculateAverageRating(Movie movie);

int main() {
    int choice;

    while (1) {
        printf("\n--- Movie Rating System ---\n");
        printf("1. Add Movie\n");
        printf("2. Rate Movie\n");
        printf("3. Display Movies\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie();
                break;
            case 2:
                rateMovie();
                break;
            case 3:
                displayMovies();
                break;
            case 4:
                printf("Exiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}

void addMovie() {
    if (movieCount >= MAX_MOVIES) {
        printf("Movie list is full. Cannot add more movies.\n");
        return;
    }
    
    printf("Enter the movie title: ");
    getchar(); // to consume newline character
    fgets(movieList[movieCount].title, MAX_TITLE_LENGTH, stdin);
    movieList[movieCount].title[strcspn(movieList[movieCount].title, "\n")] = 0; // remove newline
    movieList[movieCount].rating = 0.0;
    movieList[movieCount].numRatings = 0;
    movieCount++;
    printf("Movie '%s' added successfully!\n", movieList[movieCount - 1].title);
}

void rateMovie() {
    char title[MAX_TITLE_LENGTH];
    float rating;

    printf("Enter the movie title to rate: ");
    getchar(); // to consume newline character
    fgets(title, MAX_TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = 0; // remove newline

    for (int i = 0; i < movieCount; i++) {
        if (strcmp(movieList[i].title, title) == 0) {
            printf("Enter your rating (0.0 to 5.0): ");
            scanf("%f", &rating);
            if (rating >= 0.0 && rating <= 5.0) {
                movieList[i].rating += rating;
                movieList[i].numRatings++;
                printf("Thank you! You rated '%s' with %.1f\n", movieList[i].title, rating);
            } else {
                printf("Invalid rating. Rating should be between 0.0 and 5.0.\n");
            }
            return;
        }
    }
    printf("Movie '%s' not found!\n", title);
}

void displayMovies() {
    printf("\n--- List of Movies ---\n");
    for (int i = 0; i < movieCount; i++) {
        float avgRating = calculateAverageRating(movieList[i]);
        printf("Title: %s | Average Rating: %.1f | Total Ratings: %d\n", 
               movieList[i].title, avgRating, movieList[i].numRatings);
    }
    if (movieCount == 0) {
        printf("No movies in the list.\n");
    }
}

float calculateAverageRating(Movie movie) {
    if (movie.numRatings == 0) {
        return 0.0;
    }
    return movie.rating / movie.numRatings;
}