//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 10

struct movie {
    char title[50];
    int rating;
    int num_ratings;
};

void print_menu() {
    printf("Movie Rating System\n");
    printf("1. Add movie\n");
    printf("2. Rate movie\n");
    printf("3. View ratings\n");
    printf("4. Exit\n");
}

int main() {
    srand(time(NULL));
    int num_movies = 0;
    struct movie movies[MAX_MOVIES];
    int choice;

    while(1) {
        print_menu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(num_movies >= MAX_MOVIES) {
                    printf("Maximum number of movies reached.\n");
                } else {
                    printf("Enter movie title: ");
                    scanf("%s", movies[num_movies].title);
                    movies[num_movies].rating = 0;
                    movies[num_movies].num_ratings = 0;
                    num_movies++;
                }
                break;

            case 2:
                printf("Enter movie title: ");
                scanf("%s", movies[num_movies-1].title);
                printf("Enter rating (1-5): ");
                scanf("%d", &movies[num_movies-1].rating);
                movies[num_movies-1].num_ratings++;
                break;

            case 3:
                printf("Movie Ratings:\n");
                for(int i=0; i<num_movies; i++) {
                    printf("%s: %.2f (%d ratings)\n", movies[i].title, (float)movies[i].rating/movies[i].num_ratings, movies[i].num_ratings);
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