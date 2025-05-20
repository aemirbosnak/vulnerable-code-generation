//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 5
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int ratings[MAX_RATINGS];
    int num_ratings;
} Movie;

void add_movie(Movie* movies, int num_movies, char* name) {
    int i;
    for (i = 0; i < num_movies; i++) {
        if (strcmp(movies[i].name, name) == 0) {
            printf("Movie already exists.\n");
            return;
        }
    }
    strcpy(movies[num_movies].name, name);
    movies[num_movies].num_ratings = 0;
}

void add_rating(Movie* movies, int num_movies, char* name, int rating) {
    int i;
    for (i = 0; i < num_movies; i++) {
        if (strcmp(movies[i].name, name) == 0) {
            if (movies[i].num_ratings >= MAX_RATINGS) {
                printf("Too many ratings for this movie.\n");
                return;
            }
            movies[i].ratings[movies[i].num_ratings++] = rating;
            return;
        }
    }
    printf("Movie not found.\n");
}

void display_movies(Movie* movies, int num_movies) {
    int i, j;
    for (i = 0; i < num_movies; i++) {
        printf("%s:\n", movies[i].name);
        for (j = 0; j < movies[i].num_ratings; j++) {
            printf("%d\n", movies[i].ratings[j]);
        }
    }
}

int main() {
    Movie movies[MAX_MOVIES];
    int num_movies = 0;
    char input[100];
    while (1) {
        printf("Enter command (add_movie, add_rating, display_movies, or quit): ");
        scanf("%s", input);
        if (strcmp(input, "add_movie") == 0) {
            char name[MAX_NAME_LENGTH];
            printf("Enter movie name: ");
            scanf("%s", name);
            add_movie(movies, num_movies, name);
            num_movies++;
        } else if (strcmp(input, "add_rating") == 0) {
            char name[MAX_NAME_LENGTH];
            int rating;
            printf("Enter movie name: ");
            scanf("%s", name);
            printf("Enter rating (1-5): ");
            scanf("%d", &rating);
            add_rating(movies, num_movies, name, rating);
        } else if (strcmp(input, "display_movies") == 0) {
            display_movies(movies, num_movies);
        } else if (strcmp(input, "quit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }
    return 0;
}