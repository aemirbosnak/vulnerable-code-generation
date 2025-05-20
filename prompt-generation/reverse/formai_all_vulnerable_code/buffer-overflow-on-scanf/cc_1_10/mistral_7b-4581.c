//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: high level of detail
#include <stdio.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_REVIEWS 20
#define MAX_NAME_LENGTH 50
#define MAX_REVIEW_LENGTH 200

// Movie struct
typedef struct {
    char title[MAX_NAME_LENGTH];
    float rating;
    int num_reviews;
    struct {
        char review[MAX_REVIEW_LENGTH];
        float rating;
    } reviews[MAX_REVIEWS];
} Movie;

void print_movie(Movie movie) {
    printf("%s (%.2f) - %d reviews\n", movie.title, movie.rating, movie.num_reviews);
    printf("----------------------------------------------------\n");
    printf("Review                                            Rating\n");
    for (int i = 0; i < movie.num_reviews; i++) {
        printf("%s                             %.2f\n", movie.reviews[i].review, movie.reviews[i].rating);
    }
}

void read_movie(Movie *movie) {
    printf("Enter movie title: ");
    fgets(movie->title, MAX_NAME_LENGTH, stdin);
    movie->title[strcspn(movie->title, "\n")] = '\0';

    printf("Enter movie rating (out of 10): ");
    scanf("%f", &movie->rating);

    printf("Enter number of reviews: ");
    scanf("%d", &movie->num_reviews);

    for (int i = 0; i < movie->num_reviews; i++) {
        printf("Enter review %d: ", i + 1);
        fgets(movie->reviews[i].review, MAX_REVIEW_LENGTH, stdin);
        movie->reviews[i].review[strcspn(movie->reviews[i].review, "\n")] = '\0';
        printf("Enter review rating (out of 10): ");
        scanf("%f", &movie->reviews[i].rating);
    }
}

int main() {
    Movie movies[MAX_MOVIES];
    int num_movies = 0;

    while (num_movies < MAX_MOVIES) {
        printf("Do you want to add a new movie? (y/n): ");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'y') {
            read_movie(&movies[num_movies]);
            num_movies++;
        }
    }

    printf("\nMovie Listings:\n");

    for (int i = 0; i < num_movies; i++) {
        print_movie(movies[i]);
    }

    return 0;
}