//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 1000
#define MAX_RATINGS 1000000

typedef struct {
    char title[100];
    int rating;
    int num_ratings;
} movie;

movie movies[MAX_MOVIES];
int num_movies = 0;

void add_movie(char* title) {
    int i;
    for (i = 0; i < num_movies; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            movies[i].rating += 1;
            movies[i].num_ratings += 1;
            return;
        }
    }
    if (num_movies >= MAX_MOVIES) {
        printf("Error: Too many movies\n");
        exit(1);
    }
    strcpy(movies[num_movies].title, title);
    movies[num_movies].rating = 1;
    movies[num_movies].num_ratings = 1;
    num_movies++;
}

void print_movies() {
    int i;
    printf("Movie Ratings:\n");
    for (i = 0; i < num_movies; i++) {
        printf("%s: %d (%d ratings)\n", movies[i].title, movies[i].rating, movies[i].num_ratings);
    }
}

int main() {
    char title[100];
    while (1) {
        printf("Enter movie title: ");
        scanf("%s", title);
        add_movie(title);
    }
    return 0;
}