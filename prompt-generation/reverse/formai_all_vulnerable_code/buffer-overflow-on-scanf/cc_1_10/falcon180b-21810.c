//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LENGTH 100
#define MAX_DIRECTOR_LENGTH 50
#define MAX_ACTORS_LENGTH 200
#define MAX_GENRE_LENGTH 50
#define MAX_RATING 5

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char actors[MAX_ACTORS_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    int rating;
} Movie;

void print_movie(Movie movie) {
    printf("Title: %s\n", movie.title);
    printf("Director: %s\n", movie.director);
    printf("Actors: %s\n", movie.actors);
    printf("Genre: %s\n", movie.genre);
    printf("Rating: %d\n", movie.rating);
}

int main() {
    int num_movies;
    scanf("%d", &num_movies);

    Movie movies[num_movies];

    for(int i = 0; i < num_movies; i++) {
        printf("Enter movie %d:\n", i+1);
        scanf("%s", movies[i].title);
        scanf("%s", movies[i].director);
        scanf("%s", movies[i].actors);
        scanf("%s", movies[i].genre);
        movies[i].rating = 0;
    }

    char input[100];
    while(1) {
        printf("Enter command:\n");
        scanf("%s", input);

        if(strcmp(input, "list") == 0) {
            for(int i = 0; i < num_movies; i++) {
                print_movie(movies[i]);
            }
        } else if(strcmp(input, "rate") == 0) {
            printf("Enter movie number:\n");
            int movie_num;
            scanf("%d", &movie_num);

            printf("Enter rating (1-5):\n");
            int rating;
            scanf("%d", &rating);

            movies[movie_num-1].rating = rating;
        } else if(strcmp(input, "exit") == 0) {
            break;
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}