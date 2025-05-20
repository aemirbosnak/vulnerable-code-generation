//FormAI DATASET v1.0 Category: Movie Rating System ; Style: synchronous
#include <stdio.h>

// function to determine appropriate rating based on user input
int movieRating(int rating) {
    switch (rating) {
        case 0: 
            return 0;
        case 1:
        case 2:
            return 1;
        case 3:
        case 4:
            return 2;
        case 5:
            return 3;
        default:
            return -1;
    }
}

int main() {
    int userRating;
    char movieTitle[50];
    printf("Welcome to the Unique C Movie Rating System!\n");
    printf("Please enter the name of the movie you would like to rate: ");
    scanf("%s", &movieTitle);
    printf("Please rate the movie on a scale of 0-5: ");
    scanf("%d", &userRating);
    int rating = movieRating(userRating);
    if (rating == -1) {
        printf("Invalid rating. Please try again.\n");
    } else {
        printf("Thank you for rating %s!\n", movieTitle);
        switch (rating) {
            case 0:
                printf("We do not recommend %s.\n", movieTitle);
                break;
            case 1:
                printf("We recommend %s for a casual movie night.\n", movieTitle);
                break;
            case 2:
                printf("We highly recommend %s for a movie night with friends or family.\n", movieTitle);
                break;
            case 3:
                printf("We absolutely loved %s and highly recommend it for a movie night with loved ones.\n", movieTitle);
                break;
            default:
                printf("Error: Something went wrong. Please try again.\n");
                break;
        }
    }
    return 0;
}