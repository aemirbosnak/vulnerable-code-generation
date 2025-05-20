//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 50

typedef struct {
    char title[MAX_TITLE_LENGTH];
    int rating;
} Movie;

int main() {
    Movie movies[MAX_MOVIES];
    int num_movies = 0;
    char title[MAX_TITLE_LENGTH];
    int rating;

    while (1) {
        printf("Enter movie title (or 'q' to quit): ");
        scanf("%s", title);
        if (strcmp(title, "q") == 0) {
            break;
        }

        printf("Enter movie rating (1-10): ");
        scanf("%d", &rating);

        if (num_movies >= MAX_MOVIES) {
            printf("Error: too many movies.\n");
            continue;
        }

        strcpy(movies[num_movies].title, title);
        movies[num_movies].rating = rating;
        num_movies++;
    }

    if (num_movies == 0) {
        printf("Error: no movies entered.\n");
        return 1;
    }

    int total_rating = 0;
    for (int i = 0; i < num_movies; i++) {
        total_rating += movies[i].rating;
    }

    float avg_rating = (float)total_rating / num_movies;
    printf("Average movie rating: %.2f\n", avg_rating);

    return 0;
}