//FormAI DATASET v1.0 Category: Movie Rating System ; Style: statistical
#include <stdio.h>

int main() {
    int ratings[5][10] = {0}; // initialize the ratings array to 0
    int num_movies = 0;

    // loop to get user input on movie ratings
    while (1) {
        int rating = 0;
        int movie_num = 0;

        printf("Enter movie number (1-10): ");
        scanf("%d", &movie_num);

        if (movie_num == 0) {
            // exit loop if user enters 0 for movie number
            break;
        } else if (movie_num < 1 || movie_num > 10) {
            // error message if user enters invalid movie number
            printf("Error: Invalid movie number\n");
            continue;
        }

        printf("Enter movie rating (1-5): ");
        scanf("%d", &rating);

        if (rating < 1 || rating > 5) {
            // error message if user enters invalid rating
            printf("Error: Invalid rating\n");
            continue;
        }

        // add rating to ratings array
        ratings[rating-1][movie_num-1]++;
        num_movies++;
    }

    // display average rating for each movie
    printf("Movie ratings:\n");
    for (int i = 0; i < 10; i++) {
        int total_rating = 0;
        int num_ratings = 0;

        // loop through each possible rating and add up the total number of ratings for that movie
        for (int j = 0; j < 5; j++) {
            total_rating += (j+1) * ratings[j][i];
            num_ratings += ratings[j][i];
        }

        if (num_ratings == 0) {
            // no ratings for this movie
            printf("Movie %d: No ratings\n", i+1);
        } else {
            // calculate and display the average rating for this movie
            float avg_rating = (float) total_rating / num_ratings;
            printf("Movie %d: %.2f\n", i+1, avg_rating);
        }
    }

    // display total number of movies and number of ratings for each rating
    printf("\nTotal movies: %d\n", num_movies);
    for (int i = 0; i < 5; i++) {
        int total_ratings = 0;

        // loop through each movie and add up the number of ratings for this rating
        for (int j = 0; j < 10; j++) {
            total_ratings += ratings[i][j];
        }

        // display the number of ratings for this rating
        printf("Number of %d star ratings: %d\n", i+1, total_ratings);
    }

    return 0;
}