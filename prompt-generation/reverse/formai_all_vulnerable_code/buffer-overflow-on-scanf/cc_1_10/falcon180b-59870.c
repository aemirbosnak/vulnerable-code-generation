//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char title[100];
    int year;
    char director[50];
    char cast[200];
    char genre[50];
    char rating;
} Movie;

int main() {
    int numMovies;
    Movie movies[100];

    printf("Enter the number of movies: ");
    scanf("%d", &numMovies);

    // Read in movie information
    for (int i = 0; i < numMovies; i++) {
        printf("Enter movie %d information:\n", i+1);
        printf("Title: ");
        scanf("%s", movies[i].title);
        printf("Year: ");
        scanf("%d", &movies[i].year);
        printf("Director: ");
        scanf("%s", movies[i].director);
        printf("Cast: ");
        scanf("%s", movies[i].cast);
        printf("Genre: ");
        scanf("%s", movies[i].genre);
        printf("Rating: ");
        scanf(" %c", &movies[i].rating);
    }

    // Sort movies by rating
    for (int i = 0; i < numMovies; i++) {
        for (int j = i+1; j < numMovies; j++) {
            if (movies[i].rating < movies[j].rating) {
                Movie temp = movies[i];
                movies[i] = movies[j];
                movies[j] = temp;
            }
        }
    }

    // Print sorted list of movies
    printf("\nSorted list of movies by rating:\n");
    for (int i = 0; i < numMovies; i++) {
        printf("%s (%d)\n", movies[i].title, movies[i].year);
        printf("Director: %s\n", movies[i].director);
        printf("Cast: %s\n", movies[i].cast);
        printf("Genre: %s\n", movies[i].genre);
        printf("Rating: %c\n\n", movies[i].rating);
    }

    return 0;
}