//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LEN 100
#define MAX_DIRECTOR_LEN 50

typedef struct {
    char title[MAX_TITLE_LEN+1];
    char director[MAX_DIRECTOR_LEN+1];
    int year;
    char rating[6];
} Movie;

int main() {
    Movie movie;
    char input[1000];
    int len, i, j;

    puts("Enter movie details:");
    printf("Title: ");
    fgets(input, sizeof(input), stdin);
    len = strlen(input);
    for (i = 0, j = 0; i < len; i++) {
        if (isalnum(input[i])) {
            movie.title[j++] = tolower(input[i]);
        }
    }
    movie.title[j] = '\0';

    printf("Director: ");
    fgets(input, sizeof(input), stdin);
    len = strlen(input);
    for (i = 0, j = 0; i < len; i++) {
        if (isalnum(input[i])) {
            movie.director[j++] = tolower(input[i]);
        }
    }
    movie.director[j] = '\0';

    printf("Year: ");
    scanf("%d", &movie.year);

    printf("Rating (G/PG/PG-13/R/NC-17): ");
    fgets(movie.rating, sizeof(movie.rating), stdin);

    printf("Movie details:\n");
    printf("Title: %s\n", movie.title);
    printf("Director: %s\n", movie.director);
    printf("Year: %d\n", movie.year);
    printf("Rating: %s\n", movie.rating);

    return 0;
}