//Falcon2-11B DATASET v1.0 Category: Movie Rating System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_RATING_LENGTH 10
#define MAX_RATINGS 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    int ratings[MAX_RATINGS];
} movie_info;

int main() {
    movie_info movies[MAX_RATINGS];
    int num_movies, movie_id, rating;

    printf("Enter the number of movies: ");
    scanf("%d", &num_movies);

    for (int i = 0; i < num_movies; i++) {
        printf("Enter movie title: ");
        scanf("%s", movies[i].title);

        printf("Enter rating 1: ");
        scanf("%d", &rating);
        movies[i].ratings[0] = rating;

        printf("Enter rating 2: ");
        scanf("%d", &rating);
        movies[i].ratings[1] = rating;

        printf("Enter rating 3: ");
        scanf("%d", &rating);
        movies[i].ratings[2] = rating;

        printf("Enter rating 4: ");
        scanf("%d", &rating);
        movies[i].ratings[3] = rating;

        printf("Enter rating 5: ");
        scanf("%d", &rating);
        movies[i].ratings[4] = rating;
    }

    for (int i = 0; i < num_movies; i++) {
        printf("Title: %s\n", movies[i].title);
        printf("Ratings:\n");
        for (int j = 0; j < 5; j++) {
            printf("%d\n", movies[i].ratings[j]);
        }
    }

    return 0;
}