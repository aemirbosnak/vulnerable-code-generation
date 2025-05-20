//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_MOVIE_NAME 100
#define MAX_RATINGS 5
#define MAX_RATING 5

typedef struct {
    char name[MAX_MOVIE_NAME];
    int ratings[MAX_RATINGS];
    int total_rating;
    int num_ratings;
} Movie;

void add_rating(Movie* movie, int rating) {
    if (movie->num_ratings < MAX_RATINGS) {
        movie->ratings[movie->num_ratings] = rating;
        movie->num_ratings++;
        movie->total_rating += rating;
    }
}

int get_average_rating(Movie* movie) {
    return (float)movie->total_rating / movie->num_ratings;
}

int main() {
    Movie movie = {"", {0}, 0, 0};

    while (1) {
        printf("Enter movie name: ");
        scanf("%s", movie.name);

        if (strlen(movie.name) == 0) {
            printf("Invalid movie name.\n");
            continue;
        }

        printf("Enter rating (0-5): ");
        int rating;
        if (scanf("%d", &rating)!= 1 || rating < 0 || rating > 5) {
            printf("Invalid rating.\n");
            continue;
        }

        add_rating(&movie, rating);

        printf("Movie added.\n");
    }

    return 0;
}