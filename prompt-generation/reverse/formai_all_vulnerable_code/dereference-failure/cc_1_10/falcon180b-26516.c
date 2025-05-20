//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000
#define MAX_RATINGS 100

typedef struct {
    char title[MAX_LENGTH];
    char director[MAX_LENGTH];
    char actors[MAX_LENGTH];
    int length;
    int year;
    int ratings[MAX_RATINGS];
    int num_ratings;
} Movie;

void add_rating(Movie *movie, int rating) {
    if (movie->num_ratings >= MAX_RATINGS) {
        printf("Maximum number of ratings reached.\n");
        return;
    }
    movie->ratings[movie->num_ratings] = rating;
    movie->num_ratings++;
}

int main() {
    Movie movie;
    char input[MAX_LENGTH];
    char *token;
    int i, j;

    printf("Enter movie details:\n");
    printf("Title: ");
    fgets(input, MAX_LENGTH, stdin);
    strcpy(movie.title, input);
    token = strtok(input, "\n");
    while (token!= NULL) {
        if (strcasecmp(token, "Director:") == 0) {
            printf("Director: ");
            fgets(input, MAX_LENGTH, stdin);
            strcpy(movie.director, input);
        } else if (strcasecmp(token, "Actors:") == 0) {
            printf("Actors: ");
            fgets(input, MAX_LENGTH, stdin);
            strcpy(movie.actors, input);
        } else if (strcasecmp(token, "Length:") == 0) {
            printf("Length (in minutes): ");
            scanf("%d", &movie.length);
        } else if (strcasecmp(token, "Year:") == 0) {
            printf("Year: ");
            scanf("%d", &movie.year);
        }
        token = strtok(NULL, "\n");
    }

    // Add initial ratings
    add_rating(&movie, 5);
    add_rating(&movie, 4);
    add_rating(&movie, 3);

    printf("\nMovie details:\n");
    printf("Title: %s\n", movie.title);
    printf("Director: %s\n", movie.director);
    printf("Actors: %s\n", movie.actors);
    printf("Length: %d minutes\n", movie.length);
    printf("Year: %d\n", movie.year);

    printf("\nRatings:\n");
    for (i = 0; i < movie.num_ratings; i++) {
        printf("%d stars\n", movie.ratings[i]);
    }

    return 0;
}