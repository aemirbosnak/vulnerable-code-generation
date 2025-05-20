//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

// Movie structure definition
typedef struct {
    char title[50];
    char director[50];
    int year;
    double rating;
} Movie;

// Function declarations
void addMovie(Movie* movies, int* count);
void displayMovies(Movie* movies, int count);
void rateMovie(Movie* movies, int count);

int main() {
    int count = 0; // Number of movies stored
    int choice; // User's menu choice
    Movie movies[10]; // Maximum of 10 movies can be stored
    
    // Loop until user chooses to quit
    do {
        printf("\nMovie Rating System\n");
        printf("1. Add movie\n");
        printf("2. Display movies\n");
        printf("3. Rate movie\n");
        printf("4. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addMovie(movies, &count);
                break;
            case 2:
                displayMovies(movies, count);
                break;
            case 3:
                rateMovie(movies, count);
                break;
            case 4:
                printf("Thank you for using the Movie Rating System.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}

// Function definition for adding a movie
void addMovie(Movie* movies, int* count) {
    // Check if maximum number of movies have been reached
    if (*count == 10) {
        printf("Maximum number of movies reached. Cannot add more movies.\n");
        return;
    }
    
    Movie newMovie;
    
    // Get movie details from user
    printf("Enter the title of the movie: ");
    scanf(" %[^\n]", newMovie.title);
    printf("Enter the director of the movie: ");
    scanf(" %[^\n]", newMovie.director);
    printf("Enter the year of release of the movie: ");
    scanf("%d", &newMovie.year);
    newMovie.rating = -1; // Rating is not set yet
    
    movies[*count] = newMovie; // Add new movie to array
    (*count)++; // Increment movie count
}

// Function definition for displaying all movies
void displayMovies(Movie* movies, int count) {
    // Check if any movies have been stored
    if (count == 0) {
        printf("No movies to display.\n");
        return;
    }
    
    printf("\nAll Movies\n");
    printf("------------------------------------------------------------\n");
    printf("%-30s %-20s %-10s %-10s\n", "Title", "Director", "Year", "Rating");
    printf("------------------------------------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        printf("%-30s %-20s %-10d ", movies[i].title, movies[i].director, movies[i].year);
        if (movies[i].rating == -1) {
            printf("Not rated");
        } else {
            printf("%.1f/5", movies[i].rating);
        }
        printf("\n");
    }
}

// Function definition for rating a movie
void rateMovie(Movie* movies, int count) {
    // Check if any movies have been stored
    if (count == 0) {
        printf("No movies to rate.\n");
        return;
    }
    
    char title[50];
    int found = 0; // Flag to check if movie was found
    
    // Get title of movie to rate from user
    printf("Enter the title of the movie to rate: ");
    scanf(" %[^\n]", title);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            found = 1; // Movie found
            
            // Get rating from user
            double rating;
            printf("Enter rating for %s (out of 5): ", title);
            scanf("%lf", &rating);
            
            // Update movie rating
            movies[i].rating = rating;
            printf("Rating for %s set to %.1f/5.\n", title, rating);
            break;
        }
    }
    
    if (!found) {
        printf("Movie not found. Please check the title and try again.\n");
    }
}