//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 10

typedef struct {
    char title[50];
    int ratings[MAX_RATINGS];
    int num_ratings;
} Movie;

void add_rating(Movie* m, int rating) {
    m->num_ratings++;
    m->ratings[m->num_ratings-1] = rating;
}

int calculate_average(Movie* m) {
    int sum = 0;
    for (int i = 0; i < m->num_ratings; i++) {
        sum += m->ratings[i];
    }
    return sum / m->num_ratings;
}

int main() {
    Movie movies[MAX_MOVIES];
    int num_movies = 0;

    char choice;
    while (1) {
        printf("C Movie Rating System\n");
        printf("1. Add movie\n");
        printf("2. Rate movie\n");
        printf("3. View movie ratings\n");
        printf("4. Quit\n");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("Enter movie title: ");
                scanf("%s", movies[num_movies].title);
                num_movies++;
                break;
            case '2':
                printf("Enter movie title: ");
                scanf("%s", movies[num_movies-1].title);
                printf("Enter rating (1-10): ");
                scanf("%d", &movies[num_movies-1].ratings[movies[num_movies-1].num_ratings-1]);
                add_rating(&movies[num_movies-1], movies[num_movies-1].ratings[movies[num_movies-1].num_ratings-1]);
                break;
            case '3':
                printf("Enter movie title: ");
                scanf("%s", movies[num_movies-1].title);
                printf("Average rating: %d\n", calculate_average(&movies[num_movies-1]));
                break;
            case '4':
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}