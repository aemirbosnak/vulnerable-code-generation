//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LENGTH 80
#define MAX_NAME_LENGTH 50
#define MAX_GENRE_LENGTH 20
#define MAX_RATING_LENGTH 10

struct movie {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_NAME_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    char rating[MAX_RATING_LENGTH];
};

void print_movie(struct movie *movie) {
    printf("Title: %s\n", movie->title);
    printf("Director: %s\n", movie->director);
    printf("Genre: %s\n", movie->genre);
    printf("Rating: %s\n", movie->rating);
}

int main() {
    int num_movies;
    struct movie movies[100];

    printf("Enter the number of movies to rate:\n");
    scanf("%d", &num_movies);

    for (int i = 0; i < num_movies; i++) {
        printf("Enter the title of movie %d:\n", i+1);
        scanf("%s", movies[i].title);

        printf("Enter the director of movie %d:\n", i+1);
        scanf("%s", movies[i].director);

        printf("Enter the genre of movie %d:\n", i+1);
        scanf("%s", movies[i].genre);

        printf("Enter the rating of movie %d (G, PG, PG-13, R, NC-17):\n", i+1);
        scanf("%s", movies[i].rating);
    }

    for (int i = 0; i < num_movies; i++) {
        print_movie(&movies[i]);
    }

    return 0;
}