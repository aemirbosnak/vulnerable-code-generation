//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_GENRES 10
#define MAX_RATINGS 5
#define MAX_TITLE_LENGTH 80
#define MAX_GENRE_LENGTH 20
#define MAX_RATING_LENGTH 20

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    int ratings[MAX_RATINGS];
    int num_ratings;
} Movie;

void print_movie(Movie movie) {
    printf("Title: %s\n", movie.title);
    printf("Genre: %s\n", movie.genre);
    printf("Ratings:\n");
    for (int i = 0; i < movie.num_ratings; i++) {
        printf(" %d stars\n", movie.ratings[i]);
    }
}

void add_rating(Movie* movie, int rating) {
    if (movie->num_ratings >= MAX_RATINGS) {
        printf("Error: Max ratings reached\n");
        return;
    }
    movie->ratings[movie->num_ratings] = rating;
    movie->num_ratings++;
}

int main() {
    Movie movies[MAX_MOVIES];
    int num_movies = 0;

    char input[100];
    while (1) {
        printf("Enter movie title: ");
        scanf("%s", input);
        if (strcmp(input, "quit") == 0) {
            break;
        }
        strcpy(movies[num_movies].title, input);
        num_movies++;
    }

    for (int i = 0; i < num_movies; i++) {
        printf("Enter genre for %s: ", movies[i].title);
        scanf("%s", movies[i].genre);
    }

    while (1) {
        printf("Enter movie title to rate: ");
        scanf("%s", input);
        for (int i = 0; i < num_movies; i++) {
            if (strcmp(input, movies[i].title) == 0) {
                printf("Enter rating (1-5 stars): ");
                int rating = getchar() - '0';
                add_rating(&movies[i], rating);
                break;
            }
        }
    }

    while (1) {
        printf("Enter movie title to view ratings: ");
        scanf("%s", input);
        for (int i = 0; i < num_movies; i++) {
            if (strcmp(input, movies[i].title) == 0) {
                print_movie(movies[i]);
                break;
            }
        }
    }

    return 0;
}