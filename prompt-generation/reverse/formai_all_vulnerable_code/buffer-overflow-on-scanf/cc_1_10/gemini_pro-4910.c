//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100

struct movie {
    char *title;
    int rating;
};

int compare_movies(const void *a, const void *b) {
    const struct movie *m1 = a;
    const struct movie *m2 = b;

    return strcmp(m1->title, m2->title);
}

int main(void) {
    struct movie movies[MAX_MOVIES];
    int num_movies = 0;

    printf("Enter the title and rating of each movie (title,rating):\n");

    while (num_movies < MAX_MOVIES) {
        char title[100];
        int rating;

        scanf(" %[^\n] %d", title, &rating);
        if (strcmp(title, "quit") == 0) {
            break;
        }

        movies[num_movies].title = strdup(title);
        movies[num_movies].rating = rating;

        num_movies++;
    }

    qsort(movies, num_movies, sizeof(struct movie), compare_movies);

    printf("\nMovie Ratings:\n");
    for (int i = 0; i < num_movies; i++) {
        printf("%s: %d\n", movies[i].title, movies[i].rating);
    }

    for (int i = 0; i < num_movies; i++) {
        free(movies[i].title);
    }

    return 0;
}