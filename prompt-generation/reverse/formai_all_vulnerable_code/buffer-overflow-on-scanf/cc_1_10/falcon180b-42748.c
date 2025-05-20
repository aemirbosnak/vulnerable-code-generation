//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LEN 100
#define MAX_DIRECTOR_LEN 50
#define MAX_CAST_LEN 200
#define MAX_GENRE_LEN 50
#define MAX_PLOT_LEN 500
#define MAX_RATING 5
#define MAX_REVIEWS 10

typedef struct {
    char title[MAX_TITLE_LEN];
    char director[MAX_DIRECTOR_LEN];
    char cast[MAX_CAST_LEN];
    char genre[MAX_GENRE_LEN];
    char plot[MAX_PLOT_LEN];
    int rating;
    int num_reviews;
    char reviews[MAX_REVIEWS][MAX_PLOT_LEN];
} Movie;

void print_movie(const Movie *movie) {
    printf("Title: %s\n", movie->title);
    printf("Director: %s\n", movie->director);
    printf("Cast: %s\n", movie->cast);
    printf("Genre: %s\n", movie->genre);
    printf("Plot: %s\n", movie->plot);
    printf("Rating: %d\n", movie->rating);
    printf("Number of Reviews: %d\n", movie->num_reviews);
    for (int i = 0; i < movie->num_reviews; i++) {
        printf("Review %d: %s\n", i+1, movie->reviews[i]);
    }
}

int main() {
    Movie movie = {0};
    char input[MAX_PLOT_LEN];

    printf("Enter the title of the movie: ");
    scanf("%s", movie.title);

    printf("Enter the name of the director: ");
    scanf("%s", movie.director);

    printf("Enter the cast of the movie: ");
    scanf("%s", movie.cast);

    printf("Enter the genre of the movie: ");
    scanf("%s", movie.genre);

    printf("Enter the plot of the movie: ");
    scanf("%s", movie.plot);

    printf("Enter the rating of the movie (1-5): ");
    scanf("%d", &movie.rating);

    printf("Enter the number of reviews: ");
    scanf("%d", &movie.num_reviews);

    for (int i = 0; i < movie.num_reviews; i++) {
        printf("Enter review %d: ", i+1);
        scanf("%s", movie.reviews[i]);
    }

    printf("Movie Details:\n");
    print_movie(&movie);

    return 0;
}