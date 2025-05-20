//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 10
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int ratings[MAX_RATINGS];
    int total_ratings;
} Movie;

bool movie_exists(Movie movies[], char name[], int size) {
    for (int i = 0; i < size; i++) {
        if (strcmp(movies[i].name, name) == 0) {
            return true;
        }
    }
    return false;
}

void add_rating(Movie *movie, int rating) {
    if (movie->total_ratings < MAX_RATINGS) {
        movie->ratings[movie->total_ratings] = rating;
        movie->total_ratings++;
    } else {
        printf("Max number of ratings reached.\n");
    }
}

void print_movie_rating(Movie movie) {
    int sum = 0;
    for (int i = 0; i < movie.total_ratings; i++) {
        sum += movie.ratings[i];
    }
    float avg_rating = (float)sum / movie.total_ratings;
    printf("Movie: %s\n", movie.name);
    printf("Rating: %.1f\n", avg_rating);
}

int main() {
    Movie movies[MAX_MOVIES];
    int choice, movie_index;
    char name[MAX_NAME_LENGTH];
    int rating;

    while (true) {
        printf("\n1. Rate a movie\n2. Print movie ratings\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter movie name: ");
                scanf("%s", name);
                if (movie_exists(movies, name, MAX_MOVIES)) {
                    movie_index = find_movie_index(movies, name, MAX_MOVIES);
                    printf("Enter movie rating (1-10): ");
                    scanf("%d", &rating);
                    add_rating(&movies[movie_index], rating);
                } else {
                    printf("Movie not found.\n");
                }
                break;
            case 2:
                printf("Enter movie name: ");
                scanf("%s", name);
                if (movie_exists(movies, name, MAX_MOVIES)) {
                    movie_index = find_movie_index(movies, name, MAX_MOVIES);
                    print_movie_rating(movies[movie_index]);
                } else {
                    printf("Movie not found.\n");
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

int find_movie_index(Movie movies[], char name[], int size) {
    for (int i = 0; i < size; i++) {
        if (strcmp(movies[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}