//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

// Define the movie rating system
enum movie_rating {
    G,
    PG,
    PG_13,
    R,
    NC_17
};

// Define the movie struct
struct movie {
    char *title;
    enum movie_rating rating;
    int year;
};

// Create a function to print the movie rating
void print_movie_rating(enum movie_rating rating) {
    switch (rating) {
        case G:
            printf("G");
            break;
        case PG:
            printf("PG");
            break;
        case PG_13:
            printf("PG-13");
            break;
        case R:
            printf("R");
            break;
        case NC_17:
            printf("NC-17");
            break;
    }
}

// Create a function to print the movie
void print_movie(struct movie *movie) {
    printf("%s (%d) ", movie->title, movie->year);
    print_movie_rating(movie->rating);
    printf("\n");
}

// Create a function to compare two movies by rating
int compare_movies_by_rating(const void *a, const void *b) {
    struct movie *movie1 = (struct movie *)a;
    struct movie *movie2 = (struct movie *)b;
    return movie1->rating - movie2->rating;
}

// Create a function to sort the movies by rating
void sort_movies_by_rating(struct movie *movies, int num_movies) {
    qsort(movies, num_movies, sizeof(struct movie), compare_movies_by_rating);
}

// Create a function to get the user's input
void get_user_input(struct movie *movies, int *num_movies) {
    printf("Enter the number of movies: ");
    scanf("%d", num_movies);

    for (int i = 0; i < *num_movies; i++) {
        printf("Enter the title of movie %d: ", i + 1);
        scanf("%s", movies[i].title);

        printf("Enter the year of movie %d: ", i + 1);
        scanf("%d", &movies[i].year);

        printf("Enter the rating of movie %d: ", i + 1);
        scanf("%d", &movies[i].rating);
    }
}

// Create a function to print the movies
void print_movies(struct movie *movies, int num_movies) {
    for (int i = 0; i < num_movies; i++) {
        print_movie(&movies[i]);
    }
}

// Main function
int main() {
    // Declare the array of movies
    struct movie movies[100];

    // Get the user's input
    int num_movies;
    get_user_input(movies, &num_movies);

    // Sort the movies by rating
    sort_movies_by_rating(movies, num_movies);

    // Print the movies
    print_movies(movies, num_movies);

    return 0;
}