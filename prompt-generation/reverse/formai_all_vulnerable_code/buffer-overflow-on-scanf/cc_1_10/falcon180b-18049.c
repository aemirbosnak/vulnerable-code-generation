//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MAX_RATINGS 10
#define MAX_USERS 10
#define MAX_MOVIES 10
#define MAX_THREADS 10

typedef struct {
    char name[50];
    int ratings[MAX_MOVIES];
} user;

typedef struct {
    char title[50];
    int ratings[MAX_USERS];
} movie;

void* rate_movie(void* arg) {
    char* movie_title = (char*)arg;
    int i;

    for(i=0; i<MAX_USERS; i++) {
        if(strcmp(movie_title, ((user*)malloc(sizeof(user)))->name) == 0) {
            printf("User %s has already rated this movie.\n", movie_title);
            return NULL;
        }
    }

    int rating;
    printf("Enter your rating for %s (1-5): ", movie_title);
    scanf("%d", &rating);

    strcpy(((movie*)malloc(sizeof(movie)))->title, movie_title);
    ((movie*)malloc(sizeof(movie)))->ratings[rating-1]++;

    return NULL;
}

void display_ratings(movie* m) {
    int i, j;

    for(i=0; i<MAX_USERS; i++) {
        if(m->ratings[i] > 0) {
            printf("%d stars: %d\n", i+1, m->ratings[i]);
        }
    }
}

int main() {
    int i, j;
    char input[100];
    user users[MAX_USERS];
    movie movies[MAX_MOVIES];

    for(i=0; i<MAX_USERS; i++) {
        printf("Enter name of user %d: ", i+1);
        scanf("%s", users[i].name);
    }

    for(i=0; i<MAX_MOVIES; i++) {
        printf("Enter title of movie %d: ", i+1);
        scanf("%s", movies[i].title);
    }

    pthread_t threads[MAX_THREADS];

    for(i=0; i<MAX_MOVIES; i++) {
        for(j=0; j<MAX_USERS; j++) {
            pthread_create(&threads[j], NULL, rate_movie, movies[i].title);
        }

        for(j=0; j<MAX_USERS; j++) {
            pthread_join(threads[j], NULL);
        }

        printf("\n");
        printf("Ratings for %s:\n", movies[i].title);
        display_ratings(&movies[i]);
    }

    return 0;
}