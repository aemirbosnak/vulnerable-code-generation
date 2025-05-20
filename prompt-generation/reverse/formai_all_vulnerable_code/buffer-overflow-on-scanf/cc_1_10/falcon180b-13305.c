//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LENGTH 100
#define MAX_DIRECTOR_LENGTH 50
#define MAX_ACTOR_LENGTH 50
#define MAX_RATING_LENGTH 10

struct movie {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char actor[MAX_ACTOR_LENGTH];
    char rating[MAX_RATING_LENGTH];
};

void print_movie(struct movie* movie) {
    printf("Title: %s\n", movie->title);
    printf("Director: %s\n", movie->director);
    printf("Actor: %s\n", movie->actor);
    printf("Rating: %s\n", movie->rating);
}

void add_movie(struct movie* movie) {
    FILE* file = fopen("movies.txt", "a");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return;
    }

    fprintf(file, "Title: %s\n", movie->title);
    fprintf(file, "Director: %s\n", movie->director);
    fprintf(file, "Actor: %s\n", movie->actor);
    fprintf(file, "Rating: %s\n", movie->rating);

    fclose(file);
}

int main() {
    struct movie movie;

    printf("Enter movie title:\n");
    scanf("%s", movie.title);

    printf("Enter movie director:\n");
    scanf("%s", movie.director);

    printf("Enter movie actor:\n");
    scanf("%s", movie.actor);

    printf("Enter movie rating:\n");
    scanf("%s", movie.rating);

    add_movie(&movie);
    printf("Movie added successfully.\n");

    return 0;
}