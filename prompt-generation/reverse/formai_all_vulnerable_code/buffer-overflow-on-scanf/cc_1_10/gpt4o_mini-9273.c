//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_USERS 50
#define MAX_NAME_LEN 50
#define MAX_TITLE_LEN 100

typedef struct {
    char title[MAX_TITLE_LEN];
    float ratings[MAX_USERS]; // To hold ratings from different users
    int userCount;
} Movie;

void initializeMovies(Movie movies[], int *movieCount);
void addMovie(Movie movies[], int *movieCount);
void rateMovie(Movie movies[], int movieCount, const char* username);
void viewRatings(Movie movies[], int movieCount);
float calculateAverageRating(const Movie *movie);
void printMenu();

int main() {
    Movie movies[MAX_MOVIES];
    int movieCount = 0;
    char username[MAX_NAME_LEN];
    int choice;

    initializeMovies(movies, &movieCount);

    printf("Welcome to the Movie Rating System!\n");
    printf("Enter your username: ");
    fgets(username, MAX_NAME_LEN, stdin);
    username[strcspn(username, "\n")] = 0; // Remove newline character

    do {
        printMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(movies, &movieCount);
                break;
            case 2:
                rateMovie(movies, movieCount, username);
                break;
            case 3:
                viewRatings(movies, movieCount);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void initializeMovies(Movie movies[], int *movieCount) {
    *movieCount = 0; // Start with no movies
}

void addMovie(Movie movies[], int *movieCount) {
    if (*movieCount >= MAX_MOVIES) {
        printf("Cannot add more movies. Maximum limit reached.\n");
        return;
    }

    printf("Enter the movie title: ");
    getchar(); // Clear input buffer
    fgets(movies[*movieCount].title, MAX_TITLE_LEN, stdin);
    movies[*movieCount].title[strcspn(movies[*movieCount].title, "\n")] = 0; // Remove newline

    movies[*movieCount].userCount = 0; // Initialize user count
    (*movieCount)++;
    printf("Movie added successfully!\n");
}

void rateMovie(Movie movies[], int movieCount, const char* username) {
    char movieTitle[MAX_TITLE_LEN];
    float rating;

    printf("Enter the title of the movie you want to rate: ");
    getchar(); // Clear input buffer
    fgets(movieTitle, MAX_TITLE_LEN, stdin);
    movieTitle[strcspn(movieTitle, "\n")] = 0; // Remove newline

    for (int i = 0; i < movieCount; i++) {
        if (strcmp(movies[i].title, movieTitle) == 0) {
            if (movies[i].userCount >= MAX_USERS) {
                printf("Cannot add more ratings for this movie. Maximum limit reached.\n");
                return;
            }
            printf("Enter your rating (0.0 to 10.0): ");
            scanf("%f", &rating);
            if (rating < 0.0 || rating > 10.0) {
                printf("Invalid rating, must be between 0.0 and 10.0.\n");
                return;
            }
            movies[i].ratings[movies[i].userCount++] = rating; // Store rating
            printf("Rating added successfully!\n");
            return;
        }
    }
    printf("Movie not found!\n");
}

void viewRatings(Movie movies[], int movieCount) {
    for (int i = 0; i < movieCount; i++) {
        printf("Movie: %s\n", movies[i].title);
        if (movies[i].userCount > 0) {
            printf("Ratings: ");
            for (int j = 0; j < movies[i].userCount; j++) {
                printf("%.1f ", movies[i].ratings[j]);
            }
            printf("\nAverage Rating: %.2f\n", calculateAverageRating(&movies[i]));
        } else {
            printf("No ratings yet.\n");
        }
    }
}

float calculateAverageRating(const Movie *movie) {
    if (movie->userCount == 0) {
        return 0.0;
    }
    float sum = 0.0;
    for (int i = 0; i < movie->userCount; i++) {
        sum += movie->ratings[i];
    }
    return sum / movie->userCount;
}

void printMenu() {
    printf("\nMenu:\n");
    printf("1. Add Movie\n");
    printf("2. Rate Movie\n");
    printf("3. View Ratings\n");
    printf("4. Exit\n");
}