//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 1000
#define MAX_NAME_LENGTH 50
#define MAX_COMMENT_LENGTH 200

typedef struct {
    char name[MAX_NAME_LENGTH];
    int ratings[MAX_RATINGS];
    int num_ratings;
    char comments[MAX_COMMENT_LENGTH];
} Movie;

void initialize_movie(Movie* movie) {
    movie->num_ratings = 0;
    memset(movie->ratings, 0, sizeof(movie->ratings));
    movie->comments[0] = '\0';
}

int add_rating(Movie* movie, int rating) {
    if (movie->num_ratings >= MAX_RATINGS) {
        printf("Error: Movie has reached maximum number of ratings.\n");
        return -1;
    }
    movie->ratings[movie->num_ratings++] = rating;
    return 0;
}

int add_comment(Movie* movie, char* comment) {
    if (strlen(movie->comments) >= MAX_COMMENT_LENGTH) {
        printf("Error: Movie has reached maximum comment length.\n");
        return -1;
    }
    strcat(movie->comments, comment);
    return 0;
}

int main() {
    Movie movies[MAX_MOVIES];
    int num_movies = 0;
    char command[MAX_NAME_LENGTH];

    initialize_movie(&movies[0]);

    while (1) {
        printf("Enter command (add/list/exit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Enter movie name: ");
            scanf("%s", command);
            strcpy(movies[num_movies].name, command);
            num_movies++;
            printf("Movie added.\n");
        } else if (strcmp(command, "list") == 0) {
            for (int i = 0; i < num_movies; i++) {
                printf("%s\n", movies[i].name);
            }
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}