//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_MOVIES 5
#define NUM_RATINGS 5

struct movie {
    char title[50];
    char director[50];
    char genre[50];
    int year;
    float rating;
};

struct rating {
    char user[50];
    float value;
};

void read_movies(struct movie *movies) {
    FILE *fp;
    char line[100];
    int i = 0;

    fp = fopen("movies.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while (fgets(line, 100, fp)!= NULL) {
        sscanf(line, "%s %s %s %d %f", movies[i].title, movies[i].director, movies[i].genre, &movies[i].year, &movies[i].rating);
        i++;
    }

    fclose(fp);
}

void read_ratings(struct rating *ratings) {
    FILE *fp;
    char line[100];
    int i = 0;

    fp = fopen("ratings.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while (fgets(line, 100, fp)!= NULL) {
        sscanf(line, "%s %f", ratings[i].user, &ratings[i].value);
        i++;
    }

    fclose(fp);
}

void calculate_average_rating(struct movie *movies, struct rating *ratings) {
    int i;

    for (i = 0; i < NUM_MOVIES; i++) {
        int count = 0;
        float sum = 0;

        printf("\nMovie: %s\n", movies[i].title);
        printf("Director: %s\n", movies[i].director);
        printf("Genre: %s\n", movies[i].genre);
        printf("Year: %d\n", movies[i].year);
        printf("Initial Rating: %.2f\n\n", movies[i].rating);

        for (int j = 0; j < NUM_RATINGS; j++) {
            if (strcmp(ratings[j].user, "unknown")!= 0 && strcmp(movies[i].title, ratings[j].user) == 0) {
                printf("Rating by %s: %.2f\n", ratings[j].user, ratings[j].value);
                sum += ratings[j].value;
                count++;
            }
        }

        if (count > 0) {
            movies[i].rating = sum / count;
            printf("Average Rating: %.2f\n\n", movies[i].rating);
        } else {
            printf("No ratings found.\n");
        }
    }
}

int main() {
    struct movie movies[NUM_MOVIES];
    struct rating ratings[NUM_RATINGS];

    read_movies(movies);
    read_ratings(ratings);

    calculate_average_rating(movies, ratings);

    return 0;
}