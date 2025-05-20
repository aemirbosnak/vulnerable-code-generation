//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 1000

typedef struct {
    char title[50];
    int year;
    char director[50];
    char actors[100];
    int length;
    int ratings;
    int num_votes;
    float avg_rating;
} Movie;

int compare_movies(const void *a, const void *b) {
    Movie *movie1 = (Movie *) a;
    Movie *movie2 = (Movie *) b;
    return strcmp(movie1->title, movie2->title);
}

int main() {
    int num_movies, num_ratings;
    scanf("%d", &num_movies);
    scanf("%d", &num_ratings);

    Movie movies[num_movies];
    for (int i = 0; i < num_movies; i++) {
        scanf("%s", movies[i].title);
        scanf("%d", &movies[i].year);
        scanf("%s", movies[i].director);
        scanf("%s", movies[i].actors);
        scanf("%d", &movies[i].length);
    }

    int ratings[num_ratings];
    char titles[num_ratings];
    scanf("%d", &movies[0].ratings);
    scanf("%d", &movies[0].num_votes);
    scanf("%f", &movies[0].avg_rating);
    strcpy(titles[0], movies[0].title);
    for (int i = 1; i < num_ratings; i++) {
        scanf("%d", &ratings[i]);
        scanf("%d", &movies[i].num_votes);
        scanf("%f", &movies[i].avg_rating);
        strcpy(titles[i], movies[i].title);
    }

    qsort(movies, num_movies, sizeof(Movie), compare_movies);
    qsort(ratings, num_ratings, sizeof(int), compare_movies);

    printf("Top 10 Movies:\n");
    for (int i = 0; i < num_movies; i++) {
        printf("%s (%d) - Director: %s - Actors: %s - Length: %d minutes\n", movies[i].title, movies[i].year, movies[i].director, movies[i].actors, movies[i].length);
    }

    printf("\nRatings:\n");
    for (int i = 0; i < num_ratings; i++) {
        printf("%s - %d votes - %.1f/10\n", titles[i], ratings[i], movies[i].avg_rating);
    }

    return 0;
}