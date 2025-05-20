//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char movie_title[100];
    int movie_rating;
} movie_t;

int main(int argc, char *argv[]) {
    int num_movies = 0;
    movie_t *movies = NULL;
    char filename[100];
    FILE *fp;
    char line[100];
    char *token;
    char *movie_title = NULL;
    int movie_rating = 0;
    int i = 0;
    int j = 0;

    printf("Enter the name of the file containing movie ratings: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, 100, fp)!= NULL) {
        num_movies++;
        movies = (movie_t *)realloc(movies, num_movies * sizeof(movie_t));
        movies[num_movies - 1].movie_title[0] = '\0';
        movies[num_movies - 1].movie_rating = 0;
        token = strtok(line, ",");
        while (token!= NULL) {
            if (i == 0) {
                strcpy(movies[num_movies - 1].movie_title, token);
                i++;
            } else if (j == 0) {
                movie_rating = atoi(token);
                j++;
            }
            token = strtok(NULL, ",");
        }
    }

    fclose(fp);

    printf("Movie Ratings:\n");
    for (i = 0; i < num_movies; i++) {
        printf("%s - %d stars\n", movies[i].movie_title, movies[i].movie_rating);
    }

    return 0;
}