//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 10

struct movie {
    char title[100];
    char director[100];
    int year;
    int ratings[MAX_RATINGS];
    int num_ratings;
};

void init_movie(struct movie *movie) {
    movie->num_ratings = 0;
    for (int i = 0; i < MAX_RATINGS; i++) {
        movie->ratings[i] = 0;
    }
}

void add_rating(struct movie *movie, int rating) {
    if (movie->num_ratings >= MAX_RATINGS) {
        printf("Sorry, this movie already has %d ratings.\n", MAX_RATINGS);
        return;
    }
    movie->ratings[movie->num_ratings] = rating;
    movie->num_ratings++;
}

double calculate_average_rating(struct movie *movie) {
    int total_ratings = 0;
    for (int i = 0; i < movie->num_ratings; i++) {
        total_ratings += movie->ratings[i];
    }
    return (double) total_ratings / movie->num_ratings;
}

void print_movie_info(struct movie *movie) {
    printf("Title: %s\n", movie->title);
    printf("Director: %s\n", movie->director);
    printf("Year: %d\n", movie->year);
    printf("Average rating: %.2f\n", calculate_average_rating(movie));
}

void main() {
    struct movie movies[MAX_MOVIES];
    int num_movies = 0;

    while (num_movies < MAX_MOVIES) {
        printf("Enter movie title, director, and year (or type 'done' to finish):\n");
        scanf("%s %s %d", movies[num_movies].title, movies[num_movies].director, &movies[num_movies].year);
        if (strcmp(movies[num_movies].title, "done") == 0) {
            break;
        }
        num_movies++;
    }

    int choice;
    while (1) {
        printf("1. Add rating\n2. Print movie info\n3. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter movie title:\n");
                scanf("%s", movies[num_movies-1].title);
                printf("Enter rating (1-10):\n");
                scanf("%d", &movies[num_movies-1].ratings[movies[num_movies-1].num_ratings-1]);
                break;
            case 2:
                printf("Enter movie title:\n");
                scanf("%s", movies[num_movies-1].title);
                print_movie_info(&movies[num_movies-1]);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}