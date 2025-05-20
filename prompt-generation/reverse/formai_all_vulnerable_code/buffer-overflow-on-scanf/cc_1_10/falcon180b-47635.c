//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_RATINGS 10

typedef struct {
    char name[50];
    int ratings[MAX_RATINGS];
    int count;
    float avg;
} Movie;

void addRating(Movie *movie, int rating) {
    if(movie->count >= MAX_RATINGS) {
        printf("Sorry, movie ratings limit reached.\n");
        return;
    }
    movie->ratings[movie->count++] = rating;
    movie->avg = (movie->avg * (movie->count - 1) + rating) / movie->count;
}

float getAvgRating(Movie *movie) {
    return movie->avg;
}

int main() {
    Movie *movies[MAX_RATINGS];
    int n, m, choice, rating;
    char name[50];

    printf("Enter the number of movies: ");
    scanf("%d", &n);

    for(m = 0; m < n; m++) {
        printf("Enter the movie name: ");
        scanf("%s", name);
        movies[m] = (Movie*)malloc(sizeof(Movie));
        strcpy(movies[m]->name, name);
        movies[m]->count = 0;
        movies[m]->avg = 0;
    }

    while(1) {
        printf("\n1. Add rating\n2. Get average rating\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the movie name: ");
                scanf("%s", name);
                for(m = 0; m < n; m++) {
                    if(strcmp(movies[m]->name, name) == 0) {
                        printf("Enter the rating: ");
                        scanf("%d", &rating);
                        addRating(movies[m], rating);
                        break;
                    }
                }
                if(m == n) {
                    printf("Movie not found.\n");
                }
                break;
            case 2:
                printf("Enter the movie name: ");
                scanf("%s", name);
                for(m = 0; m < n; m++) {
                    if(strcmp(movies[m]->name, name) == 0) {
                        printf("Average rating: %.2f\n", getAvgRating(movies[m]));
                        break;
                    }
                }
                if(m == n) {
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