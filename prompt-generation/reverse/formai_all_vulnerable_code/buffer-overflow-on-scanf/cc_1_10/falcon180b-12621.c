//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LENGTH 100
#define MAX_DIRECTOR_LENGTH 100
#define MAX_ACTORS_LENGTH 500
#define MAX_GENRE_LENGTH 50
#define MAX_RATING_LENGTH 10

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char actors[MAX_ACTORS_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    char rating[MAX_RATING_LENGTH];
} Movie;

int main() {
    int numMovies;
    Movie movies[100];
    FILE *inputFile;
    char line[1000];
    char *token;
    int i;

    printf("Enter the number of movies: ");
    scanf("%d", &numMovies);

    inputFile = fopen("movies.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    i = 0;
    while (i < numMovies && fgets(line, sizeof(line), inputFile)!= NULL) {
        token = strtok(line, ",");
        strcpy(movies[i].title, token);
        token = strtok(NULL, ",");
        strcpy(movies[i].director, token);
        token = strtok(NULL, ",");
        strcpy(movies[i].actors, token);
        token = strtok(NULL, ",");
        strcpy(movies[i].genre, token);
        token = strtok(NULL, ",");
        strcpy(movies[i].rating, token);
        i++;
    }

    fclose(inputFile);

    printf("List of movies:\n");
    for (i = 0; i < numMovies; i++) {
        printf("Title: %s\n", movies[i].title);
        printf("Director: %s\n", movies[i].director);
        printf("Actors: %s\n", movies[i].actors);
        printf("Genre: %s\n", movies[i].genre);
        printf("Rating: %s\n\n", movies[i].rating);
    }

    return 0;
}