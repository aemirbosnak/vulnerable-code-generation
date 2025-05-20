//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the maximum number of movies that can be stored in the system
#define MAX_MOVIES 1000

// struct to hold all the information about a movie
typedef struct {
    char title[100];
    char director[100];
    int year;
    float rating;
} Movie;

// function to compare two movies for sorting
int movie_cmp(const void *a, const void *b) {
    Movie *ma = (Movie *) a;
    Movie *mb = (Movie *) b;
    if (ma->rating < mb->rating) {
        return 1;
    } else if (ma->rating > mb->rating) {
        return -1;
    } else {
        return strcmp(ma->title, mb->title);
    }
}

int main() {

    // array to hold all the movies
    Movie movies[MAX_MOVIES];
    int num_movies = 0;

    // loop to get information about each movie from the user
    while (num_movies < MAX_MOVIES) {
        printf("Enter the title of the movie: ");
        fgets(movies[num_movies].title, 100, stdin);

        // remove trailing newline from fgets
        movies[num_movies].title[strcspn(movies[num_movies].title, "\n")] = 0;

        printf("Enter the name of the director: ");
        fgets(movies[num_movies].director, 100, stdin);
        movies[num_movies].director[strcspn(movies[num_movies].director, "\n")] = 0;

        printf("Enter the year the movie was made: ");
        scanf(" %d", &movies[num_movies].year);

        printf("Enter the movie's rating out of 10: ");
        scanf(" %f", &movies[num_movies].rating);

        // remove any remaining characters from stdin input buffer
        while (getchar() != '\n') {}

        num_movies++;

        // ask the user if they want to add another movie
        char choice;
        printf("Do you want to enter another movie? (y/n) ");
        scanf(" %c", &choice);

        if (choice == 'n') {
            break;
        }

        // remove any remaining characters from stdin input buffer
        while (getchar() != '\n') {}
    }

    // sort the movies by rating (high to low), and then by title (A-Z)
    qsort(movies, num_movies, sizeof(Movie), movie_cmp);

    // display the movies in order
    printf("Movie Ratings\n");
    printf("--------------\n");
    printf("TITLE\t\t\t\tDIRECTOR\tYEAR\tRATING\n");
    printf("----------------------------------------------------------------\n");

    for (int i = 0; i < num_movies; i++) {
        printf("%-30s%-20s%-10d%.1f\n", movies[i].title, movies[i].director, movies[i].year, movies[i].rating);
    }

    return 0;
}