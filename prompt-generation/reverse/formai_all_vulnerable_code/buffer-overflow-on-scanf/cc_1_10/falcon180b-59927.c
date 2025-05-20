//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LENGTH 100
#define MAX_DIRECTOR_LENGTH 50
#define MAX_ACTOR_LENGTH 50
#define MAX_REVIEW_LENGTH 200

struct movie {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char actor1[MAX_ACTOR_LENGTH];
    char actor2[MAX_ACTOR_LENGTH];
    char actor3[MAX_ACTOR_LENGTH];
    float rating;
    char review[MAX_REVIEW_LENGTH];
};

int main() {
    int num_movies, i;
    struct movie movies[100];
    FILE *input_file;
    char filename[50];
    char line[200];
    char delimiter = ',';

    printf("Enter the name of the input file: ");
    scanf("%s", filename);

    input_file = fopen(filename, "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    fscanf(input_file, "%d", &num_movies);

    for (i = 0; i < num_movies; i++) {
        fscanf(input_file, "%s%c%s%c%s%c%s%c%f%c%[^\n]", movies[i].title, &delimiter, movies[i].director, &delimiter, movies[i].actor1, &delimiter, movies[i].actor2, &delimiter, movies[i].actor3, &delimiter, movies[i].review);
        movies[i].rating = (float)i / num_movies;
    }

    fclose(input_file);

    printf("Movie Ratings:\n");
    for (i = 0; i < num_movies; i++) {
        printf("%s - %.2f stars\n", movies[i].title, movies[i].rating);
    }

    return 0;
}