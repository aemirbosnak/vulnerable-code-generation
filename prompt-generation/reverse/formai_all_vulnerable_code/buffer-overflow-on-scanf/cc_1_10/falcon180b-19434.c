//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 5

typedef struct {
    char title[100];
    int ratings[MAX_RATINGS];
    double average_rating;
} Movie;

void add_rating(Movie* movie, int rating) {
    if (movie->average_rating == 0) {
        movie->average_rating = rating;
    } else {
        movie->average_rating = ((movie->average_rating * (MAX_RATINGS - 1)) + rating) / MAX_RATINGS;
    }
}

int main() {
    Movie movies[MAX_MOVIES];
    int num_movies = 0;
    int num_ratings = 0;

    printf("Welcome to the Movie Rating System!\n");
    while (1) {
        printf("Please choose an option:\n");
        printf("1. Add a movie\n");
        printf("2. Rate a movie\n");
        printf("3. View all movies and ratings\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_movies >= MAX_MOVIES) {
                printf("Sorry, you have reached the maximum number of movies.\n");
            } else {
                printf("Enter the title of the movie: ");
                scanf("%s", movies[num_movies].title);
                num_movies++;
            }
            break;
        case 2:
            if (num_movies == 0) {
                printf("Sorry, there are no movies to rate.\n");
            } else {
                printf("Enter the rating for the movie (1-5): ");
                int rating;
                scanf("%d", &rating);
                int movie_index;
                printf("Enter the index of the movie (1-%d): ", num_movies);
                scanf("%d", &movie_index);
                add_rating(&movies[movie_index - 1], rating);
                num_ratings++;
            }
            break;
        case 3:
            if (num_movies == 0) {
                printf("Sorry, there are no movies to view.\n");
            } else {
                printf("Movie Ratings:\n");
                for (int i = 0; i < num_movies; i++) {
                    printf("%s: %.1f\n", movies[i].title, movies[i].average_rating);
                }
            }
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}