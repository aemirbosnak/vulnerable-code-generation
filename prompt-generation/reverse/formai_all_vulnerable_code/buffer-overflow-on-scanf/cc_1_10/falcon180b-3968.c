//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_USERS 100
#define MAX_RATINGS 1000

typedef struct {
    char title[100];
    int year;
    char director[100];
} Movie;

typedef struct {
    char name[100];
    int age;
} User;

typedef struct {
    Movie movie;
    User user;
    int rating;
} Rating;

int main() {
    int num_movies, num_users, num_ratings;
    Movie movies[MAX_MOVIES];
    User users[MAX_USERS];
    Rating ratings[MAX_RATINGS];

    printf("Enter the number of movies: ");
    scanf("%d", &num_movies);

    for (int i = 0; i < num_movies; i++) {
        printf("Enter movie title: ");
        scanf("%s", movies[i].title);
        printf("Enter movie year: ");
        scanf("%d", &movies[i].year);
        printf("Enter movie director: ");
        scanf("%s", movies[i].director);
    }

    printf("Enter the number of users: ");
    scanf("%d", &num_users);

    for (int i = 0; i < num_users; i++) {
        printf("Enter user name: ");
        scanf("%s", users[i].name);
        printf("Enter user age: ");
        scanf("%d", &users[i].age);
    }

    printf("Enter the number of ratings: ");
    scanf("%d", &num_ratings);

    for (int i = 0; i < num_ratings; i++) {
        printf("Enter movie title: ");
        int movie_index = -1;
        for (int j = 0; j < num_movies; j++) {
            if (strcmp(movies[j].title, ratings[i].movie.title) == 0) {
                movie_index = j;
                break;
            }
        }

        if (movie_index == -1) {
            printf("Movie not found.\n");
            continue;
        }

        printf("Enter user name: ");
        int user_index = -1;
        for (int j = 0; j < num_users; j++) {
            if (strcmp(users[j].name, ratings[i].user.name) == 0) {
                user_index = j;
                break;
            }
        }

        if (user_index == -1) {
            printf("User not found.\n");
            continue;
        }

        printf("Enter rating (1-5): ");
        scanf("%d", &ratings[i].rating);
        ratings[i].movie = movies[movie_index];
        ratings[i].user = users[user_index];
    }

    return 0;
}