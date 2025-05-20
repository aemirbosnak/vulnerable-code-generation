//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: detailed
#include <stdio.h>

// Define the movie rating system
enum rating_t {
    RATING_G,
    RATING_PG,
    RATING_PG_13,
    RATING_R,
    RATING_NC_17
};

// Define the movie struct
typedef struct {
    char *title;
    enum rating_t rating;
    int year;
} movie_t;

// Create a function to print the movie rating
void print_rating(enum rating_t rating) {
    switch (rating) {
        case RATING_G:
            printf("G");
            break;
        case RATING_PG:
            printf("PG");
            break;
        case RATING_PG_13:
            printf("PG-13");
            break;
        case RATING_R:
            printf("R");
            break;
        case RATING_NC_17:
            printf("NC-17");
            break;
        default:
            printf("Invalid rating");
            break;
    }
}

// Create a function to print the movie information
void print_movie(movie_t movie) {
    printf("%s (%d) ", movie.title, movie.year);
    print_rating(movie.rating);
    printf("\n");
}

// Create a function to compare two movies by rating
int compare_movies_by_rating(movie_t movie1, movie_t movie2) {
    return movie1.rating - movie2.rating;
}

// Create a function to sort an array of movies by rating
void sort_movies_by_rating(movie_t movies[], int num_movies) {
    qsort(movies, num_movies, sizeof(movie_t), compare_movies_by_rating);
}

// Create a function to get the user's input for a movie
movie_t get_movie_input() {
    movie_t movie;

    printf("Enter the movie title: ");
    scanf("%s", movie.title);

    printf("Enter the movie year: ");
    scanf("%d", &movie.year);

    printf("Enter the movie rating (G, PG, PG-13, R, or NC-17): ");
    char rating_input[3];
    scanf("%s", rating_input);

    if (strcmp(rating_input, "G") == 0) {
        movie.rating = RATING_G;
    } else if (strcmp(rating_input, "PG") == 0) {
        movie.rating = RATING_PG;
    } else if (strcmp(rating_input, "PG-13") == 0) {
        movie.rating = RATING_PG_13;
    } else if (strcmp(rating_input, "R") == 0) {
        movie.rating = RATING_R;
    } else if (strcmp(rating_input, "NC-17") == 0) {
        movie.rating = RATING_NC_17;
    } else {
        printf("Invalid rating input. Please enter a valid rating (G, PG, PG-13, R, or NC-17).");
        movie.rating = -1;
    }

    return movie;
}

// Create a function to print the menu
void print_menu() {
    printf("\n");
    printf("1. Add a movie\n");
    printf("2. List all movies\n");
    printf("3. Sort movies by rating\n");
    printf("4. Quit\n");
    printf("\n");
}

// Create the main function
int main() {
    // Create an array of movies
    movie_t movies[100];

    // Set the number of movies to 0
    int num_movies = 0;

    // Print the menu
    print_menu();

    // Get the user's choice
    int choice;
    scanf("%d", &choice);

    // While the user does not choose to quit
    while (choice != 4) {
        // Switch on the user's choice
        switch (choice) {
            case 1:
                // Add a movie to the array
                movies[num_movies] = get_movie_input();
                num_movies++;
                break;
            case 2:
                // List all movies
                for (int i = 0; i < num_movies; i++) {
                    print_movie(movies[i]);
                }
                break;
            case 3:
                // Sort movies by rating
                sort_movies_by_rating(movies, num_movies);
                break;
            default:
                // Invalid choice
                printf("Invalid choice. Please enter a valid choice (1-4).");
                break;
        }

        // Print the menu
        print_menu();

        // Get the user's choice
        scanf("%d", &choice);
    }

    return 0;
}