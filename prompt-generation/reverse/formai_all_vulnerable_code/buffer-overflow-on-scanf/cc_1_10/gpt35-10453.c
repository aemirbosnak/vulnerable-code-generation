//FormAI DATASET v1.0 Category: Movie Rating System ; Style: imaginative
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Declare the maximum size for title of the movie
#define MAX_TITLE_SIZE 50
// Declare the maximum number of movies that can be rated
#define MAX_MOVIE_CAPACITY 10

// Define struct to store movie details
typedef struct {
    char title[MAX_TITLE_SIZE];
    int rating;
} Movie;

// Initialize an array to store all the movies
Movie movies[MAX_MOVIE_CAPACITY];

// Initialize function to display menu for the user
void display_menu() {
    printf("Welcome to the C Movie Rating System!\n");
    printf("1. Add a movie\n");
    printf("2. View movies\n");
    printf("3. Rate a movie\n");
    printf("4. Exit\n");
}

// Initialize function to add a movie
void add_movie() {
    char title[MAX_TITLE_SIZE];
    int i = 0;

    // Get the title of the movie from the user
    printf("Enter the title of the movie: ");
    scanf("%s", title);

    // Find the first free index in the movies array
    while (movies[i].rating != 0) {
        i++;
    }

    // Check if the movie array is full
    if (i == MAX_MOVIE_CAPACITY) {
        printf("The movie list is full. Please rate a movie or remove a movie before adding another.\n");
        return;
    }

    // Add the movie to the array
    strcpy(movies[i].title, title);
    movies[i].rating = -1;

    printf("%s has been added to the movie list.\n", title);
}

// Initialize function to view all the movies
void view_movies() {
    int i = 0;
    bool list_empty = true;

    // Check if the movie list is empty
    for (i = 0; i < MAX_MOVIE_CAPACITY; i++) {
        if (movies[i].rating != 0) {
            list_empty = false;
            break;
        }
    }

    if (list_empty) {
        printf("The movie list is empty.\n");
        return;
    }

    // Display all the movies in the movie list
    printf("\nMovie List:\n");
    printf("---------------------------------\n");
    for (i = 0; i < MAX_MOVIE_CAPACITY; i++) {
        if (movies[i].rating != 0) {
            printf("%d. %s\n", i+1, movies[i].title);
        }
    }
}

// Initialize function to rate a movie
void rate_movie() {
    int movie_number, rating;

    // Get the movie number to rate from the user
    printf("Enter the movie number you wish to rate: ");
    scanf("%d", &movie_number);

    // Check if the movie number is valid
    if (movie_number < 1 || movie_number > MAX_MOVIE_CAPACITY || movies[movie_number-1].rating == 0) {
        printf("Invalid movie number.\n");
        return;
    }

    // Get the rating of the movie from the user
    printf("Enter your rating of %s (1-10): ", movies[movie_number-1].title);
    scanf("%d", &rating);

    // Check if the rating is valid
    if (rating < 1 || rating > 10) {
        printf("Invalid rating.\n");
        return;
    }

    // Save the rating of the movie in the movies array
    movies[movie_number-1].rating = rating;

    printf("Your rating of %d for %s has been saved.\n", rating, movies[movie_number-1].title);
}

int main() {
    int choice;

    do {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_movie();
                break;
            case 2:
                view_movies();
                break;
            case 3:
                rate_movie();
                break;
            case 4:
                printf("Thank you for using the C Movie Rating System.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
                break;
        }
    } while (true);

    return 0;
}