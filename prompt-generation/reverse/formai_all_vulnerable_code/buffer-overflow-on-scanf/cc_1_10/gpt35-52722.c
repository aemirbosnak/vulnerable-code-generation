//FormAI DATASET v1.0 Category: Movie Rating System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_RATINGS 10
#define MIN_RATING 0
#define MAX_RATING 10

// Function to display menu and get choice from user
int displayMenuAndGetChoice() {
    int choice;
    printf("\nWelcome to the Movie Rating System\n");
    printf("---------------------------------\n");
    printf("1. Add a new movie rating\n");
    printf("2. View the ratings for a movie\n");
    printf("3. View the average rating for a movie\n");
    printf("4. View the highest rated movie\n");
    printf("5. View the lowest rated movie\n");
    printf("6. Exit\n");
    printf("---------------------------------\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function to add a new rating for a movie
void addMovieRating(int ratings[][2], int numRatings, int movieID) {
    if (numRatings >= MAX_RATINGS) {
        printf("Maximum number of ratings reached for this movie.\n");
        return;
    }
    int rating;
    printf("Enter a rating between %d and %d for movie %d: ", MIN_RATING, MAX_RATING, movieID);
    scanf("%d", &rating);
    if (rating < MIN_RATING || rating > MAX_RATING) {
        printf("Invalid rating entered.\n");
        return;
    }
    ratings[numRatings][0] = movieID;
    ratings[numRatings][1] = rating;
    printf("Movie rating added successfully.\n");
}

// Function to view all ratings for a movie
void viewMovieRatings(int ratings[][2], int numRatings, int movieID) {
    printf("Ratings for movie %d:\n", movieID);
    int count = 0;
    for (int i = 0; i < numRatings; i++) {
        if (ratings[i][0] == movieID) {
            printf("%d. %d\n", ++count, ratings[i][1]);
        }
    }
    if (count == 0) {
        printf("No ratings found for this movie.\n");
    }
}

// Function to view the average rating for a movie
void viewMovieAverageRating(int ratings[][2], int numRatings, int movieID) {
    int sumRating = 0;
    int count = 0;
    for (int i = 0; i < numRatings; i++) {
        if (ratings[i][0] == movieID) {
            sumRating += ratings[i][1];
            count++;
        }
    }
    double averageRating = (count == 0) ? 0 : (double) sumRating / count;
    printf("Average rating for movie %d: %.2f\n", movieID, averageRating);
}

// Function to view the highest rated movie
void viewHighestRatedMovie(int ratings[][2], int numRatings) {
    int maxRating = -1;
    int maxMovieID = -1;
    for (int i = 0; i < numRatings; i++) {
        if (ratings[i][1] > maxRating) {
            maxRating = ratings[i][1];
            maxMovieID = ratings[i][0];
        }
    }
    if (maxMovieID == -1) {
        printf("No movies found.\n");
    } else {
        printf("Movie %d has the highest rating of %d.\n", maxMovieID, maxRating);
    }
}

// Function to view the lowest rated movie
void viewLowestRatedMovie(int ratings[][2], int numRatings) {
    int minRating = 11;
    int minMovieID = -1;
    for (int i = 0; i < numRatings; i++) {
        if (ratings[i][1] < minRating) {
            minRating = ratings[i][1];
            minMovieID = ratings[i][0];
        }
    }
    if (minMovieID == -1) {
        printf("No movies found.\n");
    } else {
        printf("Movie %d has the lowest rating of %d.\n", minMovieID, minRating);
    }
}

int main() {
    int ratings[MAX_RATINGS][2] = {{1, 7}, {2, 9}, {1, 8}, {3, 6}, {2, 6}};
    int numRatings = 5;

    int choice = 0;
    while (choice != 6) {
        choice = displayMenuAndGetChoice();
        switch (choice) {
            case 1:
                {
                    int movieID;
                    printf("Enter the movie ID (1-100): ");
                    scanf("%d", &movieID);
                    addMovieRating(ratings, numRatings++, movieID);
                    break;
                }
            case 2:
                {
                    int movieID;
                    printf("Enter the movie ID (1-100): ");
                    scanf("%d", &movieID);
                    viewMovieRatings(ratings, numRatings, movieID);
                    break;
                }
            case 3:
                {
                    int movieID;
                    printf("Enter the movie ID (1-100): ");
                    scanf("%d", &movieID);
                    viewMovieAverageRating(ratings, numRatings, movieID);
                    break;
                }
            case 4:
                {
                    viewHighestRatedMovie(ratings, numRatings);
                    break;
                }
            case 5:
                {
                    viewLowestRatedMovie(ratings, numRatings);
                    break;
                }
            case 6:
                {
                    printf("Exiting program. Goodbye!\n");
                    break;
                }
            default:
                {
                    printf("Invalid choice entered. Please try again.\n");
                    break;
                }
        }
    }

    return 0;
}