//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LENGTH 100
#define MAX_DIRECTOR_LENGTH 50
#define MAX_CAST_LENGTH 200
#define MAX_GENRE_LENGTH 50
#define MAX_RATING 5

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char cast[MAX_CAST_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    int rating;
} Movie;

int main() {
    int num_movies, i;
    Movie movies[100];

    printf("Enter the number of movies: ");
    scanf("%d", &num_movies);

    for (i = 0; i < num_movies; i++) {
        printf("Enter movie %d details:\n", i+1);
        printf("Title: ");
        scanf("%s", movies[i].title);
        printf("Director: ");
        scanf("%s", movies[i].director);
        printf("Cast: ");
        scanf("%s", movies[i].cast);
        printf("Genre: ");
        scanf("%s", movies[i].genre);
        printf("Rating (1-5): ");
        scanf("%d", &movies[i].rating);
    }

    printf("\nMovie Ratings:\n");
    for (i = 0; i < num_movies; i++) {
        printf("%s - %s\n", movies[i].title, movies[i].director);
        printf("Cast: %s\n", movies[i].cast);
        printf("Genre: %s\n", movies[i].genre);
        printf("Rating: %d\n\n", movies[i].rating);
    }

    return 0;
}