//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000
#define NUM_RATINGS 5

typedef struct {
    char name[MAX_LENGTH];
    int ratings[NUM_RATINGS];
    int num_ratings;
} Movie;

void get_movie_name(char *name) {
    printf("Enter movie name: ");
    scanf("%s", name);
    for (int i = 0; i < strlen(name); i++) {
        if (isalpha(name[i])) {
            name[i] = toupper(name[i]);
        }
    }
}

void get_rating(int *rating) {
    int temp;
    while (1) {
        printf("Enter rating (1-5): ");
        scanf("%d", &temp);
        if (temp >= 1 && temp <= 5) {
            *rating = temp;
            break;
        }
        printf("Invalid rating. Please enter a number between 1 and 5.\n");
    }
}

void print_movie_ratings(Movie *movie) {
    printf("Movie: %s\n", movie->name);
    printf("Ratings:\n");
    for (int i = 0; i < movie->num_ratings; i++) {
        printf("%d stars\n", movie->ratings[i]);
    }
}

int main() {
    Movie movie;
    strcpy(movie.name, "");
    movie.num_ratings = 0;

    while (1) {
        printf("1. Add rating\n");
        printf("2. Print ratings\n");
        printf("3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                get_movie_name(movie.name);
                if (movie.num_ratings == NUM_RATINGS) {
                    printf("Cannot add more ratings.\n");
                } else {
                    get_rating(&movie.ratings[movie.num_ratings]);
                    movie.num_ratings++;
                }
                break;
            case 2:
                print_movie_ratings(&movie);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}