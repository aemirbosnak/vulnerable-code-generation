//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_MOVIES 100
#define MAX_RATING 10

typedef struct {
    char title[50];
    int rating;
    time_t timestamp;
} Movie;

int main() {
    int i, j, k;
    int num_movies = 0;
    Movie movies[MAX_MOVIES];

    printf("Welcome to the Surprising C Movie Rating System!\n");
    printf("We'll keep track of movies and their ratings for you!\n");
    printf("Let's get started, shall we?\n");

    while (1) {
        printf("\n1. Add a movie\n");
        printf("2. Rate a movie\n");
        printf("3. List movies and their ratings\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");

        scanf("%d", &i);

        switch (i) {
            case 1:
                if (num_movies >= MAX_MOVIES) {
                    printf("Whoa, hold on there!\n");
                    printf("We've reached the maximum number of movies!\n");
                    printf("Try removing some movies first!\n");
                    break;
                }

                printf("Enter the title of the movie: ");
                scanf("%s", movies[num_movies].title);
                movies[num_movies].rating = 0;
                movies[num_movies].timestamp = time(NULL);

                num_movies++;
                printf("Movie added successfully!\n");
                break;

            case 2:
                if (num_movies == 0) {
                    printf("You haven't added any movies yet!\n");
                    break;
                }

                printf("Enter the number of the movie you want to rate: ");
                scanf("%d", &i);

                if (i > num_movies || i < 1) {
                    printf("Invalid choice!\n");
                    break;
                }

                printf("Enter a rating (1-10): ");
                scanf("%d", &j);

                if (j < 1 || j > 10) {
                    printf("Invalid rating!\n");
                    break;
                }

                movies[i - 1].rating = j;
                movies[i - 1].timestamp = time(NULL);

                printf("Movie rated successfully!\n");
                break;

            case 3:
                printf("Movies and their ratings:\n");

                for (i = 0; i < num_movies; i++) {
                    printf("%d. %s - Rating: %d, Last rated: %s\n", i + 1, movies[i].title, movies[i].rating, ctime(&movies[i].timestamp));
                }
                break;

            case 4:
                printf("Goodbye and happy movie rating!\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}