//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RATINGS 100

typedef struct {
    char movie_name[50];
    int ratings[MAX_RATINGS];
    int num_ratings;
} Movie;

void add_rating(Movie *movie, int rating) {
    if (movie->num_ratings >= MAX_RATINGS) {
        printf("Error: Cannot add more ratings.\n");
        return;
    }

    movie->ratings[movie->num_ratings] = rating;
    movie->num_ratings++;
}

void print_ratings(Movie *movie) {
    printf("Movie: %s\n", movie->movie_name);
    printf("Ratings:\n");

    for (int i = 0; i < movie->num_ratings; i++) {
        printf("%d\n", movie->ratings[i]);
    }
}

int main() {
    Movie movie;

    printf("Enter movie name: ");
    scanf("%s", movie.movie_name);

    while (1) {
        printf("\nOptions:\n");
        printf("1. Add rating\n");
        printf("2. Print ratings\n");
        printf("3. Exit\n");
        printf("Enter option: ");

        int option;
        scanf("%d", &option);

        switch (option) {
        case 1:
            printf("Enter rating: ");
            scanf("%d", &movie.ratings[movie.num_ratings]);
            add_rating(&movie, movie.ratings[movie.num_ratings]);
            break;

        case 2:
            print_ratings(&movie);
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid option.\n");
        }
    }

    return 0;
}