//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100
#define MAX_RATINGS 10
#define MAX_RATING_LENGTH 100

typedef struct {
    char title[MAX_LENGTH];
    char director[MAX_LENGTH];
    int year;
    int rating;
    char rating_source[MAX_RATING_LENGTH];
} Movie;

int main() {
    int num_movies, i;
    Movie movies[MAX_RATINGS];
    char filename[MAX_LENGTH];
    FILE *fp;

    printf("Enter the name of the file containing movie ratings: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    num_movies = 0;
    while (fscanf(fp, "%s %s %d %d %s", movies[num_movies].title, movies[num_movies].director, &movies[num_movies].year, &movies[num_movies].rating, movies[num_movies].rating_source)!= EOF) {
        num_movies++;
        if (num_movies == MAX_RATINGS) {
            printf("Error: maximum number of movies reached.\n");
            exit(1);
        }
    }

    fclose(fp);

    printf("Movie Ratings\n");
    printf("=============\n");
    printf("Title\tDirector\tYear\tRating\tSource\n");
    for (i = 0; i < num_movies; i++) {
        printf("%-20s %-20s %4d %4d %s\n", movies[i].title, movies[i].director, movies[i].year, movies[i].rating, movies[i].rating_source);
    }

    return 0;
}