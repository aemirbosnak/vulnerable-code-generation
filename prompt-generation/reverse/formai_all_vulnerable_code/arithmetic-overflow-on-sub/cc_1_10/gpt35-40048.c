//FormAI DATASET v1.0 Category: Movie Rating System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store movie information
struct movie {
    char* title;
    char* director;
    int year;
    float rating;
};

// Function to compare movie ratings for sorting
int compare_ratings(const void* a, const void* b) {
    float rating_a = ((struct movie*) a)->rating;
    float rating_b = ((struct movie*) b)->rating;
    return (rating_a > rating_b) - (rating_a < rating_b);
}

// Function to print single movie's information
void print_movie(struct movie m) {
    printf("%s, %s, %d, %.1f\n", m.title, m.director, m.year, m.rating);
}

// Function to print top rated movies
void print_top_rated(struct movie* movies, int num_movies) {
    int i = 0;
    printf("-------TOP RATED MOVIES-------\n");
    for (i = num_movies-1; i >= 0; i--) {
        if (movies[i].rating >= 8.0) {
            print_movie(movies[i]);
        }
    }
    printf("------------------------------\n");
}

int main() {
    // Prompt user for number of movies and allocate memory for movies array
    int num_movies = 0;
    printf("Enter number of movies: ");
    scanf("%d", &num_movies);
    struct movie* movies = (struct movie*) malloc(num_movies * sizeof(struct movie));

    // Prompt user for movie information and store in movies array
    int i = 0;
    for (i = 0; i < num_movies; i++) {
        printf("Movie %d: \n", i+1);
        movies[i].title = (char*) malloc(256 * sizeof(char));
        printf("Title: ");
        scanf(" %[^\n]s", movies[i].title);
        movies[i].director = (char*) malloc(256 * sizeof(char));
        printf("Director: ");
        scanf(" %[^\n]s", movies[i].director);
        printf("Year: ");
        scanf("%d", &movies[i].year);
        printf("Rating (0.0-10.0): ");
        scanf("%f", &movies[i].rating);
    }

    // Sort movies by rating in ascending order
    qsort(movies, num_movies, sizeof(struct movie), compare_ratings);

    // Print top rated movies
    print_top_rated(movies, num_movies);

    // Free allocated memory
    for (i = 0; i < num_movies; i++) {
        free(movies[i].title);
        free(movies[i].director);
    }
    free(movies);

    return 0;
}