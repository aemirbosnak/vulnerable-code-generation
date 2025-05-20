//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 10

struct movie {
    char title[50];
    int rating;
    int num_ratings;
};

struct user {
    char name[50];
    int rating;
};

void add_movie(struct movie *movies, int num_movies, char *title) {
    int i;
    for (i = 0; i < num_movies; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            printf("Movie already exists.\n");
            return;
        }
    }
    strcpy(movies[num_movies].title, title);
    movies[num_movies].rating = 0;
    movies[num_movies].num_ratings = 0;
    num_movies++;
}

void add_rating(struct movie *movies, int num_movies, char *title, int rating) {
    int i;
    for (i = 0; i < num_movies; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            movies[i].rating += rating;
            movies[i].num_ratings++;
            return;
        }
    }
    printf("Movie not found.\n");
}

void display_movies(struct movie *movies, int num_movies) {
    int i;
    for (i = 0; i < num_movies; i++) {
        printf("%s: %.1f\n", movies[i].title, (float)movies[i].rating/movies[i].num_ratings);
    }
}

int main() {
    struct movie movies[MAX_MOVIES];
    int num_movies = 0;
    char title[50];
    while (1) {
        printf("Enter movie title: ");
        scanf("%s", title);
        if (strcmp(title, "exit") == 0) {
            break;
        }
        add_movie(movies, num_movies, title);
        num_movies++;
    }
    while (1) {
        printf("Enter rating for movie: ");
        scanf("%s", title);
        int rating;
        if (strcmp(title, "exit") == 0) {
            break;
        }
        printf("Enter rating (1-10): ");
        scanf("%d", &rating);
        add_rating(movies, num_movies, title, rating);
    }
    display_movies(movies, num_movies);
    return 0;
}