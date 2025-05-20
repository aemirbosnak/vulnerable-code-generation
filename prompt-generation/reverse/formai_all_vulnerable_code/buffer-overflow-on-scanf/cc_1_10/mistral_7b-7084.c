//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_NAME_LEN 50
#define MAX_STARS 6

struct movie {
    char name[MAX_NAME_LEN];
    int stars;
};

void error(const char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    FILE *fp;
    int num_movies = 0;
    struct movie movies[MAX_MOVIES];

    fp = fopen("movies.dat", "wb");
    if (fp == NULL) {
        error("Could not open file for writing");
    }

    while (1) {
        printf("Enter movie name (empty line to quit):\n");
        scanf("%s", movies[num_movies].name);
        if (strlen(movies[num_movies].name) == 0) {
            break;
        }

        printf("Enter number of stars (1-6):\n");
        scanf("%d", &movies[num_movies].stars);
        if (movies[num_movies].stars < 1 || movies[num_movies].stars > 6) {
            error("Invalid number of stars");
        }

        fwrite(&num_movies, sizeof(int), 1, fp);
        fwrite(movies[num_movies].name, MAX_NAME_LEN, 1, fp);
        fwrite(&movies[num_movies].stars, sizeof(int), 1, fp);

        num_movies++;
        if (num_movies >= MAX_MOVIES) {
            error("Max number of movies reached");
        }
    }

    fclose(fp);

    fp = fopen("movies.dat", "rb");
    if (fp == NULL) {
        error("Could not open file for reading");
    }

    int total_stars = 0;
    int num_movies_read = 0;

    while (1) {
        int movie_num;
        fread(&movie_num, sizeof(int), 1, fp);
        if (feof(fp)) {
            break;
        }

        char name[MAX_NAME_LEN];
        fread(name, MAX_NAME_LEN, 1, fp);
        fread(&movies[num_movies_read].stars, sizeof(int), 1, fp);

        total_stars += movies[num_movies_read].stars;
        num_movies_read++;
    }

    fclose(fp);

    printf("Average rating: %.1f\n", (float)total_stars / num_movies_read);

    return 0;
}