//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RATINGS 100

struct rating {
    char movie_title[100];
    int rating;
};

int compare_ratings(const void *a, const void *b) {
    struct rating *movie_a = (struct rating *)a;
    struct rating *movie_b = (struct rating *)b;

    return strcmp(movie_a->movie_title, movie_b->movie_title);
}

void print_ratings(struct rating *ratings, int num_ratings) {
    qsort(ratings, num_ratings, sizeof(struct rating), compare_ratings);

    for (int i = 0; i < num_ratings; i++) {
        printf("%s: %d\n", ratings[i].movie_title, ratings[i].rating);
    }
}

int main() {
    struct rating ratings[MAX_RATINGS];
    int num_ratings = 0;

    while (num_ratings < MAX_RATINGS) {
        printf("Enter a movie title and rating (or enter 'done' to finish):\n");
        char input[100];
        scanf("%s", input);

        if (strcmp(input, "done") == 0) {
            break;
        }

        struct rating *movie = &ratings[num_ratings];
        strcpy(movie->movie_title, input);
        movie->rating = atoi(input);
        num_ratings++;
    }

    print_ratings(ratings, num_ratings);

    return 0;
}