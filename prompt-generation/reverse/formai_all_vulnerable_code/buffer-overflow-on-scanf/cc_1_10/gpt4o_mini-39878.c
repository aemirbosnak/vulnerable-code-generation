//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_USERS 50
#define MAX_NAME_LENGTH 50
#define MAX_TITLE_LENGTH 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    int ratings[MAX_USERS];
    int ratingCount;
} Movie;

Movie movies[MAX_MOVIES];
int movieCount = 0;

void addMovie(char* title);
void rateMovie(char* title, int userIndex, int rating);
void displayMovieRatings();
int getUserIndex(const char* name);
void loadMovies();
void saveMovies();

int main() {
    loadMovies();
    
    char option;
    char name[MAX_NAME_LENGTH];
    char title[MAX_TITLE_LENGTH];
    int rating, userIndex;

    printf("Welcome to the Movie Rating System!\n");
    printf("Please enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline character

    while (1) {
        printf("\nOptions:\n");
        printf("1. Add Movie\n");
        printf("2. Rate Movie\n");
        printf("3. Display Movie Ratings\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf(" %c", &option);
        getchar();  // Clear newline character from input buffer

        switch (option) {
            case '1':
                printf("Enter movie title: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline character
                addMovie(title);
                break;
            case '2':
                printf("Enter movie title to rate: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline character
                userIndex = getUserIndex(name);
                if (userIndex == -1) {
                    printf("Error: Maximum users reached.\n");
                } else {
                    printf("Rate the movie from 1 to 5: ");
                    scanf("%d", &rating);
                    if (rating < 1 || rating > 5) {
                        printf("Invalid rating! Please provide a rating between 1 and 5.\n");
                    } else {
                        rateMovie(title, userIndex, rating);
                    }
                }
                break;
            case '3':
                displayMovieRatings();
                break;
            case '4':
                saveMovies();
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
}

void addMovie(char* title) {
    if (movieCount < MAX_MOVIES) {
        strcpy(movies[movieCount].title, title);
        memset(movies[movieCount].ratings, 0, sizeof(movies[movieCount].ratings));
        movies[movieCount].ratingCount = 0;
        movieCount++;
        printf("Movie '%s' added.\n", title);
    } else {
        printf("Maximum movies reached, cannot add more.\n");
    }
}

void rateMovie(char* title, int userIndex, int rating) {
    for (int i = 0; i < movieCount; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            if (movies[i].ratings[userIndex] == 0) { // If the user has not rated
                movies[i].ratings[userIndex] = rating;
                movies[i].ratingCount++;
                printf("Thank you! Your rating for '%s' has been recorded.\n", title);
            } else {
                printf("You have already rated '%s'.\n", title);
            }
            return;
        }
    }
    printf("Movie '%s' not found.\n", title);
}

void displayMovieRatings() {
    printf("\nMovie Ratings:\n");
    for (int i = 0; i < movieCount; i++) {
        printf("Title: %s\n", movies[i].title);
        int totalRating = 0, numberOfRatings = 0;
        for (int j = 0; j < MAX_USERS; j++) {
            if (movies[i].ratings[j] != 0) {
                totalRating += movies[i].ratings[j];
                numberOfRatings++;
            }
        }
        if (numberOfRatings > 0) {
            printf("Average Rating: %.2f\n", (float)totalRating / numberOfRatings);
        } else {
            printf("No ratings yet.\n");
        }
    }
}

int getUserIndex(const char* name) {
    static char users[MAX_USERS][MAX_NAME_LENGTH];
    static int userCount = 0;

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i], name) == 0) {
            return i; // Return existing user index
        }
    }
    
    // Add new user if below limit
    if (userCount < MAX_USERS) {
        strcpy(users[userCount], name);
        return userCount++; // Return new user index
    }

    return -1; // Maximum users reached
}

void loadMovies() {
    FILE *file = fopen("movies.dat", "r");
    if (file) {
        while (fscanf(file, "%s", movies[movieCount].title) != EOF && movieCount < MAX_MOVIES) {
            fscanf(file, "%d", &movies[movieCount].ratingCount);
            for (int i = 0; i < MAX_USERS; i++) {
                fscanf(file, "%d", &movies[movieCount].ratings[i]);
            }
            movieCount++;
        }
        fclose(file);
    }
}

void saveMovies() {
    FILE *file = fopen("movies.dat", "w");
    if (file) {
        for (int i = 0; i < movieCount; i++) {
            fprintf(file, "%s\n", movies[i].title);
            fprintf(file, "%d\n", movies[i].ratingCount);
            for (int j = 0; j < MAX_USERS; j++) {
                fprintf(file, "%d ", movies[i].ratings[j]);
            }
            fprintf(file, "\n");
        }
        fclose(file);
    } else {
        printf("Error saving movies.\n");
    }
}