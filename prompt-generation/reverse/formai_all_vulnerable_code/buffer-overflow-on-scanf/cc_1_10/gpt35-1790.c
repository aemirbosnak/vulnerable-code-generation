//FormAI DATASET v1.0 Category: Movie Rating System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of movies in the system
#define MAX_MOVIES 50

// Define the maximum length of a movie title
#define MAX_TITLE_LEN 100

// Declare the struct for a movie
typedef struct {
    char title[MAX_TITLE_LEN];
    int rating;
} Movie;

// Declare the array to hold all the movies
Movie movie_list[MAX_MOVIES];

// Declare the current number of movies in the system
int current_num_movies = 0;

// Function to add a movie to the system
void add_movie() {
    // Check if the maximum number of movies has been reached
    if (current_num_movies >= MAX_MOVIES) {
        printf("Sorry, the maximum number of movies has been reached.\n");
        return;
    }
    
    // Get movie title from user
    char title[MAX_TITLE_LEN];
    printf("Enter the movie title: ");
    scanf("%s", title);
    
    // Get movie rating from user
    int rating;
    printf("Enter the movie rating (1-10): ");
    scanf("%d", &rating);
    
    // Create the movie and add it to the list
    Movie new_movie;
    strcpy(new_movie.title, title);
    new_movie.rating = rating;
    movie_list[current_num_movies++] = new_movie;
    
    printf("Movie added!\n");
}

// Function to display all the movies in the system
void display_movies() {
    if (current_num_movies == 0) {
        printf("No movies have been added yet.\n");
        return;
    }
    
    printf("Movie Title\t\t\tRating\n");
    for (int i = 0; i < current_num_movies; i++) {
        printf("%-30s\t%d\n", movie_list[i].title, movie_list[i].rating);
    }
}

// Main function
int main() {
    // Display welcome message
    printf("Welcome to the Unique C Movie Rating System!\n");
    
    // Display menu options
    printf("Menu Options:\n");
    printf("1. Add a movie\n");
    printf("2. Display all movies\n");
    printf("3. Quit\n");
    
    while (1) {
        // Get user's choice
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        // Perform action based on user's choice
        switch (choice) {
            case 1:
                add_movie();
                break;
            case 2:
                display_movies();
                break;
            case 3:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}