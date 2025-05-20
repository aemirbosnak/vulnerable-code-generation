//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RATINGS 10
#define MAX_MOVIES 100

typedef struct {
    char title[100];
    char director[100];
    char actors[200];
    int year;
    int ratings;
    int num_ratings;
} movie_t;

movie_t movies[MAX_MOVIES];

void add_movie() {
    int i;
    for (i = 0; i < MAX_MOVIES; i++) {
        if (movies[i].title[0] == '\0') {
            printf("Enter movie title: ");
            scanf("%s", movies[i].title);
            printf("Enter director: ");
            scanf("%s", movies[i].director);
            printf("Enter actors (comma-separated): ");
            scanf("%s", movies[i].actors);
            printf("Enter year: ");
            scanf("%d", &movies[i].year);
            printf("Enter initial rating (0-10): ");
            scanf("%d", &movies[i].ratings);
            printf("Movie added.\n");
            return;
        }
    }
    printf("Maximum number of movies reached.\n");
}

void rate_movie() {
    int i, j;
    char title[100];
    printf("Enter movie title: ");
    scanf("%s", title);
    for (i = 0; i < MAX_MOVIES; i++) {
        if (strcmp(title, movies[i].title) == 0) {
            printf("Enter rating (0-10): ");
            scanf("%d", &movies[i].ratings);
            movies[i].num_ratings++;
            printf("Rating added.\n");
            return;
        }
    }
    printf("Movie not found.\n");
}

void view_ratings() {
    int i;
    for (i = 0; i < MAX_MOVIES; i++) {
        if (movies[i].title[0]!= '\0') {
            printf("%s (%d)\n", movies[i].title, movies[i].ratings);
        }
    }
}

int main() {
    int choice;
    while (1) {
        printf("1. Add movie\n2. Rate movie\n3. View ratings\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_movie();
                break;
            case 2:
                rate_movie();
                break;
            case 3:
                view_ratings();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}