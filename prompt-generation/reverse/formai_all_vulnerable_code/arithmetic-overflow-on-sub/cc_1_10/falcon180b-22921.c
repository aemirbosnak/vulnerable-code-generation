//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 5

struct movie {
    char title[100];
    int rating_count;
    int ratings[MAX_RATINGS];
};

void add_rating(struct movie *movie, int rating) {
    movie->rating_count++;
    movie->ratings[movie->rating_count - 1] = rating;
}

int main() {
    struct movie movies[MAX_MOVIES];
    int num_movies = 0;
    char choice;
    int movie_index, rating;

    do {
        printf("C Movie Rating System\n");
        printf("------------------------\n");
        printf("1. Add a movie\n");
        printf("2. Rate a movie\n");
        printf("3. View movie ratings\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            if (num_movies >= MAX_MOVIES) {
                printf("Maximum number of movies reached.\n");
            } else {
                printf("Enter movie title: ");
                scanf("%s", movies[num_movies].title);
                movies[num_movies].rating_count = 0;
                num_movies++;
            }
            break;

        case '2':
            printf("Enter movie title: ");
            scanf("%s", movies[0].title);

            printf("Enter your rating (1-5): ");
            scanf("%d", &rating);

            add_rating(movies, rating);

            break;

        case '3':
            printf("Movie Ratings\n");
            printf("---------------\n");
            for (movie_index = 0; movie_index < num_movies; movie_index++) {
                printf("%s: ", movies[movie_index].title);
                for (int i = 0; i < movies[movie_index].rating_count; i++) {
                    printf("%d ", movies[movie_index].ratings[i]);
                }
                printf("\n");
            }
            break;

        case '4':
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= '4');

    return 0;
}