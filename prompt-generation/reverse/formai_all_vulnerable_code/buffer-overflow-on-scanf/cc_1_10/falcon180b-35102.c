//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 10

struct Movie {
    char title[50];
    char director[50];
    char actors[100];
    int ratings[MAX_RATINGS];
    int num_ratings;
};

void initialize_movie(struct Movie *movie) {
    strcpy(movie->title, "");
    strcpy(movie->director, "");
    strcpy(movie->actors, "");
    movie->num_ratings = 0;
}

void add_rating(struct Movie *movie, int rating) {
    if (movie->num_ratings >= MAX_RATINGS) {
        printf("Sorry, the movie already has %d ratings.\n", MAX_RATINGS);
        return;
    }
    movie->ratings[movie->num_ratings] = rating;
    movie->num_ratings++;
}

void print_movie(struct Movie *movie) {
    printf("Title: %s\n", movie->title);
    printf("Director: %s\n", movie->director);
    printf("Actors: %s\n", movie->actors);
    printf("Ratings:\n");
    for (int i = 0; i < movie->num_ratings; i++) {
        printf("%d\n", movie->ratings[i]);
    }
}

int main() {
    struct Movie movies[MAX_MOVIES];
    int num_movies = 0;

    initialize_movie(&movies[num_movies]);
    num_movies++;

    int choice;
    while (1) {
        printf("\nMovie Rating System\n");
        printf("1. Add a movie\n");
        printf("2. Add a rating\n");
        printf("3. Print a movie\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_movies >= MAX_MOVIES) {
                    printf("Sorry, you have added %d movies already.\n", MAX_MOVIES);
                } else {
                    initialize_movie(&movies[num_movies]);
                    num_movies++;
                }
                break;
            case 2:
                printf("Enter the movie title: ");
                scanf("%s", movies[0].title);
                add_rating(&movies[0], 5);
                break;
            case 3:
                printf("Enter the movie title: ");
                scanf("%s", movies[0].title);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}