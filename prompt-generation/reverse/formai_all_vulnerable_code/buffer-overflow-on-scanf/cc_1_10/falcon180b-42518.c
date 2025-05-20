//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[100];
    char director[50];
    char cast[100];
    int runtime;
    int budget;
    int gross;
    int rating;
} Movie;

int main() {
    int num_movies, i;
    Movie movies[100];

    printf("Enter the number of movies: ");
    scanf("%d", &num_movies);

    for (i = 0; i < num_movies; i++) {
        printf("\nEnter the details for movie %d:\n", i+1);
        printf("Title: ");
        scanf("%s", movies[i].title);
        printf("Director: ");
        scanf("%s", movies[i].director);
        printf("Cast: ");
        scanf("%s", movies[i].cast);
        printf("Runtime: ");
        scanf("%d", &movies[i].runtime);
        printf("Budget: ");
        scanf("%d", &movies[i].budget);
        printf("Gross: ");
        scanf("%d", &movies[i].gross);
        printf("Rating: ");
        scanf("%d", &movies[i].rating);
    }

    printf("\nMovie Ratings:\n");
    for (i = 0; i < num_movies; i++) {
        if (movies[i].runtime < 30) {
            printf("%s - Runtime is too short.\n", movies[i].title);
        } else if (movies[i].budget < 10000) {
            printf("%s - Budget is too low.\n", movies[i].title);
        } else if (movies[i].gross < 100000) {
            printf("%s - Gross is too low.\n", movies[i].title);
        } else if (movies[i].rating < 5) {
            printf("%s - Rating is too low.\n", movies[i].title);
        } else {
            printf("%s - Rating: %d\n", movies[i].title, movies[i].rating);
        }
    }

    return 0;
}