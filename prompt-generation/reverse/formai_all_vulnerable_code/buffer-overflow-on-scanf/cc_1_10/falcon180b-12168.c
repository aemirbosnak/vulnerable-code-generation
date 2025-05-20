//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 10

struct movie {
    char title[100];
    int year;
    int rating[MAX_RATINGS];
    int num_ratings;
};

struct movie movies[MAX_MOVIES];
int num_movies = 0;

void add_movie() {
    printf("Enter movie title: ");
    scanf("%s", movies[num_movies].title);
    printf("Enter movie year: ");
    scanf("%d", &movies[num_movies].year);
    num_movies++;
}

void rate_movie() {
    int movie_index;
    printf("Enter movie index: ");
    scanf("%d", &movie_index);
    if (movie_index >= 0 && movie_index < num_movies) {
        printf("Enter rating (1-10): ");
        int rating;
        scanf("%d", &rating);
        movies[movie_index].rating[movies[movie_index].num_ratings++] = rating;
        printf("Rating added.\n");
    } else {
        printf("Invalid movie index.\n");
    }
}

void print_ratings() {
    int i, j;
    for (i = 0; i < num_movies; i++) {
        printf("%s (%d)\n", movies[i].title, movies[i].year);
        for (j = 0; j < movies[i].num_ratings; j++) {
            printf("  Rating: %d", movies[i].rating[j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int choice;
    do {
        printf("\nC Movie Rating System\n");
        printf("1. Add movie\n");
        printf("2. Rate movie\n");
        printf("3. Print ratings\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_movie();
                break;
            case 2:
                rate_movie();
                break;
            case 3:
                print_ratings();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);
    return 0;
}