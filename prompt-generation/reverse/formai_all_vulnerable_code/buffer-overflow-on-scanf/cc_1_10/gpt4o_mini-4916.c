//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 100

// Structure to hold movie information
typedef struct {
    char title[MAX_TITLE_LENGTH];
    int rating; // Scale of 1 to 5
} Movie;

// Array to hold all movies
Movie movieDB[MAX_MOVIES];
int movieCount = 0;

// Function to display menu
void displayMenu() {
    printf("\n=========================\n");
    printf(" Post-Apocalyptic Movie Rating System\n");
    printf("=========================\n");
    printf("1. Add a Movie\n");
    printf("2. Rate a Movie\n");
    printf("3. Display Movies\n");
    printf("4. Exit\n");
    printf("=========================\n");
    printf("Choose an option (1-4): ");
}

// Function to add a movie
void addMovie() {
    if (movieCount >= MAX_MOVIES) {
        printf("Cannot add more movies. Database is full!\n");
        return;
    }
    
    printf("Enter the movie title: ");
    getchar(); // Clear newline from input buffer
    fgets(movieDB[movieCount].title, MAX_TITLE_LENGTH, stdin);
    movieDB[movieCount].title[strcspn(movieDB[movieCount].title, "\n")] = '\0'; // Remove newline character
    movieDB[movieCount].rating = 0; // Initialize rating to 0
    movieCount++;
    printf("Movie '%s' added to the database.\n", movieDB[movieCount - 1].title);
}

// Function to rate a movie
void rateMovie() {
    char title[MAX_TITLE_LENGTH];
    printf("Enter the title of the movie to rate: ");
    getchar(); // Clear newline from input buffer
    fgets(title, MAX_TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = '\0'; // Remove newline character

    for (int i = 0; i < movieCount; i++) {
        if (strcmp(movieDB[i].title, title) == 0) {
            printf("Enter your rating (1-5): ");
            int newRating;
            scanf("%d", &newRating);
            if (newRating < 1 || newRating > 5) {
                printf("Invalid rating! Please enter a value between 1 and 5.\n");
            } else {
                movieDB[i].rating = newRating;
                printf("You've rated the movie '%s' with a score of %d.\n", movieDB[i].title, newRating);
            }
            return;
        }
    }

    printf("Movie '%s' not found in the database.\n", title);
}

// Function to display all movies
void displayMovies() {
    if (movieCount == 0) {
        printf("No movies in the database.\n");
        return;
    }
    
    printf("\nList of Movies:\n");
    for (int i = 0; i < movieCount; i++) {
        printf("Title: %s, Rating: %d\n", movieDB[i].title, movieDB[i].rating);
    }
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
                displayMovies();
                break;
            case 4:
                printf("Exiting the program. Stay safe out there!\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose between 1 and 4.\n");
        }
    }

    return 0;
}