//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold movie information
typedef struct {
    char title[100];
    char genre[50];
    int year;
    float rating;
    char reviewer[50];
} Movie;

// Declare global variables
Movie *movieList = NULL;
int movieCount = 0;

// Function to add a new movie
void addMovie() {
    movieCount++;
    movieList = realloc(movieList, movieCount * sizeof(Movie));
    
    printf("Enter movie title: ");
    scanf(" %[^\n]%*c", movieList[movieCount - 1].title);
    
    printf("Enter genre: ");
    scanf(" %[^\n]%*c", movieList[movieCount - 1].genre);
    
    printf("Enter year of release: ");
    scanf("%d", &movieList[movieCount - 1].year);
    
    printf("Enter rating (0.0 to 10.0): ");
    scanf("%f", &movieList[movieCount - 1].rating);
    
    printf("Enter reviewer's name: ");
    scanf(" %[^\n]%*c", movieList[movieCount - 1].reviewer);
    
    printf("Movie '%s' added successfully!\n", movieList[movieCount - 1].title);
}

// Function to display all movies
void displayMovies() {
    if (movieCount == 0) {
        printf("\nNo movies available to display.\n");
        return;
    }
    
    printf("\n--- Movie List ---\n");
    for (int i = 0; i < movieCount; i++) {
        printf("Movie #%d: \n", i + 1);
        printf("Title: %s\n", movieList[i].title);
        printf("Genre: %s\n", movieList[i].genre);
        printf("Year: %d\n", movieList[i].year);
        printf("Rating: %.1f\n", movieList[i].rating);
        printf("Reviewer: %s\n\n", movieList[i].reviewer);
    }
}

// Function to delete a movie by title
void deleteMovie() {
    char title[100];
    int found = 0;

    printf("Enter the title of the movie to delete: ");
    scanf(" %[^\n]%*c", title);

    for (int i = 0; i < movieCount; i++) {
        if (strcmp(movieList[i].title, title) == 0) {
            found = 1;
            for (int j = i; j < movieCount - 1; j++) {
                movieList[j] = movieList[j + 1];
            }
            movieCount--;
            movieList = realloc(movieList, movieCount * sizeof(Movie));
            printf("Movie '%s' deleted successfully!\n", title);
            break;
        }
    }
    
    if (!found) {
        printf("Movie with title '%s' not found!\n", title);
    }
}

// Function for user menu
void showMenu() {
    int choice;

    while (1) {
        printf("\n--- Movie Rating System ---\n");
        printf("1. Add Movie\n");
        printf("2. Display Movies\n");
        printf("3. Delete Movie\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie();
                break;
            case 2:
                displayMovies();
                break;
            case 3:
                deleteMovie();
                break;
            case 4:
                printf("Exiting the movie rating system. Goodbye!\n");
                free(movieList);
                return;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
}

int main() {
    // Initialize movie list
    movieList = NULL;
    movieCount = 0;

    // Show user menu
    showMenu();

    return 0;
}