//FormAI DATASET v1.0 Category: Movie Rating System ; Style: thoughtful
/*
  Movie Rating System
  This program allows users to rate movies and displays the average rating
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constant variables
#define MAX_MOVIES 10
#define MAX_NAME_LENGTH 50

// Struct for movie data
typedef struct {
    char name[MAX_NAME_LENGTH];
    int ratings[MAX_MOVIES];
    int num_ratings;
} Movie;

// Function declarations
void print_menu();
void add_movie(Movie movies[], int num_movies);
void rate_movie(Movie movies[], int num_movies);
void display_movies(Movie movies[], int num_movies);

int main() {
    Movie movies[MAX_MOVIES]; // Array to hold movie data
    int num_movies = 0; // Counter for number of movies added
    int choice; // User's menu choice

    // Loop to display menu and process user's choice
    do {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_movie(movies, num_movies);
                num_movies++;
                break;
            case 2:
                rate_movie(movies, num_movies);
                break;
            case 3:
                display_movies(movies, num_movies);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while(choice != 4);

    return 0;
}

// Function to print the menu
void print_menu() {
    printf("\nMovie Rating System\n");
    printf("--------------------\n");
    printf("1. Add movie\n");
    printf("2. Rate movie\n");
    printf("3. Display movies\n");
    printf("4. Exit\n");
}

// Function to add a movie to the movies array
void add_movie(Movie movies[], int num_movies) {
    char name[MAX_NAME_LENGTH];
    
    // Prompt user for movie name and add to movies array
    printf("Enter movie name: ");
    scanf("%s", name);
    strcpy(movies[num_movies].name, name);
    movies[num_movies].num_ratings = 0;
}

// Function to rate a movie
void rate_movie(Movie movies[], int num_movies) {
    char name[MAX_NAME_LENGTH];
    int rating;
    int movie_index = -1; // Initialize to -1 to check if movie was found
    
    // Prompt user for movie name to rate
    printf("Enter movie name: ");
    scanf("%s", name);

    // Loop through movies array to find the index of the movie to rate
    for(int i = 0; i < num_movies; i++) {
        if(strcmp(movies[i].name, name) == 0) {
            movie_index = i;
            break;
        }
    }

    // Check if movie was found
    if(movie_index == -1) {
        printf("Movie not found.\n");
        return;
    }

    // Prompt user for rating and add to movie's ratings array
    printf("Enter rating for %s: ", name);
    scanf("%d", &rating);
    movies[movie_index].ratings[movies[movie_index].num_ratings] = rating;
    movies[movie_index].num_ratings++;
}

// Function to display all movies and their average ratings
void display_movies(Movie movies[], int num_movies) {
    float average_rating;
    
    printf("Movie ratings:\n");
    printf("%-30s %s\n", "Movie Name", "Average Rating");
    printf("-----------------------------------\n");

    // Loop through movies array to display name and average rating for each movie
    for(int i = 0; i < num_movies; i++) {
        average_rating = 0;

        // Calculate average rating for movie
        if(movies[i].num_ratings > 0) {
            for(int j = 0; j < movies[i].num_ratings; j++) {
                average_rating += movies[i].ratings[j];
            }
            average_rating /= movies[i].num_ratings;
        }

        // Display movie name and average rating
        printf("%-30s %.1f\n", movies[i].name, average_rating);
    }
}