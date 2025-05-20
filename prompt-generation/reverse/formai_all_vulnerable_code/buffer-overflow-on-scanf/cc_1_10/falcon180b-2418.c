//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 1000

typedef struct {
    char title[50];
    float rating;
} Movie;

Movie movies[MAX_MOVIES];
int num_movies;

void add_movie(char* title) {
    if (num_movies >= MAX_MOVIES) {
        printf("Error: Maximum number of movies reached.\n");
        return;
    }

    strcpy(movies[num_movies].title, title);
    movies[num_movies].rating = 0;
    num_movies++;
}

void rate_movie(char* title, float rating) {
    int i;
    for (i = 0; i < num_movies; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            movies[i].rating += rating;
            return;
        }
    }

    add_movie(title);
    rate_movie(title, rating);
}

void display_movies() {
    int i;
    printf("Movie Ratings:\n");
    for (i = 0; i < num_movies; i++) {
        printf("%s - %.2f\n", movies[i].title, movies[i].rating);
    }
}

int main() {
    int choice;
    char title[50];

    do {
        printf("1. Add movie\n2. Rate movie\n3. Display ratings\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter movie title: ");
                scanf("%s", title);
                add_movie(title);
                break;
            case 2:
                printf("Enter movie title: ");
                scanf("%s", title);
                printf("Enter rating (0-10): ");
                scanf("%f", &movies[num_movies-1].rating);
                break;
            case 3:
                display_movies();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}