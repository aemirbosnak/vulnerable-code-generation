//FormAI DATASET v1.0 Category: Movie Rating System ; Style: single-threaded
#include <stdio.h>
#include <string.h>

#define MAX_MOVIES 100

// Struct definition for movie
struct Movie {
    char title[50];
    char director[30];
    int year;
    float rating;
};

// Array to store all movies
struct Movie movies[MAX_MOVIES];

// Total number of movies
int numMovies = 0;

// Function to add a movie to the array
void add_movie() {
    // Check if array is full
    if (numMovies >= MAX_MOVIES) {
        printf("Maximum number of movies reached!\n");
        return;
    }

    // Get user input for movie details
    printf("Enter title of movie: ");
    scanf("%s", movies[numMovies].title);
    printf("Enter director of movie: ");
    scanf("%s", movies[numMovies].director);
    printf("Enter year of release of movie: ");
    scanf("%d", &movies[numMovies].year);
    printf("Enter your rating of the movie (out of 10): ");
    scanf("%f", &movies[numMovies].rating);

    // Increment number of movies
    numMovies++;
}

// Function to display all movies in the array
void display_movies() {
    // Check if array is empty
    if (numMovies == 0) {
        printf("No movies to display!\n");
        return;
    }

    // Print table header
    printf("%-30s %-20s %-10s %-10s\n", "Title", "Director", "Year", "Rating");
    printf("-----------------------------------------------------------------\n");

    // Loop through array and print details of each movie
    for (int i = 0; i < numMovies; i++) {
        printf("%-30s %-20s %-10d %-10.2f\n", movies[i].title, movies[i].director, movies[i].year, movies[i].rating);
    }
}

// Function to search for a movie by title and display its details
void search_movie() {
    char searchTitle[50];
    int foundIndex = -1;

    // Get user input for title to search
    printf("Enter title of movie to search: ");
    scanf("%s", searchTitle);

    // Loop through array and search for movie with given title
    for (int i = 0; i < numMovies; i++) {
        if (strcmp(movies[i].title, searchTitle) == 0) {
            foundIndex = i;
            break;
        }
    }

    // If movie is found, display its details
    if (foundIndex != -1) {
        printf("%-30s %-20s %-10s %-10s\n", "Title", "Director", "Year", "Rating");
        printf("-----------------------------------------------------------------\n");
        printf("%-30s %-20s %-10d %-10.2f\n", movies[foundIndex].title, movies[foundIndex].director, movies[foundIndex].year, movies[foundIndex].rating);
    } else {
        printf("Movie not found!\n");
    }
}

// Function to update the rating of a movie by searching for it by title
void update_rating() {
    char searchTitle[50];
    int foundIndex = -1;

    // Get user input for title to search
    printf("Enter title of movie to update rating: ");
    scanf("%s", searchTitle);

    // Loop through array and search for movie with given title
    for (int i = 0; i < numMovies; i++) {
        if (strcmp(movies[i].title, searchTitle) == 0) {
            foundIndex = i;
            break;
        }
    }

    // If movie is found, get user input for new rating and update it
    if (foundIndex != -1) {
        float newRating;
        printf("Enter your new rating (out of 10) for %s: ", movies[foundIndex].title);
        scanf("%f", &newRating);
        movies[foundIndex].rating = newRating;
        printf("Rating updated successfully!\n");
    } else {
        printf("Movie not found!\n");
    }
}

// Main function
int main() {
    int choice;

    do {
        // Print menu and get user choice
        printf("\nWelcome to the Movie Rating System\n");
        printf("----------------------------------\n");
        printf("1. Add a movie\n");
        printf("2. Display all movies\n");
        printf("3. Search for a movie\n");
        printf("4. Update rating of a movie\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform action based on user choice
        switch (choice) {
            case 1:
                add_movie();
                break;
            case 2:
                display_movies();
                break;
            case 3:
                search_movie();
                break;
            case 4:
                update_rating();
                break;
            case 5:
                printf("Thank you for using the Movie Rating System!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}