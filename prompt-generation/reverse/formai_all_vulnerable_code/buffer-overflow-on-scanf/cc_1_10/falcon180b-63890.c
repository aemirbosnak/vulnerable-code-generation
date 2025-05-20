//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 10
#define MAX_RATING_VALUE 5

typedef struct {
    char title[100];
    int ratings[MAX_RATINGS];
    int num_ratings;
} movie_t;

void add_movie(movie_t *movies, int num_movies, char *title) {
    int i;
    for (i = 0; i < num_movies; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            printf("Movie already exists.\n");
            return;
        }
    }
    strcpy(movies[num_movies].title, title);
    movies[num_movies].num_ratings = 0;
    memset(movies[num_movies].ratings, 0, sizeof(int) * MAX_RATINGS);
    num_movies++;
}

void rate_movie(movie_t *movies, int num_movies, char *title, int rating) {
    int i, j;
    for (i = 0; i < num_movies; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            for (j = 0; j < MAX_RATINGS; j++) {
                if (movies[i].ratings[j] == 0) {
                    movies[i].ratings[j] = rating;
                    movies[i].num_ratings++;
                    break;
                }
            }
            printf("Movie rated.\n");
            return;
        }
    }
    printf("Movie not found.\n");
}

void print_movies(movie_t *movies, int num_movies) {
    int i, j;
    for (i = 0; i < num_movies; i++) {
        printf("%s:\n", movies[i].title);
        printf("Rating: ");
        for (j = 0; j < MAX_RATINGS; j++) {
            if (movies[i].ratings[j]!= 0) {
                printf("%d ", movies[i].ratings[j]);
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
}

int main() {
    movie_t movies[MAX_MOVIES];
    int num_movies = 0;
    char title[100];

    while (1) {
        printf("1. Add movie\n2. Rate movie\n3. Print all movies\n4. Exit\n");
        scanf("%d", &num_movies);

        switch (num_movies) {
            case 1:
                printf("Enter movie title: ");
                scanf("%s", title);
                add_movie(movies, num_movies, title);
                break;
            case 2:
                printf("Enter movie title: ");
                scanf("%s", title);
                rate_movie(movies, num_movies, title, 5);
                break;
            case 3:
                print_movies(movies, num_movies);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}