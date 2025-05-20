//FormAI DATASET v1.0 Category: Movie Rating System ; Style: visionary
#include <stdio.h>

// Define struct for movie rating
struct rating {
    int five_star;
    int four_star;
    int three_star;
    int two_star;
    int one_star;
};

int main() {

    // initialize movie rating with 0
    struct rating movie_rating = {0, 0, 0, 0, 0};

    // get user's rating for the movie
    int rating;
    printf("Please rate the movie (1-5 stars): ");
    scanf("%d", &rating);

    // update movie rating with user's rating
    switch (rating) {
        case 1:
            movie_rating.one_star++;
            break;
        case 2:
            movie_rating.two_star++;
            break;
        case 3:
            movie_rating.three_star++;
            break;
        case 4:
            movie_rating.four_star++;
            break;
        case 5:
            movie_rating.five_star++;
            break;
        default:
            printf("Invalid rating.\n");
    }

    // display current movie rating
    printf("\nCurrent movie rating:\n");
    printf(" 5 stars: %d\n", movie_rating.five_star);
    printf(" 4 stars: %d\n", movie_rating.four_star);
    printf(" 3 stars: %d\n", movie_rating.three_star);
    printf(" 2 stars: %d\n", movie_rating.two_star);
    printf(" 1 star : %d\n", movie_rating.one_star);

    // calculate and display the average rating
    int total_ratings = movie_rating.five_star + movie_rating.four_star +
                        movie_rating.three_star + movie_rating.two_star +
                        movie_rating.one_star;
    float average_rating = (5 * movie_rating.five_star + 4 * movie_rating.four_star +
                            3 * movie_rating.three_star + 2 * movie_rating.two_star +
                            1 * movie_rating.one_star) / (float)total_ratings;

    printf("\nAverage rating: %.2f\n", average_rating);

    return 0;
}