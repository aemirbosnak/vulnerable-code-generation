//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 5

typedef struct {
    char title[50];
    int ratings[MAX_RATINGS];
    int num_ratings;
} Movie;

void init_movie(Movie* movie) {
    strcpy(movie->title, "");
    for (int i = 0; i < MAX_RATINGS; i++) {
        movie->ratings[i] = 0;
    }
    movie->num_ratings = 0;
}

void print_movie(const Movie* movie) {
    printf("Title: %s\n", movie->title);
    printf("Ratings:");
    for (int i = 0; i < MAX_RATINGS; i++) {
        if (movie->ratings[i] > 0) {
            printf(" %d", movie->ratings[i]);
        }
    }
    printf("\n");
}

void add_rating(Movie* movie, int rating) {
    if (movie->num_ratings < MAX_RATINGS) {
        movie->ratings[movie->num_ratings++] = rating;
    }
}

int main() {
    Movie movies[MAX_MOVIES];
    int num_movies = 0;

    while (num_movies < MAX_MOVIES) {
        printf("Enter movie title: ");
        scanf("%s", movies[num_movies].title);
        init_movie(&movies[num_movies]);
        num_movies++;
    }

    while (1) {
        printf("Select a movie:\n");
        for (int i = 0; i < num_movies; i++) {
            print_movie(&movies[i]);
        }

        int choice;
        scanf("%d", &choice);
        if (choice >= 0 && choice < num_movies) {
            printf("Enter rating (0-5): ");
            int rating;
            scanf("%d", &rating);
            add_rating(&movies[choice], rating);
        }
    }

    return 0;
}