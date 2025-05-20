//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 5
#define MAX_RATING_VALUE 10

typedef struct {
    char title[50];
    int ratings[MAX_RATINGS];
    int num_ratings;
} Movie;

void print_movies(Movie movies[]) {
    printf("Movie Ratings:\n");
    for (int i = 0; i < MAX_MOVIES; i++) {
        if (movies[i].num_ratings > 0) {
            printf("Title: %s\n", movies[i].title);
            printf("Ratings: ");
            for (int j = 0; j < movies[i].num_ratings; j++) {
                printf("%d ", movies[i].ratings[j]);
            }
            printf("\n");
        }
    }
}

int main() {
    Movie movies[MAX_MOVIES];
    int num_movies, i, j;

    printf("Enter the number of movies: ");
    scanf("%d", &num_movies);

    for (i = 0; i < num_movies; i++) {
        printf("Enter movie %d title: ", i+1);
        scanf("%s", movies[i].title);
        movies[i].num_ratings = 0;
    }

    while (1) {
        printf("\nSelect an option:\n");
        printf("1. Add rating\n");
        printf("2. Print ratings\n");
        printf("3. Exit\n");
        scanf("%d", &j);

        switch (j) {
            case 1:
                printf("Enter movie title: ");
                scanf("%s", movies[i].title);
                printf("Enter rating (1-10): ");
                scanf("%d", &movies[i].ratings[movies[i].num_ratings]);
                movies[i].num_ratings++;
                break;
            case 2:
                print_movies(movies);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid option\n");
        }
    }

    return 0;
}