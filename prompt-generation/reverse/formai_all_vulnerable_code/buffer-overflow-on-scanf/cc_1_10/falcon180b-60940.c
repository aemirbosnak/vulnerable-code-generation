//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 10

struct movie {
    char title[50];
    int rating[MAX_RATINGS];
    int num_ratings;
};

void add_rating(struct movie* movie, int rating) {
    if (movie->num_ratings >= MAX_RATINGS) {
        printf("Error: Movie already has %d ratings.\n", MAX_RATINGS);
        return;
    }
    movie->rating[movie->num_ratings] = rating;
    movie->num_ratings++;
}

int main() {
    srand(time(NULL));
    struct movie movies[MAX_MOVIES];
    int num_movies = 0;
    int choice;

    while (num_movies < MAX_MOVIES) {
        printf("Enter movie title (or 0 to stop): ");
        scanf("%s", movies[num_movies].title);
        if (strcmp(movies[num_movies].title, "0") == 0) {
            break;
        }
        num_movies++;
    }

    while (1) {
        printf("\n");
        printf("1. Add rating\n");
        printf("2. View ratings\n");
        printf("3. Sort by rating\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter movie title: ");
                scanf("%s", movies[num_movies].title);
                add_rating(&movies[num_movies], rand() % 101);
                printf("Rating added.\n");
                break;
            case 2:
                printf("Ratings for %s:\n", movies[num_movies].title);
                for (int i = 0; i < movies[num_movies].num_ratings; i++) {
                    printf("%d\n", movies[num_movies].rating[i]);
                }
                break;
            case 3:
                for (int i = 0; i < num_movies; i++) {
                    for (int j = 0; j < MAX_RATINGS; j++) {
                        movies[i].rating[j] = -1;
                    }
                    movies[i].num_ratings = 0;
                }
                printf("Enter sort order (1 for ascending, 2 for descending): ");
                scanf("%d", &choice);
                for (int i = 0; i < num_movies; i++) {
                    for (int j = 0; j < movies[i].num_ratings; j++) {
                        printf("%d ", movies[i].rating[j]);
                    }
                    printf("\n");
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}