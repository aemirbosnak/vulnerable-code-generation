//FormAI DATASET v1.0 Category: Movie Rating System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100

// Structure to represent a movie
struct Movie {
    char title[50];
    int year;
    float rating;
};

// Function to add a new movie to the movies array
void addMovie(struct Movie *movies, int *count) {
    if (*count >= MAX_MOVIES) {
        printf("Maximum number of movies reached.\n");
        return;
    }

    struct Movie new_movie;

    printf("Enter the title of the movie: ");
    scanf("%[^\n]%*c", new_movie.title);  // read the title with spaces and discard the newline

    printf("Enter the year of the movie: ");
    scanf("%d", &new_movie.year);

    printf("Enter the rating of the movie (out of 10): ");
    scanf("%f", &new_movie.rating);

    movies[*count] = new_movie;
    (*count)++;

    printf("Movie added successfully.\n");
}

// Function to list all the movies in the movies array
void listMovies(struct Movie *movies, int count) {
    if (count == 0) {
        printf("No movies found.\n");
        return;
    }

    printf("List of movies:\n");

    for (int i = 0; i < count; i++) {
        printf("%s (%d) - %.1f/10\n", movies[i].title, movies[i].year, movies[i].rating);
    }
}

// Function to rate a movie
void rateMovie(struct Movie *movies, int count) {
    if (count == 0) {
        printf("No movies found.\n");
        return;
    }

    char movie_title[50];
    int found = 0;

    printf("Enter the title of the movie you want to rate: ");
    scanf("%[^\n]%*c", movie_title);  // read the title with spaces and discard the newline

    for (int i = 0; i < count; i++) {
        if (strcmp(movies[i].title, movie_title) == 0) {
            printf("Current rating for %s (%d) is %.1f/10\n", movies[i].title, movies[i].year, movies[i].rating);

            printf("Enter your rating for this movie (out of 10): ");
            scanf("%f", &movies[i].rating);

            printf("Thanks for your rating!\n");

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Movie not found.\n");
    }
}

// Function to display statistics about the movies
void displayStats(struct Movie *movies, int count) {
    if (count == 0) {
        printf("No movies found.\n");
        return;
    }

    float total_rating = 0;
    float min_rating = 10;
    float max_rating = 0;

    for (int i = 0; i < count; i++) {
        total_rating += movies[i].rating;

        if (movies[i].rating < min_rating) {
            min_rating = movies[i].rating;
        }

        if (movies[i].rating > max_rating) {
            max_rating = movies[i].rating;
        }
    }

    float avg_rating = total_rating / count;

    printf("Number of movies: %d\n", count);
    printf("Average rating: %.1f/10\n", avg_rating);
    printf("Minimum rating: %.1f/10\n", min_rating);
    printf("Maximum rating: %.1f/10\n", max_rating);
}

int main() {
    printf("----- C Movie Rating System -----\n");

    struct Movie movies[MAX_MOVIES];
    int count = 0;

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Add a new movie\n");
        printf("2. List all the movies\n");
        printf("3. Rate a movie\n");
        printf("4. Display statistics\n");
        printf("5. Exit\n");

        int option;
        scanf("%d", &option);

        switch (option) {
            case 1:
                addMovie(movies, &count);
                break;
            case 2:
                listMovies(movies, count);
                break;
            case 3:
                rateMovie(movies, count);
                break;
            case 4:
                displayStats(movies, count);
                break;
            case 5:
                printf("Thank you for using C Movie Rating System!\n");
                exit(0);
            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}