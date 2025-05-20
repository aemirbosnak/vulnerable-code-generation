//FormAI DATASET v1.0 Category: Movie Rating System ; Style: single-threaded
#include <stdio.h>

// Define a struct to hold movie information
struct Movie {
    char title[50];
    int rating;
};

// Function to add a movie and its rating to the database
void add_movie(struct Movie *movies, int index) {
    printf("Enter the title of the movie: ");
    scanf("%s", movies[index].title);
    printf("Enter the rating of the movie (1-10): ");
    scanf("%d", &movies[index].rating);
}

// Function to print all movies in the database
void print_movies(struct Movie *movies, int num_movies) {
    printf("\nMovie Rating Database:\n");
    for (int i = 0; i < num_movies; i++) {
        printf("%s: %d\n", movies[i].title, movies[i].rating);
    }
}

int main() {
    // Initialize variables
    int num_movies = 0;
    int max_movies = 10;
    struct Movie movies[max_movies];

    // Display menu options
    printf("Welcome to the Movie Rating System!\n\n");
    printf("Please select an option:\n");
    printf("1. Add a movie and rating\n");
    printf("2. View movie ratings\n");
    printf("3. Quit\n\n");

    // Variable to store user's selected option
    int option;

    // Loop until user selects "Quit" option
    do {
        printf("Enter your selection number: ");
        scanf("%d", &option);

        switch (option) {
            // Add a movie and rating
            case 1:
                if (num_movies < max_movies) {
                    add_movie(movies, num_movies);
                    num_movies++;
                } else {
                    printf("Cannot add any more movies to database.\n");
                }
                break;

            // View movie ratings
            case 2:
                if (num_movies > 0) {
                    print_movies(movies, num_movies);
                } else {
                    printf("Database is empty.\n");
                }
                break;

            // Quit program
            case 3:
                printf("Quitting Movie Rating System.\n");
                break;

            // Invalid option selected
            default:
                printf("Invalid option selected.\n");
                break;
        }

    } while (option != 3);

    return 0;
}