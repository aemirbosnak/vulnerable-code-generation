//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define RATING_MAX 5
#define RATING_MIN 1

typedef struct {
    char title[100];
    char director[50];
    char actors[200];
    int year;
    int rating;
} Movie;

void read_movies(Movie movies[], int n) {
    FILE *fp;
    fp = fopen("movies.txt", "r");

    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(fp, "%s %s %s %d %d\n", movies[i].title, movies[i].director, movies[i].actors, &movies[i].year, &movies[i].rating)!= EOF) {
        i++;
    }

    fclose(fp);
}

void display_movies(Movie movies[], int n) {
    printf("Movie Ratings:\n");
    for (int i = 0; i < n; i++) {
        printf("%s (%d) - Directed by %s, starring %s, released in %d with a rating of %d\n", movies[i].title, i + 1, movies[i].director, movies[i].actors, movies[i].year, movies[i].rating);
    }
}

int main() {
    Movie movies[100];
    int n;

    read_movies(movies, &n);

    printf("Sorting by rating...\n");
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (movies[j].rating < movies[j + 1].rating) {
                Movie temp = movies[j];
                movies[j] = movies[j + 1];
                movies[j + 1] = temp;
            }
        }
    }

    display_movies(movies, n);

    return 0;
}