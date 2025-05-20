//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_MOVIES 100
#define NUM_RATINGS 10

typedef struct {
    char title[50];
    int ratings[NUM_RATINGS];
    double mean;
    double stddev;
} Movie;

Movie movies[NUM_MOVIES];

void read_movies() {
    FILE *fp = fopen("movies.txt", "r");
    if (fp == NULL) {
        perror("Error opening movies.txt");
        exit(1);
    }

    for (int i = 0; i < NUM_MOVIES; i++) {
        fscanf(fp, "%s", movies[i].title);
        for (int j = 0; j < NUM_RATINGS; j++) {
            fscanf(fp, "%d", &movies[i].ratings[j]);
        }
    }

    fclose(fp);
}

void calculate_stats() {
    for (int i = 0; i < NUM_MOVIES; i++) {
        double sum = 0;
        for (int j = 0; j < NUM_RATINGS; j++) {
            sum += movies[i].ratings[j];
        }
        movies[i].mean = sum / NUM_RATINGS;

        double sq_sum = 0;
        for (int j = 0; j < NUM_RATINGS; j++) {
            sq_sum += pow(movies[i].ratings[j] - movies[i].mean, 2);
        }
        movies[i].stddev = sqrt(sq_sum / (NUM_RATINGS - 1));
    }
}

void print_movies() {
    printf("%-50s %-10s %-10s\n", "Title", "Mean", "Stddev");
    for (int i = 0; i < NUM_MOVIES; i++) {
        printf("%-50s %-10.2f %-10.2f\n", movies[i].title, movies[i].mean, movies[i].stddev);
    }
}

int main() {
    read_movies();
    calculate_stats();
    print_movies();

    return 0;
}