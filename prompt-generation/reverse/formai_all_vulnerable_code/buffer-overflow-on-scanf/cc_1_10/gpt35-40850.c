//FormAI DATASET v1.0 Category: Movie Rating System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of movies the system can handle
#define MAX_MOVIES 10

// Define the maximum length of the movie title
#define MAX_TITLE_LENGTH 50

// Define the maximum length of the rating comment
#define MAX_COMMENT_LENGTH 100

// Define the rating categories
#define EXCELLENT 5
#define GOOD 4
#define AVERAGE 3
#define POOR 2
#define TERRIBLE 1

// Define a struct for storing movie information
typedef struct {
    char title[MAX_TITLE_LENGTH];
    int rating;
    char comment[MAX_COMMENT_LENGTH];
} Movie;

// Define a function for inputting movie information
Movie input_movie() {
    Movie movie;
    printf("Enter the movie title (max %d characters): ", MAX_TITLE_LENGTH);
    fflush(stdin);  // Flush the buffer to prevent issues with fgets
    fgets(movie.title, MAX_TITLE_LENGTH, stdin);
    printf("Enter the rating (1-5): ");
    scanf("%d", &movie.rating);
    printf("Enter a comment (max %d characters): ", MAX_COMMENT_LENGTH);
    fflush(stdin);
    fgets(movie.comment, MAX_COMMENT_LENGTH, stdin);
    return movie;
}

// Define a function for displaying movie information
void display_movie(Movie movie) {
    printf("Title: %s", movie.title);
    printf("Rating: %d\n", movie.rating);
    printf("Comment: %s", movie.comment);
}

int main() {
    Movie movies[MAX_MOVIES];  // Array for storing movie information

    int num_movies = 0;  // Keep track of the number of movies added

    // Loop for inputting movies until the maximum is reached
    while (num_movies < MAX_MOVIES) {
        printf("\nMovie %d:\n", num_movies + 1);
        movies[num_movies] = input_movie();
        num_movies++;

        // Ask the user if they want to input another movie
        printf("\nDo you want to input another movie? (y/n): ");
        char option = getchar();
        if (option == 'n' || option == 'N') {
            break;
        }
    }

    // Loop for displaying all the movies
    printf("\nAll Movies:\n");
    for (int i = 0; i < num_movies; i++) {
        display_movie(movies[i]);

        // Give a rating comment based on the rating
        switch (movies[i].rating) {
            case EXCELLENT:
                printf("Wow, that was an excellent movie!\n");
                break;
            case GOOD:
                printf("That was a good movie.\n");
                break;
            case AVERAGE:
                printf("It was an okay movie.\n");
                break;
            case POOR:
                printf("That movie was not very good.\n");
                break;
            case TERRIBLE:
                printf("That was a terrible movie!\n");
                break;
            default:
                printf("Invalid rating.\n");
                break;
        }

        printf("\n");  // Add a blank line to separate movies
    }

    return 0;  // Exit program
}