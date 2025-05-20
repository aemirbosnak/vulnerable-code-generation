//FormAI DATASET v1.0 Category: Movie Rating System ; Style: light-weight
#include <stdio.h>

// Structure to store movie details
typedef struct {
    char name[50];
    char genre[20];
    int year;
    float rating;
} Movie;

// Function to get movie details from user
void get_movie_details(Movie *movie) {
    printf("Enter movie name: ");
    scanf("%[^\n]", movie->name);
    printf("Enter movie genre: ");
    scanf(" %[^\n]", movie->genre);
    printf("Enter movie year: ");
    scanf("%d", &movie->year);
    printf("Enter movie rating (out of 10): ");
    scanf("%f", &movie->rating);
}

// Function to display movie details
void display_movie_details(Movie *movie) {
    printf("Name: %s\n", movie->name);
    printf("Genre: %s\n", movie->genre);
    printf("Year: %d\n", movie->year);
    printf("Rating: %.1f/10\n", movie->rating);
    printf("\n");
}

int main() {
    int num_movies;
    printf("Welcome to C Movie Rating System!\n\n");
    printf("How many movies do you want to rate?");
    scanf("%d", &num_movies);

    Movie movies[num_movies];
    int i;
    for (i = 0; i < num_movies; i++) {
        printf("\nMovie %d: \n", i+1);
        get_movie_details(&movies[i]);
    }

    // Sort movies by rating
    for (i = 0; i < num_movies-1; i++) {
        int j;
        for (j = 0; j < num_movies-i-1; j++) {
            if (movies[j].rating < movies[j+1].rating) {
                Movie temp = movies[j];
                movies[j] = movies[j+1];
                movies[j+1] = temp;
            }
        }
    }

    // Display movies by rating
    printf("\nMovies sorted by rating (highest to lowest):\n");
    for (i = 0; i < num_movies; i++) {
        display_movie_details(&movies[i]);
    }

    return 0;
}