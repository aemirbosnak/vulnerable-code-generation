//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RATINGS 100
#define MAX_MOVIES 100

typedef struct {
    char title[50];
    int ratings[MAX_RATINGS];
    int num_ratings;
} Movie;

void add_rating(Movie* movie, int rating) {
    if (movie->num_ratings >= MAX_RATINGS) {
        printf("ERROR: Maximum number of ratings reached.\n");
        return;
    }
    movie->ratings[movie->num_ratings++] = rating;
}

int main() {
    Movie movies[MAX_MOVIES];
    int num_movies = 0;
    char input[100];

    while (num_movies < MAX_MOVIES) {
        printf("Enter movie title: ");
        scanf("%s", input);
        strcpy(movies[num_movies].title, input);
        num_movies++;
    }

    while (1) {
        printf("Enter movie title to rate: ");
        scanf("%s", input);
        int movie_index = -1;
        for (int i = 0; i < num_movies; i++) {
            if (strcmp(movies[i].title, input) == 0) {
                movie_index = i;
                break;
            }
        }
        if (movie_index == -1) {
            printf("Movie not found.\n");
            continue;
        }
        printf("Enter rating (1-5): ");
        int rating;
        scanf("%d", &rating);
        add_rating(&movies[movie_index], rating);
    }

    return 0;
}