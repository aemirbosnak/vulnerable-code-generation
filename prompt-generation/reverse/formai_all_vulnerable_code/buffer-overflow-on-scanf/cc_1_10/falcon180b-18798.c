//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 5

typedef struct {
    char title[50];
    int rating;
    char reviewers[MAX_RATINGS][50];
    int num_reviewers;
} Movie;

void add_movie(Movie movies[], int num_movies) {
    printf("Enter movie title: ");
    scanf("%s", movies[num_movies].title);
    movies[num_movies].rating = 0;
    movies[num_movies].num_reviewers = 0;
}

void add_reviewer(Movie movies[], int num_movies) {
    printf("Enter reviewer name: ");
    scanf("%s", movies[num_movies].reviewers[movies[num_movies].num_reviewers]);
    movies[num_movies].num_reviewers++;
}

void add_rating(Movie movies[], int num_movies) {
    printf("Enter rating (1-5): ");
    scanf("%d", &movies[num_movies].rating);
}

void print_movies(Movie movies[], int num_movies) {
    printf("Movie Ratings:\n");
    for (int i = 0; i < num_movies; i++) {
        printf("%s - Rating: %d\n", movies[i].title, movies[i].rating);
    }
}

int main() {
    Movie movies[MAX_MOVIES];
    int num_movies = 0;

    while (num_movies < MAX_MOVIES) {
        printf("1. Add movie\n2. Add reviewer\n3. Add rating\n4. Print ratings\n5. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_movie(movies, num_movies);
                num_movies++;
                break;
            case 2:
                add_reviewer(movies, num_movies);
                break;
            case 3:
                add_rating(movies, num_movies);
                break;
            case 4:
                print_movies(movies, num_movies);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}