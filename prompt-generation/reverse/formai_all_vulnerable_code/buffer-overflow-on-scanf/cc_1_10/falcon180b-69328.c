//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_USERS 10

typedef struct {
    char name[20];
    int rating;
    int num_ratings;
    int num_movies;
    double avg_rating;
} User;

User users[MAX_USERS];

void init_user(User* user, char* name) {
    strcpy(user->name, name);
    user->rating = 0;
    user->num_ratings = 0;
    user->num_movies = 0;
    user->avg_rating = 0;
}

void print_user(User* user) {
    printf("User: %s\n", user->name);
    printf("Rating: %d\n", user->rating);
    printf("Number of ratings: %d\n", user->num_ratings);
    printf("Number of movies: %d\n", user->num_movies);
    printf("Average rating: %.2f\n", user->avg_rating);
}

void add_rating(User* user, int rating) {
    user->num_ratings++;
    user->num_movies++;
    user->avg_rating = (user->num_ratings * user->avg_rating + rating) / (user->num_ratings + 1);
    user->rating += rating;
}

int main() {
    srand(time(NULL));
    char name[20];
    printf("Enter your name: ");
    scanf("%s", name);
    init_user(&users[0], name);

    int choice;
    while (1) {
        printf("1. Rate a movie\n2. View your ratings\n3. Exit\n");
        scanf("%d", &choice);
        if (choice == 1) {
            int rating;
            printf("Enter movie rating (0-10): ");
            scanf("%d", &rating);
            add_rating(&users[0], rating);
            printf("Rating added.\n");
        } else if (choice == 2) {
            print_user(&users[0]);
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}