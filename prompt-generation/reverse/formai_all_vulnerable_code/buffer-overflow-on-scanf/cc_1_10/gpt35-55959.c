//FormAI DATASET v1.0 Category: Movie Rating System ; Style: protected
#include <stdio.h>

// Define a constant for the maximum number of movies
#define MAX_MOVIES 10

// Define struct for a movie
typedef struct {
    char title[50];
    char director[50];
    int year;
    float rating;
} Movie;

// Declare an array of movies
Movie movies[MAX_MOVIES];

// Declare a variable for the current number of movies
int num_movies = 0;

// Function for adding a new movie
void add_movie() {
    // Check if the maximum number of movies has been reached
    if (num_movies == MAX_MOVIES) {
        printf("Maximum number of movies reached.\n");
        return;
    }
    
    // Get input from the user for the new movie
    Movie new_movie;
    printf("Enter the title of the movie: ");
    fgets(new_movie.title, 50, stdin);
    printf("Enter the name of the director: ");
    fgets(new_movie.director, 50, stdin);
    printf("Enter the year the movie was released: ");
    scanf("%d", &new_movie.year);
    printf("Enter the movie rating (out of 10): ");
    scanf("%f", &new_movie.rating);
    getchar(); // Consume the \n character left in the input buffer
    
    // Add the new movie to the array and increment the number of movies
    movies[num_movies] = new_movie;
    num_movies++;
    
    printf("Movie added successfully.\n");
}

// Function for displaying all the movies
void display_movies() {
    // Check if there are any movies to display
    if (num_movies == 0) {
        printf("No movies to display.\n");
        return;
    }
    
    // Loop through the array of movies and display each movie
    for (int i = 0; i < num_movies; i++) {
        printf("Title: %s", movies[i].title);
        printf("Director: %s", movies[i].director);
        printf("Year: %d\n", movies[i].year);
        printf("Rating: %.1f\n", movies[i].rating);
    }
}

// Function for calculating the average rating of all the movies
void calculate_average_rating() {
    // Check if there are any movies to calculate the average rating for
    if (num_movies == 0) {
        printf("No movies to calculate average rating for.\n");
        return;
    }
    
    // Calculate the sum of all the ratings
    float sum_ratings = 0;
    for (int i = 0; i < num_movies; i++) {
        sum_ratings += movies[i].rating;
    }
    
    // Calculate the average rating and display it
    float avg_rating = sum_ratings / num_movies;
    printf("The average rating of all the movies is: %.2f\n", avg_rating);
}

int main() {
    // Declare a variable for the user's choice
    int choice;
    
    // Loop through the menu until the user chooses to exit
    do {
        // Display the menu and get the user's choice
        printf("\n1. Add a new movie\n");
        printf("2. Display all the movies\n");
        printf("3. Calculate the average rating of all the movies\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume the \n character left in the input buffer
        
        // Perform the action based on the user's choice
        switch (choice) {
            case 1:
                add_movie();
                break;
            case 2:
                display_movies();
                break;
            case 3:
                calculate_average_rating();
                break;
            case 4:
                printf("Thank you for using the movie rating system.\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
    } while (choice != 4);
    
    return 0;
}