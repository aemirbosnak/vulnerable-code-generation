//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 100
#define MAX_MOVIES 100

struct Movie {
    char name[MAX_NAME_LEN];
    int rating;
};

struct Movie movies[MAX_MOVIES];
int numMovies;

void addMovie(char* name, int rating) {
    for (int i = 0; i < numMovies; i++) {
        if (strcmp(movies[i].name, name) == 0) {
            movies[i].rating += rating;
            return;
        }
    }
    if (numMovies >= MAX_MOVIES) {
        printf("Error: Maximum number of movies reached\n");
        return;
    }
    strcpy(movies[numMovies].name, name);
    movies[numMovies].rating = rating;
    numMovies++;
}

int getMovieRating(char* name) {
    for (int i = 0; i < numMovies; i++) {
        if (strcmp(movies[i].name, name) == 0) {
            return movies[i].rating;
        }
    }
    return -1;
}

int main() {
    printf("Welcome to the Movie Rating System\n");
    printf("Commands: add, rate, quit\n");
    while (1) {
        char cmd[10];
        scanf("%s", cmd);
        if (strcmp(cmd, "add") == 0) {
            char name[MAX_NAME_LEN];
            int rating;
            printf("Enter movie name: ");
            scanf("%s", name);
            printf("Enter movie rating: ");
            scanf("%d", &rating);
            addMovie(name, rating);
        } else if (strcmp(cmd, "rate") == 0) {
            char name[MAX_NAME_LEN];
            printf("Enter movie name: ");
            scanf("%s", name);
            int rating = getMovieRating(name);
            if (rating == -1) {
                printf("Movie not found\n");
            } else {
                printf("Movie rating: %d\n", rating);
            }
        } else if (strcmp(cmd, "quit") == 0) {
            break;
        } else {
            printf("Invalid command\n");
        }
    }
    return 0;
}