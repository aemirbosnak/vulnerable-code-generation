//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 10

struct movie {
    char title[50];
    double rating;
    int ratings_count;
};

void add_movie(struct movie *movies, int num_movies, char *title) {
    int i;
    for (i = 0; i < num_movies; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            printf("Movie already exists!\n");
            return;
        }
    }
    strcpy(movies[num_movies].title, title);
    movies[num_movies].rating = 0;
    movies[num_movies].ratings_count = 0;
    printf("Movie added successfully!\n");
}

void rate_movie(struct movie *movies, int num_movies, char *title, double rating) {
    int i;
    for (i = 0; i < num_movies; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            movies[i].rating += rating;
            movies[i].ratings_count++;
            printf("Movie rated successfully!\n");
            return;
        }
    }
    printf("Movie not found!\n");
}

void display_movies(struct movie *movies, int num_movies) {
    int i;
    for (i = 0; i < num_movies; i++) {
        printf("%s: %.2f (%d ratings)\n", movies[i].title, movies[i].rating, movies[i].ratings_count);
    }
}

int main() {
    struct movie movies[MAX_MOVIES];
    int num_movies = 0;
    char title[50];
    int choice;

    do {
        printf("1. Add movie\n2. Rate movie\n3. Display movies\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter movie title: ");
                scanf("%s", title);
                add_movie(movies, num_movies, title);
                break;
            case 2:
                printf("Enter movie title: ");
                scanf("%s", title);
                printf("Enter rating (1-5): ");
                scanf("%lf", &movies[num_movies].rating);
                rate_movie(movies, num_movies, title, movies[num_movies].rating);
                break;
            case 3:
                display_movies(movies, num_movies);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice!= 4);

    return 0;
}