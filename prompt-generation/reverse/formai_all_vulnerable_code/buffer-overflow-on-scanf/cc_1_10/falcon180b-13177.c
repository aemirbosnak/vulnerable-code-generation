//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_MOVIES 5
#define NUM_RATINGS 5

struct movie {
    char name[50];
    int ratings[NUM_RATINGS];
};

struct movie movies[NUM_MOVIES] = {
    {"The Shawshank Redemption", {5, 5, 5, 5, 5}},
    {"The Godfather", {5, 5, 5, 5, 5}},
    {"The Dark Knight", {5, 5, 5, 5, 5}},
    {"Pulp Fiction", {5, 5, 5, 5, 5}},
    {"Forrest Gump", {5, 5, 5, 5, 5}}
};

int main() {
    int choice;
    int movie_index;
    int rating;
    int total_ratings;
    double average_rating;
    time_t now;
    struct tm *current_time;

    srand(time(NULL));

    printf("Welcome to the Movie Rating System!\n");
    printf("Please choose a movie:\n");

    for (int i = 0; i < NUM_MOVIES; i++) {
        printf("%d. %s\n", i + 1, movies[i].name);
    }

    scanf("%d", &choice);

    movie_index = choice - 1;
    total_ratings = 0;

    printf("Thank you for choosing %s.\n", movies[movie_index].name);
    printf("Please enter your rating (1-5):\n");

    scanf("%d", &rating);
    total_ratings++;

    movies[movie_index].ratings[total_ratings - 1] = rating;

    time(&now);
    current_time = localtime(&now);

    printf("Your rating has been recorded at %s.\n", asctime(current_time));

    average_rating = (double)total_ratings / (double)NUM_RATINGS;

    printf("The current average rating for %s is: %.2f\n", movies[movie_index].name, average_rating);

    return 0;
}