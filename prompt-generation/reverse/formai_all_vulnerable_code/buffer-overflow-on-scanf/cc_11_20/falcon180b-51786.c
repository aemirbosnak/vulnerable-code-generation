//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 1000
#define MAX_RATINGS 10000
#define MAX_USERS 10000
#define MAX_NAME_LENGTH 50
#define MAX_RATING_VALUE 5

typedef struct {
    char name[MAX_NAME_LENGTH];
    int ratings[MAX_RATING_VALUE];
    int num_ratings;
} Movie;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int user_id;
} User;

int main() {
    int num_movies, num_users;
    Movie movies[MAX_MOVIES];
    User users[MAX_USERS];
    char input_buffer[MAX_NAME_LENGTH];
    int user_id = 1;
    int movie_id = 1;
    int rating;

    printf("Enter the number of movies: ");
    scanf("%d", &num_movies);

    printf("Enter the number of users: ");
    scanf("%d", &num_users);

    for (int i = 0; i < num_movies; i++) {
        printf("Enter movie name: ");
        scanf("%s", movies[i].name);
        movies[i].num_ratings = 0;
    }

    for (int i = 0; i < num_users; i++) {
        printf("Enter user name: ");
        scanf("%s", users[i].name);
        users[i].user_id = user_id++;
    }

    while (1) {
        printf("Enter command (rate, list_top_rated, exit): ");
        scanf("%s", input_buffer);

        if (strcmp(input_buffer, "rate") == 0) {
            printf("Enter movie name: ");
            scanf("%s", input_buffer);

            printf("Enter user name: ");
            scanf("%s", input_buffer);

            for (int i = 0; i < num_movies; i++) {
                if (strcmp(movies[i].name, input_buffer) == 0) {
                    printf("Enter rating: ");
                    scanf("%d", &rating);
                    movies[i].ratings[rating-1]++;
                    movies[i].num_ratings++;
                    break;
                }
            }

            for (int i = 0; i < num_users; i++) {
                if (strcmp(users[i].name, input_buffer) == 0) {
                    printf("Rating submitted.\n");
                    break;
                }
            }
        }
        else if (strcmp(input_buffer, "list_top_rated") == 0) {
            printf("Top rated movies:\n");
            for (int i = 0; i < num_movies; i++) {
                if (movies[i].num_ratings > 0) {
                    double avg_rating = (double)movies[i].num_ratings / (double)movies[i].ratings[0];
                    printf("%s: %.1f\n", movies[i].name, avg_rating);
                }
            }
        }
        else if (strcmp(input_buffer, "exit") == 0) {
            break;
        }
        else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}