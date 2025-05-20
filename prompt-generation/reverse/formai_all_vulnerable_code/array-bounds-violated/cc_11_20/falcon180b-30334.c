//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024
#define MAX_WORD_SIZE 64
#define MAX_RATING_SIZE 10

typedef struct {
    char *word;
    int rating;
} MovieRating;

int main(int argc, char *argv[]) {
    FILE *input;
    char line[MAX_LINE_SIZE];
    int num_movies = 0;
    MovieRating *movies = NULL;

    input = fopen(argv[1], "r");
    if (input == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_SIZE, input)!= NULL) {
        int len = strlen(line);
        if (line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }

        char *word = line;
        char *token = strtok(word, " ");
        while (token!= NULL) {
            if (num_movies >= MAX_RATING_SIZE) {
                printf("Error: too many movies.\n");
                return 1;
            }

            int rating = atoi(token);
            if (rating < 1 || rating > 5) {
                printf("Error: invalid rating.\n");
                return 1;
            }

            movies[num_movies].word = strdup(token);
            movies[num_movies].rating = rating;
            num_movies++;

            token = strtok(NULL, " ");
        }
    }

    fclose(input);

    if (num_movies == 0) {
        printf("Error: no movies found.\n");
        return 1;
    }

    printf("Movie Ratings\n");
    for (int i = 0; i < num_movies; i++) {
        printf("%s: %d\n", movies[i].word, movies[i].rating);
    }

    for (int i = 0; i < num_movies; i++) {
        free(movies[i].word);
    }
    free(movies);

    return 0;
}