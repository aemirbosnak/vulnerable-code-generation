//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 5
#define MAX_USERS 100

struct movie {
    char title[50];
    int year;
    int num_ratings;
    double avg_rating;
    int ratings[MAX_RATINGS];
};

struct user {
    char name[50];
    int num_ratings;
    int ratings[MAX_RATINGS];
};

int main() {
    srand(time(NULL));

    struct movie movies[MAX_MOVIES];
    int num_movies = 0;
    struct user users[MAX_USERS];
    int num_users = 0;

    int choice;
    do {
        printf("Romeo and Juliet Movie Rating System\n");
        printf("1. Add a movie\n");
        printf("2. Add a user\n");
        printf("3. Rate a movie\n");
        printf("4. View movie ratings\n");
        printf("5. View user ratings\n");
        printf("6. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter movie title: ");
                scanf("%s", movies[num_movies].title);
                printf("Enter movie year: ");
                scanf("%d", &movies[num_movies].year);
                num_movies++;
                break;
            case 2:
                printf("Enter user name: ");
                scanf("%s", users[num_users].name);
                num_users++;
                break;
            case 3:
                printf("Enter movie title: ");
                scanf("%s", movies[num_movies].title);
                printf("Enter user name: ");
                scanf("%s", users[num_users-1].name);
                printf("Enter rating (1-5): ");
                scanf("%d", &movies[num_movies-1].ratings[users[num_users-1].num_ratings]);
                movies[num_movies-1].num_ratings++;
                users[num_users-1].num_ratings++;
                break;
            case 4:
                printf("Movie ratings:\n");
                for (int i = 0; i < num_movies; i++) {
                    printf("%s (%d): %.2f\n", movies[i].title, movies[i].year, movies[i].avg_rating);
                }
                break;
            case 5:
                printf("User ratings:\n");
                for (int i = 0; i < num_users; i++) {
                    printf("%s: ", users[i].name);
                    for (int j = 0; j < users[i].num_ratings; j++) {
                        printf("%d ", users[i].ratings[j]);
                    }
                    printf("\n");
                }
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}