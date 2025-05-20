//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char title[50];
    int year;
    char genre[20];
    char director[30];
    char cast[100];
    char plot[200];
    int runtime;
    int rating;
} Movie;

int main() {
    int numMovies, i;
    Movie movies[100];

    printf("Enter number of movies: ");
    scanf("%d", &numMovies);

    for (i = 0; i < numMovies; i++) {
        printf("Enter movie %d details:\n", i+1);
        printf("Title: ");
        scanf("%s", movies[i].title);

        printf("Year: ");
        scanf("%d", &movies[i].year);

        printf("Genre: ");
        scanf("%s", movies[i].genre);

        printf("Director: ");
        scanf("%s", movies[i].director);

        printf("Cast: ");
        scanf("%s", movies[i].cast);

        printf("Plot: ");
        scanf("%s", movies[i].plot);

        printf("Runtime: ");
        scanf("%d", &movies[i].runtime);

        printf("Rating: ");
        scanf("%d", &movies[i].rating);
    }

    printf("\nMovie List:\n");
    for (i = 0; i < numMovies; i++) {
        printf("%d. %s (%d)\n", i+1, movies[i].title, movies[i].year);
        printf("Genre: %s\n", movies[i].genre);
        printf("Director: %s\n", movies[i].director);
        printf("Cast: %s\n", movies[i].cast);
        printf("Plot: %s\n", movies[i].plot);
        printf("Runtime: %d minutes\n", movies[i].runtime);
        printf("Rating: %d/10\n\n", movies[i].rating);
    }

    return 0;
}