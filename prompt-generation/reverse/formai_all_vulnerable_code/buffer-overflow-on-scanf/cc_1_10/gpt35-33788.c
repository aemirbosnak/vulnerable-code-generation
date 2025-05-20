//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 50
#define MAX_RATINGS 10

typedef struct {
    char title[MAX_LEN];
    int year;
    float rating[MAX_RATINGS];
    int num_ratings;
    float avg_rating;
} Movie;

void print_movie(Movie m) {
    printf("%s (%d) - Average Rating: %.2f\n", m.title, m.year, m.avg_rating);
}

void add_rating(Movie *m, float rating) {
    if (m->num_ratings < MAX_RATINGS) {
        m->rating[m->num_ratings++] = rating;
        float total = 0;
        for (int i = 0; i < m->num_ratings; i++) {
            total += m->rating[i];
        }
        m->avg_rating = total / m->num_ratings;
    } else {
        printf("ERROR: Max number of ratings reached for %s.\n", m->title);
    }
}

int main() {
    printf("Welcome to the Cyberpunk Movie Rating System!\n");

    Movie movie1;
    strcpy(movie1.title, "Blade Runner");
    movie1.year = 1982;
    movie1.num_ratings = 0;
    movie1.avg_rating = 0;

    printf("Enter your rating (0.0 - 10.0) for %s (%d): ", movie1.title, movie1.year);
    float rating;
    scanf("%f", &rating);
    add_rating(&movie1, rating);

    printf("You rated %s (%d) %.2f out of 10.00.\n", movie1.title, movie1.year, rating);
    print_movie(movie1);

    return 0;
}