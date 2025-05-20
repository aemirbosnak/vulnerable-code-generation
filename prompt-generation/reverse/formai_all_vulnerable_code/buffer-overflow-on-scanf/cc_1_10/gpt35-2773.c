//FormAI DATASET v1.0 Category: Movie Rating System ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TITLE_LENGTH 50
#define MAX_PLATFORM_LENGTH 20
#define MAX_RATING_LENGTH 3
#define MAX_NUM_MOVIES 50

// Struct to store movies
typedef struct {
    char title[MAX_TITLE_LENGTH];
    char platform[MAX_PLATFORM_LENGTH];
    char rating[MAX_RATING_LENGTH];
} Movie;

// Function declarations
void add_movie(Movie* movies, int* num_movies);
void display_movies(Movie* movies, int num_movies);
void rate_movie(Movie* movies, int num_movies);
int menu();

int main() {
    // Initialize movie array and counter
    Movie movies[MAX_NUM_MOVIES];
    int num_movies = 0;

    while(1) {
        int choice = menu();

        switch(choice) {
            case 1:
                add_movie(movies, &num_movies);
                break;
            case 2:
                display_movies(movies, num_movies);
                break;
            case 3:
                rate_movie(movies, num_movies);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

void add_movie(Movie* movies, int* num_movies) {
    // Check if there is space left for a new movie
    if(*num_movies == MAX_NUM_MOVIES) {
        printf("Cannot add more movies.\n");
        return;
    }

    // Prompt user for movie information
    printf("Enter movie title: ");
    scanf("%s", movies[*num_movies].title);

    printf("Enter platform: ");
    scanf("%s", movies[*num_movies].platform);

    printf("Enter rating (out of 10): ");
    scanf("%s", movies[*num_movies].rating);

    // Increment counter
    (*num_movies)++;
}

void display_movies(Movie* movies, int num_movies) {
    // Check if there are any movies to display
    if(num_movies == 0) {
        printf("No movies found.\n");
        return;
    }

    // Loop through and print movie information
    printf("%-30s %-20s %-10s\n", "Title", "Platform", "Rating");
    printf("----------------------------------------------------------------------------------\n");

    for(int i = 0; i < num_movies; i++) {
        printf("%-30s %-20s %-10s\n", movies[i].title, movies[i].platform, movies[i].rating);
    }
}

void rate_movie(Movie* movies, int num_movies) {
    // Check if there are any movies to rate
    if(num_movies == 0) {
        printf("No movies found.\n");
        return;
    }

    // Prompt user for movie title
    char title[MAX_TITLE_LENGTH];
    printf("Enter the title of the movie to rate: ");
    scanf("%s", title);

    // Find movie in array
    Movie* movie = NULL;

    for(int i = 0; i < num_movies; i++) {
        if(strcmp(movies[i].title, title) == 0) {
            movie = &movies[i];
            break;
        }
    }

    // Check if movie was found
    if(movie == NULL) {
        printf("Movie not found.\n");
        return;
    }

    // Prompt user for rating
    printf("Enter rating (out of 10) for %s: ", movie->title);
    scanf("%s", movie->rating);
}

int menu() {
    // Display menu options
    printf("Movie Rating System\n");
    printf("-------------------\n");
    printf("1. Add movie\n");
    printf("2. Display movies\n");
    printf("3. Rate movie\n");
    printf("4. Exit\n");

    // Prompt user for choice
    printf("Enter choice: ");
    int choice;
    scanf("%d", &choice);

    return choice;
}