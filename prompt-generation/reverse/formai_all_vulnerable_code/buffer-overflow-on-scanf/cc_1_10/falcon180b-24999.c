//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 1000

typedef struct {
    char title[100];
    int year;
    int rating;
    int num_ratings;
} Movie;

Movie movies[MAX_MOVIES];
int num_movies;

typedef struct {
    int user_id;
    int movie_id;
    int rating;
    int timestamp;
} Rating;

Rating ratings[MAX_RATINGS];
int num_ratings;

void print_movie(int i) {
    printf("%s (%d)\n", movies[i].title, movies[i].year);
    printf("Rating: %.1f\n", (float)movies[i].rating/movies[i].num_ratings);
    printf("Number of ratings: %d\n\n", movies[i].num_ratings);
}

int main() {
    srand(time(NULL));

    num_movies = 0;
    num_ratings = 0;

    movies[num_movies].title[0] = '\0';
    movies[num_movies].year = 0;
    movies[num_movies].rating = 0;
    movies[num_movies].num_ratings = 0;
    num_movies++;

    int choice;
    do {
        printf("1. Add movie\n");
        printf("2. Rate movie\n");
        printf("3. Print top-rated movies\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter movie title: ");
                scanf("%s", movies[num_movies].title);
                printf("Enter release year: ");
                scanf("%d", &movies[num_movies].year);
                movies[num_movies].rating = 0;
                movies[num_movies].num_ratings = 0;
                num_movies++;
                break;
            case 2:
                printf("Enter user ID: ");
                scanf("%d", &ratings[num_ratings].user_id);
                printf("Enter movie ID: ");
                scanf("%d", &ratings[num_ratings].movie_id);
                printf("Enter rating (1-5): ");
                scanf("%d", &ratings[num_ratings].rating);
                ratings[num_ratings].timestamp = time(NULL);
                num_ratings++;
                break;
            case 3:
                printf("Top-rated movies:\n");
                for(int i=0; i<num_movies; i++) {
                    float rating = (float)movies[i].rating/movies[i].num_ratings;
                    printf("%s (%d) - Rating: %.1f\n", movies[i].title, movies[i].year, rating);
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while(1);

    return 0;
}