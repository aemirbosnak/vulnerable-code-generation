//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LEN 100
#define MAX_DIRECTOR_LEN 50
#define MAX_ACTOR_LEN 50
#define MAX_GENRE_LEN 20
#define MAX_RATING_LEN 10
#define MAX_REVIEW_LEN 200

typedef struct {
    char title[MAX_TITLE_LEN];
    char director[MAX_DIRECTOR_LEN];
    char actors[MAX_ACTOR_LEN];
    char genre[MAX_GENRE_LEN];
    char rating[MAX_RATING_LEN];
    char review[MAX_REVIEW_LEN];
} Movie;

int main() {

    FILE *movieFile;
    char filename[MAX_TITLE_LEN];
    char line[MAX_REVIEW_LEN];
    Movie movie;

    printf("Enter the name of the movie file: ");
    scanf("%s", filename);

    movieFile = fopen(filename, "r");

    if (movieFile == NULL) {
        printf("File not found!");
        exit(1);
    }

    fscanf(movieFile, "Title: %s\n", movie.title);
    fscanf(movieFile, "Director: %s\n", movie.director);
    fscanf(movieFile, "Actors: %s\n", movie.actors);
    fscanf(movieFile, "Genre: %s\n", movie.genre);
    fscanf(movieFile, "Rating: %s\n", movie.rating);

    while (fgets(line, MAX_REVIEW_LEN, movieFile)!= NULL) {
        strcat(movie.review, line);
    }

    fclose(movieFile);

    printf("\nMovie Details:\n");
    printf("Title: %s\n", movie.title);
    printf("Director: %s\n", movie.director);
    printf("Actors: %s\n", movie.actors);
    printf("Genre: %s\n", movie.genre);
    printf("Rating: %s\n", movie.rating);
    printf("Review: %s\n", movie.review);

    return 0;
}