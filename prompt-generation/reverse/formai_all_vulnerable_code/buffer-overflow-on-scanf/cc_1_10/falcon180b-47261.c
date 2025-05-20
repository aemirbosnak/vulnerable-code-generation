//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_LENGTH 100

typedef struct {
    char title[MAX_LENGTH];
    char director[MAX_LENGTH];
    char actors[MAX_LENGTH];
    int year;
    int rating;
    int votes;
} Movie;

void parse_movies(char *filename, Movie *movies, int *num_movies) {
    FILE *fp = fopen(filename, "r");
    char line[MAX_LENGTH];
    int count = 0;

    while (fgets(line, MAX_LENGTH, fp)!= NULL) {
        if (count >= *num_movies) {
            printf("Error: too many movies in file\n");
            exit(1);
        }
        int i = 0;
        char *token = strtok(line, ",");
        strcpy(movies[count].title, token);
        token = strtok(NULL, ",");
        strcpy(movies[count].director, token);
        token = strtok(NULL, ",");
        strcpy(movies[count].actors, token);
        movies[count].year = atoi(strtok(NULL, ","));
        movies[count].rating = atof(strtok(NULL, ","));
        movies[count].votes = atoi(strtok(NULL, ","));
        count++;
    }

    fclose(fp);
}

void print_movies(Movie *movies, int num_movies) {
    for (int i = 0; i < num_movies; i++) {
        printf("%s\n", movies[i].title);
    }
}

int main() {
    char filename[MAX_LENGTH];
    printf("Enter the name of the file containing movie data: ");
    scanf("%s", filename);

    Movie movies[100];
    int num_movies = 0;

    parse_movies(filename, movies, &num_movies);

    printf("Enter the name of the movie to search for: ");
    scanf("%s", movies[0].title);

    int index = -1;
    for (int i = 0; i < num_movies; i++) {
        if (strcmp(movies[i].title, movies[0].title) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Movie not found\n");
    } else {
        printf("Movie found: %s\n", movies[index].title);
        printf("Director: %s\n", movies[index].director);
        printf("Actors: %s\n", movies[index].actors);
        printf("Year: %d\n", movies[index].year);
        printf("Rating: %f\n", movies[index].rating);
        printf("Votes: %d\n", movies[index].votes);
    }

    return 0;
}