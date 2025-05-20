//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 100

struct movie {
    char name[50];
    int rating;
    int num_ratings;
};

struct user {
    char name[50];
    int ratings[MAX_MOVIES];
};

void add_movie(struct movie* movies, int num_movies, char* name) {
    for (int i = 0; i < num_movies; i++) {
        if (strcmp(movies[i].name, name) == 0) {
            printf("Movie already exists.\n");
            return;
        }
    }

    strcpy(movies[num_movies].name, name);
    movies[num_movies].rating = 0;
    movies[num_movies].num_ratings = 0;

    printf("Movie added successfully.\n");
}

void add_rating(struct movie* movies, int num_movies, char* name, int rating) {
    for (int i = 0; i < num_movies; i++) {
        if (strcmp(movies[i].name, name) == 0) {
            movies[i].rating += rating;
            movies[i].num_ratings++;

            printf("Rating added successfully.\n");
            return;
        }
    }

    printf("Movie not found.\n");
}

void view_movies(struct movie* movies, int num_movies) {
    printf("Movie Ratings:\n");

    for (int i = 0; i < num_movies; i++) {
        printf("%s: %d (%d ratings)\n", movies[i].name, movies[i].rating, movies[i].num_ratings);
    }
}

void main() {
    struct movie movies[MAX_MOVIES];
    int num_movies = 0;

    while (num_movies < MAX_MOVIES) {
        printf("Enter movie name: ");
        scanf("%s", movies[num_movies].name);

        add_movie(movies, num_movies, movies[num_movies].name);

        num_movies++;
    }

    while (1) {
        printf("1. Add rating\n");
        printf("2. View ratings\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter movie name: ");
                scanf("%s", movies[num_movies-1].name);

                printf("Enter rating (1-5): ");
                scanf("%d", &movies[num_movies-1].rating);

                add_rating(movies, num_movies, movies[num_movies-1].name, movies[num_movies-1].rating);

                break;

            case 2:
                view_movies(movies, num_movies);

                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }
}