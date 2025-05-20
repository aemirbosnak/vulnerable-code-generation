//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 10

typedef struct {
    char title[100];
    int ratings[MAX_RATINGS];
    int num_ratings;
    double mean_rating;
    double std_dev;
} movie_t;

// Function to calculate the mean rating of a movie
double mean_rating(movie_t *movie) {
    double sum = 0;
    for (int i = 0; i < movie->num_ratings; i++) {
        sum += movie->ratings[i];
    }
    return sum / movie->num_ratings;
}

// Function to calculate the standard deviation of a movie's ratings
double std_dev(movie_t *movie) {
    double sum_of_squared_differences = 0;
    double mean = mean_rating(movie);
    for (int i = 0; i < movie->num_ratings; i++) {
        sum_of_squared_differences += pow(movie->ratings[i] - mean, 2);
    }
    return sqrt(sum_of_squared_differences / (movie->num_ratings - 1));
}

// Function to print the rating information for a movie
void print_movie(movie_t *movie) {
    printf("%s:\n", movie->title);
    printf("- Mean rating: %.2f\n", movie->mean_rating);
    printf("- Standard deviation: %.2f\n", movie->std_dev);
    printf("- Number of ratings: %d\n", movie->num_ratings);
    printf("- Ratings: ");
    for (int i = 0; i < movie->num_ratings; i++) {
        printf("%d ", movie->ratings[i]);
    }
    printf("\n");
}

// Function to compare two movies by their mean ratings
int compare_movies(const void *a, const void *b) {
    movie_t *movie1 = (movie_t *)a;
    movie_t *movie2 = (movie_t *)b;
    return movie1->mean_rating - movie2->mean_rating;
}

int main() {
    // Create an array of movies
    movie_t movies[MAX_MOVIES];

    // Read the movie data from a file
    FILE *fp = fopen("movies.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    int num_movies = 0;
    while (fscanf(fp, "%s", movies[num_movies].title) != EOF) {
        // Read the ratings for the movie
        for (int i = 0; i < MAX_RATINGS; i++) {
            fscanf(fp, "%d", &movies[num_movies].ratings[i]);
        }

        // Calculate the number of ratings for the movie
        movies[num_movies].num_ratings = 0;
        for (int i = 0; i < MAX_RATINGS; i++) {
            if (movies[num_movies].ratings[i] != 0) {
                movies[num_movies].num_ratings++;
            }
        }

        // Calculate the mean rating and standard deviation for the movie
        movies[num_movies].mean_rating = mean_rating(&movies[num_movies]);
        movies[num_movies].std_dev = std_dev(&movies[num_movies]);

        num_movies++;
    }

    fclose(fp);

    // Sort the movies by their mean ratings
    qsort(movies, num_movies, sizeof(movie_t), compare_movies);

    // Print the rating information for each movie
    for (int i = 0; i < num_movies; i++) {
        print_movie(&movies[i]);
    }

    return EXIT_SUCCESS;
}