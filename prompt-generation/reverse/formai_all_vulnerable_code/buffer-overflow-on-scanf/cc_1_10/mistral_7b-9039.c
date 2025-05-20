//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

#define MAX_MOVIES 10
#define MAX_NAME_LENGTH 50
#define MAX_RATINGS 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    int ratings[MAX_RATINGS];
    int num_ratings;
} Movie;

void init_movie(Movie *movie, const char *name) {
    strcpy(movie->name, name);
    movie->num_ratings = 0;
}

void rate_movie(Movie *movie, int rating) {
    movie->ratings[movie->num_ratings] = rating;
    movie->num_ratings++;
}

float average_rating(const Movie *movie) {
    float sum = 0;
    for (int i = 0; i < movie->num_ratings; i++) {
        sum += movie->ratings[i];
    }
    return sum / movie->num_ratings;
}

int main() {
    Movie movies[MAX_MOVIES];

    int movie_index = 0;

    while (movie_index < MAX_MOVIES) {
        printf("Enter movie name (or 'quit' to exit): ");
        char name[MAX_NAME_LENGTH];
        scanf("%s", name);

        if (strcmp(name, "quit") == 0) {
            break;
        }

        Movie *movie = &movies[movie_index];
        init_movie(movie, name);

        printf("Enter the number of ratings for %s (or 'done' when finished): ", name);
        int num_ratings;
        scanf("%d", &num_ratings);

        for (int i = 0; i < num_ratings; i++) {
            printf("Enter rating %d for %s: ", i + 1, name);
            int rating;
            scanf("%d", &rating);

            rate_movie(movie, rating);
        }

        movie_index++;
    }

    for (int i = 0; i < movie_index; i++) {
        printf("%s: Average rating = %.2f\n", movies[i].name, average_rating(&movies[i]));
    }

    return 0;
}