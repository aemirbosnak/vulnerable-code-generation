//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 100
#define MAX_REVIEW_LENGTH 500

typedef struct {
    char title[MAX_TITLE_LENGTH];
    float rating;
    char review[MAX_REVIEW_LENGTH];
} Movie;

Movie movieList[MAX_MOVIES];
int movieCount = 0;

void addMovie() {
    if (movieCount >= MAX_MOVIES) {
        printf("Movie list is full! Cannot add more movies.\n");
        return;
    }
    
    Movie newMovie;
    printf("Enter movie title: ");
    getchar(); // Consume newline left by previous input
    fgets(newMovie.title, MAX_TITLE_LENGTH, stdin);
    newMovie.title[strcspn(newMovie.title, "\n")] = 0;  // Remove newline character
    
    printf("Enter rating (0-5): ");
    scanf("%f", &newMovie.rating);
    if (newMovie.rating < 0 || newMovie.rating > 5) {
        printf("Invalid rating! Please enter a value between 0 and 5.\n");
        return;
    }
    
    printf("Enter review (max %d characters): ", MAX_REVIEW_LENGTH);
    getchar(); // Consume newline left by previous input
    fgets(newMovie.review, MAX_REVIEW_LENGTH, stdin);
    newMovie.review[strcspn(newMovie.review, "\n")] = 0; // Remove newline character

    movieList[movieCount++] = newMovie;
    printf("Movie added successfully!\n");
}

void displayMovies() {
    if (movieCount == 0) {
        printf("No movies to display.\n");
        return;
    }

    printf("\nList of Movies:\n");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < movieCount; i++) {
        printf("Title: %s\n", movieList[i].title);
        printf("Rating: %.1f\n", movieList[i].rating);
        printf("Review: %s\n", movieList[i].review);
        printf("-------------------------------------------------------------\n");
    }
}

void showMenu() {
    printf("\n===== Movie Rating System =====\n");
    printf("1. Add Movie\n");
    printf("2. Display Movies\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    
    while (1) {
        showMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addMovie();
                break;
            case 2:
                displayMovies();
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a number between 1 and 3.\n");
        }
    }
    
    return 0;
}