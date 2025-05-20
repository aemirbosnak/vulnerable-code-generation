//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RATING_COUNT 5

struct movie {
    char title[50];
    char director[50];
    char cast[100];
    char genre[50];
    int runtime;
    int release_year;
    int rating[RATING_COUNT];
    int total_rating;
    float avg_rating;
};

void print_movie_info(struct movie movie) {
    printf("Title: %s\n", movie.title);
    printf("Director: %s\n", movie.director);
    printf("Cast: %s\n", movie.cast);
    printf("Genre: %s\n", movie.genre);
    printf("Runtime: %d minutes\n", movie.runtime);
    printf("Release Year: %d\n", movie.release_year);
}

void add_rating(struct movie *movie, int rating) {
    movie->rating[movie->total_rating] = rating;
    movie->total_rating++;
    movie->avg_rating = (movie->avg_rating * movie->total_rating + rating) / (movie->total_rating + 1);
}

int main() {
    struct movie movie;
    int choice, rating;
    char input[50];

    printf("Welcome to the Movie Rating System!\n");
    printf("Enter movie information:\n");
    printf("Title: ");
    scanf("%s", movie.title);
    printf("Director: ");
    scanf("%s", movie.director);
    printf("Cast: ");
    scanf("%s", movie.cast);
    printf("Genre: ");
    scanf("%s", movie.genre);
    printf("Runtime: ");
    scanf("%d", &movie.runtime);
    printf("Release Year: ");
    scanf("%d", &movie.release_year);

    printf("\nMovie Information:\n");
    print_movie_info(movie);

    while(1) {
        printf("\n1. Add a rating\n2. View ratings\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter your rating (1-5): ");
                scanf("%d", &rating);
                add_rating(&movie, rating);
                printf("\nRating added successfully!\n");
                break;
            case 2:
                printf("\nRatings:\n");
                for(int i=0; i<movie.total_rating; i++) {
                    printf("%d stars\n", movie.rating[i]);
                }
                printf("Average rating: %.2f\n", movie.avg_rating);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}