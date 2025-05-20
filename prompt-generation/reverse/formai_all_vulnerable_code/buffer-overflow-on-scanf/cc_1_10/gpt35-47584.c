//FormAI DATASET v1.0 Category: Movie Rating System ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_MOVIES 100 // maximum number of movies that can be rated
#define MAX_RATING 10 // maximum rating a movie can have
#define MIN_RATING 1 // minimum rating a movie can have

// movie struct definition
typedef struct {
    char title[50];
    int rating;
} Movie;

// function prototypes
void printMenu();
void addMovie(Movie movies[], int *numMovies);
void viewMovies(Movie movies[], int numMovies);
void rateMovie(Movie movies[], int numMovies);

int main() {
    // array of movies
    Movie movies[MAX_MOVIES];
    int numMovies = 0; // number of movies currently in array
    
    // display menu
    int choice = 0;
    do {
        printMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addMovie(movies, &numMovies);
                break;
            case 2:
                viewMovies(movies, numMovies);
                break;
            case 3:
                rateMovie(movies, numMovies);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);
    
    return 0;
}

// prints main menu options
void printMenu() {
    printf("\n1. Add movie\n");
    printf("2. View movies\n");
    printf("3. Rate movie\n");
    printf("4. Quit\n");
    printf("Please enter your choice: ");
}

// adds a movie to array
void addMovie(Movie movies[], int *numMovies) {
    if (*numMovies >= MAX_MOVIES) {
        printf("Sorry, no space for new movies.\n");
    } else {
        printf("Please enter movie title: ");
        scanf("%s", &movies[*numMovies].title);
        movies[*numMovies].rating = -1; // set rating to -1 until rated
        printf("Movie added successfully.\n");
        *numMovies += 1; // increment number of movies
    }
}

// displays all movies in array
void viewMovies(Movie movies[], int numMovies) {
    if (numMovies == 0) {
        printf("No movies added yet.\n");
    } else {
        printf("\n%-50s|%s\n", "Title", "Rating");
        printf("--------------------------------------------------\n");
        for (int i = 0; i < numMovies; i++) {
            printf("%-50s|", movies[i].title);
            if (movies[i].rating == -1) {
                printf("Not rated\n");
            } else {
                printf("%d/10\n", movies[i].rating);
            }
        }
    }
}

// allows user to rate a movie from array
void rateMovie(Movie movies[], int numMovies) {
    if (numMovies == 0) {
        printf("No movies added yet.\n");
    } else {
        // display movies to choose from
        for (int i = 0; i < numMovies; i++) {
            printf("%d. %s\n", i+1, movies[i].title);
        }
        int choice = 0;
        do {
            printf("Please choose a movie to rate (1-%d): ", numMovies);
            scanf("%d", &choice);
            if (choice < 1 || choice > numMovies) {
                printf("Invalid choice. Please try again.\n");
            }
        } while (choice < 1 || choice > numMovies);
        
        // choose rating for selected movie
        int rating = 0;
        do {
            printf("Please enter rating for %s (1-10): ", movies[choice-1].title);
            scanf("%d", &rating);
            if (rating < MIN_RATING || rating > MAX_RATING) {
                printf("Invalid rating. Please enter a rating between 1 and 10.\n");
            }
        } while (rating < MIN_RATING || rating > MAX_RATING);
        
        // update movie rating
        movies[choice-1].rating = rating;
        printf("Rating added successfully.\n");
    }
}