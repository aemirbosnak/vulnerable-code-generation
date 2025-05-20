//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 5

typedef struct {
    char title[50];
    int ratings[MAX_RATINGS];
    int num_ratings;
    double avg_rating;
} Movie;

void initialize_movie(Movie* movie, char* title) {
    strcpy(movie->title, title);
    movie->num_ratings = 0;
    movie->avg_rating = 0;
}

void add_rating(Movie* movie, int rating) {
    movie->ratings[movie->num_ratings] = rating;
    movie->num_ratings++;
    movie->avg_rating = 0;
    for (int i = 0; i < movie->num_ratings; i++) {
        movie->avg_rating += movie->ratings[i];
    }
    movie->avg_rating /= movie->num_ratings;
}

void print_movie(Movie* movie) {
    printf("Title: %s\n", movie->title);
    printf("Average rating: %.2f\n", movie->avg_rating);
    printf("Ratings:\n");
    for (int i = 0; i < movie->num_ratings; i++) {
        printf("%d\n", movie->ratings[i]);
    }
}

int main() {
    int num_movies;
    printf("Enter number of movies: ");
    scanf("%d", &num_movies);

    Movie movies[MAX_MOVIES];
    for (int i = 0; i < num_movies; i++) {
        char title[50];
        printf("Enter title of movie #%d: ", i+1);
        scanf("%s", title);
        initialize_movie(&movies[i], title);
    }

    int num_users;
    printf("Enter number of users: ");
    scanf("%d", &num_users);

    for (int i = 0; i < num_users; i++) {
        char name[50];
        printf("Enter name of user #%d: ", i+1);
        scanf("%s", name);
        printf("User %s is rating movies...\n", name);
        for (int j = 0; j < num_movies; j++) {
            int rating;
            printf("User %s is rating movie %s...\n", name, movies[j].title);
            scanf("%d", &rating);
            add_rating(&movies[j], rating);
        }
    }

    printf("\nMovie Ratings:\n");
    for (int i = 0; i < num_movies; i++) {
        print_movie(&movies[i]);
    }

    return 0;
}