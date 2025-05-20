//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 10
#define MAX_RATING_VALUE 5

typedef struct {
    char title[50];
    int rating;
    int num_ratings;
} movie_t;

void add_movie(movie_t movies[], int num_movies, char* title) {
    int i;
    for (i = 0; i < num_movies; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            printf("Movie already exists!\n");
            return;
        }
    }
    if (num_movies >= MAX_MOVIES) {
        printf("Max number of movies reached!\n");
        return;
    }
    strcpy(movies[num_movies].title, title);
    movies[num_movies].rating = 0;
    movies[num_movies].num_ratings = 0;
    num_movies++;
}

void rate_movie(movie_t movies[], int num_movies, char* title, int rating) {
    int i;
    for (i = 0; i < num_movies; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            movies[i].rating += rating;
            movies[i].num_ratings++;
            movies[i].rating /= movies[i].num_ratings;
            printf("Rating updated for %s\n", title);
            return;
        }
    }
    printf("Movie not found!\n");
}

void display_movies(movie_t movies[], int num_movies) {
    int i;
    for (i = 0; i < num_movies; i++) {
        printf("%s - %d (%d ratings)\n", movies[i].title, movies[i].rating, movies[i].num_ratings);
    }
}

int main() {
    int num_movies = 0;
    movie_t movies[MAX_MOVIES];
    int choice;
    char title[50];

    do {
        printf("\nC Movie Rating System\n");
        printf("1. Add Movie\n2. Rate Movie\n3. Display Movies\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter movie title: ");
                scanf("%s", title);
                add_movie(movies, num_movies, title);
                break;
            case 2:
                printf("Enter movie title: ");
                scanf("%s", title);
                printf("Enter rating (1-5): ");
                scanf("%d", &choice);
                rate_movie(movies, num_movies, title, choice);
                break;
            case 3:
                display_movies(movies, num_movies);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 4);

    return 0;
}