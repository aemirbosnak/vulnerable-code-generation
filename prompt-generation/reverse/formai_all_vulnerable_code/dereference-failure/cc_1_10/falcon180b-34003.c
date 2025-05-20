//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: decentralized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 100
#define MAX_RATINGS 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    int num_ratings;
    int ratings[MAX_RATINGS];
} Movie;

void add_rating(Movie *movie, int rating) {
    if (movie->num_ratings < MAX_RATINGS) {
        movie->ratings[movie->num_ratings++] = rating;
    }
}

int calculate_average_rating(Movie *movie) {
    int sum = 0;
    for (int i = 0; i < movie->num_ratings; i++) {
        sum += movie->ratings[i];
    }
    return sum / movie->num_ratings;
}

int main() {
    FILE *input_file = fopen("movies.txt", "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error: could not open input file.\n");
        return 1;
    }

    Movie *movies = malloc(sizeof(Movie) * 100);
    int num_movies = 0;

    char line[MAX_NAME_LENGTH];
    while (fgets(line, MAX_NAME_LENGTH, input_file)!= NULL) {
        char *name = strtok(line, "\t");
        int rating = atoi(strtok(NULL, "\t"));

        Movie *movie = movies + num_movies++;
        strcpy(movie->name, name);
        add_rating(movie, rating);
    }

    fclose(input_file);

    for (int i = 0; i < num_movies; i++) {
        printf("Movie: %s\n", movies[i].name);
        printf("Average rating: %.2f\n\n", calculate_average_rating(movies + i));
    }

    free(movies);
    return 0;
}