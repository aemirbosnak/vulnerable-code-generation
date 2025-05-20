//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 10

struct movie {
    char title[100];
    int ratings[MAX_RATINGS];
    int num_ratings;
};

struct movie movies[MAX_MOVIES];
int num_movies;

void add_movie(char* title) {
    int i;
    for (i = 0; i < num_movies; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            return;
        }
    }
    strcpy(movies[num_movies].title, title);
    movies[num_movies].num_ratings = 0;
    num_movies++;
}

void add_rating(char* title, int rating) {
    int i;
    for (i = 0; i < num_movies; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            if (movies[i].num_ratings == MAX_RATINGS) {
                printf("Error: Maximum ratings reached for %s\n", title);
                return;
            }
            movies[i].ratings[movies[i].num_ratings++] = rating;
            return;
        }
    }
    printf("Error: Movie not found\n");
}

void display_movies() {
    int i;
    printf("Movie Ratings:\n");
    for (i = 0; i < num_movies; i++) {
        printf("%s:\n", movies[i].title);
        int j;
        for (j = 0; j < movies[i].num_ratings; j++) {
            printf("%d\n", movies[i].ratings[j]);
        }
    }
}

int main() {
    int choice;
    do {
        printf("\n1. Add Movie\n2. Add Rating\n3. Display Movies\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                char title[100];
                printf("Enter movie title: ");
                scanf("%s", title);
                add_movie(title);
                break;
            }
            case 2: {
                char title[100];
                int rating;
                printf("Enter movie title: ");
                scanf("%s", title);
                printf("Enter rating: ");
                scanf("%d", &rating);
                add_rating(title, rating);
                break;
            }
            case 3: {
                display_movies();
                break;
            }
            case 4: {
                exit(0);
            }
            default: {
                printf("Invalid choice\n");
            }
        }
    } while (1);
    return 0;
}