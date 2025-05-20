//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 5

typedef struct {
    char title[50];
    int ratings[MAX_RATINGS];
    int num_ratings;
} movie_t;

void add_rating(movie_t* movie, int rating) {
    if (movie->num_ratings >= MAX_RATINGS) {
        printf("Error: movie already has %d ratings\n", MAX_RATINGS);
        return;
    }
    movie->ratings[movie->num_ratings] = rating;
    movie->num_ratings++;
}

double calculate_average(int ratings[], int num_ratings) {
    int sum = 0;
    for (int i = 0; i < num_ratings; i++) {
        sum += ratings[i];
    }
    return (double) sum / num_ratings;
}

void print_movies(movie_t movies[], int num_movies) {
    for (int i = 0; i < num_movies; i++) {
        printf("%s: ", movies[i].title);
        for (int j = 0; j < movies[i].num_ratings; j++) {
            printf("%d ", movies[i].ratings[j]);
        }
        printf("(%.2f)\n", calculate_average(movies[i].ratings, movies[i].num_ratings));
    }
}

int main() {
    movie_t movies[MAX_MOVIES];
    int num_movies = 0;

    while (num_movies < MAX_MOVIES) {
        printf("Enter movie title or type 'done' to finish: ");
        scanf("%s", movies[num_movies].title);
        if (strcmp(movies[num_movies].title, "done") == 0) {
            break;
        }
        num_movies++;
    }

    while (1) {
        printf("Select a movie:\n");
        for (int i = 0; i < num_movies; i++) {
            printf("%d. %s\n", i+1, movies[i].title);
        }
        int choice;
        scanf("%d", &choice);
        if (choice < 1 || choice > num_movies) {
            printf("Invalid choice\n");
            continue;
        }
        movie_t* movie = &movies[choice-1];
        printf("Enter rating (1-5): ");
        int rating;
        scanf("%d", &rating);
        add_rating(movie, rating);
        print_movies(movies, num_movies);
    }

    return 0;
}