//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 10

struct movie {
    char title[100];
    int ratings[MAX_RATINGS];
    int num_ratings;
};

void add_rating(struct movie *movie, int rating) {
    if (movie->num_ratings == MAX_RATINGS) {
        printf("Error: Movie has reached maximum number of ratings.\n");
        return;
    }
    movie->ratings[movie->num_ratings] = rating;
    movie->num_ratings++;
}

void print_ratings(struct movie *movie) {
    printf("Ratings for %s:\n", movie->title);
    for (int i = 0; i < movie->num_ratings; i++) {
        printf("%d\n", movie->ratings[i]);
    }
}

int main() {
    struct movie movies[MAX_MOVIES];
    int num_movies = 0;

    while (num_movies < MAX_MOVIES) {
        printf("Enter title of movie (or enter 'quit' to exit): ");
        scanf("%s", movies[num_movies].title);

        if (strcmp(movies[num_movies].title, "quit") == 0) {
            break;
        }

        num_movies++;
    }

    printf("Enter ratings for each movie (0-10):\n");
    for (int i = 0; i < num_movies; i++) {
        add_rating(&movies[i], 0);
    }

    char title[100];
    while (1) {
        printf("Enter title of movie to view ratings: ");
        scanf("%s", title);

        for (int i = 0; i < num_movies; i++) {
            if (strcmp(movies[i].title, title) == 0) {
                print_ratings(&movies[i]);
                break;
            }
        }
    }

    return 0;
}