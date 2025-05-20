//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LENGTH 100
#define MAX_DIRECTOR_LENGTH 50
#define MAX_ACTORS_LENGTH 200
#define MAX_SYNOPSIS_LENGTH 500
#define MAX_RATING_LENGTH 10
#define MAX_GENRE_LENGTH 50
#define MAX_YEAR_LENGTH 4
#define MAX_REVIEW_LENGTH 1000
#define MAX_MOVIES 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char actors[MAX_ACTORS_LENGTH];
    char synopsis[MAX_SYNOPSIS_LENGTH];
    char rating[MAX_RATING_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    int year;
    char review[MAX_REVIEW_LENGTH];
} Movie;

int main() {
    FILE *fp;
    char filename[MAX_TITLE_LENGTH];
    int num_movies = 0;
    Movie movies[MAX_MOVIES];

    printf("Enter the name of the file containing movie information: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while (fscanf(fp, "%s\t%s\t%s\t%s\t%s\t%d\t%s\n", movies[num_movies].title, movies[num_movies].director, movies[num_movies].actors, movies[num_movies].synopsis, movies[num_movies].rating, &movies[num_movies].year, movies[num_movies].review) == 7) {
        num_movies++;
        if (num_movies == MAX_MOVIES) {
            printf("Error: too many movies in file.\n");
            exit(1);
        }
    }

    fclose(fp);

    printf("\nMovie Ratings:\n");
    printf("=================\n");

    for (int i = 0; i < num_movies; i++) {
        printf("%s\t%s\t%s\t%s\t%s\t%d\t%s\n", movies[i].title, movies[i].director, movies[i].actors, movies[i].synopsis, movies[i].rating, movies[i].year, movies[i].review);
    }

    return 0;
}