//FormAI DATASET v1.0 Category: Movie Rating System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 1000   // Maximum number of movies
#define MAX_STRING 100    // Maximum string length

// An enum to represent movie genres
typedef enum {
    ACTION,
    DRAMA,
    COMEDY,
    HORROR,
    DOCUMENTARY
} Genre;

// A struct to represent a movie
typedef struct {
    char title[MAX_STRING];
    int year;
    Genre genre;
    float rating;
} Movie;

// An array to hold all movies
Movie movies[MAX_MOVIES];

// Function to get a genre from user input
Genre get_genre() {
    int input;
    printf("Select a genre:\n");
    printf("1. Action\n");
    printf("2. Drama\n");
    printf("3. Comedy\n");
    printf("4. Horror\n");
    printf("5. Documentary\n");
    scanf("%d", &input);

    switch (input) {
        case 1:
            return ACTION;
        case 2:
            return DRAMA;
        case 3:
            return COMEDY;
        case 4:
            return HORROR;
        case 5:
            return DOCUMENTARY;
        default:
            printf("Invalid selection. Please try again.\n");
            return get_genre();
    }
}

// Function to add a movie to the array
void add_movie() {
    char title[MAX_STRING];
    int year;
    Genre genre;
    float rating;

    printf("Enter movie title: ");
    scanf(" %[^\n]%*c", title);

    printf("Enter release year: ");
    scanf("%d", &year);

    genre = get_genre();

    printf("Enter rating (0-10): ");
    scanf("%f", &rating);

    // Create movie struct and add to array
    Movie new_movie = {title, year, genre, rating};

    for (int i = 0; i < MAX_MOVIES; i++) {
        if (movies[i].year == 0) {
            movies[i] = new_movie;
            return;
        }
    }

    printf("Failed to add movie. Too many movies in database.\n");
}

// Function to rate a movie
void rate_movie() {
    char title[MAX_STRING];
    float rating;

    printf("Enter title of movie: ");
    scanf(" %[^\n]%*c", title);

    for (int i = 0; i < MAX_MOVIES; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            printf("Enter new rating for %s: ", title);
            scanf("%f", &rating);
            movies[i].rating = rating;
            return;
        }
    }

    printf("No movie with title %s found.\n", title);
}

// Function to print all movies in the array
void print_movies() {
    printf("Movies in database:\n");

    for (int i = 0; i < MAX_MOVIES; i++) {
        if (movies[i].year != 0) {
            printf("%s (%d) - ", movies[i].title, movies[i].year);

            switch (movies[i].genre) {
                case ACTION:
                    printf("Action");
                    break;
                case DRAMA:
                    printf("Drama");
                    break;
                case COMEDY:
                    printf("Comedy");
                    break;
                case HORROR:
                    printf("Horror");
                    break;
                case DOCUMENTARY:
                    printf("Documentary");
                    break;
                default:
                    break;
            }

            printf(" - %0.1f/10\n", movies[i].rating);
        }
    }
}

// Main function
int main() {
    int choice;

    while (1) {
        printf("\n1. Add movie\n");
        printf("2. Rate movie\n");
        printf("3. Print all movies\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_movie();
                break;
            case 2:
                rate_movie();
                break;
            case 3:
                print_movies();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}