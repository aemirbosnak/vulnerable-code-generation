//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 10

typedef struct {
    char title[100];
    int ratings[MAX_RATINGS];
    int num_ratings;
} movie;

void print_movie(movie *m) {
    printf("%s:", m->title);
    for (int i = 0; i < m->num_ratings; i++) {
        printf(" %d", m->ratings[i]);
    }
    printf("\n");
}

double entropy(movie *m) {
    double p[MAX_RATINGS];
    for (int i = 0; i < MAX_RATINGS; i++) {
        p[i] = 0;
    }
    for (int i = 0; i < m->num_ratings; i++) {
        p[m->ratings[i]]++;
    }
    for (int i = 0; i < MAX_RATINGS; i++) {
        p[i] /= m->num_ratings;
    }
    double entropy = 0;
    for (int i = 0; i < MAX_RATINGS; i++) {
        if (p[i] > 0) {
            entropy -= p[i] * log2(p[i]);
        }
    }
    return entropy;
}

int main() {
    movie movies[MAX_MOVIES];
    int num_movies = 0;

    FILE *fp = fopen("movies.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp)) {
        if (num_movies >= MAX_MOVIES) {
            break;
        }
        movie *m = &movies[num_movies];
        sscanf(line, "%s", m->title);
        m->num_ratings = 0;
        for (int i = 0; i < MAX_RATINGS; i++) {
            int rating;
            if (sscanf(line, "%s %d", m->title, &rating) == 2) {
                m->ratings[m->num_ratings++] = rating;
            }
        }
        num_movies++;
    }
    fclose(fp);

    for (int i = 0; i < num_movies; i++) {
        print_movie(&movies[i]);
    }

    for (int i = 0; i < num_movies; i++) {
        double e = entropy(&movies[i]);
        printf("%s: %.4f\n", movies[i].title, e);
    }

    return EXIT_SUCCESS;
}