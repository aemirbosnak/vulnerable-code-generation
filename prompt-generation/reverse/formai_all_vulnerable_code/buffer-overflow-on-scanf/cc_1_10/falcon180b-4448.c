//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LENGTH 100
#define MAX_DIRECTOR_LENGTH 50
#define MAX_ACTORS_LENGTH 200
#define MAX_GENRE_LENGTH 50
#define MAX_RATING 5
#define MAX_REVIEW_LENGTH 500

typedef struct {
    char title[MAX_TITLE_LENGTH+1];
    char director[MAX_DIRECTOR_LENGTH+1];
    char actors[MAX_ACTORS_LENGTH+1];
    char genre[MAX_GENRE_LENGTH+1];
    int rating;
    char review[MAX_REVIEW_LENGTH+1];
} Movie;

void trim(char* str) {
    int i, j;
    for (i = strlen(str) - 1; i >= 0 && isspace(str[i]); i--) {
        str[i] = '\0';
    }
    for (j = 0; isspace(str[j]); j++) {
        strcpy(str, str + j);
    }
}

int main() {
    Movie movie;
    FILE* fp;
    char filename[100];
    char line[1000];
    int i;

    printf("Enter the name of the movie file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fgets(line, sizeof(line), fp);
    trim(line);
    strcpy(movie.title, line);

    fgets(line, sizeof(line), fp);
    trim(line);
    strcpy(movie.director, line);

    fgets(line, sizeof(line), fp);
    trim(line);
    strcpy(movie.actors, line);

    fgets(line, sizeof(line), fp);
    trim(line);
    strcpy(movie.genre, line);

    fgets(line, sizeof(line), fp);
    trim(line);
    movie.rating = atoi(line);

    fgets(line, sizeof(line), fp);
    trim(line);
    strcpy(movie.review, line);

    fclose(fp);

    printf("Movie Title: %s\n", movie.title);
    printf("Director: %s\n", movie.director);
    printf("Actors: %s\n", movie.actors);
    printf("Genre: %s\n", movie.genre);
    printf("Rating: %d\n", movie.rating);
    printf("Review: %s\n", movie.review);

    return 0;
}