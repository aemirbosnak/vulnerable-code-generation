//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 100
#define MAX_USERS 100
#define MAX_GENRES 100
#define MAX_DIRECTORS 100
#define MAX_ACTORS 100
#define MAX_PLOT 1000
#define MAX_TITLE 100
#define MAX_USER_RATING 5
#define MAX_USER_NAME 100
#define MAX_USER_EMAIL 100
#define MAX_USER_ADDRESS 100

typedef struct {
    char title[MAX_TITLE];
    char plot[MAX_PLOT];
    char director[MAX_DIRECTORS];
    char actors[MAX_ACTORS];
    char genres[MAX_GENRES];
    int rating;
} Movie;

typedef struct {
    char name[MAX_USER_NAME];
    char email[MAX_USER_EMAIL];
    char address[MAX_USER_ADDRESS];
    int ratings[MAX_MOVIES];
} User;

int main() {
    int num_movies, num_users;
    scanf("%d %d", &num_movies, &num_users);

    Movie movies[num_movies];
    User users[num_users];

    for (int i = 0; i < num_movies; i++) {
        scanf("%s %s %s %s %d", movies[i].title, movies[i].plot, movies[i].director, movies[i].actors, &movies[i].rating);
    }

    for (int i = 0; i < num_users; i++) {
        scanf("%s %s %s", users[i].name, users[i].email, users[i].address);
        for (int j = 0; j < num_movies; j++) {
            scanf("%d", &users[i].ratings[j]);
        }
    }

    return 0;
}