//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LENGTH 100
#define MAX_DIRECTOR_LENGTH 50
#define MAX_ACTOR_LENGTH 50
#define MAX_GENRE_LENGTH 50
#define MAX_RATING 5
#define MAX_REVIEW_LENGTH 200

struct movie {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char actors[MAX_ACTOR_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    int rating;
    char review[MAX_REVIEW_LENGTH];
};

struct movie movies[100];
int num_movies = 0;

void add_movie() {
    if (num_movies >= 100) {
        printf("Error: Too many movies\n");
        return;
    }

    char title[MAX_TITLE_LENGTH];
    printf("Enter movie title: ");
    scanf("%s", title);

    char director[MAX_DIRECTOR_LENGTH];
    printf("Enter movie director: ");
    scanf("%s", director);

    char actors[MAX_ACTOR_LENGTH];
    printf("Enter movie actors: ");
    scanf("%s", actors);

    char genre[MAX_GENRE_LENGTH];
    printf("Enter movie genre: ");
    scanf("%s", genre);

    int rating;
    printf("Enter movie rating (0-5): ");
    scanf("%d", &rating);

    char review[MAX_REVIEW_LENGTH];
    printf("Enter movie review: ");
    scanf("%s", review);

    num_movies++;
}

void print_movies() {
    printf("Movie List:\n");
    for (int i = 0; i < num_movies; i++) {
        printf("%d. %s (%d)\n", i+1, movies[i].title, movies[i].rating);
    }
}

void search_movies() {
    char query[MAX_TITLE_LENGTH];
    printf("Enter movie title to search: ");
    scanf("%s", query);

    for (int i = 0; i < num_movies; i++) {
        if (strcasecmp(movies[i].title, query) == 0) {
            printf("%s\n", movies[i].review);
        }
    }
}

int main() {
    add_movie();
    add_movie();
    add_movie();

    print_movies();

    search_movies();

    return 0;
}