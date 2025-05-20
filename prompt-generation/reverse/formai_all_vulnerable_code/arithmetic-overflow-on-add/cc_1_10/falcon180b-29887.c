//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_MOVIES 10
#define NUM_RATINGS 5

typedef struct {
    char title[100];
    int rating;
    int count;
} movie;

void print_movies(movie* movies, int num_movies) {
    printf("Movie Ratings:\n");
    for (int i = 0; i < num_movies; i++) {
        printf("%s: %d (%d ratings)\n", movies[i].title, movies[i].rating, movies[i].count);
    }
}

int main() {
    srand(time(NULL));

    movie movies[NUM_MOVIES] = {
        {"Blade Runner", 0, 0},
        {"The Matrix", 0, 0},
        {"Akira", 0, 0},
        {"Ghost in the Shell", 0, 0},
        {"Tron", 0, 0},
        {"Total Recall", 0, 0},
        {"Elysium", 0, 0},
        {"RoboCop", 0, 0},
        {"Minority Report", 0, 0},
        {"Ex Machina", 0, 0}
    };

    int choice;
    printf("Welcome to the Cyberpunk Movie Rating System!\n");
    printf("Please choose an option:\n");
    printf("1. Rate a movie\n");
    printf("2. View ratings\n");
    printf("3. Exit\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the title of the movie you want to rate: ");
            scanf("%s", movies[0].title);
            printf("Rate the movie (1-10): ");
            scanf("%d", &movies[0].rating);
            movies[0].count++;
            break;
        case 2:
            print_movies(movies, NUM_MOVIES);
            break;
        case 3:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}