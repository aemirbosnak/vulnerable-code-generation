//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float ratings[MAX_MOVIES];
    int ratingCount;
    float averageRating;
} Movie;

Movie movieList[MAX_MOVIES];
int movieCount = 0;

void addMovie() {
    if (movieCount >= MAX_MOVIES) {
        printf("Movie List is full! Cannot add more movies.\n");
        return;
    }

    printf("Enter movie name: ");
    scanf("%s", movieList[movieCount].name);
    movieList[movieCount].ratingCount = 0;
    movieList[movieCount].averageRating = 0.0;
    movieCount++;
    printf("Movie '%s' added successfully!\n", movieList[movieCount - 1].name);
}

void rateMovie() {
    char movieName[MAX_NAME_LENGTH];
    printf("Enter movie name to rate: ");
    scanf("%s", movieName);

    for (int i = 0; i < movieCount; i++) {
        if (strcmp(movieList[i].name, movieName) == 0) {
            float rating;
            printf("Enter your rating (0.0 to 10.0): ");
            scanf("%f", &rating);

            if (rating < 0.0 || rating > 10.0) {
                printf("Invalid rating! Please enter a rating between 0.0 and 10.0.\n");
                return;
            }

            movieList[i].ratings[movieList[i].ratingCount] = rating;
            movieList[i].ratingCount++;
            // Recalculate average rating
            float total = 0.0;
            for (int j = 0; j < movieList[i].ratingCount; j++) {
                total += movieList[i].ratings[j];
            }
            movieList[i].averageRating = total / movieList[i].ratingCount;
            printf("Thank you! You rated '%s' with %.1f\n", movieList[i].name, rating);
            return;
        }
    }
    printf("Movie '%s' not found in the list.\n", movieName);
}

void viewMovies() {
    printf("Movies List:\n");
    for (int i = 0; i < movieCount; i++) {
        printf("%s - Average Rating: %.2f\n", movieList[i].name, movieList[i].averageRating);
    }
}

void viewMovieRatings() {
    char movieName[MAX_NAME_LENGTH];
    printf("Enter movie name to view ratings: ");
    scanf("%s", movieName);

    for (int i = 0; i < movieCount; i++) {
        if (strcmp(movieList[i].name, movieName) == 0) {
            printf("Ratings for '%s':\n", movieList[i].name);
            for (int j = 0; j < movieList[i].ratingCount; j++) {
                printf("%.1f ", movieList[i].ratings[j]);
            }
            printf("\nAverage Rating: %.2f\n", movieList[i].averageRating);
            return;
        }
    }
    printf("Movie '%s' not found in the list.\n", movieName);
}

void displayMenu() {
    printf("\nMovie Rating System\n");
    printf("1. Add Movie\n");
    printf("2. Rate Movie\n");
    printf("3. View Movies\n");
    printf("4. View Movie Ratings\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

int main() {
    int choice;
    
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addMovie();
                break;
            case 2:
                rateMovie();
                break;
            case 3:
                viewMovies();
                break;
            case 4:
                viewMovieRatings();
                break;
            case 5:
                printf("Exiting... Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please choose again.\n");
        }
    }
    
    return 0;
}