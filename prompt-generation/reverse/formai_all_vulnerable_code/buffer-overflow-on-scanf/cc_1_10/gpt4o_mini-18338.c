//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: happy
#include <stdio.h>

#define MAX_MOVIES 100

// Structure to hold movie details
typedef struct {
    char title[100];
    float ratings[MAX_MOVIES];
    int ratingCount;
} Movie;

// Function to add a movie
void addMovie(Movie movies[], int *movieCount) {
    if (*movieCount >= MAX_MOVIES) {
        printf("Whoa! Can't add more movies. We're at maximum capacity!\n");
        return;
    }

    printf("Enter the movie title: ");
    getchar(); // to consume newline
    fgets(movies[*movieCount].title, 100, stdin);
    movies[*movieCount].ratings[0] = 0;
    movies[*movieCount].ratingCount = 0;
    (*movieCount)++;
    printf("Hooray! Movie added successfully!\n");
}

// Function to rate a movie
void rateMovie(Movie movies[], int movieCount) {
    char movieTitle[100];
    printf("Which movie do you want to rate? ");
    getchar(); // to consume newline
    fgets(movieTitle, 100, stdin);

    for (int i = 0; i < movieCount; i++) {
        if (strncmp(movieTitle, movies[i].title, strlen(movies[i].title) - 1) == 0) {
            float rating;
            printf("Enter your rating for '%s' (from 1.0 to 5.0): ", movies[i].title);
            scanf("%f", &rating);
            if (rating < 1.0 || rating > 5.0) {
                printf("Please provide a rating between 1.0 and 5.0.\n");
            } else {
                movies[i].ratings[movies[i].ratingCount++] = rating;
                printf("Thank you for rating '%s'! Your rating has been saved!\n", movies[i].title);
            }
            return;
        }
    }
    printf("Oh no! Movie not found in our happy collection!\n");
}

// Function to display average rating of a movie
void displayAverageRating(Movie movies[], int movieCount) {
    char movieTitle[100];
    printf("Which movie do you want to check the average rating for? ");
    getchar(); // to consume newline
    fgets(movieTitle, 100, stdin);

    for (int i = 0; i < movieCount; i++) {
        if (strncmp(movieTitle, movies[i].title, strlen(movies[i].title) - 1) == 0) {
            if (movies[i].ratingCount == 0) {
                printf("No ratings yet for '%s'. Be the first to rate it!\n", movies[i].title);
            } else {
                float sum = 0.0;
                for (int j = 0; j < movies[i].ratingCount; j++) {
                    sum += movies[i].ratings[j];
                }
                float average = sum / movies[i].ratingCount;
                printf("The average rating for '%s' is %.2f. Thank you for rating!\n", movies[i].title, average);
            }
            return;
        }
    }
    printf("Oh dear! Movie not found in our happy collection!\n");
}

int main() {
    Movie movies[MAX_MOVIES];
    int movieCount = 0;
    int choice;

    do {
        printf("\nWelcome to the Happy Movie Rating System!\n");
        printf("1. Add Movie\n");
        printf("2. Rate Movie\n");
        printf("3. Display Average Rating\n");
        printf("4. Exit\n");
        printf("Please choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(movies, &movieCount);
                break;
            case 2:
                rateMovie(movies, movieCount);
                break;
            case 3:
                displayAverageRating(movies, movieCount);
                break;
            case 4:
                printf("Thank you for using the Happy Movie Rating System! Goodbye!\n");
                break;
            default:
                printf("Oops! Invalid choice! Please choose again.\n");
        }
    } while (choice != 4);

    return 0;
}