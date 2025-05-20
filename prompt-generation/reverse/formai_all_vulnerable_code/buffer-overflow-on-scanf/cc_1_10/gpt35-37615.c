//FormAI DATASET v1.0 Category: Movie Rating System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[50];
    char director[50];
    int year;
    float rating;
} Movie;

int main() {
    Movie movies[5];
    int i;

    // Populate array of movies
    strcpy(movies[0].title, "The Shawshank Redemption");
    strcpy(movies[0].director, "Frank Darabont");
    movies[0].year = 1994;
    movies[0].rating = 9.3;

    strcpy(movies[1].title, "The Godfather");
    strcpy(movies[1].director, "Francis Ford Coppola");
    movies[1].year = 1972;
    movies[1].rating = 9.2;

    strcpy(movies[2].title, "The Godfather: Part II");
    strcpy(movies[2].director, "Francis Ford Coppola");
    movies[2].year = 1974;
    movies[2].rating = 9.0;

    strcpy(movies[3].title, "The Dark Knight");
    strcpy(movies[3].director, "Christopher Nolan");
    movies[3].year = 2008;
    movies[3].rating = 9.0;

    strcpy(movies[4].title, "12 Angry Men");
    strcpy(movies[4].director, "Sidney Lumet");
    movies[4].year = 1957;
    movies[4].rating = 8.9;

    printf("Welcome to the Unique C Movie Rating System!\n");
    printf("Please rate the following movies on a scale of 1-10.\n");

    // Take user input for rating movies
    for (i = 0; i < 5; i++) {
        printf("\n%s (dir. %s, %d): ", movies[i].title, movies[i].director, movies[i].year);
        scanf("%f", &movies[i].rating);
    }

    // Print out updated movie ratings
    printf("\nUpdated movie ratings:\n");
    for (i = 0; i < 5; i++) {
        printf("%s (dir. %s, %d): %.1f\n", movies[i].title, movies[i].director, movies[i].year, movies[i].rating);
    }

    return 0;
}