//FormAI DATASET v1.0 Category: Movie Rating System ; Style: complete
#include <stdio.h>

// Define struct for a movie
typedef struct {
    char title[100];
    int year;
    char director[100];
    float rating;
} Movie;

// Function to display movie details
void displayMovieDetails(Movie m) {
    printf("Title: %s\n", m.title);
    printf("Year: %d\n", m.year);
    printf("Director: %s\n", m.director);
    printf("Rating: %.2f\n\n", m.rating);
}

// Main function
int main() {
    // Declare an array of 10 movies
    Movie movies[10];
    
    // Get movie details from user
    for (int i = 0; i < 10; i++) {
        printf("Enter details for movie %d:\n", i+1);
        printf("Title: ");
        scanf("%s", movies[i].title);
        printf("Year: ");
        scanf("%d", &movies[i].year);
        printf("Director: ");
        scanf("%s", movies[i].director);
        printf("Rating (out of 10): ");
        scanf("%f", &movies[i].rating);
        printf("\n");
    }
    
    // Display all movies and their rating
    printf("All movies:\n");
    for (int i = 0; i < 10; i++) {
        displayMovieDetails(movies[i]);
    }
    
    // Calculate average rating of all movies
    float totalRating = 0.0f;
    for (int i = 0; i < 10; i++) {
        totalRating += movies[i].rating;
    }
    float avgRating = totalRating / 10.0f;
    
    // Display average rating
    printf("Average rating of all movies: %.2f\n", avgRating);
    
    // Display top 3 rated movies
    printf("Top 3 rated movies:\n");
    for (int i = 0; i < 2; i++) {
        float maxRating = 0.0f;
        int maxIndex = i;
        for (int j = i+1; j < 10; j++) {
            if (movies[j].rating > maxRating) {
                maxRating = movies[j].rating;
                maxIndex = j;
            }
        }
        // Swap movies at index i and maxIndex
        Movie temp = movies[i];
        movies[i] = movies[maxIndex];
        movies[maxIndex] = temp;
        
        displayMovieDetails(movies[i]);
    }
    
    return 0;
}