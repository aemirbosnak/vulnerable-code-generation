//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RATINGS 10
#define MAX_CHAR 100

struct rating {
    char movie_title[MAX_CHAR];
    int rating;
};

void display_menu() {
    printf("Movie Rating System\n");
    printf("1. Add Movie\n");
    printf("2. Display Ratings\n");
    printf("3. Exit\n");
}

void add_movie(struct rating ratings[], int num_ratings) {
    if (num_ratings >= MAX_RATINGS) {
        printf("Cannot add more ratings\n");
        return;
    }
    printf("Enter movie title: ");
    scanf("%s", ratings[num_ratings].movie_title);
    printf("Enter rating (0-5): ");
    scanf("%d", &ratings[num_ratings].rating);
    num_ratings++;
}

void display_ratings(struct rating ratings[], int num_ratings) {
    printf("\nRatings:\n");
    for (int i = 0; i < num_ratings; i++) {
        printf("%s - %d\n", ratings[i].movie_title, ratings[i].rating);
    }
}

int main() {
    struct rating ratings[MAX_RATINGS];
    int num_ratings = 0;
    int choice;

    printf("Welcome to the Movie Rating System!\n");
    while (1) {
        display_menu();
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            add_movie(ratings, num_ratings);
            break;
        case 2:
            display_ratings(ratings, num_ratings);
            break;
        case 3:
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}