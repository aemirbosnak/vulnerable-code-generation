//FormAI DATASET v1.0 Category: Movie Rating System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_MOVIES 5

struct movie {
    char title[50];
    int rating;
};

struct user {
    char name[50];
    struct movie seen[MAX_MOVIES];
};

void print_ratings(struct movie movies[], int num_movies) {
    printf("Movie Ratings:\n");
    for (int i = 0; i < num_movies; i++) {
        printf("%s: %d\n", movies[i].title, movies[i].rating);
    }
}

void print_seen(struct user users[], int num_users, int user_index) {
    printf("%s's Seen Movies:\n", users[user_index].name);
    for (int i = 0; i < MAX_MOVIES; i++) {
        if (users[user_index].seen[i].title[0] != '\0') {
            printf("%s: %d Stars\n", users[user_index].seen[i].title, users[user_index].seen[i].rating);
        }
    }
}

int get_movie_index(char movie_title[], struct movie movies[], int num_movies) {
    for (int i = 0; i < num_movies; i++) {
        if (strcmp(movie_title, movies[i].title) == 0) {
            return i;
        }
    }
    return -1;
}

int get_user_index(char username[], struct user users[], int num_users) {
    for (int i = 0; i < num_users; i++) {
        if (strcmp(username, users[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    struct movie movies[MAX_MOVIES] = {
        {"The Matrix", 0},
        {"Star Wars: Episode IV - A New Hope", 0},
        {"The Dark Knight", 0},
        {"Jurassic Park", 0},
        {"Frozen", 0}
    };
    int num_movies = MAX_MOVIES;

    struct user users[MAX_USERS] = {
        {"Alice", {}},
        {"Bob", {}},
        {"Charlie", {}},
        {"David", {}},
        {"Eve", {}},
        {"Frank", {}},
        {"Grace", {}},
        {"Henry", {}},
        {"Ivy", {}},
        {"Jack", {}}
    };
    int num_users = MAX_USERS;

    int exit = 0;

    while (!exit) {
        printf("\nMovie Rating System Menu:\n");
        printf("-------------------------\n");
        printf("1. View Movie Ratings\n");
        printf("2. Rate a Movie\n");
        printf("3. View Seen Movies\n");
        printf("4. Exit\n");

        int choice;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                print_ratings(movies, num_movies);
                break;
            case 2:
                printf("\nEnter your name: ");
                char username[50];
                scanf("%s", username);
                int user_index = get_user_index(username, users, num_users);
                if (user_index == -1) {
                    printf("User does not exist.\n");
                    break;
                }
                printf("\nEnter movie title: ");
                char movie_title[50];
                scanf("%s", movie_title);
                int movie_index = get_movie_index(movie_title, movies, num_movies);
                if (movie_index == -1) {
                    printf("Movie does not exist.\n");
                    break;
                }
                printf("\nEnter rating (0-5 stars): ");
                int rating;
                scanf("%d", &rating);
                if (rating < 0 || rating > 5) {
                    printf("Invalid rating.\n");
                    break;
                }
                users[user_index].seen[movie_index].rating = rating;
                strcpy(users[user_index].seen[movie_index].title, movie_title);
                movies[movie_index].rating = (movies[movie_index].rating + rating) / 2;
                printf("Rating added.\n");
                break;
            case 3:
                printf("\nEnter your name: ");
                char username2[50];
                scanf("%s", username2);
                int user_index2 = get_user_index(username2, users, num_users);
                if (user_index2 == -1) {
                    printf("User does not exist.\n");
                    break;
                }
                print_seen(users, num_users, user_index2);
                break;
            case 4:
                printf("Exiting program...\n");
                exit = 1;
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}