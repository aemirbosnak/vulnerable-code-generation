//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TITLES 100
#define RATING_MAX 10

struct Movie {
    char title[50];
    int rating;
};

typedef struct Movie movie_t;

int main() {
    srand(time(NULL));
    movie_t movies[MAX_TITLES];

    int num_movies = 0;
    printf("Welcome to the Irregular Movie Rating System!\n");
    printf("Enter a movie title or 'quit' to exit.\n");

    while (num_movies < MAX_TITLES) {
        printf("\nTitle: ");
        scanf("%s", movies[num_movies].title);

        if (strcmp(movies[num_movies].title, "quit") == 0) {
            break;
        }

        int random_number = rand() % RATING_MAX + 1;
        movies[num_movies].rating = random_number;

        printf("Rating: %d stars (%s)\n", random_number, movies[num_movies].title);
        num_movies++;
    }

    printf("\nRating Report:\n");

    for (int i = 0; i < num_movies; i++) {
        printf("\nTitle: %s", movies[i].title);
        printf("\nRating: %d stars", movies[i].rating);

        int j = movies[i].rating % 3;
        switch (j) {
            case 0:
                printf("\n  ...and a handful of popcorn from the back row!");
                break;
            case 1:
                printf("\n  ...and a snooze from the middle seat!");
                break;
            case 2:
                printf("\n  ...and a free bucket of buttery popcorn!");
                break;
            default:
                printf("\n  ...and a ticket to the mystery screening room 13!");
                break;
        }
    }

    return 0;
}