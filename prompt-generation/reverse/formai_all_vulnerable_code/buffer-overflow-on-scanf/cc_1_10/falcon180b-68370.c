//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Movie {
    char title[50];
    char director[50];
    char actors[100];
    char genre[20];
    char rating;
};

void main() {
    int num_movies, i, j, k, l;
    struct Movie movies[50];

    // Get number of movies from user
    printf("Enter the number of movies: ");
    scanf("%d", &num_movies);

    // Get movie information from user
    for (i = 0; i < num_movies; i++) {
        printf("Enter movie %d information:\n", i+1);
        printf("Title: ");
        scanf("%s", movies[i].title);
        printf("Director: ");
        scanf("%s", movies[i].director);
        printf("Actors: ");
        scanf("%s", movies[i].actors);
        printf("Genre: ");
        scanf("%s", movies[i].genre);
        printf("Rating: ");
        scanf(" %c", &movies[i].rating);
    }

    // Sort movies by rating
    for (i = 0; i < num_movies-1; i++) {
        for (j = i+1; j < num_movies; j++) {
            if (movies[i].rating < movies[j].rating) {
                struct Movie temp = movies[i];
                movies[i] = movies[j];
                movies[j] = temp;
            }
        }
    }

    // Print sorted movie list
    printf("\nSorted movie list:\n");
    for (i = 0; i < num_movies; i++) {
        printf("%s (%c)\n", movies[i].title, movies[i].rating);
    }
}