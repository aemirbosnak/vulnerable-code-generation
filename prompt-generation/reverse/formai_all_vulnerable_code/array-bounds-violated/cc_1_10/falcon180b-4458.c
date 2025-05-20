//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MOVIE_MAX 100
#define USER_MAX 10
#define REVIEW_MAX 200

typedef struct {
    char title[50];
    char director[50];
    char genre[20];
    int rating;
} Movie;

typedef struct {
    char name[20];
    int age;
    char review[REVIEW_MAX];
} User;

int main() {
    Movie movies[MOVIE_MAX];
    User users[USER_MAX];
    int num_movies, num_users;

    printf("Enter number of movies: ");
    scanf("%d", &num_movies);

    for (int i = 0; i < num_movies; i++) {
        printf("Enter movie %d title: ", i+1);
        scanf("%s", movies[i].title);
        movies[i].rating = 0;
    }

    printf("Enter number of users: ");
    scanf("%d", &num_users);

    for (int i = 0; i < num_users; i++) {
        printf("Enter user %d name: ", i+1);
        scanf("%s", users[i].name);
        printf("Enter user %d age: ", i+1);
        scanf("%d", &users[i].age);
    }

    char choice;
    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Add a movie\n2. Add a user\n3. Rate a movie\n4. View ratings\n5. Exit\n");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("Enter movie title: ");
                scanf("%s", movies[num_movies].title);
                movies[num_movies].rating = 0;
                num_movies++;
                break;
            case '2':
                printf("Enter user name: ");
                scanf("%s", users[num_users].name);
                printf("Enter user age: ");
                scanf("%d", &users[num_users].age);
                num_users++;
                break;
            case '3':
                printf("Enter movie title: ");
                scanf("%s", movies[0].title);
                printf("Enter user name: ");
                scanf("%s", users[0].name);
                printf("Enter rating: ");
                scanf("%d", &movies[0].rating);
                printf("Enter review: ");
                scanf("%s", users[0].review);
                break;
            case '4':
                printf("\nMovie Ratings:\n");
                for (int i = 0; i < num_movies; i++) {
                    printf("%s - %d stars\n", movies[i].title, movies[i].rating);
                }
                break;
            case '5':
                exit(0);
            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}